#!/usr/bin/perl -w

#
# author: Nightinggale
#
# Update XML files to add new tags to existing files
#

use strict;
use warnings;


use XMLaccess;

updateDir(".");



sub updateDir
{
	my $dirname = $_[0];
	
	my $pathdirname = getXMLlocation() . "/" . $dirname;
	
	opendir my($dh), $pathdirname or die "Couldn't open dir '$pathdirname': $!";
	my @files = grep { !/^\.\.?$/ } readdir $dh;
	closedir $dh;

	foreach (@files)
	{
		my $filename = $dirname . "/" . $_;
		my $pathfilename = getXMLlocation() . "/" . $filename;
		if (-d $pathfilename)
		{
			updateDir($dirname . "/". $filename);
		}
		elsif (substr($_, -4) eq '.xml')
		{
			updateFile($filename);
		}
		
	}
}


sub updateFile
{
	my $filename = $_[0];
	my @lines;
	my $indent = 0;
	my $comments = 0;
	
	
	foreach (openFile($filename))
	{
		my $line = $_;
		if (index($_, '<?xml') != -1 or index($_, '<!--') != -1)
		{
			$comments = 1;
		}

		if ($comments == 0)
		{
	
			if (index($_, '</') != -1 and index($_, '</') == index($_, '<'))
			{
				$indent += -1;
			}
			
			while (substr($line, 0, 1) eq " " or substr($line, 0, 1) eq "	")
			{
				$line = substr($line,1);
			}
			
			my $prefix = "";
			
			for (my $count = 0; $count < $indent; $count++)
			{
				$prefix .= "	";
			}
			
			$line = $prefix . $line;
			
			if (index($_, '</') == -1 and index($_, '/>') == -1 and index($_, '<') != -1)
			{
				$indent += 1;
			}
		}
		else
		{
			if (index($_, '?>') != -1 or index($_, '-->') != -1)
		{
			$comments = 0;
		}
		}
	
		push ( @lines, $line);
	}
	writeFile(@lines);
}
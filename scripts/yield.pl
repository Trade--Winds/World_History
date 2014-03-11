#!/usr/bin/perl

# Script to autogenerate needed lists for yields
# Written by Nightinggale

# Autogenerates needed code for yields in DLL
# triggers on all source files starting with Yields_ and ends with .h

# Updates:
#   group functions in header
#   XML check in cpp file
#   python enum

use strict;
use warnings;

my $target = '';
my $group = "";

my $HEADER_FILE = "";
my $SOURCE_FILE = "";

my @yield_array = ();
my %yield_hash = ();
my %yield_convertion = ();

my $DEFINE_FLAG = "";

my $to_file = 1;

my @needed_yields = ();
push(@needed_yields, "YIELD_FOOD");
push(@needed_yields, "YIELD_LUMBER");
push(@needed_yields, "YIELD_STONE");
push(@needed_yields, "YIELD_ORE");
push(@needed_yields, "YIELD_TOOLS");
push(@needed_yields, "YIELD_WEAPONS");
push(@needed_yields, "YIELD_HORSES");
push(@needed_yields, "YIELD_TRADE_GOODS");
push(@needed_yields, "YIELD_HAMMERS");
push(@needed_yields, "YIELD_BELLS");
push(@needed_yields, "YIELD_CROSSES");
push(@needed_yields, "YIELD_EDUCATION");
push(@needed_yields, "YIELD_IDEAS");
push(@needed_yields, "YIELD_CULTURE");
push(@needed_yields, "YIELD_GOLD");

chdir "../DLL_sources";

opendir my($dh), "." or die "Couldn't open dir '../DLL_sources': $!";
my @files = grep { !/^\.\.?$/ } readdir $dh;
closedir $dh;


foreach (@files)
{
	if (substr($_,0,7) eq "Yields_")
	{
		if (substr($_,-2) eq ".h" )
		{
			$target = substr($_,7, -2);
			updateTarget();
		}
	}
}


exit;


sub updateTarget
{
	print "\nWorking on " . $target . "\n";
	
	@yield_array = ();
	%yield_hash = ();
	%yield_convertion = ();
	$DEFINE_FLAG = "";

	$HEADER_FILE = "Yields_" . $target . ".h";
	$SOURCE_FILE = "Yields_" . $target . ".cpp";
	
	open (FILE, "< " . $SOURCE_FILE) or die "Can't open file " . $SOURCE_FILE;
	while (<FILE>)
	{
		if (substr($_, 0, 7) eq "#ifdef ")
		{
			$DEFINE_FLAG = substr($_, 7);
			$DEFINE_FLAG =~ s/\r\n/\n/g;
			chomp $DEFINE_FLAG;
			last;
		}
	}
	close FILE;

	die "Can't find #ifdef in " . $SOURCE_FILE if $DEFINE_FLAG eq "";

	##
	## generate a hash and an array with all yields
	##
	open (FILE, "< " . $HEADER_FILE) or die "Can't open file " . $HEADER_FILE;

	my $status = 0;

	while (<FILE>) {
		my $comment_index = index($_, '//');
		my $yield_index = index($_, 'YIELD');
		
		if ($comment_index != -1 and $comment_index < $yield_index)
		{
			next;
		}
		
		if ($status == 0) {
			if (index($_, 'NO_YIELD = -1') != -1) {
				$status = 1;
			}
		} elsif ($status == 1) {
			if (index($_, 'NUM_YIELD_TYPES') != -1) {
				$status = 2;
			} elsif (index($_, 'YIELD_') != -1) {
				my $line = substr($_,index($_, 'YIELD_'));
				$line = substr($line, 0, index($line, ','));
				$yield_hash{$line} = scalar(@yield_array);
				$yield_convertion{$line} = $line;
				push(@yield_array, $line);
			}
		}
		elsif ($status == 2) {
			if (substr($_,0,1) eq '}') {
				last;
			} elsif (index($_, '=') != -1) {
				my $left = substr($_, index($_, 'Y'));
				$left = substr($left, 0, index($left, ' ') );
				
				my $right = substr($_, index($_, '='));
				$right = substr($right, index($right, 'Y'));
				$right = substr($right,0,index($right, ',') );
				
				if ($left eq "YIELD_FROM_ANIMALS")
				{
					last;
				}
				else
				{
					$yield_convertion{$right} = $left;
				}
			}
		}
		
		if ($status gt 0 and substr($_,0,1) eq '}')
		{
			last;
		}
	}

	close FILE;

	# at this point we can look up yield_names by index in @yield_array and yield_index by name in %yield_hash
	
	OUTER:
	foreach my $needed_yield (@needed_yields)
	{
		foreach (@yield_array)
		{
			next OUTER if $yield_convertion{$_} eq $needed_yield;
		}
		die $needed_yield . " is unknown";
	}
	
	makeAllGroups();
	writeYieldXMLAccess();
	writeYieldPythonAccess();

}

sub writeoutput {
	if ($to_file == 0) {
		print $_[0];
	} else {
		print WRITE_FILE $_[0];
	}
}


sub GetOptimizedgroup{
	my $group = $_[0];
	my @active_yields = ();
	my $status = 0;

	# init all active yields to not being included
	foreach (@yield_array)
	{
		push(@active_yields, -1);
	}

	open (FILE, "< ../DLL_Sources/Yields_" . $target . ".cpp") or die "Can't open file DLL_Sources/Yields_" . $target . ".cpp";
	while (<FILE>) {
		if ($status == 0) {
			if (index($_, $group) != -1) {
				$status = 1;
			}
		} elsif ($status == 1) {
			my $index = index($_, 'YieldVector.push_back');
			if (index($_, '}') != -1) {
				last
			} elsif ($index != -1) {
				my $comment_index = index($_, '//');
				if ($comment_index == -1 or $comment_index > $index)
				{
					my $yield = substr($_,index($_, '(') + 1);
					$yield = substr($yield, 0, index($yield, ')'));
					
					my $found = 0;
					for (keys %yield_hash)
					{
						if ($_ eq $yield)
						{
							$found = 1;
							last;
						}
					}
					die $yield . " used in cpp without being defined in header" if $found == 0; 
					
					$active_yields[$yield_hash{$yield}] = $yield_hash{$yield};
				}
			}
		}
	}
	close FILE;
	
	
	writeoutput("\treturn ");
	
	my $num_yields = scalar(@yield_array);
	
	my $first = -1;
	my $last = -1;
	my $empty = 1;
	for (@active_yields)
	{
		if ($_ != -1) {
			if ($first == -1)
			{
				$first = $_;
			} else {
				$last = $_;
			}
		} elsif ($first != -1 and $_ == -1) {
			if ($last != -1)
			{
				if ($empty == 0) {
					writeoutput(" || ");
				}
				$empty = 0;
				if (($num_yields - $first) > ($num_yields + ($last - $num_yields)))
				{
					writeoutput("(eYield <= " . $yield_array[$last] . " && eYield >= " . $yield_array[$first] . ")");
				} else {
					writeoutput("(eYield >= " . $yield_array[$first] . " && eYield <= " . $yield_array[$last] . ")");
				}
			}
			$first = -1;
			$last = -1;
		}
	}
	
	$first = -1;
	$last = -1;
	
	for (@active_yields)
	{
		if ($_ != -1) {
			if ($first == -1)
			{
				$first = $_;
			} else {
				$last = $_;
			}
		} elsif ($first != -1 and $_ == -1) {
			if ($last == -1) {
				if ($empty == 0) {
					writeoutput(" || ");
				}
				$empty = 0;
				writeoutput("(eYield == " . $yield_array[$first] . ")");
			}
			$first = -1;
			$last = -1;
		}
	}
	
	if ($empty == 1) {
		writeoutput("false");
	}
	writeoutput(";\n");
}

sub checkXML {
	if ($to_file == 0) {
		print "Fill in Yields_" . $target . ".cpp\n";
		print "in function BaseCheckYieldGroup::checkXML\n";
	} else {
		print "writing XML checking code to " . $SOURCE_FILE . "\n";
	}
	for (@yield_array) {
		writeoutput("\tcheckSingleXMLType(" . $_ . ",");
		for (my $count = 26; $count >= length $_; $count--) {
			writeoutput(" ");
		}
		writeoutput("\"" . $_ . "\");\n");
	}
}

sub createPythonAccess {
	if ($to_file == 0) {
		print "Fill in CyEnumsInterface.cpp\n";
		print "python::enum_<YieldTypes>(\"YieldTypes\")\n";
		print "under " . $target . "\n";
	} else {
		print "writing python access code to CyEnumsInterface.cpp\n";
	}
	for (@yield_array) {
		my $new_yield = $yield_convertion{$_};
		writeoutput("\t\t.value(\"" . $new_yield . "\", ");
		for (my $count = 26; $count >= length $new_yield; $count--) {
			writeoutput(" ");
		}
		writeoutput($_ . ")\n");
	}
}

sub writeYieldXMLAccess {
	open (FILE, "< " . $SOURCE_FILE) or die "Can't open file " . $SOURCE_FILE . "\n" . $!;
	my @lines = <FILE>;
	close FILE;
	
	open (WRITE_FILE, "> " . $SOURCE_FILE) or die "Can't open file " . $SOURCE_FILE . "\n" . $!;
	
	$to_file = 1;
	
	my $found = 0;
	foreach (@lines)
	{
		if ($found == 0 and index($_, "checkSingleXMLType") != -1)
		{
			$found = 1;
			checkXML();
		} elsif ($found == 1)
		{
			if (substr($_,0,1) eq "}")
			{
				$found = 2;
				print WRITE_FILE $_;
			}
		} else {
			print WRITE_FILE $_;
		}
	}
	
	close WRITE_FILE;
}

sub writeYieldPythonAccess {
	my $source = "CyEnumsInterface.cpp";
	open (FILE, "< " . $source) or die "Can't open file " . $source . "\n" . $!;
	my @lines = <FILE>;
	close FILE;
	
	open (WRITE_FILE, "> " . $source) or die "Can't open file " . $source . "\n" . $!;
	
	$to_file = 1;
	
	my $status = 0;
	foreach (@lines)
	{

		if ($status == 0 and index($_, 'YieldTypes') != -1)
		{
			$status = 1;
			print WRITE_FILE $_;
		} elsif ($status == 1 and substr($_, 0, 1) eq "#")
		{
			if (substr($_, 0, 6) eq "#endif")
			{
				# define flag is not present in file
				# create a new block for this flag
				$status = 3;
				print WRITE_FILE "#elif defined(" . $DEFINE_FLAG . ")\n";
				createPythonAccess();
			}
		
			print WRITE_FILE $_;
		
			if (index($_, $DEFINE_FLAG) != -1)
			{
				$status = 2;
				createPythonAccess();
			}
		} elsif ($status == 2)
		{
			if (substr($_, 0, 1) eq "#") {
				$status = 3;
				print WRITE_FILE $_;
			}
		} else {
			print WRITE_FILE $_;
		}
	}
	
	close WRITE_FILE;
}

sub makeAllGroups {
	open (FILE, "< " . $HEADER_FILE) or die "Can't open file " . $HEADER_FILE . "\n" . $!;
	my @lines = <FILE>;
	close FILE;
	
	open (WRITE_FILE, "> " . $HEADER_FILE) or die "Can't open file " . $HEADER_FILE . "\n" . $!;
	
	$to_file = 1;
	my $function = "";
	
	foreach (@lines)
	{
		if (substr($_,0,29) eq "static inline bool YieldGroup" and index ($_, "YieldGroup_Luxury_Food") == -1)
		{
			$function = substr($_, index($_, "YieldGroup"));
			$function = substr($function, 0, index($function, "("));
		}
		
		if ($function ne "" and index($_, "return") != -1)
		{
			GetOptimizedgroup("Check_" . $function);
			$function = "";
		} else {
			print WRITE_FILE $_;
		}
	}
	close WRITE_FILE;
}


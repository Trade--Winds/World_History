#!/usr/bin/perl

# Script to autogenerate switch-case for XML cache
# Written by Nightinggale

use strict;
use warnings;

my $SOURCE_FILE = "../DLL_Sources/CvEnums.h";
my $DESTINATION_FILE = "../DLL_Sources/CvGlobals.cpp";

my $to_file = 1;


sub writeoutput {
	if ($to_file == 0) {
		print $_[0];
	} else {
		print WRITE_FILE $_[0];
	}
}

sub writecase {
	my $flag = $_[0];
	
	writeoutput "\t\tcase $flag:\n";
	writeoutput "\t\t\treturn this->getDefineINT(\"" . substr($flag, 4) ."\");\n";
	writeoutput "\t\t\tbreak;\n";
}


sub readflags {
	open (FILE, $SOURCE_FILE) or die "Can't open file " . $SOURCE_FILE . "\n";

	my $status = 0;

	while (<FILE>) {
		if ($status == 0) {
			if (index($_, "NO_XML_TYPE") != -1) {
				$status = 1;
			}
		} elsif (index($_, "NUM_XML_CONSTANTS") != -1) {
			last;
		} else {
			if (index($_, "XML_") != -1) {
				 my $line = substr($_, index($_, "XML_"));
				 $line = substr($line, 0, index($line, ","));
				 writecase $line;
			}
		}
	}
}


open (FILE, "< " . $DESTINATION_FILE) or die "Can't open file " . $DESTINATION_FILE . "\n" . $!;
my @lines = <FILE>;
close FILE;

if ($to_file != 0) {
	open (WRITE_FILE, "> " . $DESTINATION_FILE) or die "Can't open file " . $DESTINATION_FILE . "\n" . $!;
}

my $write_status = 0;
foreach (@lines)
{
	if ($write_status == 0) {
		writeoutput $_;
		if (substr($_,0,29) eq "\t\t/// cache script hook start") {
			$write_status = 1;
			readflags();
		}
	} elsif ($write_status == 1) {
		if (substr($_,0,27) eq "\t\t/// cache script hook end") {
			writeoutput $_;
			$write_status = 2;
		}
	} else {
		writeoutput $_;	
	}
}
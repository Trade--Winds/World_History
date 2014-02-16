#!/usr/bin/perl -w

#
# author: Nightinggale
#
# Update XML files to add new tags to existing files
#

use strict;
use warnings;

# adding to files work as follows:
#
# A file is opened with openFile(path) where path is the path to the file from the XML directory
#
# updateFile(A,B) adds a new line.
# A is the tag it should be added after
# B is the line to add. This line will only be added if the following line
#    doesn't have the new tag (auto read from the new line).
#
# writeFile writes the changes to the file. updateFile() works in memory only for performance reasons.
#
#
# After writeFile has been called, the whole process can start over with openFile for a new file
#

# setup (global definitions, which has to be first)
my $xml_location = '../Assets/xml';
my $xml_source_location = $xml_location;
my $to_file = 1;
my $FILE = "INIT";
my @lines;
init();

# UnitInfo

openFile('Units/CIV4UnitInfos.xml');

updateFile ("DefaultProfession",       "<bNativesInvalid>0</bNativesInvalid>");
updateFile ("bNativesInvalid",         "<bEuropeInvalid>0</bEuropeInvalid>");
updateFile ("bEuropeInvalid",          "<bColonialInvalid>0</bColonialInvalid>");
updateFile ("bTreasure",               "<bAnimal>0</bAnimal>");
updateFile ("FeatureImpassables",      "<TerrainNatives/>");
updateFile ("TerrainNatives",          "<FeatureNatives/>");
updateFile ("FeatureNatives",          "<BonusNatives/>");
updateFile ("bWaterYieldChanges",      "<YieldDemands/>");
updateFile ("iTeacherWeight",          "<iTeachLevel>0</iTeachLevel>");
updateFile ("iTeachLevel",             "<iAnimalPatrolWeight>-1</iAnimalPatrolWeight>");
updateFile ("iAnimalPatrolWeight",     "<iAnimalAttackWeight>-1</iAnimalAttackWeight>");
updateFile ("iLeaderExperience",       "<ProfessionsNotAllowed/>");
updateFile ("ProfessionsNotAllowed",   "<KnightDubbingWeight>-1</KnightDubbingWeight>");
updateFile ("KnightDubbingWeight",     "<iCasteAttribute>0</iCasteAttribute>");
updateFile ("iCasteAttribute",         "<bPreventFounding>0</bPreventFounding>");
updateFile ("bPreventFounding",        "<bPreventTraveling>0</bPreventTraveling>");
updateFile ("bPreventTraveling",       "<EducationUnitClass>NONE</EducationUnitClass>");
updateFile ("EducationUnitClass",      "<RehibilitateUnitClass>NONE</RehibilitateUnitClass>");
updateFile ("RehibilitateUnitClass",   "<LaborForceUnitClass>NONE</LaborForceUnitClass>");
updateFile ("LaborForceUnitClass",     "<iTradeBonus>0</iTradeBonus>");
updateFile ("iTradeBonus",             "<ConvertsToYield>NONE</ConvertsToYield>");
updateFile ("ConvertsToYield",         "<ConvertsToBuildingClass>NONE</ConvertsToBuildingClass>");
updateFile ("ConvertsToBuildingClass", "<ConvertsToGold>0</ConvertsToGold>");

writeFile();

openFile('Units/CIV4ProfessionInfos.xml');
updateFile ("Button",       "<ProfessionSubTypes/>");
writeFile();

# end if setup. The following code handles actual file handling etc.

sub init
{
	my $source_dir = $xml_location . '/../../DLL_Sources';
	
	my $settings_file = $source_dir . '/Makefile.settings';
	
	if ( -e $settings_file )
	{
		open (READFILE, "< " . $settings_file) or die "Can't open file " . $settings_file . "\n" . $!;
		my @settings_lines = <READFILE>;
		close READFILE;
	
		foreach (@settings_lines)
		{
			if (substr($_, 0, 7) eq 'YOURMOD')
			{
				my $path = substr($_, 7);
				while (substr($path, 0, 1) eq " " or substr($path, 0, 1) eq "=")
				{
					$path = substr($path, 1);
				}
				
				if (substr($path, 1, 2) eq ":\\")
				{
					if ($^O eq 'MSWin32')
					{
						$xml_location = $path;
					} else {
						$xml_location = substr($path, 2);
					}
				}
				else
				{
					$xml_location = $source_dir . "/" . $path;
				}
				
				if ($^O ne 'MSWin32')
				{
					$xml_location =~ s/\\/\//g;
				}
				$xml_location =~ s/[\x0A\x0D]//g;
				chomp($xml_location);
				
				$xml_location = $xml_location . "/Assets/xml";

				print "Using XML location: " . $xml_location . "\n";
				return;
			}
		}
	}
	print "Using XML location: " . $xml_location . "\n";
}

sub writeoutput
{
	if ($to_file == 0) {
		print $_[0];
	} else {
		print WRITE_FILE $_[0];
	}
}

sub openFile
{
	$FILE = $_[0];
	
	if ($xml_source_location ne $xml_location)
	{
		if (index($FILE, "/") != -1)
		{
			my $subdir = substr($FILE, 0, index($FILE, "/"));
			
			my $schemaFile = "";
			my $dirname = $xml_source_location . "/" . $subdir;
			
			opendir my($dh), $dirname or die "Couldn't open dir '$dirname': $!";
			foreach (readdir $dh)
			{
				if (index($_, "Schema") != -1)
				{
					$schemaFile = $_;
				} 
			}
			closedir $dh;
			
			if ($schemaFile ne "" )
			{
				print "Copying " . $schemaFile . "\n";
				
				my $source_file = $dirname . "/" . $schemaFile;
				my $destination_file = $xml_location . "/" . $subdir . "/" . $schemaFile;
				
				open (READFILE, "< " . $source_file) or die "Can't open file " . $source_file . "\n" . $!;
				open (WRITE_FILE, "> " . $destination_file) or die "Can't open file " . $destination_file . "\n" . $!;
				
				foreach (<READFILE>)
				{
					print WRITE_FILE $_;
				}
				
				close READFILE;
				close WRITE_FILE;
			}
		}
	}
	print "Updating file $FILE\n";
	
	my $DESTINATION_FILE = $xml_location . '/' . $FILE;
	open (READFILE, "< " . $DESTINATION_FILE) or die "Can't open file " . $DESTINATION_FILE . "\n" . $!;
	@lines = <READFILE>;
	close READFILE;
}

sub writeFile
{
	my $DESTINATION_FILE = $xml_location . '/' . $FILE;
	if ($to_file != 0) {
		open (WRITE_FILE, "> " . $DESTINATION_FILE) or die "Can't open file " . $DESTINATION_FILE . "\n" . $!;
	}
	foreach (@lines)
	{
		writeoutput $_;
	}
	close WRITE_FILE;
}

sub updateFile
{
	my $KEYWORD = $_[0];
	my $LINE = $_[1];

	my $keyword_to_check_for = $LINE;

	my $end_index = index ($keyword_to_check_for, '>');

	if ($end_index != -1) {
		$keyword_to_check_for = substr($keyword_to_check_for, 0, $end_index);
	}

	$end_index = index ($keyword_to_check_for, '/');

	if ($end_index != -1) {
		$keyword_to_check_for = substr($keyword_to_check_for, 0, $end_index);
	}

	my $keyword_found = 0;
	my $prefix = '';
	my @temp_array;
	
	foreach (@lines)
	{
		if ($keyword_found == 0)
		{
			if (index($_, '</' . $KEYWORD . '>') != -1 or index($_, '<' . $KEYWORD . '/>') != -1)
			{
				$keyword_found = 1;
				$prefix = substr($_, 0, index($_, '<'));
			}
		} else {
			$keyword_found = 0;
			if (index($_, $keyword_to_check_for) == -1)
			{
				push ( @temp_array, $prefix . $LINE . "\n");
			}
		}
		push ( @temp_array, $_);
	}
	@lines = (@temp_array);
}


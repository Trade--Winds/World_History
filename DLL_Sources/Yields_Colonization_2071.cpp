//
// Yields_Colonization_2071.cpp
// Written by Nightinggale
//
#include "CvGameCoreDLL.h"
#include "CvGlobals.h"
#include "YieldsTestBase.h"

#ifdef COLONIZATION_2071

// AI sells unconditionally to natives and Europe unless they are raw materials as well
void Check_YieldGroup_AI_Sell::build()
{
	YieldVector.push_back(YIELD_EARTH_GOODS);
	YieldVector.push_back(YIELD_CONTRABAND);
}

// AI sells these in Europe
// AI can also sell unneeded raw materials even if they aren't listed here
void Check_YieldGroup_AI_Sell_To_Europe::build()
{
	YieldVector.push_back(YIELD_BASE_METALS);
	YieldVector.push_back(YIELD_ACTINIDES);
	YieldVector.push_back(YIELD_ISOTOPES);
	YieldVector.push_back(YIELD_RARE_EARTHS);
	YieldVector.push_back(YIELD_CRYSTALLOIDS);
	YieldVector.push_back(YIELD_NUCLEIC_ACIDS);
	YieldVector.push_back(YIELD_AMINO_ACIDS);
	YieldVector.push_back(YIELD_TISSUE_SAMPLES);
	YieldVector.push_back(YIELD_MICROBES);
	YieldVector.push_back(YIELD_DATACORES);
	YieldVector.push_back(YIELD_PROGENITOR_ARTIFACTS);
	YieldVector.push_back(YIELD_ALIEN_SPECIMENS);
	YieldVector.push_back(YIELD_PRECIOUS_METALS);
	YieldVector.push_back(YIELD_OPIATES);
	YieldVector.push_back(YIELD_XENOTOXINS);
	YieldVector.push_back(YIELD_BOTANICALS);
	YieldVector.push_back(YIELD_HYDROCARBONS);
	YieldVector.push_back(YIELD_CLATHRATES);
	YieldVector.push_back(YIELD_CORE_SAMPLES);
	YieldVector.push_back(YIELD_PHOTONICS);
	YieldVector.push_back(YIELD_PLASTEEL);
	YieldVector.push_back(YIELD_DURALLOY);
	YieldVector.push_back(YIELD_CRYSTALLOY);
	YieldVector.push_back(YIELD_NUCLEONICS);
	YieldVector.push_back(YIELD_EARTHLING_SPECIMENS);

	YieldVector.push_back(YIELD_FUSION_CORES);
	YieldVector.push_back(YIELD_SEMICONDUCTORS);
	YieldVector.push_back(YIELD_PLASMIDS);
	YieldVector.push_back(YIELD_ENZYMES);
	YieldVector.push_back(YIELD_STEM_CELLS);
	YieldVector.push_back(YIELD_STATE_SECRETS);
	YieldVector.push_back(YIELD_PROGENITOR_TECH);
	YieldVector.push_back(YIELD_ALIEN_RELICS);
	YieldVector.push_back(YIELD_NARCOTICS);
	YieldVector.push_back(YIELD_BIOWEAPONS);
	YieldVector.push_back(YIELD_PHARMACEUTICALS);
	YieldVector.push_back(YIELD_PETROCHEMICALS);
	YieldVector.push_back(YIELD_COLLOIDS);
	YieldVector.push_back(YIELD_CATALYSTS);
	YieldVector.push_back(YIELD_HARD_CURRENCY);
}

// AI attemps to buy from natives as needed (or whenever offered?)
void Check_YieldGroup_AI_Buy_From_Natives::build()
{
	YieldVector.push_back(YIELD_ACTINIDES);
	YieldVector.push_back(YIELD_ISOTOPES);
	YieldVector.push_back(YIELD_RARE_EARTHS);
	YieldVector.push_back(YIELD_CRYSTALLOIDS);
	YieldVector.push_back(YIELD_NUCLEIC_ACIDS);
	YieldVector.push_back(YIELD_AMINO_ACIDS);
	YieldVector.push_back(YIELD_TISSUE_SAMPLES);
	YieldVector.push_back(YIELD_MICROBES);
	YieldVector.push_back(YIELD_DATACORES);
	YieldVector.push_back(YIELD_PROGENITOR_ARTIFACTS);
	YieldVector.push_back(YIELD_ALIEN_SPECIMENS);
	YieldVector.push_back(YIELD_PRECIOUS_METALS);
	YieldVector.push_back(YIELD_OPIATES);
	YieldVector.push_back(YIELD_XENOTOXINS);
	YieldVector.push_back(YIELD_BOTANICALS);
	YieldVector.push_back(YIELD_HYDROCARBONS);
	YieldVector.push_back(YIELD_CLATHRATES);
	YieldVector.push_back(YIELD_CORE_SAMPLES);
}

// AI attemps to buy from Europe (Europe as in vanilla functionality)
void Check_YieldGroup_AI_Buy_From_Europe::build()
{
	YieldVector.push_back(YIELD_EARTH_GOODS);
	YieldVector.push_back(YIELD_CONTRABAND);
	YieldVector.push_back(YIELD_MACHINE_TOOLS);
	YieldVector.push_back(YIELD_MUNITIONS);
	YieldVector.push_back(YIELD_ROBOTICS);
}

// AI sells unless they are needed
// Used for production building input like ore, cotton etc.
void Check_YieldGroup_AI_Raw_Material::build()
{
	YieldVector.push_back(YIELD_NUTRIENTS);
	YieldVector.push_back(YIELD_BIOPOLYMERS);
	YieldVector.push_back(YIELD_SILICATES);
	YieldVector.push_back(YIELD_BASE_METALS);
	YieldVector.push_back(YIELD_MACHINE_TOOLS);
	YieldVector.push_back(YIELD_PHOTONICS);
	YieldVector.push_back(YIELD_PLASTEEL);
	YieldVector.push_back(YIELD_DURALLOY);
	YieldVector.push_back(YIELD_CRYSTALLOY);
}

// Set yields the natives will produce
// Natives will also produce yields, which has bIsNativeTrade set in XML
// Other code might give natives the ability to produce even more yields.
//   They can produce yields, which is accepted by any one of the options.
void Check_YieldGroup_AI_Native_Product::build()
{
}

// Yields to show up on city billboards
void Check_YieldGroup_City_Billboard::build()
{
}

// yields, which are affected by an off by one offset error when displaying billboard icons
// TODO: find the real culprint of this bug instead of working around it.
void Check_YieldGroup_City_Billboard_Offset_Fix::build()
{
}

// yield is either light or heavy armor (not both)
void Check_YieldGroup_Armor::build()
{
}

// yield is light armor
void Check_YieldGroup_Light_Armor::build()
{
}

// yield is heavy armor
void Check_YieldGroup_Heavy_Armor::build()
{
}

// check YieldTypes vs XML yield names
void BaseCheckYieldGroup::checkXML()
{
	// first argument is YieldTypes enum value while the second is the name in XML
	checkSingleXMLType(YIELD_NUTRIENTS,            "YIELD_NUTRIENTS");
	checkSingleXMLType(YIELD_BIOPOLYMERS,          "YIELD_BIOPOLYMERS");
	checkSingleXMLType(YIELD_SILICATES,            "YIELD_SILICATES");
	checkSingleXMLType(YIELD_BASE_METALS,          "YIELD_BASE_METALS");
	checkSingleXMLType(YIELD_ACTINIDES,            "YIELD_ACTINIDES");
	checkSingleXMLType(YIELD_ISOTOPES,             "YIELD_ISOTOPES");
	checkSingleXMLType(YIELD_RARE_EARTHS,          "YIELD_RARE_EARTHS");
	checkSingleXMLType(YIELD_CRYSTALLOIDS,         "YIELD_CRYSTALLOIDS");
	checkSingleXMLType(YIELD_NUCLEIC_ACIDS,        "YIELD_NUCLEIC_ACIDS");
	checkSingleXMLType(YIELD_AMINO_ACIDS,          "YIELD_AMINO_ACIDS");
	checkSingleXMLType(YIELD_TISSUE_SAMPLES,       "YIELD_TISSUE_SAMPLES");
	checkSingleXMLType(YIELD_MICROBES,             "YIELD_MICROBES");
	checkSingleXMLType(YIELD_DATACORES,            "YIELD_DATACORES");
	checkSingleXMLType(YIELD_PROGENITOR_ARTIFACTS, "YIELD_PROGENITOR_ARTIFACTS");
	checkSingleXMLType(YIELD_ALIEN_SPECIMENS,      "YIELD_ALIEN_SPECIMENS");
	checkSingleXMLType(YIELD_PRECIOUS_METALS,      "YIELD_PRECIOUS_METALS");
	checkSingleXMLType(YIELD_OPIATES,              "YIELD_OPIATES");
	checkSingleXMLType(YIELD_XENOTOXINS,           "YIELD_XENOTOXINS");
	checkSingleXMLType(YIELD_BOTANICALS,           "YIELD_BOTANICALS");
	checkSingleXMLType(YIELD_HYDROCARBONS,         "YIELD_HYDROCARBONS");
	checkSingleXMLType(YIELD_CLATHRATES,           "YIELD_CLATHRATES");
	checkSingleXMLType(YIELD_CORE_SAMPLES,         "YIELD_CORE_SAMPLES");
	checkSingleXMLType(YIELD_MACHINE_TOOLS,        "YIELD_MACHINE_TOOLS");
	checkSingleXMLType(YIELD_ROBOTICS,             "YIELD_ROBOTICS");
	checkSingleXMLType(YIELD_MUNITIONS,            "YIELD_MUNITIONS");
	checkSingleXMLType(YIELD_PHOTONICS,            "YIELD_PHOTONICS");
	checkSingleXMLType(YIELD_PLASTEEL,             "YIELD_PLASTEEL");
	checkSingleXMLType(YIELD_DURALLOY,             "YIELD_DURALLOY");
	checkSingleXMLType(YIELD_CRYSTALLOY,           "YIELD_CRYSTALLOY");
	checkSingleXMLType(YIELD_NUCLEONICS,           "YIELD_NUCLEONICS");
	checkSingleXMLType(YIELD_FUSION_CORES,         "YIELD_FUSION_CORES");
	checkSingleXMLType(YIELD_SEMICONDUCTORS,       "YIELD_SEMICONDUCTORS");
	checkSingleXMLType(YIELD_PLASMIDS,             "YIELD_PLASMIDS");
	checkSingleXMLType(YIELD_ENZYMES,              "YIELD_ENZYMES");
	checkSingleXMLType(YIELD_STEM_CELLS,           "YIELD_STEM_CELLS");
	checkSingleXMLType(YIELD_STATE_SECRETS,        "YIELD_STATE_SECRETS");
	checkSingleXMLType(YIELD_PROGENITOR_TECH,      "YIELD_PROGENITOR_TECH");
	checkSingleXMLType(YIELD_ALIEN_RELICS,         "YIELD_ALIEN_RELICS");
	checkSingleXMLType(YIELD_NARCOTICS,            "YIELD_NARCOTICS");
	checkSingleXMLType(YIELD_BIOWEAPONS,           "YIELD_BIOWEAPONS");
	checkSingleXMLType(YIELD_PHARMACEUTICALS,      "YIELD_PHARMACEUTICALS");
	checkSingleXMLType(YIELD_PETROCHEMICALS,       "YIELD_PETROCHEMICALS");
	checkSingleXMLType(YIELD_COLLOIDS,             "YIELD_COLLOIDS");
	checkSingleXMLType(YIELD_CATALYSTS,            "YIELD_CATALYSTS");
	checkSingleXMLType(YIELD_HARD_CURRENCY,        "YIELD_HARD_CURRENCY");
	checkSingleXMLType(YIELD_EARTH_GOODS,          "YIELD_EARTH_GOODS");
	checkSingleXMLType(YIELD_CONTRABAND,           "YIELD_CONTRABAND");
	checkSingleXMLType(YIELD_EARTHLING_SPECIMENS,  "YIELD_EARTHLING_SPECIMENS");
	checkSingleXMLType(YIELD_INDUSTRY,             "YIELD_INDUSTRY");
	checkSingleXMLType(YIELD_MEDIA,                "YIELD_MEDIA");
	checkSingleXMLType(YIELD_LIBERTY,              "YIELD_LIBERTY");
	checkSingleXMLType(YIELD_RESEARCH,             "YIELD_RESEARCH");
	checkSingleXMLType(YIELD_EDUCATION,            "YIELD_EDUCATION");
	checkSingleXMLType(YIELD_INFLUENCE,            "YIELD_INFLUENCE");
	checkSingleXMLType(YIELD_ENERGY,               "YIELD_ENERGY");
	checkSingleXMLType(YIELD_POLLUTANTS,           "YIELD_POLLUTANTS");
	checkSingleXMLType(YIELD_CREDITS,              "YIELD_CREDITS");
}
#endif // COLONIZATION_2071

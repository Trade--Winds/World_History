#pragma once

#ifndef YIELDS_COLONIZATION_2071_H
#define YIELDS_COLONIZATION_2071_H

//
// Yields_Colonization_2071.h
// Written by Nightinggale
//

#ifdef COLONIZATION_2071

// keep this enum in sync with python::enum_<YieldTypes>("YieldTypes") in CyEnumsInterface.cpp

enum DllExport YieldTypes
{
	NO_YIELD = -1,

	YIELD_NUTRIENTS,
	YIELD_BIOPOLYMERS,
	YIELD_SILICATES,
	YIELD_BASE_METALS,
	YIELD_PRECIOUS_METALS,
	YIELD_ISOTOPES,
	YIELD_URANIUM,
	YIELD_RARE_EARTHS,
	YIELD_CRYSTALLOIDS,
	YIELD_TISSUE_SAMPLES,
	YIELD_YIELD_NUCLEIC_ACIDS,
	YIELD_AMINO_ACIDS,
	YIELD_MICROBES,
	YIELD_PROGENITOR_ARTIFACTS,
	YIELD_ALIEN_SPECIMENS,
	YIELD_ENCRYPTED_DATA,
	YIELD_OPIATES,
	YIELD_XENOTOXINS,
	YIELD_BOTANICALS,
	YIELD_HYDROCARBONS,
	YIELD_HALOGENS,
	YIELD_CORE_SAMPLES,

	// next 4 have hardcoded names
	YIELD_TOOLS,
	YIELD_WEAPONS,
	YIELD_HORSES,
	YIELD_TRADE_GOODS,
	
	// virtual yields
	YIELD_HAMMERS,
	YIELD_BELLS,
	YIELD_CROSSES,
	YIELD_EDUCATION,
	YIELD_IDEAS,
	YIELD_CULTURE,
    YIELD_GOLD,

#ifdef _USRDLL
	NUM_YIELD_TYPES,
#endif

	YIELD_FROM_ANIMALS = NO_YIELD,

	// name connection with hardcoded names
	YIELD_FOOD        = YIELD_NUTRIENTS,
	YIELD_LUMBER      = YIELD_BIOPOLYMERS,
	YIELD_STONE       = YIELD_SILICATES,
	YIELD_ORE         = YIELD_BASE_METALS,
	//YIELD_TOOLS       = YIELD_TOOLS,
	//YIELD_WEAPONS     = YIELD_WEAPONS,
	//YIELD_HORSES      = YIELD_HORSES,
	//YIELD_TRADE_GOODS = YIELD_TRADE_GOODS,

};

static inline bool YieldGroup_AI_Sell(YieldTypes eYield)
{
	return eYield == YIELD_TRADE_GOODS;
}

static inline bool YieldGroup_AI_Sell_To_Europe(YieldTypes eYield)
{
	return eYield == YIELD_ORE;
}

static inline bool YieldGroup_AI_Buy_From_Natives(YieldTypes eYield)
{
	return eYield == YIELD_TOOLS;
}

static inline bool YieldGroup_AI_Buy_From_Europe(YieldTypes eYield)
{
	return eYield >= YIELD_TOOLS && eYield <= YIELD_TRADE_GOODS;
}

static inline bool YieldGroup_AI_Raw_Material(YieldTypes eYield)
{
	return eYield == YIELD_ORE || eYield == YIELD_STONE;
}

static inline bool YieldGroup_AI_Native_Product(YieldTypes eYield)
{
	return false;
}

static inline bool YieldGroup_City_Billboard(YieldTypes eYield)
{
	return eYield == YIELD_HORSES || eYield == YIELD_TOOLS;
}

static inline bool YieldGroup_City_Billboard_Offset_Fix(YieldTypes eYield)
{
	return eYield == YIELD_HORSES || eYield == YIELD_TOOLS;
}

static inline bool YieldGroup_Armor(YieldTypes eYield)
{
	return false;
}

static inline bool YieldGroup_Light_Armor(YieldTypes eYield)
{
	return false;
}

static inline bool YieldGroup_Heavy_Armor(YieldTypes eYield)
{
	return false;
}

static inline bool YieldGroup_Luxury_Food(YieldTypes eYield)
{
	return false;
}

#endif // COLONIZATION_2071

#endif	// YIELDS_MEDIEVAL_TECH_H

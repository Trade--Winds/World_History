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

	YIELD_FOOD,///0
	///TKs ME
	//YIELD_GRAIN,///1NEW*
	//YIELD_CATTLE,///2/NEW*
	//YIELD_SHEEP,///3/NEW*
	//YIELD_WOOL,///4NEW*
	//YIELD_SALT,///5NEW*
	YIELD_LUMBER,///6
	YIELD_STONE,///7NEW*
//	YIELD_LEATHER,///20NEW*
	//YIELD_SILVER,///8
	//YIELD_GOLD,///9/NEW*
//	YIELD_IVORY,//9/NEW*
    //YIELD_SALT,///5NEW*
	//YIELD_SPICES,///10NEW*
	//YIELD_FUR,///11
	//YIELD_COTTON,///12
	//YIELD_BARLEY,///13YIELD_SUGAR,
	//YIELD_GRAPES,///14YIELD_TOBACCO,
	YIELD_ORE,///15
	//YIELD_CLOTH,///16
	//YIELD_COATS,///17
	//YIELD_ALE,///18YIELD_RUM,
	//YIELD_WINE,///19YIELD_CIGARS,
	YIELD_TOOLS,///20
	YIELD_WEAPONS,///21YIELD_MUSKETS,
	YIELD_HORSES,///22
	//YIELD_LEATHER_ARMOR,///23NEW*
	//YIELD_SCALE_ARMOR,///24NEW*
	//YIELD_MAIL_ARMOR,///25NEW*
	//YIELD_PLATE_ARMOR,///26NEW*
	YIELD_TRADE_GOODS,///27
//	YIELD_SILK,///29NEW*
//	YIELD_PORCELAIN,///30NEW*
	YIELD_HAMMERS,///28
	YIELD_BELLS,///29
	YIELD_CROSSES,///30
	YIELD_EDUCATION,///31
	///TKs Invention Core Mod v 1.0
	YIELD_IDEAS,///32
	YIELD_CULTURE,///33
    YIELD_GOLD,///34/NEW*

	///TKe

#ifdef _USRDLL
	NUM_YIELD_TYPES,
#endif

	YIELD_FROM_ANIMALS = NO_YIELD,
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

#pragma once

#ifndef YIELDS_H
#define YIELDS_H

//
// Yields.h
// Written by Nightinggale
//

#include "CvDefines.h"

enum DllExport YieldTypes
{
	NO_YIELD = -1,

	YIELD_FOOD,///0
	///TKs ME
	YIELD_GRAIN,///1NEW*
	YIELD_CATTLE,///2/NEW*
	YIELD_SHEEP,///3/NEW*
	YIELD_WOOL,///4NEW*
	//YIELD_SALT,///5NEW*
	YIELD_LUMBER,///6
	YIELD_STONE,///7NEW*
//	YIELD_LEATHER,///20NEW*
	YIELD_SILVER,///8
	//YIELD_GOLD,///9/NEW*
//	YIELD_IVORY,//9/NEW*
    YIELD_SALT,///5NEW*
	YIELD_SPICES,///10NEW*
	YIELD_FUR,///11
	YIELD_COTTON,///12
	YIELD_BARLEY,///13YIELD_SUGAR,
	YIELD_GRAPES,///14YIELD_TOBACCO,
	YIELD_ORE,///15
	YIELD_CLOTH,///16
	YIELD_COATS,///17
	YIELD_ALE,///18YIELD_RUM,
	YIELD_WINE,///19YIELD_CIGARS,
	YIELD_TOOLS,///20
	YIELD_WEAPONS,///21YIELD_MUSKETS,
	YIELD_HORSES,///22
	YIELD_LEATHER_ARMOR,///23NEW*
	YIELD_SCALE_ARMOR,///24NEW*
	YIELD_MAIL_ARMOR,///25NEW*
	YIELD_PLATE_ARMOR,///26NEW*
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
	NUM_YIELD_TYPES
#endif
};

static inline bool YieldIsBonusResource(YieldTypes eYield)
{
	return eYield >= YIELD_SILVER && eYield <= YIELD_WINE && eYield != YIELD_SPICES;
}

static inline bool YieldGroup_AI_Sell(YieldTypes eYield)
{
	return (eYield >= YIELD_CLOTH && eYield <= YIELD_WINE) || eYield == YIELD_SILVER || eYield == YIELD_TRADE_GOODS;
}

static inline bool YieldGroup_AI_Sell_To_Europe(YieldTypes eYield)
{
	return (eYield >= YIELD_SILVER && eYield <= YIELD_WINE) || (eYield >= YIELD_CATTLE && eYield <= YIELD_WOOL);
}

static inline bool YieldGroup_AI_Buy_From_Natives(YieldTypes eYield)
{
	return eYield == YIELD_SPICES || eYield == YIELD_TOOLS || eYield ==  YIELD_GRAIN || eYield == YIELD_CATTLE;
}

static inline bool YieldGroup_AI_Buy_From_Europe(YieldTypes eYield)
{
	return (eYield >= YIELD_TOOLS && eYield <= YIELD_TRADE_GOODS) || eYield == YIELD_SPICES;
}

static inline bool YieldGroup_AI_Raw_Material(YieldTypes eYield)
{
	return (eYield >= YIELD_SALT && eYield <= YIELD_ORE) || (eYield <= YIELD_STONE && eYield >= YIELD_CATTLE && eYield != YIELD_LUMBER);
}

// virtual means it can't be loaded into a ship, meaning it's yields like crosses and bells.
// Invert the output from this group and you will only get yields, which can be loaded into ships.
static inline bool YieldGroup_Virtual(YieldTypes eYield)
{
	// Vanilla assumes hammers to be the first virtual yield. This is deeply hardcoded in C++ as well as python.
	return eYield >= YIELD_HAMMERS;
}

#endif	// YIELDS_H

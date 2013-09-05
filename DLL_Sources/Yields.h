#pragma once

#ifndef YIELDS_H
#define YIELDS_H

//
// Yields.h
// Written by Nightinggale
//

#include "CvDefines.h"

#include "Yields_Medieval_Tech.h"
#include "Yields_Colonization_2071.h"

// virtual means it can't be loaded into a ship, meaning it's yields like crosses and bells.
// Invert the output from this group and you will only get yields, which can be loaded into ships.
static inline bool YieldGroup_Virtual(YieldTypes eYield)
{
	// Vanilla assumes hammers to be the first virtual yield. This is deeply hardcoded in C++ as well as python.
	return eYield >= YIELD_HAMMERS;
}

#endif	// YIELDS_H

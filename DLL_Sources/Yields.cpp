//
// Yields.cpp
// Written by Nightinggale
//
#include "CvGameCoreDLL.h"
#include "CvGlobals.h"
#include "YieldsTestBase.h"

void BaseCheckYieldGroup::build()
{
	FAssertMsg(false, "The base function shouldn't call this virtual function");
}

bool BaseCheckYieldGroup::function(YieldTypes eYield)
{
	FAssertMsg(false, "The base function shouldn't call this virtual function");
	return false;
}

void BaseCheckYieldGroup::check()
{
	this->build();

	bool checklist[NUM_YIELD_TYPES];

	for (int i = 0; i < NUM_YIELD_TYPES; i++)
	{
		checklist[i] = false;
	}

	for(unsigned int iYield = 0; iYield < YieldVector.size(); iYield++) {
		FAssert(YieldVector[iYield] < NUM_YIELD_TYPES);
		FAssert(YieldVector[iYield] >= 0);
		checklist[YieldVector[iYield]] = true;
	}

	for (int i = 0; i < NUM_YIELD_TYPES; i++)
	{
		YieldTypes eYield = (YieldTypes)i;
		if (checklist[i])
		{
			FAssertMsg(this->function(eYield), CvString::format("Yield %s missing in %s", GC.getYieldInfo(eYield).getType(), func_name).c_str());
		} else {
			FAssertMsg(!this->function(eYield), CvString::format("Yield %s is a false positive in %s", GC.getYieldInfo(eYield).getType(), func_name).c_str());
		}
	}
}

void CvGlobals::CheckEnumYieldTypes() const
{
#ifdef FASSERT_ENABLE
	BaseCheckYieldGroup BaseGroup;
	BaseGroup.checkXML();
	FAssertMsg(GC.getYieldInfo().size() == NUM_YIELD_TYPES, CvString::format("XML error. Expected %d types, but found %d", NUM_YIELD_TYPES, GC.getYieldInfo().size()));

	Check_YieldGroup_AI_Sell AI_Sell;
	AI_Sell.check();
	Check_YieldGroup_AI_Sell_To_Europe AI_Sell_To_Europe;
	AI_Sell_To_Europe.check();
	Check_YieldGroup_AI_Buy_From_Natives AI_Buy_From_Natives;
	AI_Buy_From_Natives.check();
	Check_YieldGroup_AI_Buy_From_Europe AI_Buy_From_Europe;
	AI_Buy_From_Europe.check();
	Check_YieldGroup_AI_Raw_Material AI_Raw_Material;
	AI_Raw_Material.check();
#endif
}
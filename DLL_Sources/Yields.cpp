//
// Yields.cpp
// Written by Nightinggale
//
#include "CvGameCoreDLL.h"
#include "CvGlobals.h"

class BaseCheckYieldGroup
{
public:
	BaseCheckYieldGroup() { func_name = "error"; }
protected:
	char *func_name;
	std::vector<YieldTypes> YieldVector;
	virtual bool function(YieldTypes eYield);
	virtual void build();
public:
	void check();
};

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

class CheckYieldIsBonusResource: public BaseCheckYieldGroup
{
public:
	CheckYieldIsBonusResource() { func_name = "YieldIsBonusResource"; }
	bool function(YieldTypes eYield) {return YieldIsBonusResource(eYield);}
	void build();
};

class Check_YieldGroup_AI_Sell: public BaseCheckYieldGroup
{
public:
	Check_YieldGroup_AI_Sell() { func_name = "YieldGroup_AI_Sell"; }
	bool function(YieldTypes eYield) {return YieldGroup_AI_Sell(eYield);}
	void build();
};

class Check_YieldGroup_AI_Buy_From_Natives: public BaseCheckYieldGroup
{
public:
	Check_YieldGroup_AI_Buy_From_Natives() { func_name = "YieldGroup_AI_Buy_From_Natives"; }
	bool function(YieldTypes eYield) {return YieldGroup_AI_Buy_From_Natives(eYield);}
	void build();
};

class Check_YieldGroup_AI_Raw_Material: public BaseCheckYieldGroup
{
public:
	Check_YieldGroup_AI_Raw_Material() { func_name = "YieldGroup_AI_Raw_Material"; }
	bool function(YieldTypes eYield) {return YieldGroup_AI_Raw_Material(eYield);}
	void build();
};

void CheckYieldIsBonusResource::build()
{
	YieldVector.push_back(YIELD_SALT);
	YieldVector.push_back(YIELD_SILVER);
	YieldVector.push_back(YIELD_COTTON);
	YieldVector.push_back(YIELD_FUR);
	YieldVector.push_back(YIELD_BARLEY);
	YieldVector.push_back(YIELD_GRAPES);
	YieldVector.push_back(YIELD_ORE);
	YieldVector.push_back(YIELD_CLOTH);
	YieldVector.push_back(YIELD_COATS);
	YieldVector.push_back(YIELD_ALE);
	YieldVector.push_back(YIELD_WINE);
}

// AI sells unconditionally unless they are raw materials as well
void Check_YieldGroup_AI_Sell::build()
{
	YieldVector.push_back(YIELD_SILVER);
	YieldVector.push_back(YIELD_CLOTH);
	YieldVector.push_back(YIELD_COATS);
	YieldVector.push_back(YIELD_ALE);
	YieldVector.push_back(YIELD_WINE);
	YieldVector.push_back(YIELD_TRADE_GOODS);
}

// AI attemps to buy from natives as needed (or whenever offered?)
void Check_YieldGroup_AI_Buy_From_Natives::build()
{
	YieldVector.push_back(YIELD_SPICES);
	YieldVector.push_back(YIELD_TOOLS);
	YieldVector.push_back(YIELD_GRAIN);
	YieldVector.push_back(YIELD_CATTLE);
}

// AI sells unless they are needed
// Used for production building input like ore, cotton etc.
void Check_YieldGroup_AI_Raw_Material::build()
{
	YieldVector.push_back(YIELD_COTTON);
	YieldVector.push_back(YIELD_BARLEY);
	YieldVector.push_back(YIELD_GRAPES);
	YieldVector.push_back(YIELD_ORE);
	YieldVector.push_back(YIELD_CATTLE);
	YieldVector.push_back(YIELD_SPICES);
	YieldVector.push_back(YIELD_SHEEP);
	YieldVector.push_back(YIELD_WOOL);
	YieldVector.push_back(YIELD_SALT);
	YieldVector.push_back(YIELD_STONE);
	YieldVector.push_back(YIELD_FUR);
}


static void CheckYieldGroupFunctions()
{
#ifdef FASSERT_ENABLE
	CheckYieldIsBonusResource a;
	a.check();
	Check_YieldGroup_AI_Sell AI_Sell;
	AI_Sell.check();
	Check_YieldGroup_AI_Buy_From_Natives AI_Buy_From_Natives;
	AI_Buy_From_Natives.check();
	Check_YieldGroup_AI_Raw_Material AI_Raw_Material;
	AI_Raw_Material.check();
#endif
}

void CvGlobals::CheckEnumYieldTypes() const
{
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_FOOD).getType(), "YIELD_FOOD"), CvString::format("XML error. Found %s instead of YIELD_FOOD at index %d", GC.getYieldInfo(YIELD_FOOD).getType(), YIELD_FOOD).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_GRAIN).getType(), "YIELD_GRAIN"), CvString::format("XML error. Found %s instead of YIELD_GRAIN at index %d", GC.getYieldInfo(YIELD_GRAIN).getType(), YIELD_GRAIN).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_CATTLE).getType(), "YIELD_CATTLE"), CvString::format("XML error. Found %s instead of YIELD_CATTLE at index %d", GC.getYieldInfo(YIELD_CATTLE).getType(), YIELD_CATTLE).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_SHEEP).getType(), "YIELD_SHEEP"), CvString::format("XML error. Found %s instead of YIELD_SHEEP at index %d", GC.getYieldInfo(YIELD_SHEEP).getType(), YIELD_SHEEP).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_WOOL).getType(), "YIELD_WOOL"), CvString::format("XML error. Found %s instead of YIELD_WOOL at index %d", GC.getYieldInfo(YIELD_WOOL).getType(), YIELD_WOOL).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_LUMBER).getType(), "YIELD_LUMBER"), CvString::format("XML error. Found %s instead of YIELD_LUMBER at index %d", GC.getYieldInfo(YIELD_LUMBER).getType(), YIELD_LUMBER).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_STONE).getType(), "YIELD_STONE"), CvString::format("XML error. Found %s instead of YIELD_STONE at index %d", GC.getYieldInfo(YIELD_STONE).getType(), YIELD_STONE).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_SILVER).getType(), "YIELD_SILVER"), CvString::format("XML error. Found %s instead of YIELD_SILVER at index %d", GC.getYieldInfo(YIELD_SILVER).getType(), YIELD_SILVER).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_SALT).getType(), "YIELD_SALT"), CvString::format("XML error. Found %s instead of YIELD_SALT at index %d", GC.getYieldInfo(YIELD_SALT).getType(), YIELD_SALT).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_SPICES).getType(), "YIELD_SPICES"), CvString::format("XML error. Found %s instead of YIELD_SPICES at index %d", GC.getYieldInfo(YIELD_SPICES).getType(), YIELD_SPICES).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_FUR).getType(), "YIELD_FUR"), CvString::format("XML error. Found %s instead of YIELD_FUR at index %d", GC.getYieldInfo(YIELD_FUR).getType(), YIELD_FUR).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_COTTON).getType(), "YIELD_COTTON"), CvString::format("XML error. Found %s instead of YIELD_COTTON at index %d", GC.getYieldInfo(YIELD_COTTON).getType(), YIELD_COTTON).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_BARLEY).getType(), "YIELD_BARLEY"), CvString::format("XML error. Found %s instead of YIELD_BARLEY at index %d", GC.getYieldInfo(YIELD_BARLEY).getType(), YIELD_BARLEY).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_GRAPES).getType(), "YIELD_GRAPES"), CvString::format("XML error. Found %s instead of YIELD_GRAPES at index %d", GC.getYieldInfo(YIELD_GRAPES).getType(), YIELD_GRAPES).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_ORE).getType(), "YIELD_ORE"), CvString::format("XML error. Found %s instead of YIELD_ORE at index %d", GC.getYieldInfo(YIELD_ORE).getType(), YIELD_ORE).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_CLOTH).getType(), "YIELD_CLOTH"), CvString::format("XML error. Found %s instead of YIELD_CLOTH at index %d", GC.getYieldInfo(YIELD_CLOTH).getType(), YIELD_CLOTH).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_COATS).getType(), "YIELD_COATS"), CvString::format("XML error. Found %s instead of YIELD_COATS at index %d", GC.getYieldInfo(YIELD_COATS).getType(), YIELD_COATS).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_ALE).getType(), "YIELD_ALE"), CvString::format("XML error. Found %s instead of YIELD_ALE at index %d", GC.getYieldInfo(YIELD_ALE).getType(), YIELD_ALE).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_WINE).getType(), "YIELD_WINE"), CvString::format("XML error. Found %s instead of YIELD_WINE at index %d", GC.getYieldInfo(YIELD_WINE).getType(), YIELD_WINE).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_TOOLS).getType(), "YIELD_TOOLS"), CvString::format("XML error. Found %s instead of YIELD_TOOLS at index %d", GC.getYieldInfo(YIELD_TOOLS).getType(), YIELD_TOOLS).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_WEAPONS).getType(), "YIELD_WEAPONS"), CvString::format("XML error. Found %s instead of YIELD_WEAPONS at index %d", GC.getYieldInfo(YIELD_WEAPONS).getType(), YIELD_WEAPONS).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_HORSES).getType(), "YIELD_HORSES"), CvString::format("XML error. Found %s instead of YIELD_HORSES at index %d", GC.getYieldInfo(YIELD_HORSES).getType(), YIELD_HORSES).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_LEATHER_ARMOR).getType(), "YIELD_LEATHER_ARMOR"), CvString::format("XML error. Found %s instead of YIELD_LEATHER_ARMOR at index %d", GC.getYieldInfo(YIELD_LEATHER_ARMOR).getType(), YIELD_LEATHER_ARMOR).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_SCALE_ARMOR).getType(), "YIELD_SCALE_ARMOR"), CvString::format("XML error. Found %s instead of YIELD_SCALE_ARMOR at index %d", GC.getYieldInfo(YIELD_SCALE_ARMOR).getType(), YIELD_SCALE_ARMOR).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_MAIL_ARMOR).getType(), "YIELD_MAIL_ARMOR"), CvString::format("XML error. Found %s instead of YIELD_MAIL_ARMOR at index %d", GC.getYieldInfo(YIELD_MAIL_ARMOR).getType(), YIELD_MAIL_ARMOR).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_PLATE_ARMOR).getType(), "YIELD_PLATE_ARMOR"), CvString::format("XML error. Found %s instead of YIELD_PLATE_ARMOR at index %d", GC.getYieldInfo(YIELD_PLATE_ARMOR).getType(), YIELD_PLATE_ARMOR).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_TRADE_GOODS).getType(), "YIELD_TRADE_GOODS"), CvString::format("XML error. Found %s instead of YIELD_TRADE_GOODS at index %d", GC.getYieldInfo(YIELD_TRADE_GOODS).getType(), YIELD_TRADE_GOODS).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_HAMMERS).getType(), "YIELD_HAMMERS"), CvString::format("XML error. Found %s instead of YIELD_HAMMERS at index %d", GC.getYieldInfo(YIELD_HAMMERS).getType(), YIELD_HAMMERS).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_BELLS).getType(), "YIELD_BELLS"), CvString::format("XML error. Found %s instead of YIELD_BELLS at index %d", GC.getYieldInfo(YIELD_BELLS).getType(), YIELD_BELLS).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_CROSSES).getType(), "YIELD_CROSSES"), CvString::format("XML error. Found %s instead of YIELD_CROSSES at index %d", GC.getYieldInfo(YIELD_CROSSES).getType(), YIELD_CROSSES).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_EDUCATION).getType(), "YIELD_EDUCATION"), CvString::format("XML error. Found %s instead of YIELD_EDUCATION at index %d", GC.getYieldInfo(YIELD_EDUCATION).getType(), YIELD_EDUCATION).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_IDEAS).getType(), "YIELD_IDEAS"), CvString::format("XML error. Found %s instead of YIELD_IDEAS at index %d", GC.getYieldInfo(YIELD_IDEAS).getType(), YIELD_IDEAS).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_CULTURE).getType(), "YIELD_CULTURE"), CvString::format("XML error. Found %s instead of YIELD_CULTURE at index %d", GC.getYieldInfo(YIELD_CULTURE).getType(), YIELD_CULTURE).c_str());
	FAssertMsg(!strcmp(GC.getYieldInfo(YIELD_GOLD).getType(), "YIELD_GOLD"), CvString::format("XML error. Found %s instead of YIELD_GOLD at index %d", GC.getYieldInfo(YIELD_GOLD).getType(), YIELD_GOLD).c_str());

	FAssertMsg(GC.getYieldInfo().size() == NUM_YIELD_TYPES, CvString::format("XML error. Expected %d types, but found %d", NUM_YIELD_TYPES, GC.getYieldInfo().size()));

	CheckYieldGroupFunctions();
}

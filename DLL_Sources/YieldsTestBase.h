//
// YieldsTestBase.h
// Written by Nightinggale
//

#include "Yields.h"

class BaseCheckYieldGroup
{
public:
	BaseCheckYieldGroup()
	{
		func_name = "error";
		bAllowVirtual = false;
	}

	bool XMLnameChecked[NUM_YIELD_TYPES];
protected:
	bool bAllowVirtual;
	char *func_name;
	std::vector<YieldTypes> YieldVector;

	virtual bool function(YieldTypes eYield);
	virtual void build();
	void checkSingleXMLType(YieldTypes eYield, const char* XMLname);
public:
	void check();
	void checkXML();
};

class Check_YieldGroup_AI_Sell: public BaseCheckYieldGroup
{
public:
	Check_YieldGroup_AI_Sell() { func_name = "YieldGroup_AI_Sell"; }
	bool function(YieldTypes eYield) {return YieldGroup_AI_Sell(eYield);}
	void build();
};

class Check_YieldGroup_AI_Sell_To_Europe: public BaseCheckYieldGroup
{
public:
	Check_YieldGroup_AI_Sell_To_Europe() { func_name = "YieldGroup_AI_Sell_To_Europe"; }
	bool function(YieldTypes eYield) {return YieldGroup_AI_Sell_To_Europe(eYield);}
	void build();
};

class Check_YieldGroup_AI_Buy_From_Natives: public BaseCheckYieldGroup
{
public:
	Check_YieldGroup_AI_Buy_From_Natives() { func_name = "YieldGroup_AI_Buy_From_Natives"; }
	bool function(YieldTypes eYield) {return YieldGroup_AI_Buy_From_Natives(eYield);}
	void build();
};

class Check_YieldGroup_AI_Buy_From_Europe: public BaseCheckYieldGroup
{
public:
	Check_YieldGroup_AI_Buy_From_Europe() { func_name = "YieldGroup_AI_Buy_From_Europe"; }
	bool function(YieldTypes eYield) {return YieldGroup_AI_Buy_From_Europe(eYield);}
	void build();
};

class Check_YieldGroup_AI_Raw_Material: public BaseCheckYieldGroup
{
public:
	Check_YieldGroup_AI_Raw_Material() { func_name = "YieldGroup_AI_Raw_Material"; }
	bool function(YieldTypes eYield) {return YieldGroup_AI_Raw_Material(eYield);}
	void build();
};

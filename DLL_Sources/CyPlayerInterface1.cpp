#include "CvGameCoreDLL.h"
#include "CyPlayer.h"
#include "CyUnit.h"
#include "CyCity.h"
#include "CyPlot.h"
#include "CySelectionGroup.h"
#include "CyArea.h"
//# include <boost/python/manage_new_object.hpp>
//# include <boost/python/return_value_policy.hpp>
//# include <boost/python/scope.hpp>
//
// published python interface for CyPlayer
//
void CyPlayerPythonInterface1(python::class_<CyPlayer>& x)
{
	OutputDebugString("Python Extension Module - CyPlayerPythonInterface1\n");
	// set the docstring of the current module scope
	python::scope().attr("__doc__") = "Civilization IV Player Class";
	x
		.def("isNone", &CyPlayer::isNone, "checks for a null player")
		.def("startingPlotRange", &CyPlayer::startingPlotRange, "int ()")
		.def("findStartingPlot", &CyPlayer::findStartingPlot, python::return_value_policy<python::manage_new_object>(), "findStartingPlot(bool bRandomize) - Finds a starting plot for player")
		.def("initCity", &CyPlayer::initCity, python::return_value_policy<python::manage_new_object>(), "initCity( plotX, plotY ) - spawns a city at x,y")
		.def("acquireCity", &CyPlayer::acquireCity, "void (CyCity* pCity, bool bConquest, bool bTrade)")
		.def("killCities", &CyPlayer::killCities, "void ()")
		.def("getNewCityName", &CyPlayer::getNewCityName, "wstring ()")
		.def("initUnit", &CyPlayer::initUnit, python::return_value_policy<python::manage_new_object>(), "CyUnit* initUnit(UnitTypes iIndex, ProfessionTypes eProfession, plotX, plotY, UnitAITypes, DirectionTypes, iYieldStored)  - place Unit at X,Y   NOTE: Always use UnitAITypes.NO_UNITAI")
		.def("initEuropeUnit", &CyPlayer::initEuropeUnit, python::return_value_policy<python::manage_new_object>(), "CyUnit* initEuropeUnit(UnitTypes iIndex, UnitAITypes, DirectionTypes)")
		.def("killUnits", &CyPlayer::killUnits, "void ()")
		.def("hasTrait", &CyPlayer::hasTrait, "bool hasTrait(int /*TraitTypes*/ iIndex)")
		.def("isHuman", &CyPlayer::isHuman, "bool ()")
		.def("isNative", &CyPlayer::isNative, "bool ()")
		.def("getName", &CyPlayer::getName, "str ()")
		.def("getNameForm", &CyPlayer::getNameForm, "str ()")
		.def("getNameKey", &CyPlayer::getNameKey, "str ()")
		.def("getCivilizationDescription", &CyPlayer::getCivilizationDescription, "str() - returns the Civilization Description String")
		.def("getCivilizationShortDescription", &CyPlayer::getCivilizationShortDescription, "str() - returns the short Civilization Description")
		.def("getCivilizationDescriptionKey", &CyPlayer::getCivilizationDescriptionKey, "str() - returns the Civilization Description String")
		.def("getCivilizationShortDescriptionKey", &CyPlayer::getCivilizationShortDescriptionKey, "str() - returns the short Civilization Description")
		.def("getCivilizationAdjective", &CyPlayer::getCivilizationAdjective, "str() - returns the Civilization name in adjective form")
		.def("getCivilizationAdjectiveKey", &CyPlayer::getCivilizationAdjectiveKey, "str() - returns the Civilization name in adjective form")
		.def("getWorstEnemyName", &CyPlayer::getWorstEnemyName, "str () - returns the name of the worst enemy")
		.def("getArtStyleType", &CyPlayer::getArtStyleType, " int () - Returns the ArtStyleType for this player (e.g. European)")
		.def("getUnitButton", &CyPlayer::getUnitButton, " string (int eUnit) - Returns the unit button for this player")
		.def("findBestFoundValue", &CyPlayer::findBestFoundValue, " int () - Finds best found value")
		.def("countNumCoastalCities", &CyPlayer::countNumCoastalCities, "int ()")
		.def("countNumCoastalCitiesByArea", &CyPlayer::countNumCoastalCitiesByArea, "(int (CyArea* pArea)")
		.def("countTotalCulture", &CyPlayer::countTotalCulture, "int ()")
		.def("countTotalYieldStored", &CyPlayer::countTotalYieldStored, "int (int /*YieldTypes*/)")
		.def("countCityFeatures", &CyPlayer::countCityFeatures, "int (int /*FeatureTypes*/ eFeature) - Returns ?")
		.def("countNumBuildings", &CyPlayer::countNumBuildings, "int (int /*BuildingTypes*/ eBuilding) - Returns the number of buildings?")
		.def("canContact", &CyPlayer::canContact, "bool (int ePlayer)")
		.def("contact", &CyPlayer::contact, "void (int ePlayer)")
		.def("canTradeWith", &CyPlayer::canTradeWith, "bool (int ePlayer)")
		.def("canTradeItem", &CyPlayer::canTradeItem, "bool (int ePlayer, bool bTestDenial)")
		.def("getTradeDenial", &CyPlayer::getTradeDenial, "DenialTypes (int eWhoTo, TradeData item)")
		.def("canStopTradingWithTeam", &CyPlayer::canStopTradingWithTeam, "int (int /*TeamTypes*/ eTeam)")
		.def("stopTradingWithTeam", &CyPlayer::stopTradingWithTeam, "int (int /*TeamTypes*/ eTeam)")
		.def("killAllDeals", &CyPlayer::killAllDeals, "void ()")
		.def("findNewCapital", &CyPlayer::findNewCapital, "void ()")
		.def("canRaze", &CyPlayer::canRaze, "bool (CyCity pCity)")
		.def("raze", &CyPlayer::raze, "void (CyCity pCity)")
		.def("disband", &CyPlayer::disband, "void (CyCity pCity)")
		.def("canReceiveGoody", &CyPlayer::canReceiveGoody, "bool (CyPlot* pPlot, int /*GoodyTypes*/ eGoody, CyUnit* pUnit)")
		.def("receiveGoody", &CyPlayer::receiveGoody, "void (CyPlot* pPlot, int /*GoodyTypes*/ eGoody, CyUnit* pUnit)")
		.def("doGoody", &CyPlayer::doGoody, "void (CyPlot* pPlot, CyUnit* pUnit)")
		.def("canFound", &CyPlayer::canFound, "bool (int iX, int iY)")
		.def("found", &CyPlayer::found, "void (int iX, int iY)")
		.def("canTrain", &CyPlayer::canTrain, "bool (int eUnit, bool bContinue, bool bTestVisible)")
		.def("canConstruct", &CyPlayer::canConstruct, "bool (int /*BuildingTypes*/eBuilding, bool bContinue, bool bTestVisible, bool bIgnoreCost)")
		.def("getBuildingClassPrereqBuilding", &CyPlayer::getBuildingClassPrereqBuilding, "int (int /*BuildingTypes*/ eBuilding, int /*BuildingClassTypes*/ ePrereqBuildingClass, iExtra) -")
		.def("getUnitYieldProductionNeeded", &CyPlayer::getUnitYieldProductionNeeded, "int getUnitYieldProductionNeeded(int /*UnitTypes*/ eUnit, int /*YieldTypes*/ eYield)")
		.def("getBuildingYieldProductionNeeded", &CyPlayer::getBuildingYieldProductionNeeded, "int getBuildingYieldProductionNeeded(int /*BuildingTypes*/ eBuilding, int /*YieldTypes*/ eYield)")
		.def("removeBuildingClass", &CyPlayer::removeBuildingClass, "void (int /*BuildingClassTypes*/ eBuildingClass)")
		.def("canBuild", &CyPlayer::canBuild, "bool (CyPlot* pPlot, int (BuildTypes) eBuild, bool bTestEra, bool bTestVisible)")
		.def("calculateTotalYield", &CyPlayer::calculateTotalYield, "int (int /*YieldTypes*/ eYield) - Returns the total sum of all city yield")
		.def("isCivic", &CyPlayer::isCivic, "bool (int (CivicTypes) eCivic)")
		///Tks Med
		.def("getMultiYieldRate", &CyPlayer::getMultiYieldRate, "int (YieldTypes eIndex)")
		///TKs Invention Core Mod v 1.0
		.def("getIdeasResearched", &CyPlayer::getIdeasResearched, "int (int (CivicTypes) eCivic)")
		.def("getIdeaProgress", &CyPlayer::getIdeaProgress, "int (int (CivicTypes) eCivic)")
		.def("getCensureType", &CyPlayer::getCensureType, "int (int (CensureType) eCensure)")
		.def("getCostToResearch", &CyPlayer::getCostToResearch, "int (int (CivicTypes) eCivic)")
		.def("getVictoryYieldCount", &CyPlayer::getVictoryYieldCount, "int (int (YieldTypes) eYield)")
		.def("getNumDocksNextUnits", &CyPlayer::getNumDocksNextUnits, "int ()")
		.def("getCurrentResearchProgress", &CyPlayer::getCurrentResearchProgress, "int (bool bGetTurns, int (CivicTypes) eCivic)")
		.def("prolificInventorThreshold", &CyPlayer::prolificInventorThreshold, "int ()")
		.def("getIdeasExperience", &CyPlayer::getIdeasExperience, "int ()")
		.def("getCurrentResearch", &CyPlayer::getCurrentResearch, "int ()")
		.def("getCurrentTradeResearch", &CyPlayer::getCurrentTradeResearch, "int ()")
		.def("getResearchPartner", &CyPlayer::getResearchPartner, "int ()")
		.def("getVassalOwner", &CyPlayer::getVassalOwner, "int ()")
		.def("canMakeVassalDemand", &CyPlayer::canMakeVassalDemand, "bool (int (PlayerTypes) eVassal)")
		.def("setCurrentResearch", &CyPlayer::setCurrentResearch, "void (int (CivicTypes) eCurrentResearch)")
		.def("setCurrentTradeResearch", &CyPlayer::setCurrentResearch, "void (int (CivicTypes) eCurrentResearch)")
		///TKs Med
		.def("getAttackForceKey", &CyPlayer::getAttackForceKey, "str() - returns the Civilization name in adjective form")
		.def("getDeclareKey", &CyPlayer::getDeclareKey, "str() - returns the Civilization name in adjective form")
		.def("getDawnKey", &CyPlayer::getDawnKey, "str() - returns the Civilization name in adjective form")
		.def("isProfessionValid", &CyPlayer::isProfessionValid, "bool ()")
		.def("canUnitBeTraded", &CyPlayer::canUnitBeTraded, "bool (int /*YieldTypes*/  eYield, int /*EuropeTypes*/ eTradeScreen, int/*UnitTypes*/ eUnit)")
		.def("canUseYield", &CyPlayer::canUseYield, "bool (YieldTypes)") // invention effect cache - Nightinggale
		.def("getHasTradeRouteType", &CyPlayer::getHasTradeRouteType, "bool (int (EuropeTypes) eTradeRoute)")

		///TKe
		//.def("getTradeDenial", &CyPlayer::getTradeDenial, "DenialTypes (int eWhoTo, TradeData item)")
        ///TKe
		.def("canDoCivics", &CyPlayer::canDoCivics, "bool (int (CivicTypes) eCivic)")
		.def("greatGeneralThreshold", &CyPlayer::greatGeneralThreshold, "int ()")
		.def("immigrationThreshold", &CyPlayer::immigrationThreshold, "int ()")
		.def("revolutionEuropeUnitThreshold", &CyPlayer::revolutionEuropeUnitThreshold, "int ()")
		.def("getStartingPlot", &CyPlayer::getStartingPlot, python::return_value_policy<python::manage_new_object>(), "CyPlot* ()")
		.def("setStartingPlot", &CyPlayer::setStartingPlot, "void (CyPlot*, bool) - sets the player's starting plot")
		.def("getTotalPopulation", &CyPlayer::getTotalPopulation, "int ()")
		.def("getAveragePopulation", &CyPlayer::getAveragePopulation, "int ()")
		.def("getRealPopulation", &CyPlayer::getRealPopulation, "long int ()")
		.def("getTotalLand", &CyPlayer::getTotalLand, "int ()")
		.def("getTotalLandScored", &CyPlayer::getTotalLandScored, "int ()")
		.def("getGold", &CyPlayer::getGold, "int ()")
		.def("setGold", &CyPlayer::setGold, "void (int iNewValue)")
		.def("changeGold", &CyPlayer::changeGold, "void (int iChange)")
		.def("getAdvancedStartPoints", &CyPlayer::getAdvancedStartPoints, "int ()")
		.def("setAdvancedStartPoints", &CyPlayer::setAdvancedStartPoints, "void (int iNewValue)")
		.def("changeAdvancedStartPoints", &CyPlayer::changeAdvancedStartPoints, "void (int iChange)")
		.def("getAdvancedStartUnitCost", &CyPlayer::getAdvancedStartUnitCost, "int (int (UnitTypes) eUnit, bool bAdd, CyPlot* pPlot)")
		.def("getAdvancedStartCityCost", &CyPlayer::getAdvancedStartCityCost, "int (int (bool bAdd, CyPlot* pPlot)")
		.def("getAdvancedStartPopCost", &CyPlayer::getAdvancedStartPopCost, "int (int (bool bAdd, CyCity* pCity)")
		.def("getAdvancedStartCultureCost", &CyPlayer::getAdvancedStartCultureCost, "int (int (bool bAdd, CyCity* pCity)")
		.def("getAdvancedStartBuildingCost", &CyPlayer::getAdvancedStartBuildingCost, "int (int (BuildingTypes) eUnit, bool bAdd, CyCity* pCity)")
		.def("getAdvancedStartImprovementCost", &CyPlayer::getAdvancedStartImprovementCost, "int (int (ImprovementTypes) eImprovement, bool bAdd, CyPlot* pPlot)")
		.def("getAdvancedStartRouteCost", &CyPlayer::getAdvancedStartRouteCost, "int (int (RouteTypes) eUnit, bool bAdd, CyPlot* pPlot)")
		.def("getAdvancedStartVisibilityCost", &CyPlayer::getAdvancedStartVisibilityCost, "int (bool bAdd, CyPlot* pPlot)")
		.def("createGreatGeneral", &CyPlayer::createGreatGeneral, "void (int /*UnitTypes*/ eUnit, bool bIncrementThreshold, int iX, int iY)")
		.def("getGreatGeneralsCreated", &CyPlayer::getGreatGeneralsCreated, "int ()")
		.def("getGreatGeneralsThresholdModifier", &CyPlayer::getGreatGeneralsThresholdModifier, "int ()")
		.def("getGreatGeneralRateModifier", &CyPlayer::getGreatGeneralRateModifier, "int ()")
		.def("getDomesticGreatGeneralRateModifier", &CyPlayer::getDomesticGreatGeneralRateModifier, "int ()")
		.def("getFreeExperience", &CyPlayer::getFreeExperience, "int ()")
		.def("getWorkerSpeedModifier", &CyPlayer::getWorkerSpeedModifier, "int ()")
		.def("getImprovementUpgradeRateModifier", &CyPlayer::getImprovementUpgradeRateModifier, "int ()")
		.def("getMilitaryProductionModifier", &CyPlayer::getMilitaryProductionModifier, "int ()")
		.def("getCityDefenseModifier", &CyPlayer::getCityDefenseModifier, "int ()")
		.def("getHighestUnitLevel", &CyPlayer::getHighestUnitLevel, "int ()")
		.def("getExpInBorderModifier", &CyPlayer::getExpInBorderModifier, "bool ()")
		.def("getLevelExperienceModifier", &CyPlayer::getLevelExperienceModifier, "int ()")
		.def("getCapitalCity", &CyPlayer::getCapitalCity, python::return_value_policy<python::manage_new_object>(), "CyCity* (int iID)")
		.def("getCitiesLost", &CyPlayer::getCitiesLost, "int ()")
		.def("getAssets", &CyPlayer::getAssets, "int ()")
		.def("changeAssets", &CyPlayer::changeAssets, "void (int iChange)")
		.def("getPower", &CyPlayer::getPower, "int ()")
		.def("getPopScore", &CyPlayer::getPopScore, "int ()")
		.def("getLandScore", &CyPlayer::getLandScore, "int ()")
		.def("getFatherScore", &CyPlayer::getFatherScore, "int ()")
		.def("getTotalTimePlayed", &CyPlayer::getTotalTimePlayed, "int ()")
		.def("isAlive", &CyPlayer::isAlive, "bool ()")
		.def("isEverAlive", &CyPlayer::isEverAlive, "bool ()")
		.def("isExtendedGame", &CyPlayer::isExtendedGame, "bool ()")
		.def("isFoundedFirstCity", &CyPlayer::isFoundedFirstCity, "bool ()")
		.def("getID", &CyPlayer::getID, "int ()")
		.def("getHandicapType", &CyPlayer::getHandicapType, "int ()")
		.def("getCivilizationType", &CyPlayer::getCivilizationType, "int ()")
		.def("getLeaderType", &CyPlayer::getLeaderType, "int ()")
		.def("getPersonalityType", &CyPlayer::getPersonalityType, "int ()")
		.def("setPersonalityType", &CyPlayer::setPersonalityType, "void (int /*LeaderHeadTypes*/ eNewValue)")
		.def("getCurrentEra", &CyPlayer::getCurrentEra, "int ()")
		.def("setCurrentEra", &CyPlayer::setCurrentEra, "void (int /*EraTypes*/ iNewValue)")
		.def("getParent", &CyPlayer::getParent, "int ()")
		.def("getTeam", &CyPlayer::getTeam, "int ()")
		.def("isTurnActive", &CyPlayer::isTurnActive, "bool ()")
		.def("getPlayerColor", &CyPlayer::getPlayerColor, "int (PlayerColorTypes) () - returns the color ID of the player")
		.def("getPlayerTextColorR", &CyPlayer::getPlayerTextColorR, "int ()")
		.def("getPlayerTextColorG", &CyPlayer::getPlayerTextColorG, "int ()")
		.def("getPlayerTextColorB", &CyPlayer::getPlayerTextColorB, "int ()")
		.def("getPlayerTextColorA", &CyPlayer::getPlayerTextColorA, "int ()")
		.def("getSeaPlotYield", &CyPlayer::getSeaPlotYield, "int (YieldTypes eIndex)")
		.def("getYieldRate", &CyPlayer::getYieldRate, "int (YieldTypes eIndex)")
		.def("getYieldRateModifier", &CyPlayer::getYieldRateModifier, "int (YieldTypes eIndex)")
		.def("getCapitalYieldRateModifier", &CyPlayer::getCapitalYieldRateModifier, "int (YieldTypes eIndex)")
		.def("getExtraYieldThreshold", &CyPlayer::getExtraYieldThreshold, "int (YieldTypes eIndex)")
		.def("isYieldEuropeTradable", &CyPlayer::isYieldEuropeTradable, "bool ()")
		.def("setYieldEuropeTradable", &CyPlayer::setYieldEuropeTradable, "void ()")
		.def("isFeatAccomplished", &CyPlayer::isFeatAccomplished, "bool ()")
		.def("setFeatAccomplished", &CyPlayer::setFeatAccomplished, "void ()")
		.def("shouldDisplayFeatPopup", &CyPlayer::shouldDisplayFeatPopup, "bool ()")
		.def("isOption", &CyPlayer::isOption, "bool ()")
		.def("setOption", &CyPlayer::setOption, "void ()")
		.def("isPlayable", &CyPlayer::isPlayable, "bool ()")
		.def("setPlayable", &CyPlayer::setPlayable, "void ()")
		.def("getImprovementCount", &CyPlayer::getImprovementCount, "int (int /*ImprovementTypes*/ iIndex)")
		.def("isBuildingFree", &CyPlayer::isBuildingFree, "bool (int /*BuildingTypes*/ eIndex)")
		.def("getUnitClassCount", &CyPlayer::getUnitClassCount, "int (int (UnitClassTypes) eIndex)")
		.def("getUnitClassMaking", &CyPlayer::getUnitClassMaking, "int (int (UnitClassTypes) eIndex)")
		.def("getUnitClassCountPlusMaking", &CyPlayer::getUnitClassCountPlusMaking, "int (int (UnitClassTypes) eIndex)")
		.def("getBuildingClassCount", &CyPlayer::getBuildingClassCount, "int (int /*BuildingClassTypes*/ eIndex)")
		.def("getBuildingClassMaking", &CyPlayer::getBuildingClassMaking, "int (int /*BuildingClassTypes*/ iIndex)")
		.def("getBuildingClassCountPlusMaking", &CyPlayer::getBuildingClassCountPlusMaking, "int (int /*BuildingClassTypes*/ iIndex)")
		.def("getHurryCount", &CyPlayer::getHurryCount, "int (int (HurryTypes) eIndex)")
		.def("canHurry", &CyPlayer::canHurry, "int (int (HurryTypes) eIndex)")
		.def("getSpecialBuildingNotRequiredCount", &CyPlayer::getSpecialBuildingNotRequiredCount, "int (int (SpecialBuildingTypes) eIndex)")
		.def("isSpecialBuildingNotRequired", &CyPlayer::isSpecialBuildingNotRequired, "int (int (SpecialBuildingTypes) eIndex)")
		.def("getBuildingYieldChange", &CyPlayer::getBuildingYieldChange, "int (BuildingClassTypes eBuildingClass, YieldTypes eYield)")
		.def("getCivic", &CyPlayer::getCivic, "int /*CivicTypes*/ (int /*CivicOptionTypes*/ iIndex)")
		.def("setCivic", &CyPlayer::setCivic, "void (int iCivicOptionType, int iCivicType)")
		.def("getCombatExperience", &CyPlayer::getCombatExperience, "int () - Combat experience used to produce Warlords")
		.def("changeCombatExperience", &CyPlayer::changeCombatExperience, "void (int) - Combat experience used to produce Warlords")
		.def("setCombatExperience", &CyPlayer::setCombatExperience, "void (int) - Combat experience used to produce Warlords")
		.def("addCityName", &CyPlayer::addCityName, "void (std::wstring szName)")
		.def("getNumCityNames", &CyPlayer::getNumCityNames, "int ()")
		.def("getCityName", &CyPlayer::getCityName, "std::wstring (int iIndex)")
		.def("firstCity", &CyPlayer::firstCity, "tuple(CyCity, int iterOut) (bool bReverse) - gets the first city")
		.def("nextCity", &CyPlayer::nextCity, "tuple(CyCity, int iterOut) (int iterIn, bool bReverse) - gets the next city")
		.def("getNumCities", &CyPlayer::getNumCities, "int ()")
		.def("getCity", &CyPlayer::getCity, python::return_value_policy<python::manage_new_object>(), "CyCity* (int iID)")
		.def("firstUnit", &CyPlayer::firstUnit, "tuple(CyUnit, int iterOut) (bool bReverse) - gets the first unit")
		.def("nextUnit", &CyPlayer::nextUnit, "tuple(CyUnit, int iterOut) (int iterIn, bool bReverse) - gets the next unit")
		.def("getNumUnits", &CyPlayer::getNumUnits, "int ()")
		.def("getUnit", &CyPlayer::getUnit, python::return_value_policy<python::manage_new_object>(), "CyUnit* (int iID)")
		.def("getNumEuropeUnits", &CyPlayer::getNumEuropeUnits, "int ()")
		.def("getEuropeUnit", &CyPlayer::getEuropeUnit, python::return_value_policy<python::manage_new_object>(), "CyUnit* (int iIndex)")
		.def("getEuropeUnitById", &CyPlayer::getEuropeUnitById, python::return_value_policy<python::manage_new_object>(), "CyUnit* (int iId)")
		.def("loadUnitFromEurope", &CyPlayer::loadUnitFromEurope, "void (CyUnit* pUnit, CyUnit* pTransport)")
		.def("unloadUnitToEurope", &CyPlayer::unloadUnitToEurope, "void (CyUnit* pUnit)")
		.def("firstSelectionGroup", &CyPlayer::firstSelectionGroup, "tuple(CySelectionGroup, int iterOut) (bool bReverse) - gets the first selectionGroup")
		.def("nextSelectionGroup", &CyPlayer::nextSelectionGroup, "tuple(CySelectionGroup, int iterOut) (int iterIn, bool bReverse) - gets the next selectionGroup")
		.def("getNumSelectionGroups", &CyPlayer::getNumSelectionGroups, "int ()")
		.def("getSelectionGroup", &CyPlayer::getSelectionGroup, python::return_value_policy<python::manage_new_object>(), "CvSelectionGroup* (int iID)")
		.def("countNumTravelUnits", &CyPlayer::countNumTravelUnits, "int (int /*UnitTravelStates*/ eState, int /*DomainTypes*/ eDomain)")
		.def("trigger", &CyPlayer::trigger, "void (/*EventTriggerTypes*/int eEventTrigger)")
		.def("getEventOccured", &CyPlayer::getEventOccured, python::return_value_policy<python::reference_existing_object>(), "EventTriggeredData* (int /*EventTypes*/ eEvent)")
		.def("resetEventOccured", &CyPlayer::resetEventOccured, "void (int /*EventTypes*/ eEvent)")
		.def("getEventTriggered", &CyPlayer::getEventTriggered, python::return_value_policy<python::reference_existing_object>(), "EventTriggeredData* (int iID)")
		.def("initTriggeredData", &CyPlayer::initTriggeredData, python::return_value_policy<python::reference_existing_object>(), "EventTriggeredData* (int eEventTrigger, bool bFire, int iCityId, int iPlotX, int iPlotY, PlayerTypes eOtherPlayer, int iOtherPlayerCityId, int iUnitId, BuildingTypes eBuilding)")
		.def("getEventTriggerWeight", &CyPlayer::getEventTriggerWeight, "int getEventTriggerWeight(int eEventTrigger)")
		;
}

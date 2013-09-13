#pragma once

// CvGlobals.h

#ifndef CIV4_GLOBALS_H
#define CIV4_GLOBALS_H

//#include "CvStructs.h"
//
// 'global' vars for Civ IV.  singleton class.
// All globals and global types should be contained in this class
// Author -	Mustafa Thamer
//

class CvDLLUtilityIFaceBase;
class CvRandom;
class CvGameAI;
class CMessageControl;
class CvDropMgr;
class CMessageQueue;
class CvSetupData;
class CvInitCore;
class CvMessageCodeTranslator;
class CvPortal;
class CvStatsReporter;
class CvDLLInterfaceIFaceBase;
class CvPlayerAI;
class CvDiplomacyScreen;
class CvCivicsScreen;
class CvWBUnitEditScreen;
class CvWBCityEditScreen;
class CMPDiplomacyScreen;
class FMPIManager;
class FAStar;
class CvInterface;
class CMainMenu;
class CvEngine;
class CvArtFileMgr;
class FVariableSystem;
class CvMap;
class CvPlayerAI;
class CvTeamAI;
class CvInterfaceModeInfo;
class CvWorldInfo;
class CvClimateInfo;
class CvSeaLevelInfo;
class CvEuropeInfo;
class CvColorInfo;
class CvPlayerColorInfo;
class CvRouteModelInfo;
class CvRiverModelInfo;
class CvWaterPlaneInfo;
class CvTerrainPlaneInfo;
class CvCameraOverlayInfo;
class CvAnimationPathInfo;
class CvAnimationCategoryInfo;
class CvEntityEventInfo;
class CvEffectInfo;
class CvAttachableInfo;
class CvUnitFormationInfo;
class CvGameText;
class CvLandscapeInfo;
class CvTerrainInfo;
class CvBonusInfo;
class CvFeatureInfo;
class CvCivilizationInfo;
class CvLeaderHeadInfo;
class CvTraitInfo;
class CvCursorInfo;
class CvSlideShowInfo;
class CvSlideShowRandomInfo;
class CvWorldPickerInfo;
class CvUnitInfo;
class CvSpecialUnitInfo;
class CvInfoBase;
class CvYieldInfo;
class CvRouteInfo;
class CvImprovementInfo;
class CvGoodyInfo;
class CvBuildInfo;
class CvHandicapInfo;
class CvGameSpeedInfo;
class CvAlarmInfo;
class CvTurnTimerInfo;
class CvBuildingClassInfo;
class CvBuildingInfo;
class CvSpecialBuildingInfo;
class CvUnitClassInfo;
class CvActionInfo;
class CvMissionInfo;
class CvControlInfo;
class CvCommandInfo;
class CvAutomateInfo;
class CvPromotionInfo;
class CvProfessionInfo;
class CvCivicInfo;
class CvDiplomacyInfo;
class CvEraInfo;
class CvHurryInfo;
class CvEmphasizeInfo;
class CvCultureLevelInfo;
class CvVictoryInfo;
class CvGameOptionInfo;
class CvMPOptionInfo;
class CvForceControlInfo;
class CvPlayerOptionInfo;
class CvGraphicOptionInfo;
class CvEventTriggerInfo;
class CvEventInfo;
class CvFatherInfo;
class CvFatherPointInfo;
//Androrc UnitArtStyles
class CvUnitArtStyleTypeInfo;
//Androrc End
class CvMainMenuInfo;


class CvGlobals
{
//	friend class CvDLLUtilityIFace;
	friend class CvXMLLoadUtility;
public:

	int XMLlength; // XML length check -  Nightinggale

	// singleton accessor
	DllExport inline static CvGlobals& getInstance();

	DllExport CvGlobals();
	DllExport virtual ~CvGlobals();

	DllExport void init();
	DllExport void uninit();
	DllExport void clearTypesMap();

	DllExport CvDiplomacyScreen* getDiplomacyScreen();
	DllExport CMPDiplomacyScreen* getMPDiplomacyScreen();

	DllExport FMPIManager*& getFMPMgrPtr();
	DllExport CvPortal& getPortal();
	DllExport CvSetupData& getSetupData();
	DllExport CvInitCore& getInitCore();
	DllExport CvInitCore& getLoadedInitCore();
	DllExport CvInitCore& getIniInitCore();
	DllExport CvMessageCodeTranslator& getMessageCodes();
	DllExport CvStatsReporter& getStatsReporter();
	DllExport CvStatsReporter* getStatsReporterPtr();
	DllExport CvInterface& getInterface();
	DllExport CvInterface* getInterfacePtr();
	DllExport int getMaxCivPlayers() const;
#ifdef _USRDLL
	CvMap& getMapINLINE() { return *m_map; }				// inlined for perf reasons, do not use outside of dll
	CvGameAI& getGameINLINE() { return *m_game; }			// inlined for perf reasons, do not use outside of dll
#endif
	DllExport CvMap& getMap();
	DllExport CvGameAI& getGame();
	DllExport CvGameAI *getGamePointer();
	DllExport CvRandom& getASyncRand();
	DllExport CMessageQueue& getMessageQueue();
	DllExport CMessageQueue& getHotMessageQueue();
	DllExport CMessageControl& getMessageControl();
	DllExport CvDropMgr& getDropMgr();
	DllExport FAStar& getPathFinder();
	DllExport FAStar& getInterfacePathFinder();
	DllExport FAStar& getStepFinder();
	DllExport FAStar& getRouteFinder();
	DllExport FAStar& getBorderFinder();
	DllExport FAStar& getAreaFinder();
	DllExport NiPoint3& getPt3Origin();

	DllExport std::vector<CvInterfaceModeInfo*>& getInterfaceModeInfo();
	DllExport CvInterfaceModeInfo& getInterfaceModeInfo(InterfaceModeTypes e);

	DllExport NiPoint3& getPt3CameraDir();

	DllExport bool& getLogging();
	DllExport bool& getRandLogging();
	DllExport bool& getSynchLogging();
	DllExport bool& overwriteLogs();

	DllExport int* getPlotDirectionX();
	DllExport int* getPlotDirectionY();
	DllExport int* getPlotCardinalDirectionX();
	DllExport int* getPlotCardinalDirectionY();
	DllExport int* getCityPlotX();
	DllExport int* getCityPlotY();
	DllExport int* getCityPlotPriority();
	DllExport int getXYCityPlot(int i, int j);
	DirectionTypes* getTurnLeftDirection();
	DirectionTypes getTurnLeftDirection(int i);
	DirectionTypes* getTurnRightDirection();
	DirectionTypes getTurnRightDirection(int i);
	DllExport DirectionTypes getXYDirection(int i, int j);

	//
	// Global Infos
	// All info type strings are upper case and are kept in this hash map for fast lookup
	//
	DllExport int getInfoTypeForString(const char* szType, bool hideAssert = false) const;			// returns the infos index, use this when searching for an info type string
	DllExport void setInfoTypeFromString(const char* szType, int idx);
	DllExport void infoTypeFromStringReset();
	DllExport void addToInfosVectors(void *infoVector);
	DllExport void infosReset();

	DllExport int getNumWorldInfos();
	DllExport std::vector<CvWorldInfo*>& getWorldInfo();
	DllExport CvWorldInfo& getWorldInfo(WorldSizeTypes e);

	DllExport int getNumClimateInfos();
	DllExport std::vector<CvClimateInfo*>& getClimateInfo();
	DllExport CvClimateInfo& getClimateInfo(ClimateTypes e);

	DllExport int getNumSeaLevelInfos();
	DllExport std::vector<CvSeaLevelInfo*>& getSeaLevelInfo();
	DllExport CvSeaLevelInfo& getSeaLevelInfo(SeaLevelTypes e);

	DllExport int getNumEuropeInfos();
	DllExport std::vector<CvEuropeInfo*>& getEuropeInfo();
	DllExport CvEuropeInfo& getEuropeInfo(EuropeTypes e);

	DllExport int getNumColorInfos();
	DllExport std::vector<CvColorInfo*>& getColorInfo();
	DllExport CvColorInfo& getColorInfo(ColorTypes e);

	DllExport int getNumPlayerColorInfos();
	DllExport std::vector<CvPlayerColorInfo*>& getPlayerColorInfo();
	DllExport CvPlayerColorInfo& getPlayerColorInfo(PlayerColorTypes e);

	DllExport int getNumHints();
	DllExport std::vector<CvInfoBase*>& getHints();
	DllExport CvInfoBase& getHints(int i);

	DllExport int getNumMainMenus();
	DllExport std::vector<CvMainMenuInfo*>& getMainMenus();
	DllExport CvMainMenuInfo& getMainMenus(int i);

	DllExport int getNumRouteModelInfos();
	DllExport std::vector<CvRouteModelInfo*>& getRouteModelInfo();
	DllExport CvRouteModelInfo& getRouteModelInfo(int i);

	DllExport int getNumRiverModelInfos();
	DllExport std::vector<CvRiverModelInfo*>& getRiverModelInfo();
	DllExport CvRiverModelInfo& getRiverModelInfo(int i);

	DllExport int getNumWaterPlaneInfos();
	DllExport std::vector<CvWaterPlaneInfo*>& getWaterPlaneInfo();
	DllExport CvWaterPlaneInfo& getWaterPlaneInfo(int i);

	DllExport int getNumTerrainPlaneInfos();
	DllExport std::vector<CvTerrainPlaneInfo*>& getTerrainPlaneInfo();
	DllExport CvTerrainPlaneInfo& getTerrainPlaneInfo(int i);

	DllExport int getNumCameraOverlayInfos();
	DllExport std::vector<CvCameraOverlayInfo*>& getCameraOverlayInfo();
	DllExport CvCameraOverlayInfo& getCameraOverlayInfo(int i);

	DllExport int getNumAnimationPathInfos();
	DllExport std::vector<CvAnimationPathInfo*>& getAnimationPathInfo();
	DllExport CvAnimationPathInfo& getAnimationPathInfo(AnimationPathTypes e);

	DllExport int getNumAnimationCategoryInfos();
	DllExport std::vector<CvAnimationCategoryInfo*>& getAnimationCategoryInfo();
	DllExport CvAnimationCategoryInfo& getAnimationCategoryInfo(AnimationCategoryTypes e);

	DllExport int getNumEntityEventInfos();
	DllExport std::vector<CvEntityEventInfo*>& getEntityEventInfo();
	DllExport CvEntityEventInfo& getEntityEventInfo(EntityEventTypes e);

	DllExport int getNumEffectInfos();
	DllExport std::vector<CvEffectInfo*>& getEffectInfo();
	DllExport CvEffectInfo& getEffectInfo(int i);

	DllExport int getNumAttachableInfos();
	DllExport std::vector<CvAttachableInfo*>& getAttachableInfo();
	DllExport CvAttachableInfo& getAttachableInfo(int i);

	DllExport int getNumUnitFormationInfos();
	DllExport std::vector<CvUnitFormationInfo*>& getUnitFormationInfo();
	DllExport CvUnitFormationInfo& getUnitFormationInfo(int i);

	DllExport int getNumGameTextXML();
	DllExport std::vector<CvGameText*>& getGameTextXML();

	DllExport int getNumLandscapeInfos();
	DllExport std::vector<CvLandscapeInfo*>& getLandscapeInfo();
	DllExport CvLandscapeInfo& getLandscapeInfo(int iIndex);
	DllExport int getActiveLandscapeID();
	DllExport void setActiveLandscapeID(int iLandscapeID);

	DllExport int getNumTerrainInfos();
	DllExport std::vector<CvTerrainInfo*>& getTerrainInfo();
	DllExport CvTerrainInfo& getTerrainInfo(TerrainTypes eTerrainNum);

	DllExport int getNumBonusInfos();
	DllExport std::vector<CvBonusInfo*>& getBonusInfo();
	DllExport CvBonusInfo& getBonusInfo(BonusTypes eBonusNum);

	DllExport int getNumFeatureInfos();
	DllExport std::vector<CvFeatureInfo*>& getFeatureInfo();
	DllExport CvFeatureInfo& getFeatureInfo(FeatureTypes eFeatureNum);

	DllExport int getNumCivilizationInfos();
	DllExport std::vector<CvCivilizationInfo*>& getCivilizationInfo();
	DllExport CvCivilizationInfo& getCivilizationInfo(CivilizationTypes eCivilizationNum);

	DllExport int getNumLeaderHeadInfos();
	DllExport std::vector<CvLeaderHeadInfo*>& getLeaderHeadInfo();
	DllExport CvLeaderHeadInfo& getLeaderHeadInfo(LeaderHeadTypes eLeaderHeadNum);

	DllExport int getNumTraitInfos();
	DllExport std::vector<CvTraitInfo*>& getTraitInfo();
	DllExport	CvTraitInfo& getTraitInfo(TraitTypes eTraitNum);

	DllExport int getNumCursorInfos();
	DllExport std::vector<CvCursorInfo*>& getCursorInfo();
	DllExport	CvCursorInfo& getCursorInfo(CursorTypes eCursorNum);

	DllExport int getNumSlideShowInfos();
	DllExport std::vector<CvSlideShowInfo*>& getSlideShowInfo();
	DllExport	CvSlideShowInfo& getSlideShowInfo(int iIndex);

	DllExport int getNumSlideShowRandomInfos();
	DllExport std::vector<CvSlideShowRandomInfo*>& getSlideShowRandomInfo();
	DllExport	CvSlideShowRandomInfo& getSlideShowRandomInfo(int iIndex);

	DllExport int getNumWorldPickerInfos();
	DllExport std::vector<CvWorldPickerInfo*>& getWorldPickerInfo();
	DllExport	CvWorldPickerInfo& getWorldPickerInfo(int iIndex);

	DllExport int getNumUnitInfos();
	DllExport std::vector<CvUnitInfo*>& getUnitInfo();
	DllExport	CvUnitInfo& getUnitInfo(UnitTypes eUnitNum);

	DllExport int getNumSpecialUnitInfos();
	DllExport std::vector<CvSpecialUnitInfo*>& getSpecialUnitInfo();
	DllExport	CvSpecialUnitInfo& getSpecialUnitInfo(SpecialUnitTypes eSpecialUnitNum);

	DllExport int getNumConceptInfos();
	DllExport std::vector<CvInfoBase*>& getConceptInfo();
	DllExport CvInfoBase& getConceptInfo(ConceptTypes e);
	DllExport int getNumCalendarInfos();
	DllExport std::vector<CvInfoBase*>& getCalendarInfo();
	DllExport CvInfoBase& getCalendarInfo(CalendarTypes e);

	DllExport int getNumSeasonInfos();
	DllExport std::vector<CvInfoBase*>& getSeasonInfo();
	DllExport CvInfoBase& getSeasonInfo(SeasonTypes e);

	DllExport int getNumMonthInfos();
	DllExport std::vector<CvInfoBase*>& getMonthInfo();
	DllExport CvInfoBase& getMonthInfo(MonthTypes e);

	DllExport int getNumDenialInfos();
	DllExport std::vector<CvInfoBase*>& getDenialInfo();
	DllExport CvInfoBase& getDenialInfo(DenialTypes e);

	DllExport int getNumInvisibleInfos();
	DllExport std::vector<CvInfoBase*>& getInvisibleInfo();
	DllExport CvInfoBase& getInvisibleInfo(InvisibleTypes e);

	DllExport int getNumFatherInfos();
	DllExport std::vector<CvFatherInfo*>& getFatherInfo();
	DllExport CvFatherInfo& getFatherInfo(FatherTypes e);

	DllExport int getNumFatherPointInfos();
	DllExport std::vector<CvFatherPointInfo*>& getFatherPointInfo();
	DllExport CvFatherPointInfo& getFatherPointInfo(FatherPointTypes e);

	DllExport int getNumUnitCombatInfos();
	DllExport std::vector<CvInfoBase*>& getUnitCombatInfo();
	DllExport CvInfoBase& getUnitCombatInfo(UnitCombatTypes e);

	DllExport std::vector<CvInfoBase*>& getDomainInfo();
	DllExport CvInfoBase& getDomainInfo(DomainTypes e);

	DllExport std::vector<CvInfoBase*>& getUnitAIInfo();
	DllExport CvInfoBase& getUnitAIInfo(UnitAITypes eUnitAINum);

	DllExport std::vector<CvInfoBase*>& getAttitudeInfo();
	DllExport	CvInfoBase& getAttitudeInfo(AttitudeTypes eAttitudeNum);

	DllExport std::vector<CvInfoBase*>& getMemoryInfo();
	DllExport	CvInfoBase& getMemoryInfo(MemoryTypes eMemoryNum);

	DllExport int getNumFatherCategoryInfos();
	DllExport std::vector<CvInfoBase*>& getFatherCategoryInfo();
	DllExport	CvInfoBase& getFatherCategoryInfo(FatherCategoryTypes eFatherCategoryNum);

	DllExport int getNumGameOptionInfos();
	DllExport std::vector<CvGameOptionInfo*>& getGameOptionInfo();
	DllExport	CvGameOptionInfo& getGameOptionInfo(GameOptionTypes eGameOptionNum);

	DllExport int getNumMPOptionInfos();
	DllExport std::vector<CvMPOptionInfo*>& getMPOptionInfo();
	DllExport	CvMPOptionInfo& getMPOptionInfo(MultiplayerOptionTypes eMPOptionNum);

	DllExport int getNumForceControlInfos();
	DllExport std::vector<CvForceControlInfo*>& getForceControlInfo();
	DllExport	CvForceControlInfo& getForceControlInfo(ForceControlTypes eForceControlNum);

	DllExport std::vector<CvPlayerOptionInfo*>& getPlayerOptionInfo();
	DllExport	CvPlayerOptionInfo& getPlayerOptionInfo(PlayerOptionTypes ePlayerOptionNum);

	DllExport std::vector<CvGraphicOptionInfo*>& getGraphicOptionInfo();
	DllExport	CvGraphicOptionInfo& getGraphicOptionInfo(GraphicOptionTypes eGraphicOptionNum);

	DllExport std::vector<CvYieldInfo*>& getYieldInfo();
	DllExport	CvYieldInfo& getYieldInfo(YieldTypes eYieldNum);

	DllExport int getNumRouteInfos();
	DllExport std::vector<CvRouteInfo*>& getRouteInfo();
	DllExport	CvRouteInfo& getRouteInfo(RouteTypes eRouteNum);

	DllExport int getNumImprovementInfos();
	DllExport std::vector<CvImprovementInfo*>& getImprovementInfo();
	DllExport CvImprovementInfo& getImprovementInfo(ImprovementTypes eImprovementNum);

	DllExport int getNumGoodyInfos();
	DllExport std::vector<CvGoodyInfo*>& getGoodyInfo();
	DllExport CvGoodyInfo& getGoodyInfo(GoodyTypes eGoodyNum);

	DllExport int getNumBuildInfos();
	DllExport std::vector<CvBuildInfo*>& getBuildInfo();
	DllExport CvBuildInfo& getBuildInfo(BuildTypes eBuildNum);

	DllExport int getNumHandicapInfos();
	DllExport std::vector<CvHandicapInfo*>& getHandicapInfo();
	DllExport CvHandicapInfo& getHandicapInfo(HandicapTypes eHandicapNum);

	DllExport int getNumGameSpeedInfos();
	DllExport std::vector<CvGameSpeedInfo*>& getGameSpeedInfo();
	DllExport CvGameSpeedInfo& getGameSpeedInfo(GameSpeedTypes eGameSpeedNum);

	DllExport int getNumAlarmInfos();
	///TKs Invention Core Mod v 1.0
	int getCostToResearch(CivicTypes eCivic);
	///TKs Med
	bool isEquipmentType(YieldTypes eEquipment, UnitEquipmentTypes iType) const;
	///TKe

	DllExport std::vector<CvAlarmInfo*>& getAlarmInfo();
	DllExport CvAlarmInfo& getAlarmInfo(AlarmTypes eAlarm);

	DllExport int getNumTurnTimerInfos();
	DllExport std::vector<CvTurnTimerInfo*>& getTurnTimerInfo();
	DllExport CvTurnTimerInfo& getTurnTimerInfo(TurnTimerTypes eTurnTimerNum);

	DllExport int getNumBuildingClassInfos();
	DllExport std::vector<CvBuildingClassInfo*>& getBuildingClassInfo();
	DllExport CvBuildingClassInfo& getBuildingClassInfo(BuildingClassTypes eBuildingClassNum);

	DllExport int getNumBuildingInfos();
	DllExport std::vector<CvBuildingInfo*>& getBuildingInfo();
	DllExport CvBuildingInfo& getBuildingInfo(BuildingTypes eBuildingNum);

	DllExport int getNumSpecialBuildingInfos();
	DllExport std::vector<CvSpecialBuildingInfo*>& getSpecialBuildingInfo();
	DllExport CvSpecialBuildingInfo& getSpecialBuildingInfo(SpecialBuildingTypes eSpecialBuildingNum);

	DllExport int getNumUnitClassInfos();
	DllExport std::vector<CvUnitClassInfo*>& getUnitClassInfo();
	DllExport CvUnitClassInfo& getUnitClassInfo(UnitClassTypes eUnitClassNum);

	DllExport int getNumActionInfos();
	DllExport std::vector<CvActionInfo*>& getActionInfo();
	DllExport CvActionInfo& getActionInfo(int i);

	DllExport std::vector<CvMissionInfo*>& getMissionInfo();
	DllExport CvMissionInfo& getMissionInfo(MissionTypes eMissionNum);

	DllExport std::vector<CvControlInfo*>& getControlInfo();
	DllExport CvControlInfo& getControlInfo(ControlTypes eControlNum);

	DllExport std::vector<CvCommandInfo*>& getCommandInfo();
	DllExport CvCommandInfo& getCommandInfo(CommandTypes eCommandNum);

	DllExport int getNumAutomateInfos();
	DllExport std::vector<CvAutomateInfo*>& getAutomateInfo();
	DllExport CvAutomateInfo& getAutomateInfo(int iAutomateNum);

	DllExport int getNumPromotionInfos();
	DllExport std::vector<CvPromotionInfo*>& getPromotionInfo();
	DllExport CvPromotionInfo& getPromotionInfo(PromotionTypes ePromotionNum);

	DllExport int getNumProfessionInfos();
	DllExport std::vector<CvProfessionInfo*>& getProfessionInfo();
	DllExport CvProfessionInfo& getProfessionInfo(ProfessionTypes eProfessionNum);

	DllExport int getNumCivicOptionInfos();
	DllExport std::vector<CvInfoBase*>& getCivicOptionInfo();
	DllExport CvInfoBase& getCivicOptionInfo(CivicOptionTypes eCivicOptionNum);

	DllExport int getNumCivicInfos();
	DllExport std::vector<CvCivicInfo*>& getCivicInfo();
	DllExport CvCivicInfo& getCivicInfo(CivicTypes eCivicNum);

	DllExport int getNumDiplomacyInfos();
	DllExport std::vector<CvDiplomacyInfo*>& getDiplomacyInfo();
	DllExport	CvDiplomacyInfo& getDiplomacyInfo(int iDiplomacyNum);

	DllExport int getNumEraInfos();
	DllExport std::vector<CvEraInfo*>& getEraInfo();
	DllExport	CvEraInfo& getEraInfo(EraTypes eEraNum);

	DllExport int getNumHurryInfos();
	DllExport std::vector<CvHurryInfo*>& getHurryInfo();
	DllExport	CvHurryInfo& getHurryInfo(HurryTypes eHurryNum);

	DllExport int getNumEmphasizeInfos();
	DllExport std::vector<CvEmphasizeInfo*>& getEmphasizeInfo();
	DllExport	CvEmphasizeInfo& getEmphasizeInfo(EmphasizeTypes eEmphasizeNum);

	DllExport int getNumCultureLevelInfos();
	DllExport std::vector<CvCultureLevelInfo*>& getCultureLevelInfo();
	DllExport	CvCultureLevelInfo& getCultureLevelInfo(CultureLevelTypes eCultureLevelNum);

	DllExport int getNumVictoryInfos();
	DllExport std::vector<CvVictoryInfo*>& getVictoryInfo();
	DllExport	CvVictoryInfo& getVictoryInfo(VictoryTypes eVictoryNum);

	DllExport int getNumEventTriggerInfos();
	DllExport std::vector<CvEventTriggerInfo*>& getEventTriggerInfo();
	DllExport CvEventTriggerInfo& getEventTriggerInfo(EventTriggerTypes eEventTrigger);

	DllExport int getNumEventInfos();
	DllExport std::vector<CvEventInfo*>& getEventInfo();
	DllExport CvEventInfo& getEventInfo(EventTypes eEvent);

    //Androrc UnitArtStyles
	DllExport int getNumUnitArtStyleTypeInfos();
	std::vector<CvUnitArtStyleTypeInfo*>& getUnitArtStyleTypeInfo();
	DllExport CvUnitArtStyleTypeInfo& getUnitArtStyleTypeInfo(UnitArtStyleTypes eUnitArtStyleTypeNum);
	//Androrc End


	DllExport int getNUM_ENGINE_DIRTY_BITS() const;
	DllExport int getNUM_INTERFACE_DIRTY_BITS() const;
	DllExport int getNUM_YIELD_TYPES() const;
	DllExport int getNUM_FORCECONTROL_TYPES() const;
	DllExport int getNUM_INFOBAR_TYPES() const;
	DllExport int getNUM_HEALTHBAR_TYPES() const;
	DllExport int getNUM_CONTROL_TYPES() const;
	DllExport int getNUM_LEADERANIM_TYPES() const;

	DllExport int& getNumEntityEventTypes();
	CvString*& getEntityEventTypes();
	DllExport CvString& getEntityEventTypes(EntityEventTypes e);

	DllExport int& getNumAnimationOperatorTypes();
	CvString*& getAnimationOperatorTypes();
	DllExport CvString& getAnimationOperatorTypes(AnimationOperatorTypes e);

	CvString*& getFunctionTypes();
	DllExport CvString& getFunctionTypes(FunctionTypes e);

	DllExport int& getNumArtStyleTypes();
	CvString*& getArtStyleTypes();
	DllExport CvString& getArtStyleTypes(ArtStyleTypes e);

	DllExport int& getNumCitySizeTypes();
	CvString*& getCitySizeTypes();
	DllExport CvString& getCitySizeTypes(int i);

	CvString*& getContactTypes();
	DllExport CvString& getContactTypes(ContactTypes e);

	CvString*& getDiplomacyPowerTypes();
	DllExport CvString& getDiplomacyPowerTypes(DiplomacyPowerTypes e);

	CvString*& getAutomateTypes();
	DllExport CvString& getAutomateTypes(AutomateTypes e);
	///TKs MEd
	CvString*& getMedCityTypes();
	DllExport CvString& getMedCityTypes(MedCityTypes e);

	CvString*& getModCodeTypes();
	DllExport CvString& getModCodeTypes(ModCodeTypes e);

	CvString*& getTradeScreenTypes();
	DllExport CvString& getTradeScreenTypes(TradeScreenTypes e);
	///TKe

	CvString*& getDirectionTypes();
	DllExport CvString& getDirectionTypes(AutomateTypes e);

	DllExport int& getNumFootstepAudioTypes();
	CvString*& getFootstepAudioTypes();
	DllExport CvString& getFootstepAudioTypes(int i);
	DllExport int getFootstepAudioTypeByTag(CvString strTag);

	CvString*& getFootstepAudioTags();
	DllExport CvString& getFootstepAudioTags(int i);

	CvString& getCurrentXMLFile();
	void setCurrentXMLFile(const TCHAR* szFileName);

	//
	///////////////// BEGIN global defines
	// THESE ARE READ-ONLY
	//

	DllExport FVariableSystem* getDefinesVarSystem();
	DllExport void cacheGlobals();

	// ***** EXPOSED TO PYTHON *****
	DllExport int getDefineINT( const char * szName ) const;
	DllExport float getDefineFLOAT( const char * szName ) const;
	DllExport const char * getDefineSTRING( const char * szName ) const;
	DllExport void setDefineINT( const char * szName, int iValue );
	DllExport void setDefineFLOAT( const char * szName, float fValue );
	DllExport void setDefineSTRING( const char * szName, const char * szValue );

	DllExport int getMOVE_DENOMINATOR();
	DllExport int getFOOD_CONSUMPTION_PER_POPULATION();
	DllExport int getMAX_HIT_POINTS();
	DllExport int getHILLS_EXTRA_DEFENSE();
	DllExport int getRIVER_ATTACK_MODIFIER();
	DllExport int getAMPHIB_ATTACK_MODIFIER();
	DllExport int getHILLS_EXTRA_MOVEMENT();
	DllExport int getPEAK_EXTRA_MOVEMENT();
	DllExport int getMAX_PLOT_LIST_ROWS();
	DllExport int getUNIT_MULTISELECT_MAX();
	DllExport int getEVENT_MESSAGE_TIME();
	DllExport int getROUTE_FEATURE_GROWTH_MODIFIER();
	DllExport int getFEATURE_GROWTH_MODIFIER();
	DllExport int getMIN_CITY_RANGE();
	DllExport int getCITY_MAX_NUM_BUILDINGS();
	DllExport int getLAKE_MAX_AREA_SIZE();
	DllExport int getMIN_WATER_SIZE_FOR_OCEAN();
	DllExport int getFORTIFY_MODIFIER_PER_TURN();
	DllExport int getMAX_CITY_DEFENSE_DAMAGE();
	DllExport int getPEAK_SEE_THROUGH_CHANGE();
	DllExport int getHILLS_SEE_THROUGH_CHANGE();
	DllExport int getSEAWATER_SEE_FROM_CHANGE();
	DllExport int getPEAK_SEE_FROM_CHANGE();
	DllExport int getHILLS_SEE_FROM_CHANGE();
	DllExport int getMAX_REBEL_YIELD_MODIFIER();

	DllExport float getCAMERA_MIN_YAW();
	DllExport float getCAMERA_MAX_YAW();
	DllExport float getCAMERA_FAR_CLIP_Z_HEIGHT();
	DllExport float getCAMERA_MAX_TRAVEL_DISTANCE();
	DllExport float getCAMERA_START_DISTANCE();
	DllExport float getPLOT_SIZE();
	DllExport float getCAMERA_SPECIAL_PITCH();
	DllExport float getCAMERA_MAX_TURN_OFFSET();
	DllExport float getCAMERA_MIN_DISTANCE();
	DllExport float getCAMERA_UPPER_PITCH();
	DllExport float getCAMERA_LOWER_PITCH();
	DllExport float getFIELD_OF_VIEW();
	DllExport float getUNIT_MULTISELECT_DISTANCE();

	DllExport int getUSE_CAN_FOUND_CITIES_ON_WATER_CALLBACK();
	DllExport int getUSE_CANNOT_DO_CIVIC_CALLBACK();
	DllExport int getUSE_CAN_DO_CIVIC_CALLBACK();
	DllExport int getUSE_CANNOT_CONSTRUCT_CALLBACK();
	DllExport int getUSE_CAN_CONSTRUCT_CALLBACK();
	DllExport int getUSE_CAN_DECLARE_WAR_CALLBACK();
	DllExport int getUSE_GET_UNIT_COST_MOD_CALLBACK();
	DllExport int getUSE_GET_BUILDING_COST_MOD_CALLBACK();
	DllExport int getUSE_GET_CITY_FOUND_VALUE_CALLBACK();
	DllExport int getUSE_CANNOT_HANDLE_ACTION_CALLBACK();
	DllExport int getUSE_CAN_BUILD_CALLBACK();
	DllExport int getUSE_CANNOT_TRAIN_CALLBACK();
	DllExport int getUSE_CAN_TRAIN_CALLBACK();
	DllExport int getUSE_UNIT_CANNOT_MOVE_INTO_CALLBACK();
	DllExport int getUSE_FINISH_TEXT_CALLBACK();
	DllExport int getUSE_ON_UNIT_SET_XY_CALLBACK();
	DllExport int getUSE_ON_UNIT_SELECTED_CALLBACK();
	DllExport int getUSE_ON_MISSIONARY_CONVERTED_UNIT_CALLBACK();
	DllExport int getUSE_ON_UPDATE_CALLBACK();
	DllExport int getUSE_ON_UNIT_CREATED_CALLBACK();
	DllExport int getUSE_ON_UNIT_LOST_CALLBACK();

	DllExport int getMAX_CIV_PLAYERS();
	DllExport int getMAX_PLAYERS();
	DllExport int getMAX_CIV_TEAMS();
	DllExport int getMAX_TEAMS();
	DllExport int getINVALID_PLOT_COORD();
	DllExport int getNUM_CITY_PLOTS();
	DllExport int getCITY_HOME_PLOT();

	// ***** END EXPOSED TO PYTHON *****

	////////////// END DEFINES //////////////////

	DllExport void setDLLIFace(CvDLLUtilityIFaceBase* pDll);
#ifdef _USRDLL
	CvDLLUtilityIFaceBase* getDLLIFace() { return m_pDLL; }		// inlined for perf reasons, do not use outside of dll
#endif
	DllExport CvDLLUtilityIFaceBase* getDLLIFaceNonInl();

	DllExport bool IsGraphicsInitialized() const;
	DllExport void SetGraphicsInitialized(bool bVal);

	//
	// additional accessors for initting globals
	//

	DllExport void setInterface(CvInterface* pVal);
	DllExport void setDiplomacyScreen(CvDiplomacyScreen* pVal);
	DllExport void setMPDiplomacyScreen(CMPDiplomacyScreen* pVal);
	DllExport void setMessageQueue(CMessageQueue* pVal);
	DllExport void setHotJoinMessageQueue(CMessageQueue* pVal);
	DllExport void setMessageControl(CMessageControl* pVal);
	DllExport void setSetupData(CvSetupData* pVal);
	DllExport void setMessageCodeTranslator(CvMessageCodeTranslator* pVal);
	DllExport void setDropMgr(CvDropMgr* pVal);
	DllExport void setPortal(CvPortal* pVal);
	DllExport void setStatsReport(CvStatsReporter* pVal);
	DllExport void setPathFinder(FAStar* pVal);
	DllExport void setInterfacePathFinder(FAStar* pVal);
	DllExport void setStepFinder(FAStar* pVal);
	DllExport void setRouteFinder(FAStar* pVal);
	DllExport void setBorderFinder(FAStar* pVal);
	DllExport void setAreaFinder(FAStar* pVal);

	// So that CvEnums are moddable in the DLL
	DllExport int getNumDirections() const;
	DllExport int getNumResourceLayers() const;
	DllExport int getNumUnitLayerOptionTypes() const;
	DllExport int getNumGameOptions() const;
	DllExport int getNumMPOptions() const;
	DllExport int getNumSpecialOptions() const;
	DllExport int getNumGraphicOptions() const;
	DllExport int getNumTradeableItems() const;
	DllExport int getNumBasicItems() const;
	DllExport int getNumTradeableHeadings() const;
	DllExport int getNumCommandInfos() const;
	DllExport int getNumControlInfos() const;
	DllExport int getNumMissionInfos() const;
	DllExport int getNumPlayerOptionInfos() const;
	DllExport int getMaxNumSymbols() const;
	DllExport int getNumGraphicLevels() const;

	void deleteInfoArrays();

	// XML enum check - start - Nightinggale
	void CheckEnumInterfaceModeTypes() const;
	void CheckEnumWorldSizeTypes() const;
	void CheckEnumYieldTypes() const;
	void CheckEnumGameOptionTypes() const;
	void CheckEnumPlayerOptionTypes() const;
	void CheckEnumGraphicOptionTypes() const;
	void CheckEnumForceControlTypes() const;
	void CheckEnumDenialTypes() const;
	void CheckEnumDomainTypes() const;
	void CheckEnumUnitAITypes() const;
	void CheckEnumMissionTypes() const;
	void CheckEnumCommandTypes() const;
	void CheckEnumControlTypes() const;
	void CheckEnumMemoryTypes() const;
	void CheckEnumAttitudeTypes() const;
	// XML enum check - end - Nightinggale

	// cache XML - start - Nightinggale
	void setXMLCache();

	int getCache_ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES() const;
	int getCache_ADVANCED_START_CITY_COST() const;
	int getCache_ADVANCED_START_CITY_COST_INCREASE() const;
	int getCache_ADVANCED_START_CITY_PLACEMENT_MAX_RANGE() const;
	int getCache_ADVANCED_START_CULTURE_COST() const;
	int getCache_ADVANCED_START_MAX_UNITS_PER_CITY() const;
	int getCache_ADVANCED_START_POPULATION_COST() const;
	int getCache_ADVANCED_START_POPULATION_COST_INCREASE() const;
	int getCache_ADVANCED_START_SIGHT_RANGE() const;
	int getCache_ADVANCED_START_VISIBILITY_COST() const;
	int getCache_ADVANCED_START_VISIBILITY_COST_INCREASE() const;
	int getCache_AI_ADVANCED_TECH_START() const;
	int getCache_AI_CAN_DISBAND_UNITS() const;
	int getCache_AI_CHEAT_AUTO_BUY() const;
	int getCache_AI_CHEAT_NEEDED_DEFENDERS() const;
	int getCache_AI_CHEAT_SPICE() const;
	int getCache_AI_CHEAT_SPICE_BUY() const;
	int getCache_AI_CHEAT_SPICE_MULTIPLE() const;
	int getCache_AI_FAVORED_TERRAIN_MOD() const;
	int getCache_AI_HANDICAP_CASTLE() const;
	int getCache_AI_HANDICAP_MOTTE() const;
	int getCache_AI_MILITARY_PROFESSION_HACK() const;
	int getCache_AI_WAREHOUSE_MOD() const;
	int getCache_ALLIANCE_CULTURE_PERCENT_DENIAL() const;
	int getCache_ALLIANCE_PACT_PEACE_DENIAL() const;
	int getCache_ANIMAL_BANDITS_GUARD_GOODY_TIMER() const;
	int getCache_AUTORESEARCH_ALL() const;
	int getCache_BANQUET_YIELD_AMOUNT() const;
	int getCache_BARBARIAN_CIVILIZATION() const;
	int getCache_BARBARIAN_LEADER() const;
	int getCache_BASE_CITY_GROWTH_THRESHOLD() const;
	int getCache_BASE_CITY_LUXURY_FOOD_THRESHOLD_MOD() const;
	int getCache_BASE_OCCUPATION_TURNS() const;
	int getCache_BASE_UNIT_UPGRADE_COST() const;
	int getCache_BUILDINGCLASS_TRAVEL_TO_FAIR() const;
	int getCache_BUILDING_PRODUCTION_DECAY_PERCENT() const;
	int getCache_BUILDING_PRODUCTION_DECAY_TIME() const;
	int getCache_BUILDING_PRODUCTION_PERCENT() const;
	int getCache_BUY_PLOT_BASE_CULTURE_COST() const;
	int getCache_BUY_PLOT_CULTURE_RANGE() const;
	int getCache_BUY_PLOT_MIN_CULTURE() const;
	int getCache_BUY_PLOT_OWNED_COST_MODIFIER() const;
	int getCache_BUY_PLOT_SELLER_INCOME_PERCENT() const;
	int getCache_CALENDER_YEAR_FIRST_CHANGE_TURN() const;
	int getCache_CALENDER_YEAR_FIRST_MULTIPLIER() const;
	int getCache_CALENDER_YEAR_SECOND_CHANGE_TURN() const;
	int getCache_CALENDER_YEAR_SECOND_MULTIPLIER() const;
	int getCache_CALENDER_YEAR_THIRD_MULTIPLIER() const;
	int getCache_CAPITAL_BUILDINGCLASS() const;
	int getCache_CAPTURED_CARGO_RANDOM_AMOUNT() const;
	int getCache_CAPTURED_LUXURY_FOOD_RANDOM_AMOUNT() const;
	int getCache_CASTLES_TO_VILLAGES_RATIO() const;
	int getCache_CHANCE_TO_CAPTURE_CRIMINALS() const;
	int getCache_CHEAT_TRAVEL_ALL() const;
	int getCache_CITY_DEFENSE_DAMAGE_HEAL_RATE() const;
	int getCache_CITY_FREE_CULTURE_GROWTH_FACTOR() const;
	int getCache_CITY_GROWTH_MULTIPLIER() const;
	int getCache_CITY_HEAL_RATE() const;
	int getCache_CITY_PILGRAM_RANDOM() const;
	int getCache_CITY_SCREEN_FOG_ENABLED() const;
	int getCache_CITY_YIELD_CAPACITY() const;
	int getCache_CITY_YIELD_DECAY_PERCENT() const;
	int getCache_CIVICOPTION_INVENTIONS() const;
	int getCache_COLONIAL_FORCED_PEACE_TURNS() const;
	int getCache_COMBAT_DAMAGE() const;
	int getCache_COMBAT_DIE_SIDES() const;
	int getCache_COMBAT_EXPERIENCE_IN_BORDERS_PERCENT() const;
	int getCache_CONSUME_EQUIPMENT_ON_FOUND() const;
	int getCache_CONTACT_YIELD_GIFT_ENCOMEIDA_TIMER() const;
	int getCache_CONTACT_YIELD_GIFT_TECH() const;
	int getCache_CULTURE_YIELD() const;
	int getCache_DEAL_TRADE_RELATIONS_POINTS() const;
	int getCache_DEEP_WATER_TERRAIN() const;
	int getCache_DEFAULT_BUILD_CASTLE() const;
	int getCache_DEFAULT_BUILD_MOTTE_AND_BAILEY() const;
	int getCache_DEFAULT_CENSURETYPE_ANATHEMA() const;
	int getCache_DEFAULT_CENSURETYPE_ANATHEMA_COUNT() const;
	int getCache_DEFAULT_CENSURETYPE_EXCOMMUNICATION() const;
	int getCache_DEFAULT_CENSURETYPE_EXCOMMUNICATION_COUNT() const;
	int getCache_DEFAULT_CENSURETYPE_INTERDICT() const;
	int getCache_DEFAULT_CENSURETYPE_INTERDICT_COUNT() const;
	int getCache_DEFAULT_COMBAT_FOR_TRAINING() const;
	int getCache_DEFAULT_DAWN_POPULATION_UNIT() const;
	int getCache_DEFAULT_FUEDALISM_TECH() const;
	int getCache_DEFAULT_GRAIN_GROWTH_UNIT_CLASS() const;
	int getCache_DEFAULT_HUNTSMAN_PROFESSION() const;
	int getCache_DEFAULT_INVENTOR_CLASS() const;
	int getCache_DEFAULT_KNIGHT_PROFESSION_PROMOTION() const;
	int getCache_DEFAULT_KNIGHT_PROMOTION() const;
	int getCache_DEFAULT_MARAUDER_CLASS() const;
	int getCache_DEFAULT_MARUADER_SEA_PROFESSION() const;
	int getCache_DEFAULT_NOBLEMAN_CLASS() const;
	int getCache_DEFAULT_NOBLE_GROWTH_UNIT_CLASS() const;
	int getCache_DEFAULT_PILGRAM_CLASS() const;
	int getCache_DEFAULT_POPULATION_UNIT() const;
	int getCache_DEFAULT_SHRINE_CLASS() const;
	int getCache_DEFAULT_SLAVE_CLASS() const;
	int getCache_DEFAULT_SPECIALBUILDING_COURTHOUSE() const;
	int getCache_DEFAULT_TEST_DEFINE() const;
	int getCache_DEFAULT_TRAINED_PROMOTION() const;
	int getCache_DEFAULT_TREASURE_YIELD() const;
	int getCache_DEFAULT_UNTRAINED_PROMOTION() const;
	int getCache_DEFAULT_VIKING_ERA() const;
	int getCache_DEFAULT_YIELD_ARMOR_TYPE() const;
	int getCache_DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT() const;
	int getCache_DIPLOMACY_VALUE_REMAINDER() const;
	int getCache_DOCKS_NEXT_UNITS() const;
	int getCache_EDUCATION_BASE_TUITION() const;
	int getCache_EDUCATION_THRESHOLD() const;
	int getCache_EDUCATION_THRESHOLD_INCREASE() const;
	int getCache_ENABLE_ALLIANCE_TRADING() const;
	int getCache_ENABLE_DEFENSIVE_PACT_TRADING() const;
	int getCache_ENABLE_GOLD_TRADING() const;
	int getCache_ENABLE_MAP_TRADING() const;
	int getCache_ENABLE_OPEN_BORDERS() const;
	int getCache_END_GAME_DISPLAY_WARNING() const;
	int getCache_ENEMY_HEAL_RATE() const;
	int getCache_ESTABLISH_TRADEPOST_COST() const;
	int getCache_EUROPE_EAST() const;
	int getCache_EUROPE_MARKET_CORRELATION_PERCENT() const;
	int getCache_EVENT_PROBABILITY_ROLL_SIDES() const;
	int getCache_EXPERIENCE_FROM_WITHDRAWL() const;
	int getCache_EXTRA_YIELD() const;
	int getCache_FATHER_COST_EXTRA_TEAM_MEMBER_MODIFIER() const;
	int getCache_FATHER_POINT_REAL_TRADE() const;
	int getCache_FEATURE_PRODUCTION_YIELD_MAX_DISTANCE() const;
	int getCache_FIRST_EVENT_DELAY_TURNS() const;
	int getCache_FOUND_MONASTERY_NUMBER() const;
	int getCache_FOUND_MOTTE_AND_BAILEY_NUMBER() const;
	int getCache_FOUND_OUTPOST_NUMBER() const;
	int getCache_FOUND_VILLAGE_NUMBER() const;
	int getCache_FREE_CITY_ADJACENT_CULTURE() const;
	int getCache_FREE_CITY_CULTURE() const;
	int getCache_FREE_PEASANT_CIVIC() const;
	int getCache_FRIENDLY_HEAL_RATE() const;
	int getCache_GREAT_GENERALS_THRESHOLD() const;
	int getCache_GREAT_GENERALS_THRESHOLD_INCREASE() const;
	int getCache_GREAT_GENERALS_THRESHOLD_INCREASE_TEAM() const;
	int getCache_HIRE_GUARD_COST() const;
	int getCache_HIRE_GUARD_PROMOTION() const;
	int getCache_IMMIGRATION_MAX_CITY_DISTANCE() const;
	int getCache_IMMIGRATION_THRESHOLD() const;
	int getCache_IMMIGRATION_THRESHOLD_INCREASE() const;
	int getCache_IMMIGRATION_TRAVEL_MOD() const;
	int getCache_INDUSTRIAL_VICTORY_SINGLE_YIELD() const;
	int getCache_INITIAL_AI_CITY_PRODUCTION() const;
	int getCache_INITIAL_CITY_POPULATION() const;
	int getCache_INITIAL_CITY_ROUTE_TYPE() const;
	int getCache_JUNGLE_FEATURE() const;
	int getCache_KING_BUY_UNIT_PRICE_MODIFIER() const;
	int getCache_KING_INITIAL_UNIT_INCREASE() const;
	int getCache_KING_TRANSPORT_TREASURE_COMISSION() const;
	int getCache_KNIGHT_RANSOM_MOD() const;
	int getCache_LAKE_PLOT_RAND() const;
	int getCache_LAND_IMPROVEMENT() const;
	int getCache_LAND_TERRAIN() const;
	int getCache_MARAUDERS_DAYSOUT_RANDOM() const;
	int getCache_MARAUDERS_TOWER_RANGE() const;
	int getCache_MARAUDER_CRUMBS_EVENT() const;
	int getCache_MARAUDER_EVENT_DEFAULT_TURNS() const;
	int getCache_MAX_CITY_POPULATION_COMMUNE() const;
	int getCache_MAX_CITY_POPULATION_VILLAGE() const;
	int getCache_MAX_EXPERIENCE_AFTER_UPGRADE() const;
	int getCache_MAX_EXPERIENCE_PER_COMBAT() const;
	int getCache_MAX_FORTIFY_TURNS() const;
	int getCache_MAX_INSULT_MODIFIER() const;
	int getCache_MAX_LEVEL_FROM_ANIMAL_XP() const;
	int getCache_MAX_MARAUDERS() const;
	int getCache_MAX_NUM_LANGUAGES() const;
	int getCache_MAX_PLOT_LIST_SIZE() const;
	int getCache_MAX_REBEL_COMBAT_MULTIPLER() const;
	int getCache_MAX_TRAINED_EXPERIENCE() const;
	int getCache_MAX_WITHDRAWAL_PROBABILITY() const;
	int getCache_MEDIEVAL_CENSURE() const;
	int getCache_MEDIEVAL_TRADE_TECH() const;
	int getCache_MINIMAP_RENDER_SIZE() const;
	int getCache_MIN_ANIMAL_STARTING_DISTANCE() const;
	int getCache_MIN_CITY_YIELD_DECAY() const;
	int getCache_MIN_CIV_STARTING_DISTANCE() const;
	int getCache_MIN_EXPERIENCE_PER_COMBAT() const;
	int getCache_MIN_TIMER_UNIT_DOUBLE_MOVES() const;
	int getCache_MIN_WATER_SIZE_FOR_OCEAN() const;
	int getCache_MISSIONARY_RATE_EFFECT_ON_SUCCESS() const;
	int getCache_MISSIONARY_THRESHOLD() const;
	int getCache_MISSIONARY_THRESHOLD_INCREASE() const;
	int getCache_MONASTERIES_TO_VILLAGES_RATIO() const;
	int getCache_NATIVE_AUTO_SELL_PERCENT() const;
	int getCache_NATIVE_GOODS_RAID_PERCENT() const;
	int getCache_NATIVE_GROWTH_THRESHOLD_MULTIPLIER() const;
	int getCache_NATIVE_HORSES_FOR_SALE() const;
	int getCache_NATIVE_HORSES_FOR_SALE_PERCENT() const;
	int getCache_NATIVE_TEACH_THRESHOLD_INCREASE() const;
	int getCache_NATIVE_TECH() const;
	int getCache_NATIVE_TRADING_TRADEPOST() const;
	int getCache_NEUTRAL_HEAL_RATE() const;
	int getCache_NEW_CITY_BUILDING_VALUE_MODIFIER() const;
	int getCache_NEW_HURRY_MODIFIER() const;
	int getCache_NOBLE_FIELD_LABOR_PENALTY() const;
	int getCache_NO_BAD_GOODIES_EXPERIENCE_PERCENT() const;
	int getCache_NO_BAD_GOODIES_GOLD_PERCENT() const;
	int getCache_NO_CITY_SHORTAGE_MESSAGES() const;
	int getCache_NO_STARTING_PLOTS_IN_JUNGLE() const;
	int getCache_OCCUPATION_CULTURE_PERCENT_THRESHOLD() const;
	int getCache_OCCUPATION_TURNS_POPULATION_PERCENT() const;
	int getCache_OWNERSHIP_SCORE_DURATION_THRESHOLD() const;
	int getCache_OWN_TEAM_STARTING_MODIFIER() const;
	int getCache_PEACE_TREATY_LENGTH() const;
	int getCache_PERCENT_TAX_ON_AUTOSELL_GOODS() const;
	int getCache_PILGRAM_OFFER_GOLD() const;
	int getCache_PILGRAM_OFFER_GOLD_DISTANCE_MOD() const;
	int getCache_PLAYER_ALWAYS_RAZES_CITIES() const;
	int getCache_PLOTS_PER_RIVER_EDGE() const;
	int getCache_PLOT_VISIBILITY_RANGE() const;
	int getCache_PROFESSION_COAL_BURNER() const;
	int getCache_PROFESSION_INVENTOR() const;
	int getCache_PROLIFIC_INVENTOR_THRESHOLD_INCREASE() const;
	int getCache_PROMOTION_BUILD_HOME() const;
	int getCache_RANDOM_TURNS_LOST_AT_SEA() const;
	int getCache_RAZING_CULTURAL_PERCENT_THRESHOLD() const;
	int getCache_REBEL_PERCENT_FOR_REVOLUTION() const;
	int getCache_REBEL_SENTIMENT_BELLS_FACTOR() const;
	int getCache_REBEL_SENTIMENT_TURN_WEIGHT() const;
	int getCache_REVOLUTION_EUROPE_UNIT_SHIP_MODIFIER() const;
	int getCache_REVOLUTION_EUROPE_UNIT_THRESHOLD() const;
	int getCache_REVOLUTION_EUROPE_UNIT_THRESHOLD_INCREASE() const;
	int getCache_RIVAL_TEAM_STARTING_MODIFIER() const;
	int getCache_RIVER_SOURCE_MIN_RIVER_RANGE() const;
	int getCache_RIVER_SOURCE_MIN_SEAWATER_RANGE() const;
	int getCache_RUINS_IMPROVEMENT() const;
	int getCache_SCORE_FATHER_FACTOR() const;
	int getCache_SCORE_LAND_FACTOR() const;
	int getCache_SCORE_POPULATION_FACTOR() const;
	int getCache_SCORE_TAX_FACTOR() const;
	int getCache_SETTLEMENT_TREASURE_YIELD() const;
	int getCache_SHALLOW_WATER_TERRAIN() const;
	int getCache_SLAVE_FOOD_CONSUMPTION_PER_POPULATION() const;
	int getCache_STANDARD_CALENDAR() const;
	int getCache_STANDARD_CLIMATE() const;
	int getCache_STANDARD_ERA() const;
	int getCache_STANDARD_GAMESPEED() const;
	int getCache_STANDARD_HANDICAP() const;
	int getCache_STANDARD_SEALEVEL() const;
	int getCache_STANDARD_TURNTIMER() const;
	int getCache_STARTING_DISTANCE_PERCENT() const;
	int getCache_START_YEAR() const;
	int getCache_STEAMWORKS_BUILDING() const;
	int getCache_STEAMWORKS_CLASS_TYPE() const;
	int getCache_TAX_INCREASE_CHANCE() const;
	int getCache_TAX_RATE_MAX_INCREASE() const;
	int getCache_TAX_TRADE_THRESHOLD() const;
	int getCache_TAX_TRADE_THRESHOLD_ATTITUDE_PERCENT() const;
	int getCache_TAX_TRADE_THRESHOLD_TAX_RATE_PERCENT() const;
	int getCache_TK_AI_RESEARCH_COST_MOD_PERCENT() const;
	int getCache_TK_HUMAN_RESEARCH_COST_MOD_PERCENT() const;
	int getCache_TK_IDEAS_CITY_VALUE() const;
	int getCache_TK_MAX_FORTS_PER_CITY() const;
	int getCache_TK_PIONEER_COAL_FURNACE_BONUS() const;
	int getCache_TK_PROLIFIC_INVENTOR_PROGRESS() const;
	int getCache_TK_PROLIFIC_INVENTOR_THRESHOLD() const;
	int getCache_TK_RESEARCH_PACT_IDEAS_THRESHOLD() const;
	int getCache_TK_RESEARCH_TRADE_VALUE() const;
	int getCache_TK_STEAMWORKS_MODIFIER() const;
	int getCache_TRADE_POINTS_FOR_ROUTE() const;
	int getCache_TRADE_ROUTE_SPICE() const;
	int getCache_TRADE_STIMULATES_RESEARCH_MIN_VALUE() const;
	int getCache_TRADE_STIMULATES_RESEARCH_PERCENT() const;
	int getCache_TRADING_POINTS_MOD_PERCENT() const;
	int getCache_TREASURE_UNITCLASS() const;
	int getCache_TREASURE_UNITS_ONLY_SELECT_COASTAL() const;
	int getCache_TURNS_TO_TRAIN() const;
	int getCache_UNITARMOR_LEATHER() const;
	int getCache_UNITARMOR_MAIL() const;
	int getCache_UNITARMOR_PLATE() const;
	int getCache_UNITARMOR_SCALE() const;
	int getCache_UNITARMOR_SHIELD() const;
	int getCache_UNITCLASS_PIONEER() const;
	int getCache_UNITTACTIC_PARRY() const;
	int getCache_UNITWEAPON_BLUNT() const;
	int getCache_UNIT_PRODUCTION_DECAY_PERCENT() const;
	int getCache_UNIT_PRODUCTION_DECAY_TIME() const;
	int getCache_UNIT_PRODUCTION_PERCENT() const;
	int getCache_UNIT_UPGRADE_COST_PER_PRODUCTION() const;
	int getCache_UNIT_VISIBILITY_RANGE() const;
	int getCache_USE_MEDIEVAL_CALENDER() const;
	int getCache_VASSAL_CIVILIZATION() const;
	int getCache_VASSAL_LEADER() const;
	int getCache_WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT() const;
	int getCache_WAR_SUCCESS_ATTACKING() const;
	int getCache_WAR_SUCCESS_CITY_CAPTURING() const;
	int getCache_WAR_SUCCESS_DEFENDING() const;
	int getCache_WAR_SUCCESS_UNIT_CAPTURING() const;
	int getCache_WATER_IMPROVEMENT() const;
	int getCache_WATER_UNIT_FACING_DIRECTION() const;
	int getCache_WEEKS_PER_MONTHS() const;
	int getCache_WILD_ANIMAL_ATTACK_WEIGHT() const;
	int getCache_WILD_ANIMAL_LAND_BONUS_NATIVE_WEIGHT() const;
	int getCache_WILD_ANIMAL_LAND_FEATURE_NATIVE_WEIGHT() const;
	int getCache_WILD_ANIMAL_LAND_PATROL_BASE_WEIGHT() const;
	int getCache_WILD_ANIMAL_LAND_TERRAIN_NATIVE_WEIGHT() const;
	int getCache_WILD_ANIMAL_LAND_UNIT_VARIATION_WEIGHT() const;
	int getCache_WILD_ANIMAL_SEA_BONUS_NATIVE_WEIGHT() const;
	int getCache_WILD_ANIMAL_SEA_FEATURE_NATIVE_WEIGHT() const;
	int getCache_WILD_ANIMAL_SEA_PATROL_BASE_WEIGHT() const;
	int getCache_WILD_ANIMAL_SEA_TERRAIN_NATIVE_WEIGHT() const;
	int getCache_WILD_ANIMAL_SEA_UNIT_VARIATION_WEIGHT() const;
	// cache XML - end - Nightinggale

protected:

	bool m_bGraphicsInitialized;
	bool m_bLogging;
	bool m_bRandLogging;
	bool m_bSynchLogging;
	bool m_bOverwriteLogs;
	NiPoint3  m_pt3CameraDir;
	int m_iNewPlayers;

	CMainMenu* m_pkMainMenu;

	bool m_bZoomOut;
	bool m_bZoomIn;
	bool m_bLoadGameFromFile;

	FMPIManager * m_pFMPMgr;

	CvRandom* m_asyncRand;

	CvGameAI* m_game;

	CMessageQueue* m_messageQueue;
	CMessageQueue* m_hotJoinMsgQueue;
	CMessageControl* m_messageControl;
	CvSetupData* m_setupData;
	CvInitCore* m_iniInitCore;
	CvInitCore* m_loadedInitCore;
	CvInitCore* m_initCore;
	CvMessageCodeTranslator * m_messageCodes;
	CvDropMgr* m_dropMgr;
	CvPortal* m_portal;
	CvStatsReporter * m_statsReporter;
	CvInterface* m_interface;

	CvArtFileMgr* m_pArtFileMgr;

	CvMap* m_map;

	CvDiplomacyScreen* m_diplomacyScreen;
	CMPDiplomacyScreen* m_mpDiplomacyScreen;

	FAStar* m_pathFinder;
	FAStar* m_interfacePathFinder;
	FAStar* m_stepFinder;
	FAStar* m_routeFinder;
	FAStar* m_borderFinder;
	FAStar* m_areaFinder;

	NiPoint3 m_pt3Origin;

	int* m_aiPlotDirectionX;	// [NUM_DIRECTION_TYPES];
	int* m_aiPlotDirectionY;	// [NUM_DIRECTION_TYPES];
	int* m_aiPlotCardinalDirectionX;	// [NUM_CARDINALDIRECTION_TYPES];
	int* m_aiPlotCardinalDirectionY;	// [NUM_CARDINALDIRECTION_TYPES];
	int* m_aiCityPlotX;	// [NUM_CITY_PLOTS];
	int* m_aiCityPlotY;	// [NUM_CITY_PLOTS];
	int* m_aiCityPlotPriority;	// [NUM_CITY_PLOTS];
	int m_aaiXYCityPlot[CITY_PLOTS_DIAMETER][CITY_PLOTS_DIAMETER];

	DirectionTypes* m_aeTurnLeftDirection;	// [NUM_DIRECTION_TYPES];
	DirectionTypes* m_aeTurnRightDirection;	// [NUM_DIRECTION_TYPES];
	DirectionTypes m_aaeXYDirection[DIRECTION_DIAMETER][DIRECTION_DIAMETER];

	//InterfaceModeInfo m_aInterfaceModeInfo[NUM_INTERFACEMODE_TYPES] =
	std::vector<CvInterfaceModeInfo*> m_paInterfaceModeInfo;

	/***********************************************************************************************************************
	Globals loaded from XML
	************************************************************************************************************************/

	// all type strings are upper case and are kept in this hash map for fast lookup, Moose
	typedef stdext::hash_map<std::string /* type string */, int /* info index */> InfosMap;
	InfosMap m_infosMap;
	std::vector<std::vector<CvInfoBase *> *> m_aInfoVectors;

	std::vector<CvColorInfo*> m_paColorInfo;
	std::vector<CvPlayerColorInfo*> m_paPlayerColorInfo;
	std::vector<CvInfoBase*> m_paHints;
	std::vector<CvMainMenuInfo*> m_paMainMenus;
	std::vector<CvTerrainInfo*> m_paTerrainInfo;
	std::vector<CvLandscapeInfo*> m_paLandscapeInfo;
	int m_iActiveLandscapeID;
	std::vector<CvWorldInfo*> m_paWorldInfo;
	std::vector<CvClimateInfo*> m_paClimateInfo;
	std::vector<CvSeaLevelInfo*> m_paSeaLevelInfo;
	std::vector<CvEuropeInfo*> m_paEuropeInfo;
	std::vector<CvYieldInfo*> m_paYieldInfo;
	std::vector<CvRouteInfo*> m_paRouteInfo;
	std::vector<CvFeatureInfo*> m_paFeatureInfo;
	std::vector<CvBonusInfo*> m_paBonusInfo;
	std::vector<CvImprovementInfo*> m_paImprovementInfo;
	std::vector<CvGoodyInfo*> m_paGoodyInfo;
	std::vector<CvBuildInfo*> m_paBuildInfo;
	std::vector<CvHandicapInfo*> m_paHandicapInfo;
	std::vector<CvGameSpeedInfo*> m_paGameSpeedInfo;
	std::vector<CvAlarmInfo*> m_paAlarmInfo;
	std::vector<CvTurnTimerInfo*> m_paTurnTimerInfo;
	std::vector<CvCivilizationInfo*> m_paCivilizationInfo;
	std::vector<CvLeaderHeadInfo*> m_paLeaderHeadInfo;
	std::vector<CvTraitInfo*> m_paTraitInfo;
	std::vector<CvCursorInfo*> m_paCursorInfo;
	std::vector<CvSlideShowInfo*> m_paSlideShowInfo;
	std::vector<CvSlideShowRandomInfo*> m_paSlideShowRandomInfo;
	std::vector<CvWorldPickerInfo*> m_paWorldPickerInfo;
	std::vector<CvBuildingClassInfo*> m_paBuildingClassInfo;
	std::vector<CvBuildingInfo*> m_paBuildingInfo;
	std::vector<CvSpecialBuildingInfo*> m_paSpecialBuildingInfo;
	std::vector<CvUnitClassInfo*> m_paUnitClassInfo;
	std::vector<CvUnitInfo*> m_paUnitInfo;
	std::vector<CvSpecialUnitInfo*> m_paSpecialUnitInfo;
	std::vector<CvInfoBase*> m_paConceptInfo;
	std::vector<CvInfoBase*> m_paCalendarInfo;
	std::vector<CvInfoBase*> m_paSeasonInfo;
	std::vector<CvInfoBase*> m_paMonthInfo;
	std::vector<CvInfoBase*> m_paDenialInfo;
	std::vector<CvInfoBase*> m_paInvisibleInfo;
	std::vector<CvFatherInfo*> m_paFatherInfo;
	std::vector<CvFatherPointInfo*> m_paFatherPointInfo;
	std::vector<CvInfoBase*> m_paUnitCombatInfo;
	std::vector<CvInfoBase*> m_paDomainInfo;
	std::vector<CvInfoBase*> m_paUnitAIInfos;
	std::vector<CvInfoBase*> m_paAttitudeInfos;
	std::vector<CvInfoBase*> m_paMemoryInfos;
	std::vector<CvInfoBase*> m_paFatherCategoryInfos;
	std::vector<CvInfoBase*> m_paFeatInfos;
	std::vector<CvGameOptionInfo*> m_paGameOptionInfos;
	std::vector<CvMPOptionInfo*> m_paMPOptionInfos;
	std::vector<CvForceControlInfo*> m_paForceControlInfos;
	std::vector<CvPlayerOptionInfo*> m_paPlayerOptionInfos;
	std::vector<CvGraphicOptionInfo*> m_paGraphicOptionInfos;
	std::vector<CvEmphasizeInfo*> m_paEmphasizeInfo;
	std::vector<CvCultureLevelInfo*> m_paCultureLevelInfo;
	std::vector<CvActionInfo*> m_paActionInfo;
	std::vector<CvMissionInfo*> m_paMissionInfo;
	std::vector<CvControlInfo*> m_paControlInfo;
	std::vector<CvCommandInfo*> m_paCommandInfo;
	std::vector<CvAutomateInfo*> m_paAutomateInfo;
	std::vector<CvPromotionInfo*> m_paPromotionInfo;
	std::vector<CvProfessionInfo*> m_paProfessionInfo;
	std::vector<CvInfoBase*> m_paCivicOptionInfo;
	std::vector<CvCivicInfo*> m_paCivicInfo;
	std::vector<CvDiplomacyInfo*> m_paDiplomacyInfo;
	std::vector<CvEraInfo*> m_aEraInfo;	// [NUM_ERA_TYPES];
	std::vector<CvHurryInfo*> m_paHurryInfo;
	std::vector<CvVictoryInfo*> m_paVictoryInfo;
	std::vector<CvRouteModelInfo*> m_paRouteModelInfo;
	std::vector<CvRiverModelInfo*> m_paRiverModelInfo;
	std::vector<CvWaterPlaneInfo*> m_paWaterPlaneInfo;
	std::vector<CvTerrainPlaneInfo*> m_paTerrainPlaneInfo;
	std::vector<CvCameraOverlayInfo*> m_paCameraOverlayInfo;
	std::vector<CvAnimationPathInfo*> m_paAnimationPathInfo;
	std::vector<CvAnimationCategoryInfo*> m_paAnimationCategoryInfo;
	std::vector<CvEntityEventInfo*> m_paEntityEventInfo;
	std::vector<CvUnitFormationInfo*> m_paUnitFormationInfo;
	std::vector<CvEffectInfo*> m_paEffectInfo;
	std::vector<CvAttachableInfo*> m_paAttachableInfo;
	std::vector<CvEventTriggerInfo*> m_paEventTriggerInfo;
	std::vector<CvEventInfo*> m_paEventInfo;
	//Androrc UnitArtStyles
    std::vector<CvUnitArtStyleTypeInfo*> m_paUnitArtStyleTypeInfo;
	//Androrc End

	// Game Text
	std::vector<CvGameText*> m_paGameTextXML;

	//////////////////////////////////////////////////////////////////////////
	// GLOBAL TYPES
	//////////////////////////////////////////////////////////////////////////

	// XXX These are duplicates and are kept for enumeration convenience - most could be removed, Moose
	CvString *m_paszEntityEventTypes2;
	CvString *m_paszEntityEventTypes;
	int m_iNumEntityEventTypes;

	CvString *m_paszAnimationOperatorTypes;
	int m_iNumAnimationOperatorTypes;

	CvString* m_paszFunctionTypes;

	CvString *m_paszArtStyleTypes;
	int m_iNumArtStyleTypes;

	CvString *m_paszCitySizeTypes;
	int m_iNumCitySizeTypes;

	CvString *m_paszContactTypes;

	CvString *m_paszDiplomacyPowerTypes;

	CvString *m_paszAutomateTypes;
    ///TKs Med
    CvString *m_paszMedCityTypes;

    CvString *m_paszTradeScreenTypes;

    CvString *m_paszModCodeTypes;
    ///TKe
	CvString *m_paszDirectionTypes;

	CvString *m_paszFootstepAudioTypes;
	int m_iNumFootstepAudioTypes;

	CvString *m_paszFootstepAudioTags;
	int m_iNumFootstepAudioTags;

	CvString m_szCurrentXMLFile;
	//////////////////////////////////////////////////////////////////////////
	// Formerly Global Defines
	//////////////////////////////////////////////////////////////////////////

	FVariableSystem* m_VarSystem;

	int m_iMOVE_DENOMINATOR;
	int m_iFOOD_CONSUMPTION_PER_POPULATION;
	int m_iMAX_HIT_POINTS;
	int m_iHILLS_EXTRA_DEFENSE;
	int m_iRIVER_ATTACK_MODIFIER;
	int m_iAMPHIB_ATTACK_MODIFIER;
	int m_iHILLS_EXTRA_MOVEMENT;
	int m_iPEAK_EXTRA_MOVEMENT;
	int m_iMAX_PLOT_LIST_ROWS;
	int m_iUNIT_MULTISELECT_MAX;
	int m_iEVENT_MESSAGE_TIME;
	int m_iROUTE_FEATURE_GROWTH_MODIFIER;
	int m_iFEATURE_GROWTH_MODIFIER;
	int m_iMIN_CITY_RANGE;
	int m_iCITY_MAX_NUM_BUILDINGS;
	int m_iLAKE_MAX_AREA_SIZE;
	int m_iMIN_WATER_SIZE_FOR_OCEAN;
	int m_iFORTIFY_MODIFIER_PER_TURN;
	int m_iMAX_CITY_DEFENSE_DAMAGE;
	int m_iPEAK_SEE_THROUGH_CHANGE;
	int m_iHILLS_SEE_THROUGH_CHANGE;
	int m_iSEAWATER_SEE_FROM_CHANGE;
	int m_iPEAK_SEE_FROM_CHANGE;
	int m_iHILLS_SEE_FROM_CHANGE;
	int m_iMAX_REBEL_YIELD_MODIFIER;

	float m_fCAMERA_MIN_YAW;
	float m_fCAMERA_MAX_YAW;
	float m_fCAMERA_FAR_CLIP_Z_HEIGHT;
	float m_fCAMERA_MAX_TRAVEL_DISTANCE;
	float m_fCAMERA_START_DISTANCE;
	float m_fPLOT_SIZE;
	float m_fCAMERA_SPECIAL_PITCH;
	float m_fCAMERA_MAX_TURN_OFFSET;
	float m_fCAMERA_MIN_DISTANCE;
	float m_fCAMERA_UPPER_PITCH;
	float m_fCAMERA_LOWER_PITCH;
	float m_fFIELD_OF_VIEW;
	float m_fUNIT_MULTISELECT_DISTANCE;

	int m_iUSE_CAN_FOUND_CITIES_ON_WATER_CALLBACK;
	int m_iUSE_CANNOT_DO_CIVIC_CALLBACK;
	int m_iUSE_CAN_DO_CIVIC_CALLBACK;
	int m_iUSE_CANNOT_CONSTRUCT_CALLBACK;
	int m_iUSE_CAN_CONSTRUCT_CALLBACK;
	int m_iUSE_CAN_DECLARE_WAR_CALLBACK;
	int m_iUSE_GET_UNIT_COST_MOD_CALLBACK;
	int m_iUSE_GET_BUILDING_COST_MOD_CALLBACK;
	int m_iUSE_GET_CITY_FOUND_VALUE_CALLBACK;
	int m_iUSE_CANNOT_HANDLE_ACTION_CALLBACK;
	int m_iUSE_CAN_BUILD_CALLBACK;
	int m_iUSE_CANNOT_TRAIN_CALLBACK;
	int m_iUSE_CAN_TRAIN_CALLBACK;
	int m_iUSE_UNIT_CANNOT_MOVE_INTO_CALLBACK;
	int m_iUSE_FINISH_TEXT_CALLBACK;
	int m_iUSE_ON_UNIT_SET_XY_CALLBACK;
	int m_iUSE_ON_UNIT_SELECTED_CALLBACK;
	int m_iUSE_ON_MISSIONARY_CONVERTED_UNIT_CALLBACK;
	int m_iUSE_ON_UPDATE_CALLBACK;
	int m_iUSE_ON_UNIT_CREATED_CALLBACK;
	int m_iUSE_ON_UNIT_LOST_CALLBACK;

	// cache XML - start - Nightinggale
	int m_cache_ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES;
	int m_cache_ADVANCED_START_CITY_COST;
	int m_cache_ADVANCED_START_CITY_COST_INCREASE;
	int m_cache_ADVANCED_START_CITY_PLACEMENT_MAX_RANGE;
	int m_cache_ADVANCED_START_CULTURE_COST;
	int m_cache_ADVANCED_START_MAX_UNITS_PER_CITY;
	int m_cache_ADVANCED_START_POPULATION_COST;
	int m_cache_ADVANCED_START_POPULATION_COST_INCREASE;
	int m_cache_ADVANCED_START_SIGHT_RANGE;
	int m_cache_ADVANCED_START_VISIBILITY_COST;
	int m_cache_ADVANCED_START_VISIBILITY_COST_INCREASE;
	int m_cache_AI_ADVANCED_TECH_START;
	int m_cache_AI_CAN_DISBAND_UNITS;
	int m_cache_AI_CHEAT_AUTO_BUY;
	int m_cache_AI_CHEAT_NEEDED_DEFENDERS;
	int m_cache_AI_CHEAT_SPICE;
	int m_cache_AI_CHEAT_SPICE_BUY;
	int m_cache_AI_CHEAT_SPICE_MULTIPLE;
	int m_cache_AI_FAVORED_TERRAIN_MOD;
	int m_cache_AI_HANDICAP_CASTLE;
	int m_cache_AI_HANDICAP_MOTTE;
	int m_cache_AI_MILITARY_PROFESSION_HACK;
	int m_cache_AI_WAREHOUSE_MOD;
	int m_cache_ALLIANCE_CULTURE_PERCENT_DENIAL;
	int m_cache_ALLIANCE_PACT_PEACE_DENIAL;
	int m_cache_ANIMAL_BANDITS_GUARD_GOODY_TIMER;
	int m_cache_AUTORESEARCH_ALL;
	int m_cache_BANQUET_YIELD_AMOUNT;
	int m_cache_BARBARIAN_CIVILIZATION;
	int m_cache_BARBARIAN_LEADER;
	int m_cache_BASE_CITY_GROWTH_THRESHOLD;
	int m_cache_BASE_CITY_LUXURY_FOOD_THRESHOLD_MOD;
	int m_cache_BASE_OCCUPATION_TURNS;
	int m_cache_BASE_UNIT_UPGRADE_COST;
	int m_cache_BUILDINGCLASS_TRAVEL_TO_FAIR;
	int m_cache_BUILDING_PRODUCTION_DECAY_PERCENT;
	int m_cache_BUILDING_PRODUCTION_DECAY_TIME;
	int m_cache_BUILDING_PRODUCTION_PERCENT;
	int m_cache_BUY_PLOT_BASE_CULTURE_COST;
	int m_cache_BUY_PLOT_CULTURE_RANGE;
	int m_cache_BUY_PLOT_MIN_CULTURE;
	int m_cache_BUY_PLOT_OWNED_COST_MODIFIER;
	int m_cache_BUY_PLOT_SELLER_INCOME_PERCENT;
	int m_cache_CALENDER_YEAR_FIRST_CHANGE_TURN;
	int m_cache_CALENDER_YEAR_FIRST_MULTIPLIER;
	int m_cache_CALENDER_YEAR_SECOND_CHANGE_TURN;
	int m_cache_CALENDER_YEAR_SECOND_MULTIPLIER;
	int m_cache_CALENDER_YEAR_THIRD_MULTIPLIER;
	int m_cache_CAPITAL_BUILDINGCLASS;
	int m_cache_CAPTURED_CARGO_RANDOM_AMOUNT;
	int m_cache_CAPTURED_LUXURY_FOOD_RANDOM_AMOUNT;
	int m_cache_CASTLES_TO_VILLAGES_RATIO;
	int m_cache_CHANCE_TO_CAPTURE_CRIMINALS;
	int m_cache_CHEAT_TRAVEL_ALL;
	int m_cache_CITY_DEFENSE_DAMAGE_HEAL_RATE;
	int m_cache_CITY_FREE_CULTURE_GROWTH_FACTOR;
	int m_cache_CITY_GROWTH_MULTIPLIER;
	int m_cache_CITY_HEAL_RATE;
	int m_cache_CITY_PILGRAM_RANDOM;
	int m_cache_CITY_SCREEN_FOG_ENABLED;
	int m_cache_CITY_YIELD_CAPACITY;
	int m_cache_CITY_YIELD_DECAY_PERCENT;
	int m_cache_CIVICOPTION_INVENTIONS;
	int m_cache_COLONIAL_FORCED_PEACE_TURNS;
	int m_cache_COMBAT_DAMAGE;
	int m_cache_COMBAT_DIE_SIDES;
	int m_cache_COMBAT_EXPERIENCE_IN_BORDERS_PERCENT;
	int m_cache_CONSUME_EQUIPMENT_ON_FOUND;
	int m_cache_CONTACT_YIELD_GIFT_ENCOMEIDA_TIMER;
	int m_cache_CONTACT_YIELD_GIFT_TECH;
	int m_cache_CULTURE_YIELD;
	int m_cache_DEAL_TRADE_RELATIONS_POINTS;
	int m_cache_DEEP_WATER_TERRAIN;
	int m_cache_DEFAULT_BUILD_CASTLE;
	int m_cache_DEFAULT_BUILD_MOTTE_AND_BAILEY;
	int m_cache_DEFAULT_CENSURETYPE_ANATHEMA;
	int m_cache_DEFAULT_CENSURETYPE_ANATHEMA_COUNT;
	int m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION;
	int m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION_COUNT;
	int m_cache_DEFAULT_CENSURETYPE_INTERDICT;
	int m_cache_DEFAULT_CENSURETYPE_INTERDICT_COUNT;
	int m_cache_DEFAULT_COMBAT_FOR_TRAINING;
	int m_cache_DEFAULT_DAWN_POPULATION_UNIT;
	int m_cache_DEFAULT_FUEDALISM_TECH;
	int m_cache_DEFAULT_GRAIN_GROWTH_UNIT_CLASS;
	int m_cache_DEFAULT_HUNTSMAN_PROFESSION;
	int m_cache_DEFAULT_INVENTOR_CLASS;
	int m_cache_DEFAULT_KNIGHT_PROFESSION_PROMOTION;
	int m_cache_DEFAULT_KNIGHT_PROMOTION;
	int m_cache_DEFAULT_MARAUDER_CLASS;
	int m_cache_DEFAULT_MARUADER_SEA_PROFESSION;
	int m_cache_DEFAULT_NOBLEMAN_CLASS;
	int m_cache_DEFAULT_NOBLE_GROWTH_UNIT_CLASS;
	int m_cache_DEFAULT_PILGRAM_CLASS;
	int m_cache_DEFAULT_POPULATION_UNIT;
	int m_cache_DEFAULT_SHRINE_CLASS;
	int m_cache_DEFAULT_SLAVE_CLASS;
	int m_cache_DEFAULT_SPECIALBUILDING_COURTHOUSE;
	int m_cache_DEFAULT_TEST_DEFINE;
	int m_cache_DEFAULT_TRAINED_PROMOTION;
	int m_cache_DEFAULT_TREASURE_YIELD;
	int m_cache_DEFAULT_UNTRAINED_PROMOTION;
	int m_cache_DEFAULT_VIKING_ERA;
	int m_cache_DEFAULT_YIELD_ARMOR_TYPE;
	int m_cache_DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT;
	int m_cache_DIPLOMACY_VALUE_REMAINDER;
	int m_cache_DOCKS_NEXT_UNITS;
	int m_cache_EDUCATION_BASE_TUITION;
	int m_cache_EDUCATION_THRESHOLD;
	int m_cache_EDUCATION_THRESHOLD_INCREASE;
	int m_cache_ENABLE_ALLIANCE_TRADING;
	int m_cache_ENABLE_DEFENSIVE_PACT_TRADING;
	int m_cache_ENABLE_GOLD_TRADING;
	int m_cache_ENABLE_MAP_TRADING;
	int m_cache_ENABLE_OPEN_BORDERS;
	int m_cache_END_GAME_DISPLAY_WARNING;
	int m_cache_ENEMY_HEAL_RATE;
	int m_cache_ESTABLISH_TRADEPOST_COST;
	int m_cache_EUROPE_EAST;
	int m_cache_EUROPE_MARKET_CORRELATION_PERCENT;
	int m_cache_EVENT_PROBABILITY_ROLL_SIDES;
	int m_cache_EXPERIENCE_FROM_WITHDRAWL;
	int m_cache_EXTRA_YIELD;
	int m_cache_FATHER_COST_EXTRA_TEAM_MEMBER_MODIFIER;
	int m_cache_FATHER_POINT_REAL_TRADE;
	int m_cache_FEATURE_PRODUCTION_YIELD_MAX_DISTANCE;
	int m_cache_FIRST_EVENT_DELAY_TURNS;
	int m_cache_FOUND_MONASTERY_NUMBER;
	int m_cache_FOUND_MOTTE_AND_BAILEY_NUMBER;
	int m_cache_FOUND_OUTPOST_NUMBER;
	int m_cache_FOUND_VILLAGE_NUMBER;
	int m_cache_FREE_CITY_ADJACENT_CULTURE;
	int m_cache_FREE_CITY_CULTURE;
	int m_cache_FREE_PEASANT_CIVIC;
	int m_cache_FRIENDLY_HEAL_RATE;
	int m_cache_GREAT_GENERALS_THRESHOLD;
	int m_cache_GREAT_GENERALS_THRESHOLD_INCREASE;
	int m_cache_GREAT_GENERALS_THRESHOLD_INCREASE_TEAM;
	int m_cache_HIRE_GUARD_COST;
	int m_cache_HIRE_GUARD_PROMOTION;
	int m_cache_IMMIGRATION_MAX_CITY_DISTANCE;
	int m_cache_IMMIGRATION_THRESHOLD;
	int m_cache_IMMIGRATION_THRESHOLD_INCREASE;
	int m_cache_IMMIGRATION_TRAVEL_MOD;
	int m_cache_INDUSTRIAL_VICTORY_SINGLE_YIELD;
	int m_cache_INITIAL_AI_CITY_PRODUCTION;
	int m_cache_INITIAL_CITY_POPULATION;
	int m_cache_INITIAL_CITY_ROUTE_TYPE;
	int m_cache_JUNGLE_FEATURE;
	int m_cache_KING_BUY_UNIT_PRICE_MODIFIER;
	int m_cache_KING_INITIAL_UNIT_INCREASE;
	int m_cache_KING_TRANSPORT_TREASURE_COMISSION;
	int m_cache_KNIGHT_RANSOM_MOD;
	int m_cache_LAKE_PLOT_RAND;
	int m_cache_LAND_IMPROVEMENT;
	int m_cache_LAND_TERRAIN;
	int m_cache_MARAUDERS_DAYSOUT_RANDOM;
	int m_cache_MARAUDERS_TOWER_RANGE;
	int m_cache_MARAUDER_CRUMBS_EVENT;
	int m_cache_MARAUDER_EVENT_DEFAULT_TURNS;
	int m_cache_MAX_CITY_POPULATION_COMMUNE;
	int m_cache_MAX_CITY_POPULATION_VILLAGE;
	int m_cache_MAX_EXPERIENCE_AFTER_UPGRADE;
	int m_cache_MAX_EXPERIENCE_PER_COMBAT;
	int m_cache_MAX_FORTIFY_TURNS;
	int m_cache_MAX_INSULT_MODIFIER;
	int m_cache_MAX_LEVEL_FROM_ANIMAL_XP;
	int m_cache_MAX_MARAUDERS;
	int m_cache_MAX_NUM_LANGUAGES;
	int m_cache_MAX_PLOT_LIST_SIZE;
	int m_cache_MAX_REBEL_COMBAT_MULTIPLER;
	int m_cache_MAX_TRAINED_EXPERIENCE;
	int m_cache_MAX_WITHDRAWAL_PROBABILITY;
	int m_cache_MEDIEVAL_CENSURE;
	int m_cache_MEDIEVAL_TRADE_TECH;
	int m_cache_MINIMAP_RENDER_SIZE;
	int m_cache_MIN_ANIMAL_STARTING_DISTANCE;
	int m_cache_MIN_CITY_YIELD_DECAY;
	int m_cache_MIN_CIV_STARTING_DISTANCE;
	int m_cache_MIN_EXPERIENCE_PER_COMBAT;
	int m_cache_MIN_TIMER_UNIT_DOUBLE_MOVES;
	int m_cache_MIN_WATER_SIZE_FOR_OCEAN;
	int m_cache_MISSIONARY_RATE_EFFECT_ON_SUCCESS;
	int m_cache_MISSIONARY_THRESHOLD;
	int m_cache_MISSIONARY_THRESHOLD_INCREASE;
	int m_cache_MONASTERIES_TO_VILLAGES_RATIO;
	int m_cache_NATIVE_AUTO_SELL_PERCENT;
	int m_cache_NATIVE_GOODS_RAID_PERCENT;
	int m_cache_NATIVE_GROWTH_THRESHOLD_MULTIPLIER;
	int m_cache_NATIVE_HORSES_FOR_SALE;
	int m_cache_NATIVE_HORSES_FOR_SALE_PERCENT;
	int m_cache_NATIVE_TEACH_THRESHOLD_INCREASE;
	int m_cache_NATIVE_TECH;
	int m_cache_NATIVE_TRADING_TRADEPOST;
	int m_cache_NEUTRAL_HEAL_RATE;
	int m_cache_NEW_CITY_BUILDING_VALUE_MODIFIER;
	int m_cache_NEW_HURRY_MODIFIER;
	int m_cache_NOBLE_FIELD_LABOR_PENALTY;
	int m_cache_NO_BAD_GOODIES_EXPERIENCE_PERCENT;
	int m_cache_NO_BAD_GOODIES_GOLD_PERCENT;
	int m_cache_NO_CITY_SHORTAGE_MESSAGES;
	int m_cache_NO_STARTING_PLOTS_IN_JUNGLE;
	int m_cache_OCCUPATION_CULTURE_PERCENT_THRESHOLD;
	int m_cache_OCCUPATION_TURNS_POPULATION_PERCENT;
	int m_cache_OWNERSHIP_SCORE_DURATION_THRESHOLD;
	int m_cache_OWN_TEAM_STARTING_MODIFIER;
	int m_cache_PEACE_TREATY_LENGTH;
	int m_cache_PERCENT_TAX_ON_AUTOSELL_GOODS;
	int m_cache_PILGRAM_OFFER_GOLD;
	int m_cache_PILGRAM_OFFER_GOLD_DISTANCE_MOD;
	int m_cache_PLAYER_ALWAYS_RAZES_CITIES;
	int m_cache_PLOTS_PER_RIVER_EDGE;
	int m_cache_PLOT_VISIBILITY_RANGE;
	int m_cache_PROFESSION_COAL_BURNER;
	int m_cache_PROFESSION_INVENTOR;
	int m_cache_PROLIFIC_INVENTOR_THRESHOLD_INCREASE;
	int m_cache_PROMOTION_BUILD_HOME;
	int m_cache_RANDOM_TURNS_LOST_AT_SEA;
	int m_cache_RAZING_CULTURAL_PERCENT_THRESHOLD;
	int m_cache_REBEL_PERCENT_FOR_REVOLUTION;
	int m_cache_REBEL_SENTIMENT_BELLS_FACTOR;
	int m_cache_REBEL_SENTIMENT_TURN_WEIGHT;
	int m_cache_REVOLUTION_EUROPE_UNIT_SHIP_MODIFIER;
	int m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD;
	int m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD_INCREASE;
	int m_cache_RIVAL_TEAM_STARTING_MODIFIER;
	int m_cache_RIVER_SOURCE_MIN_RIVER_RANGE;
	int m_cache_RIVER_SOURCE_MIN_SEAWATER_RANGE;
	int m_cache_RUINS_IMPROVEMENT;
	int m_cache_SCORE_FATHER_FACTOR;
	int m_cache_SCORE_LAND_FACTOR;
	int m_cache_SCORE_POPULATION_FACTOR;
	int m_cache_SCORE_TAX_FACTOR;
	int m_cache_SETTLEMENT_TREASURE_YIELD;
	int m_cache_SHALLOW_WATER_TERRAIN;
	int m_cache_SLAVE_FOOD_CONSUMPTION_PER_POPULATION;
	int m_cache_STANDARD_CALENDAR;
	int m_cache_STANDARD_CLIMATE;
	int m_cache_STANDARD_ERA;
	int m_cache_STANDARD_GAMESPEED;
	int m_cache_STANDARD_HANDICAP;
	int m_cache_STANDARD_SEALEVEL;
	int m_cache_STANDARD_TURNTIMER;
	int m_cache_STARTING_DISTANCE_PERCENT;
	int m_cache_START_YEAR;
	int m_cache_STEAMWORKS_BUILDING;
	int m_cache_STEAMWORKS_CLASS_TYPE;
	int m_cache_TAX_INCREASE_CHANCE;
	int m_cache_TAX_RATE_MAX_INCREASE;
	int m_cache_TAX_TRADE_THRESHOLD;
	int m_cache_TAX_TRADE_THRESHOLD_ATTITUDE_PERCENT;
	int m_cache_TAX_TRADE_THRESHOLD_TAX_RATE_PERCENT;
	int m_cache_TK_AI_RESEARCH_COST_MOD_PERCENT;
	int m_cache_TK_HUMAN_RESEARCH_COST_MOD_PERCENT;
	int m_cache_TK_IDEAS_CITY_VALUE;
	int m_cache_TK_MAX_FORTS_PER_CITY;
	int m_cache_TK_PIONEER_COAL_FURNACE_BONUS;
	int m_cache_TK_PROLIFIC_INVENTOR_PROGRESS;
	int m_cache_TK_PROLIFIC_INVENTOR_THRESHOLD;
	int m_cache_TK_RESEARCH_PACT_IDEAS_THRESHOLD;
	int m_cache_TK_RESEARCH_TRADE_VALUE;
	int m_cache_TK_STEAMWORKS_MODIFIER;
	int m_cache_TRADE_POINTS_FOR_ROUTE;
	int m_cache_TRADE_ROUTE_SPICE;
	int m_cache_TRADE_STIMULATES_RESEARCH_MIN_VALUE;
	int m_cache_TRADE_STIMULATES_RESEARCH_PERCENT;
	int m_cache_TRADING_POINTS_MOD_PERCENT;
	int m_cache_TREASURE_UNITCLASS;
	int m_cache_TREASURE_UNITS_ONLY_SELECT_COASTAL;
	int m_cache_TURNS_TO_TRAIN;
	int m_cache_UNITARMOR_LEATHER;
	int m_cache_UNITARMOR_MAIL;
	int m_cache_UNITARMOR_PLATE;
	int m_cache_UNITARMOR_SCALE;
	int m_cache_UNITARMOR_SHIELD;
	int m_cache_UNITCLASS_PIONEER;
	int m_cache_UNITTACTIC_PARRY;
	int m_cache_UNITWEAPON_BLUNT;
	int m_cache_UNIT_PRODUCTION_DECAY_PERCENT;
	int m_cache_UNIT_PRODUCTION_DECAY_TIME;
	int m_cache_UNIT_PRODUCTION_PERCENT;
	int m_cache_UNIT_UPGRADE_COST_PER_PRODUCTION;
	int m_cache_UNIT_VISIBILITY_RANGE;
	int m_cache_USE_MEDIEVAL_CALENDER;
	int m_cache_VASSAL_CIVILIZATION;
	int m_cache_VASSAL_LEADER;
	int m_cache_WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT;
	int m_cache_WAR_SUCCESS_ATTACKING;
	int m_cache_WAR_SUCCESS_CITY_CAPTURING;
	int m_cache_WAR_SUCCESS_DEFENDING;
	int m_cache_WAR_SUCCESS_UNIT_CAPTURING;
	int m_cache_WATER_IMPROVEMENT;
	int m_cache_WATER_UNIT_FACING_DIRECTION;
	int m_cache_WEEKS_PER_MONTHS;
	int m_cache_WILD_ANIMAL_ATTACK_WEIGHT;
	int m_cache_WILD_ANIMAL_LAND_BONUS_NATIVE_WEIGHT;
	int m_cache_WILD_ANIMAL_LAND_FEATURE_NATIVE_WEIGHT;
	int m_cache_WILD_ANIMAL_LAND_PATROL_BASE_WEIGHT;
	int m_cache_WILD_ANIMAL_LAND_TERRAIN_NATIVE_WEIGHT;
	int m_cache_WILD_ANIMAL_LAND_UNIT_VARIATION_WEIGHT;
	int m_cache_WILD_ANIMAL_SEA_BONUS_NATIVE_WEIGHT;
	int m_cache_WILD_ANIMAL_SEA_FEATURE_NATIVE_WEIGHT;
	int m_cache_WILD_ANIMAL_SEA_PATROL_BASE_WEIGHT;
	int m_cache_WILD_ANIMAL_SEA_TERRAIN_NATIVE_WEIGHT;
	int m_cache_WILD_ANIMAL_SEA_UNIT_VARIATION_WEIGHT;
	// cache XML - end - Nightinggale

	// EDU remake - start - Nightinggale
public:
	float getEducationCost(int iTeachLevel) const;
protected:
	float m_aiEducationCost[NUM_TEACH_LEVELS];
	// EDU remake - start - Nightinggale
	
	// DLL interface
	CvDLLUtilityIFaceBase* m_pDLL;
};

extern CvGlobals gGlobals;	// for debugging

//
// inlines
//
inline CvGlobals& CvGlobals::getInstance()
{
	return gGlobals;
}


//
// helpers
//
#define GC CvGlobals::getInstance()
#ifndef _USRDLL
#define gDLL GC.getDLLIFaceNonInl()
#else
#define gDLL GC.getDLLIFace()
#endif

#ifndef _USRDLL
#define NUM_DIRECTION_TYPES (GC.getNumDirections())
#define NUM_RESOURCE_LAYERS (GC.getNumResourceLayers())
#define NUM_UNIT_LAYER_OPTION_TYPES (GC.getNumUnitLayerOptionTypes())
#define NUM_GAMEOPTION_TYPES (GC.getNumGameOptions())
#define NUM_MPOPTION_TYPES (GC.getNumMPOptions())
#define NUM_SPECIALOPTION_TYPES (GC.getNumSpecialOptions())
#define NUM_GRAPHICOPTION_TYPES (GC.getNumGraphicOptions())
#define NUM_TRADEABLE_ITEMS (GC.getNumTradeableItems())
#define NUM_BASIC_ITEMS (GC.getNumBasicItems())
#define NUM_TRADEABLE_HEADINGS (GC.getNumTradeableHeadings())
#define NUM_COMMAND_TYPES (GC.getNumCommandInfos())
#define NUM_CONTROL_TYPES (GC.getNumControlInfos())
#define NUM_MISSION_TYPES (GC.getNumMissionInfos())
#define NUM_PLAYEROPTION_TYPES (GC.getNumPlayerOptionInfos())
#define MAX_NUM_SYMBOLS (GC.getMaxNumSymbols())
#define NUM_GRAPHICLEVELS (GC.getNumGraphicLevels())
#endif

//helper functions
template <class T>
void deleteInfoArray(std::vector<T*>& array)
{
	for (std::vector<T*>::iterator it = array.begin(); it != array.end(); ++it)
	{
		SAFE_DELETE(*it);
	}

	array.clear();
}

template <class T>
bool readInfoArray(FDataStreamBase* pStream, std::vector<T*>& array, const char* szClassName)
{
	GC.addToInfosVectors(&array);

	int iSize;
	pStream->Read(&iSize);
	FAssertMsg(iSize==sizeof(T), CvString::format("class size doesn't match cache size - check info read/write functions:%s", szClassName).c_str());
	if (iSize!=sizeof(T))
		return false;
	pStream->Read(&iSize);

	deleteInfoArray(array);

	for (int i = 0; i < iSize; ++i)
	{
		array.push_back(new T);
	}

	int iIndex = 0;
	for (std::vector<T*>::iterator it = array.begin(); it != array.end(); ++it)
	{
		(*it)->read(pStream);
		GC.setInfoTypeFromString((*it)->getType(), iIndex);
		++iIndex;
	}

	return true;
}

template <class T>
bool writeInfoArray(FDataStreamBase* pStream,  std::vector<T*>& array)
{
	int iSize = sizeof(T);
	pStream->Write(iSize);
	pStream->Write(array.size());
	for (std::vector<T*>::iterator it = array.begin(); it != array.end(); ++it)
	{
		(*it)->write(pStream);
	}
	return true;
}

// cache XML - start - Nightinggale
// The assert has an extra check to boost speed for Debug and Assert builds (non-assert builds ignores the line)
// It works like this:
// Assert inverts the code and triggers an assert with this code
// if (!(val != 0 || val == XML))
// Using DeMorgan it turns into
// if (val == 0 && val != XML)
// the compiler will treat this like it was written
// if (val == 0)
// {
//     if (val != XML)
//     {
// This mean the XML file is only read when the cache is the default value (0).
// Check for 0 values are much faster than reading from the XML file (hence the whole reason for this cache)
// This will trigger under the same conditions as if it had been written FAssert(val == XML)
//
// The assert is needed because the cache is not set until an actual game starts and using the cache during initial setup (before/during main menu) will cause havoc.

inline int CvGlobals::getCache_ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES() const
{
	FAssertMsg(m_cache_ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES != 0 || m_cache_ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES == getDefineINT("ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES"), "Cache for ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES is read before it's set");
	return m_cache_ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES;
}

inline int CvGlobals::getCache_ADVANCED_START_CITY_COST() const
{
	FAssertMsg(m_cache_ADVANCED_START_CITY_COST != 0 || m_cache_ADVANCED_START_CITY_COST == getDefineINT("ADVANCED_START_CITY_COST"), "Cache for ADVANCED_START_CITY_COST is read before it's set");
	return m_cache_ADVANCED_START_CITY_COST;
}

inline int CvGlobals::getCache_ADVANCED_START_CITY_COST_INCREASE() const
{
	FAssertMsg(m_cache_ADVANCED_START_CITY_COST_INCREASE != 0 || m_cache_ADVANCED_START_CITY_COST_INCREASE == getDefineINT("ADVANCED_START_CITY_COST_INCREASE"), "Cache for ADVANCED_START_CITY_COST_INCREASE is read before it's set");
	return m_cache_ADVANCED_START_CITY_COST_INCREASE;
}

inline int CvGlobals::getCache_ADVANCED_START_CITY_PLACEMENT_MAX_RANGE() const
{
	FAssertMsg(m_cache_ADVANCED_START_CITY_PLACEMENT_MAX_RANGE != 0 || m_cache_ADVANCED_START_CITY_PLACEMENT_MAX_RANGE == getDefineINT("ADVANCED_START_CITY_PLACEMENT_MAX_RANGE"), "Cache for ADVANCED_START_CITY_PLACEMENT_MAX_RANGE is read before it's set");
	return m_cache_ADVANCED_START_CITY_PLACEMENT_MAX_RANGE;
}

inline int CvGlobals::getCache_ADVANCED_START_CULTURE_COST() const
{
	FAssertMsg(m_cache_ADVANCED_START_CULTURE_COST != 0 || m_cache_ADVANCED_START_CULTURE_COST == getDefineINT("ADVANCED_START_CULTURE_COST"), "Cache for ADVANCED_START_CULTURE_COST is read before it's set");
	return m_cache_ADVANCED_START_CULTURE_COST;
}

inline int CvGlobals::getCache_ADVANCED_START_MAX_UNITS_PER_CITY() const
{
	FAssertMsg(m_cache_ADVANCED_START_MAX_UNITS_PER_CITY != 0 || m_cache_ADVANCED_START_MAX_UNITS_PER_CITY == getDefineINT("ADVANCED_START_MAX_UNITS_PER_CITY"), "Cache for ADVANCED_START_MAX_UNITS_PER_CITY is read before it's set");
	return m_cache_ADVANCED_START_MAX_UNITS_PER_CITY;
}

inline int CvGlobals::getCache_ADVANCED_START_POPULATION_COST() const
{
	FAssertMsg(m_cache_ADVANCED_START_POPULATION_COST != 0 || m_cache_ADVANCED_START_POPULATION_COST == getDefineINT("ADVANCED_START_POPULATION_COST"), "Cache for ADVANCED_START_POPULATION_COST is read before it's set");
	return m_cache_ADVANCED_START_POPULATION_COST;
}

inline int CvGlobals::getCache_ADVANCED_START_POPULATION_COST_INCREASE() const
{
	FAssertMsg(m_cache_ADVANCED_START_POPULATION_COST_INCREASE != 0 || m_cache_ADVANCED_START_POPULATION_COST_INCREASE == getDefineINT("ADVANCED_START_POPULATION_COST_INCREASE"), "Cache for ADVANCED_START_POPULATION_COST_INCREASE is read before it's set");
	return m_cache_ADVANCED_START_POPULATION_COST_INCREASE;
}

inline int CvGlobals::getCache_ADVANCED_START_SIGHT_RANGE() const
{
	FAssertMsg(m_cache_ADVANCED_START_SIGHT_RANGE != 0 || m_cache_ADVANCED_START_SIGHT_RANGE == getDefineINT("ADVANCED_START_SIGHT_RANGE"), "Cache for ADVANCED_START_SIGHT_RANGE is read before it's set");
	return m_cache_ADVANCED_START_SIGHT_RANGE;
}

inline int CvGlobals::getCache_ADVANCED_START_VISIBILITY_COST() const
{
	FAssertMsg(m_cache_ADVANCED_START_VISIBILITY_COST != 0 || m_cache_ADVANCED_START_VISIBILITY_COST == getDefineINT("ADVANCED_START_VISIBILITY_COST"), "Cache for ADVANCED_START_VISIBILITY_COST is read before it's set");
	return m_cache_ADVANCED_START_VISIBILITY_COST;
}

inline int CvGlobals::getCache_ADVANCED_START_VISIBILITY_COST_INCREASE() const
{
	FAssertMsg(m_cache_ADVANCED_START_VISIBILITY_COST_INCREASE != 0 || m_cache_ADVANCED_START_VISIBILITY_COST_INCREASE == getDefineINT("ADVANCED_START_VISIBILITY_COST_INCREASE"), "Cache for ADVANCED_START_VISIBILITY_COST_INCREASE is read before it's set");
	return m_cache_ADVANCED_START_VISIBILITY_COST_INCREASE;
}

inline int CvGlobals::getCache_AI_ADVANCED_TECH_START() const
{
	FAssertMsg(m_cache_AI_ADVANCED_TECH_START != 0 || m_cache_AI_ADVANCED_TECH_START == getDefineINT("AI_ADVANCED_TECH_START"), "Cache for AI_ADVANCED_TECH_START is read before it's set");
	return m_cache_AI_ADVANCED_TECH_START;
}

inline int CvGlobals::getCache_AI_CAN_DISBAND_UNITS() const
{
	FAssertMsg(m_cache_AI_CAN_DISBAND_UNITS != 0 || m_cache_AI_CAN_DISBAND_UNITS == getDefineINT("AI_CAN_DISBAND_UNITS"), "Cache for AI_CAN_DISBAND_UNITS is read before it's set");
	return m_cache_AI_CAN_DISBAND_UNITS;
}

inline int CvGlobals::getCache_AI_CHEAT_AUTO_BUY() const
{
	FAssertMsg(m_cache_AI_CHEAT_AUTO_BUY != 0 || m_cache_AI_CHEAT_AUTO_BUY == getDefineINT("AI_CHEAT_AUTO_BUY"), "Cache for AI_CHEAT_AUTO_BUY is read before it's set");
	return m_cache_AI_CHEAT_AUTO_BUY;
}

inline int CvGlobals::getCache_AI_CHEAT_NEEDED_DEFENDERS() const
{
	FAssertMsg(m_cache_AI_CHEAT_NEEDED_DEFENDERS != 0 || m_cache_AI_CHEAT_NEEDED_DEFENDERS == getDefineINT("AI_CHEAT_NEEDED_DEFENDERS"), "Cache for AI_CHEAT_NEEDED_DEFENDERS is read before it's set");
	return m_cache_AI_CHEAT_NEEDED_DEFENDERS;
}

inline int CvGlobals::getCache_AI_CHEAT_SPICE() const
{
	FAssertMsg(m_cache_AI_CHEAT_SPICE != 0 || m_cache_AI_CHEAT_SPICE == getDefineINT("AI_CHEAT_SPICE"), "Cache for AI_CHEAT_SPICE is read before it's set");
	return m_cache_AI_CHEAT_SPICE;
}

inline int CvGlobals::getCache_AI_CHEAT_SPICE_BUY() const
{
	FAssertMsg(m_cache_AI_CHEAT_SPICE_BUY != 0 || m_cache_AI_CHEAT_SPICE_BUY == getDefineINT("AI_CHEAT_SPICE_BUY"), "Cache for AI_CHEAT_SPICE_BUY is read before it's set");
	return m_cache_AI_CHEAT_SPICE_BUY;
}

inline int CvGlobals::getCache_AI_CHEAT_SPICE_MULTIPLE() const
{
	FAssertMsg(m_cache_AI_CHEAT_SPICE_MULTIPLE != 0 || m_cache_AI_CHEAT_SPICE_MULTIPLE == getDefineINT("AI_CHEAT_SPICE_MULTIPLE"), "Cache for AI_CHEAT_SPICE_MULTIPLE is read before it's set");
	return m_cache_AI_CHEAT_SPICE_MULTIPLE;
}

inline int CvGlobals::getCache_AI_FAVORED_TERRAIN_MOD() const
{
	FAssertMsg(m_cache_AI_FAVORED_TERRAIN_MOD != 0 || m_cache_AI_FAVORED_TERRAIN_MOD == getDefineINT("AI_FAVORED_TERRAIN_MOD"), "Cache for AI_FAVORED_TERRAIN_MOD is read before it's set");
	return m_cache_AI_FAVORED_TERRAIN_MOD;
}

inline int CvGlobals::getCache_AI_HANDICAP_CASTLE() const
{
	FAssertMsg(m_cache_AI_HANDICAP_CASTLE != 0 || m_cache_AI_HANDICAP_CASTLE == getDefineINT("AI_HANDICAP_CASTLE"), "Cache for AI_HANDICAP_CASTLE is read before it's set");
	return m_cache_AI_HANDICAP_CASTLE;
}

inline int CvGlobals::getCache_AI_HANDICAP_MOTTE() const
{
	FAssertMsg(m_cache_AI_HANDICAP_MOTTE != 0 || m_cache_AI_HANDICAP_MOTTE == getDefineINT("AI_HANDICAP_MOTTE"), "Cache for AI_HANDICAP_MOTTE is read before it's set");
	return m_cache_AI_HANDICAP_MOTTE;
}

inline int CvGlobals::getCache_AI_MILITARY_PROFESSION_HACK() const
{
	FAssertMsg(m_cache_AI_MILITARY_PROFESSION_HACK != 0 || m_cache_AI_MILITARY_PROFESSION_HACK == getDefineINT("AI_MILITARY_PROFESSION_HACK"), "Cache for AI_MILITARY_PROFESSION_HACK is read before it's set");
	return m_cache_AI_MILITARY_PROFESSION_HACK;
}

inline int CvGlobals::getCache_AI_WAREHOUSE_MOD() const
{
	FAssertMsg(m_cache_AI_WAREHOUSE_MOD != 0 || m_cache_AI_WAREHOUSE_MOD == getDefineINT("AI_WAREHOUSE_MOD"), "Cache for AI_WAREHOUSE_MOD is read before it's set");
	return m_cache_AI_WAREHOUSE_MOD;
}

inline int CvGlobals::getCache_ALLIANCE_CULTURE_PERCENT_DENIAL() const
{
	FAssertMsg(m_cache_ALLIANCE_CULTURE_PERCENT_DENIAL != 0 || m_cache_ALLIANCE_CULTURE_PERCENT_DENIAL == getDefineINT("ALLIANCE_CULTURE_PERCENT_DENIAL"), "Cache for ALLIANCE_CULTURE_PERCENT_DENIAL is read before it's set");
	return m_cache_ALLIANCE_CULTURE_PERCENT_DENIAL;
}

inline int CvGlobals::getCache_ALLIANCE_PACT_PEACE_DENIAL() const
{
	FAssertMsg(m_cache_ALLIANCE_PACT_PEACE_DENIAL != 0 || m_cache_ALLIANCE_PACT_PEACE_DENIAL == getDefineINT("ALLIANCE_PACT_PEACE_DENIAL"), "Cache for ALLIANCE_PACT_PEACE_DENIAL is read before it's set");
	return m_cache_ALLIANCE_PACT_PEACE_DENIAL;
}

inline int CvGlobals::getCache_ANIMAL_BANDITS_GUARD_GOODY_TIMER() const
{
	FAssertMsg(m_cache_ANIMAL_BANDITS_GUARD_GOODY_TIMER != 0 || m_cache_ANIMAL_BANDITS_GUARD_GOODY_TIMER == getDefineINT("ANIMAL_BANDITS_GUARD_GOODY_TIMER"), "Cache for ANIMAL_BANDITS_GUARD_GOODY_TIMER is read before it's set");
	return m_cache_ANIMAL_BANDITS_GUARD_GOODY_TIMER;
}

inline int CvGlobals::getCache_AUTORESEARCH_ALL() const
{
	FAssertMsg(m_cache_AUTORESEARCH_ALL != 0 || m_cache_AUTORESEARCH_ALL == getDefineINT("AUTORESEARCH_ALL"), "Cache for AUTORESEARCH_ALL is read before it's set");
	return m_cache_AUTORESEARCH_ALL;
}

inline int CvGlobals::getCache_BANQUET_YIELD_AMOUNT() const
{
	FAssertMsg(m_cache_BANQUET_YIELD_AMOUNT != 0 || m_cache_BANQUET_YIELD_AMOUNT == getDefineINT("BANQUET_YIELD_AMOUNT"), "Cache for BANQUET_YIELD_AMOUNT is read before it's set");
	return m_cache_BANQUET_YIELD_AMOUNT;
}

inline int CvGlobals::getCache_BARBARIAN_CIVILIZATION() const
{
	FAssertMsg(m_cache_BARBARIAN_CIVILIZATION != 0 || m_cache_BARBARIAN_CIVILIZATION == getDefineINT("BARBARIAN_CIVILIZATION"), "Cache for BARBARIAN_CIVILIZATION is read before it's set");
	return m_cache_BARBARIAN_CIVILIZATION;
}

inline int CvGlobals::getCache_BARBARIAN_LEADER() const
{
	FAssertMsg(m_cache_BARBARIAN_LEADER != 0 || m_cache_BARBARIAN_LEADER == getDefineINT("BARBARIAN_LEADER"), "Cache for BARBARIAN_LEADER is read before it's set");
	return m_cache_BARBARIAN_LEADER;
}

inline int CvGlobals::getCache_BASE_CITY_GROWTH_THRESHOLD() const
{
	FAssertMsg(m_cache_BASE_CITY_GROWTH_THRESHOLD != 0 || m_cache_BASE_CITY_GROWTH_THRESHOLD == getDefineINT("BASE_CITY_GROWTH_THRESHOLD"), "Cache for BASE_CITY_GROWTH_THRESHOLD is read before it's set");
	return m_cache_BASE_CITY_GROWTH_THRESHOLD;
}

inline int CvGlobals::getCache_BASE_CITY_LUXURY_FOOD_THRESHOLD_MOD() const
{
	FAssertMsg(m_cache_BASE_CITY_LUXURY_FOOD_THRESHOLD_MOD != 0 || m_cache_BASE_CITY_LUXURY_FOOD_THRESHOLD_MOD == getDefineINT("BASE_CITY_LUXURY_FOOD_THRESHOLD_MOD"), "Cache for BASE_CITY_LUXURY_FOOD_THRESHOLD_MOD is read before it's set");
	return m_cache_BASE_CITY_LUXURY_FOOD_THRESHOLD_MOD;
}

inline int CvGlobals::getCache_BASE_OCCUPATION_TURNS() const
{
	FAssertMsg(m_cache_BASE_OCCUPATION_TURNS != 0 || m_cache_BASE_OCCUPATION_TURNS == getDefineINT("BASE_OCCUPATION_TURNS"), "Cache for BASE_OCCUPATION_TURNS is read before it's set");
	return m_cache_BASE_OCCUPATION_TURNS;
}

inline int CvGlobals::getCache_BASE_UNIT_UPGRADE_COST() const
{
	FAssertMsg(m_cache_BASE_UNIT_UPGRADE_COST != 0 || m_cache_BASE_UNIT_UPGRADE_COST == getDefineINT("BASE_UNIT_UPGRADE_COST"), "Cache for BASE_UNIT_UPGRADE_COST is read before it's set");
	return m_cache_BASE_UNIT_UPGRADE_COST;
}

inline int CvGlobals::getCache_BUILDINGCLASS_TRAVEL_TO_FAIR() const
{
	FAssertMsg(m_cache_BUILDINGCLASS_TRAVEL_TO_FAIR != 0 || m_cache_BUILDINGCLASS_TRAVEL_TO_FAIR == getDefineINT("BUILDINGCLASS_TRAVEL_TO_FAIR"), "Cache for BUILDINGCLASS_TRAVEL_TO_FAIR is read before it's set");
	return m_cache_BUILDINGCLASS_TRAVEL_TO_FAIR;
}

inline int CvGlobals::getCache_BUILDING_PRODUCTION_DECAY_PERCENT() const
{
	FAssertMsg(m_cache_BUILDING_PRODUCTION_DECAY_PERCENT != 0 || m_cache_BUILDING_PRODUCTION_DECAY_PERCENT == getDefineINT("BUILDING_PRODUCTION_DECAY_PERCENT"), "Cache for BUILDING_PRODUCTION_DECAY_PERCENT is read before it's set");
	return m_cache_BUILDING_PRODUCTION_DECAY_PERCENT;
}

inline int CvGlobals::getCache_BUILDING_PRODUCTION_DECAY_TIME() const
{
	FAssertMsg(m_cache_BUILDING_PRODUCTION_DECAY_TIME != 0 || m_cache_BUILDING_PRODUCTION_DECAY_TIME == getDefineINT("BUILDING_PRODUCTION_DECAY_TIME"), "Cache for BUILDING_PRODUCTION_DECAY_TIME is read before it's set");
	return m_cache_BUILDING_PRODUCTION_DECAY_TIME;
}

inline int CvGlobals::getCache_BUILDING_PRODUCTION_PERCENT() const
{
	FAssertMsg(m_cache_BUILDING_PRODUCTION_PERCENT != 0 || m_cache_BUILDING_PRODUCTION_PERCENT == getDefineINT("BUILDING_PRODUCTION_PERCENT"), "Cache for BUILDING_PRODUCTION_PERCENT is read before it's set");
	return m_cache_BUILDING_PRODUCTION_PERCENT;
}

inline int CvGlobals::getCache_BUY_PLOT_BASE_CULTURE_COST() const
{
	FAssertMsg(m_cache_BUY_PLOT_BASE_CULTURE_COST != 0 || m_cache_BUY_PLOT_BASE_CULTURE_COST == getDefineINT("BUY_PLOT_BASE_CULTURE_COST"), "Cache for BUY_PLOT_BASE_CULTURE_COST is read before it's set");
	return m_cache_BUY_PLOT_BASE_CULTURE_COST;
}

inline int CvGlobals::getCache_BUY_PLOT_CULTURE_RANGE() const
{
	FAssertMsg(m_cache_BUY_PLOT_CULTURE_RANGE != 0 || m_cache_BUY_PLOT_CULTURE_RANGE == getDefineINT("BUY_PLOT_CULTURE_RANGE"), "Cache for BUY_PLOT_CULTURE_RANGE is read before it's set");
	return m_cache_BUY_PLOT_CULTURE_RANGE;
}

inline int CvGlobals::getCache_BUY_PLOT_MIN_CULTURE() const
{
	FAssertMsg(m_cache_BUY_PLOT_MIN_CULTURE != 0 || m_cache_BUY_PLOT_MIN_CULTURE == getDefineINT("BUY_PLOT_MIN_CULTURE"), "Cache for BUY_PLOT_MIN_CULTURE is read before it's set");
	return m_cache_BUY_PLOT_MIN_CULTURE;
}

inline int CvGlobals::getCache_BUY_PLOT_OWNED_COST_MODIFIER() const
{
	FAssertMsg(m_cache_BUY_PLOT_OWNED_COST_MODIFIER != 0 || m_cache_BUY_PLOT_OWNED_COST_MODIFIER == getDefineINT("BUY_PLOT_OWNED_COST_MODIFIER"), "Cache for BUY_PLOT_OWNED_COST_MODIFIER is read before it's set");
	return m_cache_BUY_PLOT_OWNED_COST_MODIFIER;
}

inline int CvGlobals::getCache_BUY_PLOT_SELLER_INCOME_PERCENT() const
{
	FAssertMsg(m_cache_BUY_PLOT_SELLER_INCOME_PERCENT != 0 || m_cache_BUY_PLOT_SELLER_INCOME_PERCENT == getDefineINT("BUY_PLOT_SELLER_INCOME_PERCENT"), "Cache for BUY_PLOT_SELLER_INCOME_PERCENT is read before it's set");
	return m_cache_BUY_PLOT_SELLER_INCOME_PERCENT;
}

inline int CvGlobals::getCache_CALENDER_YEAR_FIRST_CHANGE_TURN() const
{
	FAssertMsg(m_cache_CALENDER_YEAR_FIRST_CHANGE_TURN != 0 || m_cache_CALENDER_YEAR_FIRST_CHANGE_TURN == getDefineINT("CALENDER_YEAR_FIRST_CHANGE_TURN"), "Cache for CALENDER_YEAR_FIRST_CHANGE_TURN is read before it's set");
	return m_cache_CALENDER_YEAR_FIRST_CHANGE_TURN;
}

inline int CvGlobals::getCache_CALENDER_YEAR_FIRST_MULTIPLIER() const
{
	FAssertMsg(m_cache_CALENDER_YEAR_FIRST_MULTIPLIER != 0 || m_cache_CALENDER_YEAR_FIRST_MULTIPLIER == getDefineINT("CALENDER_YEAR_FIRST_MULTIPLIER"), "Cache for CALENDER_YEAR_FIRST_MULTIPLIER is read before it's set");
	return m_cache_CALENDER_YEAR_FIRST_MULTIPLIER;
}

inline int CvGlobals::getCache_CALENDER_YEAR_SECOND_CHANGE_TURN() const
{
	FAssertMsg(m_cache_CALENDER_YEAR_SECOND_CHANGE_TURN != 0 || m_cache_CALENDER_YEAR_SECOND_CHANGE_TURN == getDefineINT("CALENDER_YEAR_SECOND_CHANGE_TURN"), "Cache for CALENDER_YEAR_SECOND_CHANGE_TURN is read before it's set");
	return m_cache_CALENDER_YEAR_SECOND_CHANGE_TURN;
}

inline int CvGlobals::getCache_CALENDER_YEAR_SECOND_MULTIPLIER() const
{
	FAssertMsg(m_cache_CALENDER_YEAR_SECOND_MULTIPLIER != 0 || m_cache_CALENDER_YEAR_SECOND_MULTIPLIER == getDefineINT("CALENDER_YEAR_SECOND_MULTIPLIER"), "Cache for CALENDER_YEAR_SECOND_MULTIPLIER is read before it's set");
	return m_cache_CALENDER_YEAR_SECOND_MULTIPLIER;
}

inline int CvGlobals::getCache_CALENDER_YEAR_THIRD_MULTIPLIER() const
{
	FAssertMsg(m_cache_CALENDER_YEAR_THIRD_MULTIPLIER != 0 || m_cache_CALENDER_YEAR_THIRD_MULTIPLIER == getDefineINT("CALENDER_YEAR_THIRD_MULTIPLIER"), "Cache for CALENDER_YEAR_THIRD_MULTIPLIER is read before it's set");
	return m_cache_CALENDER_YEAR_THIRD_MULTIPLIER;
}

inline int CvGlobals::getCache_CAPITAL_BUILDINGCLASS() const
{
	FAssertMsg(m_cache_CAPITAL_BUILDINGCLASS != 0 || m_cache_CAPITAL_BUILDINGCLASS == getDefineINT("CAPITAL_BUILDINGCLASS"), "Cache for CAPITAL_BUILDINGCLASS is read before it's set");
	return m_cache_CAPITAL_BUILDINGCLASS;
}

inline int CvGlobals::getCache_CAPTURED_CARGO_RANDOM_AMOUNT() const
{
	FAssertMsg(m_cache_CAPTURED_CARGO_RANDOM_AMOUNT != 0 || m_cache_CAPTURED_CARGO_RANDOM_AMOUNT == getDefineINT("CAPTURED_CARGO_RANDOM_AMOUNT"), "Cache for CAPTURED_CARGO_RANDOM_AMOUNT is read before it's set");
	return m_cache_CAPTURED_CARGO_RANDOM_AMOUNT;
}

inline int CvGlobals::getCache_CAPTURED_LUXURY_FOOD_RANDOM_AMOUNT() const
{
	FAssertMsg(m_cache_CAPTURED_LUXURY_FOOD_RANDOM_AMOUNT != 0 || m_cache_CAPTURED_LUXURY_FOOD_RANDOM_AMOUNT == getDefineINT("CAPTURED_LUXURY_FOOD_RANDOM_AMOUNT"), "Cache for CAPTURED_LUXURY_FOOD_RANDOM_AMOUNT is read before it's set");
	return m_cache_CAPTURED_LUXURY_FOOD_RANDOM_AMOUNT;
}

inline int CvGlobals::getCache_CASTLES_TO_VILLAGES_RATIO() const
{
	FAssertMsg(m_cache_CASTLES_TO_VILLAGES_RATIO != 0 || m_cache_CASTLES_TO_VILLAGES_RATIO == getDefineINT("CASTLES_TO_VILLAGES_RATIO"), "Cache for CASTLES_TO_VILLAGES_RATIO is read before it's set");
	return m_cache_CASTLES_TO_VILLAGES_RATIO;
}

inline int CvGlobals::getCache_CHANCE_TO_CAPTURE_CRIMINALS() const
{
	FAssertMsg(m_cache_CHANCE_TO_CAPTURE_CRIMINALS != 0 || m_cache_CHANCE_TO_CAPTURE_CRIMINALS == getDefineINT("CHANCE_TO_CAPTURE_CRIMINALS"), "Cache for CHANCE_TO_CAPTURE_CRIMINALS is read before it's set");
	return m_cache_CHANCE_TO_CAPTURE_CRIMINALS;
}

inline int CvGlobals::getCache_CHEAT_TRAVEL_ALL() const
{
	FAssertMsg(m_cache_CHEAT_TRAVEL_ALL != 0 || m_cache_CHEAT_TRAVEL_ALL == getDefineINT("CHEAT_TRAVEL_ALL"), "Cache for CHEAT_TRAVEL_ALL is read before it's set");
	return m_cache_CHEAT_TRAVEL_ALL;
}

inline int CvGlobals::getCache_CITY_DEFENSE_DAMAGE_HEAL_RATE() const
{
	FAssertMsg(m_cache_CITY_DEFENSE_DAMAGE_HEAL_RATE != 0 || m_cache_CITY_DEFENSE_DAMAGE_HEAL_RATE == getDefineINT("CITY_DEFENSE_DAMAGE_HEAL_RATE"), "Cache for CITY_DEFENSE_DAMAGE_HEAL_RATE is read before it's set");
	return m_cache_CITY_DEFENSE_DAMAGE_HEAL_RATE;
}

inline int CvGlobals::getCache_CITY_FREE_CULTURE_GROWTH_FACTOR() const
{
	FAssertMsg(m_cache_CITY_FREE_CULTURE_GROWTH_FACTOR != 0 || m_cache_CITY_FREE_CULTURE_GROWTH_FACTOR == getDefineINT("CITY_FREE_CULTURE_GROWTH_FACTOR"), "Cache for CITY_FREE_CULTURE_GROWTH_FACTOR is read before it's set");
	return m_cache_CITY_FREE_CULTURE_GROWTH_FACTOR;
}

inline int CvGlobals::getCache_CITY_GROWTH_MULTIPLIER() const
{
	FAssertMsg(m_cache_CITY_GROWTH_MULTIPLIER != 0 || m_cache_CITY_GROWTH_MULTIPLIER == getDefineINT("CITY_GROWTH_MULTIPLIER"), "Cache for CITY_GROWTH_MULTIPLIER is read before it's set");
	return m_cache_CITY_GROWTH_MULTIPLIER;
}

inline int CvGlobals::getCache_CITY_HEAL_RATE() const
{
	FAssertMsg(m_cache_CITY_HEAL_RATE != 0 || m_cache_CITY_HEAL_RATE == getDefineINT("CITY_HEAL_RATE"), "Cache for CITY_HEAL_RATE is read before it's set");
	return m_cache_CITY_HEAL_RATE;
}

inline int CvGlobals::getCache_CITY_PILGRAM_RANDOM() const
{
	FAssertMsg(m_cache_CITY_PILGRAM_RANDOM != 0 || m_cache_CITY_PILGRAM_RANDOM == getDefineINT("CITY_PILGRAM_RANDOM"), "Cache for CITY_PILGRAM_RANDOM is read before it's set");
	return m_cache_CITY_PILGRAM_RANDOM;
}

inline int CvGlobals::getCache_CITY_SCREEN_FOG_ENABLED() const
{
	FAssertMsg(m_cache_CITY_SCREEN_FOG_ENABLED != 0 || m_cache_CITY_SCREEN_FOG_ENABLED == getDefineINT("CITY_SCREEN_FOG_ENABLED"), "Cache for CITY_SCREEN_FOG_ENABLED is read before it's set");
	return m_cache_CITY_SCREEN_FOG_ENABLED;
}

inline int CvGlobals::getCache_CITY_YIELD_CAPACITY() const
{
	FAssertMsg(m_cache_CITY_YIELD_CAPACITY != 0 || m_cache_CITY_YIELD_CAPACITY == getDefineINT("CITY_YIELD_CAPACITY"), "Cache for CITY_YIELD_CAPACITY is read before it's set");
	return m_cache_CITY_YIELD_CAPACITY;
}

inline int CvGlobals::getCache_CITY_YIELD_DECAY_PERCENT() const
{
	FAssertMsg(m_cache_CITY_YIELD_DECAY_PERCENT != 0 || m_cache_CITY_YIELD_DECAY_PERCENT == getDefineINT("CITY_YIELD_DECAY_PERCENT"), "Cache for CITY_YIELD_DECAY_PERCENT is read before it's set");
	return m_cache_CITY_YIELD_DECAY_PERCENT;
}

inline int CvGlobals::getCache_CIVICOPTION_INVENTIONS() const
{
	FAssertMsg(m_cache_CIVICOPTION_INVENTIONS != 0 || m_cache_CIVICOPTION_INVENTIONS == getDefineINT("CIVICOPTION_INVENTIONS"), "Cache for CIVICOPTION_INVENTIONS is read before it's set");
	return m_cache_CIVICOPTION_INVENTIONS;
}

inline int CvGlobals::getCache_COLONIAL_FORCED_PEACE_TURNS() const
{
	FAssertMsg(m_cache_COLONIAL_FORCED_PEACE_TURNS != 0 || m_cache_COLONIAL_FORCED_PEACE_TURNS == getDefineINT("COLONIAL_FORCED_PEACE_TURNS"), "Cache for COLONIAL_FORCED_PEACE_TURNS is read before it's set");
	return m_cache_COLONIAL_FORCED_PEACE_TURNS;
}

inline int CvGlobals::getCache_COMBAT_DAMAGE() const
{
	FAssertMsg(m_cache_COMBAT_DAMAGE != 0 || m_cache_COMBAT_DAMAGE == getDefineINT("COMBAT_DAMAGE"), "Cache for COMBAT_DAMAGE is read before it's set");
	return m_cache_COMBAT_DAMAGE;
}

inline int CvGlobals::getCache_COMBAT_DIE_SIDES() const
{
	FAssertMsg(m_cache_COMBAT_DIE_SIDES != 0 || m_cache_COMBAT_DIE_SIDES == getDefineINT("COMBAT_DIE_SIDES"), "Cache for COMBAT_DIE_SIDES is read before it's set");
	return m_cache_COMBAT_DIE_SIDES;
}

inline int CvGlobals::getCache_COMBAT_EXPERIENCE_IN_BORDERS_PERCENT() const
{
	FAssertMsg(m_cache_COMBAT_EXPERIENCE_IN_BORDERS_PERCENT != 0 || m_cache_COMBAT_EXPERIENCE_IN_BORDERS_PERCENT == getDefineINT("COMBAT_EXPERIENCE_IN_BORDERS_PERCENT"), "Cache for COMBAT_EXPERIENCE_IN_BORDERS_PERCENT is read before it's set");
	return m_cache_COMBAT_EXPERIENCE_IN_BORDERS_PERCENT;
}

inline int CvGlobals::getCache_CONSUME_EQUIPMENT_ON_FOUND() const
{
	FAssertMsg(m_cache_CONSUME_EQUIPMENT_ON_FOUND != 0 || m_cache_CONSUME_EQUIPMENT_ON_FOUND == getDefineINT("CONSUME_EQUIPMENT_ON_FOUND"), "Cache for CONSUME_EQUIPMENT_ON_FOUND is read before it's set");
	return m_cache_CONSUME_EQUIPMENT_ON_FOUND;
}

inline int CvGlobals::getCache_CONTACT_YIELD_GIFT_ENCOMEIDA_TIMER() const
{
	FAssertMsg(m_cache_CONTACT_YIELD_GIFT_ENCOMEIDA_TIMER != 0 || m_cache_CONTACT_YIELD_GIFT_ENCOMEIDA_TIMER == getDefineINT("CONTACT_YIELD_GIFT_ENCOMEIDA_TIMER"), "Cache for CONTACT_YIELD_GIFT_ENCOMEIDA_TIMER is read before it's set");
	return m_cache_CONTACT_YIELD_GIFT_ENCOMEIDA_TIMER;
}

inline int CvGlobals::getCache_CONTACT_YIELD_GIFT_TECH() const
{
	FAssertMsg(m_cache_CONTACT_YIELD_GIFT_TECH != 0 || m_cache_CONTACT_YIELD_GIFT_TECH == getDefineINT("CONTACT_YIELD_GIFT_TECH"), "Cache for CONTACT_YIELD_GIFT_TECH is read before it's set");
	return m_cache_CONTACT_YIELD_GIFT_TECH;
}

inline int CvGlobals::getCache_CULTURE_YIELD() const
{
	FAssertMsg(m_cache_CULTURE_YIELD != 0 || m_cache_CULTURE_YIELD == getDefineINT("CULTURE_YIELD"), "Cache for CULTURE_YIELD is read before it's set");
	return m_cache_CULTURE_YIELD;
}

inline int CvGlobals::getCache_DEAL_TRADE_RELATIONS_POINTS() const
{
	FAssertMsg(m_cache_DEAL_TRADE_RELATIONS_POINTS != 0 || m_cache_DEAL_TRADE_RELATIONS_POINTS == getDefineINT("DEAL_TRADE_RELATIONS_POINTS"), "Cache for DEAL_TRADE_RELATIONS_POINTS is read before it's set");
	return m_cache_DEAL_TRADE_RELATIONS_POINTS;
}

inline int CvGlobals::getCache_DEEP_WATER_TERRAIN() const
{
	FAssertMsg(m_cache_DEEP_WATER_TERRAIN != 0 || m_cache_DEEP_WATER_TERRAIN == getDefineINT("DEEP_WATER_TERRAIN"), "Cache for DEEP_WATER_TERRAIN is read before it's set");
	return m_cache_DEEP_WATER_TERRAIN;
}

inline int CvGlobals::getCache_DEFAULT_BUILD_CASTLE() const
{
	FAssertMsg(m_cache_DEFAULT_BUILD_CASTLE != 0 || m_cache_DEFAULT_BUILD_CASTLE == getDefineINT("DEFAULT_BUILD_CASTLE"), "Cache for DEFAULT_BUILD_CASTLE is read before it's set");
	return m_cache_DEFAULT_BUILD_CASTLE;
}

inline int CvGlobals::getCache_DEFAULT_BUILD_MOTTE_AND_BAILEY() const
{
	FAssertMsg(m_cache_DEFAULT_BUILD_MOTTE_AND_BAILEY != 0 || m_cache_DEFAULT_BUILD_MOTTE_AND_BAILEY == getDefineINT("DEFAULT_BUILD_MOTTE_AND_BAILEY"), "Cache for DEFAULT_BUILD_MOTTE_AND_BAILEY is read before it's set");
	return m_cache_DEFAULT_BUILD_MOTTE_AND_BAILEY;
}

inline int CvGlobals::getCache_DEFAULT_CENSURETYPE_ANATHEMA() const
{
	FAssertMsg(m_cache_DEFAULT_CENSURETYPE_ANATHEMA != 0 || m_cache_DEFAULT_CENSURETYPE_ANATHEMA == getDefineINT("DEFAULT_CENSURETYPE_ANATHEMA"), "Cache for DEFAULT_CENSURETYPE_ANATHEMA is read before it's set");
	return m_cache_DEFAULT_CENSURETYPE_ANATHEMA;
}

inline int CvGlobals::getCache_DEFAULT_CENSURETYPE_ANATHEMA_COUNT() const
{
	FAssertMsg(m_cache_DEFAULT_CENSURETYPE_ANATHEMA_COUNT != 0 || m_cache_DEFAULT_CENSURETYPE_ANATHEMA_COUNT == getDefineINT("DEFAULT_CENSURETYPE_ANATHEMA_COUNT"), "Cache for DEFAULT_CENSURETYPE_ANATHEMA_COUNT is read before it's set");
	return m_cache_DEFAULT_CENSURETYPE_ANATHEMA_COUNT;
}

inline int CvGlobals::getCache_DEFAULT_CENSURETYPE_EXCOMMUNICATION() const
{
	FAssertMsg(m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION != 0 || m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION == getDefineINT("DEFAULT_CENSURETYPE_EXCOMMUNICATION"), "Cache for DEFAULT_CENSURETYPE_EXCOMMUNICATION is read before it's set");
	return m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION;
}

inline int CvGlobals::getCache_DEFAULT_CENSURETYPE_EXCOMMUNICATION_COUNT() const
{
	FAssertMsg(m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION_COUNT != 0 || m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION_COUNT == getDefineINT("DEFAULT_CENSURETYPE_EXCOMMUNICATION_COUNT"), "Cache for DEFAULT_CENSURETYPE_EXCOMMUNICATION_COUNT is read before it's set");
	return m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION_COUNT;
}

inline int CvGlobals::getCache_DEFAULT_CENSURETYPE_INTERDICT() const
{
	FAssertMsg(m_cache_DEFAULT_CENSURETYPE_INTERDICT != 0 || m_cache_DEFAULT_CENSURETYPE_INTERDICT == getDefineINT("DEFAULT_CENSURETYPE_INTERDICT"), "Cache for DEFAULT_CENSURETYPE_INTERDICT is read before it's set");
	return m_cache_DEFAULT_CENSURETYPE_INTERDICT;
}

inline int CvGlobals::getCache_DEFAULT_CENSURETYPE_INTERDICT_COUNT() const
{
	FAssertMsg(m_cache_DEFAULT_CENSURETYPE_INTERDICT_COUNT != 0 || m_cache_DEFAULT_CENSURETYPE_INTERDICT_COUNT == getDefineINT("DEFAULT_CENSURETYPE_INTERDICT_COUNT"), "Cache for DEFAULT_CENSURETYPE_INTERDICT_COUNT is read before it's set");
	return m_cache_DEFAULT_CENSURETYPE_INTERDICT_COUNT;
}

inline int CvGlobals::getCache_DEFAULT_COMBAT_FOR_TRAINING() const
{
	FAssertMsg(m_cache_DEFAULT_COMBAT_FOR_TRAINING != 0 || m_cache_DEFAULT_COMBAT_FOR_TRAINING == getDefineINT("DEFAULT_COMBAT_FOR_TRAINING"), "Cache for DEFAULT_COMBAT_FOR_TRAINING is read before it's set");
	return m_cache_DEFAULT_COMBAT_FOR_TRAINING;
}

inline int CvGlobals::getCache_DEFAULT_DAWN_POPULATION_UNIT() const
{
	FAssertMsg(m_cache_DEFAULT_DAWN_POPULATION_UNIT != 0 || m_cache_DEFAULT_DAWN_POPULATION_UNIT == getDefineINT("DEFAULT_DAWN_POPULATION_UNIT"), "Cache for DEFAULT_DAWN_POPULATION_UNIT is read before it's set");
	return m_cache_DEFAULT_DAWN_POPULATION_UNIT;
}

inline int CvGlobals::getCache_DEFAULT_FUEDALISM_TECH() const
{
	FAssertMsg(m_cache_DEFAULT_FUEDALISM_TECH != 0 || m_cache_DEFAULT_FUEDALISM_TECH == getDefineINT("DEFAULT_FUEDALISM_TECH"), "Cache for DEFAULT_FUEDALISM_TECH is read before it's set");
	return m_cache_DEFAULT_FUEDALISM_TECH;
}

inline int CvGlobals::getCache_DEFAULT_GRAIN_GROWTH_UNIT_CLASS() const
{
	FAssertMsg(m_cache_DEFAULT_GRAIN_GROWTH_UNIT_CLASS != 0 || m_cache_DEFAULT_GRAIN_GROWTH_UNIT_CLASS == getDefineINT("DEFAULT_GRAIN_GROWTH_UNIT_CLASS"), "Cache for DEFAULT_GRAIN_GROWTH_UNIT_CLASS is read before it's set");
	return m_cache_DEFAULT_GRAIN_GROWTH_UNIT_CLASS;
}

inline int CvGlobals::getCache_DEFAULT_HUNTSMAN_PROFESSION() const
{
	FAssertMsg(m_cache_DEFAULT_HUNTSMAN_PROFESSION != 0 || m_cache_DEFAULT_HUNTSMAN_PROFESSION == getDefineINT("DEFAULT_HUNTSMAN_PROFESSION"), "Cache for DEFAULT_HUNTSMAN_PROFESSION is read before it's set");
	return m_cache_DEFAULT_HUNTSMAN_PROFESSION;
}

inline int CvGlobals::getCache_DEFAULT_INVENTOR_CLASS() const
{
	FAssertMsg(m_cache_DEFAULT_INVENTOR_CLASS != 0 || m_cache_DEFAULT_INVENTOR_CLASS == getDefineINT("DEFAULT_INVENTOR_CLASS"), "Cache for DEFAULT_INVENTOR_CLASS is read before it's set");
	return m_cache_DEFAULT_INVENTOR_CLASS;
}

inline int CvGlobals::getCache_DEFAULT_KNIGHT_PROFESSION_PROMOTION() const
{
	FAssertMsg(m_cache_DEFAULT_KNIGHT_PROFESSION_PROMOTION != 0 || m_cache_DEFAULT_KNIGHT_PROFESSION_PROMOTION == getDefineINT("DEFAULT_KNIGHT_PROFESSION_PROMOTION"), "Cache for DEFAULT_KNIGHT_PROFESSION_PROMOTION is read before it's set");
	return m_cache_DEFAULT_KNIGHT_PROFESSION_PROMOTION;
}

inline int CvGlobals::getCache_DEFAULT_KNIGHT_PROMOTION() const
{
	FAssertMsg(m_cache_DEFAULT_KNIGHT_PROMOTION != 0 || m_cache_DEFAULT_KNIGHT_PROMOTION == getDefineINT("DEFAULT_KNIGHT_PROMOTION"), "Cache for DEFAULT_KNIGHT_PROMOTION is read before it's set");
	return m_cache_DEFAULT_KNIGHT_PROMOTION;
}

inline int CvGlobals::getCache_DEFAULT_MARAUDER_CLASS() const
{
	FAssertMsg(m_cache_DEFAULT_MARAUDER_CLASS != 0 || m_cache_DEFAULT_MARAUDER_CLASS == getDefineINT("DEFAULT_MARAUDER_CLASS"), "Cache for DEFAULT_MARAUDER_CLASS is read before it's set");
	return m_cache_DEFAULT_MARAUDER_CLASS;
}

inline int CvGlobals::getCache_DEFAULT_MARUADER_SEA_PROFESSION() const
{
	FAssertMsg(m_cache_DEFAULT_MARUADER_SEA_PROFESSION != 0 || m_cache_DEFAULT_MARUADER_SEA_PROFESSION == getDefineINT("DEFAULT_MARUADER_SEA_PROFESSION"), "Cache for DEFAULT_MARUADER_SEA_PROFESSION is read before it's set");
	return m_cache_DEFAULT_MARUADER_SEA_PROFESSION;
}

inline int CvGlobals::getCache_DEFAULT_NOBLEMAN_CLASS() const
{
	FAssertMsg(m_cache_DEFAULT_NOBLEMAN_CLASS != 0 || m_cache_DEFAULT_NOBLEMAN_CLASS == getDefineINT("DEFAULT_NOBLEMAN_CLASS"), "Cache for DEFAULT_NOBLEMAN_CLASS is read before it's set");
	return m_cache_DEFAULT_NOBLEMAN_CLASS;
}

inline int CvGlobals::getCache_DEFAULT_NOBLE_GROWTH_UNIT_CLASS() const
{
	FAssertMsg(m_cache_DEFAULT_NOBLE_GROWTH_UNIT_CLASS != 0 || m_cache_DEFAULT_NOBLE_GROWTH_UNIT_CLASS == getDefineINT("DEFAULT_NOBLE_GROWTH_UNIT_CLASS"), "Cache for DEFAULT_NOBLE_GROWTH_UNIT_CLASS is read before it's set");
	return m_cache_DEFAULT_NOBLE_GROWTH_UNIT_CLASS;
}

inline int CvGlobals::getCache_DEFAULT_PILGRAM_CLASS() const
{
	FAssertMsg(m_cache_DEFAULT_PILGRAM_CLASS != 0 || m_cache_DEFAULT_PILGRAM_CLASS == getDefineINT("DEFAULT_PILGRAM_CLASS"), "Cache for DEFAULT_PILGRAM_CLASS is read before it's set");
	return m_cache_DEFAULT_PILGRAM_CLASS;
}

inline int CvGlobals::getCache_DEFAULT_POPULATION_UNIT() const
{
	FAssertMsg(m_cache_DEFAULT_POPULATION_UNIT != 0 || m_cache_DEFAULT_POPULATION_UNIT == getDefineINT("DEFAULT_POPULATION_UNIT"), "Cache for DEFAULT_POPULATION_UNIT is read before it's set");
	return m_cache_DEFAULT_POPULATION_UNIT;
}

inline int CvGlobals::getCache_DEFAULT_SHRINE_CLASS() const
{
	FAssertMsg(m_cache_DEFAULT_SHRINE_CLASS != 0 || m_cache_DEFAULT_SHRINE_CLASS == getDefineINT("DEFAULT_SHRINE_CLASS"), "Cache for DEFAULT_SHRINE_CLASS is read before it's set");
	return m_cache_DEFAULT_SHRINE_CLASS;
}

inline int CvGlobals::getCache_DEFAULT_SLAVE_CLASS() const
{
	FAssertMsg(m_cache_DEFAULT_SLAVE_CLASS != 0 || m_cache_DEFAULT_SLAVE_CLASS == getDefineINT("DEFAULT_SLAVE_CLASS"), "Cache for DEFAULT_SLAVE_CLASS is read before it's set");
	return m_cache_DEFAULT_SLAVE_CLASS;
}

inline int CvGlobals::getCache_DEFAULT_SPECIALBUILDING_COURTHOUSE() const
{
	FAssertMsg(m_cache_DEFAULT_SPECIALBUILDING_COURTHOUSE != 0 || m_cache_DEFAULT_SPECIALBUILDING_COURTHOUSE == getDefineINT("DEFAULT_SPECIALBUILDING_COURTHOUSE"), "Cache for DEFAULT_SPECIALBUILDING_COURTHOUSE is read before it's set");
	return m_cache_DEFAULT_SPECIALBUILDING_COURTHOUSE;
}

inline int CvGlobals::getCache_DEFAULT_TEST_DEFINE() const
{
	FAssertMsg(m_cache_DEFAULT_TEST_DEFINE != 0 || m_cache_DEFAULT_TEST_DEFINE == getDefineINT("DEFAULT_TEST_DEFINE"), "Cache for DEFAULT_TEST_DEFINE is read before it's set");
	return m_cache_DEFAULT_TEST_DEFINE;
}

inline int CvGlobals::getCache_DEFAULT_TRAINED_PROMOTION() const
{
	FAssertMsg(m_cache_DEFAULT_TRAINED_PROMOTION != 0 || m_cache_DEFAULT_TRAINED_PROMOTION == getDefineINT("DEFAULT_TRAINED_PROMOTION"), "Cache for DEFAULT_TRAINED_PROMOTION is read before it's set");
	return m_cache_DEFAULT_TRAINED_PROMOTION;
}

inline int CvGlobals::getCache_DEFAULT_TREASURE_YIELD() const
{
	FAssertMsg(m_cache_DEFAULT_TREASURE_YIELD != 0 || m_cache_DEFAULT_TREASURE_YIELD == getDefineINT("DEFAULT_TREASURE_YIELD"), "Cache for DEFAULT_TREASURE_YIELD is read before it's set");
	return m_cache_DEFAULT_TREASURE_YIELD;
}

inline int CvGlobals::getCache_DEFAULT_UNTRAINED_PROMOTION() const
{
	FAssertMsg(m_cache_DEFAULT_UNTRAINED_PROMOTION != 0 || m_cache_DEFAULT_UNTRAINED_PROMOTION == getDefineINT("DEFAULT_UNTRAINED_PROMOTION"), "Cache for DEFAULT_UNTRAINED_PROMOTION is read before it's set");
	return m_cache_DEFAULT_UNTRAINED_PROMOTION;
}

inline int CvGlobals::getCache_DEFAULT_VIKING_ERA() const
{
	FAssertMsg(m_cache_DEFAULT_VIKING_ERA != 0 || m_cache_DEFAULT_VIKING_ERA == getDefineINT("DEFAULT_VIKING_ERA"), "Cache for DEFAULT_VIKING_ERA is read before it's set");
	return m_cache_DEFAULT_VIKING_ERA;
}

inline int CvGlobals::getCache_DEFAULT_YIELD_ARMOR_TYPE() const
{
	FAssertMsg(m_cache_DEFAULT_YIELD_ARMOR_TYPE != 0 || m_cache_DEFAULT_YIELD_ARMOR_TYPE == getDefineINT("DEFAULT_YIELD_ARMOR_TYPE"), "Cache for DEFAULT_YIELD_ARMOR_TYPE is read before it's set");
	return m_cache_DEFAULT_YIELD_ARMOR_TYPE;
}

inline int CvGlobals::getCache_DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT() const
{
	FAssertMsg(m_cache_DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT != 0 || m_cache_DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT == getDefineINT("DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT"), "Cache for DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT is read before it's set");
	return m_cache_DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT;
}

inline int CvGlobals::getCache_DIPLOMACY_VALUE_REMAINDER() const
{
	FAssertMsg(m_cache_DIPLOMACY_VALUE_REMAINDER != 0 || m_cache_DIPLOMACY_VALUE_REMAINDER == getDefineINT("DIPLOMACY_VALUE_REMAINDER"), "Cache for DIPLOMACY_VALUE_REMAINDER is read before it's set");
	return m_cache_DIPLOMACY_VALUE_REMAINDER;
}

inline int CvGlobals::getCache_DOCKS_NEXT_UNITS() const
{
	FAssertMsg(m_cache_DOCKS_NEXT_UNITS != 0 || m_cache_DOCKS_NEXT_UNITS == getDefineINT("DOCKS_NEXT_UNITS"), "Cache for DOCKS_NEXT_UNITS is read before it's set");
	return m_cache_DOCKS_NEXT_UNITS;
}

inline int CvGlobals::getCache_EDUCATION_BASE_TUITION() const
{
	FAssertMsg(m_cache_EDUCATION_BASE_TUITION != 0 || m_cache_EDUCATION_BASE_TUITION == getDefineINT("EDUCATION_BASE_TUITION"), "Cache for EDUCATION_BASE_TUITION is read before it's set");
	return m_cache_EDUCATION_BASE_TUITION;
}

inline int CvGlobals::getCache_EDUCATION_THRESHOLD() const
{
	FAssertMsg(m_cache_EDUCATION_THRESHOLD != 0 || m_cache_EDUCATION_THRESHOLD == getDefineINT("EDUCATION_THRESHOLD"), "Cache for EDUCATION_THRESHOLD is read before it's set");
	return m_cache_EDUCATION_THRESHOLD;
}

inline int CvGlobals::getCache_EDUCATION_THRESHOLD_INCREASE() const
{
	FAssertMsg(m_cache_EDUCATION_THRESHOLD_INCREASE != 0 || m_cache_EDUCATION_THRESHOLD_INCREASE == getDefineINT("EDUCATION_THRESHOLD_INCREASE"), "Cache for EDUCATION_THRESHOLD_INCREASE is read before it's set");
	return m_cache_EDUCATION_THRESHOLD_INCREASE;
}

inline int CvGlobals::getCache_ENABLE_ALLIANCE_TRADING() const
{
	FAssertMsg(m_cache_ENABLE_ALLIANCE_TRADING != 0 || m_cache_ENABLE_ALLIANCE_TRADING == getDefineINT("ENABLE_ALLIANCE_TRADING"), "Cache for ENABLE_ALLIANCE_TRADING is read before it's set");
	return m_cache_ENABLE_ALLIANCE_TRADING;
}

inline int CvGlobals::getCache_ENABLE_DEFENSIVE_PACT_TRADING() const
{
	FAssertMsg(m_cache_ENABLE_DEFENSIVE_PACT_TRADING != 0 || m_cache_ENABLE_DEFENSIVE_PACT_TRADING == getDefineINT("ENABLE_DEFENSIVE_PACT_TRADING"), "Cache for ENABLE_DEFENSIVE_PACT_TRADING is read before it's set");
	return m_cache_ENABLE_DEFENSIVE_PACT_TRADING;
}

inline int CvGlobals::getCache_ENABLE_GOLD_TRADING() const
{
	FAssertMsg(m_cache_ENABLE_GOLD_TRADING != 0 || m_cache_ENABLE_GOLD_TRADING == getDefineINT("ENABLE_GOLD_TRADING"), "Cache for ENABLE_GOLD_TRADING is read before it's set");
	return m_cache_ENABLE_GOLD_TRADING;
}

inline int CvGlobals::getCache_ENABLE_MAP_TRADING() const
{
	FAssertMsg(m_cache_ENABLE_MAP_TRADING != 0 || m_cache_ENABLE_MAP_TRADING == getDefineINT("ENABLE_MAP_TRADING"), "Cache for ENABLE_MAP_TRADING is read before it's set");
	return m_cache_ENABLE_MAP_TRADING;
}

inline int CvGlobals::getCache_ENABLE_OPEN_BORDERS() const
{
	FAssertMsg(m_cache_ENABLE_OPEN_BORDERS != 0 || m_cache_ENABLE_OPEN_BORDERS == getDefineINT("ENABLE_OPEN_BORDERS"), "Cache for ENABLE_OPEN_BORDERS is read before it's set");
	return m_cache_ENABLE_OPEN_BORDERS;
}

inline int CvGlobals::getCache_END_GAME_DISPLAY_WARNING() const
{
	FAssertMsg(m_cache_END_GAME_DISPLAY_WARNING != 0 || m_cache_END_GAME_DISPLAY_WARNING == getDefineINT("END_GAME_DISPLAY_WARNING"), "Cache for END_GAME_DISPLAY_WARNING is read before it's set");
	return m_cache_END_GAME_DISPLAY_WARNING;
}

inline int CvGlobals::getCache_ENEMY_HEAL_RATE() const
{
	FAssertMsg(m_cache_ENEMY_HEAL_RATE != 0 || m_cache_ENEMY_HEAL_RATE == getDefineINT("ENEMY_HEAL_RATE"), "Cache for ENEMY_HEAL_RATE is read before it's set");
	return m_cache_ENEMY_HEAL_RATE;
}

inline int CvGlobals::getCache_ESTABLISH_TRADEPOST_COST() const
{
	FAssertMsg(m_cache_ESTABLISH_TRADEPOST_COST != 0 || m_cache_ESTABLISH_TRADEPOST_COST == getDefineINT("ESTABLISH_TRADEPOST_COST"), "Cache for ESTABLISH_TRADEPOST_COST is read before it's set");
	return m_cache_ESTABLISH_TRADEPOST_COST;
}

inline int CvGlobals::getCache_EUROPE_EAST() const
{
	FAssertMsg(m_cache_EUROPE_EAST != 0 || m_cache_EUROPE_EAST == getDefineINT("EUROPE_EAST"), "Cache for EUROPE_EAST is read before it's set");
	return m_cache_EUROPE_EAST;
}

inline int CvGlobals::getCache_EUROPE_MARKET_CORRELATION_PERCENT() const
{
	FAssertMsg(m_cache_EUROPE_MARKET_CORRELATION_PERCENT != 0 || m_cache_EUROPE_MARKET_CORRELATION_PERCENT == getDefineINT("EUROPE_MARKET_CORRELATION_PERCENT"), "Cache for EUROPE_MARKET_CORRELATION_PERCENT is read before it's set");
	return m_cache_EUROPE_MARKET_CORRELATION_PERCENT;
}

inline int CvGlobals::getCache_EVENT_PROBABILITY_ROLL_SIDES() const
{
	FAssertMsg(m_cache_EVENT_PROBABILITY_ROLL_SIDES != 0 || m_cache_EVENT_PROBABILITY_ROLL_SIDES == getDefineINT("EVENT_PROBABILITY_ROLL_SIDES"), "Cache for EVENT_PROBABILITY_ROLL_SIDES is read before it's set");
	return m_cache_EVENT_PROBABILITY_ROLL_SIDES;
}

inline int CvGlobals::getCache_EXPERIENCE_FROM_WITHDRAWL() const
{
	FAssertMsg(m_cache_EXPERIENCE_FROM_WITHDRAWL != 0 || m_cache_EXPERIENCE_FROM_WITHDRAWL == getDefineINT("EXPERIENCE_FROM_WITHDRAWL"), "Cache for EXPERIENCE_FROM_WITHDRAWL is read before it's set");
	return m_cache_EXPERIENCE_FROM_WITHDRAWL;
}

inline int CvGlobals::getCache_EXTRA_YIELD() const
{
	FAssertMsg(m_cache_EXTRA_YIELD != 0 || m_cache_EXTRA_YIELD == getDefineINT("EXTRA_YIELD"), "Cache for EXTRA_YIELD is read before it's set");
	return m_cache_EXTRA_YIELD;
}

inline int CvGlobals::getCache_FATHER_COST_EXTRA_TEAM_MEMBER_MODIFIER() const
{
	FAssertMsg(m_cache_FATHER_COST_EXTRA_TEAM_MEMBER_MODIFIER != 0 || m_cache_FATHER_COST_EXTRA_TEAM_MEMBER_MODIFIER == getDefineINT("FATHER_COST_EXTRA_TEAM_MEMBER_MODIFIER"), "Cache for FATHER_COST_EXTRA_TEAM_MEMBER_MODIFIER is read before it's set");
	return m_cache_FATHER_COST_EXTRA_TEAM_MEMBER_MODIFIER;
}

inline int CvGlobals::getCache_FATHER_POINT_REAL_TRADE() const
{
	FAssertMsg(m_cache_FATHER_POINT_REAL_TRADE != 0 || m_cache_FATHER_POINT_REAL_TRADE == getDefineINT("FATHER_POINT_REAL_TRADE"), "Cache for FATHER_POINT_REAL_TRADE is read before it's set");
	return m_cache_FATHER_POINT_REAL_TRADE;
}

inline int CvGlobals::getCache_FEATURE_PRODUCTION_YIELD_MAX_DISTANCE() const
{
	FAssertMsg(m_cache_FEATURE_PRODUCTION_YIELD_MAX_DISTANCE != 0 || m_cache_FEATURE_PRODUCTION_YIELD_MAX_DISTANCE == getDefineINT("FEATURE_PRODUCTION_YIELD_MAX_DISTANCE"), "Cache for FEATURE_PRODUCTION_YIELD_MAX_DISTANCE is read before it's set");
	return m_cache_FEATURE_PRODUCTION_YIELD_MAX_DISTANCE;
}

inline int CvGlobals::getCache_FIRST_EVENT_DELAY_TURNS() const
{
	FAssertMsg(m_cache_FIRST_EVENT_DELAY_TURNS != 0 || m_cache_FIRST_EVENT_DELAY_TURNS == getDefineINT("FIRST_EVENT_DELAY_TURNS"), "Cache for FIRST_EVENT_DELAY_TURNS is read before it's set");
	return m_cache_FIRST_EVENT_DELAY_TURNS;
}

inline int CvGlobals::getCache_FOUND_MONASTERY_NUMBER() const
{
	FAssertMsg(m_cache_FOUND_MONASTERY_NUMBER != 0 || m_cache_FOUND_MONASTERY_NUMBER == getDefineINT("FOUND_MONASTERY_NUMBER"), "Cache for FOUND_MONASTERY_NUMBER is read before it's set");
	return m_cache_FOUND_MONASTERY_NUMBER;
}

inline int CvGlobals::getCache_FOUND_MOTTE_AND_BAILEY_NUMBER() const
{
	FAssertMsg(m_cache_FOUND_MOTTE_AND_BAILEY_NUMBER != 0 || m_cache_FOUND_MOTTE_AND_BAILEY_NUMBER == getDefineINT("FOUND_MOTTE_AND_BAILEY_NUMBER"), "Cache for FOUND_MOTTE_AND_BAILEY_NUMBER is read before it's set");
	return m_cache_FOUND_MOTTE_AND_BAILEY_NUMBER;
}

inline int CvGlobals::getCache_FOUND_OUTPOST_NUMBER() const
{
	FAssertMsg(m_cache_FOUND_OUTPOST_NUMBER != 0 || m_cache_FOUND_OUTPOST_NUMBER == getDefineINT("FOUND_OUTPOST_NUMBER"), "Cache for FOUND_OUTPOST_NUMBER is read before it's set");
	return m_cache_FOUND_OUTPOST_NUMBER;
}

inline int CvGlobals::getCache_FOUND_VILLAGE_NUMBER() const
{
	FAssertMsg(m_cache_FOUND_VILLAGE_NUMBER != 0 || m_cache_FOUND_VILLAGE_NUMBER == getDefineINT("FOUND_VILLAGE_NUMBER"), "Cache for FOUND_VILLAGE_NUMBER is read before it's set");
	return m_cache_FOUND_VILLAGE_NUMBER;
}

inline int CvGlobals::getCache_FREE_CITY_ADJACENT_CULTURE() const
{
	FAssertMsg(m_cache_FREE_CITY_ADJACENT_CULTURE != 0 || m_cache_FREE_CITY_ADJACENT_CULTURE == getDefineINT("FREE_CITY_ADJACENT_CULTURE"), "Cache for FREE_CITY_ADJACENT_CULTURE is read before it's set");
	return m_cache_FREE_CITY_ADJACENT_CULTURE;
}

inline int CvGlobals::getCache_FREE_CITY_CULTURE() const
{
	FAssertMsg(m_cache_FREE_CITY_CULTURE != 0 || m_cache_FREE_CITY_CULTURE == getDefineINT("FREE_CITY_CULTURE"), "Cache for FREE_CITY_CULTURE is read before it's set");
	return m_cache_FREE_CITY_CULTURE;
}

inline int CvGlobals::getCache_FREE_PEASANT_CIVIC() const
{
	FAssertMsg(m_cache_FREE_PEASANT_CIVIC != 0 || m_cache_FREE_PEASANT_CIVIC == getDefineINT("FREE_PEASANT_CIVIC"), "Cache for FREE_PEASANT_CIVIC is read before it's set");
	return m_cache_FREE_PEASANT_CIVIC;
}

inline int CvGlobals::getCache_FRIENDLY_HEAL_RATE() const
{
	FAssertMsg(m_cache_FRIENDLY_HEAL_RATE != 0 || m_cache_FRIENDLY_HEAL_RATE == getDefineINT("FRIENDLY_HEAL_RATE"), "Cache for FRIENDLY_HEAL_RATE is read before it's set");
	return m_cache_FRIENDLY_HEAL_RATE;
}

inline int CvGlobals::getCache_GREAT_GENERALS_THRESHOLD() const
{
	FAssertMsg(m_cache_GREAT_GENERALS_THRESHOLD != 0 || m_cache_GREAT_GENERALS_THRESHOLD == getDefineINT("GREAT_GENERALS_THRESHOLD"), "Cache for GREAT_GENERALS_THRESHOLD is read before it's set");
	return m_cache_GREAT_GENERALS_THRESHOLD;
}

inline int CvGlobals::getCache_GREAT_GENERALS_THRESHOLD_INCREASE() const
{
	FAssertMsg(m_cache_GREAT_GENERALS_THRESHOLD_INCREASE != 0 || m_cache_GREAT_GENERALS_THRESHOLD_INCREASE == getDefineINT("GREAT_GENERALS_THRESHOLD_INCREASE"), "Cache for GREAT_GENERALS_THRESHOLD_INCREASE is read before it's set");
	return m_cache_GREAT_GENERALS_THRESHOLD_INCREASE;
}

inline int CvGlobals::getCache_GREAT_GENERALS_THRESHOLD_INCREASE_TEAM() const
{
	FAssertMsg(m_cache_GREAT_GENERALS_THRESHOLD_INCREASE_TEAM != 0 || m_cache_GREAT_GENERALS_THRESHOLD_INCREASE_TEAM == getDefineINT("GREAT_GENERALS_THRESHOLD_INCREASE_TEAM"), "Cache for GREAT_GENERALS_THRESHOLD_INCREASE_TEAM is read before it's set");
	return m_cache_GREAT_GENERALS_THRESHOLD_INCREASE_TEAM;
}

inline int CvGlobals::getCache_HIRE_GUARD_COST() const
{
	FAssertMsg(m_cache_HIRE_GUARD_COST != 0 || m_cache_HIRE_GUARD_COST == getDefineINT("HIRE_GUARD_COST"), "Cache for HIRE_GUARD_COST is read before it's set");
	return m_cache_HIRE_GUARD_COST;
}

inline int CvGlobals::getCache_HIRE_GUARD_PROMOTION() const
{
	FAssertMsg(m_cache_HIRE_GUARD_PROMOTION != 0 || m_cache_HIRE_GUARD_PROMOTION == getDefineINT("HIRE_GUARD_PROMOTION"), "Cache for HIRE_GUARD_PROMOTION is read before it's set");
	return m_cache_HIRE_GUARD_PROMOTION;
}

inline int CvGlobals::getCache_IMMIGRATION_MAX_CITY_DISTANCE() const
{
	FAssertMsg(m_cache_IMMIGRATION_MAX_CITY_DISTANCE != 0 || m_cache_IMMIGRATION_MAX_CITY_DISTANCE == getDefineINT("IMMIGRATION_MAX_CITY_DISTANCE"), "Cache for IMMIGRATION_MAX_CITY_DISTANCE is read before it's set");
	return m_cache_IMMIGRATION_MAX_CITY_DISTANCE;
}

inline int CvGlobals::getCache_IMMIGRATION_THRESHOLD() const
{
	FAssertMsg(m_cache_IMMIGRATION_THRESHOLD != 0 || m_cache_IMMIGRATION_THRESHOLD == getDefineINT("IMMIGRATION_THRESHOLD"), "Cache for IMMIGRATION_THRESHOLD is read before it's set");
	return m_cache_IMMIGRATION_THRESHOLD;
}

inline int CvGlobals::getCache_IMMIGRATION_THRESHOLD_INCREASE() const
{
	FAssertMsg(m_cache_IMMIGRATION_THRESHOLD_INCREASE != 0 || m_cache_IMMIGRATION_THRESHOLD_INCREASE == getDefineINT("IMMIGRATION_THRESHOLD_INCREASE"), "Cache for IMMIGRATION_THRESHOLD_INCREASE is read before it's set");
	return m_cache_IMMIGRATION_THRESHOLD_INCREASE;
}

inline int CvGlobals::getCache_IMMIGRATION_TRAVEL_MOD() const
{
	FAssertMsg(m_cache_IMMIGRATION_TRAVEL_MOD != 0 || m_cache_IMMIGRATION_TRAVEL_MOD == getDefineINT("IMMIGRATION_TRAVEL_MOD"), "Cache for IMMIGRATION_TRAVEL_MOD is read before it's set");
	return m_cache_IMMIGRATION_TRAVEL_MOD;
}

inline int CvGlobals::getCache_INDUSTRIAL_VICTORY_SINGLE_YIELD() const
{
	FAssertMsg(m_cache_INDUSTRIAL_VICTORY_SINGLE_YIELD != 0 || m_cache_INDUSTRIAL_VICTORY_SINGLE_YIELD == getDefineINT("INDUSTRIAL_VICTORY_SINGLE_YIELD"), "Cache for INDUSTRIAL_VICTORY_SINGLE_YIELD is read before it's set");
	return m_cache_INDUSTRIAL_VICTORY_SINGLE_YIELD;
}

inline int CvGlobals::getCache_INITIAL_AI_CITY_PRODUCTION() const
{
	FAssertMsg(m_cache_INITIAL_AI_CITY_PRODUCTION != 0 || m_cache_INITIAL_AI_CITY_PRODUCTION == getDefineINT("INITIAL_AI_CITY_PRODUCTION"), "Cache for INITIAL_AI_CITY_PRODUCTION is read before it's set");
	return m_cache_INITIAL_AI_CITY_PRODUCTION;
}

inline int CvGlobals::getCache_INITIAL_CITY_POPULATION() const
{
	FAssertMsg(m_cache_INITIAL_CITY_POPULATION != 0 || m_cache_INITIAL_CITY_POPULATION == getDefineINT("INITIAL_CITY_POPULATION"), "Cache for INITIAL_CITY_POPULATION is read before it's set");
	return m_cache_INITIAL_CITY_POPULATION;
}

inline int CvGlobals::getCache_INITIAL_CITY_ROUTE_TYPE() const
{
	FAssertMsg(m_cache_INITIAL_CITY_ROUTE_TYPE != 0 || m_cache_INITIAL_CITY_ROUTE_TYPE == getDefineINT("INITIAL_CITY_ROUTE_TYPE"), "Cache for INITIAL_CITY_ROUTE_TYPE is read before it's set");
	return m_cache_INITIAL_CITY_ROUTE_TYPE;
}

inline int CvGlobals::getCache_JUNGLE_FEATURE() const
{
	FAssertMsg(m_cache_JUNGLE_FEATURE != 0 || m_cache_JUNGLE_FEATURE == getDefineINT("JUNGLE_FEATURE"), "Cache for JUNGLE_FEATURE is read before it's set");
	return m_cache_JUNGLE_FEATURE;
}

inline int CvGlobals::getCache_KING_BUY_UNIT_PRICE_MODIFIER() const
{
	FAssertMsg(m_cache_KING_BUY_UNIT_PRICE_MODIFIER != 0 || m_cache_KING_BUY_UNIT_PRICE_MODIFIER == getDefineINT("KING_BUY_UNIT_PRICE_MODIFIER"), "Cache for KING_BUY_UNIT_PRICE_MODIFIER is read before it's set");
	return m_cache_KING_BUY_UNIT_PRICE_MODIFIER;
}

inline int CvGlobals::getCache_KING_INITIAL_UNIT_INCREASE() const
{
	FAssertMsg(m_cache_KING_INITIAL_UNIT_INCREASE != 0 || m_cache_KING_INITIAL_UNIT_INCREASE == getDefineINT("KING_INITIAL_UNIT_INCREASE"), "Cache for KING_INITIAL_UNIT_INCREASE is read before it's set");
	return m_cache_KING_INITIAL_UNIT_INCREASE;
}

inline int CvGlobals::getCache_KING_TRANSPORT_TREASURE_COMISSION() const
{
	FAssertMsg(m_cache_KING_TRANSPORT_TREASURE_COMISSION != 0 || m_cache_KING_TRANSPORT_TREASURE_COMISSION == getDefineINT("KING_TRANSPORT_TREASURE_COMISSION"), "Cache for KING_TRANSPORT_TREASURE_COMISSION is read before it's set");
	return m_cache_KING_TRANSPORT_TREASURE_COMISSION;
}

inline int CvGlobals::getCache_KNIGHT_RANSOM_MOD() const
{
	FAssertMsg(m_cache_KNIGHT_RANSOM_MOD != 0 || m_cache_KNIGHT_RANSOM_MOD == getDefineINT("KNIGHT_RANSOM_MOD"), "Cache for KNIGHT_RANSOM_MOD is read before it's set");
	return m_cache_KNIGHT_RANSOM_MOD;
}

inline int CvGlobals::getCache_LAKE_PLOT_RAND() const
{
	FAssertMsg(m_cache_LAKE_PLOT_RAND != 0 || m_cache_LAKE_PLOT_RAND == getDefineINT("LAKE_PLOT_RAND"), "Cache for LAKE_PLOT_RAND is read before it's set");
	return m_cache_LAKE_PLOT_RAND;
}

inline int CvGlobals::getCache_LAND_IMPROVEMENT() const
{
	FAssertMsg(m_cache_LAND_IMPROVEMENT != 0 || m_cache_LAND_IMPROVEMENT == getDefineINT("LAND_IMPROVEMENT"), "Cache for LAND_IMPROVEMENT is read before it's set");
	return m_cache_LAND_IMPROVEMENT;
}

inline int CvGlobals::getCache_LAND_TERRAIN() const
{
	FAssertMsg(m_cache_LAND_TERRAIN != 0 || m_cache_LAND_TERRAIN == getDefineINT("LAND_TERRAIN"), "Cache for LAND_TERRAIN is read before it's set");
	return m_cache_LAND_TERRAIN;
}

inline int CvGlobals::getCache_MARAUDERS_DAYSOUT_RANDOM() const
{
	FAssertMsg(m_cache_MARAUDERS_DAYSOUT_RANDOM != 0 || m_cache_MARAUDERS_DAYSOUT_RANDOM == getDefineINT("MARAUDERS_DAYSOUT_RANDOM"), "Cache for MARAUDERS_DAYSOUT_RANDOM is read before it's set");
	return m_cache_MARAUDERS_DAYSOUT_RANDOM;
}

inline int CvGlobals::getCache_MARAUDERS_TOWER_RANGE() const
{
	FAssertMsg(m_cache_MARAUDERS_TOWER_RANGE != 0 || m_cache_MARAUDERS_TOWER_RANGE == getDefineINT("MARAUDERS_TOWER_RANGE"), "Cache for MARAUDERS_TOWER_RANGE is read before it's set");
	return m_cache_MARAUDERS_TOWER_RANGE;
}

inline int CvGlobals::getCache_MARAUDER_CRUMBS_EVENT() const
{
	FAssertMsg(m_cache_MARAUDER_CRUMBS_EVENT != 0 || m_cache_MARAUDER_CRUMBS_EVENT == getDefineINT("MARAUDER_CRUMBS_EVENT"), "Cache for MARAUDER_CRUMBS_EVENT is read before it's set");
	return m_cache_MARAUDER_CRUMBS_EVENT;
}

inline int CvGlobals::getCache_MARAUDER_EVENT_DEFAULT_TURNS() const
{
	FAssertMsg(m_cache_MARAUDER_EVENT_DEFAULT_TURNS != 0 || m_cache_MARAUDER_EVENT_DEFAULT_TURNS == getDefineINT("MARAUDER_EVENT_DEFAULT_TURNS"), "Cache for MARAUDER_EVENT_DEFAULT_TURNS is read before it's set");
	return m_cache_MARAUDER_EVENT_DEFAULT_TURNS;
}

inline int CvGlobals::getCache_MAX_CITY_POPULATION_COMMUNE() const
{
	FAssertMsg(m_cache_MAX_CITY_POPULATION_COMMUNE != 0 || m_cache_MAX_CITY_POPULATION_COMMUNE == getDefineINT("MAX_CITY_POPULATION_COMMUNE"), "Cache for MAX_CITY_POPULATION_COMMUNE is read before it's set");
	return m_cache_MAX_CITY_POPULATION_COMMUNE;
}

inline int CvGlobals::getCache_MAX_CITY_POPULATION_VILLAGE() const
{
	FAssertMsg(m_cache_MAX_CITY_POPULATION_VILLAGE != 0 || m_cache_MAX_CITY_POPULATION_VILLAGE == getDefineINT("MAX_CITY_POPULATION_VILLAGE"), "Cache for MAX_CITY_POPULATION_VILLAGE is read before it's set");
	return m_cache_MAX_CITY_POPULATION_VILLAGE;
}

inline int CvGlobals::getCache_MAX_EXPERIENCE_AFTER_UPGRADE() const
{
	FAssertMsg(m_cache_MAX_EXPERIENCE_AFTER_UPGRADE != 0 || m_cache_MAX_EXPERIENCE_AFTER_UPGRADE == getDefineINT("MAX_EXPERIENCE_AFTER_UPGRADE"), "Cache for MAX_EXPERIENCE_AFTER_UPGRADE is read before it's set");
	return m_cache_MAX_EXPERIENCE_AFTER_UPGRADE;
}

inline int CvGlobals::getCache_MAX_EXPERIENCE_PER_COMBAT() const
{
	FAssertMsg(m_cache_MAX_EXPERIENCE_PER_COMBAT != 0 || m_cache_MAX_EXPERIENCE_PER_COMBAT == getDefineINT("MAX_EXPERIENCE_PER_COMBAT"), "Cache for MAX_EXPERIENCE_PER_COMBAT is read before it's set");
	return m_cache_MAX_EXPERIENCE_PER_COMBAT;
}

inline int CvGlobals::getCache_MAX_FORTIFY_TURNS() const
{
	FAssertMsg(m_cache_MAX_FORTIFY_TURNS != 0 || m_cache_MAX_FORTIFY_TURNS == getDefineINT("MAX_FORTIFY_TURNS"), "Cache for MAX_FORTIFY_TURNS is read before it's set");
	return m_cache_MAX_FORTIFY_TURNS;
}

inline int CvGlobals::getCache_MAX_INSULT_MODIFIER() const
{
	FAssertMsg(m_cache_MAX_INSULT_MODIFIER != 0 || m_cache_MAX_INSULT_MODIFIER == getDefineINT("MAX_INSULT_MODIFIER"), "Cache for MAX_INSULT_MODIFIER is read before it's set");
	return m_cache_MAX_INSULT_MODIFIER;
}

inline int CvGlobals::getCache_MAX_LEVEL_FROM_ANIMAL_XP() const
{
	FAssertMsg(m_cache_MAX_LEVEL_FROM_ANIMAL_XP != 0 || m_cache_MAX_LEVEL_FROM_ANIMAL_XP == getDefineINT("MAX_LEVEL_FROM_ANIMAL_XP"), "Cache for MAX_LEVEL_FROM_ANIMAL_XP is read before it's set");
	return m_cache_MAX_LEVEL_FROM_ANIMAL_XP;
}

inline int CvGlobals::getCache_MAX_MARAUDERS() const
{
	FAssertMsg(m_cache_MAX_MARAUDERS != 0 || m_cache_MAX_MARAUDERS == getDefineINT("MAX_MARAUDERS"), "Cache for MAX_MARAUDERS is read before it's set");
	return m_cache_MAX_MARAUDERS;
}

inline int CvGlobals::getCache_MAX_NUM_LANGUAGES() const
{
	FAssertMsg(m_cache_MAX_NUM_LANGUAGES != 0 || m_cache_MAX_NUM_LANGUAGES == getDefineINT("MAX_NUM_LANGUAGES"), "Cache for MAX_NUM_LANGUAGES is read before it's set");
	return m_cache_MAX_NUM_LANGUAGES;
}

inline int CvGlobals::getCache_MAX_PLOT_LIST_SIZE() const
{
	FAssertMsg(m_cache_MAX_PLOT_LIST_SIZE != 0 || m_cache_MAX_PLOT_LIST_SIZE == getDefineINT("MAX_PLOT_LIST_SIZE"), "Cache for MAX_PLOT_LIST_SIZE is read before it's set");
	return m_cache_MAX_PLOT_LIST_SIZE;
}

inline int CvGlobals::getCache_MAX_REBEL_COMBAT_MULTIPLER() const
{
	FAssertMsg(m_cache_MAX_REBEL_COMBAT_MULTIPLER != 0 || m_cache_MAX_REBEL_COMBAT_MULTIPLER == getDefineINT("MAX_REBEL_COMBAT_MULTIPLER"), "Cache for MAX_REBEL_COMBAT_MULTIPLER is read before it's set");
	return m_cache_MAX_REBEL_COMBAT_MULTIPLER;
}

inline int CvGlobals::getCache_MAX_TRAINED_EXPERIENCE() const
{
	FAssertMsg(m_cache_MAX_TRAINED_EXPERIENCE != 0 || m_cache_MAX_TRAINED_EXPERIENCE == getDefineINT("MAX_TRAINED_EXPERIENCE"), "Cache for MAX_TRAINED_EXPERIENCE is read before it's set");
	return m_cache_MAX_TRAINED_EXPERIENCE;
}

inline int CvGlobals::getCache_MAX_WITHDRAWAL_PROBABILITY() const
{
	FAssertMsg(m_cache_MAX_WITHDRAWAL_PROBABILITY != 0 || m_cache_MAX_WITHDRAWAL_PROBABILITY == getDefineINT("MAX_WITHDRAWAL_PROBABILITY"), "Cache for MAX_WITHDRAWAL_PROBABILITY is read before it's set");
	return m_cache_MAX_WITHDRAWAL_PROBABILITY;
}

inline int CvGlobals::getCache_MEDIEVAL_CENSURE() const
{
	FAssertMsg(m_cache_MEDIEVAL_CENSURE != 0 || m_cache_MEDIEVAL_CENSURE == getDefineINT("MEDIEVAL_CENSURE"), "Cache for MEDIEVAL_CENSURE is read before it's set");
	return m_cache_MEDIEVAL_CENSURE;
}

inline int CvGlobals::getCache_MEDIEVAL_TRADE_TECH() const
{
	FAssertMsg(m_cache_MEDIEVAL_TRADE_TECH != 0 || m_cache_MEDIEVAL_TRADE_TECH == getDefineINT("MEDIEVAL_TRADE_TECH"), "Cache for MEDIEVAL_TRADE_TECH is read before it's set");
	return m_cache_MEDIEVAL_TRADE_TECH;
}

inline int CvGlobals::getCache_MINIMAP_RENDER_SIZE() const
{
	FAssertMsg(m_cache_MINIMAP_RENDER_SIZE != 0 || m_cache_MINIMAP_RENDER_SIZE == getDefineINT("MINIMAP_RENDER_SIZE"), "Cache for MINIMAP_RENDER_SIZE is read before it's set");
	return m_cache_MINIMAP_RENDER_SIZE;
}

inline int CvGlobals::getCache_MIN_ANIMAL_STARTING_DISTANCE() const
{
	FAssertMsg(m_cache_MIN_ANIMAL_STARTING_DISTANCE != 0 || m_cache_MIN_ANIMAL_STARTING_DISTANCE == getDefineINT("MIN_ANIMAL_STARTING_DISTANCE"), "Cache for MIN_ANIMAL_STARTING_DISTANCE is read before it's set");
	return m_cache_MIN_ANIMAL_STARTING_DISTANCE;
}

inline int CvGlobals::getCache_MIN_CITY_YIELD_DECAY() const
{
	FAssertMsg(m_cache_MIN_CITY_YIELD_DECAY != 0 || m_cache_MIN_CITY_YIELD_DECAY == getDefineINT("MIN_CITY_YIELD_DECAY"), "Cache for MIN_CITY_YIELD_DECAY is read before it's set");
	return m_cache_MIN_CITY_YIELD_DECAY;
}

inline int CvGlobals::getCache_MIN_CIV_STARTING_DISTANCE() const
{
	FAssertMsg(m_cache_MIN_CIV_STARTING_DISTANCE != 0 || m_cache_MIN_CIV_STARTING_DISTANCE == getDefineINT("MIN_CIV_STARTING_DISTANCE"), "Cache for MIN_CIV_STARTING_DISTANCE is read before it's set");
	return m_cache_MIN_CIV_STARTING_DISTANCE;
}

inline int CvGlobals::getCache_MIN_EXPERIENCE_PER_COMBAT() const
{
	FAssertMsg(m_cache_MIN_EXPERIENCE_PER_COMBAT != 0 || m_cache_MIN_EXPERIENCE_PER_COMBAT == getDefineINT("MIN_EXPERIENCE_PER_COMBAT"), "Cache for MIN_EXPERIENCE_PER_COMBAT is read before it's set");
	return m_cache_MIN_EXPERIENCE_PER_COMBAT;
}

inline int CvGlobals::getCache_MIN_TIMER_UNIT_DOUBLE_MOVES() const
{
	FAssertMsg(m_cache_MIN_TIMER_UNIT_DOUBLE_MOVES != 0 || m_cache_MIN_TIMER_UNIT_DOUBLE_MOVES == getDefineINT("MIN_TIMER_UNIT_DOUBLE_MOVES"), "Cache for MIN_TIMER_UNIT_DOUBLE_MOVES is read before it's set");
	return m_cache_MIN_TIMER_UNIT_DOUBLE_MOVES;
}

inline int CvGlobals::getCache_MIN_WATER_SIZE_FOR_OCEAN() const
{
	FAssertMsg(m_cache_MIN_WATER_SIZE_FOR_OCEAN != 0 || m_cache_MIN_WATER_SIZE_FOR_OCEAN == getDefineINT("MIN_WATER_SIZE_FOR_OCEAN"), "Cache for MIN_WATER_SIZE_FOR_OCEAN is read before it's set");
	return m_cache_MIN_WATER_SIZE_FOR_OCEAN;
}

inline int CvGlobals::getCache_MISSIONARY_RATE_EFFECT_ON_SUCCESS() const
{
	FAssertMsg(m_cache_MISSIONARY_RATE_EFFECT_ON_SUCCESS != 0 || m_cache_MISSIONARY_RATE_EFFECT_ON_SUCCESS == getDefineINT("MISSIONARY_RATE_EFFECT_ON_SUCCESS"), "Cache for MISSIONARY_RATE_EFFECT_ON_SUCCESS is read before it's set");
	return m_cache_MISSIONARY_RATE_EFFECT_ON_SUCCESS;
}

inline int CvGlobals::getCache_MISSIONARY_THRESHOLD() const
{
	FAssertMsg(m_cache_MISSIONARY_THRESHOLD != 0 || m_cache_MISSIONARY_THRESHOLD == getDefineINT("MISSIONARY_THRESHOLD"), "Cache for MISSIONARY_THRESHOLD is read before it's set");
	return m_cache_MISSIONARY_THRESHOLD;
}

inline int CvGlobals::getCache_MISSIONARY_THRESHOLD_INCREASE() const
{
	FAssertMsg(m_cache_MISSIONARY_THRESHOLD_INCREASE != 0 || m_cache_MISSIONARY_THRESHOLD_INCREASE == getDefineINT("MISSIONARY_THRESHOLD_INCREASE"), "Cache for MISSIONARY_THRESHOLD_INCREASE is read before it's set");
	return m_cache_MISSIONARY_THRESHOLD_INCREASE;
}

inline int CvGlobals::getCache_MONASTERIES_TO_VILLAGES_RATIO() const
{
	FAssertMsg(m_cache_MONASTERIES_TO_VILLAGES_RATIO != 0 || m_cache_MONASTERIES_TO_VILLAGES_RATIO == getDefineINT("MONASTERIES_TO_VILLAGES_RATIO"), "Cache for MONASTERIES_TO_VILLAGES_RATIO is read before it's set");
	return m_cache_MONASTERIES_TO_VILLAGES_RATIO;
}

inline int CvGlobals::getCache_NATIVE_AUTO_SELL_PERCENT() const
{
	FAssertMsg(m_cache_NATIVE_AUTO_SELL_PERCENT != 0 || m_cache_NATIVE_AUTO_SELL_PERCENT == getDefineINT("NATIVE_AUTO_SELL_PERCENT"), "Cache for NATIVE_AUTO_SELL_PERCENT is read before it's set");
	return m_cache_NATIVE_AUTO_SELL_PERCENT;
}

inline int CvGlobals::getCache_NATIVE_GOODS_RAID_PERCENT() const
{
	FAssertMsg(m_cache_NATIVE_GOODS_RAID_PERCENT != 0 || m_cache_NATIVE_GOODS_RAID_PERCENT == getDefineINT("NATIVE_GOODS_RAID_PERCENT"), "Cache for NATIVE_GOODS_RAID_PERCENT is read before it's set");
	return m_cache_NATIVE_GOODS_RAID_PERCENT;
}

inline int CvGlobals::getCache_NATIVE_GROWTH_THRESHOLD_MULTIPLIER() const
{
	FAssertMsg(m_cache_NATIVE_GROWTH_THRESHOLD_MULTIPLIER != 0 || m_cache_NATIVE_GROWTH_THRESHOLD_MULTIPLIER == getDefineINT("NATIVE_GROWTH_THRESHOLD_MULTIPLIER"), "Cache for NATIVE_GROWTH_THRESHOLD_MULTIPLIER is read before it's set");
	return m_cache_NATIVE_GROWTH_THRESHOLD_MULTIPLIER;
}

inline int CvGlobals::getCache_NATIVE_HORSES_FOR_SALE() const
{
	FAssertMsg(m_cache_NATIVE_HORSES_FOR_SALE != 0 || m_cache_NATIVE_HORSES_FOR_SALE == getDefineINT("NATIVE_HORSES_FOR_SALE"), "Cache for NATIVE_HORSES_FOR_SALE is read before it's set");
	return m_cache_NATIVE_HORSES_FOR_SALE;
}

inline int CvGlobals::getCache_NATIVE_HORSES_FOR_SALE_PERCENT() const
{
	FAssertMsg(m_cache_NATIVE_HORSES_FOR_SALE_PERCENT != 0 || m_cache_NATIVE_HORSES_FOR_SALE_PERCENT == getDefineINT("NATIVE_HORSES_FOR_SALE_PERCENT"), "Cache for NATIVE_HORSES_FOR_SALE_PERCENT is read before it's set");
	return m_cache_NATIVE_HORSES_FOR_SALE_PERCENT;
}

inline int CvGlobals::getCache_NATIVE_TEACH_THRESHOLD_INCREASE() const
{
	FAssertMsg(m_cache_NATIVE_TEACH_THRESHOLD_INCREASE != 0 || m_cache_NATIVE_TEACH_THRESHOLD_INCREASE == getDefineINT("NATIVE_TEACH_THRESHOLD_INCREASE"), "Cache for NATIVE_TEACH_THRESHOLD_INCREASE is read before it's set");
	return m_cache_NATIVE_TEACH_THRESHOLD_INCREASE;
}

inline int CvGlobals::getCache_NATIVE_TECH() const
{
	FAssertMsg(m_cache_NATIVE_TECH != 0 || m_cache_NATIVE_TECH == getDefineINT("NATIVE_TECH"), "Cache for NATIVE_TECH is read before it's set");
	return m_cache_NATIVE_TECH;
}

inline int CvGlobals::getCache_NATIVE_TRADING_TRADEPOST() const
{
	FAssertMsg(m_cache_NATIVE_TRADING_TRADEPOST != 0 || m_cache_NATIVE_TRADING_TRADEPOST == getDefineINT("NATIVE_TRADING_TRADEPOST"), "Cache for NATIVE_TRADING_TRADEPOST is read before it's set");
	return m_cache_NATIVE_TRADING_TRADEPOST;
}

inline int CvGlobals::getCache_NEUTRAL_HEAL_RATE() const
{
	FAssertMsg(m_cache_NEUTRAL_HEAL_RATE != 0 || m_cache_NEUTRAL_HEAL_RATE == getDefineINT("NEUTRAL_HEAL_RATE"), "Cache for NEUTRAL_HEAL_RATE is read before it's set");
	return m_cache_NEUTRAL_HEAL_RATE;
}

inline int CvGlobals::getCache_NEW_CITY_BUILDING_VALUE_MODIFIER() const
{
	FAssertMsg(m_cache_NEW_CITY_BUILDING_VALUE_MODIFIER != 0 || m_cache_NEW_CITY_BUILDING_VALUE_MODIFIER == getDefineINT("NEW_CITY_BUILDING_VALUE_MODIFIER"), "Cache for NEW_CITY_BUILDING_VALUE_MODIFIER is read before it's set");
	return m_cache_NEW_CITY_BUILDING_VALUE_MODIFIER;
}

inline int CvGlobals::getCache_NEW_HURRY_MODIFIER() const
{
	FAssertMsg(m_cache_NEW_HURRY_MODIFIER != 0 || m_cache_NEW_HURRY_MODIFIER == getDefineINT("NEW_HURRY_MODIFIER"), "Cache for NEW_HURRY_MODIFIER is read before it's set");
	return m_cache_NEW_HURRY_MODIFIER;
}

inline int CvGlobals::getCache_NOBLE_FIELD_LABOR_PENALTY() const
{
	FAssertMsg(m_cache_NOBLE_FIELD_LABOR_PENALTY != 0 || m_cache_NOBLE_FIELD_LABOR_PENALTY == getDefineINT("NOBLE_FIELD_LABOR_PENALTY"), "Cache for NOBLE_FIELD_LABOR_PENALTY is read before it's set");
	return m_cache_NOBLE_FIELD_LABOR_PENALTY;
}

inline int CvGlobals::getCache_NO_BAD_GOODIES_EXPERIENCE_PERCENT() const
{
	FAssertMsg(m_cache_NO_BAD_GOODIES_EXPERIENCE_PERCENT != 0 || m_cache_NO_BAD_GOODIES_EXPERIENCE_PERCENT == getDefineINT("NO_BAD_GOODIES_EXPERIENCE_PERCENT"), "Cache for NO_BAD_GOODIES_EXPERIENCE_PERCENT is read before it's set");
	return m_cache_NO_BAD_GOODIES_EXPERIENCE_PERCENT;
}

inline int CvGlobals::getCache_NO_BAD_GOODIES_GOLD_PERCENT() const
{
	FAssertMsg(m_cache_NO_BAD_GOODIES_GOLD_PERCENT != 0 || m_cache_NO_BAD_GOODIES_GOLD_PERCENT == getDefineINT("NO_BAD_GOODIES_GOLD_PERCENT"), "Cache for NO_BAD_GOODIES_GOLD_PERCENT is read before it's set");
	return m_cache_NO_BAD_GOODIES_GOLD_PERCENT;
}

inline int CvGlobals::getCache_NO_CITY_SHORTAGE_MESSAGES() const
{
	FAssertMsg(m_cache_NO_CITY_SHORTAGE_MESSAGES != 0 || m_cache_NO_CITY_SHORTAGE_MESSAGES == getDefineINT("NO_CITY_SHORTAGE_MESSAGES"), "Cache for NO_CITY_SHORTAGE_MESSAGES is read before it's set");
	return m_cache_NO_CITY_SHORTAGE_MESSAGES;
}

inline int CvGlobals::getCache_NO_STARTING_PLOTS_IN_JUNGLE() const
{
	FAssertMsg(m_cache_NO_STARTING_PLOTS_IN_JUNGLE != 0 || m_cache_NO_STARTING_PLOTS_IN_JUNGLE == getDefineINT("NO_STARTING_PLOTS_IN_JUNGLE"), "Cache for NO_STARTING_PLOTS_IN_JUNGLE is read before it's set");
	return m_cache_NO_STARTING_PLOTS_IN_JUNGLE;
}

inline int CvGlobals::getCache_OCCUPATION_CULTURE_PERCENT_THRESHOLD() const
{
	FAssertMsg(m_cache_OCCUPATION_CULTURE_PERCENT_THRESHOLD != 0 || m_cache_OCCUPATION_CULTURE_PERCENT_THRESHOLD == getDefineINT("OCCUPATION_CULTURE_PERCENT_THRESHOLD"), "Cache for OCCUPATION_CULTURE_PERCENT_THRESHOLD is read before it's set");
	return m_cache_OCCUPATION_CULTURE_PERCENT_THRESHOLD;
}

inline int CvGlobals::getCache_OCCUPATION_TURNS_POPULATION_PERCENT() const
{
	FAssertMsg(m_cache_OCCUPATION_TURNS_POPULATION_PERCENT != 0 || m_cache_OCCUPATION_TURNS_POPULATION_PERCENT == getDefineINT("OCCUPATION_TURNS_POPULATION_PERCENT"), "Cache for OCCUPATION_TURNS_POPULATION_PERCENT is read before it's set");
	return m_cache_OCCUPATION_TURNS_POPULATION_PERCENT;
}

inline int CvGlobals::getCache_OWNERSHIP_SCORE_DURATION_THRESHOLD() const
{
	FAssertMsg(m_cache_OWNERSHIP_SCORE_DURATION_THRESHOLD != 0 || m_cache_OWNERSHIP_SCORE_DURATION_THRESHOLD == getDefineINT("OWNERSHIP_SCORE_DURATION_THRESHOLD"), "Cache for OWNERSHIP_SCORE_DURATION_THRESHOLD is read before it's set");
	return m_cache_OWNERSHIP_SCORE_DURATION_THRESHOLD;
}

inline int CvGlobals::getCache_OWN_TEAM_STARTING_MODIFIER() const
{
	FAssertMsg(m_cache_OWN_TEAM_STARTING_MODIFIER != 0 || m_cache_OWN_TEAM_STARTING_MODIFIER == getDefineINT("OWN_TEAM_STARTING_MODIFIER"), "Cache for OWN_TEAM_STARTING_MODIFIER is read before it's set");
	return m_cache_OWN_TEAM_STARTING_MODIFIER;
}

inline int CvGlobals::getCache_PEACE_TREATY_LENGTH() const
{
	FAssertMsg(m_cache_PEACE_TREATY_LENGTH != 0 || m_cache_PEACE_TREATY_LENGTH == getDefineINT("PEACE_TREATY_LENGTH"), "Cache for PEACE_TREATY_LENGTH is read before it's set");
	return m_cache_PEACE_TREATY_LENGTH;
}

inline int CvGlobals::getCache_PERCENT_TAX_ON_AUTOSELL_GOODS() const
{
	FAssertMsg(m_cache_PERCENT_TAX_ON_AUTOSELL_GOODS != 0 || m_cache_PERCENT_TAX_ON_AUTOSELL_GOODS == getDefineINT("PERCENT_TAX_ON_AUTOSELL_GOODS"), "Cache for PERCENT_TAX_ON_AUTOSELL_GOODS is read before it's set");
	return m_cache_PERCENT_TAX_ON_AUTOSELL_GOODS;
}

inline int CvGlobals::getCache_PILGRAM_OFFER_GOLD() const
{
	FAssertMsg(m_cache_PILGRAM_OFFER_GOLD != 0 || m_cache_PILGRAM_OFFER_GOLD == getDefineINT("PILGRAM_OFFER_GOLD"), "Cache for PILGRAM_OFFER_GOLD is read before it's set");
	return m_cache_PILGRAM_OFFER_GOLD;
}

inline int CvGlobals::getCache_PILGRAM_OFFER_GOLD_DISTANCE_MOD() const
{
	FAssertMsg(m_cache_PILGRAM_OFFER_GOLD_DISTANCE_MOD != 0 || m_cache_PILGRAM_OFFER_GOLD_DISTANCE_MOD == getDefineINT("PILGRAM_OFFER_GOLD_DISTANCE_MOD"), "Cache for PILGRAM_OFFER_GOLD_DISTANCE_MOD is read before it's set");
	return m_cache_PILGRAM_OFFER_GOLD_DISTANCE_MOD;
}

inline int CvGlobals::getCache_PLAYER_ALWAYS_RAZES_CITIES() const
{
	FAssertMsg(m_cache_PLAYER_ALWAYS_RAZES_CITIES != 0 || m_cache_PLAYER_ALWAYS_RAZES_CITIES == getDefineINT("PLAYER_ALWAYS_RAZES_CITIES"), "Cache for PLAYER_ALWAYS_RAZES_CITIES is read before it's set");
	return m_cache_PLAYER_ALWAYS_RAZES_CITIES;
}

inline int CvGlobals::getCache_PLOTS_PER_RIVER_EDGE() const
{
	FAssertMsg(m_cache_PLOTS_PER_RIVER_EDGE != 0 || m_cache_PLOTS_PER_RIVER_EDGE == getDefineINT("PLOTS_PER_RIVER_EDGE"), "Cache for PLOTS_PER_RIVER_EDGE is read before it's set");
	return m_cache_PLOTS_PER_RIVER_EDGE;
}

inline int CvGlobals::getCache_PLOT_VISIBILITY_RANGE() const
{
	FAssertMsg(m_cache_PLOT_VISIBILITY_RANGE != 0 || m_cache_PLOT_VISIBILITY_RANGE == getDefineINT("PLOT_VISIBILITY_RANGE"), "Cache for PLOT_VISIBILITY_RANGE is read before it's set");
	return m_cache_PLOT_VISIBILITY_RANGE;
}

inline int CvGlobals::getCache_PROFESSION_COAL_BURNER() const
{
	FAssertMsg(m_cache_PROFESSION_COAL_BURNER != 0 || m_cache_PROFESSION_COAL_BURNER == getDefineINT("PROFESSION_COAL_BURNER"), "Cache for PROFESSION_COAL_BURNER is read before it's set");
	return m_cache_PROFESSION_COAL_BURNER;
}

inline int CvGlobals::getCache_PROFESSION_INVENTOR() const
{
	FAssertMsg(m_cache_PROFESSION_INVENTOR != 0 || m_cache_PROFESSION_INVENTOR == getDefineINT("PROFESSION_INVENTOR"), "Cache for PROFESSION_INVENTOR is read before it's set");
	return m_cache_PROFESSION_INVENTOR;
}

inline int CvGlobals::getCache_PROLIFIC_INVENTOR_THRESHOLD_INCREASE() const
{
	FAssertMsg(m_cache_PROLIFIC_INVENTOR_THRESHOLD_INCREASE != 0 || m_cache_PROLIFIC_INVENTOR_THRESHOLD_INCREASE == getDefineINT("PROLIFIC_INVENTOR_THRESHOLD_INCREASE"), "Cache for PROLIFIC_INVENTOR_THRESHOLD_INCREASE is read before it's set");
	return m_cache_PROLIFIC_INVENTOR_THRESHOLD_INCREASE;
}

inline int CvGlobals::getCache_PROMOTION_BUILD_HOME() const
{
	FAssertMsg(m_cache_PROMOTION_BUILD_HOME != 0 || m_cache_PROMOTION_BUILD_HOME == getDefineINT("PROMOTION_BUILD_HOME"), "Cache for PROMOTION_BUILD_HOME is read before it's set");
	return m_cache_PROMOTION_BUILD_HOME;
}

inline int CvGlobals::getCache_RANDOM_TURNS_LOST_AT_SEA() const
{
	FAssertMsg(m_cache_RANDOM_TURNS_LOST_AT_SEA != 0 || m_cache_RANDOM_TURNS_LOST_AT_SEA == getDefineINT("RANDOM_TURNS_LOST_AT_SEA"), "Cache for RANDOM_TURNS_LOST_AT_SEA is read before it's set");
	return m_cache_RANDOM_TURNS_LOST_AT_SEA;
}

inline int CvGlobals::getCache_RAZING_CULTURAL_PERCENT_THRESHOLD() const
{
	FAssertMsg(m_cache_RAZING_CULTURAL_PERCENT_THRESHOLD != 0 || m_cache_RAZING_CULTURAL_PERCENT_THRESHOLD == getDefineINT("RAZING_CULTURAL_PERCENT_THRESHOLD"), "Cache for RAZING_CULTURAL_PERCENT_THRESHOLD is read before it's set");
	return m_cache_RAZING_CULTURAL_PERCENT_THRESHOLD;
}

inline int CvGlobals::getCache_REBEL_PERCENT_FOR_REVOLUTION() const
{
	FAssertMsg(m_cache_REBEL_PERCENT_FOR_REVOLUTION != 0 || m_cache_REBEL_PERCENT_FOR_REVOLUTION == getDefineINT("REBEL_PERCENT_FOR_REVOLUTION"), "Cache for REBEL_PERCENT_FOR_REVOLUTION is read before it's set");
	return m_cache_REBEL_PERCENT_FOR_REVOLUTION;
}

inline int CvGlobals::getCache_REBEL_SENTIMENT_BELLS_FACTOR() const
{
	FAssertMsg(m_cache_REBEL_SENTIMENT_BELLS_FACTOR != 0 || m_cache_REBEL_SENTIMENT_BELLS_FACTOR == getDefineINT("REBEL_SENTIMENT_BELLS_FACTOR"), "Cache for REBEL_SENTIMENT_BELLS_FACTOR is read before it's set");
	return m_cache_REBEL_SENTIMENT_BELLS_FACTOR;
}

inline int CvGlobals::getCache_REBEL_SENTIMENT_TURN_WEIGHT() const
{
	FAssertMsg(m_cache_REBEL_SENTIMENT_TURN_WEIGHT != 0 || m_cache_REBEL_SENTIMENT_TURN_WEIGHT == getDefineINT("REBEL_SENTIMENT_TURN_WEIGHT"), "Cache for REBEL_SENTIMENT_TURN_WEIGHT is read before it's set");
	return m_cache_REBEL_SENTIMENT_TURN_WEIGHT;
}

inline int CvGlobals::getCache_REVOLUTION_EUROPE_UNIT_SHIP_MODIFIER() const
{
	FAssertMsg(m_cache_REVOLUTION_EUROPE_UNIT_SHIP_MODIFIER != 0 || m_cache_REVOLUTION_EUROPE_UNIT_SHIP_MODIFIER == getDefineINT("REVOLUTION_EUROPE_UNIT_SHIP_MODIFIER"), "Cache for REVOLUTION_EUROPE_UNIT_SHIP_MODIFIER is read before it's set");
	return m_cache_REVOLUTION_EUROPE_UNIT_SHIP_MODIFIER;
}

inline int CvGlobals::getCache_REVOLUTION_EUROPE_UNIT_THRESHOLD() const
{
	FAssertMsg(m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD != 0 || m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD == getDefineINT("REVOLUTION_EUROPE_UNIT_THRESHOLD"), "Cache for REVOLUTION_EUROPE_UNIT_THRESHOLD is read before it's set");
	return m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD;
}

inline int CvGlobals::getCache_REVOLUTION_EUROPE_UNIT_THRESHOLD_INCREASE() const
{
	FAssertMsg(m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD_INCREASE != 0 || m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD_INCREASE == getDefineINT("REVOLUTION_EUROPE_UNIT_THRESHOLD_INCREASE"), "Cache for REVOLUTION_EUROPE_UNIT_THRESHOLD_INCREASE is read before it's set");
	return m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD_INCREASE;
}

inline int CvGlobals::getCache_RIVAL_TEAM_STARTING_MODIFIER() const
{
	FAssertMsg(m_cache_RIVAL_TEAM_STARTING_MODIFIER != 0 || m_cache_RIVAL_TEAM_STARTING_MODIFIER == getDefineINT("RIVAL_TEAM_STARTING_MODIFIER"), "Cache for RIVAL_TEAM_STARTING_MODIFIER is read before it's set");
	return m_cache_RIVAL_TEAM_STARTING_MODIFIER;
}

inline int CvGlobals::getCache_RIVER_SOURCE_MIN_RIVER_RANGE() const
{
	FAssertMsg(m_cache_RIVER_SOURCE_MIN_RIVER_RANGE != 0 || m_cache_RIVER_SOURCE_MIN_RIVER_RANGE == getDefineINT("RIVER_SOURCE_MIN_RIVER_RANGE"), "Cache for RIVER_SOURCE_MIN_RIVER_RANGE is read before it's set");
	return m_cache_RIVER_SOURCE_MIN_RIVER_RANGE;
}

inline int CvGlobals::getCache_RIVER_SOURCE_MIN_SEAWATER_RANGE() const
{
	FAssertMsg(m_cache_RIVER_SOURCE_MIN_SEAWATER_RANGE != 0 || m_cache_RIVER_SOURCE_MIN_SEAWATER_RANGE == getDefineINT("RIVER_SOURCE_MIN_SEAWATER_RANGE"), "Cache for RIVER_SOURCE_MIN_SEAWATER_RANGE is read before it's set");
	return m_cache_RIVER_SOURCE_MIN_SEAWATER_RANGE;
}

inline int CvGlobals::getCache_RUINS_IMPROVEMENT() const
{
	FAssertMsg(m_cache_RUINS_IMPROVEMENT != 0 || m_cache_RUINS_IMPROVEMENT == getDefineINT("RUINS_IMPROVEMENT"), "Cache for RUINS_IMPROVEMENT is read before it's set");
	return m_cache_RUINS_IMPROVEMENT;
}

inline int CvGlobals::getCache_SCORE_FATHER_FACTOR() const
{
	FAssertMsg(m_cache_SCORE_FATHER_FACTOR != 0 || m_cache_SCORE_FATHER_FACTOR == getDefineINT("SCORE_FATHER_FACTOR"), "Cache for SCORE_FATHER_FACTOR is read before it's set");
	return m_cache_SCORE_FATHER_FACTOR;
}

inline int CvGlobals::getCache_SCORE_LAND_FACTOR() const
{
	FAssertMsg(m_cache_SCORE_LAND_FACTOR != 0 || m_cache_SCORE_LAND_FACTOR == getDefineINT("SCORE_LAND_FACTOR"), "Cache for SCORE_LAND_FACTOR is read before it's set");
	return m_cache_SCORE_LAND_FACTOR;
}

inline int CvGlobals::getCache_SCORE_POPULATION_FACTOR() const
{
	FAssertMsg(m_cache_SCORE_POPULATION_FACTOR != 0 || m_cache_SCORE_POPULATION_FACTOR == getDefineINT("SCORE_POPULATION_FACTOR"), "Cache for SCORE_POPULATION_FACTOR is read before it's set");
	return m_cache_SCORE_POPULATION_FACTOR;
}

inline int CvGlobals::getCache_SCORE_TAX_FACTOR() const
{
	FAssertMsg(m_cache_SCORE_TAX_FACTOR != 0 || m_cache_SCORE_TAX_FACTOR == getDefineINT("SCORE_TAX_FACTOR"), "Cache for SCORE_TAX_FACTOR is read before it's set");
	return m_cache_SCORE_TAX_FACTOR;
}

inline int CvGlobals::getCache_SETTLEMENT_TREASURE_YIELD() const
{
	FAssertMsg(m_cache_SETTLEMENT_TREASURE_YIELD != 0 || m_cache_SETTLEMENT_TREASURE_YIELD == getDefineINT("SETTLEMENT_TREASURE_YIELD"), "Cache for SETTLEMENT_TREASURE_YIELD is read before it's set");
	return m_cache_SETTLEMENT_TREASURE_YIELD;
}

inline int CvGlobals::getCache_SHALLOW_WATER_TERRAIN() const
{
	FAssertMsg(m_cache_SHALLOW_WATER_TERRAIN != 0 || m_cache_SHALLOW_WATER_TERRAIN == getDefineINT("SHALLOW_WATER_TERRAIN"), "Cache for SHALLOW_WATER_TERRAIN is read before it's set");
	return m_cache_SHALLOW_WATER_TERRAIN;
}

inline int CvGlobals::getCache_SLAVE_FOOD_CONSUMPTION_PER_POPULATION() const
{
	FAssertMsg(m_cache_SLAVE_FOOD_CONSUMPTION_PER_POPULATION != 0 || m_cache_SLAVE_FOOD_CONSUMPTION_PER_POPULATION == getDefineINT("SLAVE_FOOD_CONSUMPTION_PER_POPULATION"), "Cache for SLAVE_FOOD_CONSUMPTION_PER_POPULATION is read before it's set");
	return m_cache_SLAVE_FOOD_CONSUMPTION_PER_POPULATION;
}

inline int CvGlobals::getCache_STANDARD_CALENDAR() const
{
	FAssertMsg(m_cache_STANDARD_CALENDAR != 0 || m_cache_STANDARD_CALENDAR == getDefineINT("STANDARD_CALENDAR"), "Cache for STANDARD_CALENDAR is read before it's set");
	return m_cache_STANDARD_CALENDAR;
}

inline int CvGlobals::getCache_STANDARD_CLIMATE() const
{
	FAssertMsg(m_cache_STANDARD_CLIMATE != 0 || m_cache_STANDARD_CLIMATE == getDefineINT("STANDARD_CLIMATE"), "Cache for STANDARD_CLIMATE is read before it's set");
	return m_cache_STANDARD_CLIMATE;
}

inline int CvGlobals::getCache_STANDARD_ERA() const
{
	FAssertMsg(m_cache_STANDARD_ERA != 0 || m_cache_STANDARD_ERA == getDefineINT("STANDARD_ERA"), "Cache for STANDARD_ERA is read before it's set");
	return m_cache_STANDARD_ERA;
}

inline int CvGlobals::getCache_STANDARD_GAMESPEED() const
{
	FAssertMsg(m_cache_STANDARD_GAMESPEED != 0 || m_cache_STANDARD_GAMESPEED == getDefineINT("STANDARD_GAMESPEED"), "Cache for STANDARD_GAMESPEED is read before it's set");
	return m_cache_STANDARD_GAMESPEED;
}

inline int CvGlobals::getCache_STANDARD_HANDICAP() const
{
	FAssertMsg(m_cache_STANDARD_HANDICAP != 0 || m_cache_STANDARD_HANDICAP == getDefineINT("STANDARD_HANDICAP"), "Cache for STANDARD_HANDICAP is read before it's set");
	return m_cache_STANDARD_HANDICAP;
}

inline int CvGlobals::getCache_STANDARD_SEALEVEL() const
{
	FAssertMsg(m_cache_STANDARD_SEALEVEL != 0 || m_cache_STANDARD_SEALEVEL == getDefineINT("STANDARD_SEALEVEL"), "Cache for STANDARD_SEALEVEL is read before it's set");
	return m_cache_STANDARD_SEALEVEL;
}

inline int CvGlobals::getCache_STANDARD_TURNTIMER() const
{
	FAssertMsg(m_cache_STANDARD_TURNTIMER != 0 || m_cache_STANDARD_TURNTIMER == getDefineINT("STANDARD_TURNTIMER"), "Cache for STANDARD_TURNTIMER is read before it's set");
	return m_cache_STANDARD_TURNTIMER;
}

inline int CvGlobals::getCache_STARTING_DISTANCE_PERCENT() const
{
	FAssertMsg(m_cache_STARTING_DISTANCE_PERCENT != 0 || m_cache_STARTING_DISTANCE_PERCENT == getDefineINT("STARTING_DISTANCE_PERCENT"), "Cache for STARTING_DISTANCE_PERCENT is read before it's set");
	return m_cache_STARTING_DISTANCE_PERCENT;
}

inline int CvGlobals::getCache_START_YEAR() const
{
	FAssertMsg(m_cache_START_YEAR != 0 || m_cache_START_YEAR == getDefineINT("START_YEAR"), "Cache for START_YEAR is read before it's set");
	return m_cache_START_YEAR;
}

inline int CvGlobals::getCache_STEAMWORKS_BUILDING() const
{
	FAssertMsg(m_cache_STEAMWORKS_BUILDING != 0 || m_cache_STEAMWORKS_BUILDING == getDefineINT("STEAMWORKS_BUILDING"), "Cache for STEAMWORKS_BUILDING is read before it's set");
	return m_cache_STEAMWORKS_BUILDING;
}

inline int CvGlobals::getCache_STEAMWORKS_CLASS_TYPE() const
{
	FAssertMsg(m_cache_STEAMWORKS_CLASS_TYPE != 0 || m_cache_STEAMWORKS_CLASS_TYPE == getDefineINT("STEAMWORKS_CLASS_TYPE"), "Cache for STEAMWORKS_CLASS_TYPE is read before it's set");
	return m_cache_STEAMWORKS_CLASS_TYPE;
}

inline int CvGlobals::getCache_TAX_INCREASE_CHANCE() const
{
	FAssertMsg(m_cache_TAX_INCREASE_CHANCE != 0 || m_cache_TAX_INCREASE_CHANCE == getDefineINT("TAX_INCREASE_CHANCE"), "Cache for TAX_INCREASE_CHANCE is read before it's set");
	return m_cache_TAX_INCREASE_CHANCE;
}

inline int CvGlobals::getCache_TAX_RATE_MAX_INCREASE() const
{
	FAssertMsg(m_cache_TAX_RATE_MAX_INCREASE != 0 || m_cache_TAX_RATE_MAX_INCREASE == getDefineINT("TAX_RATE_MAX_INCREASE"), "Cache for TAX_RATE_MAX_INCREASE is read before it's set");
	return m_cache_TAX_RATE_MAX_INCREASE;
}

inline int CvGlobals::getCache_TAX_TRADE_THRESHOLD() const
{
	FAssertMsg(m_cache_TAX_TRADE_THRESHOLD != 0 || m_cache_TAX_TRADE_THRESHOLD == getDefineINT("TAX_TRADE_THRESHOLD"), "Cache for TAX_TRADE_THRESHOLD is read before it's set");
	return m_cache_TAX_TRADE_THRESHOLD;
}

inline int CvGlobals::getCache_TAX_TRADE_THRESHOLD_ATTITUDE_PERCENT() const
{
	FAssertMsg(m_cache_TAX_TRADE_THRESHOLD_ATTITUDE_PERCENT != 0 || m_cache_TAX_TRADE_THRESHOLD_ATTITUDE_PERCENT == getDefineINT("TAX_TRADE_THRESHOLD_ATTITUDE_PERCENT"), "Cache for TAX_TRADE_THRESHOLD_ATTITUDE_PERCENT is read before it's set");
	return m_cache_TAX_TRADE_THRESHOLD_ATTITUDE_PERCENT;
}

inline int CvGlobals::getCache_TAX_TRADE_THRESHOLD_TAX_RATE_PERCENT() const
{
	FAssertMsg(m_cache_TAX_TRADE_THRESHOLD_TAX_RATE_PERCENT != 0 || m_cache_TAX_TRADE_THRESHOLD_TAX_RATE_PERCENT == getDefineINT("TAX_TRADE_THRESHOLD_TAX_RATE_PERCENT"), "Cache for TAX_TRADE_THRESHOLD_TAX_RATE_PERCENT is read before it's set");
	return m_cache_TAX_TRADE_THRESHOLD_TAX_RATE_PERCENT;
}

inline int CvGlobals::getCache_TK_AI_RESEARCH_COST_MOD_PERCENT() const
{
	FAssertMsg(m_cache_TK_AI_RESEARCH_COST_MOD_PERCENT != 0 || m_cache_TK_AI_RESEARCH_COST_MOD_PERCENT == getDefineINT("TK_AI_RESEARCH_COST_MOD_PERCENT"), "Cache for TK_AI_RESEARCH_COST_MOD_PERCENT is read before it's set");
	return m_cache_TK_AI_RESEARCH_COST_MOD_PERCENT;
}

inline int CvGlobals::getCache_TK_HUMAN_RESEARCH_COST_MOD_PERCENT() const
{
	FAssertMsg(m_cache_TK_HUMAN_RESEARCH_COST_MOD_PERCENT != 0 || m_cache_TK_HUMAN_RESEARCH_COST_MOD_PERCENT == getDefineINT("TK_HUMAN_RESEARCH_COST_MOD_PERCENT"), "Cache for TK_HUMAN_RESEARCH_COST_MOD_PERCENT is read before it's set");
	return m_cache_TK_HUMAN_RESEARCH_COST_MOD_PERCENT;
}

inline int CvGlobals::getCache_TK_IDEAS_CITY_VALUE() const
{
	FAssertMsg(m_cache_TK_IDEAS_CITY_VALUE != 0 || m_cache_TK_IDEAS_CITY_VALUE == getDefineINT("TK_IDEAS_CITY_VALUE"), "Cache for TK_IDEAS_CITY_VALUE is read before it's set");
	return m_cache_TK_IDEAS_CITY_VALUE;
}

inline int CvGlobals::getCache_TK_MAX_FORTS_PER_CITY() const
{
	FAssertMsg(m_cache_TK_MAX_FORTS_PER_CITY != 0 || m_cache_TK_MAX_FORTS_PER_CITY == getDefineINT("TK_MAX_FORTS_PER_CITY"), "Cache for TK_MAX_FORTS_PER_CITY is read before it's set");
	return m_cache_TK_MAX_FORTS_PER_CITY;
}

inline int CvGlobals::getCache_TK_PIONEER_COAL_FURNACE_BONUS() const
{
	FAssertMsg(m_cache_TK_PIONEER_COAL_FURNACE_BONUS != 0 || m_cache_TK_PIONEER_COAL_FURNACE_BONUS == getDefineINT("TK_PIONEER_COAL_FURNACE_BONUS"), "Cache for TK_PIONEER_COAL_FURNACE_BONUS is read before it's set");
	return m_cache_TK_PIONEER_COAL_FURNACE_BONUS;
}

inline int CvGlobals::getCache_TK_PROLIFIC_INVENTOR_PROGRESS() const
{
	FAssertMsg(m_cache_TK_PROLIFIC_INVENTOR_PROGRESS != 0 || m_cache_TK_PROLIFIC_INVENTOR_PROGRESS == getDefineINT("TK_PROLIFIC_INVENTOR_PROGRESS"), "Cache for TK_PROLIFIC_INVENTOR_PROGRESS is read before it's set");
	return m_cache_TK_PROLIFIC_INVENTOR_PROGRESS;
}

inline int CvGlobals::getCache_TK_PROLIFIC_INVENTOR_THRESHOLD() const
{
	FAssertMsg(m_cache_TK_PROLIFIC_INVENTOR_THRESHOLD != 0 || m_cache_TK_PROLIFIC_INVENTOR_THRESHOLD == getDefineINT("TK_PROLIFIC_INVENTOR_THRESHOLD"), "Cache for TK_PROLIFIC_INVENTOR_THRESHOLD is read before it's set");
	return m_cache_TK_PROLIFIC_INVENTOR_THRESHOLD;
}

inline int CvGlobals::getCache_TK_RESEARCH_PACT_IDEAS_THRESHOLD() const
{
	FAssertMsg(m_cache_TK_RESEARCH_PACT_IDEAS_THRESHOLD != 0 || m_cache_TK_RESEARCH_PACT_IDEAS_THRESHOLD == getDefineINT("TK_RESEARCH_PACT_IDEAS_THRESHOLD"), "Cache for TK_RESEARCH_PACT_IDEAS_THRESHOLD is read before it's set");
	return m_cache_TK_RESEARCH_PACT_IDEAS_THRESHOLD;
}

inline int CvGlobals::getCache_TK_RESEARCH_TRADE_VALUE() const
{
	FAssertMsg(m_cache_TK_RESEARCH_TRADE_VALUE != 0 || m_cache_TK_RESEARCH_TRADE_VALUE == getDefineINT("TK_RESEARCH_TRADE_VALUE"), "Cache for TK_RESEARCH_TRADE_VALUE is read before it's set");
	return m_cache_TK_RESEARCH_TRADE_VALUE;
}

inline int CvGlobals::getCache_TK_STEAMWORKS_MODIFIER() const
{
	FAssertMsg(m_cache_TK_STEAMWORKS_MODIFIER != 0 || m_cache_TK_STEAMWORKS_MODIFIER == getDefineINT("TK_STEAMWORKS_MODIFIER"), "Cache for TK_STEAMWORKS_MODIFIER is read before it's set");
	return m_cache_TK_STEAMWORKS_MODIFIER;
}

inline int CvGlobals::getCache_TRADE_POINTS_FOR_ROUTE() const
{
	FAssertMsg(m_cache_TRADE_POINTS_FOR_ROUTE != 0 || m_cache_TRADE_POINTS_FOR_ROUTE == getDefineINT("TRADE_POINTS_FOR_ROUTE"), "Cache for TRADE_POINTS_FOR_ROUTE is read before it's set");
	return m_cache_TRADE_POINTS_FOR_ROUTE;
}

inline int CvGlobals::getCache_TRADE_ROUTE_SPICE() const
{
	FAssertMsg(m_cache_TRADE_ROUTE_SPICE != 0 || m_cache_TRADE_ROUTE_SPICE == getDefineINT("TRADE_ROUTE_SPICE"), "Cache for TRADE_ROUTE_SPICE is read before it's set");
	return m_cache_TRADE_ROUTE_SPICE;
}

inline int CvGlobals::getCache_TRADE_STIMULATES_RESEARCH_MIN_VALUE() const
{
	FAssertMsg(m_cache_TRADE_STIMULATES_RESEARCH_MIN_VALUE != 0 || m_cache_TRADE_STIMULATES_RESEARCH_MIN_VALUE == getDefineINT("TRADE_STIMULATES_RESEARCH_MIN_VALUE"), "Cache for TRADE_STIMULATES_RESEARCH_MIN_VALUE is read before it's set");
	return m_cache_TRADE_STIMULATES_RESEARCH_MIN_VALUE;
}

inline int CvGlobals::getCache_TRADE_STIMULATES_RESEARCH_PERCENT() const
{
	FAssertMsg(m_cache_TRADE_STIMULATES_RESEARCH_PERCENT != 0 || m_cache_TRADE_STIMULATES_RESEARCH_PERCENT == getDefineINT("TRADE_STIMULATES_RESEARCH_PERCENT"), "Cache for TRADE_STIMULATES_RESEARCH_PERCENT is read before it's set");
	return m_cache_TRADE_STIMULATES_RESEARCH_PERCENT;
}

inline int CvGlobals::getCache_TRADING_POINTS_MOD_PERCENT() const
{
	FAssertMsg(m_cache_TRADING_POINTS_MOD_PERCENT != 0 || m_cache_TRADING_POINTS_MOD_PERCENT == getDefineINT("TRADING_POINTS_MOD_PERCENT"), "Cache for TRADING_POINTS_MOD_PERCENT is read before it's set");
	return m_cache_TRADING_POINTS_MOD_PERCENT;
}

inline int CvGlobals::getCache_TREASURE_UNITCLASS() const
{
	FAssertMsg(m_cache_TREASURE_UNITCLASS != 0 || m_cache_TREASURE_UNITCLASS == getDefineINT("TREASURE_UNITCLASS"), "Cache for TREASURE_UNITCLASS is read before it's set");
	return m_cache_TREASURE_UNITCLASS;
}

inline int CvGlobals::getCache_TREASURE_UNITS_ONLY_SELECT_COASTAL() const
{
	FAssertMsg(m_cache_TREASURE_UNITS_ONLY_SELECT_COASTAL != 0 || m_cache_TREASURE_UNITS_ONLY_SELECT_COASTAL == getDefineINT("TREASURE_UNITS_ONLY_SELECT_COASTAL"), "Cache for TREASURE_UNITS_ONLY_SELECT_COASTAL is read before it's set");
	return m_cache_TREASURE_UNITS_ONLY_SELECT_COASTAL;
}

inline int CvGlobals::getCache_TURNS_TO_TRAIN() const
{
	FAssertMsg(m_cache_TURNS_TO_TRAIN != 0 || m_cache_TURNS_TO_TRAIN == getDefineINT("TURNS_TO_TRAIN"), "Cache for TURNS_TO_TRAIN is read before it's set");
	return m_cache_TURNS_TO_TRAIN;
}

inline int CvGlobals::getCache_UNITARMOR_LEATHER() const
{
	FAssertMsg(m_cache_UNITARMOR_LEATHER != 0 || m_cache_UNITARMOR_LEATHER == getDefineINT("UNITARMOR_LEATHER"), "Cache for UNITARMOR_LEATHER is read before it's set");
	return m_cache_UNITARMOR_LEATHER;
}

inline int CvGlobals::getCache_UNITARMOR_MAIL() const
{
	FAssertMsg(m_cache_UNITARMOR_MAIL != 0 || m_cache_UNITARMOR_MAIL == getDefineINT("UNITARMOR_MAIL"), "Cache for UNITARMOR_MAIL is read before it's set");
	return m_cache_UNITARMOR_MAIL;
}

inline int CvGlobals::getCache_UNITARMOR_PLATE() const
{
	FAssertMsg(m_cache_UNITARMOR_PLATE != 0 || m_cache_UNITARMOR_PLATE == getDefineINT("UNITARMOR_PLATE"), "Cache for UNITARMOR_PLATE is read before it's set");
	return m_cache_UNITARMOR_PLATE;
}

inline int CvGlobals::getCache_UNITARMOR_SCALE() const
{
	FAssertMsg(m_cache_UNITARMOR_SCALE != 0 || m_cache_UNITARMOR_SCALE == getDefineINT("UNITARMOR_SCALE"), "Cache for UNITARMOR_SCALE is read before it's set");
	return m_cache_UNITARMOR_SCALE;
}

inline int CvGlobals::getCache_UNITARMOR_SHIELD() const
{
	FAssertMsg(m_cache_UNITARMOR_SHIELD != 0 || m_cache_UNITARMOR_SHIELD == getDefineINT("UNITARMOR_SHIELD"), "Cache for UNITARMOR_SHIELD is read before it's set");
	return m_cache_UNITARMOR_SHIELD;
}

inline int CvGlobals::getCache_UNITCLASS_PIONEER() const
{
	FAssertMsg(m_cache_UNITCLASS_PIONEER != 0 || m_cache_UNITCLASS_PIONEER == getDefineINT("UNITCLASS_PIONEER"), "Cache for UNITCLASS_PIONEER is read before it's set");
	return m_cache_UNITCLASS_PIONEER;
}

inline int CvGlobals::getCache_UNITTACTIC_PARRY() const
{
	FAssertMsg(m_cache_UNITTACTIC_PARRY != 0 || m_cache_UNITTACTIC_PARRY == getDefineINT("UNITTACTIC_PARRY"), "Cache for UNITTACTIC_PARRY is read before it's set");
	return m_cache_UNITTACTIC_PARRY;
}

inline int CvGlobals::getCache_UNITWEAPON_BLUNT() const
{
	FAssertMsg(m_cache_UNITWEAPON_BLUNT != 0 || m_cache_UNITWEAPON_BLUNT == getDefineINT("UNITWEAPON_BLUNT"), "Cache for UNITWEAPON_BLUNT is read before it's set");
	return m_cache_UNITWEAPON_BLUNT;
}

inline int CvGlobals::getCache_UNIT_PRODUCTION_DECAY_PERCENT() const
{
	FAssertMsg(m_cache_UNIT_PRODUCTION_DECAY_PERCENT != 0 || m_cache_UNIT_PRODUCTION_DECAY_PERCENT == getDefineINT("UNIT_PRODUCTION_DECAY_PERCENT"), "Cache for UNIT_PRODUCTION_DECAY_PERCENT is read before it's set");
	return m_cache_UNIT_PRODUCTION_DECAY_PERCENT;
}

inline int CvGlobals::getCache_UNIT_PRODUCTION_DECAY_TIME() const
{
	FAssertMsg(m_cache_UNIT_PRODUCTION_DECAY_TIME != 0 || m_cache_UNIT_PRODUCTION_DECAY_TIME == getDefineINT("UNIT_PRODUCTION_DECAY_TIME"), "Cache for UNIT_PRODUCTION_DECAY_TIME is read before it's set");
	return m_cache_UNIT_PRODUCTION_DECAY_TIME;
}

inline int CvGlobals::getCache_UNIT_PRODUCTION_PERCENT() const
{
	FAssertMsg(m_cache_UNIT_PRODUCTION_PERCENT != 0 || m_cache_UNIT_PRODUCTION_PERCENT == getDefineINT("UNIT_PRODUCTION_PERCENT"), "Cache for UNIT_PRODUCTION_PERCENT is read before it's set");
	return m_cache_UNIT_PRODUCTION_PERCENT;
}

inline int CvGlobals::getCache_UNIT_UPGRADE_COST_PER_PRODUCTION() const
{
	FAssertMsg(m_cache_UNIT_UPGRADE_COST_PER_PRODUCTION != 0 || m_cache_UNIT_UPGRADE_COST_PER_PRODUCTION == getDefineINT("UNIT_UPGRADE_COST_PER_PRODUCTION"), "Cache for UNIT_UPGRADE_COST_PER_PRODUCTION is read before it's set");
	return m_cache_UNIT_UPGRADE_COST_PER_PRODUCTION;
}

inline int CvGlobals::getCache_UNIT_VISIBILITY_RANGE() const
{
	FAssertMsg(m_cache_UNIT_VISIBILITY_RANGE != 0 || m_cache_UNIT_VISIBILITY_RANGE == getDefineINT("UNIT_VISIBILITY_RANGE"), "Cache for UNIT_VISIBILITY_RANGE is read before it's set");
	return m_cache_UNIT_VISIBILITY_RANGE;
}

inline int CvGlobals::getCache_USE_MEDIEVAL_CALENDER() const
{
	FAssertMsg(m_cache_USE_MEDIEVAL_CALENDER != 0 || m_cache_USE_MEDIEVAL_CALENDER == getDefineINT("USE_MEDIEVAL_CALENDER"), "Cache for USE_MEDIEVAL_CALENDER is read before it's set");
	return m_cache_USE_MEDIEVAL_CALENDER;
}

inline int CvGlobals::getCache_VASSAL_CIVILIZATION() const
{
	FAssertMsg(m_cache_VASSAL_CIVILIZATION != 0 || m_cache_VASSAL_CIVILIZATION == getDefineINT("VASSAL_CIVILIZATION"), "Cache for VASSAL_CIVILIZATION is read before it's set");
	return m_cache_VASSAL_CIVILIZATION;
}

inline int CvGlobals::getCache_VASSAL_LEADER() const
{
	FAssertMsg(m_cache_VASSAL_LEADER != 0 || m_cache_VASSAL_LEADER == getDefineINT("VASSAL_LEADER"), "Cache for VASSAL_LEADER is read before it's set");
	return m_cache_VASSAL_LEADER;
}

inline int CvGlobals::getCache_WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT() const
{
	FAssertMsg(m_cache_WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT != 0 || m_cache_WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT == getDefineINT("WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT"), "Cache for WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT is read before it's set");
	return m_cache_WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT;
}

inline int CvGlobals::getCache_WAR_SUCCESS_ATTACKING() const
{
	FAssertMsg(m_cache_WAR_SUCCESS_ATTACKING != 0 || m_cache_WAR_SUCCESS_ATTACKING == getDefineINT("WAR_SUCCESS_ATTACKING"), "Cache for WAR_SUCCESS_ATTACKING is read before it's set");
	return m_cache_WAR_SUCCESS_ATTACKING;
}

inline int CvGlobals::getCache_WAR_SUCCESS_CITY_CAPTURING() const
{
	FAssertMsg(m_cache_WAR_SUCCESS_CITY_CAPTURING != 0 || m_cache_WAR_SUCCESS_CITY_CAPTURING == getDefineINT("WAR_SUCCESS_CITY_CAPTURING"), "Cache for WAR_SUCCESS_CITY_CAPTURING is read before it's set");
	return m_cache_WAR_SUCCESS_CITY_CAPTURING;
}

inline int CvGlobals::getCache_WAR_SUCCESS_DEFENDING() const
{
	FAssertMsg(m_cache_WAR_SUCCESS_DEFENDING != 0 || m_cache_WAR_SUCCESS_DEFENDING == getDefineINT("WAR_SUCCESS_DEFENDING"), "Cache for WAR_SUCCESS_DEFENDING is read before it's set");
	return m_cache_WAR_SUCCESS_DEFENDING;
}

inline int CvGlobals::getCache_WAR_SUCCESS_UNIT_CAPTURING() const
{
	FAssertMsg(m_cache_WAR_SUCCESS_UNIT_CAPTURING != 0 || m_cache_WAR_SUCCESS_UNIT_CAPTURING == getDefineINT("WAR_SUCCESS_UNIT_CAPTURING"), "Cache for WAR_SUCCESS_UNIT_CAPTURING is read before it's set");
	return m_cache_WAR_SUCCESS_UNIT_CAPTURING;
}

inline int CvGlobals::getCache_WATER_IMPROVEMENT() const
{
	FAssertMsg(m_cache_WATER_IMPROVEMENT != 0 || m_cache_WATER_IMPROVEMENT == getDefineINT("WATER_IMPROVEMENT"), "Cache for WATER_IMPROVEMENT is read before it's set");
	return m_cache_WATER_IMPROVEMENT;
}

inline int CvGlobals::getCache_WATER_UNIT_FACING_DIRECTION() const
{
	FAssertMsg(m_cache_WATER_UNIT_FACING_DIRECTION != 0 || m_cache_WATER_UNIT_FACING_DIRECTION == getDefineINT("WATER_UNIT_FACING_DIRECTION"), "Cache for WATER_UNIT_FACING_DIRECTION is read before it's set");
	return m_cache_WATER_UNIT_FACING_DIRECTION;
}

inline int CvGlobals::getCache_WEEKS_PER_MONTHS() const
{
	FAssertMsg(m_cache_WEEKS_PER_MONTHS != 0 || m_cache_WEEKS_PER_MONTHS == getDefineINT("WEEKS_PER_MONTHS"), "Cache for WEEKS_PER_MONTHS is read before it's set");
	return m_cache_WEEKS_PER_MONTHS;
}

inline int CvGlobals::getCache_WILD_ANIMAL_ATTACK_WEIGHT() const
{
	FAssertMsg(m_cache_WILD_ANIMAL_ATTACK_WEIGHT != 0 || m_cache_WILD_ANIMAL_ATTACK_WEIGHT == getDefineINT("WILD_ANIMAL_ATTACK_WEIGHT"), "Cache for WILD_ANIMAL_ATTACK_WEIGHT is read before it's set");
	return m_cache_WILD_ANIMAL_ATTACK_WEIGHT;
}

inline int CvGlobals::getCache_WILD_ANIMAL_LAND_BONUS_NATIVE_WEIGHT() const
{
	FAssertMsg(m_cache_WILD_ANIMAL_LAND_BONUS_NATIVE_WEIGHT != 0 || m_cache_WILD_ANIMAL_LAND_BONUS_NATIVE_WEIGHT == getDefineINT("WILD_ANIMAL_LAND_BONUS_NATIVE_WEIGHT"), "Cache for WILD_ANIMAL_LAND_BONUS_NATIVE_WEIGHT is read before it's set");
	return m_cache_WILD_ANIMAL_LAND_BONUS_NATIVE_WEIGHT;
}

inline int CvGlobals::getCache_WILD_ANIMAL_LAND_FEATURE_NATIVE_WEIGHT() const
{
	FAssertMsg(m_cache_WILD_ANIMAL_LAND_FEATURE_NATIVE_WEIGHT != 0 || m_cache_WILD_ANIMAL_LAND_FEATURE_NATIVE_WEIGHT == getDefineINT("WILD_ANIMAL_LAND_FEATURE_NATIVE_WEIGHT"), "Cache for WILD_ANIMAL_LAND_FEATURE_NATIVE_WEIGHT is read before it's set");
	return m_cache_WILD_ANIMAL_LAND_FEATURE_NATIVE_WEIGHT;
}

inline int CvGlobals::getCache_WILD_ANIMAL_LAND_PATROL_BASE_WEIGHT() const
{
	FAssertMsg(m_cache_WILD_ANIMAL_LAND_PATROL_BASE_WEIGHT != 0 || m_cache_WILD_ANIMAL_LAND_PATROL_BASE_WEIGHT == getDefineINT("WILD_ANIMAL_LAND_PATROL_BASE_WEIGHT"), "Cache for WILD_ANIMAL_LAND_PATROL_BASE_WEIGHT is read before it's set");
	return m_cache_WILD_ANIMAL_LAND_PATROL_BASE_WEIGHT;
}

inline int CvGlobals::getCache_WILD_ANIMAL_LAND_TERRAIN_NATIVE_WEIGHT() const
{
	FAssertMsg(m_cache_WILD_ANIMAL_LAND_TERRAIN_NATIVE_WEIGHT != 0 || m_cache_WILD_ANIMAL_LAND_TERRAIN_NATIVE_WEIGHT == getDefineINT("WILD_ANIMAL_LAND_TERRAIN_NATIVE_WEIGHT"), "Cache for WILD_ANIMAL_LAND_TERRAIN_NATIVE_WEIGHT is read before it's set");
	return m_cache_WILD_ANIMAL_LAND_TERRAIN_NATIVE_WEIGHT;
}

inline int CvGlobals::getCache_WILD_ANIMAL_LAND_UNIT_VARIATION_WEIGHT() const
{
	FAssertMsg(m_cache_WILD_ANIMAL_LAND_UNIT_VARIATION_WEIGHT != 0 || m_cache_WILD_ANIMAL_LAND_UNIT_VARIATION_WEIGHT == getDefineINT("WILD_ANIMAL_LAND_UNIT_VARIATION_WEIGHT"), "Cache for WILD_ANIMAL_LAND_UNIT_VARIATION_WEIGHT is read before it's set");
	return m_cache_WILD_ANIMAL_LAND_UNIT_VARIATION_WEIGHT;
}

inline int CvGlobals::getCache_WILD_ANIMAL_SEA_BONUS_NATIVE_WEIGHT() const
{
	FAssertMsg(m_cache_WILD_ANIMAL_SEA_BONUS_NATIVE_WEIGHT != 0 || m_cache_WILD_ANIMAL_SEA_BONUS_NATIVE_WEIGHT == getDefineINT("WILD_ANIMAL_SEA_BONUS_NATIVE_WEIGHT"), "Cache for WILD_ANIMAL_SEA_BONUS_NATIVE_WEIGHT is read before it's set");
	return m_cache_WILD_ANIMAL_SEA_BONUS_NATIVE_WEIGHT;
}

inline int CvGlobals::getCache_WILD_ANIMAL_SEA_FEATURE_NATIVE_WEIGHT() const
{
	FAssertMsg(m_cache_WILD_ANIMAL_SEA_FEATURE_NATIVE_WEIGHT != 0 || m_cache_WILD_ANIMAL_SEA_FEATURE_NATIVE_WEIGHT == getDefineINT("WILD_ANIMAL_SEA_FEATURE_NATIVE_WEIGHT"), "Cache for WILD_ANIMAL_SEA_FEATURE_NATIVE_WEIGHT is read before it's set");
	return m_cache_WILD_ANIMAL_SEA_FEATURE_NATIVE_WEIGHT;
}

inline int CvGlobals::getCache_WILD_ANIMAL_SEA_PATROL_BASE_WEIGHT() const
{
	FAssertMsg(m_cache_WILD_ANIMAL_SEA_PATROL_BASE_WEIGHT != 0 || m_cache_WILD_ANIMAL_SEA_PATROL_BASE_WEIGHT == getDefineINT("WILD_ANIMAL_SEA_PATROL_BASE_WEIGHT"), "Cache for WILD_ANIMAL_SEA_PATROL_BASE_WEIGHT is read before it's set");
	return m_cache_WILD_ANIMAL_SEA_PATROL_BASE_WEIGHT;
}

inline int CvGlobals::getCache_WILD_ANIMAL_SEA_TERRAIN_NATIVE_WEIGHT() const
{
	FAssertMsg(m_cache_WILD_ANIMAL_SEA_TERRAIN_NATIVE_WEIGHT != 0 || m_cache_WILD_ANIMAL_SEA_TERRAIN_NATIVE_WEIGHT == getDefineINT("WILD_ANIMAL_SEA_TERRAIN_NATIVE_WEIGHT"), "Cache for WILD_ANIMAL_SEA_TERRAIN_NATIVE_WEIGHT is read before it's set");
	return m_cache_WILD_ANIMAL_SEA_TERRAIN_NATIVE_WEIGHT;
}

inline int CvGlobals::getCache_WILD_ANIMAL_SEA_UNIT_VARIATION_WEIGHT() const
{
	FAssertMsg(m_cache_WILD_ANIMAL_SEA_UNIT_VARIATION_WEIGHT != 0 || m_cache_WILD_ANIMAL_SEA_UNIT_VARIATION_WEIGHT == getDefineINT("WILD_ANIMAL_SEA_UNIT_VARIATION_WEIGHT"), "Cache for WILD_ANIMAL_SEA_UNIT_VARIATION_WEIGHT is read before it's set");
	return m_cache_WILD_ANIMAL_SEA_UNIT_VARIATION_WEIGHT;
}
// cache XML - end - Nightinggale


// EDU remake - start - Nightinggale
inline float CvGlobals::getEducationCost(int iTeachLevel) const
{
	FAssert(iTeachLevel > 0 && iTeachLevel <= NUM_TEACH_LEVELS);
	return m_aiEducationCost[iTeachLevel - 1];
}
// EDU remake - start - Nightinggale
#endif

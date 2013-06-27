//
// globals.cpp
// Author -	Mustafa Thamer
//
#include "CvGameCoreDLL.h"
#include "CvGlobals.h"
#include "CvRandom.h"
#include "CvGameAI.h"
#include "CvDLLInterfaceIFaceBase.h"
#include "CvMap.h"
#include "CvPlayerAI.h"
#include "CvTeamAI.h"
#include "CvInfos.h"
#include "CvDLLUtilityIFaceBase.h"
#include "CvArtFileMgr.h"
#include "CvDLLXMLIFaceBase.h"
#include "CvPlayerAI.h"
#include "CvInfoWater.h"
#include "CvGameTextMgr.h"
#include "FProfiler.h"
#include "FVariableSystem.h"
#include "CvInitCore.h"

#define COPY(dst, src, typeName) \
	{ \
		int iNum = sizeof(src)/sizeof(typeName); \
		dst = new typeName[iNum]; \
		for (int i =0;i<iNum;i++) \
			dst[i] = src[i]; \
	}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

CvGlobals gGlobals;

//
// CONSTRUCTOR
//
CvGlobals::CvGlobals() :
m_bGraphicsInitialized(false),
m_bLogging(false),
m_bRandLogging(false),
m_bOverwriteLogs(false),
m_bSynchLogging(false),
m_pkMainMenu(NULL),
m_iNewPlayers(0),
m_bZoomOut(false),
m_bZoomIn(false),
m_bLoadGameFromFile(false),
m_pFMPMgr(NULL),
m_asyncRand(NULL),
m_interface(NULL),
m_game(NULL),
m_messageQueue(NULL),
m_hotJoinMsgQueue(NULL),
m_messageControl(NULL),
m_messageCodes(NULL),
m_dropMgr(NULL),
m_portal(NULL),
m_setupData(NULL),
m_initCore(NULL),
m_statsReporter(NULL),
m_map(NULL),
m_diplomacyScreen(NULL),
m_mpDiplomacyScreen(NULL),
m_pathFinder(NULL),
m_interfacePathFinder(NULL),
m_stepFinder(NULL),
m_routeFinder(NULL),
m_borderFinder(NULL),
m_areaFinder(NULL),
m_pDLL(NULL),
m_aiPlotDirectionX(NULL),
m_aiPlotDirectionY(NULL),
m_aiPlotCardinalDirectionX(NULL),
m_aiPlotCardinalDirectionY(NULL),
m_aiCityPlotX(NULL),
m_aiCityPlotY(NULL),
m_aiCityPlotPriority(NULL),
m_aeTurnLeftDirection(NULL),
m_aeTurnRightDirection(NULL),
m_VarSystem(NULL),
m_iMOVE_DENOMINATOR(0),
m_iFOOD_CONSUMPTION_PER_POPULATION(0),
m_iMAX_HIT_POINTS(0),
m_iHILLS_EXTRA_DEFENSE(0),
m_iRIVER_ATTACK_MODIFIER(0),
m_iAMPHIB_ATTACK_MODIFIER(0),
m_iHILLS_EXTRA_MOVEMENT(0),
m_iPEAK_EXTRA_MOVEMENT(0),
m_iMAX_PLOT_LIST_ROWS(0),
m_iUNIT_MULTISELECT_MAX(0),
m_iEVENT_MESSAGE_TIME(0),
m_iROUTE_FEATURE_GROWTH_MODIFIER(0),
m_iFEATURE_GROWTH_MODIFIER(0),
m_iMIN_CITY_RANGE(0),
m_iCITY_MAX_NUM_BUILDINGS(0),
m_iLAKE_MAX_AREA_SIZE(0),
m_iMIN_WATER_SIZE_FOR_OCEAN(0),
m_iFORTIFY_MODIFIER_PER_TURN(0),
m_iMAX_CITY_DEFENSE_DAMAGE(0),
m_iPEAK_SEE_THROUGH_CHANGE(0),
m_iHILLS_SEE_THROUGH_CHANGE(0),
m_iSEAWATER_SEE_FROM_CHANGE(0),
m_iPEAK_SEE_FROM_CHANGE(0),
m_iHILLS_SEE_FROM_CHANGE(0),
m_iMAX_REBEL_YIELD_MODIFIER(0),
m_fCAMERA_MIN_YAW(0),
m_fCAMERA_MAX_YAW(0),
m_fCAMERA_FAR_CLIP_Z_HEIGHT(0),
m_fCAMERA_MAX_TRAVEL_DISTANCE(0),
m_fCAMERA_START_DISTANCE(0),
m_fPLOT_SIZE(0),
m_fCAMERA_SPECIAL_PITCH(0),
m_fCAMERA_MAX_TURN_OFFSET(0),
m_fCAMERA_MIN_DISTANCE(0),
m_fCAMERA_UPPER_PITCH(0),
m_fCAMERA_LOWER_PITCH(0),
m_fFIELD_OF_VIEW(0),
m_fUNIT_MULTISELECT_DISTANCE(0),
m_iUSE_CAN_FOUND_CITIES_ON_WATER_CALLBACK(0),
m_iUSE_CANNOT_DO_CIVIC_CALLBACK(0),
m_iUSE_CAN_DO_CIVIC_CALLBACK(0),
m_iUSE_CANNOT_CONSTRUCT_CALLBACK(0),
m_iUSE_CAN_CONSTRUCT_CALLBACK(0),
m_iUSE_CAN_DECLARE_WAR_CALLBACK(0),
m_iUSE_GET_UNIT_COST_MOD_CALLBACK(0),
m_iUSE_GET_CITY_FOUND_VALUE_CALLBACK(0),
m_iUSE_CANNOT_HANDLE_ACTION_CALLBACK(0),
m_iUSE_CAN_BUILD_CALLBACK(0),
m_iUSE_CANNOT_TRAIN_CALLBACK(0),
m_iUSE_CAN_TRAIN_CALLBACK(0),
m_iUSE_UNIT_CANNOT_MOVE_INTO_CALLBACK(0),
m_iUSE_FINISH_TEXT_CALLBACK(0),
m_iUSE_ON_UNIT_SET_XY_CALLBACK(0),
m_iUSE_ON_UNIT_SELECTED_CALLBACK(0),
m_iUSE_ON_MISSIONARY_CONVERTED_UNIT_CALLBACK(0),
m_iUSE_ON_UPDATE_CALLBACK(0),
m_iUSE_ON_UNIT_CREATED_CALLBACK(0),
m_iUSE_ON_UNIT_LOST_CALLBACK(0),

// cache XML - start - Nightinggale
m_cache_ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES(0),
m_cache_ADVANCED_START_CITY_COST(0),
m_cache_ADVANCED_START_CITY_COST_INCREASE(0),
m_cache_ADVANCED_START_CITY_PLACEMENT_MAX_RANGE(0),
m_cache_ADVANCED_START_CULTURE_COST(0),
m_cache_ADVANCED_START_MAX_UNITS_PER_CITY(0),
m_cache_ADVANCED_START_POPULATION_COST(0),
m_cache_ADVANCED_START_POPULATION_COST_INCREASE(0),
m_cache_ADVANCED_START_SIGHT_RANGE(0),
m_cache_ADVANCED_START_VISIBILITY_COST(0),
m_cache_ADVANCED_START_VISIBILITY_COST_INCREASE(0),
m_cache_AI_ADVANCED_TECH_START(0),
m_cache_AI_CAN_DISBAND_UNITS(0),
m_cache_AI_CHEAT_AUTO_BUY(0),
m_cache_AI_CHEAT_NEEDED_DEFENDERS(0),
m_cache_AI_CHEAT_SPICE(0),
m_cache_AI_CHEAT_SPICE_BUY(0),
m_cache_AI_CHEAT_SPICE_MULTIPLE(0),
m_cache_AI_FAVORED_TERRAIN_MOD(0),
m_cache_AI_HANDICAP_CASTLE(0),
m_cache_AI_HANDICAP_MOTTE(0),
m_cache_AI_MILITARY_PROFESSION_HACK(0),
m_cache_AI_WAREHOUSE_MOD(0),
m_cache_ALLIANCE_CULTURE_PERCENT_DENIAL(0),
m_cache_ALLIANCE_PACT_PEACE_DENIAL(0),
m_cache_ANIMAL_BANDITS_GUARD_GOODY_TIMER(0),
m_cache_AUTORESEARCH_ALL(0),
m_cache_BANQUET_YIELD_AMOUNT(0),
m_cache_BARBARIAN_CIVILIZATION(0),
m_cache_BARBARIAN_LEADER(0),
m_cache_BASE_CITY_GROWTH_THRESHOLD(0),
m_cache_BASE_CITY_LUXURY_FOOD_THRESHOLD_MOD(0),
m_cache_BASE_OCCUPATION_TURNS(0),
m_cache_BASE_UNIT_UPGRADE_COST(0),
m_cache_BUILDINGCLASS_TRAVEL_TO_FAIR(0),
m_cache_BUILDING_PRODUCTION_DECAY_PERCENT(0),
m_cache_BUILDING_PRODUCTION_DECAY_TIME(0),
m_cache_BUILDING_PRODUCTION_PERCENT(0),
m_cache_BUY_PLOT_BASE_CULTURE_COST(0),
m_cache_BUY_PLOT_CULTURE_RANGE(0),
m_cache_BUY_PLOT_MIN_CULTURE(0),
m_cache_BUY_PLOT_OWNED_COST_MODIFIER(0),
m_cache_BUY_PLOT_SELLER_INCOME_PERCENT(0),
m_cache_CALENDER_YEAR_FIRST_CHANGE_TURN(0),
m_cache_CALENDER_YEAR_FIRST_MULTIPLIER(0),
m_cache_CALENDER_YEAR_SECOND_CHANGE_TURN(0),
m_cache_CALENDER_YEAR_SECOND_MULTIPLIER(0),
m_cache_CALENDER_YEAR_THIRD_MULTIPLIER(0),
m_cache_CAPITAL_BUILDINGCLASS(0),
m_cache_CAPTURED_CARGO_RANDOM_AMOUNT(0),
m_cache_CAPTURED_LUXURY_FOOD_RANDOM_AMOUNT(0),
m_cache_CASTLES_TO_VILLAGES_RATIO(0),
m_cache_CHANCE_TO_CAPTURE_CRIMINALS(0),
m_cache_CHEAT_TRAVEL_ALL(0),
m_cache_CITY_DEFENSE_DAMAGE_HEAL_RATE(0),
m_cache_CITY_FREE_CULTURE_GROWTH_FACTOR(0),
m_cache_CITY_GROWTH_MULTIPLIER(0),
m_cache_CITY_HEAL_RATE(0),
m_cache_CITY_PILGRAM_RANDOM(0),
m_cache_CITY_SCREEN_FOG_ENABLED(0),
m_cache_CITY_YIELD_CAPACITY(0),
m_cache_CITY_YIELD_DECAY_PERCENT(0),
m_cache_CIVICOPTION_INVENTIONS(0),
m_cache_COLONIAL_FORCED_PEACE_TURNS(0),
m_cache_COMBAT_DAMAGE(0),
m_cache_COMBAT_DIE_SIDES(0),
m_cache_COMBAT_EXPERIENCE_IN_BORDERS_PERCENT(0),
m_cache_CONSUME_EQUIPMENT_ON_FOUND(0),
m_cache_CONTACT_YIELD_GIFT_ENCOMEIDA_TIMER(0),
m_cache_CONTACT_YIELD_GIFT_TECH(0),
m_cache_CULTURE_YIELD(0),
m_cache_DEAL_TRADE_RELATIONS_POINTS(0),
m_cache_DEEP_WATER_TERRAIN(0),
m_cache_DEFAULT_BUILD_CASTLE(0),
m_cache_DEFAULT_BUILD_MOTTE_AND_BAILEY(0),
m_cache_DEFAULT_CENSURETYPE_ANATHEMA(0),
m_cache_DEFAULT_CENSURETYPE_ANATHEMA_COUNT(0),
m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION(0),
m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION_COUNT(0),
m_cache_DEFAULT_CENSURETYPE_INTERDICT(0),
m_cache_DEFAULT_CENSURETYPE_INTERDICT_COUNT(0),
m_cache_DEFAULT_COMBAT_FOR_TRAINING(0),
m_cache_DEFAULT_DAWN_POPULATION_UNIT(0),
m_cache_DEFAULT_FUEDALISM_TECH(0),
m_cache_DEFAULT_GRAIN_GROWTH_UNIT_CLASS(0),
m_cache_DEFAULT_HUNTSMAN_PROFESSION(0),
m_cache_DEFAULT_INVENTOR_CLASS(0),
m_cache_DEFAULT_KNIGHT_PROFESSION_PROMOTION(0),
m_cache_DEFAULT_KNIGHT_PROMOTION(0),
m_cache_DEFAULT_MARAUDER_CLASS(0),
m_cache_DEFAULT_MARUADER_SEA_PROFESSION(0),
m_cache_DEFAULT_NOBLEMAN_CLASS(0),
m_cache_DEFAULT_NOBLE_GROWTH_UNIT_CLASS(0),
m_cache_DEFAULT_PILGRAM_CLASS(0),
m_cache_DEFAULT_POPULATION_UNIT(0),
m_cache_DEFAULT_SHRINE_CLASS(0),
m_cache_DEFAULT_SLAVE_CLASS(0),
m_cache_DEFAULT_SPECIALBUILDING_COURTHOUSE(0),
m_cache_DEFAULT_TEST_DEFINE(0),
m_cache_DEFAULT_TRAINED_PROMOTION(0),
m_cache_DEFAULT_TREASURE_YIELD(0),
m_cache_DEFAULT_UNTRAINED_PROMOTION(0),
m_cache_DEFAULT_VIKING_ERA(0),
m_cache_DEFAULT_YIELD_ARMOR_TYPE(0),
m_cache_DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT(0),
m_cache_DIPLOMACY_VALUE_REMAINDER(0),
m_cache_DOCKS_NEXT_UNITS(0),
m_cache_EDUCATION_BASE_TUITION(0),
m_cache_EDUCATION_THRESHOLD(0),
m_cache_EDUCATION_THRESHOLD_INCREASE(0),
m_cache_ENABLE_ALLIANCE_TRADING(0),
m_cache_ENABLE_DEFENSIVE_PACT_TRADING(0),
m_cache_ENABLE_GOLD_TRADING(0),
m_cache_ENABLE_MAP_TRADING(0),
m_cache_ENABLE_OPEN_BORDERS(0),
m_cache_END_GAME_DISPLAY_WARNING(0),
m_cache_ENEMY_HEAL_RATE(0),
m_cache_ESTABLISH_TRADEPOST_COST(0),
m_cache_EUROPE_EAST(0),
m_cache_EUROPE_MARKET_CORRELATION_PERCENT(0),
m_cache_EVENT_PROBABILITY_ROLL_SIDES(0),
m_cache_EXPERIENCE_FROM_WITHDRAWL(0),
m_cache_EXTRA_YIELD(0),
m_cache_FATHER_COST_EXTRA_TEAM_MEMBER_MODIFIER(0),
m_cache_FATHER_POINT_REAL_TRADE(0),
m_cache_FEATURE_PRODUCTION_YIELD_MAX_DISTANCE(0),
m_cache_FIRST_EVENT_DELAY_TURNS(0),
m_cache_FOUND_MONASTERY_NUMBER(0),
m_cache_FOUND_MOTTE_AND_BAILEY_NUMBER(0),
m_cache_FOUND_OUTPOST_NUMBER(0),
m_cache_FOUND_VILLAGE_NUMBER(0),
m_cache_FREE_CITY_ADJACENT_CULTURE(0),
m_cache_FREE_CITY_CULTURE(0),
m_cache_FREE_PEASANT_CIVIC(0),
m_cache_FRIENDLY_HEAL_RATE(0),
m_cache_GREAT_GENERALS_THRESHOLD(0),
m_cache_GREAT_GENERALS_THRESHOLD_INCREASE(0),
m_cache_GREAT_GENERALS_THRESHOLD_INCREASE_TEAM(0),
m_cache_HIRE_GUARD_COST(0),
m_cache_HIRE_GUARD_PROMOTION(0),
m_cache_IMMIGRATION_MAX_CITY_DISTANCE(0),
m_cache_IMMIGRATION_THRESHOLD(0),
m_cache_IMMIGRATION_THRESHOLD_INCREASE(0),
m_cache_IMMIGRATION_TRAVEL_MOD(0),
m_cache_INDUSTRIAL_VICTORY_SINGLE_YIELD(0),
m_cache_INITIAL_AI_CITY_PRODUCTION(0),
m_cache_INITIAL_CITY_POPULATION(0),
m_cache_INITIAL_CITY_ROUTE_TYPE(0),
m_cache_JUNGLE_FEATURE(0),
m_cache_KING_BUY_UNIT_PRICE_MODIFIER(0),
m_cache_KING_INITIAL_UNIT_INCREASE(0),
m_cache_KING_TRANSPORT_TREASURE_COMISSION(0),
m_cache_KNIGHT_RANSOM_MOD(0),
m_cache_LAKE_PLOT_RAND(0),
m_cache_LAND_IMPROVEMENT(0),
m_cache_LAND_TERRAIN(0),
m_cache_MARAUDERS_DAYSOUT_RANDOM(0),
m_cache_MARAUDERS_TOWER_RANGE(0),
m_cache_MARAUDER_CRUMBS_EVENT(0),
m_cache_MARAUDER_EVENT_DEFAULT_TURNS(0),
m_cache_MAX_CITY_POPULATION_COMMUNE(0),
m_cache_MAX_CITY_POPULATION_VILLAGE(0),
m_cache_MAX_EXPERIENCE_AFTER_UPGRADE(0),
m_cache_MAX_EXPERIENCE_PER_COMBAT(0),
m_cache_MAX_FORTIFY_TURNS(0),
m_cache_MAX_INSULT_MODIFIER(0),
m_cache_MAX_LEVEL_FROM_ANIMAL_XP(0),
m_cache_MAX_MARAUDERS(0),
m_cache_MAX_NUM_LANGUAGES(0),
m_cache_MAX_PLOT_LIST_SIZE(0),
m_cache_MAX_REBEL_COMBAT_MULTIPLER(0),
m_cache_MAX_TRAINED_EXPERIENCE(0),
m_cache_MAX_WITHDRAWAL_PROBABILITY(0),
m_cache_MEDIEVAL_CENSURE(0),
m_cache_MEDIEVAL_TRADE_TECH(0),
m_cache_MINIMAP_RENDER_SIZE(0),
m_cache_MIN_ANIMAL_STARTING_DISTANCE(0),
m_cache_MIN_CITY_YIELD_DECAY(0),
m_cache_MIN_CIV_STARTING_DISTANCE(0),
m_cache_MIN_EXPERIENCE_PER_COMBAT(0),
m_cache_MIN_TIMER_UNIT_DOUBLE_MOVES(0),
m_cache_MIN_WATER_SIZE_FOR_OCEAN(0),
m_cache_MISSIONARY_RATE_EFFECT_ON_SUCCESS(0),
m_cache_MISSIONARY_THRESHOLD(0),
m_cache_MISSIONARY_THRESHOLD_INCREASE(0),
m_cache_MONASTERIES_TO_VILLAGES_RATIO(0),
m_cache_NATIVE_AUTO_SELL_PERCENT(0),
m_cache_NATIVE_GOODS_RAID_PERCENT(0),
m_cache_NATIVE_GROWTH_THRESHOLD_MULTIPLIER(0),
m_cache_NATIVE_HORSES_FOR_SALE(0),
m_cache_NATIVE_HORSES_FOR_SALE_PERCENT(0),
m_cache_NATIVE_TEACH_THRESHOLD_INCREASE(0),
m_cache_NATIVE_TECH(0),
m_cache_NATIVE_TRADING_TRADEPOST(0),
m_cache_NEUTRAL_HEAL_RATE(0),
m_cache_NEW_CITY_BUILDING_VALUE_MODIFIER(0),
m_cache_NEW_HURRY_MODIFIER(0),
m_cache_NOBLE_FIELD_LABOR_PENALTY(0),
m_cache_NO_BAD_GOODIES_EXPERIENCE_PERCENT(0),
m_cache_NO_BAD_GOODIES_GOLD_PERCENT(0),
m_cache_NO_CITY_SHORTAGE_MESSAGES(0),
m_cache_NO_STARTING_PLOTS_IN_JUNGLE(0),
m_cache_OCCUPATION_CULTURE_PERCENT_THRESHOLD(0),
m_cache_OCCUPATION_TURNS_POPULATION_PERCENT(0),
m_cache_OWNERSHIP_SCORE_DURATION_THRESHOLD(0),
m_cache_OWN_TEAM_STARTING_MODIFIER(0),
m_cache_PEACE_TREATY_LENGTH(0),
m_cache_PERCENT_TAX_ON_AUTOSELL_GOODS(0),
m_cache_PILGRAM_OFFER_GOLD(0),
m_cache_PILGRAM_OFFER_GOLD_DISTANCE_MOD(0),
m_cache_PLAYER_ALWAYS_RAZES_CITIES(0),
m_cache_PLOTS_PER_RIVER_EDGE(0),
m_cache_PLOT_VISIBILITY_RANGE(0),
m_cache_PROFESSION_COAL_BURNER(0),
m_cache_PROFESSION_INVENTOR(0),
m_cache_PROLIFIC_INVENTOR_THRESHOLD_INCREASE(0),
m_cache_PROMOTION_BUILD_HOME(0),
m_cache_RANDOM_TURNS_LOST_AT_SEA(0),
m_cache_RAZING_CULTURAL_PERCENT_THRESHOLD(0),
m_cache_REBEL_PERCENT_FOR_REVOLUTION(0),
m_cache_REBEL_SENTIMENT_BELLS_FACTOR(0),
m_cache_REBEL_SENTIMENT_TURN_WEIGHT(0),
m_cache_REVOLUTION_EUROPE_UNIT_SHIP_MODIFIER(0),
m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD(0),
m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD_INCREASE(0),
m_cache_RIVAL_TEAM_STARTING_MODIFIER(0),
m_cache_RIVER_SOURCE_MIN_RIVER_RANGE(0),
m_cache_RIVER_SOURCE_MIN_SEAWATER_RANGE(0),
m_cache_RUINS_IMPROVEMENT(0),
m_cache_SCORE_FATHER_FACTOR(0),
m_cache_SCORE_LAND_FACTOR(0),
m_cache_SCORE_POPULATION_FACTOR(0),
m_cache_SCORE_TAX_FACTOR(0),
m_cache_SETTLEMENT_TREASURE_YIELD(0),
m_cache_SHALLOW_WATER_TERRAIN(0),
m_cache_SLAVE_FOOD_CONSUMPTION_PER_POPULATION(0),
m_cache_STANDARD_CALENDAR(0),
m_cache_STANDARD_CLIMATE(0),
m_cache_STANDARD_ERA(0),
m_cache_STANDARD_GAMESPEED(0),
m_cache_STANDARD_HANDICAP(0),
m_cache_STANDARD_SEALEVEL(0),
m_cache_STANDARD_TURNTIMER(0),
m_cache_STARTING_DISTANCE_PERCENT(0),
m_cache_START_YEAR(0),
m_cache_STEAMWORKS_BUILDING(0),
m_cache_STEAMWORKS_CLASS_TYPE(0),
m_cache_TAX_INCREASE_CHANCE(0),
m_cache_TAX_RATE_MAX_INCREASE(0),
m_cache_TAX_TRADE_THRESHOLD(0),
m_cache_TAX_TRADE_THRESHOLD_ATTITUDE_PERCENT(0),
m_cache_TAX_TRADE_THRESHOLD_TAX_RATE_PERCENT(0),
m_cache_TK_AI_RESEARCH_COST_MOD_PERCENT(0),
m_cache_TK_HUMAN_RESEARCH_COST_MOD_PERCENT(0),
m_cache_TK_IDEAS_CITY_VALUE(0),
m_cache_TK_MAX_FORTS_PER_CITY(0),
m_cache_TK_PIONEER_COAL_FURNACE_BONUS(0),
m_cache_TK_PROLIFIC_INVENTOR_PROGRESS(0),
m_cache_TK_PROLIFIC_INVENTOR_THRESHOLD(0),
m_cache_TK_RESEARCH_PACT_IDEAS_THRESHOLD(0),
m_cache_TK_RESEARCH_TRADE_VALUE(0),
m_cache_TK_STEAMWORKS_MODIFIER(0),
m_cache_TRADE_POINTS_FOR_ROUTE(0),
m_cache_TRADE_ROUTE_SPICE(0),
m_cache_TRADE_STIMULATES_RESEARCH_MIN_VALUE(0),
m_cache_TRADE_STIMULATES_RESEARCH_PERCENT(0),
m_cache_TRADING_POINTS_MOD_PERCENT(0),
m_cache_TREASURE_UNITCLASS(0),
m_cache_TREASURE_UNITS_ONLY_SELECT_COASTAL(0),
m_cache_TURNS_TO_TRAIN(0),
m_cache_UNITARMOR_LEATHER(0),
m_cache_UNITARMOR_MAIL(0),
m_cache_UNITARMOR_PLATE(0),
m_cache_UNITARMOR_SCALE(0),
m_cache_UNITARMOR_SHIELD(0),
m_cache_UNITCLASS_PIONEER(0),
m_cache_UNITTACTIC_PARRY(0),
m_cache_UNITWEAPON_BLUNT(0),
m_cache_UNIT_PRODUCTION_DECAY_PERCENT(0),
m_cache_UNIT_PRODUCTION_DECAY_TIME(0),
m_cache_UNIT_PRODUCTION_PERCENT(0),
m_cache_UNIT_UPGRADE_COST_PER_PRODUCTION(0),
m_cache_UNIT_VISIBILITY_RANGE(0),
m_cache_USE_MEDIEVAL_CALENDER(0),
m_cache_VASSAL_CIVILIZATION(0),
m_cache_VASSAL_LEADER(0),
m_cache_WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT(0),
m_cache_WAR_SUCCESS_ATTACKING(0),
m_cache_WAR_SUCCESS_CITY_CAPTURING(0),
m_cache_WAR_SUCCESS_DEFENDING(0),
m_cache_WAR_SUCCESS_UNIT_CAPTURING(0),
m_cache_WATER_IMPROVEMENT(0),
m_cache_WATER_UNIT_FACING_DIRECTION(0),
m_cache_WEEKS_PER_MONTHS(0),
m_cache_WILD_ANIMAL_ATTACK_WEIGHT(0),
m_cache_WILD_ANIMAL_LAND_BONUS_NATIVE_WEIGHT(0),
m_cache_WILD_ANIMAL_LAND_FEATURE_NATIVE_WEIGHT(0),
m_cache_WILD_ANIMAL_LAND_PATROL_BASE_WEIGHT(0),
m_cache_WILD_ANIMAL_LAND_TERRAIN_NATIVE_WEIGHT(0),
m_cache_WILD_ANIMAL_LAND_UNIT_VARIATION_WEIGHT(0),
m_cache_WILD_ANIMAL_SEA_BONUS_NATIVE_WEIGHT(0),
m_cache_WILD_ANIMAL_SEA_FEATURE_NATIVE_WEIGHT(0),
m_cache_WILD_ANIMAL_SEA_PATROL_BASE_WEIGHT(0),
m_cache_WILD_ANIMAL_SEA_TERRAIN_NATIVE_WEIGHT(0),
m_cache_WILD_ANIMAL_SEA_UNIT_VARIATION_WEIGHT(0),
// cache XML - end - Nightinggale

m_paHints(NULL),
m_paMainMenus(NULL)
{
}

CvGlobals::~CvGlobals()
{
}

//
// allocate
//
void CvGlobals::init()
{
	//
	// These vars are used to initialize the globals.
	//

	int aiPlotDirectionX[NUM_DIRECTION_TYPES] =
	{
		0,	// DIRECTION_NORTH
		1,	// DIRECTION_NORTHEAST
		1,	// DIRECTION_EAST
		1,	// DIRECTION_SOUTHEAST
		0,	// DIRECTION_SOUTH
		-1,	// DIRECTION_SOUTHWEST
		-1,	// DIRECTION_WEST
		-1,	// DIRECTION_NORTHWEST
	};

	int aiPlotDirectionY[NUM_DIRECTION_TYPES] =
	{
		1,	// DIRECTION_NORTH
		1,	// DIRECTION_NORTHEAST
		0,	// DIRECTION_EAST
		-1,	// DIRECTION_SOUTHEAST
		-1,	// DIRECTION_SOUTH
		-1,	// DIRECTION_SOUTHWEST
		0,	// DIRECTION_WEST
		1,	// DIRECTION_NORTHWEST
	};

	int aiPlotCardinalDirectionX[NUM_CARDINALDIRECTION_TYPES] =
	{
		0,	// CARDINALDIRECTION_NORTH
		1,	// CARDINALDIRECTION_EAST
		0,	// CARDINALDIRECTION_SOUTH
		-1,	// CARDINALDIRECTION_WEST
	};

	int aiPlotCardinalDirectionY[NUM_CARDINALDIRECTION_TYPES] =
	{
		1,	// CARDINALDIRECTION_NORTH
		0,	// CARDINALDIRECTION_EAST
		-1,	// CARDINALDIRECTION_SOUTH
		0,	// CARDINALDIRECTION_WEST
	};

	int aiCityPlotX[NUM_CITY_PLOTS] =
	{
		0,
		0, 1, 1, 1, 0,-1,-1,-1,
//		0, 1, 2, 2, 2, 1, 0,-1,-2,-2,-2,-1,
	};

	int aiCityPlotY[NUM_CITY_PLOTS] =
	{
		0,
		1, 1, 0,-1,-1,-1, 0, 1,
//		2, 2, 1, 0,-1,-2,-2,-2,-1, 0, 1, 2,
	};

	int aiCityPlotPriority[NUM_CITY_PLOTS] =
	{
		0,
		1, 2, 1, 2, 1, 2, 1, 2,
//		3, 4, 4, 3, 4, 4, 3, 4, 4, 3, 4, 4,
	};

	int aaiXYCityPlot[CITY_PLOTS_DIAMETER][CITY_PLOTS_DIAMETER] =
	{
		{6, 7, 8,},

		{5, 0, 1,},

		{4, 3, 2,}
	};

	DirectionTypes aeTurnRightDirection[NUM_DIRECTION_TYPES] =
	{
		DIRECTION_NORTHEAST,	// DIRECTION_NORTH
		DIRECTION_EAST,				// DIRECTION_NORTHEAST
		DIRECTION_SOUTHEAST,	// DIRECTION_EAST
		DIRECTION_SOUTH,			// DIRECTION_SOUTHEAST
		DIRECTION_SOUTHWEST,	// DIRECTION_SOUTH
		DIRECTION_WEST,				// DIRECTION_SOUTHWEST
		DIRECTION_NORTHWEST,	// DIRECTION_WEST
		DIRECTION_NORTH,			// DIRECTION_NORTHWEST
	};

	DirectionTypes aeTurnLeftDirection[NUM_DIRECTION_TYPES] =
	{
		DIRECTION_NORTHWEST,	// DIRECTION_NORTH
		DIRECTION_NORTH,			// DIRECTION_NORTHEAST
		DIRECTION_NORTHEAST,	// DIRECTION_EAST
		DIRECTION_EAST,				// DIRECTION_SOUTHEAST
		DIRECTION_SOUTHEAST,	// DIRECTION_SOUTH
		DIRECTION_SOUTH,			// DIRECTION_SOUTHWEST
		DIRECTION_SOUTHWEST,	// DIRECTION_WEST
		DIRECTION_WEST,				// DIRECTION_NORTHWEST
	};

	DirectionTypes aaeXYDirection[DIRECTION_DIAMETER][DIRECTION_DIAMETER] =
	{
		DIRECTION_SOUTHWEST, DIRECTION_WEST,	DIRECTION_NORTHWEST,
		DIRECTION_SOUTH,     NO_DIRECTION,    DIRECTION_NORTH,
		DIRECTION_SOUTHEAST, DIRECTION_EAST,	DIRECTION_NORTHEAST,
	};

	FAssertMsg(gDLL != NULL, "Civ app needs to set gDLL");

	m_VarSystem = new FVariableSystem;
	m_asyncRand = new CvRandom;
	m_initCore = new CvInitCore;
	m_loadedInitCore = new CvInitCore;
	m_iniInitCore = new CvInitCore;

	gDLL->initGlobals();	// some globals need to be allocated outside the dll

	m_game = new CvGameAI;
	m_map = new CvMap;

	CvPlayerAI::initStatics();
	CvTeamAI::initStatics();

	m_pt3Origin = NiPoint3(0.0f, 0.0f, 0.0f);

	COPY(m_aiPlotDirectionX, aiPlotDirectionX, int);
	COPY(m_aiPlotDirectionY, aiPlotDirectionY, int);
	COPY(m_aiPlotCardinalDirectionX, aiPlotCardinalDirectionX, int);
	COPY(m_aiPlotCardinalDirectionY, aiPlotCardinalDirectionY, int);
	COPY(m_aiCityPlotX, aiCityPlotX, int);
	COPY(m_aiCityPlotY, aiCityPlotY, int);
	COPY(m_aiCityPlotPriority, aiCityPlotPriority, int);
	COPY(m_aeTurnLeftDirection, aeTurnLeftDirection, DirectionTypes);
	COPY(m_aeTurnRightDirection, aeTurnRightDirection, DirectionTypes);
	memcpy(m_aaiXYCityPlot, aaiXYCityPlot, sizeof(m_aaiXYCityPlot));
	memcpy(m_aaeXYDirection, aaeXYDirection,sizeof(m_aaeXYDirection));
}

//
// free
//
void CvGlobals::uninit()
{
	//
	// See also CvXMLLoadUtilityInit.cpp::CleanUpGlobalVariables()
	//
	SAFE_DELETE_ARRAY(m_aiPlotDirectionX);
	SAFE_DELETE_ARRAY(m_aiPlotDirectionY);
	SAFE_DELETE_ARRAY(m_aiPlotCardinalDirectionX);
	SAFE_DELETE_ARRAY(m_aiPlotCardinalDirectionY);
	SAFE_DELETE_ARRAY(m_aiCityPlotX);
	SAFE_DELETE_ARRAY(m_aiCityPlotY);
	SAFE_DELETE_ARRAY(m_aiCityPlotPriority);
	SAFE_DELETE_ARRAY(m_aeTurnLeftDirection);
	SAFE_DELETE_ARRAY(m_aeTurnRightDirection);

	CvPlayerAI::freeStatics();
	CvTeamAI::freeStatics();

	SAFE_DELETE(m_game);
	SAFE_DELETE(m_map);

	SAFE_DELETE(m_asyncRand);
	SAFE_DELETE(m_initCore);
	SAFE_DELETE(m_loadedInitCore);
	SAFE_DELETE(m_iniInitCore);
	gDLL->uninitGlobals();	// free globals allocated outside the dll
	SAFE_DELETE(m_VarSystem);

	// already deleted outside of the dll, set to null for safety
	m_messageQueue=NULL;
	m_hotJoinMsgQueue=NULL;
	m_messageControl=NULL;
	m_setupData=NULL;
	m_messageCodes=NULL;
	m_dropMgr=NULL;
	m_portal=NULL;
	m_statsReporter=NULL;
	m_interface=NULL;
	m_diplomacyScreen=NULL;
	m_mpDiplomacyScreen=NULL;
	m_pathFinder=NULL;
	m_interfacePathFinder=NULL;
	m_stepFinder=NULL;
	m_routeFinder=NULL;
	m_borderFinder=NULL;
	m_areaFinder=NULL;

	deleteInfoArrays();
}

void CvGlobals::clearTypesMap()
{
	infoTypeFromStringReset();
	if (m_VarSystem)
	{
		m_VarSystem->UnInit();
	}
}


CvDiplomacyScreen* CvGlobals::getDiplomacyScreen()
{
	return m_diplomacyScreen;
}

CMPDiplomacyScreen* CvGlobals::getMPDiplomacyScreen()
{
	return m_mpDiplomacyScreen;
}

CvMessageCodeTranslator& CvGlobals::getMessageCodes()
{
	return *m_messageCodes;
}

FMPIManager*& CvGlobals::getFMPMgrPtr()
{
	return m_pFMPMgr;
}

CvPortal& CvGlobals::getPortal()
{
	return *m_portal;
}

CvSetupData& CvGlobals::getSetupData()
{
	return *m_setupData;
}

CvInitCore& CvGlobals::getInitCore()
{
	return *m_initCore;
}

CvInitCore& CvGlobals::getLoadedInitCore()
{
	return *m_loadedInitCore;
}

CvInitCore& CvGlobals::getIniInitCore()
{
	return *m_iniInitCore;
}

CvStatsReporter& CvGlobals::getStatsReporter()
{
	return *m_statsReporter;
}

CvStatsReporter* CvGlobals::getStatsReporterPtr()
{
	return m_statsReporter;
}

CvInterface& CvGlobals::getInterface()
{
	return *m_interface;
}

CvInterface* CvGlobals::getInterfacePtr()
{
	return m_interface;
}

CvRandom& CvGlobals::getASyncRand()
{
	return *m_asyncRand;
}

CMessageQueue& CvGlobals::getMessageQueue()
{
	return *m_messageQueue;
}

CMessageQueue& CvGlobals::getHotMessageQueue()
{
	return *m_hotJoinMsgQueue;
}

CMessageControl& CvGlobals::getMessageControl()
{
	return *m_messageControl;
}

CvDropMgr& CvGlobals::getDropMgr()
{
	return *m_dropMgr;
}

FAStar& CvGlobals::getPathFinder()
{
	return *m_pathFinder;
}

FAStar& CvGlobals::getInterfacePathFinder()
{
	return *m_interfacePathFinder;
}

FAStar& CvGlobals::getStepFinder()
{
	return *m_stepFinder;
}

FAStar& CvGlobals::getRouteFinder()
{
	return *m_routeFinder;
}

FAStar& CvGlobals::getBorderFinder()
{
	return *m_borderFinder;
}

FAStar& CvGlobals::getAreaFinder()
{
	return *m_areaFinder;
}

NiPoint3& CvGlobals::getPt3Origin()
{
	return m_pt3Origin;
}

std::vector<CvInterfaceModeInfo*>& CvGlobals::getInterfaceModeInfo()		// For Moose - XML Load Util and CvInfos
{
	return m_paInterfaceModeInfo;
}

CvInterfaceModeInfo& CvGlobals::getInterfaceModeInfo(InterfaceModeTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_INTERFACEMODE_TYPES);
	return *(m_paInterfaceModeInfo[e]);
}

NiPoint3& CvGlobals::getPt3CameraDir()
{
	return m_pt3CameraDir;
}

bool& CvGlobals::getLogging()
{
	return m_bLogging;
}

bool& CvGlobals::getRandLogging()
{
	return m_bRandLogging;
}

bool& CvGlobals::getSynchLogging()
{
	return m_bSynchLogging;
}

bool& CvGlobals::overwriteLogs()
{
	return m_bOverwriteLogs;
}

int* CvGlobals::getPlotDirectionX()
{
	return m_aiPlotDirectionX;
}

int* CvGlobals::getPlotDirectionY()
{
	return m_aiPlotDirectionY;
}

int* CvGlobals::getPlotCardinalDirectionX()
{
	return m_aiPlotCardinalDirectionX;
}

int* CvGlobals::getPlotCardinalDirectionY()
{
	return m_aiPlotCardinalDirectionY;
}

int* CvGlobals::getCityPlotX()
{
	return m_aiCityPlotX;
}

int* CvGlobals::getCityPlotY()
{
	return m_aiCityPlotY;
}

int* CvGlobals::getCityPlotPriority()
{
	return m_aiCityPlotPriority;
}

int CvGlobals::getXYCityPlot(int i, int j)
{
	FAssertMsg(i < CITY_PLOTS_DIAMETER, "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	FAssertMsg(j < CITY_PLOTS_DIAMETER, "Index out of bounds");
	FAssertMsg(j > -1, "Index out of bounds");
	return m_aaiXYCityPlot[i][j];
}

DirectionTypes* CvGlobals::getTurnLeftDirection()
{
	return m_aeTurnLeftDirection;
}

DirectionTypes CvGlobals::getTurnLeftDirection(int i)
{
	FAssertMsg(i < NUM_DIRECTION_TYPES, "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	return m_aeTurnLeftDirection[i];
}

DirectionTypes* CvGlobals::getTurnRightDirection()
{
	return m_aeTurnRightDirection;
}

DirectionTypes CvGlobals::getTurnRightDirection(int i)
{
	FAssertMsg(i < NUM_DIRECTION_TYPES, "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	return m_aeTurnRightDirection[i];
}

DirectionTypes CvGlobals::getXYDirection(int i, int j)
{
	FAssertMsg(i < DIRECTION_DIAMETER, "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	FAssertMsg(j < DIRECTION_DIAMETER, "Index out of bounds");
	FAssertMsg(j > -1, "Index out of bounds");
	return m_aaeXYDirection[i][j];
}

int CvGlobals::getNumWorldInfos()
{
	return (int)m_paWorldInfo.size();
}

std::vector<CvWorldInfo*>& CvGlobals::getWorldInfo()
{
	return m_paWorldInfo;
}

CvWorldInfo& CvGlobals::getWorldInfo(WorldSizeTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumWorldInfos());
	return *(m_paWorldInfo[e]);
}

/////////////////////////////////////////////
// CLIMATE
/////////////////////////////////////////////

int CvGlobals::getNumClimateInfos()
{
	return (int)m_paClimateInfo.size();
}

std::vector<CvClimateInfo*>& CvGlobals::getClimateInfo()
{
	return m_paClimateInfo;
}

CvClimateInfo& CvGlobals::getClimateInfo(ClimateTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumClimateInfos());
	return *(m_paClimateInfo[e]);
}

/////////////////////////////////////////////
// SEALEVEL
/////////////////////////////////////////////

int CvGlobals::getNumSeaLevelInfos()
{
	return (int)m_paSeaLevelInfo.size();
}

std::vector<CvSeaLevelInfo*>& CvGlobals::getSeaLevelInfo()
{
	return m_paSeaLevelInfo;
}

CvSeaLevelInfo& CvGlobals::getSeaLevelInfo(SeaLevelTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumSeaLevelInfos());
	return *(m_paSeaLevelInfo[e]);
}

/////////////////////////////////////////////
// EUROPE
/////////////////////////////////////////////

int CvGlobals::getNumEuropeInfos()
{
	return (int)m_paEuropeInfo.size();
}

std::vector<CvEuropeInfo*>& CvGlobals::getEuropeInfo()
{
	return m_paEuropeInfo;
}

CvEuropeInfo& CvGlobals::getEuropeInfo(EuropeTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumEuropeInfos());
	return *(m_paEuropeInfo[e]);
}

int CvGlobals::getNumHints()
{
	return (int)m_paHints.size();
}

std::vector<CvInfoBase*>& CvGlobals::getHints()
{
	return m_paHints;
}

CvInfoBase& CvGlobals::getHints(int i)
{
	return *(m_paHints[i]);
}

int CvGlobals::getNumMainMenus()
{
	return (int)m_paMainMenus.size();
}

std::vector<CvMainMenuInfo*>& CvGlobals::getMainMenus()
{
	return m_paMainMenus;
}

CvMainMenuInfo& CvGlobals::getMainMenus(int i)
{
	if (i >= getNumMainMenus())
	{
		return *(m_paMainMenus[0]);
	}

	return *(m_paMainMenus[i]);
}

int CvGlobals::getNumColorInfos()
{
	return (int)m_paColorInfo.size();
}

std::vector<CvColorInfo*>& CvGlobals::getColorInfo()
{
	return m_paColorInfo;
}

CvColorInfo& CvGlobals::getColorInfo(ColorTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumColorInfos());
	return *(m_paColorInfo[e]);
}


int CvGlobals::getNumPlayerColorInfos()
{
	return (int)m_paPlayerColorInfo.size();
}

std::vector<CvPlayerColorInfo*>& CvGlobals::getPlayerColorInfo()
{
	return m_paPlayerColorInfo;
}

CvPlayerColorInfo& CvGlobals::getPlayerColorInfo(PlayerColorTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumPlayerColorInfos());
	return *(m_paPlayerColorInfo[e]);
}

int CvGlobals::getNumRouteModelInfos()
{
	return (int)m_paRouteModelInfo.size();
}

std::vector<CvRouteModelInfo*>& CvGlobals::getRouteModelInfo()
{
	return m_paRouteModelInfo;
}

CvRouteModelInfo& CvGlobals::getRouteModelInfo(int i)
{
	FAssert(i > -1);
	FAssert(i < GC.getNumRouteModelInfos());
	return *(m_paRouteModelInfo[i]);
}

int CvGlobals::getNumRiverModelInfos()
{
	return (int)m_paRiverModelInfo.size();
}

std::vector<CvRiverModelInfo*>& CvGlobals::getRiverModelInfo()
{
	return m_paRiverModelInfo;
}

CvRiverModelInfo& CvGlobals::getRiverModelInfo(int i)
{
	FAssert(i > -1);
	FAssert(i < GC.getNumRiverModelInfos());
	return *(m_paRiverModelInfo[i]);
}

int CvGlobals::getNumWaterPlaneInfos()
{
	return (int)m_paWaterPlaneInfo.size();
}

std::vector<CvWaterPlaneInfo*>& CvGlobals::getWaterPlaneInfo()
{
	return m_paWaterPlaneInfo;
}

CvWaterPlaneInfo& CvGlobals::getWaterPlaneInfo(int i)
{
	FAssert(i > -1);
	FAssert(i < GC.getNumWaterPlaneInfos());
	return *(m_paWaterPlaneInfo[i]);
}

int CvGlobals::getNumTerrainPlaneInfos()
{
	return (int)m_paTerrainPlaneInfo.size();
}

std::vector<CvTerrainPlaneInfo*>& CvGlobals::getTerrainPlaneInfo()
{
	return m_paTerrainPlaneInfo;
}

CvTerrainPlaneInfo& CvGlobals::getTerrainPlaneInfo(int i)
{
	FAssert(i > -1);
	FAssert(i < GC.getNumTerrainPlaneInfos());
	return *(m_paTerrainPlaneInfo[i]);
}

int CvGlobals::getNumCameraOverlayInfos()
{
	return (int)m_paCameraOverlayInfo.size();
}

std::vector<CvCameraOverlayInfo*>& CvGlobals::getCameraOverlayInfo()
{
	return m_paCameraOverlayInfo;
}

CvCameraOverlayInfo& CvGlobals::getCameraOverlayInfo(int i)
{
	FAssert(i > -1);
	FAssert(i < GC.getNumCameraOverlayInfos());
	return *(m_paCameraOverlayInfo[i]);
}

int CvGlobals::getNumAnimationPathInfos()
{
	return (int)m_paAnimationPathInfo.size();
}

std::vector<CvAnimationPathInfo*>& CvGlobals::getAnimationPathInfo()
{
	return m_paAnimationPathInfo;
}

CvAnimationPathInfo& CvGlobals::getAnimationPathInfo(AnimationPathTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumAnimationPathInfos());
	return *(m_paAnimationPathInfo[e]);
}

int CvGlobals::getNumAnimationCategoryInfos()
{
	return (int)m_paAnimationCategoryInfo.size();
}

std::vector<CvAnimationCategoryInfo*>& CvGlobals::getAnimationCategoryInfo()
{
	return m_paAnimationCategoryInfo;
}

CvAnimationCategoryInfo& CvGlobals::getAnimationCategoryInfo(AnimationCategoryTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumAnimationCategoryInfos());
	return *(m_paAnimationCategoryInfo[e]);
}

int CvGlobals::getNumEntityEventInfos()
{
	return (int)m_paEntityEventInfo.size();
}

std::vector<CvEntityEventInfo*>& CvGlobals::getEntityEventInfo()
{
	return m_paEntityEventInfo;
}

CvEntityEventInfo& CvGlobals::getEntityEventInfo(EntityEventTypes e)
{
	FAssert( e > -1 );
	FAssert( e < GC.getNumEntityEventInfos() );
	return *(m_paEntityEventInfo[e]);
}

int CvGlobals::getNumEffectInfos()
{
	return (int)m_paEffectInfo.size();
}

std::vector<CvEffectInfo*>& CvGlobals::getEffectInfo()
{
	return m_paEffectInfo;
}

CvEffectInfo& CvGlobals::getEffectInfo(int i)
{
	FAssert(i > -1);
	FAssert(i < GC.getNumEffectInfos());
	return *(m_paEffectInfo[i]);
}


int CvGlobals::getNumAttachableInfos()
{
	return (int)m_paAttachableInfo.size();
}

std::vector<CvAttachableInfo*>& CvGlobals::getAttachableInfo()
{
	return m_paAttachableInfo;
}

CvAttachableInfo& CvGlobals::getAttachableInfo(int i)
{
	FAssert(i > -1);
	FAssert(i < GC.getNumAttachableInfos());
	return *(m_paAttachableInfo[i]);
}

int CvGlobals::getNumUnitFormationInfos()
{
	return (int)m_paUnitFormationInfo.size();
}

std::vector<CvUnitFormationInfo*>& CvGlobals::getUnitFormationInfo()		// For Moose - CvUnitEntity
{
	return m_paUnitFormationInfo;
}

CvUnitFormationInfo& CvGlobals::getUnitFormationInfo(int i)
{
	FAssert(i > -1);
	FAssert(i < GC.getNumUnitFormationInfos());
	return *(m_paUnitFormationInfo[i]);
}

// TEXT
int CvGlobals::getNumGameTextXML()
{
	return (int)m_paGameTextXML.size();
}

std::vector<CvGameText*>& CvGlobals::getGameTextXML()
{
	return m_paGameTextXML;
}

// Landscape INFOS
int CvGlobals::getNumLandscapeInfos()
{
	return (int)m_paLandscapeInfo.size();
}

std::vector<CvLandscapeInfo*>& CvGlobals::getLandscapeInfo()
{
	return m_paLandscapeInfo;
}

CvLandscapeInfo& CvGlobals::getLandscapeInfo(int iIndex)
{
	FAssert(iIndex > -1);
	FAssert(iIndex < GC.getNumLandscapeInfos());
	return *(m_paLandscapeInfo[iIndex]);
}

int CvGlobals::getActiveLandscapeID()
{
	return m_iActiveLandscapeID;
}

void CvGlobals::setActiveLandscapeID(int iLandscapeID)
{
	m_iActiveLandscapeID = iLandscapeID;
}


int CvGlobals::getNumTerrainInfos()
{
	return (int)m_paTerrainInfo.size();
}

std::vector<CvTerrainInfo*>& CvGlobals::getTerrainInfo()		// For Moose - XML Load Util, CvInfos, CvTerrainTypeWBPalette
{
	return m_paTerrainInfo;
}

CvTerrainInfo& CvGlobals::getTerrainInfo(TerrainTypes eTerrainNum)
{
	FAssert(eTerrainNum > -1);
	FAssert(eTerrainNum < (int)m_paTerrainInfo.size());
	return *(m_paTerrainInfo[eTerrainNum]);
}

int CvGlobals::getNumBonusInfos()
{
	return (int)m_paBonusInfo.size();
}

std::vector<CvBonusInfo*>& CvGlobals::getBonusInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paBonusInfo;
}

CvBonusInfo& CvGlobals::getBonusInfo(BonusTypes eBonusNum)
{
	FAssert(eBonusNum > -1);
	FAssert(eBonusNum < (int)m_paBonusInfo.size());
	return *(m_paBonusInfo[eBonusNum]);
}

int CvGlobals::getNumFeatureInfos()
{
	return (int)m_paFeatureInfo.size();
}

std::vector<CvFeatureInfo*>& CvGlobals::getFeatureInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paFeatureInfo;
}

CvFeatureInfo& CvGlobals::getFeatureInfo(FeatureTypes eFeatureNum)
{
	FAssert(eFeatureNum > -1);
	FAssert(eFeatureNum < (int)m_paFeatureInfo.size());
	return *(m_paFeatureInfo[eFeatureNum]);
}

int CvGlobals::getNumCivilizationInfos()
{
	return (int)m_paCivilizationInfo.size();
}

std::vector<CvCivilizationInfo*>& CvGlobals::getCivilizationInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paCivilizationInfo;
}

CvCivilizationInfo& CvGlobals::getCivilizationInfo(CivilizationTypes eCivilizationNum)
{
	FAssert(eCivilizationNum > -1);
	FAssert(eCivilizationNum < (int)m_paCivilizationInfo.size());
	return *(m_paCivilizationInfo[eCivilizationNum]);
}


int CvGlobals::getNumLeaderHeadInfos()
{
	return (int)m_paLeaderHeadInfo.size();
}

std::vector<CvLeaderHeadInfo*>& CvGlobals::getLeaderHeadInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paLeaderHeadInfo;
}

CvLeaderHeadInfo& CvGlobals::getLeaderHeadInfo(LeaderHeadTypes eLeaderHeadNum)
{
	FAssert(eLeaderHeadNum > -1);
	FAssert(eLeaderHeadNum < GC.getNumLeaderHeadInfos());
	return *(m_paLeaderHeadInfo[eLeaderHeadNum]);
}


int CvGlobals::getNumTraitInfos()
{
	return (int)m_paTraitInfo.size();
}

std::vector<CvTraitInfo*>& CvGlobals::getTraitInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paTraitInfo;
}

CvTraitInfo& CvGlobals::getTraitInfo(TraitTypes eTraitNum)
{
	FAssert(eTraitNum > -1);
	FAssert(eTraitNum < GC.getNumTraitInfos());
	return *(m_paTraitInfo[eTraitNum]);
}


int CvGlobals::getNumCursorInfos()
{
	return (int)m_paCursorInfo.size();
}

std::vector<CvCursorInfo*>& CvGlobals::getCursorInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paCursorInfo;
}

CvCursorInfo& CvGlobals::getCursorInfo(CursorTypes eCursorNum)
{
	FAssert(eCursorNum > -1);
	FAssert(eCursorNum < GC.getNumCursorInfos());
	return *(m_paCursorInfo[eCursorNum]);
}

int CvGlobals::getNumSlideShowInfos()
{
	return (int)m_paSlideShowInfo.size();
}

std::vector<CvSlideShowInfo*>& CvGlobals::getSlideShowInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paSlideShowInfo;
}

CvSlideShowInfo& CvGlobals::getSlideShowInfo(int iIndex)
{
	FAssert(iIndex > -1);
	FAssert(iIndex < GC.getNumSlideShowInfos());
	return *(m_paSlideShowInfo[iIndex]);
}

int CvGlobals::getNumSlideShowRandomInfos()
{
	return (int)m_paSlideShowRandomInfo.size();
}

std::vector<CvSlideShowRandomInfo*>& CvGlobals::getSlideShowRandomInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paSlideShowRandomInfo;
}

CvSlideShowRandomInfo& CvGlobals::getSlideShowRandomInfo(int iIndex)
{
	FAssert(iIndex > -1);
	FAssert(iIndex < GC.getNumSlideShowRandomInfos());
	return *(m_paSlideShowRandomInfo[iIndex]);
}

int CvGlobals::getNumWorldPickerInfos()
{
	return (int)m_paWorldPickerInfo.size();
}

std::vector<CvWorldPickerInfo*>& CvGlobals::getWorldPickerInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paWorldPickerInfo;
}

CvWorldPickerInfo& CvGlobals::getWorldPickerInfo(int iIndex)
{
	FAssert(iIndex > -1);
	FAssert(iIndex < GC.getNumWorldPickerInfos());
	return *(m_paWorldPickerInfo[iIndex]);
}

int CvGlobals::getNumUnitInfos()
{
	return (int)m_paUnitInfo.size();
}

std::vector<CvUnitInfo*>& CvGlobals::getUnitInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paUnitInfo;
}

CvUnitInfo& CvGlobals::getUnitInfo(UnitTypes eUnitNum)
{
	FAssert(eUnitNum > -1);
	FAssert(eUnitNum < GC.getNumUnitInfos());
	return *(m_paUnitInfo[eUnitNum]);
}

int CvGlobals::getNumSpecialUnitInfos()
{
	return (int)m_paSpecialUnitInfo.size();
}

std::vector<CvSpecialUnitInfo*>& CvGlobals::getSpecialUnitInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paSpecialUnitInfo;
}

CvSpecialUnitInfo& CvGlobals::getSpecialUnitInfo(SpecialUnitTypes eSpecialUnitNum)
{
	FAssert(eSpecialUnitNum > -1);
	FAssert(eSpecialUnitNum < GC.getNumSpecialUnitInfos());
	return *(m_paSpecialUnitInfo[eSpecialUnitNum]);
}


int CvGlobals::getNumConceptInfos()
{
	return (int)m_paConceptInfo.size();
}

std::vector<CvInfoBase*>& CvGlobals::getConceptInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paConceptInfo;
}

CvInfoBase& CvGlobals::getConceptInfo(ConceptTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumConceptInfos());
	return *(m_paConceptInfo[e]);
}
int CvGlobals::getNumCalendarInfos()
{
	return (int)m_paCalendarInfo.size();
}

std::vector<CvInfoBase*>& CvGlobals::getCalendarInfo()
{
	return m_paCalendarInfo;
}

CvInfoBase& CvGlobals::getCalendarInfo(CalendarTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumCalendarInfos());
	return *(m_paCalendarInfo[e]);
}


int CvGlobals::getNumSeasonInfos()
{
	return (int)m_paSeasonInfo.size();
}

std::vector<CvInfoBase*>& CvGlobals::getSeasonInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paSeasonInfo;
}

CvInfoBase& CvGlobals::getSeasonInfo(SeasonTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumSeasonInfos());
	return *(m_paSeasonInfo[e]);
}


int CvGlobals::getNumMonthInfos()
{
	return (int)m_paMonthInfo.size();
}

std::vector<CvInfoBase*>& CvGlobals::getMonthInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paMonthInfo;
}

CvInfoBase& CvGlobals::getMonthInfo(MonthTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumMonthInfos());
	return *(m_paMonthInfo[e]);
}


int CvGlobals::getNumDenialInfos()
{
	return (int)m_paDenialInfo.size();
}

std::vector<CvInfoBase*>& CvGlobals::getDenialInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paDenialInfo;
}

CvInfoBase& CvGlobals::getDenialInfo(DenialTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumDenialInfos());
	return *(m_paDenialInfo[e]);
}


int CvGlobals::getNumInvisibleInfos()
{
	return (int)m_paInvisibleInfo.size();
}

std::vector<CvInfoBase*>& CvGlobals::getInvisibleInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paInvisibleInfo;
}

CvInfoBase& CvGlobals::getInvisibleInfo(InvisibleTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumInvisibleInfos());
	return *(m_paInvisibleInfo[e]);
}


int CvGlobals::getNumFatherInfos()
{
	return (int)m_paFatherInfo.size();
}

std::vector<CvFatherInfo*>& CvGlobals::getFatherInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paFatherInfo;
}

CvFatherInfo& CvGlobals::getFatherInfo(FatherTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumFatherInfos());
	return *(m_paFatherInfo[e]);
}

int CvGlobals::getNumFatherPointInfos()
{
	return (int)m_paFatherPointInfo.size();
}

std::vector<CvFatherPointInfo*>& CvGlobals::getFatherPointInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paFatherPointInfo;
}

CvFatherPointInfo& CvGlobals::getFatherPointInfo(FatherPointTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumFatherPointInfos());
	return *(m_paFatherPointInfo[e]);
}

int CvGlobals::getNumUnitCombatInfos()
{
	return (int)m_paUnitCombatInfo.size();
}

std::vector<CvInfoBase*>& CvGlobals::getUnitCombatInfo()
{
	return m_paUnitCombatInfo;
}

CvInfoBase& CvGlobals::getUnitCombatInfo(UnitCombatTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumUnitCombatInfos());
	return *(m_paUnitCombatInfo[e]);
}


std::vector<CvInfoBase*>& CvGlobals::getDomainInfo()
{
	return m_paDomainInfo;
}

CvInfoBase& CvGlobals::getDomainInfo(DomainTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_DOMAIN_TYPES);
	return *(m_paDomainInfo[e]);
}


std::vector<CvInfoBase*>& CvGlobals::getUnitAIInfo()
{
	return m_paUnitAIInfos;
}

CvInfoBase& CvGlobals::getUnitAIInfo(UnitAITypes eUnitAINum)
{
	FAssert(eUnitAINum >= 0);
	FAssert(eUnitAINum < NUM_UNITAI_TYPES);
	return *(m_paUnitAIInfos[eUnitAINum]);
}


std::vector<CvInfoBase*>& CvGlobals::getAttitudeInfo()
{
	return m_paAttitudeInfos;
}

CvInfoBase& CvGlobals::getAttitudeInfo(AttitudeTypes eAttitudeNum)
{
	FAssert(eAttitudeNum >= 0);
	FAssert(eAttitudeNum < NUM_ATTITUDE_TYPES);
	return *(m_paAttitudeInfos[eAttitudeNum]);
}


std::vector<CvInfoBase*>& CvGlobals::getMemoryInfo()
{
	return m_paMemoryInfos;
}

CvInfoBase& CvGlobals::getMemoryInfo(MemoryTypes eMemoryNum)
{
	FAssert(eMemoryNum >= 0);
	FAssert(eMemoryNum < NUM_MEMORY_TYPES);
	return *(m_paMemoryInfos[eMemoryNum]);
}

int CvGlobals::getNumFatherCategoryInfos()
{
	return (int)m_paFatherCategoryInfos.size();
}

std::vector<CvInfoBase*>& CvGlobals::getFatherCategoryInfo()
{
	return m_paFatherCategoryInfos;
}

CvInfoBase& CvGlobals::getFatherCategoryInfo(FatherCategoryTypes eFatherCategoryNum)
{
	FAssert(eFatherCategoryNum >= 0);
	FAssert(eFatherCategoryNum < GC.getNumFatherCategoryInfos());
	return *(m_paFatherCategoryInfos[eFatherCategoryNum]);
}

int CvGlobals::getNumGameOptionInfos()
{
	return (int)m_paGameOptionInfos.size();
}

std::vector<CvGameOptionInfo*>& CvGlobals::getGameOptionInfo()
{
	return m_paGameOptionInfos;
}

CvGameOptionInfo& CvGlobals::getGameOptionInfo(GameOptionTypes eGameOptionNum)
{
	FAssert(eGameOptionNum >= 0);
	FAssert(eGameOptionNum < GC.getNumGameOptionInfos());
	return *(m_paGameOptionInfos[eGameOptionNum]);
}

int CvGlobals::getNumMPOptionInfos()
{
	return (int)m_paMPOptionInfos.size();
}

std::vector<CvMPOptionInfo*>& CvGlobals::getMPOptionInfo()
{
	 return m_paMPOptionInfos;
}

CvMPOptionInfo& CvGlobals::getMPOptionInfo(MultiplayerOptionTypes eMPOptionNum)
{
	FAssert(eMPOptionNum >= 0);
	FAssert(eMPOptionNum < GC.getNumMPOptionInfos());
	return *(m_paMPOptionInfos[eMPOptionNum]);
}

int CvGlobals::getNumForceControlInfos()
{
	return (int)m_paForceControlInfos.size();
}

std::vector<CvForceControlInfo*>& CvGlobals::getForceControlInfo()
{
	return m_paForceControlInfos;
}

CvForceControlInfo& CvGlobals::getForceControlInfo(ForceControlTypes eForceControlNum)
{
	FAssert(eForceControlNum >= 0);
	FAssert(eForceControlNum < GC.getNumForceControlInfos());
	return *(m_paForceControlInfos[eForceControlNum]);
}

std::vector<CvPlayerOptionInfo*>& CvGlobals::getPlayerOptionInfo()
{
	return m_paPlayerOptionInfos;
}

CvPlayerOptionInfo& CvGlobals::getPlayerOptionInfo(PlayerOptionTypes ePlayerOptionNum)
{
	FAssert(ePlayerOptionNum >= 0);
	FAssert(ePlayerOptionNum < NUM_PLAYEROPTION_TYPES);
	return *(m_paPlayerOptionInfos[ePlayerOptionNum]);
}

std::vector<CvGraphicOptionInfo*>& CvGlobals::getGraphicOptionInfo()
{
	return m_paGraphicOptionInfos;
}

CvGraphicOptionInfo& CvGlobals::getGraphicOptionInfo(GraphicOptionTypes eGraphicOptionNum)
{
	FAssert(eGraphicOptionNum >= 0);
	FAssert(eGraphicOptionNum < NUM_GRAPHICOPTION_TYPES);
	return *(m_paGraphicOptionInfos[eGraphicOptionNum]);
}


std::vector<CvYieldInfo*>& CvGlobals::getYieldInfo()	// For Moose - XML Load Util
{
	return m_paYieldInfo;
}

CvYieldInfo& CvGlobals::getYieldInfo(YieldTypes eYieldNum)
{
	FAssert(eYieldNum > -1);
	FAssert(eYieldNum < NUM_YIELD_TYPES);
	return *(m_paYieldInfo[eYieldNum]);
}


int CvGlobals::getNumRouteInfos()
{
	return (int)m_paRouteInfo.size();
}

std::vector<CvRouteInfo*>& CvGlobals::getRouteInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paRouteInfo;
}

CvRouteInfo& CvGlobals::getRouteInfo(RouteTypes eRouteNum)
{
	FAssert(eRouteNum > -1);
	FAssert(eRouteNum < GC.getNumRouteInfos());
	return *(m_paRouteInfo[eRouteNum]);
}

int CvGlobals::getNumImprovementInfos()
{
	return (int)m_paImprovementInfo.size();
}

std::vector<CvImprovementInfo*>& CvGlobals::getImprovementInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paImprovementInfo;
}

CvImprovementInfo& CvGlobals::getImprovementInfo(ImprovementTypes eImprovementNum)
{
	FAssert(eImprovementNum > -1);
	FAssert(eImprovementNum < GC.getNumImprovementInfos());
	return *(m_paImprovementInfo[eImprovementNum]);
}

int CvGlobals::getNumGoodyInfos()
{
	return (int)m_paGoodyInfo.size();
}

std::vector<CvGoodyInfo*>& CvGlobals::getGoodyInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paGoodyInfo;
}

CvGoodyInfo& CvGlobals::getGoodyInfo(GoodyTypes eGoodyNum)
{
	FAssert(eGoodyNum > -1);
	FAssert(eGoodyNum < GC.getNumGoodyInfos());
	return *(m_paGoodyInfo[eGoodyNum]);
}

int CvGlobals::getNumBuildInfos()
{
	return (int)m_paBuildInfo.size();
}

std::vector<CvBuildInfo*>& CvGlobals::getBuildInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paBuildInfo;
}

CvBuildInfo& CvGlobals::getBuildInfo(BuildTypes eBuildNum)
{
	FAssert(eBuildNum > -1);
	FAssert(eBuildNum < GC.getNumBuildInfos());
	return *(m_paBuildInfo[eBuildNum]);
}

int CvGlobals::getNumHandicapInfos()
{
	return (int)m_paHandicapInfo.size();
}

std::vector<CvHandicapInfo*>& CvGlobals::getHandicapInfo()	// Do NOT export outside of the DLL	// For Moose - XML Load Util
{
	return m_paHandicapInfo;
}

CvHandicapInfo& CvGlobals::getHandicapInfo(HandicapTypes eHandicapNum)
{
	FAssert(eHandicapNum > -1);
	FAssert(eHandicapNum < GC.getNumHandicapInfos());
	return *(m_paHandicapInfo[eHandicapNum]);
}

int CvGlobals::getNumGameSpeedInfos()
{
	return (int)m_paGameSpeedInfo.size();
}

std::vector<CvGameSpeedInfo*>& CvGlobals::getGameSpeedInfo()	// Do NOT export outside of the DLL	// For Moose - XML Load Util
{
	return m_paGameSpeedInfo;
}

CvGameSpeedInfo& CvGlobals::getGameSpeedInfo(GameSpeedTypes eGameSpeedNum)
{
	FAssert(eGameSpeedNum > -1);
	FAssert(eGameSpeedNum < GC.getNumGameSpeedInfos());
	return *(m_paGameSpeedInfo[eGameSpeedNum]);
}

int CvGlobals::getNumAlarmInfos()
{
	return (int)m_paAlarmInfo.size();
}
///TKs Invention Core Mod v 1.0
int CvGlobals::getCostToResearch(CivicTypes eCivic)
{
    if (eCivic != NO_CIVIC)
    {
        ///TK Update 1.1b
        CvCivicInfo& kCivicInfo = GC.getCivicInfo(eCivic);
        int iCivicResearchCost = kCivicInfo.getCostToResearch();
        iCivicResearchCost = (iCivicResearchCost * GC.getCache_TK_HUMAN_RESEARCH_COST_MOD_PERCENT()) / 100;
        return iCivicResearchCost;
    }
    return 0;

}

///Equipment Types 0 = Any; 1 = Heavy Armor; 2 = Any Armor; 3 = Armor & Horses
bool CvGlobals::isEquipmentType(YieldTypes eEquipment, UnitEquipmentTypes eType) const
{
    if (eType == EQUIPMENT_ANY)
    {
        if (eEquipment == YIELD_LEATHER_ARMOR || eEquipment == YIELD_SCALE_ARMOR || eEquipment == YIELD_MAIL_ARMOR || eEquipment == YIELD_PLATE_ARMOR)
        //if (eEquipment == YIELD_LEATHER_ARMOR || eEquipment == YIELD_SCALE_ARMOR)
        {
            return true;
        }

        if (eEquipment == YIELD_WEAPONS || eEquipment == YIELD_HORSES)
        {
            return true;
        }
    }
    else if (eType == EQUIPMENT_HEAVY_ARMOR)
    {
        if (eEquipment == YIELD_SCALE_ARMOR || eEquipment == YIELD_MAIL_ARMOR || eEquipment == YIELD_PLATE_ARMOR)
        //if (eEquipment == YIELD_SCALE_ARMOR)
        {
            return true;
        }
    }
    else if (eType == EQUIPMENT_ANY_ARMOR)
    {
        if (eEquipment == YIELD_LEATHER_ARMOR || eEquipment == YIELD_SCALE_ARMOR || eEquipment == YIELD_MAIL_ARMOR || eEquipment == YIELD_PLATE_ARMOR)
        //if (eEquipment == YIELD_LEATHER_ARMOR || eEquipment == YIELD_SCALE_ARMOR)
        {
            return true;
        }
    }
    else if (eType == EQUIPMENT_ARMOR_HORSES)
    {
        if (eEquipment == YIELD_LEATHER_ARMOR || eEquipment == YIELD_SCALE_ARMOR || eEquipment == YIELD_MAIL_ARMOR || eEquipment == YIELD_PLATE_ARMOR)
        //if (eEquipment == YIELD_LEATHER_ARMOR || eEquipment == YIELD_SCALE_ARMOR || eEquipment == YIELD_MAIL_ARMOR || eEquipment == YIELD_PLATE_ARMOR)
        {
            return true;
        }

        if (eEquipment == YIELD_HORSES)
        {
            return true;
        }
    }
    return false;
}
///TKe

std::vector<CvAlarmInfo*>& CvGlobals::getAlarmInfo()	// Do NOT export outside of the DLL	// For Moose - XML Load Util
{
	return m_paAlarmInfo;
}

CvAlarmInfo& CvGlobals::getAlarmInfo(AlarmTypes eAlarm)
{
	FAssert(eAlarm > -1);
	FAssert(eAlarm < GC.getNumAlarmInfos());
	return *(m_paAlarmInfo[eAlarm]);
}

int CvGlobals::getNumTurnTimerInfos()
{
	return (int)m_paTurnTimerInfo.size();
}

std::vector<CvTurnTimerInfo*>& CvGlobals::getTurnTimerInfo()	// Do NOT export outside of the DLL	// For Moose - XML Load Util
{
	return m_paTurnTimerInfo;
}

CvTurnTimerInfo& CvGlobals::getTurnTimerInfo(TurnTimerTypes eTurnTimerNum)
{
	FAssert(eTurnTimerNum > -1);
	FAssert(eTurnTimerNum < GC.getNumTurnTimerInfos());
	return *(m_paTurnTimerInfo[eTurnTimerNum]);
}

int CvGlobals::getNumBuildingClassInfos()
{
	return (int)m_paBuildingClassInfo.size();
}

std::vector<CvBuildingClassInfo*>& CvGlobals::getBuildingClassInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paBuildingClassInfo;
}

CvBuildingClassInfo& CvGlobals::getBuildingClassInfo(BuildingClassTypes eBuildingClassNum)
{
	FAssert(eBuildingClassNum > -1);
	FAssert(eBuildingClassNum < GC.getNumBuildingClassInfos());
	return *(m_paBuildingClassInfo[eBuildingClassNum]);
}

int CvGlobals::getNumBuildingInfos()
{
	return (int)m_paBuildingInfo.size();
}

std::vector<CvBuildingInfo*>& CvGlobals::getBuildingInfo()	// For Moose - XML Load Util, CvInfos, CvCacheObject
{
	return m_paBuildingInfo;
}

CvBuildingInfo& CvGlobals::getBuildingInfo(BuildingTypes eBuildingNum)
{
	FAssert(eBuildingNum > -1);
	FAssert(eBuildingNum < GC.getNumBuildingInfos());
	return *(m_paBuildingInfo[eBuildingNum]);
}

int CvGlobals::getNumSpecialBuildingInfos()
{
	return (int)m_paSpecialBuildingInfo.size();
}

std::vector<CvSpecialBuildingInfo*>& CvGlobals::getSpecialBuildingInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paSpecialBuildingInfo;
}

CvSpecialBuildingInfo& CvGlobals::getSpecialBuildingInfo(SpecialBuildingTypes eSpecialBuildingNum)
{
	FAssert(eSpecialBuildingNum > -1);
	FAssert(eSpecialBuildingNum < GC.getNumSpecialBuildingInfos());
	return *(m_paSpecialBuildingInfo[eSpecialBuildingNum]);
}

int CvGlobals::getNumUnitClassInfos()
{
	return (int)m_paUnitClassInfo.size();
}

std::vector<CvUnitClassInfo*>& CvGlobals::getUnitClassInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paUnitClassInfo;
}

CvUnitClassInfo& CvGlobals::getUnitClassInfo(UnitClassTypes eUnitClassNum)
{
	FAssert(eUnitClassNum > -1);
	FAssert(eUnitClassNum < GC.getNumUnitClassInfos());
	return *(m_paUnitClassInfo[eUnitClassNum]);
}

int CvGlobals::getNumActionInfos()
{
	return (int)m_paActionInfo.size();
}

std::vector<CvActionInfo*>& CvGlobals::getActionInfo()	// For Moose - XML Load Util
{
	return m_paActionInfo;
}

CvActionInfo& CvGlobals::getActionInfo(int i)
{
	FAssertMsg(i < getNumActionInfos(), "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	return *(m_paActionInfo[i]);
}

std::vector<CvMissionInfo*>& CvGlobals::getMissionInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paMissionInfo;
}

CvMissionInfo& CvGlobals::getMissionInfo(MissionTypes eMissionNum)
{
	FAssert(eMissionNum > -1);
	FAssert(eMissionNum < NUM_MISSION_TYPES);
	return *(m_paMissionInfo[eMissionNum]);
}

std::vector<CvControlInfo*>& CvGlobals::getControlInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paControlInfo;
}

CvControlInfo& CvGlobals::getControlInfo(ControlTypes eControlNum)
{
	FAssert(eControlNum > -1);
	FAssert(eControlNum < NUM_CONTROL_TYPES);
	FAssert(m_paControlInfo.size() > 0);
	return *(m_paControlInfo[eControlNum]);
}

std::vector<CvCommandInfo*>& CvGlobals::getCommandInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paCommandInfo;
}

CvCommandInfo& CvGlobals::getCommandInfo(CommandTypes eCommandNum)
{
	FAssert(eCommandNum > -1);
	FAssert(eCommandNum < NUM_COMMAND_TYPES);
	return *(m_paCommandInfo[eCommandNum]);
}

int CvGlobals::getNumAutomateInfos()
{
	return (int)m_paAutomateInfo.size();
}

std::vector<CvAutomateInfo*>& CvGlobals::getAutomateInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paAutomateInfo;
}

CvAutomateInfo& CvGlobals::getAutomateInfo(int iAutomateNum)
{
	FAssertMsg(iAutomateNum < getNumAutomateInfos(), "Index out of bounds");
	FAssertMsg(iAutomateNum > -1, "Index out of bounds");
	return *(m_paAutomateInfo[iAutomateNum]);
}

int CvGlobals::getNumPromotionInfos()
{
	return (int)m_paPromotionInfo.size();
}

std::vector<CvPromotionInfo*>& CvGlobals::getPromotionInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paPromotionInfo;
}

CvPromotionInfo& CvGlobals::getPromotionInfo(PromotionTypes ePromotionNum)
{
	FAssert(ePromotionNum > -1);
	FAssert(ePromotionNum < GC.getNumPromotionInfos());
	return *(m_paPromotionInfo[ePromotionNum]);
}

int CvGlobals::getNumProfessionInfos()
{
	return (int)m_paProfessionInfo.size();
}

std::vector<CvProfessionInfo*>& CvGlobals::getProfessionInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paProfessionInfo;
}

CvProfessionInfo& CvGlobals::getProfessionInfo(ProfessionTypes eProfessionNum)
{
	FAssert(eProfessionNum > -1);
	FAssert(eProfessionNum < (int)m_paProfessionInfo.size());
	return *(m_paProfessionInfo[eProfessionNum]);
}
int CvGlobals::getNumCivicOptionInfos()
{
	return (int)m_paCivicOptionInfo.size();
}

std::vector<CvInfoBase*>& CvGlobals::getCivicOptionInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paCivicOptionInfo;
}

CvInfoBase& CvGlobals::getCivicOptionInfo(CivicOptionTypes eCivicOptionNum)
{
	FAssert(eCivicOptionNum > -1);
	FAssert(eCivicOptionNum < GC.getNumCivicOptionInfos());
	return *(m_paCivicOptionInfo[eCivicOptionNum]);
}

int CvGlobals::getNumCivicInfos()
{
	return (int)m_paCivicInfo.size();
}

std::vector<CvCivicInfo*>& CvGlobals::getCivicInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paCivicInfo;
}

CvCivicInfo& CvGlobals::getCivicInfo(CivicTypes eCivicNum)
{
	FAssert(eCivicNum > -1);
	FAssert(eCivicNum < GC.getNumCivicInfos());
	return *(m_paCivicInfo[eCivicNum]);
}

int CvGlobals::getNumDiplomacyInfos()
{
	return (int)m_paDiplomacyInfo.size();
}

std::vector<CvDiplomacyInfo*>& CvGlobals::getDiplomacyInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paDiplomacyInfo;
}

CvDiplomacyInfo& CvGlobals::getDiplomacyInfo(int iDiplomacyNum)
{
	FAssertMsg(iDiplomacyNum < getNumDiplomacyInfos(), "Index out of bounds");
	FAssertMsg(iDiplomacyNum > -1, "Index out of bounds");
	return *(m_paDiplomacyInfo[iDiplomacyNum]);
}

int CvGlobals::getNumEraInfos()
{
	return (int)m_aEraInfo.size();
}

std::vector<CvEraInfo*>& CvGlobals::getEraInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_aEraInfo;
}

CvEraInfo& CvGlobals::getEraInfo(EraTypes eEraNum)
{
	FAssert(eEraNum > -1);
	FAssert(eEraNum < GC.getNumEraInfos());
	return *(m_aEraInfo[eEraNum]);
}

int CvGlobals::getNumHurryInfos()
{
	return (int)m_paHurryInfo.size();
}

std::vector<CvHurryInfo*>& CvGlobals::getHurryInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paHurryInfo;
}

CvHurryInfo& CvGlobals::getHurryInfo(HurryTypes eHurryNum)
{
	FAssert(eHurryNum > -1);
	FAssert(eHurryNum < GC.getNumHurryInfos());
	return *(m_paHurryInfo[eHurryNum]);
}

int CvGlobals::getNumEmphasizeInfos()
{
	return (int)m_paEmphasizeInfo.size();
}

std::vector<CvEmphasizeInfo*>& CvGlobals::getEmphasizeInfo()	// For Moose - XML Load Util
{
	return m_paEmphasizeInfo;
}

CvEmphasizeInfo& CvGlobals::getEmphasizeInfo(EmphasizeTypes eEmphasizeNum)
{
	FAssert(eEmphasizeNum > -1);
	FAssert(eEmphasizeNum < GC.getNumEmphasizeInfos());
	return *(m_paEmphasizeInfo[eEmphasizeNum]);
}

int CvGlobals::getNumCultureLevelInfos()
{
	return (int)m_paCultureLevelInfo.size();
}

std::vector<CvCultureLevelInfo*>& CvGlobals::getCultureLevelInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paCultureLevelInfo;
}

CvCultureLevelInfo& CvGlobals::getCultureLevelInfo(CultureLevelTypes eCultureLevelNum)
{
	FAssert(eCultureLevelNum > -1);
	FAssert(eCultureLevelNum < GC.getNumCultureLevelInfos());
	return *(m_paCultureLevelInfo[eCultureLevelNum]);
}

int CvGlobals::getNumVictoryInfos()
{
	return (int)m_paVictoryInfo.size();
}

std::vector<CvVictoryInfo*>& CvGlobals::getVictoryInfo()	// For Moose - XML Load Util, CvInfos
{
	return m_paVictoryInfo;
}

CvVictoryInfo& CvGlobals::getVictoryInfo(VictoryTypes eVictoryNum)
{
	FAssert(eVictoryNum > -1);
	FAssert(eVictoryNum < GC.getNumVictoryInfos());
	return *(m_paVictoryInfo[eVictoryNum]);
}

int CvGlobals::getNumEventTriggerInfos()
{
	return (int)m_paEventTriggerInfo.size();
}

std::vector<CvEventTriggerInfo*>& CvGlobals::getEventTriggerInfo()
{
	return m_paEventTriggerInfo;
}

CvEventTriggerInfo& CvGlobals::getEventTriggerInfo(EventTriggerTypes eEventTrigger)
{
	FAssert(eEventTrigger > -1);
	FAssert(eEventTrigger < GC.getNumEventTriggerInfos());
	return *(m_paEventTriggerInfo[eEventTrigger]);
}

int CvGlobals::getNumEventInfos()
{
	return (int)m_paEventInfo.size();
}

std::vector<CvEventInfo*>& CvGlobals::getEventInfo()
{
	return m_paEventInfo;
}

CvEventInfo& CvGlobals::getEventInfo(EventTypes eEvent)
{
	FAssert(eEvent > -1);
	FAssert(eEvent < GC.getNumEventInfos());
	return *(m_paEventInfo[eEvent]);
}

int& CvGlobals::getNumEntityEventTypes()
{
	return m_iNumEntityEventTypes;
}

CvString*& CvGlobals::getEntityEventTypes()
{
	return m_paszEntityEventTypes;
}

CvString& CvGlobals::getEntityEventTypes(EntityEventTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumEntityEventTypes());
	return m_paszEntityEventTypes[e];
}

int& CvGlobals::getNumAnimationOperatorTypes()
{
	return m_iNumAnimationOperatorTypes;
}

CvString*& CvGlobals::getAnimationOperatorTypes()
{
	return m_paszAnimationOperatorTypes;
}

CvString& CvGlobals::getAnimationOperatorTypes(AnimationOperatorTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumAnimationOperatorTypes());
	return m_paszAnimationOperatorTypes[e];
}

CvString*& CvGlobals::getFunctionTypes()
{
	return m_paszFunctionTypes;
}

CvString& CvGlobals::getFunctionTypes(FunctionTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_FUNC_TYPES);
	return m_paszFunctionTypes[e];
}

int& CvGlobals::getNumArtStyleTypes()
{
	return m_iNumArtStyleTypes;
}

CvString*& CvGlobals::getArtStyleTypes()
{
	return m_paszArtStyleTypes;
}

CvString& CvGlobals::getArtStyleTypes(ArtStyleTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumArtStyleTypes());
	return m_paszArtStyleTypes[e];
}


//Androrc UnitArtStyles
int CvGlobals::getNumUnitArtStyleTypeInfos()
{
    return (int)m_paUnitArtStyleTypeInfo.size();
}

std::vector<CvUnitArtStyleTypeInfo*>& CvGlobals::getUnitArtStyleTypeInfo()
{
	return m_paUnitArtStyleTypeInfo;
}

CvUnitArtStyleTypeInfo& CvGlobals::getUnitArtStyleTypeInfo(UnitArtStyleTypes eUnitArtStyleTypeNum)
{
	FAssert(eUnitArtStyleTypeNum > -1);
	FAssert(eUnitArtStyleTypeNum < GC.getNumUnitArtStyleTypeInfos());
	return *(m_paUnitArtStyleTypeInfo[eUnitArtStyleTypeNum]);
}
//Androrc End

int& CvGlobals::getNumCitySizeTypes()
{
	return m_iNumCitySizeTypes;
}

CvString*& CvGlobals::getCitySizeTypes()
{
	return m_paszCitySizeTypes;
}

CvString& CvGlobals::getCitySizeTypes(int i)
{
	FAssertMsg(i < getNumCitySizeTypes(), "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	return m_paszCitySizeTypes[i];
}

CvString*& CvGlobals::getContactTypes()
{
	return m_paszContactTypes;
}

CvString& CvGlobals::getContactTypes(ContactTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_CONTACT_TYPES);
	return m_paszContactTypes[e];
}

CvString*& CvGlobals::getDiplomacyPowerTypes()
{
	return m_paszDiplomacyPowerTypes;
}

CvString& CvGlobals::getDiplomacyPowerTypes(DiplomacyPowerTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_DIPLOMACYPOWER_TYPES);
	return m_paszDiplomacyPowerTypes[e];
}

CvString*& CvGlobals::getAutomateTypes()
{
	return m_paszAutomateTypes;
}

CvString& CvGlobals::getAutomateTypes(AutomateTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_AUTOMATE_TYPES);
	return m_paszAutomateTypes[e];
}
///TKs Med
CvString*& CvGlobals::getMedCityTypes()
{
	return m_paszMedCityTypes;
}

CvString*& CvGlobals::getModCodeTypes()
{
	return m_paszModCodeTypes;
}

CvString& CvGlobals::getModCodeTypes(ModCodeTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_MOD_CODE_TYPES);
	return m_paszModCodeTypes[e];
}

CvString& CvGlobals::getMedCityTypes(MedCityTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_CITY_TYPES);
	return m_paszMedCityTypes[e];
}
CvString*& CvGlobals::getTradeScreenTypes()
{
	return m_paszTradeScreenTypes;
}

CvString& CvGlobals::getTradeScreenTypes(TradeScreenTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_TRADE_SCREEN_TYPES);
	return m_paszTradeScreenTypes[e];
}
///Tke

CvString*& CvGlobals::getDirectionTypes()
{
	return m_paszDirectionTypes;
}

CvString& CvGlobals::getDirectionTypes(AutomateTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_DIRECTION_TYPES);
	return m_paszDirectionTypes[e];
}

int& CvGlobals::getNumFootstepAudioTypes()
{
	return m_iNumFootstepAudioTypes;
}

CvString*& CvGlobals::getFootstepAudioTypes()
{
	return m_paszFootstepAudioTypes;
}

CvString& CvGlobals::getFootstepAudioTypes(int i)
{
	FAssertMsg(i < getNumFootstepAudioTypes(), "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	return m_paszFootstepAudioTypes[i];
}

int CvGlobals::getFootstepAudioTypeByTag(CvString strTag)
{
	int iIndex = -1;

	if ( strTag.GetLength() <= 0 )
	{
		return iIndex;
	}

	for ( int i = 0; i < m_iNumFootstepAudioTypes; i++ )
	{
		if ( strTag.CompareNoCase(m_paszFootstepAudioTypes[i]) == 0 )
		{
			iIndex = i;
			break;
		}
	}

	return iIndex;
}

CvString*& CvGlobals::getFootstepAudioTags()
{
	return m_paszFootstepAudioTags;
}

CvString& CvGlobals::getFootstepAudioTags(int i)
{
//	FAssertMsg(i < getNumFootstepAudioTags(), "Index out of bounds")
	FAssertMsg(i > -1, "Index out of bounds");
	return m_paszFootstepAudioTags[i];
}

void CvGlobals::setCurrentXMLFile(const TCHAR* szFileName)
{
	m_szCurrentXMLFile = szFileName;
}

CvString& CvGlobals::getCurrentXMLFile()
{
	return m_szCurrentXMLFile;
}

FVariableSystem* CvGlobals::getDefinesVarSystem()
{
	return m_VarSystem;
}

void CvGlobals::cacheGlobals()
{
	m_iMOVE_DENOMINATOR = getDefineINT("MOVE_DENOMINATOR");
	m_iFOOD_CONSUMPTION_PER_POPULATION = getDefineINT("FOOD_CONSUMPTION_PER_POPULATION");
	m_iMAX_HIT_POINTS = getDefineINT("MAX_HIT_POINTS");
	m_iHILLS_EXTRA_DEFENSE = getDefineINT("HILLS_EXTRA_DEFENSE");
	m_iRIVER_ATTACK_MODIFIER = getDefineINT("RIVER_ATTACK_MODIFIER");
	m_iAMPHIB_ATTACK_MODIFIER = getDefineINT("AMPHIB_ATTACK_MODIFIER");
	m_iHILLS_EXTRA_MOVEMENT = getDefineINT("HILLS_EXTRA_MOVEMENT");
	m_iPEAK_EXTRA_MOVEMENT = getDefineINT("PEAK_EXTRA_MOVEMENT");
	m_iMAX_PLOT_LIST_ROWS = getDefineINT("MAX_PLOT_LIST_ROWS");
	m_iUNIT_MULTISELECT_MAX = getDefineINT("UNIT_MULTISELECT_MAX");
	m_iEVENT_MESSAGE_TIME = getDefineINT("EVENT_MESSAGE_TIME");
	m_iROUTE_FEATURE_GROWTH_MODIFIER = getDefineINT("ROUTE_FEATURE_GROWTH_MODIFIER");
	m_iFEATURE_GROWTH_MODIFIER = getDefineINT("FEATURE_GROWTH_MODIFIER");
	m_iMIN_CITY_RANGE = getDefineINT("MIN_CITY_RANGE");
	m_iCITY_MAX_NUM_BUILDINGS = getDefineINT("CITY_MAX_NUM_BUILDINGS");
	m_iLAKE_MAX_AREA_SIZE = getDefineINT("LAKE_MAX_AREA_SIZE");
	m_iMIN_WATER_SIZE_FOR_OCEAN = getDefineINT("MIN_WATER_SIZE_FOR_OCEAN");
	m_iFORTIFY_MODIFIER_PER_TURN = getDefineINT("FORTIFY_MODIFIER_PER_TURN");
	m_iMAX_CITY_DEFENSE_DAMAGE = getDefineINT("MAX_CITY_DEFENSE_DAMAGE");
	m_iPEAK_SEE_THROUGH_CHANGE = getDefineINT("PEAK_SEE_THROUGH_CHANGE");
	m_iHILLS_SEE_THROUGH_CHANGE = getDefineINT("HILLS_SEE_THROUGH_CHANGE");
	m_iSEAWATER_SEE_FROM_CHANGE = getDefineINT("SEAWATER_SEE_FROM_CHANGE");
	m_iPEAK_SEE_FROM_CHANGE = getDefineINT("PEAK_SEE_FROM_CHANGE");
	m_iHILLS_SEE_FROM_CHANGE = getDefineINT("HILLS_SEE_FROM_CHANGE");
	m_iMAX_REBEL_YIELD_MODIFIER = getDefineINT("MAX_REBEL_YIELD_MODIFIER");

	m_fCAMERA_MIN_YAW = getDefineFLOAT("CAMERA_MIN_YAW");
	m_fCAMERA_MAX_YAW = getDefineFLOAT("CAMERA_MAX_YAW");
	m_fCAMERA_FAR_CLIP_Z_HEIGHT = getDefineFLOAT("CAMERA_FAR_CLIP_Z_HEIGHT");
	m_fCAMERA_MAX_TRAVEL_DISTANCE = getDefineFLOAT("CAMERA_MAX_TRAVEL_DISTANCE");
	m_fCAMERA_START_DISTANCE = getDefineFLOAT("CAMERA_START_DISTANCE");
	m_fPLOT_SIZE = getDefineFLOAT("PLOT_SIZE");
	m_fCAMERA_SPECIAL_PITCH = getDefineFLOAT("CAMERA_SPECIAL_PITCH");
	m_fCAMERA_MAX_TURN_OFFSET = getDefineFLOAT("CAMERA_MAX_TURN_OFFSET");
	m_fCAMERA_MIN_DISTANCE = getDefineFLOAT("CAMERA_MIN_DISTANCE");
	m_fCAMERA_UPPER_PITCH = getDefineFLOAT("CAMERA_UPPER_PITCH");
	m_fCAMERA_LOWER_PITCH = getDefineFLOAT("CAMERA_LOWER_PITCH");
	m_fFIELD_OF_VIEW = getDefineFLOAT("FIELD_OF_VIEW");
	m_fUNIT_MULTISELECT_DISTANCE = getDefineFLOAT("UNIT_MULTISELECT_DISTANCE");

	m_iUSE_CAN_FOUND_CITIES_ON_WATER_CALLBACK = getDefineINT("USE_CAN_FOUND_CITIES_ON_WATER_CALLBACK");
	m_iUSE_CANNOT_DO_CIVIC_CALLBACK = getDefineINT("USE_CANNOT_DO_CIVIC_CALLBACK");
	m_iUSE_CAN_DO_CIVIC_CALLBACK = getDefineINT("USE_CAN_DO_CIVIC_CALLBACK");
	m_iUSE_CANNOT_CONSTRUCT_CALLBACK = getDefineINT("USE_CANNOT_CONSTRUCT_CALLBACK");
	m_iUSE_CAN_CONSTRUCT_CALLBACK = getDefineINT("USE_CAN_CONSTRUCT_CALLBACK");
	m_iUSE_CAN_DECLARE_WAR_CALLBACK = getDefineINT("USE_CAN_DECLARE_WAR_CALLBACK");
	m_iUSE_GET_UNIT_COST_MOD_CALLBACK = getDefineINT("USE_GET_UNIT_COST_MOD_CALLBACK");
	m_iUSE_GET_BUILDING_COST_MOD_CALLBACK = getDefineINT("USE_GET_BUILDING_COST_MOD_CALLBACK");
	m_iUSE_GET_CITY_FOUND_VALUE_CALLBACK = getDefineINT("USE_GET_CITY_FOUND_VALUE_CALLBACK");
	m_iUSE_CANNOT_HANDLE_ACTION_CALLBACK = getDefineINT("USE_CANNOT_HANDLE_ACTION_CALLBACK");
	m_iUSE_CAN_BUILD_CALLBACK = getDefineINT("USE_CAN_BUILD_CALLBACK");
	m_iUSE_CANNOT_TRAIN_CALLBACK = getDefineINT("USE_CANNOT_TRAIN_CALLBACK");
	m_iUSE_CAN_TRAIN_CALLBACK = getDefineINT("USE_CAN_TRAIN_CALLBACK");
	m_iUSE_UNIT_CANNOT_MOVE_INTO_CALLBACK = getDefineINT("USE_UNIT_CANNOT_MOVE_INTO_CALLBACK");
	m_iUSE_FINISH_TEXT_CALLBACK = getDefineINT("USE_FINISH_TEXT_CALLBACK");
	m_iUSE_ON_UNIT_SET_XY_CALLBACK = getDefineINT("USE_ON_UNIT_SET_XY_CALLBACK");
	m_iUSE_ON_UNIT_SELECTED_CALLBACK = getDefineINT("USE_ON_UNIT_SELECTED_CALLBACK");
	m_iUSE_ON_MISSIONARY_CONVERTED_UNIT_CALLBACK = getDefineINT("USE_ON_MISSIONARY_CONVERTED_UNIT_CALLBACK");
	m_iUSE_ON_UPDATE_CALLBACK = getDefineINT("USE_ON_UPDATE_CALLBACK");
	m_iUSE_ON_UNIT_CREATED_CALLBACK = getDefineINT("USE_ON_UNIT_CREATED_CALLBACK");
	m_iUSE_ON_UNIT_LOST_CALLBACK = getDefineINT("USE_ON_UNIT_LOST_CALLBACK");
}

int CvGlobals::getDefineINT( const char * szName ) const
{
	int iReturn = 0;
	GC.getDefinesVarSystem()->GetValue( szName, iReturn );
	return iReturn;
}

float CvGlobals::getDefineFLOAT( const char * szName ) const
{
	float fReturn = 0;
	GC.getDefinesVarSystem()->GetValue( szName, fReturn );
	return fReturn;
}

const char * CvGlobals::getDefineSTRING( const char * szName ) const
{
	const char * szReturn = NULL;
	GC.getDefinesVarSystem()->GetValue( szName, szReturn );
	return szReturn;
}

void CvGlobals::setDefineINT( const char * szName, int iValue )
{
	GC.getDefinesVarSystem()->SetValue( szName, iValue );
	cacheGlobals();
}

void CvGlobals::setDefineFLOAT( const char * szName, float fValue )
{
	GC.getDefinesVarSystem()->SetValue( szName, fValue );
	cacheGlobals();
}

void CvGlobals::setDefineSTRING( const char * szName, const char * szValue )
{
	GC.getDefinesVarSystem()->SetValue( szName, szValue );
	cacheGlobals();
}

int CvGlobals::getMOVE_DENOMINATOR()
{
	return m_iMOVE_DENOMINATOR;
}

int CvGlobals::getFOOD_CONSUMPTION_PER_POPULATION()
{
	return m_iFOOD_CONSUMPTION_PER_POPULATION;
}

int CvGlobals::getMAX_HIT_POINTS()
{
	return m_iMAX_HIT_POINTS;
}

int CvGlobals::getHILLS_EXTRA_DEFENSE()
{
	return m_iHILLS_EXTRA_DEFENSE;
}

int CvGlobals::getRIVER_ATTACK_MODIFIER()
{
	return m_iRIVER_ATTACK_MODIFIER;
}

int CvGlobals::getAMPHIB_ATTACK_MODIFIER()
{
	return m_iAMPHIB_ATTACK_MODIFIER;
}

int CvGlobals::getHILLS_EXTRA_MOVEMENT()
{
	return m_iHILLS_EXTRA_MOVEMENT;
}

int CvGlobals::getPEAK_EXTRA_MOVEMENT()
{
	return m_iPEAK_EXTRA_MOVEMENT;
}

int CvGlobals::getMAX_PLOT_LIST_ROWS()
{
	return m_iMAX_PLOT_LIST_ROWS;
}

int CvGlobals::getUNIT_MULTISELECT_MAX()
{
	return m_iUNIT_MULTISELECT_MAX;
}

int CvGlobals::getEVENT_MESSAGE_TIME()
{
	return m_iEVENT_MESSAGE_TIME;
}

int CvGlobals::getROUTE_FEATURE_GROWTH_MODIFIER()
{
	return m_iROUTE_FEATURE_GROWTH_MODIFIER;
}

int CvGlobals::getFEATURE_GROWTH_MODIFIER()
{
	return m_iFEATURE_GROWTH_MODIFIER;
}

int CvGlobals::getMIN_CITY_RANGE()
{
	return m_iMIN_CITY_RANGE;
}

int CvGlobals::getCITY_MAX_NUM_BUILDINGS()
{
	return m_iCITY_MAX_NUM_BUILDINGS;
}
int CvGlobals::getLAKE_MAX_AREA_SIZE()
{
	return m_iLAKE_MAX_AREA_SIZE;
}
int CvGlobals::getMIN_WATER_SIZE_FOR_OCEAN()
{
	return m_iMIN_WATER_SIZE_FOR_OCEAN;
}

int CvGlobals::getFORTIFY_MODIFIER_PER_TURN()
{
	return m_iFORTIFY_MODIFIER_PER_TURN;
}

int CvGlobals::getMAX_CITY_DEFENSE_DAMAGE()
{
	return m_iMAX_CITY_DEFENSE_DAMAGE;
}

int CvGlobals::getPEAK_SEE_THROUGH_CHANGE()
{
	return m_iPEAK_SEE_THROUGH_CHANGE;
}

int CvGlobals::getHILLS_SEE_THROUGH_CHANGE()
{
	return m_iHILLS_SEE_THROUGH_CHANGE;
}

int CvGlobals::getSEAWATER_SEE_FROM_CHANGE()
{
	return m_iSEAWATER_SEE_FROM_CHANGE;
}

int CvGlobals::getPEAK_SEE_FROM_CHANGE()
{
	return m_iPEAK_SEE_FROM_CHANGE;
}

int CvGlobals::getHILLS_SEE_FROM_CHANGE()
{
	return m_iHILLS_SEE_FROM_CHANGE;
}

int CvGlobals::getMAX_REBEL_YIELD_MODIFIER()
{
	return m_iMAX_REBEL_YIELD_MODIFIER;
}

float CvGlobals::getCAMERA_MIN_YAW()
{
	return m_fCAMERA_MIN_YAW;
}

float CvGlobals::getCAMERA_MAX_YAW()
{
	return m_fCAMERA_MAX_YAW;
}

float CvGlobals::getCAMERA_FAR_CLIP_Z_HEIGHT()
{
	return m_fCAMERA_FAR_CLIP_Z_HEIGHT;
}

float CvGlobals::getCAMERA_MAX_TRAVEL_DISTANCE()
{
	return m_fCAMERA_MAX_TRAVEL_DISTANCE;
}

float CvGlobals::getCAMERA_START_DISTANCE()
{
	return m_fCAMERA_START_DISTANCE;
}

float CvGlobals::getPLOT_SIZE()
{
	return m_fPLOT_SIZE;
}

float CvGlobals::getCAMERA_SPECIAL_PITCH()
{
	return m_fCAMERA_SPECIAL_PITCH;
}

float CvGlobals::getCAMERA_MAX_TURN_OFFSET()
{
	return m_fCAMERA_MAX_TURN_OFFSET;
}

float CvGlobals::getCAMERA_MIN_DISTANCE()
{
	return m_fCAMERA_MIN_DISTANCE;
}

float CvGlobals::getCAMERA_UPPER_PITCH()
{
	return m_fCAMERA_UPPER_PITCH;
}

float CvGlobals::getCAMERA_LOWER_PITCH()
{
	return m_fCAMERA_LOWER_PITCH;
}

float CvGlobals::getFIELD_OF_VIEW()
{
	return m_fFIELD_OF_VIEW;
}

float CvGlobals::getUNIT_MULTISELECT_DISTANCE()
{
	return m_fUNIT_MULTISELECT_DISTANCE;
}

int CvGlobals::getUSE_CAN_FOUND_CITIES_ON_WATER_CALLBACK()
{
	return m_iUSE_CAN_FOUND_CITIES_ON_WATER_CALLBACK;
}
int CvGlobals::getUSE_CANNOT_DO_CIVIC_CALLBACK()
{
	return m_iUSE_CANNOT_DO_CIVIC_CALLBACK;
}

int CvGlobals::getUSE_CAN_DO_CIVIC_CALLBACK()
{
	return m_iUSE_CAN_DO_CIVIC_CALLBACK;
}

int CvGlobals::getUSE_CANNOT_CONSTRUCT_CALLBACK()
{
	return m_iUSE_CANNOT_CONSTRUCT_CALLBACK;
}

int CvGlobals::getUSE_CAN_CONSTRUCT_CALLBACK()
{
	return m_iUSE_CAN_CONSTRUCT_CALLBACK;
}

int CvGlobals::getUSE_CAN_DECLARE_WAR_CALLBACK()
{
	return m_iUSE_CAN_DECLARE_WAR_CALLBACK;
}
int CvGlobals::getUSE_GET_UNIT_COST_MOD_CALLBACK()
{
	return m_iUSE_GET_UNIT_COST_MOD_CALLBACK;
}

int CvGlobals::getUSE_GET_BUILDING_COST_MOD_CALLBACK()
{
	return m_iUSE_GET_BUILDING_COST_MOD_CALLBACK;
}

int CvGlobals::getUSE_GET_CITY_FOUND_VALUE_CALLBACK()
{
	return m_iUSE_GET_CITY_FOUND_VALUE_CALLBACK;
}

int CvGlobals::getUSE_CANNOT_HANDLE_ACTION_CALLBACK()
{
	return m_iUSE_CANNOT_HANDLE_ACTION_CALLBACK;
}

int CvGlobals::getUSE_CAN_BUILD_CALLBACK()
{
	return m_iUSE_CAN_BUILD_CALLBACK;
}

int CvGlobals::getUSE_CANNOT_TRAIN_CALLBACK()
{
	return m_iUSE_CANNOT_TRAIN_CALLBACK;
}

int CvGlobals::getUSE_CAN_TRAIN_CALLBACK()
{
	return m_iUSE_CAN_TRAIN_CALLBACK;
}

int CvGlobals::getUSE_UNIT_CANNOT_MOVE_INTO_CALLBACK()
{
	return m_iUSE_UNIT_CANNOT_MOVE_INTO_CALLBACK;
}

int CvGlobals::getUSE_FINISH_TEXT_CALLBACK()
{
	return m_iUSE_FINISH_TEXT_CALLBACK;
}

int CvGlobals::getUSE_ON_UNIT_SET_XY_CALLBACK()
{
	return m_iUSE_ON_UNIT_SET_XY_CALLBACK;
}

int CvGlobals::getUSE_ON_UNIT_SELECTED_CALLBACK()
{
	return m_iUSE_ON_UNIT_SELECTED_CALLBACK;
}

int CvGlobals::getUSE_ON_MISSIONARY_CONVERTED_UNIT_CALLBACK()
{
	return m_iUSE_ON_MISSIONARY_CONVERTED_UNIT_CALLBACK;
}

int CvGlobals::getUSE_ON_UPDATE_CALLBACK()
{
	return m_iUSE_ON_UPDATE_CALLBACK;
}

int CvGlobals::getUSE_ON_UNIT_CREATED_CALLBACK()
{
	return m_iUSE_ON_UNIT_CREATED_CALLBACK;
}

int CvGlobals::getUSE_ON_UNIT_LOST_CALLBACK()
{
	return m_iUSE_ON_UNIT_LOST_CALLBACK;
}

int CvGlobals::getMAX_CIV_PLAYERS()
{
	return MAX_PLAYERS;
}

int CvGlobals::getMAX_PLAYERS()
{
	return MAX_PLAYERS;
}

int CvGlobals::getMAX_CIV_TEAMS()
{
	return MAX_TEAMS;
}

int CvGlobals::getMAX_TEAMS()
{
	return MAX_TEAMS;
}

int CvGlobals::getINVALID_PLOT_COORD()
{
	return INVALID_PLOT_COORD;
}

int CvGlobals::getNUM_CITY_PLOTS()
{
	return NUM_CITY_PLOTS;
}

int CvGlobals::getCITY_HOME_PLOT()
{
	return CITY_HOME_PLOT;
}

void CvGlobals::setDLLIFace(CvDLLUtilityIFaceBase* pDll)
{
	m_pDLL = pDll;
}

int CvGlobals::getNUM_ENGINE_DIRTY_BITS() const
{
	return NUM_ENGINE_DIRTY_BITS;
}

int CvGlobals::getNUM_INTERFACE_DIRTY_BITS() const
{
	return NUM_INTERFACE_DIRTY_BITS;
}

int CvGlobals::getNUM_YIELD_TYPES() const
{
	return NUM_YIELD_TYPES;
}

int CvGlobals::getNUM_FORCECONTROL_TYPES() const
{
	return NUM_FORCECONTROL_TYPES;
}

int CvGlobals::getNUM_INFOBAR_TYPES() const
{
	return NUM_INFOBAR_TYPES;
}

int CvGlobals::getNUM_HEALTHBAR_TYPES() const
{
	return NUM_HEALTHBAR_TYPES;
}

int CvGlobals::getNUM_CONTROL_TYPES() const
{
	return NUM_CONTROL_TYPES;
}

int CvGlobals::getNUM_LEADERANIM_TYPES() const
{
	return NUM_LEADERANIM_TYPES;
}


void CvGlobals::deleteInfoArrays()
{
	for(int i=0;i<(int)m_aInfoVectors.size();i++)
	{
		deleteInfoArray(*m_aInfoVectors[i]);
	}
    //Androrc UnitArtStyles
	//this probably isn't necessary, due to the loop just before, which wasn't present in the BTS code; however, I want to be safe.
	deleteInfoArray(m_paUnitArtStyleTypeInfo);
	//Androrc End
	SAFE_DELETE_ARRAY(GC.getEntityEventTypes());
	SAFE_DELETE_ARRAY(GC.getAnimationOperatorTypes());
	SAFE_DELETE_ARRAY(GC.getFunctionTypes());
	SAFE_DELETE_ARRAY(GC.getArtStyleTypes());
	SAFE_DELETE_ARRAY(GC.getCitySizeTypes());
	SAFE_DELETE_ARRAY(GC.getContactTypes());
	SAFE_DELETE_ARRAY(GC.getDiplomacyPowerTypes());
	SAFE_DELETE_ARRAY(GC.getAutomateTypes());
	///TKs Med
	SAFE_DELETE_ARRAY(GC.getMedCityTypes());
	SAFE_DELETE_ARRAY(GC.getTradeScreenTypes());
	SAFE_DELETE_ARRAY(GC.getModCodeTypes());
	///TKe
	SAFE_DELETE_ARRAY(GC.getDirectionTypes());
	SAFE_DELETE_ARRAY(GC.getFootstepAudioTypes());
	SAFE_DELETE_ARRAY(GC.getFootstepAudioTags());

	clearTypesMap();
	m_aInfoVectors.clear();
}


//
// Global Infos Hash Map
//

int CvGlobals::getInfoTypeForString(const char* szType, bool hideAssert) const
{
	FAssertMsg(szType, "null info type string");
	InfosMap::const_iterator it = m_infosMap.find(szType);
	if (it!=m_infosMap.end())
	{
		return it->second;
	}

	if(!hideAssert)
	{
		CvString szError;
		szError.Format("info type %s not found, Current XML file is: %s", szType, GC.getCurrentXMLFile().GetCString());
		FAssertMsg(strcmp(szType, "NONE")==0 || strcmp(szType, "")==0, szError.c_str());
		gDLL->logMsg("xml.log", szError);
	}

	return -1;
}

void CvGlobals::setInfoTypeFromString(const char* szType, int idx)
{
	FAssertMsg(szType, "null info type string");
#ifdef _DEBUG
	InfosMap::const_iterator it = m_infosMap.find(szType);
	int iExisting = (it!=m_infosMap.end()) ? it->second : -1;
	FAssertMsg(iExisting==-1 || iExisting==idx || strcmp(szType, "ERROR")==0, CvString::format("xml info type entry %s already exists", szType).c_str());
#endif
	m_infosMap[szType] = idx;
}

void CvGlobals::infoTypeFromStringReset()
{
	m_infosMap.clear();
}

void CvGlobals::addToInfosVectors(void *infoVector)
{
	std::vector<CvInfoBase *> *infoBaseVector = (std::vector<CvInfoBase *> *) infoVector;
	m_aInfoVectors.push_back(infoBaseVector);
}

void CvGlobals::infosReset()
{
	for(int i=0;i<(int)m_aInfoVectors.size();i++)
	{
		std::vector<CvInfoBase *> *infoBaseVector = m_aInfoVectors[i];
		for(int j=0;j<(int)infoBaseVector->size();j++)
			infoBaseVector->at(j)->reset();
	}
}

int CvGlobals::getNumDirections() const { return NUM_DIRECTION_TYPES; }
int CvGlobals::getNumResourceLayers() const { return NUM_RESOURCE_LAYERS; }
int CvGlobals::getNumUnitLayerOptionTypes() const { return NUM_UNIT_LAYER_OPTION_TYPES; }
int CvGlobals::getNumGameOptions() const { return NUM_GAMEOPTION_TYPES; }
int CvGlobals::getNumMPOptions() const { return NUM_MPOPTION_TYPES; }
int CvGlobals::getNumSpecialOptions() const { return NUM_SPECIALOPTION_TYPES; }
int CvGlobals::getNumGraphicOptions() const { return NUM_GRAPHICOPTION_TYPES; }
int CvGlobals::getNumTradeableItems() const { return NUM_TRADEABLE_ITEMS; }
int CvGlobals::getNumBasicItems() const { return NUM_BASIC_ITEMS; }
int CvGlobals::getNumTradeableHeadings() const { return NUM_TRADEABLE_HEADINGS; }
int CvGlobals::getNumCommandInfos() const { return NUM_COMMAND_TYPES; }
int CvGlobals::getNumControlInfos() const { return NUM_CONTROL_TYPES; }
int CvGlobals::getNumMissionInfos() const { return NUM_MISSION_TYPES; }
int CvGlobals::getNumPlayerOptionInfos() const { return NUM_PLAYEROPTION_TYPES; }
int CvGlobals::getMaxNumSymbols() const { return MAX_NUM_SYMBOLS; }
int CvGlobals::getNumGraphicLevels() const { return NUM_GRAPHICLEVELS; }


//
// non-inline versions
//
CvMap& CvGlobals::getMap() { return *m_map; }
CvGameAI& CvGlobals::getGame() { return *m_game; }
CvGameAI *CvGlobals::getGamePointer(){ return m_game; }

int CvGlobals::getMaxCivPlayers() const
{
	return MAX_PLAYERS;
}

bool CvGlobals::IsGraphicsInitialized() const { return m_bGraphicsInitialized;}
void CvGlobals::SetGraphicsInitialized(bool bVal) { m_bGraphicsInitialized = bVal;}
void CvGlobals::setInterface(CvInterface* pVal) { m_interface = pVal; }
void CvGlobals::setDiplomacyScreen(CvDiplomacyScreen* pVal) { m_diplomacyScreen = pVal; }
void CvGlobals::setMPDiplomacyScreen(CMPDiplomacyScreen* pVal) { m_mpDiplomacyScreen = pVal; }
void CvGlobals::setMessageQueue(CMessageQueue* pVal) { m_messageQueue = pVal; }
void CvGlobals::setHotJoinMessageQueue(CMessageQueue* pVal) { m_hotJoinMsgQueue = pVal; }
void CvGlobals::setMessageControl(CMessageControl* pVal) { m_messageControl = pVal; }
void CvGlobals::setSetupData(CvSetupData* pVal) { m_setupData = pVal; }
void CvGlobals::setMessageCodeTranslator(CvMessageCodeTranslator* pVal) { m_messageCodes = pVal; }
void CvGlobals::setDropMgr(CvDropMgr* pVal) { m_dropMgr = pVal; }
void CvGlobals::setPortal(CvPortal* pVal) { m_portal = pVal; }
void CvGlobals::setStatsReport(CvStatsReporter* pVal) { m_statsReporter = pVal; }
void CvGlobals::setPathFinder(FAStar* pVal) { m_pathFinder = pVal; }
void CvGlobals::setInterfacePathFinder(FAStar* pVal) { m_interfacePathFinder = pVal; }
void CvGlobals::setStepFinder(FAStar* pVal) { m_stepFinder = pVal; }
void CvGlobals::setRouteFinder(FAStar* pVal) { m_routeFinder = pVal; }
void CvGlobals::setBorderFinder(FAStar* pVal) { m_borderFinder = pVal; }
void CvGlobals::setAreaFinder(FAStar* pVal) { m_areaFinder = pVal; }
CvDLLUtilityIFaceBase* CvGlobals::getDLLIFaceNonInl() { return m_pDLL; }

// cache XML - start - Nightinggale
void CvGlobals::setXMLCache()
{
	if (m_cache_WEEKS_PER_MONTHS > 0)
	{
		// cache is already set.
		return;
	}

	m_cache_ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES = getDefineINT("ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES");
	m_cache_ADVANCED_START_CITY_COST = getDefineINT("ADVANCED_START_CITY_COST");
	m_cache_ADVANCED_START_CITY_COST_INCREASE = getDefineINT("ADVANCED_START_CITY_COST_INCREASE");
	m_cache_ADVANCED_START_CITY_PLACEMENT_MAX_RANGE = getDefineINT("ADVANCED_START_CITY_PLACEMENT_MAX_RANGE");
	m_cache_ADVANCED_START_CULTURE_COST = getDefineINT("ADVANCED_START_CULTURE_COST"); 
	m_cache_ADVANCED_START_MAX_UNITS_PER_CITY = getDefineINT("ADVANCED_START_MAX_UNITS_PER_CITY");
	m_cache_ADVANCED_START_POPULATION_COST = getDefineINT("ADVANCED_START_POPULATION_COST");
	m_cache_ADVANCED_START_POPULATION_COST_INCREASE = getDefineINT("ADVANCED_START_POPULATION_COST_INCREASE");
	m_cache_ADVANCED_START_SIGHT_RANGE = getDefineINT("ADVANCED_START_SIGHT_RANGE");
	m_cache_ADVANCED_START_VISIBILITY_COST = getDefineINT("ADVANCED_START_VISIBILITY_COST");
	m_cache_ADVANCED_START_VISIBILITY_COST_INCREASE = getDefineINT("ADVANCED_START_VISIBILITY_COST_INCREASE");
	m_cache_AI_ADVANCED_TECH_START = getDefineINT("AI_ADVANCED_TECH_START");
	m_cache_AI_CAN_DISBAND_UNITS = getDefineINT("AI_CAN_DISBAND_UNITS");
	m_cache_AI_CHEAT_AUTO_BUY = getDefineINT("AI_CHEAT_AUTO_BUY");
	m_cache_AI_CHEAT_NEEDED_DEFENDERS = getDefineINT("AI_CHEAT_NEEDED_DEFENDERS");
	m_cache_AI_CHEAT_SPICE = getDefineINT("AI_CHEAT_SPICE");
	m_cache_AI_CHEAT_SPICE_BUY = getDefineINT("AI_CHEAT_SPICE_BUY");
	m_cache_AI_CHEAT_SPICE_MULTIPLE = getDefineINT("AI_CHEAT_SPICE_MULTIPLE");
	m_cache_AI_FAVORED_TERRAIN_MOD = getDefineINT("AI_FAVORED_TERRAIN_MOD");
	m_cache_AI_HANDICAP_CASTLE = getDefineINT("AI_HANDICAP_CASTLE");
	m_cache_AI_HANDICAP_MOTTE = getDefineINT("AI_HANDICAP_MOTTE");
	m_cache_AI_MILITARY_PROFESSION_HACK = getDefineINT("AI_MILITARY_PROFESSION_HACK");
	m_cache_AI_WAREHOUSE_MOD = getDefineINT("AI_WAREHOUSE_MOD");
	m_cache_ALLIANCE_CULTURE_PERCENT_DENIAL = getDefineINT("ALLIANCE_CULTURE_PERCENT_DENIAL");
	m_cache_ALLIANCE_PACT_PEACE_DENIAL = getDefineINT("ALLIANCE_PACT_PEACE_DENIAL");
	m_cache_ANIMAL_BANDITS_GUARD_GOODY_TIMER = getDefineINT("ANIMAL_BANDITS_GUARD_GOODY_TIMER");
	m_cache_AUTORESEARCH_ALL = getDefineINT("AUTORESEARCH_ALL");
	m_cache_BANQUET_YIELD_AMOUNT = getDefineINT("BANQUET_YIELD_AMOUNT");
	m_cache_BARBARIAN_CIVILIZATION = getDefineINT("BARBARIAN_CIVILIZATION");
	m_cache_BARBARIAN_LEADER = getDefineINT("BARBARIAN_LEADER");
	m_cache_BASE_CITY_GROWTH_THRESHOLD = getDefineINT("BASE_CITY_GROWTH_THRESHOLD");
	m_cache_BASE_CITY_LUXURY_FOOD_THRESHOLD_MOD = getDefineINT("BASE_CITY_LUXURY_FOOD_THRESHOLD_MOD");
	m_cache_BASE_OCCUPATION_TURNS = getDefineINT("BASE_OCCUPATION_TURNS");
	m_cache_BASE_UNIT_UPGRADE_COST = getDefineINT("BASE_UNIT_UPGRADE_COST");
	m_cache_BUILDINGCLASS_TRAVEL_TO_FAIR = getDefineINT("BUILDINGCLASS_TRAVEL_TO_FAIR");
	m_cache_BUILDING_PRODUCTION_DECAY_PERCENT = getDefineINT("BUILDING_PRODUCTION_DECAY_PERCENT");
	m_cache_BUILDING_PRODUCTION_DECAY_TIME = getDefineINT("BUILDING_PRODUCTION_DECAY_TIME");
	m_cache_BUILDING_PRODUCTION_PERCENT = getDefineINT("BUILDING_PRODUCTION_PERCENT");
	m_cache_BUY_PLOT_BASE_CULTURE_COST = getDefineINT("BUY_PLOT_BASE_CULTURE_COST");
	m_cache_BUY_PLOT_CULTURE_RANGE = getDefineINT("BUY_PLOT_CULTURE_RANGE");
	m_cache_BUY_PLOT_MIN_CULTURE = getDefineINT("BUY_PLOT_MIN_CULTURE");
	m_cache_BUY_PLOT_OWNED_COST_MODIFIER = getDefineINT("BUY_PLOT_OWNED_COST_MODIFIER");
	m_cache_BUY_PLOT_SELLER_INCOME_PERCENT = getDefineINT("BUY_PLOT_SELLER_INCOME_PERCENT");
	m_cache_CALENDER_YEAR_FIRST_CHANGE_TURN = getDefineINT("CALENDER_YEAR_FIRST_CHANGE_TURN");
	m_cache_CALENDER_YEAR_FIRST_MULTIPLIER = getDefineINT("CALENDER_YEAR_FIRST_MULTIPLIER");
	m_cache_CALENDER_YEAR_SECOND_CHANGE_TURN = getDefineINT("CALENDER_YEAR_SECOND_CHANGE_TURN");
	m_cache_CALENDER_YEAR_SECOND_MULTIPLIER = getDefineINT("CALENDER_YEAR_SECOND_MULTIPLIER");
	m_cache_CALENDER_YEAR_THIRD_MULTIPLIER = getDefineINT("CALENDER_YEAR_THIRD_MULTIPLIER");
	m_cache_CAPITAL_BUILDINGCLASS = getDefineINT("CAPITAL_BUILDINGCLASS");
	m_cache_CAPTURED_CARGO_RANDOM_AMOUNT = getDefineINT("CAPTURED_CARGO_RANDOM_AMOUNT");
	m_cache_CAPTURED_LUXURY_FOOD_RANDOM_AMOUNT = getDefineINT("CAPTURED_LUXURY_FOOD_RANDOM_AMOUNT");
	m_cache_CASTLES_TO_VILLAGES_RATIO = getDefineINT("CASTLES_TO_VILLAGES_RATIO");
	m_cache_CHANCE_TO_CAPTURE_CRIMINALS = getDefineINT("CHANCE_TO_CAPTURE_CRIMINALS");
	m_cache_CHEAT_TRAVEL_ALL = getDefineINT("CHEAT_TRAVEL_ALL");
	m_cache_CITY_DEFENSE_DAMAGE_HEAL_RATE = getDefineINT("CITY_DEFENSE_DAMAGE_HEAL_RATE");
	m_cache_CITY_FREE_CULTURE_GROWTH_FACTOR = getDefineINT("CITY_FREE_CULTURE_GROWTH_FACTOR");
	m_cache_CITY_GROWTH_MULTIPLIER = getDefineINT("CITY_GROWTH_MULTIPLIER");
	m_cache_CITY_HEAL_RATE = getDefineINT("CITY_HEAL_RATE");
	m_cache_CITY_PILGRAM_RANDOM = getDefineINT("CITY_PILGRAM_RANDOM");
	m_cache_CITY_SCREEN_FOG_ENABLED = getDefineINT("CITY_SCREEN_FOG_ENABLED");
	m_cache_CITY_YIELD_CAPACITY = getDefineINT("CITY_YIELD_CAPACITY");
	m_cache_CITY_YIELD_DECAY_PERCENT = getDefineINT("CITY_YIELD_DECAY_PERCENT");
	m_cache_CIVICOPTION_INVENTIONS = getDefineINT("CIVICOPTION_INVENTIONS");
	m_cache_COLONIAL_FORCED_PEACE_TURNS = getDefineINT("COLONIAL_FORCED_PEACE_TURNS");
	m_cache_COMBAT_DAMAGE = getDefineINT("COMBAT_DAMAGE");
	m_cache_COMBAT_DIE_SIDES = getDefineINT("COMBAT_DIE_SIDES");
	m_cache_COMBAT_EXPERIENCE_IN_BORDERS_PERCENT = getDefineINT("COMBAT_EXPERIENCE_IN_BORDERS_PERCENT");
	m_cache_CONSUME_EQUIPMENT_ON_FOUND = getDefineINT("CONSUME_EQUIPMENT_ON_FOUND");
	m_cache_CONTACT_YIELD_GIFT_ENCOMEIDA_TIMER = getDefineINT("CONTACT_YIELD_GIFT_ENCOMEIDA_TIMER");
	m_cache_CONTACT_YIELD_GIFT_TECH = getDefineINT("CONTACT_YIELD_GIFT_TECH");
	m_cache_CULTURE_YIELD = getDefineINT("CULTURE_YIELD");
	m_cache_DEAL_TRADE_RELATIONS_POINTS = getDefineINT("DEAL_TRADE_RELATIONS_POINTS");
	m_cache_DEEP_WATER_TERRAIN = getDefineINT("DEEP_WATER_TERRAIN");
	m_cache_DEFAULT_BUILD_CASTLE = getDefineINT("DEFAULT_BUILD_CASTLE");
	m_cache_DEFAULT_BUILD_MOTTE_AND_BAILEY = getDefineINT("DEFAULT_BUILD_MOTTE_AND_BAILEY");
	m_cache_DEFAULT_CENSURETYPE_ANATHEMA = getDefineINT("DEFAULT_CENSURETYPE_ANATHEMA");
	m_cache_DEFAULT_CENSURETYPE_ANATHEMA_COUNT = getDefineINT("DEFAULT_CENSURETYPE_ANATHEMA_COUNT");
	m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION = getDefineINT("DEFAULT_CENSURETYPE_EXCOMMUNICATION");
	m_cache_DEFAULT_CENSURETYPE_EXCOMMUNICATION_COUNT = getDefineINT("DEFAULT_CENSURETYPE_EXCOMMUNICATION_COUNT");
	m_cache_DEFAULT_CENSURETYPE_INTERDICT = getDefineINT("DEFAULT_CENSURETYPE_INTERDICT");
	m_cache_DEFAULT_CENSURETYPE_INTERDICT_COUNT = getDefineINT("DEFAULT_CENSURETYPE_INTERDICT_COUNT");
	m_cache_DEFAULT_COMBAT_FOR_TRAINING = getDefineINT("DEFAULT_COMBAT_FOR_TRAINING");
	m_cache_DEFAULT_DAWN_POPULATION_UNIT = getDefineINT("DEFAULT_DAWN_POPULATION_UNIT");
	m_cache_DEFAULT_FUEDALISM_TECH = getDefineINT("DEFAULT_FUEDALISM_TECH");
	m_cache_DEFAULT_GRAIN_GROWTH_UNIT_CLASS = getDefineINT("DEFAULT_GRAIN_GROWTH_UNIT_CLASS");
	m_cache_DEFAULT_HUNTSMAN_PROFESSION = getDefineINT("DEFAULT_HUNTSMAN_PROFESSION");
	m_cache_DEFAULT_INVENTOR_CLASS = getDefineINT("DEFAULT_INVENTOR_CLASS");
	m_cache_DEFAULT_KNIGHT_PROFESSION_PROMOTION = getDefineINT("DEFAULT_KNIGHT_PROFESSION_PROMOTION");
	m_cache_DEFAULT_KNIGHT_PROMOTION = getDefineINT("DEFAULT_KNIGHT_PROMOTION");
	m_cache_DEFAULT_MARAUDER_CLASS = getDefineINT("DEFAULT_MARAUDER_CLASS");
	m_cache_DEFAULT_MARUADER_SEA_PROFESSION = getDefineINT("DEFAULT_MARUADER_SEA_PROFESSION");
	m_cache_DEFAULT_NOBLEMAN_CLASS = getDefineINT("DEFAULT_NOBLEMAN_CLASS");
	m_cache_DEFAULT_NOBLE_GROWTH_UNIT_CLASS = getDefineINT("DEFAULT_NOBLE_GROWTH_UNIT_CLASS");
	m_cache_DEFAULT_PILGRAM_CLASS = getDefineINT("DEFAULT_PILGRAM_CLASS");
	m_cache_DEFAULT_POPULATION_UNIT = getDefineINT("DEFAULT_POPULATION_UNIT");
	m_cache_DEFAULT_SHRINE_CLASS = getDefineINT("DEFAULT_SHRINE_CLASS");
	m_cache_DEFAULT_SLAVE_CLASS = getDefineINT("DEFAULT_SLAVE_CLASS");
	m_cache_DEFAULT_SPECIALBUILDING_COURTHOUSE = getDefineINT("DEFAULT_SPECIALBUILDING_COURTHOUSE");
	m_cache_DEFAULT_TEST_DEFINE = getDefineINT("DEFAULT_TEST_DEFINE");
	m_cache_DEFAULT_TRAINED_PROMOTION = getDefineINT("DEFAULT_TRAINED_PROMOTION");
	m_cache_DEFAULT_TREASURE_YIELD = getDefineINT("DEFAULT_TREASURE_YIELD");
	m_cache_DEFAULT_UNTRAINED_PROMOTION = getDefineINT("DEFAULT_UNTRAINED_PROMOTION");
	m_cache_DEFAULT_VIKING_ERA = getDefineINT("DEFAULT_VIKING_ERA");
	m_cache_DEFAULT_YIELD_ARMOR_TYPE = getDefineINT("DEFAULT_YIELD_ARMOR_TYPE");
	m_cache_DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT = getDefineINT("DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT");
	m_cache_DIPLOMACY_VALUE_REMAINDER = getDefineINT("DIPLOMACY_VALUE_REMAINDER");
	m_cache_DOCKS_NEXT_UNITS = getDefineINT("DOCKS_NEXT_UNITS");
	m_cache_EDUCATION_BASE_TUITION = getDefineINT("EDUCATION_BASE_TUITION");
	m_cache_EDUCATION_THRESHOLD = getDefineINT("EDUCATION_THRESHOLD");
	m_cache_EDUCATION_THRESHOLD_INCREASE = getDefineINT("EDUCATION_THRESHOLD_INCREASE");
	m_cache_ENABLE_ALLIANCE_TRADING = getDefineINT("ENABLE_ALLIANCE_TRADING");
	m_cache_ENABLE_DEFENSIVE_PACT_TRADING = getDefineINT("ENABLE_DEFENSIVE_PACT_TRADING");
	m_cache_ENABLE_GOLD_TRADING = getDefineINT("ENABLE_GOLD_TRADING");
	m_cache_ENABLE_MAP_TRADING = getDefineINT("ENABLE_MAP_TRADING");
	m_cache_ENABLE_OPEN_BORDERS = getDefineINT("ENABLE_OPEN_BORDERS");
	m_cache_END_GAME_DISPLAY_WARNING = getDefineINT("END_GAME_DISPLAY_WARNING");
	m_cache_ENEMY_HEAL_RATE = getDefineINT("ENEMY_HEAL_RATE");
	m_cache_ESTABLISH_TRADEPOST_COST = getDefineINT("ESTABLISH_TRADEPOST_COST");
	m_cache_EUROPE_EAST = getDefineINT("EUROPE_EAST");
	m_cache_EUROPE_MARKET_CORRELATION_PERCENT = getDefineINT("EUROPE_MARKET_CORRELATION_PERCENT");
	m_cache_EVENT_PROBABILITY_ROLL_SIDES = getDefineINT("EVENT_PROBABILITY_ROLL_SIDES");
	m_cache_EXPERIENCE_FROM_WITHDRAWL = getDefineINT("EXPERIENCE_FROM_WITHDRAWL");
	m_cache_EXTRA_YIELD = getDefineINT("EXTRA_YIELD");
	m_cache_FATHER_COST_EXTRA_TEAM_MEMBER_MODIFIER = getDefineINT("FATHER_COST_EXTRA_TEAM_MEMBER_MODIFIER");
	m_cache_FATHER_POINT_REAL_TRADE = getDefineINT("FATHER_POINT_REAL_TRADE");
	m_cache_FEATURE_PRODUCTION_YIELD_MAX_DISTANCE = getDefineINT("FEATURE_PRODUCTION_YIELD_MAX_DISTANCE");
	m_cache_FIRST_EVENT_DELAY_TURNS = getDefineINT("FIRST_EVENT_DELAY_TURNS");
	m_cache_FOUND_MONASTERY_NUMBER = getDefineINT("FOUND_MONASTERY_NUMBER");
	m_cache_FOUND_MOTTE_AND_BAILEY_NUMBER = getDefineINT("FOUND_MOTTE_AND_BAILEY_NUMBER");
	m_cache_FOUND_OUTPOST_NUMBER = getDefineINT("FOUND_OUTPOST_NUMBER");
	m_cache_FOUND_VILLAGE_NUMBER = getDefineINT("FOUND_VILLAGE_NUMBER");
	m_cache_FREE_CITY_ADJACENT_CULTURE = getDefineINT("FREE_CITY_ADJACENT_CULTURE");
	m_cache_FREE_CITY_CULTURE = getDefineINT("FREE_CITY_CULTURE");
	m_cache_FREE_PEASANT_CIVIC = getDefineINT("FREE_PEASANT_CIVIC");
	m_cache_FRIENDLY_HEAL_RATE = getDefineINT("FRIENDLY_HEAL_RATE");
	m_cache_GREAT_GENERALS_THRESHOLD = getDefineINT("GREAT_GENERALS_THRESHOLD");
	m_cache_GREAT_GENERALS_THRESHOLD_INCREASE = getDefineINT("GREAT_GENERALS_THRESHOLD_INCREASE");
	m_cache_GREAT_GENERALS_THRESHOLD_INCREASE_TEAM = getDefineINT("GREAT_GENERALS_THRESHOLD_INCREASE_TEAM");
	m_cache_HIRE_GUARD_COST = getDefineINT("HIRE_GUARD_COST");
	m_cache_HIRE_GUARD_PROMOTION = getDefineINT("HIRE_GUARD_PROMOTION");
	m_cache_IMMIGRATION_MAX_CITY_DISTANCE = getDefineINT("IMMIGRATION_MAX_CITY_DISTANCE");
	m_cache_IMMIGRATION_THRESHOLD = getDefineINT("IMMIGRATION_THRESHOLD");
	m_cache_IMMIGRATION_THRESHOLD_INCREASE = getDefineINT("IMMIGRATION_THRESHOLD_INCREASE");
	m_cache_IMMIGRATION_TRAVEL_MOD = getDefineINT("IMMIGRATION_TRAVEL_MOD");
	m_cache_INDUSTRIAL_VICTORY_SINGLE_YIELD = getDefineINT("INDUSTRIAL_VICTORY_SINGLE_YIELD");
	m_cache_INITIAL_AI_CITY_PRODUCTION = getDefineINT("INITIAL_AI_CITY_PRODUCTION");
	m_cache_INITIAL_CITY_POPULATION = getDefineINT("INITIAL_CITY_POPULATION");
	m_cache_INITIAL_CITY_ROUTE_TYPE = getDefineINT("INITIAL_CITY_ROUTE_TYPE");
	m_cache_JUNGLE_FEATURE = getDefineINT("JUNGLE_FEATURE");
	m_cache_KING_BUY_UNIT_PRICE_MODIFIER = getDefineINT("KING_BUY_UNIT_PRICE_MODIFIER");
	m_cache_KING_INITIAL_UNIT_INCREASE = getDefineINT("KING_INITIAL_UNIT_INCREASE");
	m_cache_KING_TRANSPORT_TREASURE_COMISSION = getDefineINT("KING_TRANSPORT_TREASURE_COMISSION");
	m_cache_KNIGHT_RANSOM_MOD = getDefineINT("KNIGHT_RANSOM_MOD");
	m_cache_LAKE_PLOT_RAND = getDefineINT("LAKE_PLOT_RAND");
	m_cache_LAND_IMPROVEMENT = getDefineINT("LAND_IMPROVEMENT");
	m_cache_LAND_TERRAIN = getDefineINT("LAND_TERRAIN");
	m_cache_MARAUDERS_DAYSOUT_RANDOM = getDefineINT("MARAUDERS_DAYSOUT_RANDOM");
	m_cache_MARAUDERS_TOWER_RANGE = getDefineINT("MARAUDERS_TOWER_RANGE");
	m_cache_MARAUDER_CRUMBS_EVENT = getDefineINT("MARAUDER_CRUMBS_EVENT");
	m_cache_MARAUDER_EVENT_DEFAULT_TURNS = getDefineINT("MARAUDER_EVENT_DEFAULT_TURNS");
	m_cache_MAX_CITY_POPULATION_COMMUNE = getDefineINT("MAX_CITY_POPULATION_COMMUNE");
	m_cache_MAX_CITY_POPULATION_VILLAGE = getDefineINT("MAX_CITY_POPULATION_VILLAGE");
	m_cache_MAX_EXPERIENCE_AFTER_UPGRADE = getDefineINT("MAX_EXPERIENCE_AFTER_UPGRADE");
	m_cache_MAX_EXPERIENCE_PER_COMBAT = getDefineINT("MAX_EXPERIENCE_PER_COMBAT");
	m_cache_MAX_FORTIFY_TURNS = getDefineINT("MAX_FORTIFY_TURNS");
	m_cache_MAX_INSULT_MODIFIER = getDefineINT("MAX_INSULT_MODIFIER");
	m_cache_MAX_LEVEL_FROM_ANIMAL_XP = getDefineINT("MAX_LEVEL_FROM_ANIMAL_XP");
	m_cache_MAX_MARAUDERS = getDefineINT("MAX_MARAUDERS");
	m_cache_MAX_NUM_LANGUAGES = getDefineINT("MAX_NUM_LANGUAGES");
	m_cache_MAX_PLOT_LIST_SIZE = getDefineINT("MAX_PLOT_LIST_SIZE");
	m_cache_MAX_REBEL_COMBAT_MULTIPLER = getDefineINT("MAX_REBEL_COMBAT_MULTIPLER");
	m_cache_MAX_TRAINED_EXPERIENCE = getDefineINT("MAX_TRAINED_EXPERIENCE");
	m_cache_MAX_WITHDRAWAL_PROBABILITY = getDefineINT("MAX_WITHDRAWAL_PROBABILITY");
	m_cache_MEDIEVAL_CENSURE = getDefineINT("MEDIEVAL_CENSURE");
	m_cache_MEDIEVAL_TRADE_TECH = getDefineINT("MEDIEVAL_TRADE_TECH");
	m_cache_MINIMAP_RENDER_SIZE = getDefineINT("MINIMAP_RENDER_SIZE");
	m_cache_MIN_ANIMAL_STARTING_DISTANCE = getDefineINT("MIN_ANIMAL_STARTING_DISTANCE");
	m_cache_MIN_CITY_YIELD_DECAY = getDefineINT("MIN_CITY_YIELD_DECAY");
	m_cache_MIN_CIV_STARTING_DISTANCE = getDefineINT("MIN_CIV_STARTING_DISTANCE");
	m_cache_MIN_EXPERIENCE_PER_COMBAT = getDefineINT("MIN_EXPERIENCE_PER_COMBAT");
	m_cache_MIN_TIMER_UNIT_DOUBLE_MOVES = getDefineINT("MIN_TIMER_UNIT_DOUBLE_MOVES");
	m_cache_MIN_WATER_SIZE_FOR_OCEAN = getDefineINT("MIN_WATER_SIZE_FOR_OCEAN");
	m_cache_MISSIONARY_RATE_EFFECT_ON_SUCCESS = getDefineINT("MISSIONARY_RATE_EFFECT_ON_SUCCESS");
	m_cache_MISSIONARY_THRESHOLD = getDefineINT("MISSIONARY_THRESHOLD");
	m_cache_MISSIONARY_THRESHOLD_INCREASE = getDefineINT("MISSIONARY_THRESHOLD_INCREASE");
	m_cache_MONASTERIES_TO_VILLAGES_RATIO = getDefineINT("MONASTERIES_TO_VILLAGES_RATIO");
	m_cache_NATIVE_AUTO_SELL_PERCENT = getDefineINT("NATIVE_AUTO_SELL_PERCENT");
	m_cache_NATIVE_GOODS_RAID_PERCENT = getDefineINT("NATIVE_GOODS_RAID_PERCENT");
	m_cache_NATIVE_GROWTH_THRESHOLD_MULTIPLIER = getDefineINT("NATIVE_GROWTH_THRESHOLD_MULTIPLIER");
	m_cache_NATIVE_HORSES_FOR_SALE = getDefineINT("NATIVE_HORSES_FOR_SALE");
	m_cache_NATIVE_HORSES_FOR_SALE_PERCENT = getDefineINT("NATIVE_HORSES_FOR_SALE_PERCENT");
	m_cache_NATIVE_TEACH_THRESHOLD_INCREASE = getDefineINT("NATIVE_TEACH_THRESHOLD_INCREASE");
	m_cache_NATIVE_TECH = getDefineINT("NATIVE_TECH");
	m_cache_NATIVE_TRADING_TRADEPOST = getDefineINT("NATIVE_TRADING_TRADEPOST");
	m_cache_NEUTRAL_HEAL_RATE = getDefineINT("NEUTRAL_HEAL_RATE");
	m_cache_NEW_CITY_BUILDING_VALUE_MODIFIER = getDefineINT("NEW_CITY_BUILDING_VALUE_MODIFIER");
	m_cache_NEW_HURRY_MODIFIER = getDefineINT("NEW_HURRY_MODIFIER");
	m_cache_NOBLE_FIELD_LABOR_PENALTY = getDefineINT("NOBLE_FIELD_LABOR_PENALTY");
	m_cache_NO_BAD_GOODIES_EXPERIENCE_PERCENT = getDefineINT("NO_BAD_GOODIES_EXPERIENCE_PERCENT");
	m_cache_NO_BAD_GOODIES_GOLD_PERCENT = getDefineINT("NO_BAD_GOODIES_GOLD_PERCENT");
	m_cache_NO_CITY_SHORTAGE_MESSAGES = getDefineINT("NO_CITY_SHORTAGE_MESSAGES");
	m_cache_NO_STARTING_PLOTS_IN_JUNGLE = getDefineINT("NO_STARTING_PLOTS_IN_JUNGLE");
	m_cache_OCCUPATION_CULTURE_PERCENT_THRESHOLD = getDefineINT("OCCUPATION_CULTURE_PERCENT_THRESHOLD");
	m_cache_OCCUPATION_TURNS_POPULATION_PERCENT = getDefineINT("OCCUPATION_TURNS_POPULATION_PERCENT");
	m_cache_OWNERSHIP_SCORE_DURATION_THRESHOLD = getDefineINT("OWNERSHIP_SCORE_DURATION_THRESHOLD");
	m_cache_OWN_TEAM_STARTING_MODIFIER = getDefineINT("OWN_TEAM_STARTING_MODIFIER");
	m_cache_PEACE_TREATY_LENGTH = getDefineINT("PEACE_TREATY_LENGTH");
	m_cache_PERCENT_TAX_ON_AUTOSELL_GOODS = getDefineINT("PERCENT_TAX_ON_AUTOSELL_GOODS");
	m_cache_PILGRAM_OFFER_GOLD = getDefineINT("PILGRAM_OFFER_GOLD");
	m_cache_PILGRAM_OFFER_GOLD_DISTANCE_MOD = getDefineINT("PILGRAM_OFFER_GOLD_DISTANCE_MOD");
	m_cache_PLAYER_ALWAYS_RAZES_CITIES = getDefineINT("PLAYER_ALWAYS_RAZES_CITIES");
	m_cache_PLOTS_PER_RIVER_EDGE = getDefineINT("PLOTS_PER_RIVER_EDGE");
	m_cache_PLOT_VISIBILITY_RANGE = getDefineINT("PLOT_VISIBILITY_RANGE");
	m_cache_PROFESSION_COAL_BURNER = getDefineINT("PROFESSION_COAL_BURNER");
	m_cache_PROFESSION_INVENTOR = getDefineINT("PROFESSION_INVENTOR");
	m_cache_PROLIFIC_INVENTOR_THRESHOLD_INCREASE = getDefineINT("PROLIFIC_INVENTOR_THRESHOLD_INCREASE");
	m_cache_PROMOTION_BUILD_HOME = getDefineINT("PROMOTION_BUILD_HOME");
	m_cache_RANDOM_TURNS_LOST_AT_SEA = getDefineINT("RANDOM_TURNS_LOST_AT_SEA");
	m_cache_RAZING_CULTURAL_PERCENT_THRESHOLD = getDefineINT("RAZING_CULTURAL_PERCENT_THRESHOLD");
	m_cache_REBEL_PERCENT_FOR_REVOLUTION = getDefineINT("REBEL_PERCENT_FOR_REVOLUTION");
	m_cache_REBEL_SENTIMENT_BELLS_FACTOR = getDefineINT("REBEL_SENTIMENT_BELLS_FACTOR");
	m_cache_REBEL_SENTIMENT_TURN_WEIGHT = getDefineINT("REBEL_SENTIMENT_TURN_WEIGHT");
	m_cache_REVOLUTION_EUROPE_UNIT_SHIP_MODIFIER = getDefineINT("REVOLUTION_EUROPE_UNIT_SHIP_MODIFIER");
	m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD = getDefineINT("REVOLUTION_EUROPE_UNIT_THRESHOLD");
	m_cache_REVOLUTION_EUROPE_UNIT_THRESHOLD_INCREASE = getDefineINT("REVOLUTION_EUROPE_UNIT_THRESHOLD_INCREASE");
	m_cache_RIVAL_TEAM_STARTING_MODIFIER = getDefineINT("RIVAL_TEAM_STARTING_MODIFIER");
	m_cache_RIVER_SOURCE_MIN_RIVER_RANGE = getDefineINT("RIVER_SOURCE_MIN_RIVER_RANGE");
	m_cache_RIVER_SOURCE_MIN_SEAWATER_RANGE = getDefineINT("RIVER_SOURCE_MIN_SEAWATER_RANGE");
	m_cache_RUINS_IMPROVEMENT = getDefineINT("RUINS_IMPROVEMENT");
	m_cache_SCORE_FATHER_FACTOR = getDefineINT("SCORE_FATHER_FACTOR");
	m_cache_SCORE_LAND_FACTOR = getDefineINT("SCORE_LAND_FACTOR");
	m_cache_SCORE_POPULATION_FACTOR = getDefineINT("SCORE_POPULATION_FACTOR");
	m_cache_SCORE_TAX_FACTOR = getDefineINT("SCORE_TAX_FACTOR");
	m_cache_SETTLEMENT_TREASURE_YIELD = getDefineINT("SETTLEMENT_TREASURE_YIELD");
	m_cache_SHALLOW_WATER_TERRAIN = getDefineINT("SHALLOW_WATER_TERRAIN");
	m_cache_SLAVE_FOOD_CONSUMPTION_PER_POPULATION = getDefineINT("SLAVE_FOOD_CONSUMPTION_PER_POPULATION");
	m_cache_STANDARD_CALENDAR = getDefineINT("STANDARD_CALENDAR");
	m_cache_STANDARD_CLIMATE = getDefineINT("STANDARD_CLIMATE");
	m_cache_STANDARD_ERA = getDefineINT("STANDARD_ERA");
	m_cache_STANDARD_GAMESPEED = getDefineINT("STANDARD_GAMESPEED");
	m_cache_STANDARD_HANDICAP = getDefineINT("STANDARD_HANDICAP");
	m_cache_STANDARD_SEALEVEL = getDefineINT("STANDARD_SEALEVEL");
	m_cache_STANDARD_TURNTIMER = getDefineINT("STANDARD_TURNTIMER");
	m_cache_STARTING_DISTANCE_PERCENT = getDefineINT("STARTING_DISTANCE_PERCENT");
	m_cache_START_YEAR = getDefineINT("START_YEAR");
	m_cache_STEAMWORKS_BUILDING = getDefineINT("STEAMWORKS_BUILDING");
	m_cache_STEAMWORKS_CLASS_TYPE = getDefineINT("STEAMWORKS_CLASS_TYPE");
	m_cache_TAX_INCREASE_CHANCE = getDefineINT("TAX_INCREASE_CHANCE");
	m_cache_TAX_RATE_MAX_INCREASE = getDefineINT("TAX_RATE_MAX_INCREASE");
	m_cache_TAX_TRADE_THRESHOLD = getDefineINT("TAX_TRADE_THRESHOLD");
	m_cache_TAX_TRADE_THRESHOLD_ATTITUDE_PERCENT = getDefineINT("TAX_TRADE_THRESHOLD_ATTITUDE_PERCENT");
	m_cache_TAX_TRADE_THRESHOLD_TAX_RATE_PERCENT = getDefineINT("TAX_TRADE_THRESHOLD_TAX_RATE_PERCENT");
	m_cache_TK_AI_RESEARCH_COST_MOD_PERCENT = getDefineINT("TK_AI_RESEARCH_COST_MOD_PERCENT");
	m_cache_TK_HUMAN_RESEARCH_COST_MOD_PERCENT = getDefineINT("TK_HUMAN_RESEARCH_COST_MOD_PERCENT");
	m_cache_TK_IDEAS_CITY_VALUE = getDefineINT("TK_IDEAS_CITY_VALUE");
	m_cache_TK_MAX_FORTS_PER_CITY = getDefineINT("TK_MAX_FORTS_PER_CITY");
	m_cache_TK_PIONEER_COAL_FURNACE_BONUS = getDefineINT("TK_PIONEER_COAL_FURNACE_BONUS");
	m_cache_TK_PROLIFIC_INVENTOR_PROGRESS = getDefineINT("TK_PROLIFIC_INVENTOR_PROGRESS");
	m_cache_TK_PROLIFIC_INVENTOR_THRESHOLD = getDefineINT("TK_PROLIFIC_INVENTOR_THRESHOLD");
	m_cache_TK_RESEARCH_PACT_IDEAS_THRESHOLD = getDefineINT("TK_RESEARCH_PACT_IDEAS_THRESHOLD");
	m_cache_TK_RESEARCH_TRADE_VALUE = getDefineINT("TK_RESEARCH_TRADE_VALUE");
	m_cache_TK_STEAMWORKS_MODIFIER = getDefineINT("TK_STEAMWORKS_MODIFIER");
	m_cache_TRADE_POINTS_FOR_ROUTE = getDefineINT("TRADE_POINTS_FOR_ROUTE");
	m_cache_TRADE_ROUTE_SPICE = getDefineINT("TRADE_ROUTE_SPICE");
	m_cache_TRADE_STIMULATES_RESEARCH_MIN_VALUE = getDefineINT("TRADE_STIMULATES_RESEARCH_MIN_VALUE");
	m_cache_TRADE_STIMULATES_RESEARCH_PERCENT = getDefineINT("TRADE_STIMULATES_RESEARCH_PERCENT");
	m_cache_TRADING_POINTS_MOD_PERCENT = getDefineINT("TRADING_POINTS_MOD_PERCENT");
	m_cache_TREASURE_UNITCLASS = getDefineINT("TREASURE_UNITCLASS");
	m_cache_TREASURE_UNITS_ONLY_SELECT_COASTAL = getDefineINT("TREASURE_UNITS_ONLY_SELECT_COASTAL");
	m_cache_TURNS_TO_TRAIN = getDefineINT("TURNS_TO_TRAIN");
	m_cache_UNITARMOR_LEATHER = getDefineINT("UNITARMOR_LEATHER");
	m_cache_UNITARMOR_MAIL = getDefineINT("UNITARMOR_MAIL");
	m_cache_UNITARMOR_PLATE = getDefineINT("UNITARMOR_PLATE");
	m_cache_UNITARMOR_SCALE = getDefineINT("UNITARMOR_SCALE");
	m_cache_UNITARMOR_SHIELD = getDefineINT("UNITARMOR_SHIELD");
	m_cache_UNITCLASS_PIONEER = getDefineINT("UNITCLASS_PIONEER");
	m_cache_UNITTACTIC_PARRY = getDefineINT("UNITTACTIC_PARRY");
	m_cache_UNITWEAPON_BLUNT = getDefineINT("UNITWEAPON_BLUNT");
	m_cache_UNIT_PRODUCTION_DECAY_PERCENT = getDefineINT("UNIT_PRODUCTION_DECAY_PERCENT");
	m_cache_UNIT_PRODUCTION_DECAY_TIME = getDefineINT("UNIT_PRODUCTION_DECAY_TIME");
	m_cache_UNIT_PRODUCTION_PERCENT = getDefineINT("UNIT_PRODUCTION_PERCENT");
	m_cache_UNIT_UPGRADE_COST_PER_PRODUCTION = getDefineINT("UNIT_UPGRADE_COST_PER_PRODUCTION");
	m_cache_UNIT_VISIBILITY_RANGE = getDefineINT("UNIT_VISIBILITY_RANGE");
	m_cache_USE_MEDIEVAL_CALENDER = getDefineINT("USE_MEDIEVAL_CALENDER");
	m_cache_VASSAL_CIVILIZATION = getDefineINT("VASSAL_CIVILIZATION");
	m_cache_VASSAL_LEADER = getDefineINT("VASSAL_LEADER");
	m_cache_WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT = getDefineINT("WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT");
	m_cache_WAR_SUCCESS_ATTACKING = getDefineINT("WAR_SUCCESS_ATTACKING");
	m_cache_WAR_SUCCESS_CITY_CAPTURING = getDefineINT("WAR_SUCCESS_CITY_CAPTURING");
	m_cache_WAR_SUCCESS_DEFENDING = getDefineINT("WAR_SUCCESS_DEFENDING");
	m_cache_WAR_SUCCESS_UNIT_CAPTURING = getDefineINT("WAR_SUCCESS_UNIT_CAPTURING");
	m_cache_WATER_IMPROVEMENT = getDefineINT("WATER_IMPROVEMENT");
	m_cache_WATER_UNIT_FACING_DIRECTION = getDefineINT("WATER_UNIT_FACING_DIRECTION");
	m_cache_WEEKS_PER_MONTHS = getDefineINT("WEEKS_PER_MONTHS");
	m_cache_WILD_ANIMAL_ATTACK_WEIGHT = getDefineINT("WILD_ANIMAL_ATTACK_WEIGHT");
	m_cache_WILD_ANIMAL_LAND_BONUS_NATIVE_WEIGHT = getDefineINT("WILD_ANIMAL_LAND_BONUS_NATIVE_WEIGHT");
	m_cache_WILD_ANIMAL_LAND_FEATURE_NATIVE_WEIGHT = getDefineINT("WILD_ANIMAL_LAND_FEATURE_NATIVE_WEIGHT");
	m_cache_WILD_ANIMAL_LAND_PATROL_BASE_WEIGHT = getDefineINT("WILD_ANIMAL_LAND_PATROL_BASE_WEIGHT");
	m_cache_WILD_ANIMAL_LAND_TERRAIN_NATIVE_WEIGHT = getDefineINT("WILD_ANIMAL_LAND_TERRAIN_NATIVE_WEIGHT");
	m_cache_WILD_ANIMAL_LAND_UNIT_VARIATION_WEIGHT = getDefineINT("WILD_ANIMAL_LAND_UNIT_VARIATION_WEIGHT");
	m_cache_WILD_ANIMAL_SEA_BONUS_NATIVE_WEIGHT = getDefineINT("WILD_ANIMAL_SEA_BONUS_NATIVE_WEIGHT");
	m_cache_WILD_ANIMAL_SEA_FEATURE_NATIVE_WEIGHT = getDefineINT("WILD_ANIMAL_SEA_FEATURE_NATIVE_WEIGHT");
	m_cache_WILD_ANIMAL_SEA_PATROL_BASE_WEIGHT = getDefineINT("WILD_ANIMAL_SEA_PATROL_BASE_WEIGHT");
	m_cache_WILD_ANIMAL_SEA_TERRAIN_NATIVE_WEIGHT = getDefineINT("WILD_ANIMAL_SEA_TERRAIN_NATIVE_WEIGHT");
	m_cache_WILD_ANIMAL_SEA_UNIT_VARIATION_WEIGHT = getDefineINT("WILD_ANIMAL_SEA_UNIT_VARIATION_WEIGHT");
}
// cache XML - end - Nightinggale

#pragma once

namespace UFG
{
	class EncounterUnitComponent;
	class CombatRegion;
	class RegionComponent;
	class SensorPhantom;

	namespace EncounterUnit
	{
		enum UnitType : s32
		{
			Unknown,
			Character,
			Vehicle,
			Boat
		};
	}

	enum eAIObjective : int
	{
		eAI_OBJECTIVE_NONE,
		eAI_OBJECTIVE_ATTACK_TARGET,
		eAI_OBJECTIVE_ATTACK_NEARBY_TARGET,
		eAI_OBJECTIVE_ATTACK_WHEN_SEE_TARGET,
		eAI_OBJECTIVE_ATTACK_WHEN_STEALTH_TARGET_SPOTTED,
		eAI_OBJECTIVE_ATTACK_USING_COVER,
		eAI_OBJECTIVE_ATTACK_IN_SCRIPTED_VEHICLE,
		eAI_OBJECTIVE_SHOOT_AT_MARKER,
		eAI_OBJECTIVE_FLEE,
		eAI_OBJECTIVE_FLEE_SPREAD_PANIC,
		eAI_OBJECTIVE_FORCE_ENTER_COVER,
		eAI_OBJECTIVE_RUN_LATERALLY_FROM_TARGET,
		eAI_OBJECTIVE_INVESTIGATE_TARGET,
		eAI_OBJECTIVE_PURSUIT_TARGET,
		eAI_OBJECTIVE_FOLLOW_TARGET,
		eAI_OBJECTIVE_FACE_TARGET,
		eAI_OBJECTIVE_FACE_TARGET_WHILE_SCARED,
		eAI_OBJECTIVE_BE_ALLY,
		eAI_OBJECTIVE_GET_IN_VEHICLE,
		eAI_OBJECTIVE_GET_OUT_OF_VEHICLE,
		eAI_OBJECTIVE_BE_INTIMIDATED,
		eAI_OBJECTIVE_PATHFIND_TO_SELECTED_OBJECT,
		eAI_OBJECTIVE_HIJACK_VEHICLE,
		eAI_OBJECTIVE_IDLE,
		eAI_OBJECTIVE_MOVE_AWAY,
		eAI_OBJECTIVE_RUN_AWAY,
		eAI_OBJECTIVE_GRAB_AND_HOLD,
		eAI_OBJECTIVE_DUCK_AND_COVER,
		eAI_OBJECTIVE_DENOUEMENT,
		eAI_OBJECTIVE_WEAPON_PICKUP,
		eAI_OBJECTIVE_COMBAT_DUMMY,
		eAI_OBJECTIVE_PATHFIND_TO_POINT_WITH_BREAKOUT,
		eAI_OBJECTIVE_COMBAT_FAST_TALK,
		eAI_OBJECTIVE_ATTACK_SUCKERPUNCH_TARGET,
		eAI_OBJECTIVE_ROB_TARGET,
		eAI_OBJECTIVE_PATDOWN_TARGET,
		NUM_AI_OBJECTIVES
	};

	enum HeatLevelEnum : s32
	{
		HEATLEVEL_NONE,
		HEATLEVEL_ONE,
		HEATLEVEL_TWO,
		HEATLEVEL_THREE,
		HEATLEVEL_FOUR,
		HEATLEVEL_FIVE,
		NUM_HEAT_LEVELS
	};

	class EncounterBase : public qSafePointerNodeWithCallbacks<EncounterBase>, public SpawnInfoInterface
	{
	public:
		enum ReplenishStyle : s32
		{
			ReplenishStyle_TopUpByPopulation,
			ReplenishStyle_TopUpByWaveType
		};

		bool mEnable;
		PropertySetHandle mProperties;
		eAIObjective mObjective;
		eAIObjective mPostObjective;
		qSymbol mCurrentWaveType;
		ReplenishStyle mReplenishStyle;
		qSymbol mHeatLevelPropertiesName[6];
		qSymbol mWaterHeatLevelPropertiesName[6];
		qPropertySet* mHeatLevelProperties[6];
		qPropertySet* mWaterHeatLevelProperties[6];
		bool mPreloadedResources[6];
		u32 mInsideDynamicRadiusCount;
		HeatLevelEnum mHeatLevel;
		int mMaxHeatLevel;
		SensorPhantom* mpVehicleSpawnSensor;
		u64 mStartTimestamp;
		int mVehicleSpawnIteratingIndex;
		f32 mNonEventfulCooldownTimestamp;
		qVector3 mFocusTargetPosition;
		int mWaveCount;
		int mWavesDisabledUnitCount;
		f32 mWaveTimer;
		f32 mReplenishTimeout;
		f32 mSpawnTimeout;
		f32 mReducedRadiusTimer;
		f32 mReducedRadiusPercentage;
		bool mHasSpawnedInFrontForCurrentWave;
		bool mDisabledUnitForCurrentWave;
		bool mIsAvoidPeds;
		bool mIsAllowedToPass;
		bool mIsStaysOffSidewalk;
		bool mIsRespectSpeedLimit;
		bool mIsCanTurnAround;
		bool mSuppressVehicleSpawningByKillCount;
		bool mIsReplenishing;
		bool mInstantCooldownActive;
		bool mCoolingDown;
		bool mCooldownAllowed;
		bool mEnableWaveTimerChangesByDisabledUnits;
		EncounterUnitContext mFocusTargetContext;
		qFixedArray<EncounterUnitComponent*, 32> mHumans;
		qFixedArray<EncounterUnitComponent*, 8> mVehicles;
		qFixedArray<RegionComponent*, 20> mHumanSpawnRegions;
		EncounterUnit::UnitType mWaveGroupTypes[10];
		int mWaveGroupInstancesRequired[10];
		int mWaveGroupInstances[10];
		u32 mNumWaveGroupTypes;
		int mNumDesiredVehicleGroups;
		int mNumDesiredCharacterGroups;
		int mVehicleSpawnCount;
		int mCharacterSpawnCount;
		int mVehicleKillCount;
		int mCharacterKillCount;
		WayTraversalClient mWayTraversalClient;
		qSafePointer<SimObject> mpFocusTarget;
		qSafePointer<SimObject> mpSecondaryTarget;
		qSafePointer<CombatRegion> mpCombatRegion;
	};
	SDK_ASSERT_SIZEOF(EncounterBase, 0xC90);
}
#pragma once

namespace UFG
{
	class EncounterUnitComponent;
	class CombatRegion;
	class RegionComponent;
	class SensorPhantom;

	namespace EncounterUnit
	{
		enum UnitType
		{
			Unknown,
			Character,
			Vehicle,
			Boat
		};
	}

	enum eAIObjective
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

	enum HeatLevelEnum
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
		enum ReplenishStyle
		{
			ReplenishStyle_TopUpByPopulation,
			ReplenishStyle_TopUpByWaveType
		};

		enum UnitType
		{
			Unknown,
			Character,
			Vehicle,
			Boat
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

		/* Virtual Functions */

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void RemoveAllUnitsOnScene(bool includeNonManaged) = 0;
		virtual void Enable(bool enable) = 0;
		virtual void SetPropertySet(const char* pPropertySetName) = 0;
		virtual bool IsActive() = 0;
		virtual bool IsEnabled() = 0;
		virtual bool IsCoolingDown() = 0;
		virtual void TriggerInstantCooldown() = 0;
		virtual void Update(f32 deltaTime) = 0;
		virtual bool IsFocusTargetOnMeshHeuristic() = 0;
		virtual bool IsFocusTargetInsideInterior() = 0;
		virtual bool IsFocusTargetInWater() = 0;
		virtual bool HasFocusTargetOpenedFired() = 0;
		virtual bool HasFocusTargetOpenedFiredWithHostage() = 0;
		virtual bool IsExecutingReducedRadiusMode() = 0;
		virtual f32 GetHeatRadius(bool isOnfoot, EncounterUnitComponent* pEncounterUnitComponent = 0) = 0;
		virtual SimObject* GetFocusTarget() = 0;
		virtual void SetFocusTarget(SimObject* pTarget) = 0;
		virtual qVector3& GetFocusTargetPosition() = 0;
		virtual SimObject* GetSecondaryTarget() = 0;
		virtual void SetSecondaryTarget(SimObject* pTarget) = 0;
		virtual void Replenish() = 0;
		virtual void OnDetachEncounterUnitComponent() = 0;
		virtual void SetCurrentWaveType(const qSymbol& waveId) = 0;
		virtual qSymbol& GetCurrentWaveType() = 0;
		virtual EncounterUnitComponent* AddExternalVehicleIntoSystem(SimObject* pVehicle) = 0;
		virtual EncounterUnitComponent* AddExternalCharacterIntoSystem(SimObject* pCharacter) = 0;
		virtual int FindWaveGroupIndex(qPropertySet* pGroupPropertySet) = 0;
		virtual int GetSpawnCount() = 0;
		virtual int GetKillCount() = 0;
		virtual void _VFunc32() = 0;
		virtual qPropertySet* GetHeatLevelProperties() = 0;
		virtual bool FindGoodSpawnLocationCharacter(qPropertySet* pProperties, TransformNodeComponent* pTargetTransform, qVector3* pResult) = 0;
		virtual u32 GetDesiredVehiclePopulation(qPropertySet* heatPropSet) = 0;
		virtual u32 GetDesiredOnFootPopulation(qPropertySet* heatPropSet) = 0;
		virtual void Forget(EncounterUnitComponent* pEncounterUnitComponent) = 0;
		virtual void UpdateSpawnTimeout(f32 deltaTime) = 0;
		virtual void UpdateHeatTimer(f32 deltaTime, f32 currentTime) = 0;
		virtual void CountInsideRadiusObjects() = 0;
		virtual void UpdatePopulation(f32 deltaTime) = 0;
		virtual void UpdateOnFootPopulation(SimObject* pTarget, TransformNodeComponent* pTargetTransform) = 0;
		virtual void UpdateVehiclePopulation(SimObject* pTargetVehicle, TransformNodeComponent* pTargetTransform) = 0;
		virtual u32 CountActualUnits(UnitType unitType) = 0;
		virtual void HandlePreloadResources(int level) = 0;
		virtual void HandleUnloadResources(int level) = 0;
		virtual bool IsCorrectResourceType(SimObject* pTarget) = 0;
		virtual bool Reacquire(UnitType unitType, SimObject* pPlayer, TransformNodeComponent* pPlayerTransform, SimObject** pExisting) = 0;
		virtual void UpdateDesiredPopulation() = 0;
		virtual void HandleHeatLevelChange() = 0;
		virtual void UpdateVehicleFlags(SimObject* pSimObject) = 0;
		virtual u32 GetDesiredNumOccupants(qPropertySet* pGroupPropertySet, qArray<u32>& vehicleResource) = 0;
		virtual bool FillVehicleOccupants(qMatrix44* pSpawnTransform, u32 desiredNumOccupants, qPropertySet* pGroupPropertySet, SimObjectVehicle* pVehicle, const qSymbol& characterResource) = 0;
		virtual bool IsSuitableSpawnPointByRoadProperty(UnitType unitType, RoadNetworkSpawnPoint* pSpawnPoint) = 0;
		virtual bool IsSuitableByRoadProperty(UnitType unitType, RoadNetworkSegment* pSegment) = 0;
		virtual bool GenerateVehicleSpawnTransform(bool enableForwardSpawning, SimObject* pTargetVehicle, TransformNodeComponent* pTargetTransform, qMatrix44* pTransform, bool* location_is_on_screen, bool enableDebugDraw) = 0;
		virtual bool IsGoodVehicleSpawnTransform(const qMatrix44* pTransform) = 0;
		virtual bool IsInvalidReacquirePosition(const qVector3& position) = 0;
		virtual bool IsInvalidOnFootPosition(const qVector3& position) = 0;
		virtual bool IsInvalidVehiclePosition(const qVector3& position) = 0;
		virtual bool IsOnFootMode() = 0;
		virtual void VisualizeNearByRoads(qPropertySet* pProperties, TransformNodeComponent* pTargetTransform) = 0;
		virtual void VisualizeFocusTargetContext() = 0;
		virtual void VisualizeRoles() = 0;
		virtual int VisualizeEncounterUnitsInfo(int x, int startY) = 0;
		virtual bool HandleVehicleSpawn(SimObject* pTargetVehicle, TransformNodeComponent* pTargetTransform) = 0;
		virtual EncounterUnitComponent* HandleOnFootSpawn(qMatrix44* pSpawnTransform, qPropertySet* pGroupPropertySet, const qSymbol* pSpecificCharacterResource) = 0;
		virtual void HandleOnFootSpawnPost(SimObject* pOnFootSpawn) = 0;
		virtual void Acquire(EncounterUnitComponent* pEncounterUnitComponent, qPropertySet* pGroupPropertySet) = 0;
		virtual void HandleLastCharacterKill(EncounterUnitComponent* pEncounterUnit) = 0;
		virtual bool IsCharacterInUseHeuristic(EncounterUnitComponent* pEncounterUnitComponent) = 0;
		virtual bool IsVehicleInUseHeuristic(EncounterUnitComponent* pEncounterUnitComponent) = 0;
		virtual bool IsCorrectWaveHeuristic(EncounterUnitComponent* pEncounterUnitComponent) = 0;
		virtual bool IsVehicleUsableByDistance(EncounterUnitComponent* pEncounterUnitComponent) = 0;
		virtual u32 CountActiveUnits(UnitType unitType) = 0;
		virtual void UpdateWaveGroupStats() = 0;
		virtual bool IsAlive(EncounterUnitComponent* pEncounterUnitComponent) = 0;
		virtual bool IsInFight(EncounterUnitComponent* pEncounterUnitComponent) = 0;
		virtual bool IsVisible(EncounterUnitComponent* pEncounterUnitComponent) = 0;
		virtual void UpdateVehicleStatus(f32 deltaTime, EncounterUnitComponent* pEncounterUnitComponent) = 0;
		virtual void HandleVehicleAcquired(EncounterUnitComponent* pEncounterUnitComponent, qPropertySet* pEncounterPropertySet, qPropertySet* pGroupPropertySet) = 0;
		virtual const char* GetSpawningPrefix(bool isCharacter) = 0;
		virtual void UpdateRoleAssignments() = 0;
		virtual f32 GetSpawnTimeout() = 0;
	};
	SDK_ASSERT_SIZEOF(EncounterBase, 0xC90);
}
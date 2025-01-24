#pragma once

namespace UFG
{
	enum eEncounterRole
	{
		eENCOUNTER_ROLE_NONE,
		eENCOUNTER_ROLE_ENFORCER,
		eENCOUNTER_ROLE_SUPPORTER,
		NUM_ENCOUNTER_ROLES_TYPES
	};

	class EncounterUnitContext
	{
	public:
		SimObject* mpSimObject;
		SimObject* mpVehicle;
		f32 mWaterContextTimer;
		bool mIsOnFootRaw;
		bool mIsInsideInterior;
		bool mIsInWater;
		bool mIsOnFootHeuristic;
		bool mIsOnMeshHeuristic;
		bool mOpenFired;
		bool mOpenFiredWithHostage;
	};
	SDK_ASSERT_SIZEOF(EncounterUnitContext, 0x20);

	class EncounterUnitComponent : public SimComponent
	{
	public:
		enum { _TypeUID = 0x6A000001 };

		eEncounterRole mRole;
		qSafePointerWithCallbacks<class EncounterBase> mpEncounter;
		qSymbol mWaveType;
		i8 mWaveTypeGroupIndex;
		i8 mUsageCount;
		bool mEngaged;
		bool mUnitDisabled;
		bool mEnableKillCount;
		f32 mInsideRadiusTimer;
		f32 mAcquiredTimer;
		f32 mVehicleFlipTimer;
		qSafePointer<SimObject> mGroupVehicle;
		ObjectiveIndicator* mpObjectiveIndicator;
		EncounterUnitContext mContext;

		/* Functions */

		void AcquireBy(EncounterBase* pEncounter, qPropertySet* pGroupPropertySet) { SDK_CALL_FUNC(void, 0x3F2E90, void*, EncounterBase*, qPropertySet*)(this, pEncounter, pGroupPropertySet); }
		void DecrementGroupVehicleUsageCount() { SDK_CALL_FUNC(void, 0x3F39F0, void*)(this); }
		void IncrementGroupVehicleUsageCount() { SDK_CALL_FUNC(void, 0x3F7BC0, void*)(this); }
		void ReleaseByEncounter() { SDK_CALL_FUNC(void, 0x3F8EF0, void*)(this); }
		void SetGroupVehicle(SimObject* transformNodeRoot) { SDK_CALL_FUNC(void, 0x1BE540, void*, SimObject*)(this, transformNodeRoot); }
	};
	SDK_ASSERT_SIZEOF(EncounterUnitComponent, 0xE0);
}
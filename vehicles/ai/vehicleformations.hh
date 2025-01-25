#pragma once

namespace UFG
{
	class VehicleFormationCombatStats
	{
	public:
		f32 mLastAttack[CarCombat::NumFormationAttacks];
		u32 mNumAttacks[CarCombat::NumFormationAttacks];
	};

	class VehicleFormations
	{
	public:
		enum FormationHeuristic
		{
			FORMATIONHEURISTIC_GENERIC,
			FORMATIONHEURISTIC_GENERIC_FAVOR_FRONT,
			FORMATIONHEURISTIC_GENERIC_FAVOR_BACK,
			FORMATIONHEURISTIC_ESCORT
		};

		struct VehicleSlotDef
		{
			SimObject* vehicle;
			qVector3 vehiclePosition;
			f32 vehicleAngle;
			int vehicleSide;
			i8 vehicleAvailability;
		};

		VehicleSubjectComponent* mpSubject;
		qList<SimObjectPointer>* mpVehicles;
		FormationHeuristic mHeuristic;
		qSafePointer<SimObject> mpSecondaryTarget;
		qSafePointer<SimObject> mpClosestToSecondaryTarget;
		qSafePointer<SimObject> mSlots[2][CarCombat::NumAttacks];
		bool mSlotUsable[2][CarCombat::NumAttacks];
		bool mSlotUsableProcessed[2][CarCombat::NumAttacks];
		bool mSlotAttacked[2][CarCombat::NumAttacks];
		i8 mSlotWeight[2][CarCombat::NumAttacks];
		qVector3 mSlotOffsets[CarCombat::NumAttacks];
		VehicleFormationCombatStats mCombatStats;
		CarCombat::FormationAttack mCurrentAttack;
		RoadNetworkSegment* mpClosestSegment;
		int mClosestLaneIndex;
		f32 mTimeSinceClosestLaneChanged;
		f32 mTimeSinceFormationRequest;
		f32 mTimeInFormation;
		int mParticipantCount;
		bool mCustomFormation;
		bool mAllSlotsAssigned;
		bool mUpdateRequested;
		bool mFormationAvailable;

		/* Functions */

		f32 CalculateSecondaryTargetScore(const qVector3& myPosition, const qVector3& slotPosition, const qVector3& secondaryTargetPosition) { 
			return SDK_CALL_FUNC(f32, 0x6740A0, void*, const qVector3&, const qVector3&, const qVector3&)(this, myPosition, slotPosition, secondaryTargetPosition); 
		}
		void EndAttack(SimObject* pVehicle) { SDK_CALL_FUNC(void, 0x677D90, void*, SimObject*)(this, pVehicle); }
		void OverrideSlotOffsets(qPropertySet* pSlotOffsetProperties) { SDK_CALL_FUNC(void, 0x685DC0, void*, qPropertySet*)(this, pSlotOffsetProperties); }
		void SetSecondaryTarget(SimObject* pSecondaryTarget) { SDK_CALL_FUNC(void, 0x3F97D0, void*, SimObject*)(this, pSecondaryTarget); }
		void SetSlotUsability(CarCombat::Position position, bool usable) { SDK_CALL_FUNC(void, 0x68B530, void*, CarCombat::Position, bool)(this, position, usable); }
	};
	SDK_ASSERT_SIZEOF(VehicleFormations, 0x268);
}
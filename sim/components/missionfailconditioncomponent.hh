#pragma once

namespace UFG
{
	class MissionFailConditionComponent : public SimComponent, public qNode<MissionFailConditionComponent>
	{
	public:
		enum { _TypeUID = 0x9E000001 };

		SceneObjectProperties* mpDistanceFailObject;
		GameSlice* mpCustomGameSlice;
		bool mIsPanicking;
		bool mIsDistanceFailTriggerEnabled;
		f32 mVehicleFlippedTimer;
		f32 mBoatStuckTimer;
		f32 mDamageHealthThreshold;
		f32 mDistanceFailThreshold;
		bool mArrestFailTrigger;
		bool mDeathFailTrigger;
		bool mDamageFailTrigger;
		bool mDistanceFailTrigger;
		bool mPanicWeaponFailTrigger;
		bool mPanicVehicleFailTrigger;
		bool mVehicleFlipFailTrigger;
		bool mBoatStuckFailTrigger;
		qSharedString mArrestFailCaption;
		qSharedString mDeathFailCaption;
		qSharedString mDamageFailCaption;
		qSharedString mDistanceFailCaption;
		qSharedString mPanicWeaponFailCaption;
		qSharedString mPanicVehicleFailCaption;
		qSharedString mVehicleFlipFailCaption;
		qSharedString mBoatStuckFailCaption;

		/* Functions */

		void EnableDistanceFailTrigger(bool enable) { SDK_CALL_FUNC(void, 0x5269A0, void*, bool)(this, enable); }
		void FailObject(SimObject* simObject, const qSymbol& captionType) { SDK_CALL_FUNC(void, 0x527C70, SimObject*, const qSymbol&)(simObject, captionType); }
		f32 GetFailThreshold(const qSymbol& triggerName) { return SDK_CALL_FUNC(f32, 0x52D040, void*, const qSymbol&)(this, triggerName); }
		MissionFailConditionComponent* HandleAttachment(GameSlice* pGameSlice, SimObject* pSimObject, component_MissionFailCondition* data_ptr) {
			return SDK_CALL_FUNC(MissionFailConditionComponent*, 0x5339A0, GameSlice*, SimObject*, component_MissionFailCondition*)(pGameSlice, pSimObject, data_ptr); 
		}
		void SetFailCaption(SimObject* pSimObject, const qSymbol& triggerName, const char* caption) { 
			SDK_CALL_FUNC(void, 0x54C9A0, SimObject*, const qSymbol&, const char*)(pSimObject, triggerName, caption); 
		}
		void SetFailThreshold(SimObject* pSimObject, const qSymbol& triggerName, f32 threshold) { SDK_CALL_FUNC(void, 0x54CC40, SimObject*, const qSymbol&, f32)(pSimObject, triggerName, threshold); }
		void SetFailTrigger(SimObject* pSimObject, const qSymbol& triggerName, bool enabled) { SDK_CALL_FUNC(void, 0x54CE70, SimObject*, const qSymbol&, bool)(pSimObject, triggerName, enabled); }
	};
	SDK_ASSERT_SIZEOF(MissionFailConditionComponent, 0xC0);
}
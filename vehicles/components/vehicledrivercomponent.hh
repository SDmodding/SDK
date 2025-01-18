#pragma once

namespace UFG
{
	enum VehicleState : i32
	{
		UNINITIALIZED,
		PARKED,
		DRIVING,
		STOP_AT_POWERSLIDE,
		FORCESTOP,
		UNCONTROLLED
	};

	class VehicleDriverInterface : public SimComponent, public UpdateInterface, public qNode<VehicleDriverInterface>
	{
	public:
		enum { _TypeUID = 0xD8000001 };

		RebindingComponentHandle<PhysicsMoverInterface> mMoverComponent;
		RebindingComponentHandle<VehicleEffectsComponent> mRenderComponent;
		RebindingComponentHandle<VehicleAudioComponent> mAudioComponent;
		qSafePointer<SimObject> mDriver;
		VehicleState mState;
		VehicleState mDesiredState;
		float mReverseLockoutDelay;
		qPropertySet* mPropertySet;
		bool mForceDock;
		TransformNodeComponent* m_ChaseSpawnTransform;
		bool mBreakOnUpdate;

		/* Impl Functions */

		SDK_INLINE void SetDesiredState(VehicleState state) { mDesiredState = state; }

		/* Functions */

		void DismountAndUpdate() { SDK_CALL_FUNC(void, 0x676B40, void*)(this); }
		void EjectDriver() { SDK_CALL_FUNC(void, 0x6773D0, void*)(this); }
		TransformNodeComponent* GetChaseSpawnTransform(f32 distance_behind) { return SDK_CALL_FUNC(TransformNodeComponent*, 0x679CC0, void*, f32)(this, distance_behind); }
		void Parked() { SDK_CALL_FUNC(void, 0x685E60, void*)(this); }
		void SetDriver(SimObject* driver) { SDK_CALL_FUNC(void, 0x68A6B0, void*, SimObject*)(this, driver); }
		void StartEngineAudio() { SDK_CALL_FUNC(void, 0x68C320, void*)(this); }
		void Uncontrolled() { SDK_CALL_FUNC(void, 0x68EC70, void*)(this); }
	};
}
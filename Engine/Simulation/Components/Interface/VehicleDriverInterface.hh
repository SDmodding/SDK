#pragma once

namespace UFG
{
	enum VehicleState : uint32_t
	{
		VehicleState_Uninitialized = 0,
		VehicleState_Parked,
		VehicleState_Driving,
		VehicleState_ForceStop,
		VehicleState_Uncontrolled
	};

	//======================================================================

	class VehicleDriverInterface : public SimComponent, public CUpdateInterface, public qNode<VehicleDriverInterface>
	{
	public:
		RebindingComponentHandle<class PhysicsMoverInterface> mMoverComponent;
		RebindingComponentHandle<class VehicleEffectsComponent> mRenderComponent;
		RebindingComponentHandle<class CVehicleAudioComponent> mAudioComponent;
		qSafePointer<SimObject> mDriver;
		VehicleState mState;
		VehicleState mDesiredState;
		float mReverseLockoutDelay;
		qPropertySet* mPropertySet;
		bool mForceDock;
		class TransformNodeComponent* m_ChaseSpawnTransform;
		bool mBreakOnUpdate;
	}; typedef VehicleDriverInterface CVehicleDriverInterface;
	UFG_ASSERT_CLASS(VehicleDriverInterface, 0x130);
}
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

	class CVehicleDriverInterface : public SimComponent, public CUpdateInterface, public qNode<CVehicleDriverInterface>
	{
	public:
		RebindingComponentHandle<class CPhysicsMoverInterface> mMoverComponent;
		RebindingComponentHandle<class CVehicleEffectsComponent> mRenderComponent;
		RebindingComponentHandle<class CVehicleAudioComponent> mAudioComponent;
		qSafePointer<SimObject> mDriver;
		VehicleState mState;
		VehicleState mDesiredState;
		float mReverseLockoutDelay;
		qPropertySet* mPropertySet;
		bool mForceDock;
		class CTransformNodeComponent* m_ChaseSpawnTransform;
		bool mBreakOnUpdate;
	};
	UFG_ASSERT_CLASS(CVehicleDriverInterface, 0x130);
}
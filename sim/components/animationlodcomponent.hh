#pragma once

namespace UFG
{
	class AnimationLODComponent : public SimComponent, public qNode<AnimationLODComponent>
	{
	public:
		enum { _TypeUID = 0xB6000001 };

		bool mHasBeenUpdatedOnce;
		u32 mSequenceID;
		u32 mUpdatePeriod;
		u32 mMinUpdatePeriod;
		RebindingComponentHandle<CharacterAnimationComponent> mCharacterAnimationComponent;
		RebindingComponentHandle<FacialActionTreeComponent> mFacialActionTreeComponent;
		RebindingComponentHandle<CompositeDrawableComponent> mCompositeDrawableComponent;
		RebindingComponentHandle<WorldContextComponent> mWorldContextComponent;
		qSafePointer<Creature> mCreature;
		bool mForceHighLOD : 1;
		bool mExtendedLOD : 1;
		bool mForceHighLODOneFrame : 1;
		bool mRagdollLock : 1;
		qList<AnimationLockHighLODTask> m_AnimationLockHighLODList;

		/* Functions */

		void AddAnimationLockHighLODTask(AnimationLockHighLODTask* pAnimationLockHighLODTask) { SDK_CALL_FUNC(void, 0x520910, void*, AnimationLockHighLODTask*)(this, pAnimationLockHighLODTask); }
		void MakeHighLOD() { SDK_CALL_FUNC(void, 0x53CAD0, void*)(this); }
		void SetExtendedLOD(bool extended_lod) { SDK_CALL_FUNC(void, 0x54C8E0, void*, bool)(this, extended_lod); }
		void getLodTestPoint(qVector3& testWorldPosition) { SDK_CALL_FUNC(void, 0x5686A0, qVector3&)(testWorldPosition); }
	};
	SDK_ASSERT_SIZEOF(AnimationLODComponent, 0x150);
}
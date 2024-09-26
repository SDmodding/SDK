#pragma once

namespace UFG
{
	class CCreature : public qSafePointerNode<CCreature>
	{
	public:
		qList<void*> mPoseDrivers;
		bool mNetworkLock;

		UFG_PAD(0x3);

		enum PoseState
		{
			UPDATED = 0x0,
			UPDATED_FROM_CACHE = 0x1,
			SUBMITTED = 0x2,
			SYNCED = 0x3,
		};
		PoseState mPoseState;

		uint32_t mPoseCRC;

		UFG_PAD(0xC);

		hkQsTransformf mPrevMotion;
		hkQsTransformf mLastSetPosition;
		qVector3 mGroundNormal;
		qList<CAttachment> mAttachments;
		qVector3 mAnimatedMoveDirection;
		float mAnimatedMoveSpeed;
		bool mIsAttached;
		int mForceTransparencyTarget;
		char mIsEndEffectorCache[4];
		uint32_t mPoseFrame;
		void* mPoseTask;
		uint32_t mCurrentStackDepth;
		bool mCorrected;
		CSkeletalPose mPose;

		UFG_PAD(0x88);
		//PoseNodeParent mBlendTree;

		bool mHaventUpdated;
		bool mLowPowerModeEnabled;
		bool mAbsoluteMonSet;
		bool mAbsoluteRelativeRootMotion;
		bool mRestPosePrev;

		UFG_PAD(0x80);
		//PoseTaskInputParams mPoseTaskParams;

		qMatrix44 mAbsoluteMon;
		qMatrix44 mAbsoluteRelativeRoot;
		bool mIsSlopeLocomotionFixupEnabled;
		float mMaxSlopeLocomotionFixupAngle;
		bool mPlaybackSpeedEnabled;
		float mPlaybackSpeed;
		float mRagdollBlendWeight;
		bool mDisablePosedrivers;
		uint32_t mNetPoseSequence;

		// HashUpper32
		UFG_INLINE int GetBoneID(uint32_t p_BoneUID)
		{
			if (!mPose.mRigHandle.mData) {
				return -1;
			}

			return mPose.mRigHandle.mUFGSkeleton->GetBoneID(p_BoneUID);
		}

		UFG_INLINE void GetPositionhkQ(hkQsTransformf* p_Result)
		{
			reinterpret_cast<void(__fastcall*)(void*, hkQsTransformf*)>(UFG_RVA(0x3A9570))(this, p_Result);
		}
		
		UFG_INLINE void MakeUpright(float p_fUprightTime)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x3AB730))(this, p_fUprightTime);
		}

		//==========================================================
		// Attachments

		CAttachment* GetAttachment(SimObject* p_AttachedSimObject)
		{
			for (auto i = mAttachments.mNode.mNext; i != &mAttachments.mNode; i = i->mNext)
			{
				CAttachment* _Attachment = i->GetPointerSub<offsetof(CAttachment, mNode)>();
				if (_Attachment->mAttachedSimObject.m_pPointer == p_AttachedSimObject) {
					return _Attachment;
				}
			}
			
			return nullptr;
		}

		CAttachment* GetAttachment(int p_AttachBoneID)
		{
			for (auto i = mAttachments.mNode.mNext; i != &mAttachments.mNode; i = i->mNext)
			{
				CAttachment* _Attachment = i->GetPointerSub<offsetof(CAttachment, mNode)>();
				if (_Attachment->attachedJoint == p_AttachBoneID) {
					return _Attachment;
				}
			}

			return nullptr;
		}

		UFG_INLINE void* AddAttachment(SimObject* p_Self, int p_AttachBoneID, SimObject* p_AttachedSimObject, int p_AttachmentBoneID, bool p_PositionOnly = false, float p_BlendIn = 0.f)
		{
			return reinterpret_cast<void*(__fastcall*)(void*, SimObject*, int, SimObject*, int, bool, float)>(UFG_RVA(0x3A0BE0))(this, p_Self, p_AttachBoneID, p_AttachedSimObject, p_AttachmentBoneID, p_PositionOnly, p_BlendIn);
		}

		UFG_INLINE bool RemoveAttachment(SimObject* p_Self, SimObject* p_AttachedSimObject, int p_AttachBoneID = -1)
		{
			if (p_AttachBoneID == -1)
			{
				auto pAttachment = GetAttachment(p_AttachedSimObject);
				if (!pAttachment) {
					return false;
				}

				p_AttachBoneID = pAttachment->attachedJoint;
			}

			return reinterpret_cast<bool(__fastcall*)(void*, SimObject*, int, SimObject*)>(UFG_RVA(0x3ADFB0))(this, p_Self, p_AttachBoneID, p_AttachedSimObject);
		}
	};
	UFG_ASSERT_CLASS(CCreature, 0x3A0);
}
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

		UFG_PAD(0x60 + 0xC);
		/*hkQsTransformf mPrevMotion;
		hkQsTransformf mLastSetPosition;*/

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
		int GetBoneID(uint32_t m_BoneUID)
		{
			if (!mPose.mRigHandleData)
				return -1;

			return mPose.mUFGSkeleton->GetBoneID(m_BoneUID);
		}

		void GetTranslation(int m_BoneID, qVector3* m_Result)
		{
			mPose.GetTranslation(m_BoneID, m_Result);
		}

		void GetTranslation(int m_BoneID, qMatrix44* m_Result)
		{
			mPose.GetTranslation(m_BoneID, m_Result);
		}

		CAttachment* GetAttachment(UFG::CSimObject* m_AttachedSimObject)
		{
			for (qNode<CAttachment>* i = mAttachments.mNode.mNext; i != &mAttachments.mNode; i = i->mNext)
			{
				CAttachment* m_Attachment = i->GetPointerSub<offsetof(CAttachment, mNode)>();
				if (m_Attachment->mAttachedSimObject.m_pPointer == m_AttachedSimObject)
					return m_Attachment;
			}
			
			return nullptr;
		}

		void* AddAttachment(UFG::CSimObject* m_Self, int m_AttachBoneID, UFG::CSimObject* m_AttachedSimObject, int m_AttachmentBoneID, bool m_PositionOnly = false, float m_BlendIn = 0.f)
		{
			return reinterpret_cast<void*(__fastcall*)(void*, UFG::CSimObject*, int, UFG::CSimObject*, int, bool, float)>(UFG_RVA(0x3A0BE0))(this, m_Self, m_AttachBoneID, m_AttachedSimObject, m_AttachmentBoneID, m_PositionOnly, m_BlendIn);
		}

		bool RemoveAttachment(UFG::CSimObject* m_Self, UFG::CSimObject* m_AttachedSimObject, int m_AttachBoneID = -1)
		{
			if (m_AttachBoneID == -1)
			{
				UFG::CAttachment* m_Attachment = GetAttachment(m_AttachedSimObject);
				if (!m_Attachment)
					return false;

				m_AttachBoneID = m_Attachment->attachedJoint;
			}

			return reinterpret_cast<bool(__fastcall*)(void*, UFG::CSimObject*, int, UFG::CSimObject*)>(UFG_RVA(0x3ADFB0))(this, m_Self, m_AttachBoneID, m_AttachedSimObject);
		}
	};
}
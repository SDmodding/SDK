#pragma once

namespace UFG
{
	class CTransformNodeComponent;

	class CSkeleton
	{
	public:
		uint32_t mNameUID;
		hkaSkeleton* mhkaSkeleton;

		struct BoneLookUpEntry_t
		{
			uint32_t guid;
			int index;
		};
		BoneLookUpEntry_t* mBoneIDLookup;

		uint32_t* mBoneNameHashIDs;
		void* mWeightSetData;
		float mBoneScale;
		qMatrix44* mInverseModelSpace;

		uint32_t GetBoneUID(int p_BoneID)
		{
			for (int i = 0; mhkaSkeleton->m_bones.m_size > i; ++i)
			{
				if (mBoneIDLookup[i].index == p_BoneID) {
					return mBoneIDLookup[i].guid;
				}
			}

			return -1;
		}

		UFG_INLINE int GetBoneID(uint32_t p_BoneUID)
		{
			return reinterpret_cast<int(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x1B9390))(this, p_BoneUID);
		}
	};

	class CSkeletalPose
	{
	public:
		int mBoneUpdateCount;

		UFG_PAD(0xC);

		qMatrix44 mRootMatrix44;

		UFG_PAD(0x30);
		//hkQsTransformf mRootQsMatrix;

		uint32_t mIsRootDirty;
		uint32_t mCachedTransformChangeID;
		qVector3 mPoseAABBMin;
		qVector3 mPoseAABBMax;
		qSafePointer<CTransformNodeComponent> mRootTransformNode;

		struct RigHandle_t : qResourceHandle
		{
			void* mLoadFunction;
			void* mUnloadFunction;
			void* mUserData;
			CSkeleton* mUFGSkeleton;
		};
		RigHandle_t mRigHandle;

		void* mHavokPose;

		// (Translation) Get

		void GetTranslationWS(int p_BoneID, qVector3* p_Translation)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qVector3*)>(UFG_RVA(0x1BBE10))(this, p_BoneID, p_Translation);
		}

		// (Position) Set

		void SetPositionLS(int p_BoneID, qMatrix44* p_Matrix)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qMatrix44*)>(UFG_RVA(0x1BC5B0))(this, p_BoneID, p_Matrix);
		}

		void SetPositionMS(int p_BoneID, qMatrix44* p_Matrix)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qMatrix44*)>(UFG_RVA(0x1BC940))(this, p_BoneID, p_Matrix);
		}

		void SetPositionMS_ReNormalize(int p_BoneID, qMatrix44* p_Matrix)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qMatrix44*)>(UFG_RVA(0x1BCCD0))(this, p_BoneID, p_Matrix);
		}

		void SetPositionWS(int p_BoneID, qMatrix44* p_Matrix)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qMatrix44*)>(UFG_RVA(0x1BD0C0))(this, p_BoneID, p_Matrix);
		}

		// (Position) Get

		void GetPositionLS(int p_BoneID, qMatrix44* p_Matrix)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qMatrix44*)>(UFG_RVA(0x1BB790))(this, p_BoneID, p_Matrix);
		}

		void GetPositionMS(int p_BoneID, qMatrix44* p_Matrix)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qMatrix44*)>(UFG_RVA(0x1BBA30))(this, p_BoneID, p_Matrix);
		}

		void GetPositionMS_ReNormalize(int p_BoneID, qMatrix44* p_Matrix)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qMatrix44*)>(UFG_RVA(0x1BBA90))(this, p_BoneID, p_Matrix);
		}

		void GetPositionWS(int p_BoneID, qMatrix44* p_Matrix)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qMatrix44*)>(UFG_RVA(0x1BBB90))(this, p_BoneID, p_Matrix);
		}
	};
}
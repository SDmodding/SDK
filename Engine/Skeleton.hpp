#pragma once

namespace UFG
{
	class CTransformNodeComponent;

	class CHavokBone // hkaBone
	{
	public:
		const char* m_name;
		bool m_lockTranslation;
	};

	class CHavokSkeleton // hkaSkeleton
	{
	public:
		UFG_PAD(0x10);

		const char* m_name;
		HavokArray<short> m_parentIndices;
		HavokArray<CHavokBone> m_bones;
		HavokArray<void*> m_referencePose;
		HavokArray<float> m_referenceFloats;
		HavokArray<const char*> m_floatSlots;
		HavokArray<void*> m_localFrames;
		HavokArray<void*> m_partitions;
	};

	class CSkeleton
	{
	public:
		uint32_t mNameUID;
		CHavokSkeleton* mhkaSkeleton;

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

		uint32_t GetBoneUID(int m_BoneID)
		{
			for (int i = 0; mhkaSkeleton->m_bones.m_size > i; ++i)
			{
				if (mBoneIDLookup[i].index == m_BoneID)
					return mBoneIDLookup[i].guid;
			}

			return -1;
		}

		int GetBoneID(uint32_t m_BoneUID)
		{
			return reinterpret_cast<int(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x1B9390))(this, m_BoneUID);
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

		UFG_PAD(0x10);

		struct RigHandle_t
		{
			void* mData;
			uint32_t mNameUID;

			UFG_PAD(0x1C);
		};
		RigHandle_t mRigHandle;

		CSkeleton* mUFGSkeleton;
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
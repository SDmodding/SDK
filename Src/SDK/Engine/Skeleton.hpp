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

		void* mRigHandleData;

		UFG_PAD(0x20);

		CSkeleton* mUFGSkeleton;
		void* mHavokPose;

		void GetTranslation(int m_BoneID, qVector3* m_Result)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qVector3*)>(UFG_RVA(0x1BBE10))(this, m_BoneID, m_Result);
		}

		void GetTranslation(int m_BoneID, qMatrix44* m_Result)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, qMatrix44*)>(UFG_RVA(0x1BBB90))(this, m_BoneID, m_Result);
		}
	};
}
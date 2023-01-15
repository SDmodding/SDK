#pragma once

namespace UFG
{
	class CCreature
	{
	public:
		UFG_PAD(0xD0);

		bool mIsAttached;

		UFG_PAD(0xE7);

		void* mRigHandleData;

		UFG_PAD(0x20);

		CSkeleton* mUFGSkeleton;

		int GetBoneID(int boneUID)
		{
			if (!mRigHandleData)
				return -1;

			return mUFGSkeleton->GetBoneID(boneUID);
		}

		void GetTranslation(qVector3* result, int boneID)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, int)>(UFG_RVA(0x3A96E0))(this, result, boneID);
		}
	};
}
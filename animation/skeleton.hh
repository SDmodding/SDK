#pragma once

class Skeleton
{
public:
	u32 mNameUID;
	hkaSkeleton* mhkaSkeleton;
	UFG::RigResource::BoneLookupEntry* mBoneIDLookup;
	u32* mBoneNameHashIDs;
	WeightSetGroup* mWeightSetData;
	f32 mBoneScale;
	UFG::qMatrix44* mInverseModelSpace;

	/* Functions */

	u32 GetBoneID(u32 boneUID) { return SDK_CALL_FUNC(u32, 0x1B9390, void*, u32)(this, boneUID); }
	bool IsParent(int parentID, int childID) { return SDK_CALL_FUNC(bool, 0x1B9440, void*, int, int)(this, parentID, childID); }
	void setHkaSkeleton(UFG::RigResource* res) { SDK_CALL_FUNC(void, 0x1B9490, void*, UFG::RigResource*)(this, res); }
};
SDK_ASSERT_SIZEOF(Skeleton, 0x38);
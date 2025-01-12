#pragma once

class Skeleton;

namespace UFG
{
	class RigResource : public qResourceData
	{
	public:
		struct CollisionMap
		{
			u32 boneIndex;
			u32 collisionGuid;
		};

		struct BoneLookupEntry
		{
			u32 guid;
			u32 index;
		};

		struct ModelMap
		{
			u32 boneIndex;
			u32 modelGuid;
		};


		qSymbol mPropertySetName;
		u32 mHavokMemImagedDataSize;
		hkaSkeleton* mSkeleton;

		union
		{
			void* mStreamingFixups;
			hkPackfileData* mLoadedData;
		};

		u32* mBoneNameGuids;
		BoneLookupEntry* mBoneNameToIndexLookup;
		u32 mNumModelMap;
		ModelMap* mModelMap;
		u32 mNumCollisionMap;
		CollisionMap* mCollisionMap;
		u32 mNumSkins;
		u32* mSkinGuids;
		u32 mNumSkinMorphs;
		u32* mSkinMorphGuids;
		u32* mSkinMorphBaseSkinID;
		qMatrix44* mInverseModelSpace;
		u32 mNumDamageMarkers;
		u32* mDamageMarkers;
		u32 mNumTriggerDamageMarkers;
		u32* mTriggerDamageMarkers;
		u32 mNumBaseDamageMarkers;
		u32* mBaseDamageMarkers;
		u32* mBaseDamageMarkerCounts;
		Skeleton* mUFGSkeleton;
	};
	SDK_ASSERT_SIZEOF(RigResource, 0x110);

	class RigHandle : public qTypedResourceHandle<RTypeUID_RigResource, RigResource>
	{
	public:
		void(__fastcall* mLoadFunction)(RigHandle*, void*);
		void(__fastcall* mUnloadFunction)(RigHandle*, void*);
		void* mUserData;
		Skeleton* mUFGSkeleton;
	};
}
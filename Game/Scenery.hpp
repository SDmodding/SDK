#pragma once

namespace UFG
{
	class CSceneryObject
	{
	public:
		uint32_t mNameUID;
		uint32_t mFlags;

		UFG_PAD(0x8);

		qResourceHandle mModelHandles[2];
		char mName[64];
	};

	class CSceneryInstance
	{
	public:
		uint32_t mNameUID;
		uint16_t mTintIndex;
		uint16_t mHierarchySkip;
		char mFlags;
		char mTransparencyState[3];
		qOffset64<CSceneryObject> mObject;

		UFG_PAD(0x8);

		qMatrix44 mLocalWorld;
	};

	class CSceneryTintEntry
	{
	public:
		qVector4 mTintColour;
		qVector4 mSITintColour;
	};

	class CSceneryGroup : public qResourceData
	{
	public:
		uint16_t mNumObjects;
		uint16_t mNumInstances;
		uint16_t mNumOccluders;
		uint16_t mNumColours;
		qOffset64<CSceneryObject> mObjects;
		qOffset64<CSceneryInstance> mInstances;
		qOffset64<class CCullInfo*> mCullInfo;
		qOffset64<class CCullInfoFull*> mOccluderInfo;
		qOffset64<CSceneryTintEntry> mInstanceColours;
		class CSceneryGroupComponent* mRenderComponent;
		qVector3 mAABBMin;
		qVector3 mAABBMax;
		uint16_t mSectionCellIndex;
		uint16_t mSectionVisIndex;
		uint16_t mSceneryLayer;
		uint16_t mFlags;
	};
}
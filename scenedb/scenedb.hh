#pragma once

namespace UFG
{
	class SceneryObject
	{
	public:
		u32 mNameUID;
		u32 mFlags;
		u32 pad0;
		u32 pad1;
		Illusion::ModelHandle mModelHandles[2];
		char mName[64];
	};

	class SceneryInstance
	{
	public:
		u32 mNameUID;
		u16 mTintIndex;
		u16 mHierarchySkip;
		char mFlags;
		char mTransparencyState[3];
		qOffset64<SceneryObject*> mObject;
		u32 mPad[2];
		qMatrix44 mLocalWorld;
	};

	class SceneryTintEntry
	{
	public:
		qVector4 mTintColour;
		qVector4 mSITintColour;
	};
}
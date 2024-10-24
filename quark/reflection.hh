#pragma once

namespace UFG
{
	class ReflectionPlane
	{
	public:
		qVector3 mPosition;
		u32 mPad0;
		qVector3 mNormal;
		u32 mPad1;
	};

	class ReflectionVolume
	{
	public:
		qVector3 mPosMinWorld;
		qVector3 mPosMaxWorld;
		qVector3 mPosMinLocal;
		qVector3 mPosMaxLocal;
		qMatrix44 mWorldToLocal;
	};

	class Reflection
	{
	public:
		u32 mUID;
		u32 mFlags;
		u32 mSceneryGroupUID;
		ReflectionPlane mPlane;
		ReflectionVolume mVolume;
		qVector3 mLightDirectionOverride;
		qVector3 mLightColorOverride;
		qVector3 mAmbientColor;
		char mName[32];
	};
	SDK_ASSERT_SIZEOF(Reflection, 0xE0);
}
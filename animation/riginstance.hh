#pragma once

namespace UFG
{
	class RigInstance
	{
	public:
		qMatrix44 mTransform;
		qSymbol mInstanceName;
		u32 mRigGuid;
		qSafePointer<SimObject>* mSimObjectHolder;
		u32 mFlags;
		i8 mPad[12];
	};
}
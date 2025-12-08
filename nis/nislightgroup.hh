#pragma once

class NISLightGroup
{
public:
	UFG::qSafePointer<UFG::SimObject> mSimObject;
	bool mValid;
	UFG::qString mLightGroupName;
	UFG::qString mLightGroupFileName;
	UFG::StreamPriorityHandle* mLightRigHandle;
	UFG::RigHandle mRigResource;
};
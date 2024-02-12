#pragma once

namespace UFG
{
	class CRigHandle : public qResourceHandle
	{
	public:
		void* mLoadFunction;
		void* mUnloadFunction;
		void* mUserData;
		CSkeleton* mUFGSkeleton;
	};
}
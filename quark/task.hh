#pragma once

namespace UFG
{
	class qTaskFunctionDeclData;
	class qTaskGroup;

	class qTask : public qNode<qTask>, qNode<qTask, class TaskPlat>
	{
	public:
		union TaskSyncVar
		{
			struct _vars
			{
				u16 mState;
				u16 mNumDependents;
				u64 mDependents;
			} v;
			u64 i64;
		};

		TaskSyncVar mSyncVars;

		union
		{
			u32 mOffloadThread;
			qTaskGroup* mTaskGroup;
		};

		u32 mFlags;
		qTaskFunctionDeclData* mFunctionDeclData;
		void* mSPUElfAddress;
		void(__fastcall* mSPUFunction)(int, qMemoryStreamer*, void*, void*, void*, void*);
		void(__fastcall* mPPUFunction)(int, qMemoryStreamer*, void*, void*, void*, void*);
		void* mParam0;
		void* mParam1;
		void* mParam2;
		void* mParam3;
	};
	SDK_ASSERT_SIZEOF(qTask, 0x80);
}
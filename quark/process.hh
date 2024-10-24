#pragma once

namespace UFG
{
	//-------------------------------------------------------------------
	// Event
	//-------------------------------------------------------------------

	class qEvent
	{
	public:
		const char* mName;
		void* mHandlePlat;
		bool mAutoReset;
	};

	//-------------------------------------------------------------------
	// Mutex
	//-------------------------------------------------------------------

	class qMutex
	{
	public:
		u32 mMutexMemory[12];
	};

	class qMutexScopeLocker
	{
	public:
		qMutex* mMutex;
	};

	//-------------------------------------------------------------------
	// Thread
	//-------------------------------------------------------------------

	class qThread
	{
	public:
		const char* mName;
		void(*mThreadFunction)(void*);
		void* mThreadParam;
		int mStacksize;
		int mPriority;
		int mLogicalCoreID;
		void* mHandlePlat;
		u64 mHandlePlat64;
		u32 mThreadIDPlat;
	};
}
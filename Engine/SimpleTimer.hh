#pragma once

namespace UFG
{
	class SimpleTimer
	{
	public:
		uint64_t mTimestamp;
		float mElapsedTime;
		bool mIsStarted;

		SimpleTimer()
		{
			this->mTimestamp = 0;
			this->mElapsedTime = 0;
			this->mIsStarted = false;
		}

		UFG_INLINE void Start()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x510510))(this);
		}

		UFG_INLINE void Stop()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x510550))(this);
		}

		UFG_INLINE void Resume()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x50F650))(this);
		}

		UFG_INLINE void SetElapsedTime(float p_ElapsedTime)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x50FC30))(this, p_ElapsedTime);
		}

		UFG_INLINE float GetElapsedTime()
		{
			return reinterpret_cast<float(__fastcall*)(void*)>(UFG_RVA(0x4E1310))(this);
		}
	};
	UFG_ASSERT_CLASS(SimpleTimer, 0x10);
}
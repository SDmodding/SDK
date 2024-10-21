#pragma once

namespace UFG
{
	class SimpleTimer
	{
	public:
		u64 mTimestamp;
		f32 mElapsedTime;
		bool mIsStarted;

		/* Functions */

		void Start() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x510510))(this); }
		void Stop() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x510550))(this); }
		void Resume() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x50F650))(this); }
		f32 GetElapsedSeconds() { return reinterpret_cast<f32(SDK_CALL*)(void*)>(SDK_RVA(0x4E1310))(this); }
		void SetElapsedTime(f32 elapsedTime) { reinterpret_cast<void(SDK_CALL*)(void*, f32)>(SDK_RVA(0x50FC30))(this, elapsedTime); }
	};
}
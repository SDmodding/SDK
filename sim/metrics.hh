#pragma once

namespace UFG
{
	class Metrics : public qNode<Metrics>
	{
	public:
		unsigned __int64 mSimTimeMSec;
		qTicks mSimTimeTicks;
		long double mSimTime;
		f32 mSimTime_Temp;
		f32 mSimTimeDelta;
		f32 mSimTimeUnscaledDelta;
		u32 mSimFrameCount;
		f32 mSimTimeScaleInGame;
		bool mSimPausedInGame;
		f32 mSimTimeScaleDebug;
		bool mSimPausedDebug;
		f32 mSimTimeDeltaMax;
		f32 mSimTimeDeltaLocked;
		f32 mSimTimeDeltaStep;
		f32 mSimTimeScaleSlow;
		f32 mSimTimeScaleTurbo;
		f32 mSimTimeScaleMax;

		/* Static Functions */

		SDK_SINLINE Metrics* GetInstance() { return reinterpret_cast<Metrics*>(SDK_RVA(0x203C920)); }
		SDK_SINLINE void UpdateAll(u32 realTimeMSecTicks, f32 deltaTime, bool frameRendered, bool nisPlaying) {
			reinterpret_cast<void(SDK_CALL*)(u32, f32, bool, bool)>(SDK_RVA(0x1919C0))(realTimeMSecTicks, deltaTime, frameRendered, nisPlaying);
		}
		SDK_SINLINE void UpdateAllCommon(u64 realTimeElapsedUnclamped, u32 realTimeDeltaUnclamped, bool frameRendered, bool nisPlaying) {
			reinterpret_cast<void(SDK_CALL*)(u64, u32, bool, bool)>(SDK_RVA(0x191AA0))(realTimeElapsedUnclamped, realTimeDeltaUnclamped, frameRendered, nisPlaying);
		}

		/* Functions */

		bool IsTimeScaled() { return reinterpret_cast<bool(SDK_CALL*)(void*)>(SDK_RVA(0x190CB0))(this); }
		void Update() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x191830))(this); }
	};
	SDK_ASSERT_SIZEOF(Metrics, 0x60);
}
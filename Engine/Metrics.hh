#pragma once

namespace UFG
{
	class Metrics
	{
	public:
		qNode<Metrics> mNode;
		uint64_t mSimTimeMSec;
		uint32_t mSimTimeTicks;
		long double mSimTime;
		float mSimTimeFloat;
		float mSimTimeDelta;
		float mSimTimeUnscaledDelta;
		uint32_t mSimFrameCount;
		float mSimTimeScaleInGame;
		bool mSimPausedInGame;
		float mSimTimeScaleDebug;
		bool mSimPausedDebug;
		float mSimTimeDeltaMax;
		float mSimTimeDeltaLocked;
		float mSimTimeDeltaStep;
		float mSimTimeScaleSlow;
		float mSimTimeScaleTurbo;
		float mSimTimeScaleMax;

		UFG_STATIC_INLINE Metrics* Instance()
		{
			return reinterpret_cast<Metrics*>(UFG_RVA(0x203C920));
		}
	};
	typedef Metrics CMetrics;
}
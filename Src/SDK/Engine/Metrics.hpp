#pragma once

namespace UFG
{
	class CMetrics
	{
	public:
		UFG_PAD(0x10);

		unsigned __int64 mSimTimeMSec;
		unsigned int mSimTimeTicks;
		long double mSimTime;
		float mSimTimeFloat;
		float mSimTimeDelta;
		float mSimTimeUnscaledDelta;
		unsigned int mSimFrameCount;
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
	};

	CMetrics* Metrics = reinterpret_cast<CMetrics*>(UFG_RVA(0x203C920));
}
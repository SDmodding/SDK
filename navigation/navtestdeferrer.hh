#pragma once

namespace UFG
{
	class TestDeferrer
	{
	public:
		qVector3 mLastPosition;
		f32 mTimeSinceLastCheck;
		f32 mDistanceTolerance;
		f32 mTimeTolerance;
		bool mResult;

		/* Functions */

		bool IsStale(const qVector3& currPosition) { return SDK_CALL_FUNC(bool, 0x265400, void*, const qVector3&)(this, currPosition); }
	};
}
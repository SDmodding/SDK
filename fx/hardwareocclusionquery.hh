#pragma once

namespace FX
{
	class HardwareOcclusionQuery
	{
	public:
		u32 mQueryID;
		u32 mUnculledQueryID;
		Illusion::Target* mTarget;
		f32 mVisibility;
	};
}
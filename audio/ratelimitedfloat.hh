#pragma once

namespace UFG
{
	class RateLimitedFloatSharedRate
	{
	public:
		f32 m_currentValue;
		f32 m_targetValue;
	};

	class RateLimitedFloatNoMinMax
	{
	public:
		float m_currentValue;
		float m_targetValue;
		float m_riseRate;
		float m_fallRate;
	};

	class RateLimitedFloat : public RateLimitedFloatNoMinMax
	{
	public:
		float m_max;
		float m_min;
	};
}
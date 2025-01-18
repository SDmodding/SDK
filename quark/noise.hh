#pragma once

namespace UFG
{
	template <typename T, typename U = T>
	class qNoise
	{
	public:
		T tDecay;
		T tRangeMin;
		T tRangeMax;
		T tAmplitude;
		U tFrequency;
		U tOffset;
		int nOctaves;
		bool bCircular;
	};
}
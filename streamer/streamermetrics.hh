#pragma once

namespace UFG
{
	class StreamerMetrics
	{
	public:
		enum DATA_TYPE
		{
			DATA_UNKNOWN,
			DATA_TEXTURE,
			DATA_MODEL,
			DATA_MATERIALS,
			DATA_BUFFERS,
			DATA_LIGHTS,
			DATA_IMPOSTERS,
			DATA_RIGS,
			DATA_PHYSICS,
			DATA_PARKOUR,
			DATA_SCENERY,
			DATA_AI,
			DATA_ANIMATION,
			DATA_GAMEPLAY,
			DATA_CORNER_COVER,
			DATA_SIDEWALK,
			DATA_ROADNETWORK,
			DATA_TYPE_COUNT
		};

		struct UsageByType
		{
			u32 mSizeBytes[DATA_TYPE_COUNT];
		};
	};
}
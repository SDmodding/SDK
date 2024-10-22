#pragma once

namespace UFG
{
	class StreamPriorityHandle
	{
	public:
		DataStreamer::Handle mHandle;
		qSharedString mFilename;
		int mMemorySize;
		u32 mPriority;
	};

	class StreamPrioritySystem
	{
	public:
		enum DATA_TYPE : s32
		{
			DATA_UNKNOWN,
			DATA_GLOBAL_LOC,
			DATA_ZONE_LOC,
			DATA_SECTION_LOD,
			DATA_SECTION_STD,
			DATA_GAMEPLAY_GLOBAL,
			DATA_GAMEPLAY_CELL,
			DATA_WORLD_INIT,
			DATA_UI,
			DATA_LOCALIZATION,
			DATA_ROADNETWORK,
			DATA_ANIMATION,
			DATA_TRUECROWD_RESOURCE,
			DATA_TRUECROWD_TEXTURE_RESOURCE,
			DATA_GAME_GLOBAL_TEXTURES,
			DATA_CLOUDS,
			DATA_SCRIPT,
			DATA_TERRAIN,
			DATA_PARTSDB_RESOURCE,
			DATA_PARTSDB_TEXTURE_RESOURCE,
			DATA_TURF,
			DATA_TYPE_COUNT
		};

		const u32 mStreamPoolIndex;
		DATA_TYPE mStreamerDataType;
		const u32 mStreamerFlags;
		const int mStreamPoolSize;
		const int mMaxHandleCount;
		u32 mMinPriorityLevel;
		u32 mHighPriorityLevel;
		qFixedAllocator mHandleAllocator;
		qArray<StreamPriorityHandle*> mDesired;
		qArray<StreamPriorityHandle*> mQueuedRelease;
	};
	SDK_ASSERT_SIZEOF(StreamPrioritySystem, 0x70);
}
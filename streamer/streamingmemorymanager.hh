#pragma once

namespace UFG
{
	class StreamingMemory
	{
	public:
		enum DATA_TYPE
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

		struct DataTypeDef
		{
			int mStreamPoolIndex;
			int mVRAMDefIndex;
		};

		struct InitParams
		{
			u32 locationMemoryPoolSize;
			u32 globalLocationOverrideSize;
			u32 locationMiscOverrideMemoryPoolSize;
			u32 animationMemoryPoolSize;
			u32 cloudsTexturePoolSize;
			u32 uiMemoryPoolSize;
			u32 localizationMemoryPoolSize;
			u32 globalGameplayPoolSize;
			u32 cellGameplayPoolSize;
			u32 scriptPoolSize;
			u32 uiVRamPoolSize;
			u32 terrainElementCount;
			u32 terrainElementSize;
			u32 terrainVRAMElementSize;
			u32 streamedMemoryPoolSize;
			u32 streamedTextureHeaderPoolSize;
			u32 streamedTexturePoolSize;
			u32 turfMemoryPoolSize;
			u32 turfTexturePoolSize;
			u32 stdSectionElementSize;
			u32 stdSectionVRAMElementSize;
			u32 lodcSectionElementSize;
			u32 lodcSectionVRAMElementSize;
			u32 zoneElementSize;
			u32 zoneVRAMElementSize;
			u32 globalVRAMElementSize;
		};

		struct MainRAMDef
		{
			u32 mBlockSize;
		};

		struct MemoryAllocation : qNodeRB<MemoryAllocation>
		{
			qString mFilePath;
			u32 mSize;
		};

		struct MemoryTracker
		{
			qString mName;
			qTreeRB<MemoryAllocation> mAllocations;
			u32 mAllocationSize;
		};

		struct VRAMDef
		{
			qVRAMemoryPool* mVRAMPool;
			u32 mBlockSize;
		};
	};
}
#pragma once

namespace UFG
{
	struct UITiledMapInteriorData_t
	{
		unsigned int InteriorId;
		UITiledMapWorldGeo_t WorldGeo;
		const char* TexturePrefix;
		unsigned int ElevationLevelCount;
		float ElevationLevel[3];
		float ZoomLevel;
	};

	class CUIMapInteriorManager
	{
	public:
		bool mActive;
		bool mChanged;
		eInteriors mActiveInterior;
		uint32_t mElevationLevel;
		uint32_t mNumInteriors;
		UITiledMapInteriorData_t mData[25];
		qString mTextureName;
		qString mTexturePack;
		bool mTextureLoaded;
		UITiledMapWorldGeo_t OldMapGeo;
	};
}
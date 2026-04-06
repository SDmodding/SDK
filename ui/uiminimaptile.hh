#pragma once

namespace UFG
{
	class UIMinimapTile : public qResourceData
	{
	public:
		f32 mOrigin_x;
		f32 mOrigin_y;
		bool mDrawTile;
		Illusion::TextureHandle mMapTileHandle;
	};
	SDK_ASSERT_SIZEOF(UIMinimapTile, 0x88);
}
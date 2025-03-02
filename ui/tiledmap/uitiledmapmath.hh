#pragma once

namespace UFG
{
	class UITiledMapMath;
	class ScreenPoint2f;
	class WorldPoint2f;

	class UIPoint2f
	{
	public:
		f32 x;
		f32 y;
	};

	class MinimapPoint2f : public UIPoint2f
	{
	public:
		MinimapPoint2f(const WorldPoint2f& point) { SDK_CALL_FUNC(void, 0xBB6E0, void*, const WorldPoint2f&)(this, point); }
	};

	class MinimapTilePoint2f : public UIPoint2f
	{
	public:
		MinimapTilePoint2f(const MinimapPoint2f& point, const UITiledMapMath& geo) { SDK_CALL_FUNC(void, 0xBB770, void*, const MinimapPoint2f&, const UITiledMapMath&)(this, point, geo); }
		MinimapTilePoint2f(const ScreenPoint2f& point, const UITiledMapMath& geo) { SDK_CALL_FUNC(void, 0xBB7B0, void*, const ScreenPoint2f&, const UITiledMapMath&)(this, point, geo); }
	};

	class WideMinimapPoint2f : public UIPoint2f
	{
	public:
	};

	class ScreenPoint2f : public UIPoint2f
	{
	public:
		ScreenPoint2f(const WorldPoint2f& point, const UITiledMapMath& geo) { SDK_CALL_FUNC(void, 0xBB880, void*, const WorldPoint2f&, const UITiledMapMath&)(this, point, geo); }

		/* Functions */

		void InitFromIconPos(const MinimapTilePoint2f& iconPos, const UITiledMapMath& geo) {
			SDK_CALL_FUNC(void, 0xC59D0, void*, const MinimapTilePoint2f&, const UITiledMapMath&)(this, iconPos, geo);
		}

		void InitFromMapPos(const MinimapTilePoint2f& mapPos, const UITiledMapMath& geo) {
			SDK_CALL_FUNC(void, 0xC5A90, void*, const MinimapTilePoint2f&, const UITiledMapMath&)(this, mapPos, geo);
		}
	};

	class WorldPoint2f : public UIPoint2f
	{
	public:
		WorldPoint2f(const qVector3& point) { SDK_CALL_FUNC(void, 0xBD360, void*, const qVector3&)(this, point); }
		WorldPoint2f(const ScreenPoint2f& point, const UITiledMapMath& geo) { SDK_CALL_FUNC(void, 0xBD2D0, void*, const ScreenPoint2f&, const UITiledMapMath&)(this, point, geo); }
	};

	class UITiledMapMath
	{
	public:
		ScreenPoint2f screenPosition;
		WorldPoint2f centerPosition;
		f32 rot;
		f32 playerRot;
		f32 scale;
		bool useWideTiles;
		bool useTiledMap;
		f32 CircleMaskX;
		f32 CircleMaskY;
		f32 MaskRadius;
		int m_rowOffset;
		int m_colOffset;
		bool IsWorldMap;

		/* Functions */

		f32 GetAdjustedScale() { return SDK_CALL_FUNC(f32, 0xC0B70, void*)(this); }
	};
}
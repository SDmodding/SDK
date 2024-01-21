#pragma once

namespace UFG
{
	class CUITiledMapMath
	{
	public:
		ScreenPoint2f screenPosition;
		WorldPoint2f centerPosition;
		float rot;
		float playerRot;
		float scale;
		bool useWideTiles;
		bool useTiledMap;
		float CircleMaskX;
		float CircleMaskY;
		float MaskRadius;
		int m_rowOffset;
		int m_colOffset;
		bool IsWorldMap;

		UFG_INLINE float GetAdjustedScale()
		{
			float m_Scale = *reinterpret_cast<float*>(UFG_RVA(0x2173F10)) + scale;
			if (useWideTiles) {
				m_Scale += 0.5f;
			}

			return m_Scale;
		}

		UFG_INLINE void MinimapTilePointOffset(MinimapTilePoint2f* p_MinimapTilePoint, MinimapPoint2f* p_MinimapPoint)
		{
			p_MinimapTilePoint->x = p_MinimapPoint->x - static_cast<float>(m_colOffset);
			p_MinimapTilePoint->y = p_MinimapPoint->y - static_cast<float>(m_rowOffset);
		}

		UFG_INLINE void MinimapTilePoint(MinimapTilePoint2f* p_MinimapTilePoint, ScreenPoint2f* p_ScreenPoint)
		{
			reinterpret_cast<void(__fastcall*)(MinimapTilePoint2f*, ScreenPoint2f*, void*)>(UFG_RVA(0xBB7B0))(p_MinimapTilePoint, p_ScreenPoint, this);
		}

		UFG_INLINE void ScreenPoint(ScreenPoint2f* p_ScreenPoint, WorldPoint2f* p_WorldPoint)
		{
			reinterpret_cast<void(__fastcall*)(ScreenPoint2f*, WorldPoint2f*, void*)>(UFG_RVA(0xBB880))(p_ScreenPoint, p_WorldPoint, this);
		}
		
		UFG_INLINE void WorldPoint(WorldPoint2f* p_WorldPoint, ScreenPoint2f* p_ScreenPoint)
		{
			reinterpret_cast<void(__fastcall*)(WorldPoint2f*, ScreenPoint2f*, void*)>(UFG_RVA(0xBD2D0))(p_WorldPoint, p_ScreenPoint, this);
		}

		UFG_INLINE void InitFromMinimapTilePos(ScreenPoint2f* p_ScreenPoint, MinimapTilePoint2f* p_MinimapTilePoint)
		{
			reinterpret_cast<void(__fastcall*)(ScreenPoint2f*, MinimapTilePoint2f*, void*)>(UFG_RVA(0xC59D0))(p_ScreenPoint, p_MinimapTilePoint, this);
		}

		UFG_INLINE void InitFromWorldPos(ScreenPoint2f* p_ScreenPoint, WorldPoint2f* p_WorldPoint)
		{
			reinterpret_cast<void(__fastcall*)(ScreenPoint2f*, WorldPoint2f*, void*)>(UFG_RVA(0xC59D0))(p_ScreenPoint, p_WorldPoint, this);
		}
	};
}
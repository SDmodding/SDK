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
	};
}
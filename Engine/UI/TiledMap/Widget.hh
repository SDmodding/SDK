#pragma once

namespace UFG
{
	class CUITiledMapWidget
	{
	public:
		CUITiledMapMath m_mapGeo;
		bool mIsWorldMap;
		bool mVisible;
		CUITiledMapMath m_prevGeo;
		CUITiledMapMath m_mapIconGeo;
		CUITiledMapZoomCalc ZoomCalc;
		bool forceUpdate;
		float mAlpha;
		qArray<CUIRenderQuad> PolyListNativeClipped;
		qArray<CUIRenderQuad> PolyListNativeDoubleClipped;
		qArray<CUIRenderQuad> PolyListNativeNotClipped;
		qMatrix44 mViewportScaleMatrix;
		float mViewportScale;
		float mViewportScaleH;
		float mViewportScaleV;

		UFG_INLINE void AdjustClipRect(ClipRect* p_ClipRect)
		{
			float m_Scale	= m_mapGeo.GetAdjustedScale() * ZoomCalc.mScale;
			float m_OffsetX	= m_mapGeo.centerPosition.x * m_Scale;
			float m_OffsetY = m_mapGeo.centerPosition.y * m_Scale;

			p_ClipRect->x0 -= m_OffsetX;
			p_ClipRect->x1 -= m_OffsetX;
			p_ClipRect->y0 += m_OffsetY;
			p_ClipRect->y1 += m_OffsetY;
		}
	};
}
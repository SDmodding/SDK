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
	};
}
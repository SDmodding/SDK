#pragma once

namespace UFG
{
	class UITiledMapWidget
	{
	public:
		UITiledMapMath m_mapGeo;
		bool mIsWorldMap;
		bool mVisible;
		UITiledMapMath m_prevGeo;
		UITiledMapMath m_mapIconGeo;
		UITiledMapZoomCalc ZoomCalc;
		bool forceUpdate;
		f32 mAlpha;
		qArray<UIRenderQuad> PolyListNativeClipped;
		qArray<UIRenderQuad> PolyListNativeDoubleClipped;
		qArray<UIRenderQuad> PolyListNativeNotClipped;
		qMatrix44 mViewportScaleMatrix;
		f32 mViewportScale;
		f32 mViewportScaleH;
		f32 mViewportScaleV;

		/* Static Functions */

		void SetGPSLineColor(const qColour& color) { SDK_CALL_FUNC(void, 0xCA800, const qColour&)(color); }

		/* Functions */

		void DrawClipRects(Render::View* view, const qColour& Color, u32 AlphaStateUID, u32 RasterStateUID, qMatrix44* TransformMatrix) {
			SDK_CALL_FUNC(void, 0xBF7E0, void*, Render::View*, const qColour&, u32, u32, qMatrix44*)(this, view, Color, AlphaStateUID, RasterStateUID, TransformMatrix);
		}

		void Flash_GetWidgetScreenPosition(UIScreen* screen) { SDK_CALL_FUNC(void, 0xC0820, void*, UIScreen*)(this, screen); }
		f32 GetZoom() { return SDK_CALL_FUNC(f32, 0xC4B10, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(UITiledMapWidget, 0x170);
}
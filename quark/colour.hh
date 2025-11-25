#pragma once

namespace UFG
{
	class qColour
	{
	public:
		f32 r, g, b, a;

		SDK_INLINE qColour() : r(0.f), g(0.f), b(0.f), a(0.f) {}
		SDK_INLINE qColour(f32 fR, f32 fG, f32 fB, f32 fA = 1.f) : r(fR), g(fG), b(fB), a(fA) {}
		SDK_INLINE qColour(int r, int g, int b, int a = 255) : qColour(static_cast<f32>(r) * (1.f / 255.f), static_cast<f32>(g) * (1.f / 255.f), static_cast<f32>(b) * (1.f / 255.f), static_cast<f32>(a) * (1.f / 255.f)) {}
	
		SDK_INLINE bool operator==(const qColour& col) const { return (r == col.r && g == col.g && b == col.b && a == col.a); }
		SDK_INLINE bool operator!=(const qColour& col) const { return (r != col.r || g != col.g || b != col.b || a != col.a); }
	};

	/* Static Functions */

	SDK_SINLINE void qColourRGBToHSV(qColour& hsv, const qColour& rgb) { SDK_CALL_FUNC(void, 0x182630, qColour&, const qColour&)(hsv, rgb); }
	SDK_SINLINE void qColourHSVToRGB(qColour& rgb, const qColour& hsv) { SDK_CALL_FUNC(void, 0x1824E0, qColour&, const qColour&)(rgb, hsv); }
}
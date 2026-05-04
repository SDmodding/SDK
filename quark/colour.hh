#pragma once

namespace UFG
{
	class qColour
	{
	public:
		f32 r, g, b, a;

		SDK_INLINE qColour() : r(0.f), g(0.f), b(0.f), a(0.f) {}
		SDK_INLINE qColour(f32 red, f32 green, f32 blue, f32 alpha = 1.f) : r(red), g(green), b(blue), a(alpha) {}
		SDK_CONSTEVAL qColour(int red, int green, int blue, int alpha = 255) : 
			r(static_cast<f32>(red) / 255.f), 
			g(static_cast<f32>(green) / 255.f), 
			b(static_cast<f32>(blue) / 255.f), 
			a(static_cast<f32>(alpha) / 255.f) {}
	
		SDK_INLINE bool operator==(const qColour& col) const { return (r == col.r && g == col.g && b == col.b && a == col.a); }
		SDK_INLINE bool operator!=(const qColour& col) const { return (r != col.r || g != col.g || b != col.b || a != col.a); }
	};

	/* Static Functions */

	SDK_SINLINE void qColourRGBToHSV(qColour& hsv, const qColour& rgb) { SDK_CALL_FUNC(void, 0x182630, qColour&, const qColour&)(hsv, rgb); }
	SDK_SINLINE void qColourHSVToRGB(qColour& rgb, const qColour& hsv) { SDK_CALL_FUNC(void, 0x1824E0, qColour&, const qColour&)(rgb, hsv); }
}
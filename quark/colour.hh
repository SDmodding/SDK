#pragma once

namespace UFG
{
	class qColour
	{
	public:
		f32 r, g, b, a;

		qColour() : r(0.f), g(0.f), b(0.f), a(0.f) {}
		qColour(f32 fR, f32 fG, f32 fB, f32 fA = 1.f) : r(fR), g(fG), b(fB), a(fA) {}
	};
}
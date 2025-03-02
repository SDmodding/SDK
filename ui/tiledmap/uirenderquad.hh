#pragma once

namespace UFG
{
	class UIRenderQuad
	{
	public:
		u32 TextureID;
		qMatrix44* Matrix;
		f32 UVs[4];
		f32 Scale;
		f32 X;
		f32 Y;
		f32 OffsetX;
		f32 OffsetY;
		f32 Size;
		qColour Color;
		bool Visible;
	};
}
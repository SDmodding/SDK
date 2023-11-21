#pragma once

namespace UFG
{
	class CUIRenderQuad
	{
	public:
		uint32_t TextureID;

		UFG_PAD_ALIGN(0x4);

		qMatrix44* Matrix;
		float UVs[4];
		float Scale;
		float X;
		float Y;
		float OffsetX;
		float OffsetY;
		float Size;
		qColour Color;
		bool Visible;
	};
}
#pragma once

namespace Scaleform::Render
{
	class GlyphCache; // TODO: Implement this

	class GlyphCacheParams
	{
	public:
		u32 TextureWidth;
		u32 TextureHeight;
		u32 NumTextures;
		u32 MaxSlotHeight;
		u32 SlotPadding;
		u32 TexUpdWidth;
		u32 TexUpdHeight;
		f32 MaxRasterScale;
		u32 MaxVectorCacheSize;
		f32 FauxItalicAngle;
		f32 FauxBoldRatio;
		f32 OutlineRatio;
		f32 ShadowQuality;
		bool UseAutoFit;
		bool UseVectorOnFullCache;
		bool FenceWaitOnFullCache;
	};
}
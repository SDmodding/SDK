#pragma once

namespace Render
{
	class Font : public UFG::qResourceData
	{
	public:
		struct Glyph
		{
			f32 mUV[4];
			u16 mUV16[4];
			f32 mXOffset;
			f32 mYOffset;
			f32 mWidth;
			f32 mHeight;
			u16 mAscii;
			u16 mXAdvance;
			u16 mPage;
			s16 mKerningIndex;
		};

		struct Kerning
		{
			u16 mFirst;
			u16 mSecond;
			s16 mAmount;
		};

		u32 mNumGlyphs;
		u32 mNumKernings;
		UFG::qOffset64<Glyph*> mGlyphTable;
		UFG::qOffset64<Kerning*> mKerningTable;
		s8 mTextureName[32];
		u16 mAsciiToGlyph[511];
		u16 mLineHeight;
		u16 mBase;
		u16 mWidth;
		u16 mHeight;
		u16 mPages;
		Illusion::Material* mMaterial;
	};

	class FontHandle : public UFG::qTypedResourceHandle<RTypeUID_Font, Font> {};
}
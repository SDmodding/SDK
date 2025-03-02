#pragma once

namespace Scaleform::GFx
{
	class FontMapImpl;

	class FontMap : public State
	{
	public:
		struct MapEntry
		{
			enum MapFontFlags
			{
				MFF_Original = 0x0010,
				MFF_NoAutoFit = 0x0020,
				MFF_Normal = 0x0000,
				MFF_Italic = 0x0001,
				MFF_Bold = 0x0002,
				MFF_BoldItalic = MFF_Italic | MFF_Bold,
				MFF_FauxItalic = 0x0004,
				MFF_FauxBold = 0x0008,
				MFF_FauxBoldItalic = MFF_FauxItalic | MFF_FauxBold
			};

			String Name;
			float ScaleFactor;
			MapFontFlags Flags;
		};

		FontMapImpl* pImpl;

		/* Functions */

		bool GetFontMapping(MapEntry* pentry, const char* pfontName) { return SDK_CALL_FUNC(bool, 0x8D84E0, void*, MapEntry*, const char*)(this, pentry, pfontName); }
	};

	class FontMapImpl
	{
	public:
		StringHashLH<FontMap::MapEntry> FontMapValue;
	};
}
#pragma once

namespace UFG
{
	class UILanguages
	{
	public:
		enum eLanguage : i32
		{
			eLang_Invalid = -1,
			eLang_DebugBlank,
			eLang_DebugLabel,
			eLang_DebugMaxString,
			eLang_DebugNumericID,
			eLang_Cantonese,
			eLang_Danish,
			eLang_Dutch,
			eLang_English,
			eLang_English_UK,
			eLang_Finnish,
			eLang_French,
			eLang_French_CA,
			eLang_German,
			eLang_Italian,
			eLang_Japanese,
			eLang_Korean,
			eLang_Norwegian,
			eLang_Polish,
			eLang_Portuguese,
			eLang_Portuguese_BR,
			eLang_Russian,
			eLang_Spanish,
			eLang_Spanish_US,
			eLang_Swedish,
			eLang_NumLanguages
		};

		/* Static Functions */

		SDK_SINLINE eLanguage getLanguage(const char* language) { return SDK_CALL_FUNC(eLanguage, 0xA2AE40, const char*)(language); }
		SDK_SINLINE const char* getLanguageString(eLanguage language) { return SDK_CALL_FUNC(const char*, 0xA2B200, eLanguage)(language); }
		SDK_SINLINE const char* getLanguageStringShort(eLanguage language) { return SDK_CALL_FUNC(const char*, 0xA2B370, eLanguage)(language); }
	};
}
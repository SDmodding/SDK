#pragma once

namespace UFG
{
	class UIDictionary : public qNode<UIDictionary>
	{
	public:
		struct UIDictionaryEntry : qNodeRB<UIDictionaryEntry>
		{
			char* mString;
		};

		u32 mUID;
		char mSectionName[128];
		char mFilename[256];
		char mPendingFilename[256];
		char* mStringData;
		bool mIsLoaded;
		bool mMarkedForDeleteOnLoad;
		qTreeRB<UIDictionaryEntry> mStringMap;
		bool mIsLoadedFromMemory;
		DataStreamer::Handle mhLocalizationData;
		UILocalizationChunkHandle mDatabaseHandle;

		/* Functions */

		void LoadDictionary(char* filename) { SDK_CALL_FUNC(void, 0xA276F0, void*, char*)(this, filename); }
		void PrintDictionary() { SDK_CALL_FUNC(void, 0xA27FC0, void*)(this); }
		void UnloadDictionary() { SDK_CALL_FUNC(void, 0xA28670, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(UIDictionary, 0x348);

	class UIGfxTranslator : public Scaleform::GFx::Translator
	{
	public:
		UILanguages::eLanguage mLanguage;
		f32 mFontScale;
		int mTimeFormat;
		int mDateFormat;
		char mCurrencySymbol[16];
		int mDecimals;
		bool mSymbolPrefixNumber;
		bool mSymbolWithSpace;
		char mThousandsSeparator[16];
		char mDecimalSymbol[16];
		Scaleform::GFx::Loader* mGfxLoader;
		UIScreenFactory* mScreenFactory;
		bool mIsAcceptButtonSwapped;
		qList<UIDictionary> mDictionaries;

		/* Virtual Functions */

		virtual const char* Translate(u32 hash) = 0;

		/* Functions */

		void loadDictionary(const char* sectionName) { SDK_CALL_FUNC(void, 0xA30570, void*, const char*)(this, sectionName); }
		void reloadDictionary(const char* sectionName) { SDK_CALL_FUNC(void, 0xA31900, void*, const char*)(this, sectionName); }
		void unloadDictionary(const char* sectionName) { SDK_CALL_FUNC(void, 0xA324B0, void*, const char*)(this, sectionName); }
		void setLanguage(UILanguages::eLanguage language, bool load_fonts) { SDK_CALL_FUNC(void, 0xA31F40, void*, UILanguages::eLanguage, bool)(this, language, load_fonts); }
	};
	SDK_ASSERT_SIZEOF(UIGfxTranslator, 0x90);
}
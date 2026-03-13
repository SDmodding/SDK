#pragma once

namespace UFG
{
	class qString : public qNode<qString>
	{
	public:
		u32 mMagic;
		int mLength;
		char* mData;
		u32 mStringHash32;
		u32 mStringHashUpper32;

		qString() { SDK_CALL_FUNC(void, 0x1620A0, void*)(this); }

		template <typename... Args>
		qString(const char* format, Args... args) { SDK_CALL_FUNC(void, 0x161FC0, void*, const char*, Args...)(this, format, args...); }

		~qString() { SDK_CALL_FUNC(void, 0x1643D0, void*)(this); }

		/* Impl Functions */

		SDK_INLINE bool IsEmpty() const { return mLength == 0; }

		/* Static Functions */

		template <typename... Args>
		SDK_SINLINE qString FormatEx(const char* format, Args... args) 
		{ 
			qProxy<qString> res;
			return *SDK_CALL_FUNC(qString*, 0x16E480, qString*, const char*, Args...)(&res, format, args...);
		}

		/* Functions */

		template <typename... Args>
		void Format(const char* format, Args... args) { SDK_CALL_FUNC(void, 0x16E350, void*, const char*, Args...)(this, format, args...); }

		qString GetFilePath() const
		{
			qProxy<qString> res;
			return *SDK_CALL_FUNC(qString*, 0x170750, const void*, qString*)(this, &res);
		}

		qString GetFilePathWithoutExtension() const
		{
			qProxy<qString> res;
			return *SDK_CALL_FUNC(qString*, 0x170810, const void*, qString*)(this, &res);
		}

		qString GetFilename() const
		{
			qProxy<qString> res;
			return *SDK_CALL_FUNC(qString*, 0x1708F0, const void*, qString*)(this, &res);
		}

		qString GetFilenameWithoutExtension() const
		{
			qProxy<qString> res;
			return *SDK_CALL_FUNC(qString*, 0x1709A0, const void*, qString*)(this, &res);
		}

		void MakeLower() { SDK_CALL_FUNC(void, 0x177530, void*)(this); }
		void MakeUpper() { SDK_CALL_FUNC(void, 0x177580, void*)(this); }
		int ReplaceCharInPlace(char search_char, char replace_char) { return SDK_CALL_FUNC(int, 0x17A920, void*, char, char)(this, search_char, replace_char); }

		qString ReplaceExtension(const char* ext) const
		{
			qProxy<qString> res;
			return *SDK_CALL_FUNC(qString*, 0x17A950, const void*, qString*, const char*)(this, &res, ext);
		}

		bool ReplaceString(const char* find_text, const char* replace_text, bool ignore_case = false) {
			return SDK_CALL_FUNC(bool, 0x17AAC0, void*, const char*, const char*, bool)(this, find_text, replace_text, ignore_case);
		}

		void Set(const char* text) { SDK_CALL_FUNC(void, 0x17C9B0, void*, const char*)(this, text); }

		void Set(const char* text, int length, const char* textb, int lengthb) {
			SDK_CALL_FUNC(void, 0x17CA00, void*, const char*, int, const char*, int)(this, text, length, textb, lengthb);
		}

		bool StartsWith(const char* text, int length = -1) const { return SDK_CALL_FUNC(bool, 0x17DF20, const void*, const char*, int)(this, text, length); }
		bool EndsWith(const char* text, int length = -1) const { return SDK_CALL_FUNC(bool, 0x16D410, const void*, const char*, int)(this, text, length); }

		qString Substring(int start, int length) const
		{
			qProxy<qString> res;
			return *SDK_CALL_FUNC(qString*, 0x17E180, const void*, qString*, int, int)(this, &res, start, length);
		}

		qString ToLower() const
		{
			qProxy<qString> res;
			return *SDK_CALL_FUNC(qString*, 0x17E5E0, const void*, qString*)(this, &res);
		}

		qString ToUpper() const
		{
			qProxy<qString> res;
			return *SDK_CALL_FUNC(qString*, 0x17E6B0, const void*, qString*)(this, &res);
		}

		qString Trim() const
		{
			qProxy<qString> res;
			return *SDK_CALL_FUNC(qString*, 0x17EBE0, const void*, qString*)(this, &res);
		}

		int find(const char* str) const { return SDK_CALL_FUNC(int, 0x180FF0, const void*, const char*)(this, str); }

		/* Operators */

		SDK_INLINE char operator[](int pos) const { return mData[pos]; }
		SDK_INLINE operator const char*() const { return mData; }

		bool operator==(const qString& text) const { return SDK_CALL_FUNC(bool, 0x1649D0, const void*, const qString&)(this, text); }
		bool operator==(const char* text) const { return SDK_CALL_FUNC(bool, 0x164A40, const void*, const char*)(this, text); }
		bool operator!=(const qString& text) const { return SDK_CALL_FUNC(bool, 0x164AA0, const void*, const qString&)(this, text); }
		bool operator!=(const char* text) const { return SDK_CALL_FUNC(bool, 0x164B30, const void*, const char*)(this, text); }

		qString& operator+=(const qString& text) { return SDK_CALL_FUNC(qString&, 0x164CB0, void*, const qString&)(this, text); }
		qString& operator+=(const char* text) { return SDK_CALL_FUNC(qString&, 0x164CE0, void*, const char*)(this, text); }
		qString& operator=(const qString& text) { return SDK_CALL_FUNC(qString&, 0x49230, void*, const qString&)(this, text); }
		qString& operator=(const char* text) { return SDK_CALL_FUNC(qString&, 0x69DE0, void*, const char*)(this, text); }
	};

	class qStringBuilder
	{
	public:
		char* mBuffer;
		int mBufferSize;
		int mStringLength;

		qStringBuilder() { SDK_CALL_FUNC(void, 0x1620F0, void*)(this); }
		~qStringBuilder() { SDK_CALL_FUNC(void, 0x164430, void*)(this); }
	};

	/* Functions */

	SDK_SINLINE char* qStringFind(const char* text, const char* find) { return reinterpret_cast<char*(SDK_CALL*)(const char*, const char*)>(SDK_RVA(0x18B200))(text, find); }

	SDK_SINLINE char* qStringFindInsensitive(const char* text, const char* find) { return reinterpret_cast<char*(SDK_CALL*)(const char*, const char*)>(SDK_RVA(0x18B370))(text, find); }
}
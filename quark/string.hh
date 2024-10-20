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

		qString() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x1620A0))(this); }
		qString(const qString& text) { reinterpret_cast<void(SDK_CALL*)(void*, const qString&)>(SDK_RVA(0x161F50))(this, text); }

		template <typename... Args>
		qString(const char* format, Args... args) { reinterpret_cast<void(SDK_CALL*)(void*, const char*, Args...)>(SDK_RVA(0x161FC0))(this, format, args...); }

		~qString() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x1643D0))(this); }

		/* Functions */

		template <typename... Args>
		void Format(const char* format, Args... args) { reinterpret_cast<void(SDK_CALL*)(void*, const char*, Args...)>(SDK_RVA(0x16E350))(this, format, args...); }

		qString GetFilePath() { return reinterpret_cast<qString(SDK_CALL*)(void*)>(SDK_RVA(0x170750))(this); }
		qString GetFilePathWithoutExtension() { return reinterpret_cast<qString(SDK_CALL*)(void*)>(SDK_RVA(0x170810))(this); }
		qString GetFilename() { return reinterpret_cast<qString(SDK_CALL*)(void*)>(SDK_RVA(0x1708F0))(this); }
		qString GetFilenameWithoutExtension() { return reinterpret_cast<qString(SDK_CALL*)(void*)>(SDK_RVA(0x1709A0))(this); }
		bool IsEmpty() { return mLength == 0; }
		void MakeLower() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x177530))(this); }
		void MakeUpper() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x177580))(this); }
		int ReplaceCharInPlace(char search_char, char replace_char) { return reinterpret_cast<int(SDK_CALL*)(void*, char, char)>(SDK_RVA(0x17A920))(this, search_char, replace_char); }
		qString ReplaceExtension(const char* ext) { return reinterpret_cast<qString(SDK_CALL*)(void*, const char*)>(SDK_RVA(0x17A950))(this, ext); }
		bool ReplaceString(const char* find_text, const char* replace_text, bool ignore_case) {
			return reinterpret_cast<bool(SDK_CALL*)(void*, const char*, const char*, bool)>(SDK_RVA(0x17AAC0))(this, find_text, replace_text, ignore_case);
		}
		void Set(const char* text, int length) { reinterpret_cast<void(SDK_CALL*)(void*, const char*, int)>(SDK_RVA(0x17C9B0))(this, text, length); }
		void Set(const char* text, int length, const char* textb, int lengthb) { 
			reinterpret_cast<void(SDK_CALL*)(void*, const char*, int, const char*, int)>(SDK_RVA(0x17CA00))(this, text, length, textb, lengthb);
		}
		bool StartsWith(const char* text, int length) { return reinterpret_cast<bool(SDK_CALL*)(void*, const char*, int)>(SDK_RVA(0x17DF20))(this, text, length); }
		bool EndsWith(const char* text, int length) { return reinterpret_cast<bool(SDK_CALL*)(void*, const char*, int)>(SDK_RVA(0x16D410))(this, text, length); }
		qString Substring(int start, int length) { return reinterpret_cast<qString(SDK_CALL*)(void*, int, int)>(SDK_RVA(0x17E180))(this, start, length); }
		qString ToLower() { return reinterpret_cast<qString(SDK_CALL*)(void*)>(SDK_RVA(0x17E5E0))(this); }
		qString ToUpper() { return reinterpret_cast<qString(SDK_CALL*)(void*)>(SDK_RVA(0x17E6B0))(this); }
		qString Trim() { return reinterpret_cast<qString(SDK_CALL*)(void*)>(SDK_RVA(0x17EBE0))(this); }
		int find(const char* str) { return reinterpret_cast<int(SDK_CALL*)(void*, const char*)>(SDK_RVA(0x180FF0))(this, str); }

		/* Operators */

		bool operator!=(const qString& text) { return reinterpret_cast<bool(SDK_CALL*)(void*, const qString&)>(SDK_RVA(0x164AA0))(this, text); }
		bool operator!=(const char* text) { return reinterpret_cast<bool(SDK_CALL*)(void*, const char*)>(SDK_RVA(0x164B30))(this, text); }
		void operator+=(const qString& text) { reinterpret_cast<void(SDK_CALL*)(void*, const qString&)>(SDK_RVA(0x164CB0))(this, text); }
		void operator+=(const char* text) { reinterpret_cast<void(SDK_CALL*)(void*, const char*)>(SDK_RVA(0x164CE0))(this, text); }
		void operator=(const qString& text) { reinterpret_cast<void(SDK_CALL*)(void*, const qString&)>(SDK_RVA(0x49230))(this, text); }
		void operator=(const char* text) { reinterpret_cast<void(SDK_CALL*)(void*, const char*)>(SDK_RVA(0x69DE0))(this, text); }
		bool operator==(const qString& text) { return reinterpret_cast<bool(SDK_CALL*)(void*, const qString&)>(SDK_RVA(0x1649D0))(this, text); }
		bool operator==(const char* text) { return reinterpret_cast<bool(SDK_CALL*)(void*, const char*)>(SDK_RVA(0x164A40))(this, text); }
	};
}
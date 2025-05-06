#pragma once

namespace UFG
{
	class qSymbol
	{
	public:
		u32 mUID;

		SDK_INLINE qSymbol() : mUID(-1) {}
		SDK_INLINE qSymbol(u32 uid) : mUID(uid) {}
		SDK_INLINE qSymbol(const qSymbol& source) : mUID(source.mUID) {}

		void set_from_cstr(const char* pszSymbolString) { SDK_CALL_FUNC(void, 0x18DC30, void*, const char*)(this, pszSymbolString); }

		SDK_SINLINE qSymbol create_from_string(const char* pszSymbolString)
		{
			qProxy<qSymbol> res;
			return *SDK_CALL_FUNC(qSymbol*, 0x180880, qSymbol*, const char*)(&res, pszSymbolString);
		}

		SDK_INLINE operator u32() const { return mUID; }
		SDK_INLINE void operator=(u32 uid) { mUID = uid; }
	};

	class qSymbolUC
	{
	public:
		u32 mUID;

		SDK_INLINE qSymbolUC() : mUID(-1) {}
		SDK_INLINE qSymbolUC(u32 uid) : mUID(uid) {}
		SDK_INLINE qSymbolUC(const qSymbolUC& source) : mUID(source.mUID) {}

		void set_from_cstr(const char* pszSymbolString) { SDK_CALL_FUNC(void, 0x18DC80, void*, const char*)(this, pszSymbolString); }

		SDK_SINLINE qSymbolUC create_from_string(const char* pszSymbolString)
		{
			qProxy<qSymbolUC> res;
			return *SDK_CALL_FUNC(qSymbolUC*, 0x1808E0, qSymbolUC*, const char*)(&res, pszSymbolString);
		}

		SDK_INLINE operator u32() const { return mUID; }
		SDK_INLINE void operator=(u32 uid) { mUID = uid; }
	};

	class qStaticSymbol : public qSymbol
	{
	public:
		using qSymbol::qSymbol;
	};

	class qStaticSymbolUC : public qSymbolUC
	{
	public:
		using qSymbolUC::qSymbolUC;
	};

	class qNamed
	{
	public:
		qSymbol i_name;
	};
}
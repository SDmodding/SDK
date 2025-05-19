#pragma once

class ASymbol
{
public:
	u32 i_uid;

	ASymbol() {}
	ASymbol(u32 uid) : i_uid(uid) {}

	/* Functions */

	void create(const AString& str) { return SDK_CALL_FUNC(void, 0x224780, void*, const AString&, int)(this, str, 0); }
	void create(const char* cstr_p, u32 length = 0) { return SDK_CALL_FUNC(void, 0x2247B0, void*, const char*, u32, int)(this, cstr_p, length, 0); }
};
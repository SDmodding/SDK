#pragma once

class AString
{
public:
	AStringRef* i_str_ref_p;

	~AString() { SDK_CALL_FUNC(void, 0xBAC60, void*)(this); }
	AString(const char* cstr_p) { SDK_CALL_FUNC(void, 0xBAB00, void*, const char*)(this, cstr_p); }

	/* Functions */

	void append(const AString& str) { SDK_CALL_FUNC(void, 0x10CDA0, void*, const AString&)(this, str); }
	void append(char ch) { SDK_CALL_FUNC(void, 0x10CE30, void*, char)(this, ch); }
	void append(const char* cstr_p, u32 length = -1) { SDK_CALL_FUNC(void, 0x223F30, void*, const char*, u32)(this, cstr_p, length); }
	char* as_cstr_writeable() { return SDK_CALL_FUNC(char*, 0x10E9B0, void*)(this); }
	void set_length(u32 length) { SDK_CALL_FUNC(void, 0x13C6C0, void*, u32)(this, length); }
};
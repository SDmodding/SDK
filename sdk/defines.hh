#pragma once

#define SDK_BASE								SDK::gBaseAddress

#define SDK_RVA(x)								SDK_BASE + x
#define SDK_RVA_GET(x)							(reinterpret_cast<uptr>(x) - SDK_BASE)
#define SDK_RVA_PTR(x)							reinterpret_cast<void*>(SDK_RVA(x))

#define SDK_CCHAR(x)							reinterpret_cast<const char*>(SDK_RVA(x))
#define SDK_THIS_OFFSET(x)						(reinterpret_cast<uptr>(this) + x)

/* Helpers */

#define SDK_STRINGIFY(x)						#x
#define SDK_TOSTRING(x)							SDK_STRINGIFY(x)

#define SDK_VAR(type, rva)						reinterpret_cast<type>(SDK_RVA(rva))
#define SDK_VAR_GET(type, rva)					*reinterpret_cast<type*>(SDK_RVA(rva))

#define SDK_CALL								__fastcall
#define SDK_CALL_FUNC(ret_type, rva, ...)		reinterpret_cast<ret_type(SDK_CALL*)(__VA_ARGS__)>(SDK_RVA(rva))

/* Inline */

#define SDK_INLINE								__forceinline
#define SDK_SINLINE								static SDK_INLINE

/* Static Asserts */

#define SDK_ASSERT_SIZEOF(name, size) \
	static_assert(sizeof(name) == size, "ERROR: sizeof(" #name ") isn't equal to " SDK_TOSTRING(size) "!")

/* Quark */

#define qDebugBreak()							__debugbreak()
#define qMin(a, b)								(a < b ? a : b)
#define qMax(a, b)								(a > b ? a : b)
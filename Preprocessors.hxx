#pragma once

// Defines
#ifdef SDK_NO_RVA_PREPROCESSOR
    #define UFG_RVA(x)      x
    #define UFG_RVA_GET(x)  x
#else   
    #define UFG_RVA(x)      (g_BaseAddress + x)
    #define UFG_RVA_GET(x)  (reinterpret_cast<uintptr_t>(x) - g_BaseAddress)
#endif
#define UFG_RVA_PTR(x)		    reinterpret_cast<void*>(UFG_RVA(x))

#define UFG_CONST_CHAR(x)	    reinterpret_cast<const char*>(UFG_RVA(x))
#define UFG_THIS_OFFSET(x)	    (reinterpret_cast<uintptr_t>(this) + x)

// Asserts
#define UFG_ASSERT_CLASS(className, classSize) \
    static_assert(sizeof(className) == classSize, "Size of class: '" #className "' is invalid!")
#define UFG_ASSERT_STRUCT(structName, structSize) \
    static_assert(sizeof(structName) == structSize, "Size of struct: '" #structName "' is invalid!")

// Pads
#define UFG_PAD_INSERT(x, y) x ## y
#define UFG_PAD_DEFINE(x, y) UFG_PAD_INSERT(x, y)
#define UFG_PAD(size) char UFG_PAD_DEFINE(padding_, __LINE__)[size]
#define UFG_PAD_ALIGN(size) private: UFG_PAD(size); public:
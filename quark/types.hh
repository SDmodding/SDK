#pragma once

template <typename E, typename T>
class qEnum
{
public:
	T mValue;

	qEnum() {}
	qEnum(E value) : mValue(static_cast<T>(value)) {}
	qEnum(T value) : mValue(value) {}
};

/* Proxy class for handling abstract classes as members. */

template <typename T>
class qProxy
{
private:
	u8 mProxySize[sizeof(T)];
public:
	SDK_INLINE T* GetProxiedClass() { return reinterpret_cast<T>(this); }
	SDK_INLINE T* operator->() { return reinterpret_cast<T>(this); }
};

template <typename T, uptr RVA>
class qGlobalVar
{
public:
	SDK_INLINE T operator->() { return SDK_VAR(T, RVA); }
	SDK_INLINE operator T&() { return SDK_VAR_GET(T, RVA); }
	SDK_INLINE void operator=(const T& value) { *reinterpret_cast<T*>(SDK_RVA(RVA)) = value; }
};

template <typename T, uptr RVA>
class qGlobalPVar
{
public:
	SDK_INLINE T operator->() { return *reinterpret_cast<T*>(SDK_RVA(RVA)); }
	SDK_INLINE void operator=(const T ptr) { *reinterpret_cast<T*>(SDK_RVA(RVA)) = ptr; }
};
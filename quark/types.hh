#pragma once

template <typename E, typename T>
class qEnum
{
public:
	T mValue;
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
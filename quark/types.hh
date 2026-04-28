#pragma once

template <typename E, typename T>
class qEnum
{
public:
	T mValue;

	qEnum() {}
	qEnum(E value) : mValue(static_cast<T>(value)) {}
	qEnum(T value) : mValue(value) {}

	bool operator==(E e) const { return mValue == e; }
};

/* Proxy class for handling abstract classes as members. */

template <typename T>
class qProxy
{
private:
	u8 mData[sizeof(T)];
public:
	SDK_INLINE T operator*() { return *reinterpret_cast<T*>(this); }
	SDK_INLINE T* operator&() { return reinterpret_cast<T*>(this); }
	SDK_INLINE T* operator->() { return reinterpret_cast<T*>(this); }
	SDK_INLINE operator T() { return *reinterpret_cast<T*>(this); }
};

// Same as qProxy, but has destructor call.
template <typename T>
class qProxyClass : public qProxy<T>
{
public:
	~qProxyClass()
	{
		reinterpret_cast<T*>(this)->~T();
	}
};

template <typename T, uptr RVA>
class qGlobalVar
{
public:
	SDK_INLINE T operator*() { return SDK_VAR(T, RVA); }
	SDK_INLINE T* operator&() { return SDK_VAR(T*, RVA); }
	SDK_INLINE T operator->() { return SDK_VAR(T, RVA); }
	SDK_INLINE operator T&() { return SDK_VAR_GET(T, RVA); }
	SDK_INLINE void operator=(const T value) { SDK_VAR_GET(T, RVA) = value; }
};

template <typename T, u32 SIZE, uptr RVA>
class qGlobalArray
{
public:
	SDK_INLINE T& operator[](int index) { return *(SDK_VAR(T*, RVA) + index); }
	SDK_INLINE T* begin() { return &this->operator[](0); }
	SDK_INLINE T* end() { return &this->operator[](SIZE); }
};

template <typename T, uptr RVA>
class qGlobalPVar
{
public:
	SDK_INLINE T operator*() { return SDK_VAR_GET(T, RVA); }
	SDK_INLINE T operator&() { return SDK_VAR(T, RVA); }
	SDK_INLINE T operator->() { return SDK_VAR_GET(T, RVA); }
	SDK_INLINE void operator=(const T ptr) { SDK_VAR_GET(T, RVA) = ptr; }
};
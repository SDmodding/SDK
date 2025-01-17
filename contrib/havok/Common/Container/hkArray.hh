#pragma once

template <typename T>
class hkArrayBase
{
public:
	T* m_data;
	int m_size;
	int m_capacityAndFlags;

	/* Functions */

	SDK_INLINE T* begin() { return m_data; }
	SDK_INLINE T* end() { return m_data + m_size; }
};

template <typename T>
class hkArray : public hkArrayBase<T>
{
public:
};

template <typename T, unsigned N>
class hkInplaceArray : public hkArray<T>
{
public:
	T m_storage[N];
};
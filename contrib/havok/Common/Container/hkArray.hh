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

template <typename T, typename Allocator = hkContainerHeapAllocator>
class hkArray : public hkArrayBase<T>
{
public:
};
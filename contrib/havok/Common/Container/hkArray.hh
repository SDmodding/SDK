#pragma once

template <typename T>
class hkArrayBase
{
public:
	T* m_data = 0;
	int m_size = 0;
	int m_capacityAndFlags = 0;

	/* Functions */

	SDK_INLINE T* begin() { return m_data; }
	SDK_INLINE T* end() { return m_data + m_size; }

	SDK_INLINE int getCapacity() { return (m_capacityAndFlags & 0x3FFFFFFF); }

	SDK_INLINE void expandOne(class hkMemoryAllocator* alloc = SDK_VAR(hkMemoryAllocator*, 0x2109A28))
	{
		if (getCapacity() > m_size) {
			return;
		}

		SDK_CALL_FUNC(void, 0xC56D30, hkMemoryAllocator*, void*, int)(alloc, this, sizeof(T));
	}

	SDK_INLINE void pushBack(T& t)
	{
		expandOne();
		memcpy(m_data + m_size, &t, sizeof(T));
		++m_size;
	}
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
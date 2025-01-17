#pragma once

template <typename T>
class hkSmallArray
{
public:
	T* m_data;
	u16 m_size;
	u16 m_capacityAndFlags;
};

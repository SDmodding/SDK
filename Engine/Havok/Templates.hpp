#pragma once

template <typename T>
struct hkArray
{
	T* m_data;
	int m_size;
	int m_capacityAndFlags; // highest 2 bits indicate any special considerations about the allocation for the array
};

template <typename T>
struct hkRefPtr
{
	T* m_pntr;
};
#pragma once

class hkClass;

class hkBool
{
public:
	s8 m_bool;
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
public:
	STORAGE m_storage;
};

template <class TYPE>
class hkRefPtr
{
public:
	TYPE* m_pntr;
};

struct hkVariant
{
	void* m_object;
	const hkClass* m_class;
};
#pragma once

class hkClass;

class hkBool
{
public:
	s8 m_bool;

	hkBool() {}
	hkBool(bool b) { m_bool = static_cast<char>(b); }
};

template<typename ENUM, typename STORAGE>
class hkEnum
{
public:
	STORAGE m_storage;

	hkEnum() {}
	hkEnum(ENUM e) { m_storage = static_cast<STORAGE>(e); }

	void operator=(ENUM e) { m_storage = static_cast<STORAGE>(e); }
};

enum hkResultEnum
{
	HK_SUCCESS = 0,
	HK_FAILURE = 1
};

struct hkResult
{
public:
	hkResultEnum m_enum;
};

template<typename BITS, typename STORAGE>
class hkFlags
{
public:
	STORAGE m_storage;

	hkFlags() {}
	hkFlags(STORAGE s) { m_storage = s; }
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
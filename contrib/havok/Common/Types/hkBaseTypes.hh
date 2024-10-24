#pragma once

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
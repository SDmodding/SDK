#pragma once

template <typename Operations, typename Allocator>
class hkCachedHashMap
{
public:
	struct Elem
	{
		u64 hash;
		u64 key;
		u64 value;
	};

	Elem* m_elem;
	int m_numElems;
	int m_hashMod; 
	Operations m_ops;
};
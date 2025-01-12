#pragma once

template <typename KEY>
struct hkMapOperations{};

template <typename KEY, typename VAL = KEY, typename OPS = hkMapOperations<KEY>>
class hkMapBase
{
public:
	struct Pair
	{
		KEY key;
		VAL val;
	};

	Pair* m_elem;
	int m_numElems;
	int m_hashMod;
};

template <typename KEY, typename VAL = KEY, typename OPS = hkMapOperations<KEY>, typename Allocator = hkContainerHeapAllocator>
class hkMap : public hkMapBase<KEY, VAL, OPS>
{
public:
};
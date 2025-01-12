#pragma once

struct hkStringMapOperations{};

template <typename V, typename Allocator = hkContainerHeapAllocator>
class hkStringMap
{
public:
	hkCachedHashMap<hkStringMapOperations, Allocator> m_map;
};
#pragma once

template <typename K, typename V, typename Allocator = hkContainerHeapAllocator>
class hkPointerMap
{
public:
	hkMap<u64, u64, hkMapOperations<u64>, Allocator> m_map;
};
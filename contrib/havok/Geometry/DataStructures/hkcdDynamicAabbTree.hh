#pragma once

class hkcdDynamicAabbTree : public hkReferencedObject
{
public:
	hkBool m_shouldDeleteTree;
	void* m_treePtr;

	SDK_INLINE void ctor() { SDK_CALL_FUNC(void, 0xC8F680, void*)(this); }

	/// Add a leaf with the specified AABB and key. The key will be used during query callbacks
	SDK_INLINE u32 insert(const hkAabb& aabb, u32 key) { return SDK_CALL_FUNC(u32, 0xC8F7B0, void*, const hkAabb&, u32)(this, aabb, key); }
};
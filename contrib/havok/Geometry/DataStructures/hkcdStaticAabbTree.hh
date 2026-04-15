#pragma once

class hkcdStaticAabbTree : public hkReferencedObject
{
public:
	hkBool m_shouldDeleteTree;
	void* m_treePtr;
};
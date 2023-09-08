#pragma once

class hkReferencedObject
{
public:
	void* vfptr;
	uint16_t m_memSizeAndFlags;
	int16_t m_referenceCount;
};
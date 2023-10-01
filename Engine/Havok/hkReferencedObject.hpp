#pragma once

class hkReferencedObject
{
public:
	void* vfptr;
	uint16_t m_memSizeAndFlags;
	int16_t m_referenceCount;

	void RemoveReference()
	{
		reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xC554F0))(this);
	}
};
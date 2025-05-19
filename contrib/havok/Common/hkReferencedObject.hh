#pragma once

class hkReferencedObject : public hkBaseObject
{
public:
	u16 m_memSizeAndFlags;
	i16 m_referenceCount;

	/* Virtual Functions */

	virtual hkClass* getClassType() = 0;

	/* Functions */

	void addReference() { SDK_CALL_FUNC(void, 0xC55420, void*)(this); }

	void removeReference() { SDK_CALL_FUNC(void, 0xC554F0, void*)(this); }
};

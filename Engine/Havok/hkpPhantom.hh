#pragma once

class hkpPhantom : public hkpWorldObject
{
public:
	hkArray<void*> m_overlapListeners;
	hkArray<void*> m_phantomListeners;
};

UFG_PAD(sizeof(hkpPhantom));

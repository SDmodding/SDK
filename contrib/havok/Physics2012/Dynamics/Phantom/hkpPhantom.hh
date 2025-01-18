#pragma once

class hkpPhantom : public hkpWorldObject
{
public:
	hkArray<class hkpPhantomOverlapListener*> m_overlapListeners;
	hkArray<class hkpPhantomListener*> m_phantomListeners;
};
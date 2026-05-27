#pragma once

class hkpRejectChassisListener : public hkReferencedObject, public hkpPhantomOverlapListener
{
public:
	hkpCollidable* m_chassis;
};
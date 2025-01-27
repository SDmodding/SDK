#pragma once

enum hkpCollidableAccept
{
	HK_COLLIDABLE_ACCEPT,
	HK_COLLIDABLE_REJECT
};

struct hkpCollidableAddedEvent
{
	hkpPhantom* m_phantom;
	hkpCollidable* m_collidable;
	hkpCollidableAccept m_collidableAccept;
};

struct hkpCollidableRemovedEvent
{
	hkpPhantom* m_phantom;
	hkpCollidable* m_collidable;
	hkBool m_collidableWasAdded;
};

class hkpPhantomOverlapListener
{
public:
	virtual void collidableAddedCallback(const hkpCollidableAddedEvent& event) = 0;
	virtual void collidableRemovedCallback(const hkpCollidableRemovedEvent& event) = 0;
	virtual ~hkpPhantomOverlapListener() {}
};
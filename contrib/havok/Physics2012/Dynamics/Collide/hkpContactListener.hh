#pragma once

class hkpCollisionEvent;
class hkpContactPointEvent;
class hkpContactPointAddedEvent;
class hkpContactPointRemovedEvent;
class hkpContactProcessEvent;

class hkpContactListener
{
public:
	virtual void contactPointCallback(const hkpContactPointEvent& event) = 0;

	//
	// Collision events.
	//
	// If hkpWorldCinfo.m_fireCollisionCallbacks is set to true, then these are fired when
	// the constraint representing the collision is added or removed from the world.
	//
	// These callbacks are fired single-threaded but not necessarily in deterministic order.
	//
	// Note that a collisionAddedCallback does not guarantee that a collision has occurred if a
	// collisionRemovedCallback is also fired in the same frame. (Of course, contactPointEvents
	// will be fired if a collision did occur during the frame).
	//

		/// Called for a new collision between two bodies.
	virtual void collisionAddedCallback(const hkpCollisionEvent& event) = 0;

	/// Called when two bodies are no longer colliding.
	virtual void collisionRemovedCallback(const hkpCollisionEvent& event) = 0;

	virtual ~hkpContactListener() = 0;

	//
	// Deprecated callbacks which support the old hkpCollisionListener interface.
	//

	virtual void contactPointAddedCallback(hkpContactPointAddedEvent& event) = 0;
	virtual void contactPointRemovedCallback(hkpContactPointRemovedEvent& event) = 0;
	virtual void contactProcessCallback(hkpContactProcessEvent& event) = 0;
};
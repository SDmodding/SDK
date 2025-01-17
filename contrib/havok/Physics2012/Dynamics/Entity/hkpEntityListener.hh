#pragma once

class hkpEntityListener
{
public:
	virtual ~hkpEntityListener() = 0;

	/// Called when an entity is added to the hkpWorld.
	virtual void entityAddedCallback(hkpEntity* entity) {}

	/// Called when an entity is removed from the hkpWorld.
	virtual void entityRemovedCallback(hkpEntity* entity) = 0;

	/// Called when an entity changes its shape.
	virtual void entityShapeSetCallback(hkpEntity* entity) = 0;

	/// Called when the motion type of an entity (rigid body) is changed
	virtual void entitySetMotionTypeCallback(hkpEntity* entity) = 0;

	/// Called when an entity is deleted. hkpEntityListener subclasses \b must implement this function.
	virtual void entityDeletedCallback(hkpEntity* entity) = 0;
};
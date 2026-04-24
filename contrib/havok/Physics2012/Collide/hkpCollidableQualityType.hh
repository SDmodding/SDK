#pragma once

enum hkpCollidableQualityType
{
	/// Invalid or unassigned type. If you add a hkpRigidBody to the hkpWorld,
	/// this type automatically gets converted to either
	/// HK_COLLIDABLE_QUALITY_FIXED, HK_COLLIDABLE_QUALITY_KEYFRAMED or HK_COLLIDABLE_QUALITY_DEBRIS
	HK_COLLIDABLE_QUALITY_INVALID = -1,

	/// Use this for fixed bodies.
	HK_COLLIDABLE_QUALITY_FIXED = 0,

	/// Use this for moving objects with infinite mass.
	HK_COLLIDABLE_QUALITY_KEYFRAMED,

	/// Use this for all your debris objects.
	HK_COLLIDABLE_QUALITY_DEBRIS,

	/// Use this for debris objects that should have simplified TOI collisions with fixed/landscape objects.
	HK_COLLIDABLE_QUALITY_DEBRIS_SIMPLE_TOI,

	/// Use this for moving bodies, which should not leave the world,
	/// but you rather prefer those objects to tunnel through the world than
	/// dropping frames because the engine .
	HK_COLLIDABLE_QUALITY_MOVING,

	/// Use this for all objects, which you cannot afford to tunnel through
	/// the world at all.
	HK_COLLIDABLE_QUALITY_CRITICAL,

	/// Use this for very fast objects.
	HK_COLLIDABLE_QUALITY_BULLET,

	/// For user. If you want to use this, you have to modify hkpCollisionDispatcher::initCollisionQualityInfo()
	HK_COLLIDABLE_QUALITY_USER,

	/// Use this for rigid body character controllers.
	HK_COLLIDABLE_QUALITY_CHARACTER,

	/// Use this for moving objects with infinite mass which should report contact points and TOI-collisions against all other bodies, including other fixed and keyframed bodies.
	///
	/// Note that only non-TOI contact points are reported in collisions against debris-quality objects.
	HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING,

	/// End of this list
	HK_COLLIDABLE_QUALITY_MAX
};
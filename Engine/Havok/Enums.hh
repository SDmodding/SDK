#pragma once

enum hkpCollidableQualityType
{
	HK_COLLIDABLE_QUALITY_INVALID = 0xFFFFFFFF,
	HK_COLLIDABLE_QUALITY_FIXED = 0x0,
	HK_COLLIDABLE_QUALITY_KEYFRAMED = 0x1,
	HK_COLLIDABLE_QUALITY_DEBRIS = 0x2,
	HK_COLLIDABLE_QUALITY_DEBRIS_SIMPLE_TOI = 0x3,
	HK_COLLIDABLE_QUALITY_MOVING = 0x4,
	HK_COLLIDABLE_QUALITY_CRITICAL = 0x5,
	HK_COLLIDABLE_QUALITY_BULLET = 0x6,
	HK_COLLIDABLE_QUALITY_USER = 0x7,
	HK_COLLIDABLE_QUALITY_CHARACTER = 0x8,
	HK_COLLIDABLE_QUALITY_KEYFRAMED_REPORTING = 0x9,
	HK_COLLIDABLE_QUALITY_MAX = 0xA,
};

enum hkpEntityActivation
{
	// Tries to add the body in an inactive state. However if the body overlaps with an active body, it gets activated.
	HK_ENTITY_ACTIVATION_DO_NOT_ACTIVATE = 0x0,

	// Always activate this body and overlapping bodies.
	HK_ENTITY_ACTIVATION_DO_ACTIVATE = 0x1,
};

enum hkpUpdateCollisionFilterOnEntityMode
{
	// Do a full check.
	HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK = 0x0,

	/// Recheck filter but only check for disabled entity-entity collisions which have been enabled before.
	HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY = 0x1,
};

#pragma once

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
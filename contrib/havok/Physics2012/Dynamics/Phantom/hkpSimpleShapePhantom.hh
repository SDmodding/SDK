#pragma once

class hkpSimpleShapePhantom : public hkpShapePhantom
{
public:
	struct CollisionDetail
	{
		class hkpCollidable* m_collidable;
	};

	hkArray<CollisionDetail> m_collisionDetails;
	hkBool m_orderDirty;
};
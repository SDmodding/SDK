#pragma once

struct hkpRootCdPoint
{
	hkContactPoint m_contact;
	hkpCollidable* m_rootCollidableA;
	u32 m_shapeKeyA;
	hkpCollidable* m_rootCollidableB;
	u32 m_shapeKeyB;
};
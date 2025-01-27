#pragma once

struct hkpWorldRayCastOutput : public hkpShapeRayCastOutput
{
	hkpCollidable* m_rootCollidable;
};
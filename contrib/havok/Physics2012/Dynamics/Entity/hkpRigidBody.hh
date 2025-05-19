#pragma once

class hkpRigidBody : public hkpEntity
{
public:
	/* Functions */

	SDK_INLINE void setMass(f32 m) { setMassInv(1.f / m); }
	SDK_INLINE void setMassInv(f32 m) { m_motion->m_inertiaAndMassInv[3] = m; }
	SDK_INLINE f32 getMass() { return (1.f / m_motion->m_inertiaAndMassInv[3]); }
};

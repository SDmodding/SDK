#pragma once

class hkpEaseConstraintsAction : public hkpArrayAction
{
public:
	f32 m_duration;
	f32 m_timePassed;
	hkArray<hkpConstraintInstance*> m_originalConstraints;
	hkArray<f32> m_originalLimits;
};
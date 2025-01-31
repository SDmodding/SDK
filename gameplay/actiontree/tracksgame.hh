#pragma once

class AccuracyModifierTrack : public Track<AccuracyModifierTask>
{
public:
	ExpressionParameterFloat m_fAccuracyModifier;
	bool m_bContinuous;
	bool m_bApplyToTargeter;
	ActionPath m_ActionPath;
};

class AimingFreeAimConeClampTrack : public Track<AimingFreeAimConeClampTask>
{
public:
	f32 m_fFreeAimConeClamp;
};

class AimingSoftLockTrack : public Track<AimingSoftLockTask>
{
public:
};

class AimingSoftLockDisableTrack : public Track<AimingSoftLockDisableTask>
{
public:
};

class SimObjectFlagSetTrack : public Track<SimObjectFlagSetTask>
{
public:
	qEnum<UFG::eSimObjectFlagEnum, u32> m_eSimObjectFlag;
	ActionPath m_ActionPath;
};
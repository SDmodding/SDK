#pragma once

class AccuracyModifierTask : public Task<class AccuracyModifierTrack>, public UFG::qNode<AccuracyModifierTask>
{
public:
	ActionContext* m_pActionContext;
	bool m_bActive : 1;
	bool m_bApplied : 1;
};

class AimingFreeAimConeClampTask : public Task<class AimingFreeAimConeClampTrack>, public UFG::qNode<AimingFreeAimConeClampTask>
{
public:
	ActionContext* m_pActionContext;
};

class AimingSoftLockTask : public Task<class AimingSoftLockTrack>, public UFG::qNode<AimingSoftLockTask>
{
public:
	ActionContext* m_pActionContext;
};

class AimingSoftLockDisableTask : public Task<class AimingSoftLockDisableTrack>, public UFG::qNode<AimingSoftLockDisableTask>
{
public:
	ActionContext* m_pActionContext;
};

class SimObjectFlagSetTask : public Task<class SimObjectFlagSetTrack>, public UFG::qNode<SimObjectFlagSetTask>
{
public:
	ActionContext* m_pActionContext;
	UFG::qSafePointer<UFG::SimObjectPropertiesComponent> m_SimObjectPropertiesComponent;
};

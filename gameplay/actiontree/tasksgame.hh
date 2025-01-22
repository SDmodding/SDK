#pragma once

class SimObjectFlagSetTask : public Task<class SimObjectFlagSetTrack>, public UFG::qNode<SimObjectFlagSetTask>
{
public:
	ActionContext* m_pActionContext;
	UFG::qSafePointer<UFG::SimObjectPropertiesComponent> m_SimObjectPropertiesComponent;
};
#pragma once

class SimObjectFlagSetTrack : Track<SimObjectFlagSetTask>
{
public:
	qEnum<UFG::eSimObjectFlagEnum, u32> m_eSimObjectFlag;
	ActionPath m_ActionPath;
};
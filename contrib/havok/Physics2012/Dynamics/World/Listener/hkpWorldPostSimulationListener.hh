#pragma once

class hkpWorldPostSimulationListener
{
public:
	virtual ~hkpWorldPostSimulationListener() = 0;
	virtual void postSimulationCallback(hkpWorld* world) = 0;
	virtual void inactiveEntityMovedCallback(hkpEntity* entity) = 0;
};
#pragma once

namespace UFG
{
	class NavWaypoint;

	class NavObject
	{
	public:
		virtual ~NavObject() = 0;
		virtual void Update(NavComponent* navComponent) = 0;
		virtual NavWaypoint* GetAdjustedWaypoint() = 0;
		virtual float GetAdjustedSpeed() = 0;
		virtual bool CurrentWaypointReache(NavComponent* navComponent) = 0;
		virtual bool IsValidWaypoint(NavComponent* navComponent) = 0;
		virtual void UpdateControl(NavComponent* navComponent) = 0;
	};
}
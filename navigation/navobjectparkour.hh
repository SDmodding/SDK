#pragma once

namespace UFG
{
	class NavObjectParkour : public NavObject
	{
	public:
		NavWaypoint m_waypoint;
		f32 m_fSpeed;
		qVector3 m_vStartEdgeA;
		qVector3 m_vStartEdgeB;
		qVector3 m_vEndEdgeA;
		qVector3 m_vEndEdgeB;
		bool m_bIsDropDown;
		bool m_bFireVaultCommand;
		bool m_bVaulting;
		bool m_bVaultCompleted;
		bool m_bFirstRun;
		bool m_bHasExtraRoom;
	};
}
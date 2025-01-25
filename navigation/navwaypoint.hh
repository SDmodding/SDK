#pragma once

namespace UFG
{
	class NavWaypoint
	{
	public:
		qProxy<HavokNavPosition> m_navPosition;
		NavObject* m_pNavObject;
		bool m_stopPoint;
		bool m_goalPoint;
		bool m_canSmooth;
	};
}
#pragma once

namespace UFG
{
	class NavGuide
	{
	public:
		enum PathQueryState
		{
			PathQueryState_Idle,
			PathQueryState_Requested,
			PathQueryState_Processing,
			PathQueryState_Succeeded,
			PathQueryState_Failed
		};

		qVector3 m_Pos;
		bool m_Active;
		bool m_Initialized;
		PathQueryState m_PathQueryState;
		FindPathDeferredQuery m_PathQueryInput;
		FindPathOutput m_PathQueryOutput;
		NavParams m_NavParams;
		u32 m_CurrPathPointIndex;

		virtual ~NavGuide() = 0;
	};
}
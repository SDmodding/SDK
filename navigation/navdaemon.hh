#pragma once

namespace UFG
{
	class FindPathOutput : public DaemonQueryOutput
	{
	public:
		UFG::NavPathRefPtr m_pPath;
	};

	class FindPathDeferredQuery : public DaemonQueryInput
	{
	public:
		qProxy<HavokNavPosition> m_npFrom;
		qProxy<HavokNavPosition> m_npTo;
		NavParams* m_pNavParams;
		int m_maxSearchIterations;
	};
}
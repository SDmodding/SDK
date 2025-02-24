#pragma once

namespace UFG
{
	class CoverObjectParkour : public CoverObjectBase
	{
	public:
		qSafePointer<ParkourHandle> m_pParkourHandle;
		bool m_bFoundParkourSync;
		f32 m_fParkourSyncZOffset;
		CoverObjectBase::CoverUser* m_pCoverUser;
	};
}
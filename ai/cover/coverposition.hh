#pragma once

namespace UFG
{
	class CoverPosition : public CoverObjectParkour
	{
	public:
		CoverCornerHandle m_LeftCorner;
		CoverCornerHandle m_RightCorner;
		f32 m_fParkourTVal;
		f32 m_fDistanceInFront;
		f32 m_fDistToLeft;
		f32 m_fDistToRight;
		qVector3 m_vInbetweenParkourPosition;
		qVector3 m_vInbetweenParkourNormal;
		qVector3 m_vInbetweenParkourAxis;
		bool m_bInbetweenParkourLine;
		qProxy<HavokNavPosition> m_NavPosition;
		qStaticBitField<3> m_bfFiringPositionClear;
		qFixedArray<CoverObjectBase::CoverUser*, 3> m_aCoverUsers;
	};
}
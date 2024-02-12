#pragma once

namespace UFG
{
	//============================================================

	class CRoadNetworkSegment;
	class CRoadNetworkIntersection;

	//============================================================

	class CRoadNetworkSection
	{
	public:
		uint32_t mNumSegments;
		qOffset64<qOffset64<CRoadNetworkSegment>> mSegmentOffsetTable;
		uint32_t mNumIntersections;
		qOffset64<qOffset64<CRoadNetworkIntersection>> mIntersectionOffsetTable;
		uint32_t mActive;
	};
	UFG_ASSERT_CLASS(CRoadNetworkSection, 0x28);
}
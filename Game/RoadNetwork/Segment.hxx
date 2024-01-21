#pragma once

namespace UFG
{
	//============================================================

	class CRoadNetworkSubSegment;

	//============================================================

	class CRoadNetworkSegment : public CRoadNetworkNode
	{
	public:
		struct RoadSegmentBits_t
		{
			uint32_t bWayFinderNoPlayer : 1;
			uint32_t bWayFinderNoVehicle : 1;
			uint32_t bGpsRestricted : 1;
			uint32_t bGpsOnly : 1;
			uint32_t bNoTraffic : 1;
			uint32_t bBuildVisibleRoadNetworkByGrid : 1;
			uint32_t bExtendBeyondVisibleAreaLimit : 1;
			uint32_t nPadding : 25;
		};

		uint32_t mPropertyID1;
		uint32_t mPropertyID2;
		qPropertySet* mpPropertySetCached;
		uint32_t mParkingPropertyID2;
		qList<CRoadNetworkSubSegment> mSubSegmentCollection;
		CRoadNetworkNode::RoadNetworkType mRoadNetworkType;
		qVector3 mMin;
		qVector3 mMax;
		float mSpeedLimit;
		RoadSegmentBits_t mBits;
	};
	UFG_ASSERT_CLASS(CRoadNetworkSegment, 0xB0);
}
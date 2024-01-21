#pragma once

namespace UFG
{
	//============================================================

	class CRoadNetworkTrafficLightPhase;
	class CRoadNetworkTrafficLightLocation;

	//============================================================

	class CRoadNetworkIntersection : public CRoadNetworkNode
	{
	public:
		qOffset64<qOffset64<CRoadNetworkTrafficLightLocation>> mTrafficLightLocations;
		char mNumTrafficLightLocations;
		char mIsMerged;
		char mEnableTimer;
		char mNumLightPhases;
		qOffset64<qOffset64<CRoadNetworkTrafficLightPhase>> mLightPhases;
		uint32_t mCurrentPhaseIndex;
		float mTimer;
		qVector3 mAABBMin;
		qVector3 mAABBMax;
	};
	UFG_ASSERT_CLASS(CRoadNetworkIntersection, 0x98);
}
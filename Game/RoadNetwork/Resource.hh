#pragma once

namespace UFG
{
	class CRoadNetworkResource : public qResourceData
	{
	public:
		uint32_t mNumRoadSections;
		qOffset64<qOffset64<CRoadNetworkSection>> mRoadSection;
		uint32_t mNumSegments;
		qOffset64<qOffset64<CRoadNetworkSegment>> mSegmentOffsetTable;
		uint32_t mNumIntersections;
		qOffset64<qOffset64<CRoadNetworkIntersection>> mIntersectionOffsetTable;
		uint32_t mNumIntersectionsWithLights;
		qOffset64<qOffset64<CRoadNetworkIntersection>> mIntersectionWithLightsOffsetTable;
		qOffset64<CRoadNetworkWayfindingList> mWayfindingList;
		qOffset64<CRoadNetworkWayfindingList> mTrafficWayfindingList;
		qOffset64<CRoadNetworkWayfindingList> mTramWayfindingList;
		qOffset64<CRoadNetworkWayfindingList> mFerryWayfindingList;

		static UFG_INLINE CRoadNetworkResource* Instance()
		{
			return *reinterpret_cast<CRoadNetworkResource**>(UFG_RVA(0x2174A50));
		}

		UFG_INLINE CRoadNetworkIntersection* GetClosestNode(const qVector3& p_Position, CRoadNetworkNode::RoadNetworkType p_RoadNetworkType = CRoadNetworkNode::Traffic, qVector3* p_NodePos = nullptr)
		{
			return reinterpret_cast<CRoadNetworkIntersection*(__fastcall*)(void*, const qVector3& , CRoadNetworkNode::RoadNetworkType, qVector3*, void*)>(UFG_RVA(0xD6E30))(this, p_Position, p_RoadNetworkType, p_NodePos, nullptr);
		}

		UFG_INLINE CRoadNetworkSegment* GetSegment(uint32_t p_Index)
		{
			return reinterpret_cast<CRoadNetworkSegment*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0xDB9D0))(this, p_Index);
		}

		/*
		
		CRoadNetworkNode* GetClosestNode(qVector3* pos, qVector3* nodePos = nullptr, unsigned int roadNetworkType = 0)
		{
			return reinterpret_cast<CRoadNetworkNode*(__fastcall*)(void*, qVector3*, unsigned int, qVector3*, void*)>(UFG_RVA(0xD6E30))(this, pos, roadNetworkType, nodePos, nullptr);
		}

		*/
	};
	UFG_ASSERT_CLASS(CRoadNetworkResource, 0xB8);
}
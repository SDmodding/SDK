#pragma once

namespace UFG
{
	class RoadNetworkSection
	{
	public:
		u32 mNumSegments;
		qOffset64<qOffset64<RoadNetworkSegment*>*> mSegmentOffsetTable;
		u32 mNumIntersections;
		qOffset64<qOffset64<RoadNetworkIntersection*>*> mIntersectionOffsetTable;
		u32 mActive;
	};

	class RoadNetworkClosestQueryCache
	{
	public:
		qVector3 mPosQuery;
		qVector3 mPosNearest;
		RoadNetworkSegment* mClosestSegment;
		RoadNetworkIntersection* mClosestIntersection;
	};

	class RoadNetworkResource : public qResourceData
	{
	public:
		u32 mNumRoadSections;
		qOffset64<qOffset64<RoadNetworkSection*>*> mRoadSection;
		u32 mNumSegments;
		qOffset64<qOffset64<RoadNetworkSegment*>*> mSegmentOffsetTable;
		u32 mNumIntersections;
		qOffset64<qOffset64<RoadNetworkIntersection*>*> mIntersectionOffsetTable;
		u32 mNumIntersectionsWithLights;
		qOffset64<qOffset64<RoadNetworkIntersection*>*> mIntersectionWithLightsOffsetTable;
		qOffset64<RoadNetworkWayfindingList*> mWayfindingList;
		qOffset64<RoadNetworkWayfindingList*> mTrafficWayfindingList;
		qOffset64<RoadNetworkWayfindingList*> mTramWayfindingList;
		qOffset64<RoadNetworkWayfindingList*> mFerryWayfindingList;

		/* Static Functions */

		SDK_SINLINE RoadNetworkResource* Instance() { return SDK_VAR_GET(RoadNetworkResource*, 0x2174A50); }

		/* Functions */

		void ClearDataGrids() { SDK_CALL_FUNC(void, 0xD3810, void*)(this); }
		RoadNetworkIntersection* GetClosestIntersection(const qVector3& pos, u32 roadNetworkType, f32 fMaxDistance, qVector3* pposClosest, RoadNetworkClosestQueryCache* cache) { 
			return SDK_CALL_FUNC(RoadNetworkIntersection*, 0xD6180, void*, const qVector3&, u32, f32, qVector3*, RoadNetworkClosestQueryCache*)(this, pos, roadNetworkType, fMaxDistance, pposClosest, cache);
		}
		RoadNetworkIntersection* GetClosestNode(const qVector3& pos, u32 roadNetworkType, qVector3* nodePos, RoadNetworkClosestQueryCache* cache) {
			return SDK_CALL_FUNC(RoadNetworkIntersection*, 0xD6E30, void*, const qVector3&, u32, qVector3*, RoadNetworkClosestQueryCache*)(this, pos, roadNetworkType, nodePos, cache);
		}
		RoadNetworkSegment* GetClosestSegment(const qVector3& pos, u32* p_segment_index, u32 roadNetworkType) {
			return SDK_CALL_FUNC(RoadNetworkSegment*, 0xD7100, void*, const qVector3&, u32*, u32)(this, pos, p_segment_index, roadNetworkType);
		}
		RoadNetworkSubSegment* GetClosestSubSegment(const qVector3& pos, u32 roadNetworkType) { 
			return SDK_CALL_FUNC(RoadNetworkSubSegment*, 0xD7AB0, void*, const qVector3&, u32)(this, pos, roadNetworkType); 
		}
		RoadNetworkIntersection* GetIntersection(u32 index) { return SDK_CALL_FUNC(RoadNetworkIntersection*, 0xD8F30, void*, u32)(this, index); }
		RoadNetworkIntersection* GetIntersectionWithLights(u32 index) { return SDK_CALL_FUNC(RoadNetworkIntersection*, 0xD9180, void*, u32)(this, index); }
		void GetIntersectionsInGrid(qArray<RoadNetworkNode*>& intersections, const qVector3& position, u32 roadNetworkType, f32 radius) {
			SDK_CALL_FUNC(void, 0xD91B0, void*, qArray<RoadNetworkNode*>&, const qVector3&, u32, f32)(this, intersections, position, roadNetworkType, radius);
		}
		void GetLanesIntersectingLine2D(const qVector3& v1, const qVector3& v2, qArray<int>& aIntersections, qArray<int>& aLanes, f32 fMaxIntersectionDistance) {
			SDK_CALL_FUNC(void, 0xD9740, void*, const qVector3&, const qVector3&, qArray<int>&, qArray<int>&, f32)(this, v1, v2, aIntersections, aLanes, fMaxIntersectionDistance);
		}
		RoadNetworkSegment* GetSegment(u32 index) { return SDK_CALL_FUNC(RoadNetworkSegment*, 0xDB9D0, void*, u32)(this, index); }
		void GetSegmentsInGrid(qArray<RoadNetworkSegment*>& segments, const qVector3& position, u32 roadNetworkType, f32 radius) {
			SDK_CALL_FUNC(void, 0xDBA00, void*, qArray<RoadNetworkSegment*>&, const qVector3&, u32, f32)(this, segments, position, roadNetworkType, radius);
		}
		RoadNetworkTrafficLightLocation* GetTrafficLightNearPosition(const qVector3& pos) { return SDK_CALL_FUNC(RoadNetworkTrafficLightLocation*, 0xDC0D0, void*, const qVector3&)(this, pos); }
		RoadNetworkWayfindingList* GetWayfindingList() { return SDK_CALL_FUNC(RoadNetworkWayfindingList*, 0xDC7A0, void*)(this); }
		void InitDataGrids() { SDK_CALL_FUNC(void, 0xDD100, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(RoadNetworkResource, 0xB8);
}
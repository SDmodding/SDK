#pragma once

namespace UFG
{
	class RoadNetworkVisibleArea;

	class RoadNetworkVisibleAreaEdge : public qNode<RoadNetworkVisibleAreaEdge>
	{
	public:
		RoadNetworkVisibleArea* mVisibleArea;
		RoadNetworkSpawnPoint mSpawnPoint[6];
		f32 mT;
		bool mComplete;
		u32 mNumSpawnPoints;
		qArray<RoadNetworkNode*> mNodesToStart;
		RoadNetworkSubSegment* mCurrentSubSegment;
		RoadNetworkSubSegment* mNextSubSegment;
		RoadNetworkSubSegment* mPreviousSubSegment;
		RoadNetworkGate* mNextGate;
		RoadNetworkGate* mPreviousGate;
		qVector3 mDirection;

		/* Functions */

		void UpdateDirection() { SDK_CALL_FUNC(void, 0xE1650, void*)(this); }
		bool ShouldExpand(RoadNetworkGate* gate) { return SDK_CALL_FUNC(bool, 0xE0980, void*, RoadNetworkGate*)(this, gate); }
		void SetCurrentSubSegment(RoadNetworkSubSegment* subSegment) { SDK_CALL_FUNC(void, 0xE0400, void*, RoadNetworkSubSegment*)(this, subSegment); }
		void RefreshT() { SDK_CALL_FUNC(void, 0xDF900, void*)(this); }
		bool IsOuterEdge() { return SDK_CALL_FUNC(bool, 0xDE710, void*)(this); }
		void Init(RoadNetworkVisibleAreaEdge* spawner) { SDK_CALL_FUNC(void, 0xDD070, void*, RoadNetworkVisibleAreaEdge*)(this, spawner); }
		RoadNetworkSubSegment* GetNextSubSegment() { return SDK_CALL_FUNC(RoadNetworkSubSegment*, 0xDADD0, void*)(this); }
		RoadNetworkGate* GetNextGate() { return SDK_CALL_FUNC(RoadNetworkGate*, 0xDABD0, void*)(this); }

		qVector3 GetCurrentPosition()
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0xD8610, void*, qVector3*)(this, &res);
		}

		void ExpandOneStep() { SDK_CALL_FUNC(void, 0xD4710, void*)(this); }
		void AttachSpawnPoints() { SDK_CALL_FUNC(void, 0xD24E0, void*)(this); }
		void AddNodeToPath(RoadNetworkNode* node) { SDK_CALL_FUNC(void, 0xD1BE0, void*, RoadNetworkNode*)(this, node); }
	};

	class EdgeIterator
	{
	public:
		u32 mCurrentIndex;
		qArray<RoadNetworkVisibleAreaEdge*>* mCollection;

		/* Virtual Functions */

		virtual ~EdgeIterator() = 0;
		virtual void First() = 0;
		virtual void Next() = 0;
		virtual bool IsDone() = 0;
	};

	class EdgeStepIterator : public EdgeIterator
	{
	public:
		u32 mEndOfStep;
	};

	class OuterEdgeIterator : public EdgeStepIterator
	{
	public:
	};

	class SpawnPointIterator : public EdgeIterator
	{
	public:
		u32 mSpawnPointIndex;
	};

	class RoadNetworkVisibleAreaEdgeManager
	{
	public:
		qArray<RoadNetworkVisibleAreaEdge*> mEdgeCollection;
		SpawnPointIterator* mSpawnPointIterator;
		EdgeStepIterator* mStepIterator;
		OuterEdgeIterator* mOuterEdgeIterator;

		/* Functions */

		bool ExpandOneStep() { return SDK_CALL_FUNC(bool, 0xD4900, void*)(this); }
		void Clear() { SDK_CALL_FUNC(void, 0xD3770, void*)(this); }
	};

	class RoadNetworkVisibleArea
	{
	public:
		RoadNetworkResource* mRoadNetwork;
		qArray<RoadNetworkNode*>* mPreviousVisibleRoadNetwork;
		qArray<RoadNetworkNode*>* mCurrentVisibleRoadNetwork;
		qArray<RoadNetworkSubSegment*>* mPreviousVisibleSubSegments;
		qArray<RoadNetworkSubSegment*>* mCurrentVisibleSubSegments;
		f32 mSpawnDistanceTransitionSpeed;
		f32 mCurrentVisibleDistance;
		RoadNetworkNode* mClosestNodeFromAllTypes;
		RoadNetworkSubSegment* mClosestSubSegmentFromAllTypes;
		qArray<RoadNetworkNode*> mClosestNodeCollection;
		qArray<RoadNetworkSubSegment*> mClosestSubSegmentCollection;
		RoadNetworkNode* mPreviousClosestNodeFromAllTypes;
		RoadNetworkSubSegment* mPreviousClosestSubSegmentFromAllTypes;
		qArray<RoadNetworkNode*> mPreviousClosestNodeCollection;
		qArray<RoadNetworkSubSegment*> mPreviousClosestSubSegmentCollection;
		RoadNetworkVisibleAreaEdgeManager mEdgeManager;
		qMap<RoadNetworkSegment*> mVisitedSegments;
		qMap<RoadNetworkIntersection*> mVisitedIntersections;
		u32 mVisibleAreaExpansionStep;
		qVector3 mPreviousStartPosition;
		qVector3 mStartPosition;
		qVector3 mStartDirection;
		f32 mStartSpeed;
		bool mForceVisibleAreaUpdate;

		/* Impl Functions */

		SDK_INLINE void SetVisibleDistance(f32 visibleDist) { mCurrentVisibleDistance = visibleDist; }
		SDK_INLINE void SetForceVisibleAreaUpdate() { mForceVisibleAreaUpdate = 1; }
		SDK_INLINE bool NoMoreSpawnPoints() { return mEdgeManager.mSpawnPointIterator->IsDone(); }
		SDK_INLINE void NextSpawnPoint() { mEdgeManager.mSpawnPointIterator->Next(); }
		SDK_INLINE f32 GetVisibleDistance() { return mCurrentVisibleDistance; }
		SDK_INLINE qVector3 GetStartPosition() { return mStartPosition; }
		SDK_INLINE qVector3 GetPreviousStartPosition() { return mPreviousStartPosition; }

		SDK_INLINE RoadNetworkSpawnPoint* GetCurrentEdgeSpawnPoint() {
			return &mEdgeManager.mSpawnPointIterator->mCollection->p[mEdgeManager.mSpawnPointIterator->mCurrentIndex]->mSpawnPoint[mEdgeManager.mSpawnPointIterator->mSpawnPointIndex];
		}

		SDK_INLINE void FirstSpawnPoint() { mEdgeManager.mSpawnPointIterator->First(); }

		/* Functions */

		void UpdateVisibleArea(qArray<RoadNetworkSubSegment*>& deactivateSubSegments, qArray<RoadNetworkSubSegment*>& activateSubSegments) {
			SDK_CALL_FUNC(void, 0xE1C20, void*, qArray<RoadNetworkSubSegment*>&, qArray<RoadNetworkSubSegment*>&)(this, deactivateSubSegments, activateSubSegments);
		}

		bool UpdateClosestRoadNetworkNodes() { return SDK_CALL_FUNC(bool, 0xE1060, void*)(this); }

		bool UpdateByEdges(qArray<RoadNetworkSubSegment*>& deactivateSubSegments, qArray<RoadNetworkSubSegment*>& activateSubSegments) {
			return SDK_CALL_FUNC(bool, 0xE0FD0, void*, qArray<RoadNetworkSubSegment*>&, qArray<RoadNetworkSubSegment*>&)(this, deactivateSubSegments, activateSubSegments);
		}

		bool Update(qArray<RoadNetworkSubSegment*>& deactivateSubSegments, qArray<RoadNetworkSubSegment*>& activateSubSegments) {
			return SDK_CALL_FUNC(bool, 0xE0FC0, void*, qArray<RoadNetworkSubSegment*>&, qArray<RoadNetworkSubSegment*>&)(this, deactivateSubSegments, activateSubSegments);
		}

		bool ShouldUpdateVisibleArea() { return SDK_CALL_FUNC(bool, 0xE0AC0, void*)(this); }
		void Release() { SDK_CALL_FUNC(void, 0xDFC90, void*)(this); }
		void Reinitialize() { SDK_CALL_FUNC(void, 0xDF970, void*)(this); }
		bool IsWithinVisibleExpandAngle(const qVector3& pos) { return SDK_CALL_FUNC(bool, 0xDF1C0, void*, const qVector3&)(this, pos); }
		bool IsWithinVisibleAngle(const qVector3& pos) { return SDK_CALL_FUNC(bool, 0xDF070, void*, const qVector3&)(this, pos); }
		bool IsSubSegmentInRange(RoadNetworkSubSegment* subSegment) { return SDK_CALL_FUNC(bool, 0xDEC60, void*, RoadNetworkSubSegment*)(this, subSegment); }
		bool IsNearStartPosition(const qVector3& pos, f32 maxDistance) { return SDK_CALL_FUNC(bool, 0xDE6C0, void*, const qVector3&, f32)(this, pos, maxDistance); }

		bool IsInRange(RoadNetworkSegment* roadSeg, const qVector3& position) {
			return SDK_CALL_FUNC(bool, 0xDE5A0, void*, RoadNetworkSegment*, const qVector3&)(this, roadSeg, position);
		}

		bool IsInRange(RoadNetworkIntersection* roadInter, const qVector3& position) {
			return SDK_CALL_FUNC(bool, 0xDE4B0, void*, RoadNetworkIntersection*, const qVector3&)(this, roadInter, position);
		}

		void Init(RoadNetworkResource* roadNetwork) { SDK_CALL_FUNC(void, 0xDCCD0, void*, RoadNetworkResource*)(this, roadNetwork); }

		f32 GetValidDistance(const qVector3& position, bool extensionAllowed, bool useSafetyMargin, bool isWater) {
			return SDK_CALL_FUNC(f32, 0xDC450, void*, const qVector3&, bool, bool, bool)(this, position, extensionAllowed, useSafetyMargin, isWater);
		}

		f32 GetSubjectSpeed() { return SDK_CALL_FUNC(f32, 0xDBDA0, void*)(this); }

		qVector3 GetSubjectPosition()
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0xDBD10, void*, qVector3*)(this, &res);
		}

		f32 GetMinVisibleDistance(bool isWater) { return SDK_CALL_FUNC(f32, 0xDA390, void*, bool)(this, isWater); }
		RoadNetworkGate* GetFirstValidGate(RoadNetworkIntersection* intersection) { return SDK_CALL_FUNC(RoadNetworkGate*, 0xD89C0, void*, RoadNetworkIntersection*)(this, intersection); }
		bool GenerateOceanVisibleArea() { return SDK_CALL_FUNC(bool, 0xD58A0, void*)(this); }
		bool GenerateLandVisibleArea() { return SDK_CALL_FUNC(bool, 0xD5760, void*)(this); }
		void CreateEdges(RoadNetworkSubSegment* subSegment) { SDK_CALL_FUNC(void, 0xD3C40, void*, RoadNetworkSubSegment*)(this, subSegment); }

		void CreateEdges(RoadNetworkIntersection* intersection, RoadNetworkVisibleAreaEdge* spawner, RoadNetworkGate* spawnerGate) {
			SDK_CALL_FUNC(void, 0xD3DF0, void*, RoadNetworkIntersection*, RoadNetworkVisibleAreaEdge*, RoadNetworkGate*)(this, intersection, spawner, spawnerGate);
		}

		void CreateEdges(RoadNetworkIntersection* intersection) { SDK_CALL_FUNC(void, 0xD3A70, void*, RoadNetworkIntersection*)(this, intersection); }
		void ClearLastVisibleArea() { SDK_CALL_FUNC(void, 0xD38F0, void*)(this); }
		void ClaimSubSegmentVisited(RoadNetworkSubSegment* subSegment) { SDK_CALL_FUNC(void, 0xD36E0, void*, RoadNetworkSubSegment*)(this, subSegment); }

		bool BuildVisibleRoadNetworkByGrid(RoadNetworkNode* closestNode, u32 roadNetworkType) {
			return SDK_CALL_FUNC(bool, 0xD2A80, void*, RoadNetworkNode*, u32)(this, closestNode, roadNetworkType);
		}

		bool AllowVisibleExtension(RoadNetworkIntersection* roadNode) { return SDK_CALL_FUNC(bool, 0xD22D0, void*, RoadNetworkIntersection*)(this, roadNode); }

		void AddEdge(RoadNetworkSubSegment* currentSubSegment, RoadNetworkSubSegment* nextSubSegment, RoadNetworkGate* nextGate) {
			SDK_CALL_FUNC(void, 0xD18B0, void*, RoadNetworkSubSegment*, RoadNetworkSubSegment*, RoadNetworkGate*)(this, currentSubSegment, nextSubSegment, nextGate);
		}

		void AddEdge(RoadNetworkGate* gate, RoadNetworkVisibleAreaEdge* spawner) { SDK_CALL_FUNC(void, 0xD1840, void*, RoadNetworkGate*, RoadNetworkVisibleAreaEdge*)(this, gate, spawner); }
	};
}
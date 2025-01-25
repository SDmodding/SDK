#pragma once

namespace UFG
{
	class CrosswalkLanes
	{
	public:
		qVector3 m_v1;
		qVector3 m_v2;
		qArray<int> m_iIntersectionID;
		qArray<int> m_aLanes;
	};

	class SidewalkWanderData
	{
	public:
		enum GoalType
		{
			Goal_Destination,
			Goal_LookAhead,
			Goal_Count
		};

		struct GoalInfo
		{
			SidewalkCommonHandle<AISidewalkEdge_Game> mpSidewalkEdge;
			SidewalkCommonHandle<AISidewalkNode_Game> mpDestinationNode;
			qVector3 mPosition;
			int mGoalId;
			bool mIsValid;
		};

		GoalInfo mGoals[Goal_Count];
		bool mAllowedToUseCrosswalks;
		qVector3 mPreviousDesiredDirection;
		bool mPreviousDesiredDirectionValid;
		bool mAtCrossWalk;
		bool mWaitingToCross;
		bool mIsDestinationSegment;
		CrosswalkLanes mCrosswalkLanes;
		u32 mLastUpdateFrame;

		/* Functions */

		void ClearData() { SDK_CALL_FUNC(void, 0x34F2C0, void*)(this); }
		void ClearDestination() { SDK_CALL_FUNC(void, 0x34F400, void*)(this); }
		void ClearLookAheadDestination() { SDK_CALL_FUNC(void, 0x34F650, void*)(this); }
		void MakeLookAheadCurrent() { SDK_CALL_FUNC(void, 0x36D640, void*)(this); }
		void SetDestinationPos(const qVector3& destination, const qVector3& current_position) { 
			SDK_CALL_FUNC(void, 0x3861D0, void*, const qVector3&, const qVector3&)(this, destination, current_position);
		}
	};
}
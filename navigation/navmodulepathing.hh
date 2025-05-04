#pragma once

namespace UFG
{
	class NavModulePathing
	{
	public:
		enum ProcessingStatus
		{
			STATUS_UNDEFINED,
			STATUS_WAITING_FOR_SCHEDULING = (1 << 0),
			STATUS_WAITING_FOR_RESULT = (1 << 1),
			STATUS_FAILED_RESCHEDULING = (1 << 2),
			STATUS_FAILED_WAITING_FOR_RESULT = (1 << 3),
			STATUS_PROCESSED = (1 << 4)
		};

		struct GoalPoint
		{
			ProcessingStatus m_status;
			f32 m_speed;
			f32 m_tolerance;
			int m_userId;
			int m_maxSearchIterations;
			u32 m_resourceTag;
			bool m_append;
			bool m_direct;
			bool m_holdingCompletePath;
			qProxy<HavokNavPosition> m_npPosition;
		};

		bool m_bGoalRefreshed;
		bool m_bAtDestination;
		bool m_bForceGoalAdvance;
		bool m_bPreserveOldPathUntilNewOne;
		float m_elapsedTimeTowardGoal;
		NavComponent* m_navComponent;
		__declspec(align(16)) NavWaypoint m_wpPreviousWaypoint;
		qVector2 m_vHalfSpaceNormal;
		__declspec(align(16)) FindPathDeferredQuery m_PathQueryInput;
		FindPathOutput m_PathQueryOutput;
		TestDeferrer m_Deferrer[2];
		qProxy<HavokNavPosition> m_npInjectedPathSource;
		qProxy<HavokNavPosition> m_npInjectedPathDestination;
		NavPathRefPtr m_pPath;
		NavPathRefPtr m_pInjectedPath;
		qArray<GoalPoint> m_aGoalPoints;
		bool m_bInvalidPath;
		bool m_bRequestReplan;

		/* Virtual Functions */

		virtual ~NavModulePathing() = 0;
		virtual void Update(f32 dt) = 0;
		virtual void Reset() = 0;

		/* Impl Functions */

		SDK_INLINE bool HasPath() { return (m_pPath.m_pNavPath && m_pPath.m_pNavPath->m_aWaypoints.size); }

		SDK_INLINE bool HoldingCompletedPath()
		{
			auto navPath = m_pPath.m_pNavPath;
			return (navPath && navPath->m_aWaypoints.size && m_aGoalPoints.size && m_aGoalPoints.p->m_holdingCompletePath);
		}

		/* Functions */

		void AddGoalPointUid(const HavokNavPosition& npPosition, u32 goalMode, f32 speed, int userId, int maxSearchIterations, f32 tolerance) {
			SDK_CALL_FUNC(void, 0x2634B0, void*, const HavokNavPosition&, u32, f32, int, int, f32)(this, npPosition, goalMode, speed, userId, maxSearchIterations, tolerance);
		}

		bool AttemptInjectPath(const HavokNavPosition& npPosition, const HavokNavPosition& npDestination) {
			return SDK_CALL_FUNC(bool, 0x263950, void*, const HavokNavPosition&, const HavokNavPosition&)(this, npPosition, npDestination);
		}

		void CalculateHalfSpace() { SDK_CALL_FUNC(void, 0x263AB0, void*)(this); }
		void CancelPendingQuery() { SDK_CALL_FUNC(void, 0x263C30, void*)(this); }
		void ClearPath() { SDK_CALL_FUNC(void, 0x263CA0, void*)(this); }

		bool CurrentWaypointReached(const HavokNavPosition& navPosition, bool forceRaycast, bool keepEnd) {
			return SDK_CALL_FUNC(bool, 0x263D70, void*, const HavokNavPosition&, bool, bool)(this, navPosition, forceRaycast, keepEnd);
		}

		bool GetCurrGoalPointInfo(qVector3& position, qVector3& direction, f32& elapsedTime, int& uid) {
			return SDK_CALL_FUNC(bool, 0x2641A0, void*, qVector3&, qVector3&, f32&, int&)(this, position, direction, elapsedTime, uid);
		}

		NavObject* GetNavObject() { return SDK_CALL_FUNC(NavObject*, 0x264320, void*)(this); }
		bool IsInsideCurrGoalRadius(const HavokNavPosition& npAgentPosition) { return SDK_CALL_FUNC(bool, 0x265360, void*, const HavokNavPosition&)(this, npAgentPosition); }
		bool IsInsideCurrGoalRadius(HavokNavPosition* npAgentPosition) { return SDK_CALL_FUNC(bool, 0x265360, void*, HavokNavPosition*)(this, npAgentPosition); }
		void ReadPathingResults(HavokNavPosition& npPosition) { SDK_CALL_FUNC(void, 0x2657C0, void*, HavokNavPosition&)(this, npPosition); }
		void RemoveGoalPointsBefore(GoalPoint*& pGoal) { SDK_CALL_FUNC(void, 0x265B80, void*, GoalPoint*&)(this, pGoal); }
		void RemoveObsoleteGoalPoints() { SDK_CALL_FUNC(void, 0x265C10, void*)(this); }
		void SchedulePathing(HavokNavPosition& npPosition) { SDK_CALL_FUNC(void, 0x265F50, void*, HavokNavPosition&)(this, npPosition); }

		void SetInjectedPath(const HavokNavPosition& npSource, const HavokNavPosition& npDestination, NavPath* pInjectedPath) {
			SDK_CALL_FUNC(void, 0x266290, void*, const HavokNavPosition&, const HavokNavPosition&, NavPath*)(this, npSource, npDestination, pInjectedPath);
		}

		void SetupRepathing() { SDK_CALL_FUNC(void, 0x2663B0, void*)(this); }
		void UpdatePath(HavokNavPosition& npPosition) { SDK_CALL_FUNC(void, 0x266EC0, void*, HavokNavPosition&)(this, npPosition); }

		char UpdatePathStart(HavokNavPosition& navPosition, bool forceRaycast, bool keepEnd) {
			return SDK_CALL_FUNC(char, 0x266F90, void*, HavokNavPosition&, bool, bool)(this, navPosition, forceRaycast, keepEnd);
		}
	};
}
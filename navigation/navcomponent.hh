#pragma once

// Move this to appropriate file.
enum hkaiUFGMaterials
{
	hkaiMaterial_None = 0x0,
	hkaiMaterial_Generic = 0x1,
	hkaiMaterial_Road = 0x2,
	hkaiMaterial_Sidewalk = 0x4,
	hkaiMaterial_Grass = 0x8,
	hkaiMaterial_Water = 0x40,
	hkaiMaterial_Door = 0x80,
	hkaiMaterial_All = 0xFF
};

namespace UFG
{
	class NavComponent : public SimComponent, public qNode<NavComponent>
	{
	public:
		enum { _TypeUID = 0x40000001 };

		class InitParameters
		{
		public:
			bool m_bIsFreerunner;
			bool m_bIsAvoidanceEnabled;
			f32 m_fAIRadius;
			f32 m_fAIAvoidanceRadius;
		};

		qProxy<HavokNavPosition> m_navPosition;
		NavModulePathing* m_pNavModulePathing;
		NavModuleLocal* m_pNavModuleLocal;
		NavModuleController* m_pNavModuleController;
		f32 m_fDesiredSpeed;
		f32 m_fAvoidanceRadius;
		bool m_bIsSloppyFreeRunner;
		f32 m_fMaxAngularVelocity;
		s8 m_iHasSteeringControl;
		NavParams m_navParams;
		qVector2 m_vForward;
		Ticket m_postStreamingTicket;
		eTicketBoothEnum m_TicketType;

		/* Virtual Functions */

		virtual void Init(SimObject* pSimObject) = 0;
		virtual void Reset(bool softReset) = 0;
		virtual void UpdatePostStreaming(f32 dt) = 0;
		virtual void UpdatePreQuery(f32 dt) = 0;
		virtual void UpdatePostQuery(f32 dt) = 0;
		virtual void UpdateSteering(f32 dt) = 0;
		virtual void UpdateControl(f32 dt) = 0;

		/* Impl Functions */

		SDK_INLINE f32 GetAvoidanceRadius() { return m_fAvoidanceRadius; }
		SDK_INLINE bool HasDestination() { return m_pNavModulePathing->m_aGoalPoints.size; }

		SDK_INLINE bool HasPath()
		{
			auto navPath = m_pNavModulePathing->m_pPath.m_pNavPath;
			return (navPath && navPath->m_aWaypoints.size);
		}


		SDK_INLINE bool IsAtDestination() { return m_pNavModulePathing->m_bAtDestination; }

		SDK_INLINE bool IsCurrentGoalProcessed()
		{
			auto goalPoints = &m_pNavModulePathing->m_aGoalPoints;
			return goalPoints->size && (goalPoints->p->m_status & (NavModulePathing::STATUS_PROCESSED | NavModulePathing::STATUS_FAILED_WAITING_FOR_RESULT | NavModulePathing::STATUS_FAILED_RESCHEDULING));
		}

		SDK_INLINE bool IsDestinationUnreachable() { return (m_pNavModulePathing->m_aGoalPoints.size && m_pNavModulePathing->m_bInvalidPath); }
		SDK_INLINE void PreserveDestination() { m_pNavModulePathing->m_bGoalRefreshed = 1; }
		SDK_INLINE void SetDesiredSpeed(f32 fDesiredSpeed) { m_fDesiredSpeed = fDesiredSpeed; }
		SDK_INLINE void SetDestinationParams(NavParams& navParams) { m_navParams = navParams; }

		/* Functions */

		bool AIRayCastHits(HavokNavPosition& positionEnd, qVector3* pCollisionPoint) {
			return SDK_CALL_FUNC(bool, 0x263310, void*, HavokNavPosition&, qVector3*)(this, positionEnd, pCollisionPoint);
		}

		bool AIRayCastHits(const qVector3& vEnd, qVector3* pCollisionPoint) { return SDK_CALL_FUNC(bool, 0x263340, void*, const qVector3&, qVector3*)(this, vEnd, pCollisionPoint); }

		void AddGoalPoint(const HavokNavPosition& npDestination, AiPathGoalMode goalMode, f32 speed, f32 fDestinationTolerance) {
			SDK_CALL_FUNC(void, 0x263430, void*, const HavokNavPosition&, u32, f32, f32)(this, npDestination, goalMode, speed, fDestinationTolerance);
		}

		void AddGoalPointUid(const HavokNavPosition& npDestination, AiPathGoalMode goalMode, f32 speed, int userId, f32 fDestinationTolerance) {
			SDK_CALL_FUNC(void, 0x263470, void*, const HavokNavPosition&, u32, f32, int, f32)(this, npDestination, goalMode, speed, userId, fDestinationTolerance);
		}

		void AddGoalPointUidHACK(const HavokNavPosition& npDestination, AiPathGoalMode goalMode, f32 speed, int userId, int maxSearchIteration, f32 fDestinationTolerance) {
			SDK_CALL_FUNC(void, 0x263760, void*, const HavokNavPosition&, u32, f32, int, int, f32)(this, npDestination, goalMode, speed, userId, maxSearchIteration, fDestinationTolerance);
		}

		void EnablePathingOnMaterial(hkaiUFGMaterials material, bool enabled) { SDK_CALL_FUNC(void, 0x2640E0, void*, hkaiUFGMaterials, bool)(this, material, enabled); }
		void ForceGoalPointAdvance() { SDK_CALL_FUNC(void, 0x264130, void*)(this); }
		eCollisionAvoidanceType GetCollisionAvoidanceType() { return SDK_CALL_FUNC(eCollisionAvoidanceType, 0x264170, void*)(this); }

		bool GetCurrGoalPointInfo(qVector3& position, qVector3& direction, f32& elapsedTime, int& uid) {
			return SDK_CALL_FUNC(bool, 0x264190, void*, qVector3&, qVector3&, f32&, int&)(this, position, direction, elapsedTime, uid);
		}

		const qVector4& GetCurrentPosition() { return SDK_CALL_FUNC(const qVector4&, 0x2642B0, void*)(this); }
		f32 GetDesiredSpeed() { return SDK_CALL_FUNC(f32, 0x2642F0, void*)(this); }
		void InitWithParams(const InitParameters& parameters) { SDK_CALL_FUNC(void, 0x264FF0, void*, const InitParameters&)(this, parameters); }

		void InjectPath(const HavokNavPosition& npSource, const HavokNavPosition& npDestination, NavPath& navPath) {
			SDK_CALL_FUNC(void, 0x265090, void*, const HavokNavPosition&, const HavokNavPosition&, NavPath&)(this, npSource, npDestination, navPath);
		}

		bool IsDestinationObstructed() { return SDK_CALL_FUNC(bool, 0x2652D0, void*)(this); }
		void SetCollisionAvoidanceType(eCollisionAvoidanceType type) { SDK_CALL_FUNC(void, 0x266250, void*, eCollisionAvoidanceType)(this, type); }
	};
	SDK_ASSERT_SIZEOF(NavComponent, 0x110);
}
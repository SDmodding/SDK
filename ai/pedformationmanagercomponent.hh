#pragma once

namespace UFG
{
	enum eMoveType
	{
		eMoveType_None,
		eMoveType_Walk,
		eMoveType_Jog,
		eMoveType_Run,
		NUM_MOVETYPES,
		eMoveType_Undefined = -1,
	};
}

namespace UFG
{
	enum ePedFormationFacingType
	{
		ePedFormationFacingType_Invalid,
		ePedFormationFacingType_None,
		ePedFormationFacingType_Leader_Direction,
		ePedFormationFacingType_Centre,
		NUM_PED_FORMATION_FACING_TYPES
	};

	class PedFormationProfile : public qNodeRB<PedFormationProfile>
	{
	public:
		struct Slot : qSafePointerNode<Slot>
		{
			ePedFormationFacingType mFacingType;
			u16 mAngle;
			bool mCanCrossLeader;
			f32 mPreference;
			u32 mMinFollowers;
			f32 mMinDistance;
			f32 mMaxDistance;
			f32 mMaxLookAhead;
			f32 mMinFacingDifference;
			f32 mMinFacingDifferenceHysteresis;
			f32 mMaxRadialDistanceFromDesiredPosition;
			f32 mMaxLateralDistanceFromDesiredPosition;
			f32 mMinRadialHysteresisModifier;
			f32 mMaxRadialHysteresisModifier;
			f32 mMaxRadialDistanceFromDesiredPositionHysteresisLarge;
			f32 mMaxRadialDistanceFromDesiredPositionHysteresis;
			f32 mMaxRadialDistanceFromDesiredPositionHysteresisFar;
			f32 mMaxLateralDistanceFromDesiredPositionHysteresis;
			f32 mMaxLateralDistanceFromDesiredPositionHysteresisFar;
		};

		qFixedArray<Slot, 9> mSlots;
		f32 mDistanceToBeConsideredClose;
		f32 mMinTimeForLargeHysteresis;
		f32 mMaxTimeForLargeHysteresis;
		f32 mMinTimeBetweenSlotChanges;
		f32 mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting;
		u32 mMaxFollowers;
		bool mIsActive;
	};

	class PedFormationTimer
	{
	public:
		f32 mNextTime;
	};

	class PedFormationPair
	{
	public:
		qSafePointer<SimObject> m_pPair;
		PedFormationTimer m_PairChangeAllowedTimer;
	};

	class PedFormationSlot
	{
	public:
		enum ePositionType
		{
			ePOSITION_IN_POSITION,
			ePOSITION_STAYING_IN_POSITION,
			ePOSITION_CLOSE,
			ePOSITION_NOT_IN_POSITION,
			ePOSITION_FAR,
			NUM_PEDFORMATIONSLOT_POSITION_TYPES
		};

		qVector3 m_Direction;
		u16 m_Angle;
		f32 m_Distance;
		qVector3 m_FacingDirection;
		PedFormationSlot::ePositionType m_InPosition;
		f32 m_TimeFinishUsingLargeHysteresis;
		bool m_CurrentlyInRange;
		bool m_CurrentlyFacingCorrectly;
		bool m_CurrentlyStayingClose;
		qSafePointer<GetInPedFormationNode> m_pMember;
		PedFormationPair m_Pair;
		f32 m_TimeGotIntoPosition;
		eMoveType m_DesiredMoveType;
		eMoveType m_NextMoveType;
		f32 m_RadialHysteresisModifier;
		PedFormationTimer m_SlotChangeAllowedTimer;
		PedFormationTimer m_ReactionTimer;
		qSafePointer<SimComponent, PedFormationManagerComponent> m_pPedFormationManagerComponent;
		PedFormationProfile::Slot* m_pProfileSlot;

		/* Functions */

		void InitWithDefaults(PedFormationManagerComponent* parent) { SDK_CALL_FUNC(void, 0x3689F0, void*, PedFormationManagerComponent*)(this, parent); }
		void SetInPosition(ePositionType in_position) { SDK_CALL_FUNC(void, 0x386760, void*, ePositionType)(this, in_position); }
		void SetRadialHysteresisModifier() { SDK_CALL_FUNC(void, 0x387B70, void*)(this); }
	};

	class PedFormationProfileSlot
	{
	public:
		qSafePointer<PedFormationProfile::Slot> mProfileSlot;
		PedFormationSlot* mMemberSlot;
		qVector3 mOffset;
		bool mIsClear;
		bool mIsEnabled;
		f32 mForwardClearance;
		f32 mClearDistance;
	};

	class PedFormationManagerComponent : public SimComponent, public UpdateInterface, public qNode<PedFormationManagerComponent>
	{
	public:
		enum { _TypeUID = 0x4E000001 };

		bool m_DebugDrawEnabled;
		RebindingComponentHandle<TransformNodeComponent> m_pTransformNodeComponent;
		RebindingComponentHandle<AIEntityComponent> m_pAIEntityComponent;
		RebindingComponentHandle<ActionTreeComponent> m_pActionTreeComponent;
		RebindingComponentHandle<TargetingSystemBaseComponent> m_pTargetingSystemBaseComponent;
		qFixedArray<PedFormationSlot, 4> m_Slots;
		u32 m_NumFreeSlots;
		u32 m_NumFollowers;
		PedFormationProfile* m_pCurrentProfile;
		bool m_CurrentlySprinting;
		eMoveType m_LeaderMoveType;
		f32 m_Speed;
		f32 m_AngularVelocity;
		qVector2 m_FormationForward;
		qVector2 m_PrevFormationForward;
		u32 m_UpdateOffset;
		qFixedArray<PedFormationProfileSlot, 9> m_ProfileSlots;
		PedFormationPair m_Pair;
		PedFormationTimer m_LeaderWaitTime;
		PedFormationTimer m_LeaderNoWaitTime;
		qVector3 m_Destination;
		bool m_IsDestinationValid;
		bool m_IsApproachingTurn;
		Ticket m_Ticket;

		/* Static Members */

		SDK_VINLINE qGlobalVar<qTreeRB<PedFormationProfile>*, 0x23BB6B0> s_Profiles;
		SDK_VINLINE qGlobalVar<qFixedArray<PedFormationProfile, 16>*, 0x23BB950> s_ProfilePool;

		/* Virtual Functions */

		virtual bool PedFormationSlotIsOccupied(GroupComponent* pGC, int slot_index) = 0;

		/* Static Functions */

		SDK_SINLINE PedFormationManagerComponent* PropertiesOnActivateNew(SceneObjectProperties* pSceneObj, bool required = 1) {
			return SDK_CALL_FUNC(PedFormationManagerComponent*, 0x37F190, SceneObjectProperties*, bool)(pSceneObj, required);
		}

		/* Impl Functions */

		SDK_INLINE SimObject* GetLeadersPair() { return m_Pair.m_pPair.m_pPointer; }

		/* Functions */

		void AssignProfileSlot(PedFormationProfileSlot& profileSlot, PedFormationSlot& slot) {
			SDK_CALL_FUNC(void, 0x342360, void*, PedFormationProfileSlot&, PedFormationSlot&)(this, profileSlot, slot);
		}

		void CheckIfInDesiredPosition() { SDK_CALL_FUNC(void, 0x34D610, void*)(this); }
		void CheckIfSprinting() { SDK_CALL_FUNC(void, 0x34DD90, void*)(this); }
		void Clear() { SDK_CALL_FUNC(void, 0x34EBF0, void*)(this); }

		bool CrossesLeadersPath(const qVector2& follower_start, const qVector2& follower_end) {
			return SDK_CALL_FUNC(bool, 0x351850, void*, const qVector2&, const qVector2&)(this, follower_start, follower_end);
		}

		bool DirectionIsClear(HavokNavPosition& npStartPos, const qVector3& direction, f32* max_clear_distance, eConstrainToSidewalks constrain_to_sidewalks) {
			return SDK_CALL_FUNC(bool, 0x352A20, void*, HavokNavPosition&, const qVector3&, f32*, eConstrainToSidewalks)(this, npStartPos, direction, max_clear_distance, constrain_to_sidewalks);
		}

		SimObject* GetClosestMember(const qVector3& pos, SimObject* pExclude1 = 0, SimObject* pExclude2 = 0) {
			return SDK_CALL_FUNC(SimObject*, 0x35AFE0, void*, const qVector3&, SimObject*, SimObject*)(this, pos, pExclude1, pExclude2);
		}

		bool GetDesiredPosition(GetInPedFormationNode* get_in_formation, qVector3& desired_position) {
			return SDK_CALL_FUNC(bool, 0x35DB90, void*, GetInPedFormationNode*, qVector3&)(this, get_in_formation, desired_position);
		}

		bool GetDesiredWaypoint(GetInPedFormationNode* get_in_formation, qVector3& desired_waypoint, f32& desired_speed) {
			return SDK_CALL_FUNC(bool, 0x35E3A0, void*, GetInPedFormationNode*, qVector3&, f32&)(this, get_in_formation, desired_waypoint, desired_speed);
		}

		SimObject* GetFollowersPair(SimObject* pFollower) { return SDK_CALL_FUNC(SimObject*, 0x35FC00, void*, SimObject*)(this, pFollower); }

		PedFormationSlot::ePositionType GetInPositionType(GetInPedFormationNode* get_in_formation) {
			return SDK_CALL_FUNC(PedFormationSlot::ePositionType, 0x360020, void*, GetInPedFormationNode*)(this, get_in_formation);
		}

		bool IsFarFromPosition(PedFormationProfile::Slot& profileSlot, f32 current_radial_offset, f32 current_distance_from_centre) {
			return SDK_CALL_FUNC(bool, 0x36A970, void*, PedFormationProfile::Slot&, f32, f32)(this, profileSlot, current_radial_offset, current_distance_from_centre);
		}

		bool IsInPedFormation(GetInPedFormationNode& get_in_formation) { return SDK_CALL_FUNC(bool, 0x36AE60, void*, GetInPedFormationNode&)(this, get_in_formation); }

		bool IsInPosition(const qVector3& follower_position, const qVector3& desired_position, f32 max_radial_offset, f32 max_lateral_offset, f32& current_radial_offset, f32& current_lateral_offset, bool debug_print = 0) {
			return SDK_CALL_FUNC(bool, 0x36B150, void*, const qVector3&, const qVector3&, f32, f32, f32&, f32&, bool)(this, follower_position, desired_position, max_radial_offset, max_lateral_offset, current_radial_offset, current_lateral_offset, debug_print);
		}

		bool IsMoving(bool includeTurning) { return SDK_CALL_FUNC(bool, 0x36B8A0, void*, bool)(this, includeTurning); }
		void MaybeSetDesiredPositionFromProfile() { SDK_CALL_FUNC(void, 0x375FB0, void*)(this); }

		void OnArrived(GetInPedFormationNode& get_in_formation, qVector3* desired_position = 0, float desired_speed = 0.f) {
			SDK_CALL_FUNC(void, 0x377D20, void*, GetInPedFormationNode&, qVector3*, float)(this, get_in_formation, desired_position, desired_speed);
		}

		void Register(GetInPedFormationNode* get_in_formation) { SDK_CALL_FUNC(void, 0x3808C0, void*, GetInPedFormationNode*)(this, get_in_formation); }
		void Reset() { SDK_CALL_FUNC(void, 0x382EF0, void*)(this); }
		void SetCurrentProfile(PedFormationProfile* pCurrentProfile) { SDK_CALL_FUNC(void, 0x385370, void*, PedFormationProfile*)(this, pCurrentProfile); }

		void SetDesiredDirection(u32 slot_index, GetInPedFormationNode* get_in_formation, const qVector3& desired_direction) {
			SDK_CALL_FUNC(void, 0x3859C0, void*, u32, GetInPedFormationNode*, const qVector3&)(this, slot_index, get_in_formation, desired_direction);
		}

		void SetDesiredDirectionFromCurrentPosition(int slot_index, GetInPedFormationNode* get_in_formation) {
			SDK_CALL_FUNC(void, 0x385F70, void*, int, GetInPedFormationNode*)(this, slot_index, get_in_formation);
		}

		void UnregisterIncorrectlyRegisteredPeople() { SDK_CALL_FUNC(void, 0x38AB80, void*)(this); }
		void UnregisterInvalidFollowers() { SDK_CALL_FUNC(void, 0x38ABE0, void*)(this); }
		void UnregisterSlot(int slot_index) { SDK_CALL_FUNC(void, 0x38ACD0, void*, int)(this, slot_index); }
		void Update(f32 delta_sec) { SDK_CALL_FUNC(void, 0x3917F0, void*, f32)(this, delta_sec); }
		void UpdateDesiredFacing() { SDK_CALL_FUNC(void, 0x395190, void*)(this); }
		void UpdatePairs() { SDK_CALL_FUNC(void, 0x3974F0, void*)(this); }
		void UpdatePeriodic(f32 delta_sec) { SDK_CALL_FUNC(void, 0x397F60, void*, f32)(this, delta_sec); }
		void UpdateProfileSlots() { SDK_CALL_FUNC(void, 0x3982B0, void*)(this); }
		void UpdateSpeed(f32 delta_sec) { SDK_CALL_FUNC(void, 0x398D80, void*, f32)(this, delta_sec); }
	};
	SDK_ASSERT_SIZEOF(PedFormationManagerComponent, 0x650);
}
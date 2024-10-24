#pragma once

namespace UFG
{
	class TargetingSystemBaseComponent;

	enum eTargetTypeEnum : s32
	{
		eTARGET_TYPE_INVALID,
		eTARGET_TYPE_SELF,
		eTARGET_TYPE_ATTACKER,
		eTARGET_TYPE_AIM_POSITION,
		eTARGET_TYPE_VEHICLE_DRIVER,
		eTARGET_TYPE_VEHICLE_PASSENGER,
		eTARGET_TYPE_VEHICLE_PASSENGER2,
		eTARGET_TYPE_VEHICLE_PASSENGER3,
		eTARGET_TYPE_VEHICLE_PASSENGER4,
		eTARGET_TYPE_VEHICLE_ROLE_SWAP_TEMP,
		eTARGET_TYPE_VEHICLE_CARGO1,
		eTARGET_TYPE_VEHICLE_CARGO2,
		eTARGET_TYPE_VEHICLE_CARGO3,
		eTARGET_TYPE_VEHICLE_PASSENGER_TRUNK,
		eTARGET_TYPE_CLOSEST_PED,
		eTARGET_TYPE_COVER_OBJECT,
		eTARGET_TYPE_COVER_POPOUT,
		eTARGET_TYPE_EQUIPPED,
		eTARGET_TYPE_EQUIPPED_LEFT_HAND,
		eTARGET_TYPE_EQUIPPED_HAT,
		eTARGET_TYPE_EQUIPPED_GLASSES,
		eTARGET_TYPE_FACING,
		eTARGET_TYPE_FOCUS,
		eTARGET_TYPE_GRAPPLE,
		eTARGET_TYPE_LOOK_AT,
		eTARGET_TYPE_POI_LOOK_AT,
		eTARGET_TYPE_POI_USE,
		eTARGET_TYPE_POI_PARENT_OBJEC,
		eTARGET_TYPE_VEHICLE,
		eTARGET_TYPE_AI_OBJECTIVE,
		eTARGET_TYPE_TO_FOLLOW,
		eTARGET_TYPE_PLAYER,
		eTARGET_TYPE_SCRIPTED_MARKER,
		eTARGET_TYPE_STIMULUS_PRODUCER,
		eTARGET_TYPE_CONDITION_STIMULUS_PRODUCER,
		eTARGET_TYPE_IGNORE_AVOIDANCE,
		eTARGET_TYPE_LAST_THREAT,
		eTARGET_TYPE_POINT_AT,
		eTARGET_TYPE_ATTACKING,
		eTARGET_TYPE_CONVERSATION,
		eTARGET_TYPE_INTERACTIVE_PROP,
		eTARGET_TYPE_PICKUP_ITEM,
		eTARGET_TYPE_STOWED_WEAPON,
		eTARGET_TYPE_STOWED_2H_WEAPON,
		eTARGET_TYPE_VEHICLE_ACTION_HIJACK,
		eTARGET_TYPE_VEHICLE_ACTION_HIJACK_POTENTIAL,
		eTARGET_TYPE_VEHICLE_CLOSEST_POINT,
		eTARGET_TYPE_CLOSEST_DOWNED_PED,
		eTARGET_TYPE_DIRECTIONAL,
		eTARGET_TYPE_PHYSICAL,
		eTARGET_TYPE_SOCIAL,
		eTARGET_TYPE_CROWD_PUSH_PRIMARY,
		eTARGET_TYPE_CROWD_PUSH_SECONDARY,
		eTARGET_TYPE_ESCORT,
		eTARGET_TYPE_OWNER,
		eTARGET_TYPE_LAST_CREATED_OBJECT,
		eTARGET_TYPE_SUBTARGET,
		eTARGET_TYPE_TRANSIT,
		eTARGET_TYPE_WORLD_EDITOR_SELECTED_OBJECT,
		eTARGET_TYPE_CRANE_CONTAINER_ATTACHED,
		eTARGET_TYPE_CRANE_CONTAINER_UNATTACHED,
		eTARGET_TYPE_MY_SPAWN_POINT,
		eTARGET_TYPE_GROUP_LEADER,
		eTARGET_TYPE_GROUP_MEMBER,
		eTARGET_TYPE_GROUP_MEMBER2,
		eTARGET_TYPE_GROUP_MEMBER3,
		eTARGET_TYPE_GROUP_MEMBER4,
		eTARGET_TYPE_GROUP_MEMBER_PAIRED,
		eTARGET_TYPE_BEST_INTERACTION_POINT,
		eTARGET_TYPE_INTERACTION_POINT0,
		eTARGET_TYPE_INTERACTION_POINT1,
		eTARGET_TYPE_INTERACTION_POINT2,
		eTARGET_TYPE_INTERACTION_POINT3,
		eTARGET_TYPE_INTERACTION_POINT4,
		eTARGET_TYPE_INTERACTION_POINT5,
		eTARGET_TYPE_HIJACKABLE_VEHICLE,
		eTARGET_TYPE_SYNC,
		eTARGET_TYPE_BEST_MELEE_ATTACKER,
		eTARGET_TYPE_LAST_ATTACKED,
		eTARGET_TYPE_INTERACTION_OFFSET,
		eTARGET_TYPE_TRANSACTION,
		eTARGET_TYPE_LAST_GRAPPLE,
		eTARGET_TYPE_PROBE_LOW_L,
		eTARGET_TYPE_PROBE_LOW_C,
		eTARGET_TYPE_PROBE_LOW_R,
		eTARGET_TYPE_PROBE_MID_L,
		eTARGET_TYPE_PROBE_MID_C,
		eTARGET_TYPE_PROBE_MID_R,
		eTARGET_TYPE_PROBE_HIGH_L,
		eTARGET_TYPE_PROBE_HIGH_C,
		eTARGET_TYPE_PROBE_HIGH_R,
		NUM_TARGET_TYPES
	};

	class TargetingSimObject : public qNode<TargetingSimObject>
	{
	public:
		TargetingSystemBaseComponent* m_pTSBC;
		qSafePointer<SimObject, SimObject> m_pTarget;
		qEnum<eTargetTypeEnum, u8> m_eTargetType;
		bool m_bLock;

		/* Functions */

		void SetTarget(SimObject* pNewTarget) { reinterpret_cast<void(SDK_CALL*)(void*, SimObject*)>(SDK_RVA(0x54EB60))(this, pNewTarget); }

		void SetLock(bool bLock) { m_bLock = bLock; }
	};
	SDK_ASSERT_SIZEOF(TargetingSimObject, 0x38);
}
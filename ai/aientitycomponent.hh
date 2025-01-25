#pragma once

namespace UFG
{
	enum eHeadTrackType
	{
		eHEAD_TRACK_TYPE_TRANSFORM_NODE,
		eHEAD_TRACK_TYPE_POSITION,
		NUM_HEAD_TRACK_TYPES,
		eHEAD_TRACK_TYPE_NONE = -1,
	};

	class HeadTrackTarget
	{
	public:
		eHeadTrackType m_Type;
		qVector3 m_Offset;
		qSafePointer<TransformNodeComponent> m_pTransformNodeComponent;
		qVector3 m_Position;
	};

	class ThreatTarget
	{
	public:
		qSafePointer<SimObject> m_pTarget;
		f32 m_Radius;
	};

	class AIEntityComponent : public SimComponent
	{
	public:
		enum { _TypeUID = 0x46000001 };

		RebindingComponentHandle<TransformNodeComponent> m_pTransformNodeComponent;
		RebindingComponentHandle<ActionTreeComponent> m_pActionTreeComponent;
		RebindingComponentHandle<RigidBodyComponent> m_pRigidBodyComponent;
		RebindingComponentHandle<CharacterAnimationComponent> m_pCharacterAnimationComponent;
		RebindingComponentHandle<SimObjectCharacterPropertiesComponent> m_pSimObjectCharacterPropertiesComponent;
		RebindingComponentHandle<AttackRightsComponent> m_pAttackRightsComponent;
		RebindingComponentHandle<SceneObjectProperties> m_pSceneObjectProperties;
		RebindingComponentHandle<HealthComponent> m_pHealthComponent;
		RebindingComponentHandle<TargetingSystemPedBaseComponent> m_pTargetingSystemBaseComponent;
		RebindingComponentHandle<CharacterOccupantComponent> m_pCharacterOccupantComponent;
		SidewalkWanderData m_WanderData;
		HeadTrackTarget m_HeadTrackingTarget;
		bool m_AIPositionValid;
		bool m_HostilityEnabled;
		NearbyCharacter* m_pNearbyCharacter;
		qSafePointer<GroupComponent> m_pGroupComponent;
		qSafePointer<CombatRegion> m_pCombatRegion;
		qFixedArray<ThreatTarget, 10> m_ThreatTargets;
		qVector3 m_vCombatRegionMoveToVec;
		bool m_bActive;
		bool m_bCanWander;
		bool m_bRefreshWander;
		bool m_bCanUseCrosswalks;

		/* Impl Functions */

		SDK_INLINE void ClearThreatTargets() { m_ThreatTargets.size = 0; }
		SDK_INLINE CharacterOccupantComponent* GetCharacterOccupantComponent() { return m_pCharacterOccupantComponent.GetComponent(); }
		SDK_INLINE HealthComponent* GetHealthComponent() { return m_pHealthComponent.GetComponent(); }
		SDK_INLINE SimObjectCharacterPropertiesComponent* GetSimObjectCharacterPropertiesComponent() { return m_pSimObjectCharacterPropertiesComponent.GetComponent(); }
		SDK_INLINE TargetingSystemPedBaseComponent* GetTargetingSystemBaseComponent() { return m_pTargetingSystemBaseComponent.GetComponent(); }
		SDK_INLINE void StopHeadTracking() { m_HeadTrackingTarget.m_Type = eHEAD_TRACK_TYPE_NONE; }

		/* Functions */

		void AddThreatTarget(SimObject* pTarget, f32 radius) { SDK_CALL_FUNC(void, 0x341190, void*, SimObject*, f32)(this, pTarget, radius); }
		bool CanWalkStraightToPoint(const qVector3& point, eConstrainToSidewalks constrain_to_sidewalks, qVector3* last_valid_point) {
			return SDK_CALL_FUNC(bool, 0x34CBF0, void*, const qVector3&, eConstrainToSidewalks, qVector3*)(this, point, constrain_to_sidewalks, last_valid_point);
		}
		void OnSiblingsChanged() { SDK_CALL_FUNC(void, 0x37BC00, void*)(this); }
		void SetCombatRegion(CombatRegion* pRegion) { SDK_CALL_FUNC(void, 0x3850F0, void*, CombatRegion*)(this, pRegion); }
		void SetGroupComponent(GroupComponent* value) { SDK_CALL_FUNC(void, 0x4166A0, void*, GroupComponent*)(this, value); }
		void SetHeadTrackingPosition(TransformNodeComponent* transform_node_component, const qVector3& offset) { 
			SDK_CALL_FUNC(void, 0x386600, void*, TransformNodeComponent*, const qVector3&)(this, transform_node_component, offset);
		}
		void SetHeadTrackingPosition(const qVector3& position) { SDK_CALL_FUNC(void, 0x3865A0, void*, const qVector3&)(this, position); }
	};
	SDK_ASSERT_SIZEOF(AIEntityComponent, 0x538);
}
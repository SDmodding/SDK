#pragma once

namespace UFG
{
	class SimObject : public qSafePointerNodeWithCallbacks<SimObject>
	{
	public:
		qNodeRB m_Node;
		qSymbol m_Name;
		uint16_t m_Flags;
		char m_ReservedComponentSlots;
		char m_ResolveRefCount;
		SceneObjectProperties* m_pSceneObj;
		CTransformNodeComponent* m_pTransformNodeComponent;
		qArray<SimComponentHolder> m_Components;
		qList<RebindingComponentHandle<SimComponent>> m_UnboundComponentHandles;

		// Virtual Functions

		UFG_INLINE ~SimObject()
		{
			UFG_VCall<0, void>(this);
		}

		UFG_INLINE void Attach(SimComponent* p_Component, uint32_t p_Index)
		{
			UFG_VCall<1, void, SimComponent*, uint32_t>(this, p_Component, p_Index);
		}

		UFG_INLINE void Detach(SimComponent* p_Component)
		{
			UFG_VCall<2, void, SimComponent*>(this, p_Component);
		}

		// SkookumScript

		UFG_INLINE bool IsReferencedByScripts()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x4E22D0))(this);
		}

		// Highlight

		UFG_INLINE bool IsHighlighted()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x6E680))(this);
		}

		UFG_INLINE void Highlight(qColour p_Colour, float p_OutlineStrength = 1.5f, float p_XrayStrength = 0.f, bool p_IsDepthEnabled = true)
		{
			struct HighlightParams_t
			{
				UFG::qColour mColour;
				float mOutlineStrength;
				float mXrayStrength;
				bool mIsDepthEnabled = 1;
			};
			HighlightParams_t m_HighlightParams;
			m_HighlightParams.mColour = p_Colour;
			m_HighlightParams.mOutlineStrength = p_OutlineStrength;
			m_HighlightParams.mXrayStrength = p_XrayStrength;
			m_HighlightParams.mIsDepthEnabled = p_IsDepthEnabled;

			reinterpret_cast<void(__fastcall*)(void*, HighlightParams_t*)>(UFG_RVA(0x6E560))(this, &m_HighlightParams);
		}

		UFG_INLINE void UnHighlight()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x6EE30))(this);
		}

		// Components

		UFG_INLINE SimComponent* GetComponentOfType(uint32_t p_TypeUID)
		{
			return reinterpret_cast<SimComponent*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x190AD0))(this, p_TypeUID);
		}

		template <typename T>
		UFG_INLINE T* GetComponentOfType(uint32_t p_TypeUID)
		{
			return reinterpret_cast<T*>(GetComponentOfType(p_TypeUID));
		}

		UFG_INLINE SimComponent* GetComponentOfTypeHK(uint32_t p_TypeUID)
		{
			return reinterpret_cast<SimComponent*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x52BBC0))(this, p_TypeUID);
		}

		template <typename T>
		UFG_INLINE T* GetComponentOfTypeHK(uint32_t p_TypeUID)
		{
			return reinterpret_cast<T*>(GetComponentOfTypeHK(p_TypeUID));
		}

		UFG_INLINE SimComponent* GetActor()
		{
			return GetComponentOfType<SimComponent>(SimTSActorComponent_TypeUID);
		}

		UFG_INLINE SimObjectPropertiesComponent* GetProperties()
		{
			return GetComponentOfType<SimObjectPropertiesComponent>(SimObjectProperties_TypeUID);
		}

		UFG_INLINE CCompositeDrawableComponent* GetCompositeDrawable()
		{
			return GetComponentOfType<CCompositeDrawableComponent>(SimObjectCompositeDrawable_TypeUID);
		}

		UFG_INLINE CFXSimComponent* GetFX()
		{
			return GetComponentOfType<CFXSimComponent>(SimObjectFXComponent_TypeUID);
		}

		UFG_INLINE CActionTreeComponent* GetActionTree()
		{
			return GetComponentOfType<CActionTreeComponent>(SimObjectActionTreeComponent_TypeUID);
		}

		UFG_INLINE CBaseAnimationComponent* GetBaseAnimation()
		{
			return GetComponentOfType<CBaseAnimationComponent>(SimObjectBaseAnimation_TypeUID);
		}

		UFG_INLINE CRigidBodyComponent* GetRigidBody()
		{
			return GetComponentOfType<CRigidBodyComponent>(SimObjectRigidbody_TypeUID);
		}

		// Functions

		UFG_INLINE bool TargetAttach(eTargetTypeEnum p_TargetType, SimObject* p_OverrideTarget, SimObject** p_OutSimObjectTarget, const qSymbol& p_AttachJoint, const qSymbol& p_TargetAttachJoint, float p_BlendInTime, bool p_AttachRelative, float p_AttachRelativeMaxDistance, bool p_AttachToTarget, bool p_AddToInventory, bool p_AssignTarget, eTargetTypeEnum p_AssignmentTargetType, bool p_LockTarget, bool p_PositionOnly, bool p_PositionXYOnly, bool* p_ManagePowerLevel)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, eTargetTypeEnum, SimObject*, SimObject**, const qSymbol&, const qSymbol&, float, bool, float, bool, bool, bool, eTargetTypeEnum, bool, bool, bool, bool*)>(UFG_RVA(0x553240))(this, p_TargetType, p_OverrideTarget, p_OutSimObjectTarget, p_AttachJoint, p_TargetAttachJoint, p_BlendInTime, p_AttachRelative, p_AttachRelativeMaxDistance, p_AttachToTarget, p_AddToInventory, p_AssignTarget, p_AssignmentTargetType, p_LockTarget, p_PositionOnly, p_PositionXYOnly, p_ManagePowerLevel);
		}

		UFG_INLINE bool TargetDetach(eTargetTypeEnum p_TargetType, SimObject* p_OverrideTarget, const qSymbol& p_AttachJoint, const qSymbol& p_TargetAttachJoint, float p_BlendOutTime, bool p_DetachFromTarget, bool p_RemoveFromInventory, bool p_DeleteOnDetach, bool p_ReleaseTarget, bool p_MakeUpright, bool p_FadeAwayOnDetach, float p_DisableCollisionDelay, float p_ClampVelocity, bool p_ManagePowerLevel)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, eTargetTypeEnum, SimObject*, const qSymbol&, const qSymbol&, float, bool, bool, bool, bool, bool, bool, float, float, bool)>(UFG_RVA(0x554F50))(this, p_TargetType, p_OverrideTarget, p_AttachJoint, p_TargetAttachJoint, p_BlendOutTime, p_DetachFromTarget, p_RemoveFromInventory, p_DeleteOnDetach, p_ReleaseTarget, p_MakeUpright, p_FadeAwayOnDetach, p_DisableCollisionDelay, p_ClampVelocity, p_ManagePowerLevel);
		}

		UFG_INLINE bool IsAttached()
		{
			CBaseAnimationComponent* _BaseAnimation = GetBaseAnimation();
			return (_BaseAnimation && _BaseAnimation->mCreature && _BaseAnimation->mCreature->mIsAttached);
		}

		UFG_INLINE void Restore()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1911F0))(this);
		}

		UFG_INLINE void Suspend()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1916D0))(this);
		}

		UFG_INLINE void Destroy()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1905C0))(this);
		}
	}; typedef SimObject CSimObject;
	UFG_ASSERT_CLASS(SimObject, 0x80);
}
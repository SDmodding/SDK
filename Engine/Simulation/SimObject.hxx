#pragma once

namespace UFG
{
	class CSimObject : public qSafePointerNodeWithCallbacks<CSimObject>
	{
	public:
		qNodeRB m_Node;
		qSymbol m_Name;
		uint16_t m_Flags;
		char m_ReservedComponentSlots;
		char m_ResolveRefCount;
		CSceneObjectProperties* m_pSceneObj;
		CTransformNodeComponent* m_pTransformNodeComponent;
		qArray<CSimComponentHolder> m_Components;
		qList<RebindingComponentHandle<CSimComponent>> m_UnboundComponentHandles;

		// Virtual Functions

		UFG_INLINE ~CSimObject() 
		{
			UFG_VCall<0, void>(this);
		}

		UFG_INLINE void Attach(CSimComponent* p_Component, uint32_t p_Index)
		{
			UFG_VCall<1, void, CSimComponent*, uint32_t>(this, p_Component, p_Index);
		}

		UFG_INLINE void Detach(CSimComponent* p_Component) 
		{
			UFG_VCall<2, void, CSimComponent*>(this, p_Component);
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

		UFG_INLINE CSimComponent* GetComponentOfType(uint32_t p_TypeUID)
		{
			return reinterpret_cast<CSimComponent * (__fastcall*)(void*, uint32_t)>(UFG_RVA(0x190AD0))(this, p_TypeUID);
		}

		template <typename T>
		UFG_INLINE T* GetComponentOfType(uint32_t p_TypeUID)
		{
			return reinterpret_cast<T*>(GetComponentOfType(p_TypeUID));
		}

		UFG_INLINE CSimComponent* GetComponentOfTypeHK(uint32_t p_TypeUID)
		{
			return reinterpret_cast<CSimComponent * (__fastcall*)(void*, uint32_t)>(UFG_RVA(0x52BBC0))(this, p_TypeUID);
		}

		template <typename T>
		UFG_INLINE T* GetComponentOfTypeHK(uint32_t p_TypeUID)
		{
			return reinterpret_cast<T*>(GetComponentOfTypeHK(p_TypeUID));
		}

		UFG_INLINE CSimComponent* GetActor()
		{
			return GetComponentOfType<CSimComponent>(SimTSActorComponent_TypeUID);
		}

		UFG_INLINE CSimObjectPropertiesComponent* GetProperties()
		{
			return GetComponentOfType<CSimObjectPropertiesComponent>(SimObjectProperties_TypeUID);
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

		UFG_INLINE bool TargetAttach(eTargetTypeEnum targetType, CSimObject* pOverrideTarget, CSimObject** ppOutSimObjectTarget, qSymbol attachJoint, qSymbol targetAttachJoint, float blendInTime, bool attachRelative, float attachRelativeMaxDistance, bool attachToTarget, bool addToInventory, bool assignTarget, eTargetTypeEnum assignmentTargetType, bool lockTarget, bool positionOnly, bool positionXYOnly, bool* managePowerLevel)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, eTargetTypeEnum, CSimObject*, CSimObject**, qSymbol*, qSymbol*, float, bool, float, bool, bool, bool, eTargetTypeEnum, bool, bool, bool, bool*)>(UFG_RVA(0x553240))(this, targetType, pOverrideTarget, ppOutSimObjectTarget, &attachJoint, &targetAttachJoint, blendInTime, attachRelative, attachRelativeMaxDistance, attachToTarget, addToInventory, assignTarget, assignmentTargetType, lockTarget, positionOnly, positionXYOnly, managePowerLevel);
		}

		UFG_INLINE bool TargetDetach(eTargetTypeEnum targetType, CSimObject* pOverrideTarget, qSymbol attachJoint, qSymbol targetAttachJoint, float blendOutTime, bool detachFromTarget, bool removeFromInventory, bool deleteOnDetach, bool releaseTarget, bool makeUpright, bool fadeAwayOnDetach, float disableCollisionDelay, float clampVelocity, bool managePowerLevel)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, eTargetTypeEnum, CSimObject*, qSymbol*, qSymbol*, float, bool, bool, bool, bool, bool, bool, float, float, bool)>(UFG_RVA(0x554F50))(this, targetType, pOverrideTarget, &attachJoint, &targetAttachJoint, blendOutTime, detachFromTarget, removeFromInventory, deleteOnDetach, releaseTarget, makeUpright, fadeAwayOnDetach, disableCollisionDelay, clampVelocity, managePowerLevel);
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
	};
	UFG_ASSERT_CLASS(CSimObject, 0x80);
}
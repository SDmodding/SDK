#pragma once

namespace UFG
{
	//...
	class CSceneObjectProperties;
	class CSimObject;
	class CSimCharacter;
	class CSimVehicle;

	class CTargetingSimObject
	{
	public:
		qNode<CTargetingSimObject> mNode;
		void* m_pTSBC; // TargetingSystemBaseComponent
		qSafePointer<CSimObject> m_pTarget;
		uint8_t m_eTargetType;
		bool m_bLock;
	};

	// Components
	class CSimComponent
	{
	public:
		void* vfptr;
		UFG_PAD(0x10);

		unsigned int m_TypeUID;
		unsigned int m_NameUID;
		unsigned short m_Flags;
		short m_SimObjIndex;
		CSimObject* m_pSimObject;

		char m_BoundComponentHandles[0x10];

		~CSimComponent() { UFG_VCall<0, void>(this); }
		const char* GetDebugTypeName() { return UFG_VCall<4, const char*>(this); }
		void OnAttach(UFG::CSimObject* p_SimObject) { UFG_VCall<6, void, UFG::CSimObject*>(this, p_SimObject); }
		void Suspend() { UFG_VCall<8, void>(this); }
		void Restore() { UFG_VCall<9, void>(this); }
		void OnDetach() { UFG_VCall<10, void>(this); }
	};

	class CActionTreeComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x68);

		bool mNisUpdated;
		const char* mActionTreeFileName;
		CActionContext* mpActionContext;
		CActionController mActionController;

		void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x58B060))(this);
		}
	};

	class CCompositeDrawableComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x28);

		void* mCompositeLook;
		Illusion::CMaterialModifierParams mMaterialModifier;

		bool IsCharacter()
		{
			if (mCompositeLook && *reinterpret_cast<uintptr_t*>(mCompositeLook) == UFG_RVA(0x17C3748))
				return true;

			return false;
		}

		bool IsVehicle()
		{
			if (mCompositeLook && *reinterpret_cast<uintptr_t*>(mCompositeLook) == UFG_RVA(0x17C3668))
				return true;

			return false;
		}

		void SetHidden(bool m_Hidden)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x4000))(this, m_Hidden);
		}
	};

	class CPowerManagementComponent : public CSimComponent
	{
	public:
		void PreventSuspendTemporarily(float p_Time)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x588930))(this, p_Time);
		}
	};

	class CStreamedResourceComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x4C8);

		bool mPartsBound;
		bool mFirstResourceLoad;
		qColour mColourTints[16];
		qSymbol mActivePriority;
		qPropertySet* mPropertySet;
		uint32_t mSpawnPriorityReferenceCount[4];
		float mCameraDistance;
		eSimObjectTypeEnum mSimObjectType;

		void Constructor(CSceneObjectProperties* m_SceneObject)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSceneObjectProperties*)>(UFG_RVA(0x4373B0))(this, m_SceneObject);
		}

		void Destructor()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x438000))(this);
		}

		void UnbindAllModels(CCompositeDrawableComponent* m_CompositeDrawable)
		{
			reinterpret_cast<void(__fastcall*)(void*, CCompositeDrawableComponent*)>(UFG_RVA(0x4440F0))(this, m_CompositeDrawable);
		}

		void BindAllModels(CCompositeDrawableComponent* m_CompositeDrawable, bool m_UsingTempRig = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, CCompositeDrawableComponent*, bool)>(UFG_RVA(0x438DD0))(this, m_CompositeDrawable, m_UsingTempRig);
		}

		void Update(float m_Seconds, qVector3* m_StreamPosition)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, qVector3*)>(UFG_RVA(0x444D00))(this, m_Seconds, m_StreamPosition);
		}

		void UpdateLoadState(CSimObject* m_Object)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x446130))(this, m_Object);
		}

		void IncrementPriorityReferenceCount(qSymbol m_Priority)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x43DF90))(this, &m_Priority);
		}

		bool IsLoadActive()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x43F160))(this);
		}

		bool AreResourcesLoaded()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x438CC0))(this);
		}
	};

	class CSimObjectPropertiesComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		eSimObjectTypeEnum m_eSimObjectType;

		UFG_PAD(0x4);

		void* m_pSubTargetingProfile;
		unsigned char m_BitField[8];

		UFG_PAD(0x30);
	};

	class CTransformNodeComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		void* mChildren[2];
		unsigned int mChangeID;
		CTransformNodeComponent* mParent;
		int mChanged;

		UFG_PAD(0xC);

		qMatrix44 mWorldTransform;
		qMatrix44 mLocalTransform;
		qVector3 mWorldVelocity;
		int mInheritXformType;

		static const char* GetName()
		{
			return reinterpret_cast<const char*>(UFG_RVA(0x16B0BD0));
		}

		static CTransformNodeComponent* Create(uint32_t p_UID = 0, CTransformNodeComponent* p_Parent = nullptr, bool p_StartSuspended = false)
		{
			CTransformNodeComponent* m_NewTransformComponent = reinterpret_cast<CTransformNodeComponent*>(MemoryPool::GetSimulationPool()->Allocate(sizeof(CTransformNodeComponent), GetName(), 0, 1));
			if (m_NewTransformComponent)
				m_NewTransformComponent->Constructor(p_UID, p_Parent, p_StartSuspended);

			return m_NewTransformComponent;
		}

		void Constructor(uint32_t p_UID, CTransformNodeComponent* p_Parent, bool p_StartSuspended)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, CTransformNodeComponent*, bool)>(UFG_RVA(0x18F1E0))(this, p_UID, p_Parent, p_StartSuspended);
		}

		void Destructor()
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x18FF10))(this, true);
		}

		void SetWorldTranslation(qVector3 p_Position)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*)>(UFG_RVA(0x191520))(this, &p_Position);
		}

		void SetLocalTransform(qMatrix44* p_Matrix)
		{
			reinterpret_cast<void(__fastcall*)(void*, qMatrix44*)>(UFG_RVA(0x191250))(this, p_Matrix);
		}

		void UpdateWorldTransform()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x191D60))(this);
		}
	};

	class CBaseAnimationComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x58);

		CCreature* mCreature;

		void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x58B220))(this);
		}

		void UnbindRequiredAnimationBanks()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x58D300))(this);
		}

		void BindRequiredAnimBanks(CSceneObjectProperties* m_SceneObj, uintptr_t m_DataPtr)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSceneObjectProperties*, uintptr_t)>(UFG_RVA(0x591CA0))(this, m_SceneObj, m_DataPtr);
		}

		void InitPropertySetInfo(CSceneObjectProperties* m_SceneObj, uintptr_t m_DataPtr)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSceneObjectProperties*, uintptr_t)>(UFG_RVA(0x583870))(this, m_SceneObj, m_DataPtr);
		}

		void Update(float m_DeltaSec)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x58D4F0))(this, m_DeltaSec);
		}

		void UpdateNIS(float m_DeltaSec)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x5909E0))(this, m_DeltaSec);
		}
	};

	class CRigidBodyComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x68);

		hkpRigidBody* mBody;

		UFG_PAD(0x58);
		/*UFG::WaterFloatingTrackerBaseComponent* mWaterFloatingTrackerComponent;
		UFG::RebindingComponentHandle<UFG::TransformNodeComponent, 0> mRootTransformComponent;
		UFG::WindAction* mWindAction;
		BitArray256* mFractureState;
		UFG::qArray<UFG::qSafePointer<UFG::Constraint, UFG::Constraint>, 0> mConstraints;*/

		unsigned int mFlags;

		void ApplyForce(qVector3* force, qVector3* point)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, qVector3*, qVector3*)>(UFG_RVA(0xA0EA0))(this, 0.f, force, point);
		}

		void ApplyLinearImpulse(qVector3* impulse, qVector3* point)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, qVector3*)>(UFG_RVA(0xA1000))(this, impulse, point);
		}

		void ApplyAngularImpulse(qVector3* vel)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*)>(UFG_RVA(0xA0BC0))(this, vel);
		}

		void SetMotionType(unsigned int mode)
		{
			reinterpret_cast<void(__fastcall*)(void*, unsigned int)>(UFG_RVA(0xB1500))(this, mode);
		}

		void SetVelocity(UFG::qVector3* vel)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::qVector3*)>(UFG_RVA(0xB2850))(this, vel);
		}

		void GetVelocity(UFG::qVector3* result)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::qVector3*)>(UFG_RVA(0xAB970))(this, result);
		}

		// NotifyProxyModeChanged
		void EnablePhysics(bool m_Enable)
		{
			reinterpret_cast<void(__fastcall*)(void*, int)>(UFG_RVA(0x46D870))(this, m_Enable ? 0 : 2);
		}

		float GetMass()
		{
			return reinterpret_cast<float(__fastcall*)(void*)>(UFG_RVA(0xAA990))(this);
		}

		void SetMass(float m)
		{
			if (mBody)
				reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0xD62710))(mBody, m);
		}
	};

	class CFXSimComponent : CSimComponent
	{
	public:
		qSymbol AttachEffect(qSymbol effectId, int jointID, qMatrix44* offset = nullptr, void* overrideObject = nullptr)
		{
			return reinterpret_cast<qSymbol(__fastcall*)(void*, qSymbol, int, qMatrix44*, void*)>(UFG_RVA(0x1C78F0))(this, effectId, jointID, offset, overrideObject);
		}

		void DetachEffect(qSymbol fxId, uint32_t killOption = 0x0)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol, uint32_t)>(UFG_RVA(0x1CB150))(this, fxId, killOption);
		}
	};

	class CTargetingSystemBaseComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x18);

		CTargetingSimObject* m_pTargets;

		struct TargetingMap_t
		{
			uint32_t m_uNumValidTargetTypes;
			qFixedArray<uint8_t, 91> m_Map;
		};
		TargetingMap_t* m_pTargetingMap;
		qList<CTargetingSimObject> m_TargetedBy;

		CTargetingSimObject* GetTarget(eTargetTypeEnum m_TargetType)
		{
			return &m_pTargets[m_pTargetingMap->m_Map.p[m_TargetType]];
		}

		void SetTarget(eTargetTypeEnum m_TargetType, CSimObject* m_SimObject)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, CSimObject*)>(UFG_RVA(0x54ED20))(this, m_TargetType, m_SimObject);
		}

		void ClearTarget(eTargetTypeEnum m_TargetType)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum)>(UFG_RVA(0x15DFB0))(this, m_TargetType);
		}
	};
}
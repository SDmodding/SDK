#pragma once

namespace UFG
{
	// Classes
	class SceneObjectProperties;
	class SimObject;
	class SimCharacter;
	class SimVehicle;

	class BasePhysicsObject
	{
	public:
		void* vfptr;
		bool mIsBoat;
		qSafePointer<SimComponent> mSimComponent;
	}; typedef BasePhysicsObject CBasePhysicsObject;

	// Components
	class CompositeDrawableComponent : public SimComponent
	{
	public:
		UFG_PAD(0x28);

		void* mCompositeLook;
		Illusion::CMaterialModifierParams mMaterialModifier;
		Illusion::CB_SceneryInstance mSceneryInstance;
		bool mIsHidden;
		void* mCullLayer;
		void* mCullResults;
		void* mCullInfo;
		__declspec(align(16)) qMatrix44 mPoseRootMatrix;
		CSkeletalPose* mPose;
		CRigHandle mRigHandle;
		uint32_t mNumModelTypeLODs;
		CModelType* mModelType[5];
		float mLODBiasMult;
		float mDrawScale;
		bool mHasSoftBody;
		bool mUsePersistentSkinningCache;
		qArray<void*> mActiveMultiMorphTargets;

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
	}; typedef CompositeDrawableComponent CCompositeDrawableComponent;

	class DynamicSceneryInstance
	{
	public:
		UFG_PAD(0x18);

		SimComponent mSimComponent;
		qNode<DynamicSceneryInstance> mNode;
		int16_t mHidden;
		int16_t mForceTransparencyState;

		UFG_PAD_ALIGN(0x4);

		void* mCullInfo;
		void* mCullResults;
		char mTransparencyState[3];

		UFG_PAD_ALIGN(0x5);
		UFG_PAD(0x28);
		//Illusion::ModelHandle mModelHandle;

		qMatrix44 mLocalWorld;
		float mSelfIlluminationOverride;
		uint32_t mNameUID;
		uint32_t mTagUID;

		UFG_PAD_ALIGN(0x4);

		void UpdateCullInfo()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x2357E0))(this);
		}
	}; typedef DynamicSceneryInstance CDynamicSceneryInstance;

	class PowerManagementComponent : public SimComponent
	{
	public:
		void PreventSuspendTemporarily(float p_Time)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x588930))(this, p_Time);
		}
	}; typedef PowerManagementComponent CPowerManagementComponent;

	class PhysicsRenderHelper : public SimComponent
	{
	public:
		qNode<PhysicsRenderHelper> mNode;
		uint16_t mNumSceneryInstances;
		DynamicSceneryInstance** mSceneryInstances;
		uint32_t mFlags;
	}; typedef PhysicsRenderHelper CPhysicsRenderHelper;

	class TransformNodeComponent : public SimComponent
	{
	public:
		UFG_PAD(0x10);

		void* mChildren[2];
		unsigned int mChangeID;
		TransformNodeComponent* mParent;
		int mChanged;

		UFG_PAD(0xC);

		qMatrix44 mWorldTransform;
		qMatrix44 mLocalTransform;
		qVector3 mWorldVelocity;
		int mInheritXformType;

		UFG_STATIC_INLINE const char* GetName()
		{
			return reinterpret_cast<const char*>(UFG_RVA(0x16B0BD0));
		}

		UFG_STATIC_INLINE TransformNodeComponent* Create(uint32_t p_UID = 0, TransformNodeComponent* p_Parent = nullptr, bool p_StartSuspended = false)
		{
			auto pComponent = reinterpret_cast<TransformNodeComponent*>(MemoryPool::GetSimulationPool()->Allocate(sizeof(TransformNodeComponent), GetName(), 0, 1));
			if (pComponent) {
				pComponent->Constructor(p_UID, p_Parent, p_StartSuspended);
			}

			return pComponent;
		}

		void Constructor(uint32_t p_UID, TransformNodeComponent* p_Parent, bool p_StartSuspended)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, TransformNodeComponent*, bool)>(UFG_RVA(0x18F1E0))(this, p_UID, p_Parent, p_StartSuspended);
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
	}; typedef TransformNodeComponent CTransformNodeComponent;

	class BaseAnimationComponent : public SimComponent
	{
	public:
		UFG_PAD(0x58);

		CCreature* mCreature;
		bool mUpdatedWithResources;
		bool mUpdatedFromNIS;
		bool mTransformsUpdated;

		UFG_PAD(0x18);
		//AnimationGroupHandleContainer mRequiredAnimationBanks;

		bool mDestroyAttachedCharacters;
		bool mTemporaryRig;
		uint32_t mCurrentRigUID;

		void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x58B220))(this);
		}

		void UnbindRequiredAnimationBanks()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x58D300))(this);
		}

		void BindRequiredAnimBanks(SceneObjectProperties* m_SceneObj, uintptr_t m_DataPtr)
		{
			reinterpret_cast<void(__fastcall*)(void*, SceneObjectProperties*, uintptr_t)>(UFG_RVA(0x591CA0))(this, m_SceneObj, m_DataPtr);
		}

		void InitPropertySetInfo(SceneObjectProperties* m_SceneObj, uintptr_t m_DataPtr)
		{
			reinterpret_cast<void(__fastcall*)(void*, SceneObjectProperties*, uintptr_t)>(UFG_RVA(0x583870))(this, m_SceneObj, m_DataPtr);
		}

		void Update(float m_DeltaSec)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x58D4F0))(this, m_DeltaSec);
		}

		void UpdateNIS(float m_DeltaSec)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x5909E0))(this, m_DeltaSec);
		}
	}; typedef BaseAnimationComponent CBaseAnimationComponent;

	class RigidBody : public SimComponent, public BasePhysicsObject
	{
	public:
		CPhysicsResourceHandle mCollisionMeshBundle;
		CollisionInstanceData* mInstanceData;
		CollisionMeshData* mCollisionMeshData;
		hkpRigidBody* mBody;
		class CWaterFloatingTrackerBaseComponent* mWaterFloatingTrackerComponent;
		RebindingComponentHandle<TransformNodeComponent> mRootTransformComponent;
		class CWindAction* mWindAction;
		struct BitArray256* mFractureState;
		qArray<qSafePointer<class CConstraint>> mConstraints;

		enum Flags : uint32_t
		{
			ACTIVE_REGION_MGT = 0x1,
			INFLATED = 0x2,
			SPAWNED_FROM_STREAMED_GEO = 0x4,
			RESOURCE_UNLOADED = 0x8,
			JUST_SPAWNED = 0x10,
			JUST_FRACTURED = 0x20,
			MODE_FIXED = 0x40,
			MODE_SIMULATED = 0x80,
			MODE_ANIMATED_HARDKEYFRAME = 0x100,
			MODE_ANIMATED_SOFTKEYFRAME = 0x200,
			MODEL_ASSET_BODY = 0x400,
		};
		Flags mFlags;
		uint32_t mCollisionLayerOverride;
		int mCollisionSystem;
	}; typedef RigidBody CRigidBody;

	class RigidBodyComponent : public RigidBody
	{
	public:
		qNode<RigidBodyComponent> mNode;
		qSafePointer<class CParkourComponent> mParkourComponent;
		qSafePointer<class DynamicCoverComponent> mCoverComponent;
		qSafePointer<class PhysicsRenderHelper> mRenderComponent;
		qSafePointer<class CStateMachineComponent> mStateMachineComponent;
		RebindingComponentHandle<class CCharacterAnimationComponent> mAnimationComponent;
		int16_t mFollowBoneIndex;
		class CStateMachineDefinition *mRuntimeStateMachineDefinition;
		float mLifeSpan;
		float mTimeSinceAddedToWorld;
		uint32_t mStoredCollisionFilter;

		UFG_INLINE void ApplyForce(float p_TimeDelta, const qVector3& p_Force, const qVector3& p_Point)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, const qVector3&, const qVector3&)>(UFG_RVA(0xA0EA0))(this, p_TimeDelta, p_Force, p_Point);
		}

		UFG_INLINE void ApplyLinearImpulse(const qVector3& p_Impulse, const qVector3& p_Point)
		{
			reinterpret_cast<void(__fastcall*)(void*, const qVector3&, const qVector3&)>(UFG_RVA(0xA1000))(this, p_Impulse, p_Point);
		}

		UFG_INLINE void ApplyAngularImpulse(const qVector3& p_Impulse)
		{
			reinterpret_cast<void(__fastcall*)(void*, const qVector3&)>(UFG_RVA(0xA0BC0))(this, p_Impulse);
		}

		UFG_INLINE void SetMotionType(uint32_t p_Mode)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t)>(UFG_RVA(0xB1500))(this, p_Mode);
		}

		UFG_INLINE void SetVelocity(const qVector3& p_Velocity)
		{
			reinterpret_cast<void(__fastcall*)(void*, const qVector3&)>(UFG_RVA(0xB2850))(this, p_Velocity);
		}

		UFG_INLINE void GetVelocity(qVector3* p_Result)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*)>(UFG_RVA(0xAB970))(this, p_Result);
		}

		// NotifyProxyModeChanged
		UFG_INLINE void EnablePhysics(bool p_Enable)
		{
			reinterpret_cast<void(__fastcall*)(void*, int)>(UFG_RVA(0x46D870))(this, p_Enable ? 0 : 2);
		}

		UFG_INLINE float GetMass()
		{
			return reinterpret_cast<float(__fastcall*)(void*)>(UFG_RVA(0xAA990))(this);
		}

		UFG_INLINE void SetMass(float p_Mass)
		{
			if (mBody) {
				reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0xD62710))(mBody, p_Mass);
			}
		}

		// This actually adds the Rigidbody to hkpWorld...
		UFG_INLINE void Inflate(bool p_AddToWorld)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x468BD0))(this, p_AddToWorld);
		}

		// Calling this without having 'INFLATED' flag can cause game to crash!
		UFG_INLINE void Deflate()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xA68C0))(this);
		}

		UFG_INLINE void DeflateSafe()
		{
			if (mFlags & INFLATED) {
				Deflate();
			}
		}
	}; typedef RigidBodyComponent CRigidBodyComponent;

	class FXSimComponent : SimComponent
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
	}; typedef FXSimComponent CFXSimComponent;

	class WaterPhantomComponent : public SimComponent
	{
	public:
		UFG_PAD(0x68);
		/*
		* UFG::BasePhysicsObject
		* UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent>
		* UFG::PhysicsResourceHandle mCollisionMeshBundle;
		*/

		hkpShapePhantom* mPhantom;

		UFG_PAD(0x220);
		// hkpAllCdBodyPairCollector mCollector;

		float mElevation;
		uint32_t mIsVolume : 1;
	}; typedef WaterPhantomComponent CWaterPhantomComponent;
}
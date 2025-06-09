#pragma once

namespace UFG
{
	class AttachedEffect : public qNode<AttachedEffect>
	{
	public:
		qMatrix44 mBodyTransform;
		qSafePointer<SimComponent, TransformNodeComponent> mTransformNode;
		StateMachineEffectNode* mEffectNode;
		StateMachineEffectNode* mRuntimeEffectNode;
		u32 mInstanceUid;

		virtual ~AttachedEffect() = 0;
	};

	class StateMachineComponent : public SimComponent, public qNode<StateMachineComponent>
	{
	public:
		enum { _TypeUID = 0x86000001 };

		enum DamageType
		{
			IMPACT_DAMAGE,
			BULLET_DAMAGE,
			EXPLOSION_DAMAGE,
			ATTACK_DAMAGE,
			ABSOLUTE_DAMAGE,
			SET_DAMAGE_HEALTH,
			NUM_DAMAGE_TYPES
		};

		struct FractureInfo : qNode<FractureInfo>
		{
			u32 m3DSMaxNodeGuid;
		};

		f32 mCollisionEventData[4];
		qSafePointer<SimComponent, RigidBodyComponent> mRigidBodyComponent;
		qReflectHandle<StateMachineDefinition> mStateMachineDefinition;
		qList<FractureInfo> mFractureList;
		qList<AttachedEffect> mAttachedEffects;
		qSafePointer<SimObject, SimObject> mLastDamageSource;
		qArray<StateMachineComponent*, 0> mChildMachines;
		hkpRigidBody* mPhantomRigidBody;
		qVector4 mThrusterForce;
		f32 mThrusterDuration;
		f32 mPhantomTimer;
		f32 mTimer;
		f32 mHealth;
		f32 mPrevHealthBeforeRunningStateMachine;
		int mSubPartIndex;
		int mCurrentNodeIndex;
		u32 mFlags;

		/* Static Members */

		SDK_VINLINE qGlobalVar<qList<StateMachineComponent>*, 0x2081A48> s_StateMachineComponentList;

		/* Impl Functions */

		SDK_INLINE f32 GetDamage() { return 1.f - mHealth; }

		/* Functions */

		void AddChildMachine(StateMachineComponent* smc) { SDK_CALL_FUNC(void, 0x454C90, void*, StateMachineComponent*)(this, smc); }
		void ApplyDamage(f32 damage, DamageType type, SimObject* source) { SDK_CALL_FUNC(void, 0x4570D0, void*, f32, DamageType, SimObject*)(this, damage, type, source); }
		void ApplyImpactEffect(const qMatrix44& mat) { SDK_CALL_FUNC(void, 0x458220, void*, const qMatrix44&)(this, mat); }
		void ApplyImpactEffect(const qVector3& position, const qVector3& normal) { SDK_CALL_FUNC(void, 0x458360, void*, const qVector3&, const qVector3&)(this, position, normal); }

		AttachedEffect* CreateEffect(const StateMachineEffectNode& effect, const qMatrix44& partOffset) {
			return SDK_CALL_FUNC(AttachedEffect*, 0x45C820, void*, const StateMachineEffectNode&, const qMatrix44&)(this, effect, partOffset);
		}

		void DeleteChildMachine(int subPartIndex) { SDK_CALL_FUNC(void, 0x460B90, void*, int)(this, subPartIndex); }
		bool DoStateTransition(int nodeToTransitionInto) { return SDK_CALL_FUNC(bool, 0x462090, void*, int)(this, nodeToTransitionInto); }
		void FractureNotification(u32 maxNodeGuid3DS) { SDK_CALL_FUNC(void, 0x465510, void*, u32)(this, maxNodeGuid3DS); }
		bool IsElementInFractureList(u32 elementID) { return SDK_CALL_FUNC(bool, 0x46AE90, void*, u32)(this, elementID); }
		void KillEffects() { SDK_CALL_FUNC(void, 0x46B550, void*)(this); }
		void SetDamage(f32 damage) { SDK_CALL_FUNC(void, 0x474A70, void*, f32)(this, damage); }

		void SpawnDestructionPhantomVolume(u32 phantomUID, const qVector3& offset, const qVector3& extents) {
			SDK_CALL_FUNC(void, 0x475FD0, void*, u32, const qVector3&, const qVector3&)(this, phantomUID, offset, extents);
		}

		bool Update(const qMatrix44& mat, f32 deltaTime) { return SDK_CALL_FUNC(bool, 0x47D500, void*, const qMatrix44&, f32)(this, mat, deltaTime); }
		void UpdateAttachedEffects(const qMatrix44& mat) { SDK_CALL_FUNC(void, 0x47E0E0, void*, const qMatrix44&)(this, mat); }
	};
}
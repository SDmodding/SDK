#pragma once

namespace UFG
{
	class CharacterEffectsComponent : public SimComponent, public qNode<CharacterEffectsComponent>
	{
	public:
		enum { _TypeUID = 0xBE000001 };

		enum Foot
		{
			Foot_Left,
			Foot_Right,
			Foot_Num
		};

		enum Node
		{
			Node_WaterFootstepLeft,
			Node_WaterFootstepRight,
			Node_Num
		};

		class PhysVolumeRef : public qNodeRB<PhysVolumeRef>
		{
		public:
			bool mActive;
			bool mForceInactive;
			f32 mTimeInVolume;
			f32 mTimeOutVolume;
			PhysicsVolumeProperties* mPhysVolume;
			bool mPhysVolume_HitRecordPlayed;
		};

		bool InvulnerableToFire;
		bool ShowHealthBar;
		TransformNodeComponent* mNodes[2];
		RebindingComponentHandle<CharacterAnimationComponent> mCharacterAnimationComponent;
		RebindingComponentHandle<CharacterPhysicsComponent> mCharacterPhysicsComponent;
		RebindingComponentHandle<PhantomVolumeComponent> mPhantomVolumeComponent;
		qSymbolUC mWalkingThroughWaterEffect;
		f32 mWalkingThroughWaterMinSpeedForEffectSqr;
		f32 mMaxWaterDepthForWalkingThroughWaterEffect;
		qTreeRB<PhysVolumeRef> mPhysVolumeRefs;
		u32 mActiveVolumeUID[5];
		u32 mActiveSurfaceUID;
		u32 mActiveWetSurfaceUID;
		bool mIsOnFire;
		u32 mFireEffectID[3];
		bool mIsSmoldering;
		u32 mSmolderEffectID[3];
		f32 mFireExtinguishTime;
		f32 mSmolderExtinguishTime;
		f32 mQueuedHealthDamage;
		hkpRigidBody* mPhantomRigidBody;
		bool mIsAttachedToPlayer;
		u32 mFootstepOverride[2];
		u32 mUIElementIndex;
		bool mIsEliteFighter;

		/* Static Functions */

		SDK_SINLINE CharacterEffectsComponent* PropertiesOnActivateNew(SceneObjectProperties* sceneObject, bool required = 1) {
			return SDK_CALL_FUNC(CharacterEffectsComponent*, 0x545FD0, SceneObjectProperties*, bool)(sceneObject, required);
		}

		/* Impl Functions */

		SDK_INLINE void SetFootstepOverride(u32 leftFootEffectID, u32 rightFootEffectID) { mFootstepOverride[0] = leftFootEffectID; mFootstepOverride[1] = rightFootEffectID; }

		/* Functions */

		void CreateNodes() { SDK_CALL_FUNC(void, 0x524970, void*)(this); }
		void ExtinguishFire() { SDK_CALL_FUNC(void, 0x527A20, void*)(this); }
		void ExtinguishSmolder() { SDK_CALL_FUNC(void, 0x527B20, void*)(this); }
		void ForceIgniteFire() { SDK_CALL_FUNC(void, 0x52A2B0, void*)(this); }
		void HandleFootstep(Foot foot) { SDK_CALL_FUNC(void, 0x533E90, void*, Foot)(this, foot); }

		void HandleWaterCollision(const qMatrix44& mat, const qVector3& characterVelocity) {
			SDK_CALL_FUNC(void, 0x535140, void*, const qMatrix44&, const qVector3&)(this, mat, characterVelocity);
		}

		void IgniteFire() { SDK_CALL_FUNC(void, 0x535AD0, void*)(this); }
		void IgniteSmolder() { SDK_CALL_FUNC(void, 0x535D70, void*)(this); }
		void Update(f32 delta_sec) { SDK_CALL_FUNC(void, 0x559AF0, void*, f32)(this, delta_sec); }
	};
	SDK_ASSERT_SIZEOF(CharacterEffectsComponent, 0x1B8);
}
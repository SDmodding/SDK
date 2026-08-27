#pragma once

namespace UFG
{
	enum eProjectileReactionEnum
	{
		ePROJECTILE_REACTION_INVALID,
		ePROJECTILE_REACTION_LIGHT,
		ePROJECTILE_REACTION_HEAVY,
		ePROJECTILE_REACTION_SNIPER,
		NUM_PROJECTILE_REACTIONS
	};

	enum eSimObjectWeaponBooleanEnum
	{
		eSIM_OBJ_WEAPON_BOOL_IS_RANGED,
		eSIM_OBJ_WEAPON_BOOL_IS_MELEE,
		eSIM_OBJ_WEAPON_BOOL_USES_AMMO,
		eSIM_OBJ_WEAPON_BOOL_IS_THROWN,
		eSIM_OBJ_WEAPON_BOOL_IS_TWO_HANDED,
		eSIM_OBJ_WEAPON_BOOL_IS_BLADED,
		NUM_SIM_OBJECT_WEAPON_BOOLEANS
	};
}

namespace UFG
{
	class FireModeInfo
	{
	public:
		u32 mSimObjectWeaponType;
		eInventoryItemEnum mAmmoInventoryItem;
		int mAmmoClipCapacity;
		int mAmmoTotalCapacity;
		f32 mRateOfFire;
		f32 mHardLockReticleSizeMin;
		f32 mHardLockReticleSizeMax;
		f32 mReticleSizeMin;
		f32 mReticleSizeMax;
		f32 mReticleSizeBlindfire;
		f32 mRangedDistance;
		f32 mAngularInaccuracyRadMin;
		f32 mAngularInaccuracyRadMax;
		f32 mProjectileSpeed;
		f32 mProjectileSpeedAI;
		f32 mProjectileGravity;
		f32 mArmingDistance;
		f32 mSlowModeRateOfFireMultiplier;
		f32 mSlowModeRateOfFireMultiplierAI;
		f32 mSlowModeProjectileSpeedMultiplier;
		f32 mSlowModeProjectileSpeedMultiplierAI;
		f32 mSlowModeProjectileDamageMultiplier;
		f32 mSlowModeProjectileDamageMultiplierAI;
		f32 mProjectilePhysicsImpulse;
		f32 mThrownSpeed;
		qSymbolUC mProjectileSpawnBoneName;
		u32 mProjectileSpawnBoneID;
		qSymbol mExplosionType;
		f32 mBulletLifeSpan;
		bool mIsTwoHandedWeapon;
		bool mIsAutomatic;
		bool mStowable;
		bool mHasSniperScope;
		u32 mBulletTypeID;
		u32 mBulletEffectID;
		u32 mBulletPerShot;
		f32 mHardLockDamageMultiplier;
		f32 mDamageMultiplier;
		f32 mDamage;
		f32 mPropDamage;
		f32 mVehicleDamage;
		eProjectileReactionEnum mProjectileReaction;
		f32 mFlickTargetingAngularLimitRad;
		f32 mAccuracyOnTargetChanged;
		f32 mAccuracyPenaltyPerShot;
		f32 m_fAccuracyRateMultiplier;
		qVector3 mMinAngularVelocityWhenThrown;
		qVector3 mMaxAngularVelocityWhenThrown;
		u32 mStartingMaxAmmoCount;
		u32 mStartingMinAmmoCount;
		u32 mAIOnDeathDropMaxAmmoCount;
		u32 mAIOnDeathDropMinAmmoCount;
		Render::BeamSettingsHandle* mTracerBeamSettingsHandle;
		Render::BeamSettingsHandle* mTracerBeamAISettingsHandle;
		Render::BeamSettingsHandle* mTracerBeamTrailSettingsHandle;
		Render::BeamSettingsHandle* mTracerBeamTrailAISettingsHandle;
		qWiseSymbol mAudioWeaponType;
		bool mAudioWeaponIsLooping;
		qArray<qWiseSymbol> mSoundbankIds;
		f32 mAimYawPerSRad;
		f32 mAimPitchPerSRad;
		f32 mAimMaxInputSpeedPerS;
		qFixedArray<f32, 10> mAimInputMappingInput;
		qFixedArray<f32, 10> mAimInputMappingOutput;
		LinearGraph<f32> mAimInputMapping;
		f32 mAimFlickTransitionRadPerS;
		f32 mAimSubtargetTransitionRadPerS;
		f32 mAimFreeAimTransitionRadPerS;
		f32 mAimFovOffset;
		f32 mRecoilKickupMin;
		f32 mRecoilKickupMax;
		f32 mRecoilKickupOffset;
		f32 mRecoilKickupRateAttack;
		f32 mRecoilKickupRateDecay;
		f32 mRecoilKickback;
		f32 mRecoilKickbackSpeed;
		f32 mRecoilKickbackDur;
		f32 mMinDesiredDistance;
		f32 mMaxDisiredDistance;
		f32 mDesiredDistance;
		qVector3 mAimOriginOffset;
		qVector3 mThrownWeaponSpinAxis;

		/* Constructor, Destructor */

		FireModeInfo() { SDK_CALL_FUNC(void, 0x517470, void*)(this); }
		~FireModeInfo() { SDK_CALL_FUNC(void, 0x51B850, void*)(this); }

		/* Functions */

		void InitFromPropertySet(qPropertySet* properties) { SDK_CALL_FUNC(void, 0x536B20, void*, qPropertySet*)(this, properties); }
	};

	class WeaponTypeInfo
	{
	public:
		qSymbol mPropertySetSymbol;
		u32 mNumFireModes;
		FireModeInfo* mFireModes[2];

		WeaponTypeInfo() : mNumFireModes(0), mFireModes{0,0} {}

		/* Functions */

		void InitFromPropertySet(qPropertySet* properties) { SDK_CALL_FUNC(void, 0x538D10, void*, qPropertySet*)(this, properties); }
	};

	class SimObjectWeaponPropertiesComponent : public SimObjectPropertiesComponent, public qNode<SimObjectWeaponPropertiesComponent>
	{
	public:
		enum { _TypeUID = 0xB2000003 };

		u32 mLastOwner;
		u32 mFireMode;
		WeaponTypeInfo* mWeaponTypeInfo;
		f32 mUnloadTimeOut;
		u32 mSoundBankLoadedId;
		f32 mLastBulletImpactStimulusTimer;
		bool mAccessoriesPreloaded;
		qSymbol mMagazineType;
		bool mIsRealWeapon;
		bool mIsPhoneCamera;
		bool mIsBladed;
		u32 mHudReticule;
		ActionPath mNetWorkedFireStateNode;

		/* Static Members */

		SDK_VINLINE qGlobalVar<u32, 0x240E3D8> sNumWeaponTypeInfos;
		SDK_VINLINE qGlobalArray<WeaponTypeInfo, 120, 0x240EEC0> sWeaponTypeInfos;

		/* Static Functions */

		SDK_SINLINE void StaticInit() { SDK_CALL_FUNC(void, 0x5500F0)(); }
		SDK_SINLINE void AddWeaponTypeInfosForPropertySet(qPropertySet* pPropertySet) { SDK_CALL_FUNC(void, 0x5214B0, qPropertySet*)(pPropertySet); }

		/* Impl Functions */

		SDK_INLINE qSymbol GetExplosionType() { return mWeaponTypeInfo->mFireModes[mFireMode]->mExplosionType; }
		SDK_INLINE qSymbol GetWeaponID() { return mWeaponTypeInfo->mPropertySetSymbol; }

		/* Functions */

		f32 DetermineProjectileDamage(bool bAI) { return SDK_CALL_FUNC(f32, 0x525E70, void*, bool)(this, bAI); }
		f32 DetermineProjectileSpeed(bool bAI) { return SDK_CALL_FUNC(f32, 0x525EE0, void*, bool)(this, bAI); }
		f32 DetermineRateOfFire(bool bAI) { return SDK_CALL_FUNC(f32, 0x525F80, void*, bool)(this, bAI); }
		bool GetBooleanValue(eSimObjectWeaponBooleanEnum eSimObjectWeaponBoolean) { return SDK_CALL_FUNC(bool, 0x52ABC0, void*, eSimObjectWeaponBooleanEnum)(this, eSimObjectWeaponBoolean); }
		u32 GetProjectileSpawnBoneID() { return SDK_CALL_FUNC(u32, 0x52F690, void*)(this); }
		bool HasAmmo() { return SDK_CALL_FUNC(bool, 0x535270, void*)(this); }
		bool IsOwned() { return SDK_CALL_FUNC(bool, 0x53B5F0, void*)(this); }
		void PreloadAccessories() { SDK_CALL_FUNC(void, 0x542E50, void*)(this); }
		void UnloadAccessories() { SDK_CALL_FUNC(void, 0x558600, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(SimObjectWeaponPropertiesComponent, 0xE8);
}
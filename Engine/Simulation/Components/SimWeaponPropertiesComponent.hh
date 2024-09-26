#pragma once

namespace UFG
{
	struct FireModeInfo_t
	{
		uint32_t mSimObjectWeaponType;
		eInventoryItemEnum mAmmoInventoryItem;
		int mAmmoClipCapacity;
		int mAmmoTotalCapacity;
		float mRateOfFire;
		float mHardLockReticleSizeMin;
		float mHardLockReticleSizeMax;
		float mReticleSizeMin;
		float mReticleSizeMax;
		float mReticleSizeBlindfire;
		float mRangedDistance;
		float mAngularInaccuracyRadMin;
		float mAngularInaccuracyRadMax;
		float mProjectileSpeed;
		float mProjectileSpeedAI;
		float mProjectileGravity;
		float mArmingDistance;
		float mSlowModeRateOfFireMultiplier;
		float mSlowModeRateOfFireMultiplierAI;
		float mSlowModeProjectileSpeedMultiplier;
		float mSlowModeProjectileSpeedMultiplierAI;
		float mSlowModeProjectileDamageMultiplier;
		float mSlowModeProjectileDamageMultiplierAI;
		float mProjectilePhysicsImpulse;
		float mThrownSpeed;
		qSymbol mProjectileSpawnBoneName;
		uint32_t mProjectileSpawnBoneID;
		qSymbol mExplosionType;
		float mBulletLifeSpan;
		bool mIsTwoHandedWeapon;
		bool mIsAutomatic;
		bool mStowable;
		bool mHasSniperScope;
		uint32_t mBulletTypeID;
		uint32_t mBulletEffectID;
		uint32_t mBulletPerShot;
		float mHardLockDamageMultiplier;
		float mDamageMultiplier;
		float mDamage;
		float mPropDamage;
		float mVehicleDamage;
		int mProjectileReaction;
		float mFlickTargetingAngularLimitRad;
		float mAccuracyOnTargetChanged;
		float mAccuracyPenaltyPerShot;
		float m_fAccuracyRateMultiplier;
		qVector3 mMinAngularVelocityWhenThrown;
		qVector3 mMaxAngularVelocityWhenThrown;
		uint32_t mStartingMaxAmmoCount;
		uint32_t mStartingMinAmmoCount;
		uint32_t mAIOnDeathDropMaxAmmoCount;
		uint32_t mAIOnDeathDropMinAmmoCount;
		qResourceHandle* mTracerBeamSettingsHandle;
		qResourceHandle* mTracerBeamAISettingsHandle;
		qResourceHandle* mTracerBeamTrailSettingsHandle;
		qResourceHandle* mTracerBeamTrailAISettingsHandle;
		qSymbol mAudioWeaponType;
		bool mAudioWeaponIsLooping;
		qArray<qSymbol> mSoundbankIds;
		float mAimYawPerSRad;
		float mAimPitchPerSRad;
		float mAimMaxInputSpeedPerS;
		qFixedArray<float, 10> mAimInputMappingInput;
		qFixedArray<float, 10> mAimInputMappingOutput;
		LinearGraph<float> mAimInputMapping;
		float mAimFlickTransitionRadPerS;
		float mAimSubtargetTransitionRadPerS;
		float mAimFreeAimTransitionRadPerS;
		float mAimFovOffset;
		float mRecoilKickupMin;
		float mRecoilKickupMax;
		float mRecoilKickupOffset;
		float mRecoilKickupRateAttack;
		float mRecoilKickupRateDecay;
		float mRecoilKickback;
		float mRecoilKickbackSpeed;
		float mRecoilKickbackDur;
		float mMinDesiredDistance;
		float mMaxDisiredDistance;
		float mDesiredDistance;
		qVector3 mAimOriginOffset;
		qVector3 mThrownWeaponSpinAxis;
	};
	UFG_ASSERT_STRUCT(FireModeInfo_t, 0x1E8);

	struct WeaponTypeInfo_t
	{
		qSymbol mPropertySetSymbol;
		uint32_t mNumFireModes;
		FireModeInfo_t* mFireModes[2];

		static UFG_INLINE WeaponTypeInfo_t* GetWeaponTypeInfos()
		{
			return reinterpret_cast<WeaponTypeInfo_t*>(UFG_RVA(0x240EEC0));
		}
	};
	UFG_ASSERT_STRUCT(WeaponTypeInfo_t, 0x18);

	//================================================================================================================================

	class SimWeaponPropertiesComponent : public SimObjectPropertiesComponent
	{
	public:
		qNode<SimWeaponPropertiesComponent> mNode;
		uint32_t mLastOwner;
		uint32_t mFireMode;
		WeaponTypeInfo_t* mWeaponTypeInfo;
		float mUnloadTimeOut;
		uint32_t mSoundBankLoadedId;
		float mLastBulletImpactStimulusTimer;
		bool mAccessoriesPreloaded;
		qSymbol mMagazineType;
		bool mIsRealWeapon;
		bool mIsPhoneCamera;
		bool mIsBladed;
		uint32_t mHudReticule;
		CActionPath mNetWorkedFireStateNode;

		static UFG_INLINE void StaticInit()
		{
			*reinterpret_cast<uint32_t*>(UFG_RVA(0x240E3D8)) = 0; // sNumWeaponTypeInfos
			reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x5500F0))();
		}
	}; typedef SimWeaponPropertiesComponent CSimWeaponPropertiesComponent;
	UFG_ASSERT_CLASS(SimWeaponPropertiesComponent, 0xE8);
}
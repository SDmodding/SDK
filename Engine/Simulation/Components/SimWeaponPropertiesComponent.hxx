#pragma once

namespace UFG
{
	class CSimWeaponPropertiesComponent : public CSimObjectPropertiesComponent
	{
	public:
		qNode<CSimWeaponPropertiesComponent> mNode;
		uint32_t mLastOwner;
		uint32_t mFireMode;

		struct WeaponTypeInfo_t
		{
			qSymbol mPropertySetSymbol;
			uint32_t mNumFireModes;

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
				void* mTracerBeamSettingsHandle;
				void* mTracerBeamAISettingsHandle;
				void* mTracerBeamTrailSettingsHandle;
				void* mTracerBeamTrailAISettingsHandle;
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
			FireModeInfo_t* mFireModes[2];
		};
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

		static void StaticInit()
		{
			*reinterpret_cast<uint32_t*>(UFG_RVA(0x240E3D8)) = 0; // sNumWeaponTypeInfos
			reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x5500F0))();
		}

		static WeaponTypeInfo_t* GetWeaponTypeInfos()
		{
			return reinterpret_cast<WeaponTypeInfo_t*>(UFG_RVA(0x240EEC0));
		}
	};
	UFG_ASSERT_CLASS(CSimWeaponPropertiesComponent, 0xE8);
}
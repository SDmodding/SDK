#pragma once

namespace UFG
{
	class CInventoryComponent;

	// Components
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
				unsigned int mSimObjectWeaponType;
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
				unsigned int mProjectileSpawnBoneID;
				qSymbol mExplosionType;
				float mBulletLifeSpan;
				bool mIsTwoHandedWeapon;
				bool mIsAutomatic;
				bool mStowable;
				bool mHasSniperScope;
				unsigned int mBulletTypeID;
				unsigned int mBulletEffectID;
				unsigned int mBulletPerShot;
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
				unsigned int mStartingMaxAmmoCount;
				unsigned int mStartingMinAmmoCount;
				unsigned int mAIOnDeathDropMaxAmmoCount;
				unsigned int mAIOnDeathDropMinAmmoCount;
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
			*reinterpret_cast<uint32_t*>(UFG_RVA(0x240E3D8)) = 0;
			reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x5500F0))();
		}
	};

	class CGunComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		unsigned int mNetShootSequence;
		qVector3 mNetBulletPosition;
		qVector3 mNetBulletVelocity;

		UFG_PAD(0x4);

		RebindingComponentHandle<CSimWeaponPropertiesComponent> mSimObjectWeaponPropertiesComponent;
		RebindingComponentHandle<CInventoryComponent> mInventoryItemComponent;

		eTargetTypeEnum mMustHitTarget;
		int mClipAmmo[2];
		float mLastFiredTime;
		float mRateOfFireOverride;
		bool mIfResetAmmoOnDeath;

		//UFG::GunComponent::ShootParams mShootParams;

		int GetClipAmmo()
		{
			return reinterpret_cast<int(__fastcall*)(void*)>(UFG_RVA(0x52B1E0))(this);
		}

		int GetTotalAmmo()
		{
			return reinterpret_cast<int(__fastcall*)(void*)>(UFG_RVA(0x530B50))(this);
		}

		void SetClipAmmo(int count)
		{
			reinterpret_cast<void(__fastcall*)(void*, int)>(UFG_RVA(0x54BF40))(this, count);
		}

		void SetTotalAmmo(int count)
		{
			reinterpret_cast<void(__fastcall*)(void*, int)>(UFG_RVA(0x54F410))(this, count);
		}
	};

	// Main
	class CSimWeapon : public CSimObject
	{
	public:
		CGunComponent* GetGun()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags >> 14) & 1)
				m_Component = GetComponentOfTypeHK(WeaponGunComponent_TypeUID);
			else if ((m_Flags & 0x8000u) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(WeaponGunComponent_TypeUID);
				else
					m_Component = GetComponentOfType(WeaponGunComponent_TypeUID);
			}
			else
				m_Component = GetComponentOfTypeHK(WeaponGunComponent_TypeUID);

			return reinterpret_cast<CGunComponent*>(m_Component);
		}
	};
}
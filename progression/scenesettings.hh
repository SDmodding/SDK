#pragma once

namespace UFG
{
	class SceneSettings : public qNodeRB<SceneSettings>
	{
	public:
		struct AltLayerSetup
		{
			qString mLayerName;
			bool mFlush;
			bool mActivate;
		};

		struct DisguiseSetup
		{
			qSymbol mDisguise;
			bool mEnableWardrobe;
			bool mEnableVendors;
			bool mKeepOutfit;
		};

		struct LayerSetup
		{
			qSymbol mLayerName;
			bool mGeoSettingsPresent;
			bool mEnable;
			bool mGeoAutoActivate;
			bool mActivate;
		};

		struct LoadingHintSetup
		{
			u32 mPriority;
			qString mHintString;
		};

		struct LoadingScreenSetup
		{
			u32 mPriority;
			qString mLoadingScreen;
		};

		struct VendorSetup
		{
			qSymbol mVendorType;
			bool mEnable;
		};

		f32 mWeatherOverrideIntensity;
		f32 mWeatherOverrideWetness;
		bool mWeatherOverrideLock;
		f32 mTimeOverrideInSeconds;
		bool mTimeOverrideLockSet;
		bool mWeatherOverrideLockSet;
		bool mTimeOverrideLock;
		bool mResetAmbientPeds;
		bool mResetEnvironmentOverride;
		bool mShowCurtains;
		bool mHideCurtains;
		bool mLockPedsOnStart;
		bool mUnLockPedsOnEnd;
		bool mEnableAmbientPedsOnStart;
		bool mEnableAmbientPedsOnEnd;
		bool mLockTrafficOnStart;
		bool mUnLockTrafficOnEnd;
		bool mEnableTrafficOnStart;
		bool mEnableTrafficOnEnd;
		f32 mVehicleTeleportRange;
		qString mName;
		qSymbol mTeleportMarker;
		qSymbol mVehicleTeleportMarker;
		bool mVehicleDestroy;
		bool mHasTeleportPositionInternal;
		qVector3 mTeleportPositionInternal;
		qArray<SceneSettings::LayerSetup> mLayerSetupOnStart;
		qArray<SceneSettings::LayerSetup> mLayerSetupOnEnd;
		qArray<SceneSettings::AltLayerSetup> mAltLayerSetupOnStart;
		qArray<SceneSettings::AltLayerSetup> mAltLayerSetupOnEnd;
		qArray<SceneSettings::VendorSetup> mVendorSetupOnStart;
		qArray<SceneSettings::VendorSetup> mVendorSetupOnEnd;
		qArray<SceneSettings::DisguiseSetup> mDisguiseSetupOnStart;
		qArray<SceneSettings::DisguiseSetup> mDisguiseSetupOnEnd;
		qArray<SceneSettings::LoadingHintSetup> mLoadingHintSetupOnStart;
		qArray<SceneSettings::LoadingHintSetup> mLoadingHintSetupOnEnd;
		qArray<SceneSettings::LoadingScreenSetup> mLoadingScreenSetupOnStart;
		qArray<SceneSettings::LoadingScreenSetup> mLoadingScreenSetupOnEnd;
	};
	SDK_ASSERT_SIZEOF(SceneSettings, 0x148);
}
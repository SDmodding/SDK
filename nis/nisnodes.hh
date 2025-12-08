#pragma once

class NISNode : public ActionNodePlayable
{
public:
	bool mIsPlaceHolder;
	BinString mPlaceHolderMessage;
	bool mCanSkip;
	bool mDisableGravityForActors;
	bool mDisableAmbientPeds;
	bool mDisableScriptedPeds;
	bool mDisableHUD;
	bool mInteriorTime;
	bool mSeamlessIn;
	bool mSeamlessOut;
	bool mAllowLetterbox;
	bool mForceContinousTimeMode;
	bool mUseBoundingBoxToClearPeds;
	bool mUseBoundingBoxToClearVehicles;
	f32 mTimeBeforeCanSkip;
	f32 mStoredTOD;
	f32 mPostNISTOD;
	f32 mTODTime;
	f32 mWeatherWetness;
	f32 mGI_Irradiance;
	f32 mFadeOutDuration;
	f32 mFadeInDuration;
	qEnum<UFG::eWeatherTypeEnum, u32> mWeatherType;
	UFG::qOffset64<TrackGroup*> mTracksAction;
	BinString mAnimationGroupName;
	BinString mFacialAnimGroupName;
	BinString mExtraFacialAnimGroupName;
	BinString mPostNISMarkerName;
	BinString mLightLayerDisableName;
	BinString mTODEnvSetting;
	BinString mSoundbank;
	BinString mNISName;
	CameraAnimationTrack* mPrimaryCameraAnimationTrack;
	NISLightGroup* mLightGroupObject;
	int m_audioTagId[4];
	u32 m_audioTagUID[4];
};
SDK_ASSERT_SIZEOF(NISNode, 0x110);
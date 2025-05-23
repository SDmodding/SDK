#pragma once

namespace Render
{
	class ParticleEmitterSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		CB_ParticleSettings mSettings;
		CB_FXSizeModule mSizeModule;
		CB_FXFlowmapSettings mFlowmapSettings;
		Illusion::ModelHandle mModel;
		u64 mBitFields[1];
		u32 mTextureID;
		u32 mReflectionMapTextureID;
		u32 mNormalTextureID;
		u32 mShaderID;
		u32 mModelToEmitFromUID;
		f32 mEmissionRate;
		u32 mEmissionInit;
		f32 mLifeMin;
		f32 mLifeMax;
		f32 mGravityMin;
		f32 mGravityMax;
		f32 mDragMin;
		f32 mDragMax;
		f32 mXScaleMin;
		f32 mXScaleMax;
		f32 mXScaleSpeedMin;
		f32 mXScaleSpeedMax;
		f32 mYScaleMin;
		f32 mYScaleMax;
		f32 mYScaleSpeedMin;
		f32 mYScaleSpeedMax;
		f32 mRotationDampMin;
		f32 mRotationDampMax;
		UFG::qVector3 mJitter;
		UFG::qVector3 mRotateMin;
		UFG::qVector3 mRotateMax;
		UFG::qVector3 mRotateSpeedMin;
		UFG::qVector3 mRotateSpeedMax;
		UFG::qVector3 mInheritVelocityMin;
		UFG::qVector3 mInheritVelocityMax;
		UFG::qVector3 mLocalVelocityMin;
		UFG::qVector3 mLocalVelocityMax;
		UFG::qVector3 mGlobalVelocityMin;
		UFG::qVector3 mGlobalVelocityMax;
		UFG::qVector3 mNormalVelocityMin;
		UFG::qVector3 mNormalVelocityMax;
		f32 mSoftContrast;
		f32 mSoftScale;
		f32 mBounciness;
		f32 mLocalSpaceToWorldSpaceBlend;
		u32 mTextureOrientation;
		u32 mPhysicsType;
		f32 mUseTransformScaling;
		f32 mBackfaceCulling;
		f32 mMeshEmissionVertexSkip;
		u32 mFlowmapTextureID;
		s8 mStartAnimFrame;
		s8 mPriority;
		s8 mParticleOrientation;
		s8 mDrawType;
		s8 mType;
		s8 mSpace;
	};

	class ParticleEmitterSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_ParticleEmitterSettings, ParticleEmitterSettings>
	{
	public:
	};

	class ScreenParticleEmitterSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		CB_ParticleSettings mParticleSettings;
		CB_FXSizeModule mFXSizeModule;
		u32 mTextureUID;
		u32 mDistortionTextureUID;
		f32 mDiffuseOverlay;
		u32 mEmissionInit;
		f32 mEmissionRate;
		f32 mEmissionDistance;
		f32 mLifeTimeMin;
		f32 mLifeTimeMax;
		f32 mGravityMin;
		f32 mGravityMax;
		f32 mInitScaleMin;
		f32 mInitScaleMax;
		f32 mRegionMinX;
		f32 mRegionMinY;
		f32 mRegionMaxX;
		f32 mRegionMaxY;
		u32 mScreenMotionPercentage;
		f32 mScreenMotionMinX;
		f32 mScreenMotionMinY;
		f32 mScreenMotionMaxX;
		f32 mScreenMotionMaxY;
		u32 mScreenJitterPercentage;
		f32 mScreenJitterMinX;
		f32 mScreenJitterMinY;
		f32 mScreenJitterMaxX;
		f32 mScreenJitterMaxY;
		bool mInvertDistortion;
	};

	class ScreenParticleEmitterSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_ScreenParticleEmitterSettings, ScreenParticleEmitterSettings>
	{
	public:
	};
}
#pragma once

namespace UFG
{
	class RenderContext;
}

namespace Render
{
	class View;

	//----------------------------------------------------------------
	//	Enums
	//----------------------------------------------------------------

	enum eAAQuality : s32
	{
		AA_QUALITY_NORMAL,
		AA_QUALITY_HIGH,
		AA_QUALITY_EXTREME,
		NUM_AA_QUALITY
	};

	enum eAnisotropicQuality : s32
	{
		ANISOTROPICQUALITY_OFF,
		ANISOTROPICQUALITY_2,
		ANISOTROPICQUALITY_4,
		ANISOTROPICQUALITY_8,
		ANISOTROPICQUALITY_16,
		NUM_ANISOTROPICQUALITY
	};

	enum eDeviceType : s32
	{
		DEVICE_TYPE_UNKNOWN,
		DEVICE_TYPE_LEGACY_ATI,
		DEVICE_TYPE_CURRENT_AMD
	};

	enum eDisplayScalingModes : s32
	{
		SCALING_MODE_NOTFILTERED = -1,
		SCALING_MODE_DEFAULT,
		SCALING_MODE_CENTERED,
		SCALING_MODE_STRETCHED
	};

	enum eFPSLimiter : s32
	{
		FPS_LIMITER_OFF,
		FPS_LIMITER_SYNC_INTERVAL_1,
		FPS_LIMITER_SYNC_INTERVAL_2,
		FPS_LIMITER_SYNC_INTERVAL_3,
		FPS_LIMITER_SYNC_INTERVAL_4,
		NUM_FPS_LIMITER
	};

	enum eGlobalSetting : s32
	{
		GRAPHICS_CUSTOM,
		GRAPHICS_LOW,
		GRAPHICS_NORMAL,
		GRAPHICS_HIGH,
		GRAPHICS_EXTREME,
		NUM_GRAPHICS
	};

	enum eHardwareFeatureLevel : s32
	{
		FEATURE_LEVEL_D3D10_0,
		FEATURE_LEVEL_D3D10_1,
		FEATURE_LEVEL_D3D11_0
	};

	enum eLODSetting : s32
	{
		LOD_SETTING_LOW,
		LOD_SETTING_NORMAL,
		LOD_SETTING_HIGH,
		LOD_SETTING_EXTREME,
		NUM_LOD_SETTING
	};

	enum eMotionBlur : s32
	{
		MOTION_BLUR_OFF,
		MOTION_BLUR_NORMAL,
		MOTION_BLUR_HIGH,
		NUM_MOTION_BLUR
	};

	enum eSSAO : s32
	{
		SSAO_NORMAL,
		SSAO_HIGH,
		NUM_SSAO
	};

	enum eScanlineMode : s32
	{
		SCANLINE_MODE_NOTFILTERED = -1,
		SCANLINE_MODE_UNSPECIFIED,
		SCANLINE_MODE_PROGRESSIVE
	};

	enum eShadowFilter : s32
	{
		SHADOW_FILTER_NORMAL,
		SHADOW_FILTER_HIGH,
		NUM_SHADOW_FILTER
	};

	enum eShadowResolution : s32
	{
		SHADOW_RES_OFF,
		SHADOW_RES_NORMAL,
		SHADOW_RES_HIGH,
		NUM_SHADOW_RES
	};

	enum eTextureDetailLevel : s32
	{
		TEXTURE_DETAIL_LOW,
		TEXTURE_DETAIL_MEDIUM,
		TEXTURE_DETAIL_HIGH
	};

	//----------------------------------------------------------------
	//	Mode
	//----------------------------------------------------------------

	class DisplayMode
	{
	public:
		u32 mBackBufferWidth;
		u32 mBackBufferHeight;
		u32 mRefreshRateNumerator;
		u32 mRefreshRateDenominator;
		u32 mAdapterUID;
		u32 mMonitorUID;
		eDisplayScalingModes mScaling;
		eScanlineMode mScanlineMode;
	};

	//----------------------------------------------------------------
	//	Frame Features
	//----------------------------------------------------------------

	class RenderFrameFeatures
	{
	public:
		bool mWorld;
		bool mScenery;
		bool mWireframeScenery;
		bool mLights;
		bool mAlternateGradientBackground;
		bool mPostFX;
		bool mUI;
		bool mDOF;
		bool mAO;
		bool mMotionBlur;
		bool mForceLetterBox;
		bool mForceSceneryDoubleSided;
	};

	//----------------------------------------------------------------
	//	Output Params
	//----------------------------------------------------------------

	class RenderOutputParams
	{
	public:
		DisplayMode mDisplayMode;
		bool mEnableFullscreen;
		bool mEnable3D;
		bool mEnableVSync;
		bool mEnableLowResBuffer;
		bool mEnableCloudVolumes;
		eAAQuality mAAQuality;
		eShadowResolution mShadowRes;
		eShadowFilter mShadowFilter;
		eMotionBlur mMotionBlur;
		f32 mInterAxialDistance;
		eSSAO mSSAO;
		eFPSLimiter mFPSLimiter;
		eHardwareFeatureLevel mFeatureLevel;
		int m3DDepth;
		int m3DConvergence;
		eLODSetting mLODSetting;
		eGlobalSetting mGlobalSetting;
		eDeviceType mDeviceType;
		int mTimeStepSmoothingFrames;
		eAnisotropicQuality mTextureFilterQuality;
		eTextureDetailLevel mTextureDetailLevel;
	};
	SDK_ASSERT_SIZEOF(RenderOutputParams, 0x68);

	struct RenderCallbacks
	{
		void(__fastcall* mRenderWorldFunc)(float, void*);
		bool(__fastcall* mUpdateWorldFunc)(float);
		void(__fastcall* mResizeRenderBuffersFunc)();
		void(__fastcall* mResizeShadowsFunc)();
		void(__fastcall* mChangeTexturePackFunc)();
		void(__fastcall* mChangeLODSettingFunc)();
		void(__fastcall* mRenderThreadSyncPointFunc)();
		void(__fastcall* mRenderSim)(UFG::RenderContext*, View*);
		void(__fastcall* mRenderSimDebug)(UFG::RenderContext*, View*);
		void(__fastcall* mRenderSimDebugOverlay)(UFG::RenderContext*, View*);
		void(__fastcall* mRenderSimOcclusionQueries)(UFG::RenderContext*, View*);
		void* mRenderParam;
		bool mbDisableSwapChainResizing;
	};

	SDK_VINLINE qGlobalVar<RenderCallbacks*, 0x2129980> gRenderCallbacks;
}
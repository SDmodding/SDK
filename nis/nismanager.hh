#pragma once

class NISManager
{
public:
	enum eNISEndCondition
	{
		eNIS_Playing,
		eNIS_Finished,
		eNIS_Skipping
	};

	enum eStateEnum
	{
		eSTATE_IDLE,
		eSTATE_SHOW_INTRO_CURTAINS,
		eSTATE_LOADING_INSTANCE,
		eSTATE_SETUP_LOCATION,
		eSTATE_ACTION,
		eSTATE_SHOW_OUTRO_CURTAINS,
		eSTATE_UNLOADING_INSTANCE,
		NUM_STATES
	};

	UFG::qSafePointer<NISInstance, NISInstance> mpActiveInstance;
	UFG::qSafePointer<NISInstance, NISInstance> mpPreloadInstance;
	UFG::qList<NISInstance, class NISInstanceMasterList, 0> mInstances;
	bool mPaused;
	eStateEnum mState;
	f32 mfStateTimeoutS;
	eNISEndCondition mEndCondition;
	f32 mTime;
	f32 mLength;
	f32 mTimeToEndAt;
	f32 mAudioTime;
	u32 mLightLayerUID;
	ActionContext* mpActionContext;
	ActionController mActionController;
	UFG::NISSpatialDataHandle mSpatialDataHandle;
	UFG::NavDynamicOutline* mpDynamicOutline;
	UFG::qSafePointer<UFG::SimObject, UFG::SimObject> mDisabledVehicle;
	bool mbCurtainsShown;
	bool mbUpdatedOnce;
	bool mbUserInputDisabled;
	bool mbAudioStopped;
	bool mbStreamingComplete;
	u32 mHudDisableCount;
	bool mbCameraAttached;
	bool mModifyPlayerVulnerability;
	bool mWasCopSystemEnabled;
	bool mHighDefModelsEnabled;
	bool mUIHelpbarLocked;
	UFG::SceneSettings mPostNisSettings;
	f32 mPlaceHolderTimeOut;

	/* Static Functions */

	SDK_SINLINE NISManager* Instance() { return SDK_VAR_GET(NISManager*, 0x23D8270); }

	/* Impl Functions */

	SDK_INLINE void Pause() { mPaused = 1; }
	SDK_INLINE bool Play(NISInstance* pInstance) { return PlayInternal(pInstance); }
	SDK_INLINE void Resume() { mPaused = 0; }

	/* Functions */

	void AllowGameStateChanges() { SDK_CALL_FUNC(void, 0x3E15E0, void*)(this); }
	bool CanSkipNow() { return SDK_CALL_FUNC(bool, 0x3E2110, void*)(this); }
	NISInstance* CreateInstance(const char* pathName) { return SDK_CALL_FUNC(NISInstance*, 0x3E25C0, void*, const char*)(this, pathName); }
	void DestroyInstance(NISInstance* pInstance) { SDK_CALL_FUNC(void, 0x3E2640, void*, NISInstance*)(this, pInstance); }
	void EnterStateAction() { SDK_CALL_FUNC(void, 0x3E28F0, void*)(this); }
	void EnterStateIntroCurtains() { SDK_CALL_FUNC(void, 0x3E29F0, void*)(this); }
	void EnterStateLoadingInstance() { SDK_CALL_FUNC(void, 0x3E2AB0, void*)(this); }
	void EnterStateOutroCurtains() { SDK_CALL_FUNC(void, 0x3E2B50, void*)(this); }
	void EnterStateSetupLocation() { SDK_CALL_FUNC(void, 0x3E2B90, void*)(this); }
	void EnterStateUnloadingInstance() { SDK_CALL_FUNC(void, 0x3E2C20, void*)(this); }
	class AudioTaskNIS* GetAudioMasterTask() { return SDK_CALL_FUNC(AudioTaskNIS*, 0x3E2C60, void*)(this); }
	void HideHUD() { SDK_CALL_FUNC(void, 0x3E2D20, void*)(this); }
	bool IntersectsSpatialBoundingBox(const UFG::qBox& box) { return SDK_CALL_FUNC(bool, 0x3E3060, void*, const UFG::qBox&)(this, box); }
	bool IsActiveInNIS(UFG::SimObject* simObject) { return SDK_CALL_FUNC(bool, 0x3E30B0, void*, UFG::SimObject*)(this, simObject); }
	void OnCameraAttached(CameraAnimationTask* cameraTask) { SDK_CALL_FUNC(void, 0x3E3760, void*, CameraAnimationTask*)(this, cameraTask); }
	void OnCameraDetached(CameraAnimationTrack* cameraTrack) { SDK_CALL_FUNC(void, 0x3E37D0, void*, CameraAnimationTrack*)(this, cameraTrack); }
	bool Play(const char* pathName) { return SDK_CALL_FUNC(bool, 0x3E3B30, void*, const char*)(this, pathName); }
	bool PlayInternal(NISInstance* pInstance) { return SDK_CALL_FUNC(char, 0x3E3B60, void*, NISInstance*)(this, pInstance); }
	void PlayNIS() { SDK_CALL_FUNC(void, 0x3E3C40, void*)(this); }
	void PreventGameStateChanges() { SDK_CALL_FUNC(void, 0x3E4290, void*)(this); }
	void RequestSkip() { SDK_CALL_FUNC(void, 0x3E44E0, void*)(this); }
	void Reset() { SDK_CALL_FUNC(void, 0x3E4560, void*)(this); }
	void ResetNISSettings() { SDK_CALL_FUNC(void, 0x3E4680, void*)(this); }
	void SetPlayTime(f32 timeAbsolute, bool syncSceneTime) { SDK_CALL_FUNC(void, 0x3E51B0, void*, f32, bool)(this, timeAbsolute, syncSceneTime); }
	void SetupNISSettingsPostStreamed() { SDK_CALL_FUNC(void, 0x3E5770, void*)(this); }
	void SetupNISSettingsPreStreamed() { SDK_CALL_FUNC(void, 0x3E5D10, void*)(this); }
	void StopActiveNIS() { SDK_CALL_FUNC(void, 0x3E6070, void*)(this); }
	void StopNIS() { SDK_CALL_FUNC(void, 0x3E60D0, void*)(this); }
	bool UseHighDefModel(const UFG::qSymbol& actorId) { return SDK_CALL_FUNC(bool, 0x3E79D0, void*, const UFG::qSymbol&)(this, actorId); }
};
SDK_ASSERT_SIZEOF(NISManager, 0x330);
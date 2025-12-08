#pragma once

class NISInstance : public UFG::qSafePointerNode<NISInstance>, public UFG::qNode<NISInstance>
{
public:
	enum eStatusEnum
	{
		eSTATUS_INVALID,
		eSTATUS_IDLE,
		eSTATUS_QUEUED_FOR_PRELOADING,
		eSTATUS_PRELOADING,
		eSTATUS_LOADING,
		eSTATUS_PLAYING,
		NUM_STATUS_TYPES
	};

	eStatusEnum mStatus;
	NISNode* mpNISNode;
	UFG::qWiseSymbol mSoundbankSymbol;
	bool mbDestroyOnUnload;
	bool mbIntermediateNIS;
	bool mbPostNISFadeIn;
	UFG::SceneSettings* mpPostNISSceneSettings;
	NISAllowPlayerControlTask* mpNISAllowPlayerControlTask;
	AnimationGroupHandle mAnimationGroupHandle;
	AnimationGroupHandle mFacialAnimGroupHandle;
	AnimationGroupHandle mExtraFacialAnimGroupHandle;
	UFG::qArray<UFG::MeshResourceLoader, 0> mMeshResources;
	bool mPlayRelativeToNISSceneRoot;
	__declspec(align(16)) UFG::qMatrix44 mNISSceneRoot;
};
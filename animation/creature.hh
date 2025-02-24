#pragma once

class Creature : UFG::qSafePointerNode<Creature>
{
public:
	enum END_EFFECTOR_CACHE
	{
		EEC_DONT_KNOW,
		EEC_YES,
		EEC_NO
	};

	enum PoseState
	{
		UPDATED,
		UPDATED_FROM_CACHE,
		SUBMITTED,
		SYNCED
	};

	UFG::qList<PoseDriver> mPoseDrivers;
	bool mNetworkLock;
	PoseState mPoseState;
	u32 mPoseCRC;
	hkQsTransformf mPrevMotion;
	hkQsTransformf mLastSetPosition;
	UFG::qVector3 mGroundNormal;
	UFG::qList<Attachment> mAttachments;
	UFG::qVector3 mAnimatedMoveDirection;
	f32 mAnimatedMoveSpeed;
	bool mIsAttached;
	int mForceTransparencyTarget;
	i8 mIsEndEffectorCache[4];
	u32 mPoseFrame;
	UFG::qTask* mPoseTask;
	u32 mCurrentStackDepth;
	bool mCorrected;
	SkeletalPose mPose;
	qProxy<PoseNodeParent> mBlendTree;
	bool mHaventUpdated;
	bool mLowPowerModeEnabled;
	bool mAbsoluteMonSet;
	bool mAbsoluteRelativeRootMotion;
	bool mRestPosePrev;
	PoseTaskInputParams mPoseTaskParams;
	UFG::qMatrix44 mAbsoluteMon;
	UFG::qMatrix44 mAbsoluteRelativeRoot;
	bool mIsSlopeLocomotionFixupEnabled;
	f32 mMaxSlopeLocomotionFixupAngle;
	bool mPlaybackSpeedEnabled;
	f32 mPlaybackSpeed;
	f32 mRagdollBlendWeight;
	bool mDisablePosedrivers;
	u32 mNetPoseSequence;

	/* Functions */

	Attachment* AddAttachment(Attachment* attachment) { return SDK_CALL_FUNC(Attachment*, 0x3A0B80, void*, Attachment*)(this, attachment); }
	Attachment* AddAttachment(UFG::SimObject* self, int attachBoneID, UFG::SimObject* attachedSimObject, int attachmentBoneID, bool positionOnly, f32 blendIn) {
		return SDK_CALL_FUNC(Attachment*, 0x3A0BE0, void*, UFG::SimObject*, int, UFG::SimObject*, int, bool, f32)(this, self, attachBoneID, attachedSimObject, attachmentBoneID, positionOnly, blendIn);
	}
	Attachment* AddAttachmentParkour(UFG::SimObject* attachedToParkourObject, int attachBoneID, UFG::SimObject* attachedSimObject, UFG::ParkourHandle* parkourHandle, f32 blendIn) {
		return SDK_CALL_FUNC(Attachment*, 0x3A1030, void*, UFG::SimObject*, int, UFG::SimObject*, UFG::ParkourHandle*, f32)(this, attachedToParkourObject, attachBoneID, attachedSimObject, parkourHandle, blendIn);
	}
	Attachment* AddAttachmentRelative(UFG::SimObject* self, int attachBoneID, UFG::SimObject* attachedSimObject, int attachmentBoneID, const UFG::qMatrix44& relativePositionWS, f32 blendIn) {
		return SDK_CALL_FUNC(Attachment*, 0x3A1300, void*, UFG::SimObject*, int, UFG::SimObject*, int, const UFG::qMatrix44&, f32)(this, self, attachBoneID, attachedSimObject, attachmentBoneID, relativePositionWS, blendIn);
	}
	void AddRelativeScale(int attachBoneID, UFG::SimObject* attachedSimObject, int attachmentBoneID, const UFG::qVector3& relativeScale) {
		SDK_CALL_FUNC(void, 0x3A1400, void*, int, UFG::SimObject*, int, const UFG::qVector3&)(this, attachBoneID, attachedSimObject, attachmentBoneID, relativeScale);
	}
	void AddRelativeTransform(int attachBoneID, UFG::SimObject* attachedSimObject, int attachmentBoneID, const UFG::qMatrix44& relativeTransform) { 
		SDK_CALL_FUNC(void, 0x3A1470, void*, int, UFG::SimObject*, int, const UFG::qMatrix44&)(this, attachBoneID, attachedSimObject, attachmentBoneID, relativeTransform);
	}
	void Attach(int attachBoneID, const UFG::qVector3& position, f32 weight) { SDK_CALL_FUNC(void, 0x3A2510, void*, int, const UFG::qVector3&, f32)(this, attachBoneID, position, weight); }
	void Attach(int attachBoneID, int blendedAttachBoneID, const UFG::qMatrix44& matrixWS, f32 weight) { 
		SDK_CALL_FUNC(void, 0x3A26B0, void*, int, int, const UFG::qMatrix44&, f32)(this, attachBoneID, blendedAttachBoneID, matrixWS, weight);
	}
	void BlendInPose(SkeletalPose* pose, f32 weight, bool projectTheArrow) { SDK_CALL_FUNC(void, 0x3A2EC0, void*, SkeletalPose*, f32, bool)(this, pose, weight, projectTheArrow); }
	void BuildPoseDriver(const UFG::qSymbolUC& poseDriverSet) { SDK_CALL_FUNC(void, 0x3A4BE0, void*, const UFG::qSymbolUC&)(this, poseDriverSet); }
	void CommonInit() { SDK_CALL_FUNC(void, 0x3A5300, void*)(this); }
	void Destroy() { SDK_CALL_FUNC(void, 0x3A6A60, void*)(this); }
	void DestroyAllAttachments(UFG::SimObject* self, bool onlyRemoveCharacterAttachments) { SDK_CALL_FUNC(void, 0x3A6AD0, void*, UFG::SimObject*, bool)(this, self, onlyRemoveCharacterAttachments); }
	void ForceSyncPose() { SDK_CALL_FUNC(void, 0x3A7A40, void*)(this); }
	hkQsTransformf GetPositionhkQ() { return SDK_CALL_FUNC(hkQsTransformf, 0x3A9570, void*)(this); }
	void GetResourceSystemAttachments(UFG::qArray<UFG::qSymbol>& nameList) { SDK_CALL_FUNC(void, 0x3A95B0, void*, UFG::qArray<UFG::qSymbol>&)(this, nameList); }
	void GetTransform(UFG::qMatrix44& transform) { SDK_CALL_FUNC(void, 0x3A96B0, void*, UFG::qMatrix44&)(this, transform); }
	void GetTransform(int boneID, UFG::qMatrix44& transform) { SDK_CALL_FUNC(void, 0x3A96C0, void*, int, UFG::qMatrix44&)(this, boneID, transform); }
	void GetTransformMS(int boneID, UFG::qMatrix44& transform) { SDK_CALL_FUNC(void, 0x3A96D0, void*, int, UFG::qMatrix44&)(this, boneID, transform); }

	UFG::qVector3 GetTranslation(int boneID)
	{
		qProxy<UFG::qVector3> res;
		SDK_CALL_FUNC(void*, 0x3A96E0, void*, void*, int)(this, &res, boneID);
		return res;
	}

	const UFG::qVector3& GetTranslationMS(int boneID) { return SDK_CALL_FUNC(const UFG::qVector3&, 0x3A9710, void*, int)(this, boneID); }
	Weightset* GetWeightSet(const UFG::qSymbolUC& weightsetName) { return SDK_CALL_FUNC(Weightset*, 0x3AA090, void*, const UFG::qSymbolUC&)(this, weightsetName); }
	void InitWeightSet(const char* weightSetNameFile) { SDK_CALL_FUNC(void, 0x3AAE60, void*, const char*)(this, weightSetNameFile); }
	bool IsEndEffector(int attachBoneID) { return SDK_CALL_FUNC(bool, 0x3AB0A0, void*, int)(this, attachBoneID); }
	void KillBlendTree() { SDK_CALL_FUNC(void, 0x3AB360, void*)(this); }
	void MakeUpright(f32 uprightTime) { SDK_CALL_FUNC(void, 0x3AB730, void*, f32)(this, uprightTime); }
	AnimationNode* PlayAnimation(const UFG::qSymbolUC& animName, AnimationPlayMode playMode, f32 startTime, f32 endTime, f32 blendInTime, bool phaseIn, int& returnCode) { 
		return SDK_CALL_FUNC(AnimationNode*, 0x3AC7A0, void*, const UFG::qSymbolUC&, AnimationPlayMode, f32, f32, f32, bool, int&)(this, animName, playMode, startTime, endTime, blendInTime, phaseIn, returnCode);
	}
	PoseNode* PlayBlendTree(PoseNode* blendTree, PoseNodeParent* blendTreeParent, u32 priority, bool phaseIn, f32 startTime, f32 endTime, int& returnCode) { 
		return SDK_CALL_FUNC(PoseNode*, 0x3ACB90, void*, PoseNode*, PoseNodeParent*, u32, bool, f32, f32, int&)(this, blendTree, blendTreeParent, priority, phaseIn, startTime, endTime, returnCode); 
	}
	PoseNode* PlayBlendTree(PoseNode* blendTree, u32 priority, f32 blendInTime, char phaseIn, f32 startTime, f32 endTime, int& returnCode) { 
		return SDK_CALL_FUNC(PoseNode*, 0x3AC9B0, void*, PoseNode*, u32, f32, char, f32, f32, int&)(this, blendTree, priority, blendInTime, phaseIn, startTime, endTime, returnCode); 
	}
	PoseNode* PlayBlendTree(const UFG::qSymbolUC& treeName, u32 priority, f32 blendInTime, char phaseIn, f32 startTime, f32 endTime, int& returnCode) {
		return SDK_CALL_FUNC(PoseNode*, 0x3AC8F0, void*, const UFG::qSymbolUC&, u32, f32, char, f32, f32, int&)(this, treeName, priority, blendInTime, phaseIn, startTime, endTime, returnCode);
	}
	void PrepPoseTaskInput(PoseNode* tree) { SDK_CALL_FUNC(void, 0x3AD290, void*, PoseNode*)(this, tree); }
	void RebindResources() { SDK_CALL_FUNC(void, 0x3AD960, void*)(this); }
	bool RemoveAttachment(UFG::SimObject* self, int attachBoneID, UFG::SimObject* attachedSimObject) {
		return SDK_CALL_FUNC(bool, 0x3ADFB0, void*, UFG::SimObject*, int, UFG::SimObject*)(this, self, attachBoneID, attachedSimObject);
	}
	void SetAbsoluteRelativeRoot(const UFG::qMatrix44& root) { SDK_CALL_FUNC(void, 0x3AED20, void*, const UFG::qMatrix44&)(this, root); }
	void SetBlendTreePlayTime(f32 timeAbsolute) { SDK_CALL_FUNC(void, 0x3AEF40, void*, f32)(this, timeAbsolute); }
	void SetEndEffectorTarget(int attachBoneID, const UFG::qMatrix44& matrix) { SDK_CALL_FUNC(void, 0x3AF250, void*, int, const UFG::qMatrix44&)(this, attachBoneID, matrix); }
	void SetGroundProperties(const UFG::GroundProperties& p) { SDK_CALL_FUNC(void, 0x3AF320, void*, const UFG::GroundProperties&)(this, p); }
	void SetPoseOnFrameBoundaries(bool val) { SDK_CALL_FUNC(void, 0x3AF620, void*, bool)(this, val); }
	void SetPositionhkQ(hkQsTransformf& pos) { SDK_CALL_FUNC(void, 0x3AF650, void*, hkQsTransformf&)(this, pos); }
	void SetTransform(const UFG::qMatrix44& pos) { SDK_CALL_FUNC(void, 0x3AF8B0, void*, const UFG::qMatrix44&)(this, pos); }
	void SetTransform(int boneID, const UFG::qMatrix44& pos) { SDK_CALL_FUNC(void, 0x3AF8C0, void*, int, const UFG::qMatrix44&)(this, boneID, pos); }
	void SetTransformNodeComponentRoot(UFG::TransformNodeComponent* transformNodeRoot) { SDK_CALL_FUNC(void, 0x3AF8D0, void*, UFG::TransformNodeComponent*)(this, transformNodeRoot); }
	void SetTranslation(const UFG::qVector3& pos) { SDK_CALL_FUNC(void, 0x3AF8E0, void*, const UFG::qVector3&)(this, pos); }
	void SubmitPoseTask() { SDK_CALL_FUNC(void, 0x3AFE90, void*)(this); }
	bool TransferAttachment(int sourceBoneID, int destsourceBoneID, const UFG::qSymbolUC& attachmentBone) { 
		return SDK_CALL_FUNC(bool, 0x3B0200, void*, int, int, const UFG::qSymbolUC&)(this, sourceBoneID, destsourceBoneID, attachmentBone);
	}
	void UnbindResources() { SDK_CALL_FUNC(void, 0x3B0410, void*)(this); }
};
SDK_ASSERT_SIZEOF(Creature, 0x3A0);
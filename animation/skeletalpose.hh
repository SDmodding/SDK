#pragma once

class SkeletalPose
{
public:
	int mBoneUpdateCount;
	__declspec(align(16)) UFG::qMatrix44 mRootMatrix44;
	hkQsTransformf mRootQsMatrix;
	u32 mIsRootDirty;
	u32 mCachedTransformChangeID;
	UFG::qVector3 mPoseAABBMin;
	UFG::qVector3 mPoseAABBMax;
	UFG::qSafePointer<UFG::SimComponent, UFG::TransformNodeComponent> mRootTransformNode;
	UFG::RigHandle mRigHandle;
	hkaPose* mHavokPose;

	/* Functions */

	bool HasPoseChanged() { return SDK_CALL_FUNC(bool, 0x1BBED0, void*)(this); }
	void Renormalize(bool syncedPose, bool skipScaleable) { SDK_CALL_FUNC(void, 0x1BBF50, void*, bool, bool)(this, syncedPose, skipScaleable); }
	void forceTeleport() { SDK_CALL_FUNC(void, 0x1BE810, void*)(this); }
	void syncTransformToRoot() { SDK_CALL_FUNC(void, 0x1BE8F0, void*)(this); }

	/* Get Functions */

	void GetPositionLS(int boneID, UFG::qMatrix44& matrixLS) { SDK_CALL_FUNC(void, 0x1BB790, void*, int, UFG::qMatrix44&)(this, boneID, matrixLS); }
	void GetPositionMS(int boneID, UFG::qMatrix44& matrixMS) { SDK_CALL_FUNC(void, 0x1BBA30, void*, int, UFG::qMatrix44&)(this, boneID, matrixMS); }
	void GetPositionMS_ReNormalize(int boneID, UFG::qMatrix44& matrixMS) { SDK_CALL_FUNC(void, 0x1BBA90, void*, int, UFG::qMatrix44&)(this, boneID, matrixMS); }
	void GetPositionRefS(int boneID, UFG::qMatrix44& matrixRS) { SDK_CALL_FUNC(void, 0x1BBB40, void*, int, UFG::qMatrix44&)(this, boneID, matrixRS); }
	void GetPositionWS(int boneID, UFG::qMatrix44& matrixWS) { SDK_CALL_FUNC(void, 0x1BBB90, void*, int, UFG::qMatrix44&)(this, boneID, matrixWS); }
	const hkQsTransformf& GetQsTransformLS(int boneID) { return SDK_CALL_FUNC(const hkQsTransformf&, 0x1BBD20, void*, int)(this, boneID); }
	const hkQsTransformf& GetRoot() { return SDK_CALL_FUNC(const hkQsTransformf&, 0x1BBD80, void*)(this); }
	void GetRootMatrix(UFG::qMatrix44& matrixRoot) { SDK_CALL_FUNC(void, 0x1BBDD0, void*, UFG::qMatrix44&)(this, matrixRoot); }
	const hkQsTransformf& GetTranslationMS(int boneID) { return SDK_CALL_FUNC(const hkQsTransformf&, 0x1BBD50, void*, int)(this, boneID); }
	void GetTranslationWS(int boneID, UFG::qVector3& translationWS) { SDK_CALL_FUNC(void, 0x1BBE10, void*, int, UFG::qVector3&)(this, boneID, translationWS); }

	/* Set Functions */

	void SetPositionLS(int boneID, const UFG::qMatrix44& matrixLS) { SDK_CALL_FUNC(void, 0x1BC5B0, void*, int, const UFG::qMatrix44&)(this, boneID, matrixLS); }
	void SetPositionMS(int boneID, const UFG::qMatrix44& matrixMS) { SDK_CALL_FUNC(void, 0x1BC940, void*, int, const UFG::qMatrix44&)(this, boneID, matrixMS); }
	void SetPositionMS_ReNormalize(int boneID, const UFG::qMatrix44& matrixMS) { SDK_CALL_FUNC(void, 0x1BCCD0, void*, int, const UFG::qMatrix44&)(this, boneID, matrixMS); }
	void SetPositionWS(int* boneID, const hkQsTransformf& xformWS, int count) { SDK_CALL_FUNC(void, 0x1BD620, void*, int*, const hkQsTransformf&, int)(this, boneID, xformWS, count); }
	void SetPositionWS(int boneID, const UFG::qMatrix44& matrixWS) { SDK_CALL_FUNC(void, 0x1BD0C0, void*, int, const UFG::qMatrix44&)(this, boneID, matrixWS); }
	void SetQsTransformLS(int boneID, const hkQsTransformf& matrixLS) { SDK_CALL_FUNC(void, 0x1BDBA0, void*, int, const hkQsTransformf&)(this, boneID, matrixLS); }
	void SetQsTransformMS(int boneID, const hkQsTransformf& transformMS) { SDK_CALL_FUNC(void, 0x1BDF10, void*, int, const hkQsTransformf&)(this, boneID, transformMS); }
	void SetRoot(UFG::qMatrix44& newRoot, bool forceTeleportEvent) { SDK_CALL_FUNC(void, 0x1BE2F0, void*, UFG::qMatrix44&, bool)(this, newRoot, forceTeleportEvent); }
	void SetRoot(const hkQsTransformf& newRoot, bool forceTeleportEvent) { SDK_CALL_FUNC(void, 0x1BE270, void*, const hkQsTransformf&, bool)(this, newRoot, forceTeleportEvent); }
	void SetRootTranslation(const UFG::qVector3& trans, bool forceTeleportEvent) { SDK_CALL_FUNC(void, 0x1BE360, void*, const UFG::qVector3&, bool)(this, trans, forceTeleportEvent); }
	void SetToRestPose() { SDK_CALL_FUNC(void, 0x1BE3F0, void*)(this); }
};
SDK_ASSERT_SIZEOF(SkeletalPose, 0x100);
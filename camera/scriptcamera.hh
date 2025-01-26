#pragma once

namespace UFG
{
	class ScriptCameraComponent : public GameCameraComponent, public qNode<ScriptCameraComponent>
	{
	public:
		enum { _TypeUID = 0x1E000085 };

		qSafePointer<Creature> mCameraCreature;
		int nCameraCreatureBone;
		qSafePointer<Creature> mTargetCreature;
		int nTargetCreatureBone;
		BaseCameraComponent* mPreviousCameraComponent;
		TransformNodeComponent* mTargetTransform;
		TransformNodeComponent* mCameraTransform;
		TransformNodeComponent* mNextCameraTransform;
		bool mDofSnapNext;
		Render::DepthOfField::Focus mDofParameters;
		HomerCubic<f32> mFov;
		HomerCubic<qVector3> mEye;
		HomerCubic<qVector3> mLook;
		qNoise<qVector3, f32> mEyeNoise;
		qNoise<qVector3, f32> mLookNoise;
		qVector3 mLookOffset;
		qVector3 mFollowTargetEyeOffset;
		f32 mEyeNoiseMagnitude;
		f32 mLookNoiseMagnitude;
		f32 mElapsedSeconds;
		f32 mTurnX;
		f32 mTurnY;
		f32 mLatitude;
		f32 mLongitude;
		bool mbScriptCameraOn;
		bool mbFollowTarget;
		bool mbFollowTargetEyeOffset;
		bool mbAttached;
		bool mbPanning;
		bool mbProfiling;
		bool mbHighlightOn;
		qSafePointer<SimObject> mHighlightedCharacter;
		bool bAllowWideAspectDisplay;

		/* Static Members */

		SDK_VINLINE qGlobalVar<bool, 0x23CF184> mbUserInputEnabled;

		/* Impl Functions */

		SDK_INLINE void EnableProfiling() { mbProfiling = true; }

		/* Functions */

		void DisableProfiling() { SDK_CALL_FUNC(void, 0x3C20A0, void*)(this); }
		void InitUserControlledCamera() { SDK_CALL_FUNC(void, 0x3C5D40, void*)(this); }
		void PanToTransform(TransformNodeComponent* pTNC, f32 duration, f32 fov) { SDK_CALL_FUNC(void, 0x3C7B80, void*, TransformNodeComponent*, f32, f32)(this, pTNC, duration, fov); }
		void ReleaseCamera(bool transitionOut) { SDK_CALL_FUNC(void, 0x3C84B0, void*, bool)(this, transitionOut); }
		void ResetDOF() { SDK_CALL_FUNC(void, 0x3C8CE0, void*)(this); }
		void SetCameraCreature(Creature* creature, int bone_id) { SDK_CALL_FUNC(void, 0x3C9830, void*, Creature*, int)(this, creature, bone_id); }
		void SetDOF(f32 focalDistance, f32 inFocusHalfRange, f32 nearBlendRange, f32 nearBlurRadius, f32 farBlendRange, f32 farBlurRadius, bool snap) {
			SDK_CALL_FUNC(void, 0x3CB030, void*, f32, f32, f32, f32, f32, f32, bool)(this, focalDistance, inFocusHalfRange, nearBlendRange, nearBlurRadius, farBlendRange, farBlurRadius, snap);
		}
		void SetDesiredEyeLook(const qVector3& eye, const qVector3& look, f32 duration, bool snap) {
			SDK_CALL_FUNC(void, 0x3CB090, void*, const qVector3&, const qVector3&, f32, bool)(this, eye, look, duration, snap);
		}
		void SetDurations(f32 duration) { SDK_CALL_FUNC(void, 0x3CC100, void*, f32)(this, duration); }
		void SetEyeAttachment(TransformNodeComponent* pTNC) { SDK_CALL_FUNC(void, 0x3CC400, void*, TransformNodeComponent*)(this, pTNC); }
		void SetEyeOffsetFromTarget(const qVector3& offset) { SDK_CALL_FUNC(void, 0x3CC480, void*, const qVector3&)(this, offset); }
		void SetTarget(TransformNodeComponent* pTNC) { SDK_CALL_FUNC(void, 0x3CD600, void*, TransformNodeComponent*)(this, pTNC); }
		void SwitchToScriptCam(TransformNodeComponent* pTNC, bool transitionIn, f32 fov) { SDK_CALL_FUNC(void, 0x3CE500, void*, TransformNodeComponent*, bool, f32)(this, pTNC, transitionIn, fov); }
	};
	SDK_ASSERT_SIZEOF(ScriptCameraComponent, 0x760);
}
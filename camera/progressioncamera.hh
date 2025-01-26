#pragma once

namespace UFG
{
	class ProgressionCameraComponent : public GameCameraComponent, public qNode<ProgressionCameraComponent>
	{
	public:
		enum { _TypeUID = 0x1E000015 };

		RebindingComponentHandle<TransformNodeComponent> mTransformNode;
		RebindingComponentHandle<CameraAnimationComponent> mAnimation;
		RebindingComponentHandle<CameraSubject> mTarget;
		bool bSnapProgress;
		bool bParamMonotonicallyIncreasing;
		f32 rParamWindowSize;
		f32 rParamDuration;
		HomerCubic<f32> mParamProgress;
		qVector3 vProgressMarkerA;
		qVector3 vProgressMarkerB;
		f32 mFov;
		int nEyeBone;
		int nLookBone;
		int nParamsBone;
		bool bTargetSpace;
		bool bMarkerRelative;
		bool bSingleBone;
		f32 mMotionblurMagnitude;
		Render::DepthOfField::Focus mDofParameters;
		qSafePointer<AnimationNode> mAnimationNode;

		/* Functions */

		AnimationNode* Play(const qSymbolUC& name, f32 start_time) { return SDK_CALL_FUNC(AnimationNode*, 0x3C7F30, void*, const qSymbolUC&, f32)(this, name, start_time); }
	};
	SDK_ASSERT_SIZEOF(ProgressionCameraComponent, 0x620);
}
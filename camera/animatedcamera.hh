#pragma once

namespace UFG
{
	class AnimatedCameraComponent : public GameCameraComponent, public qNode<AnimatedCameraComponent>
	{
	public:
		enum { _TypeUID = 0x1E00000D };

		RebindingComponentHandle<TransformNodeComponent> mTransformNode;
		RebindingComponentHandle<CameraAnimationComponent> mAnimation;
		RebindingComponentHandle<CameraSubject> mTarget;
		f32 mFov;
		int nEyeBone;
		int nLookBone;
		int nParamsBone;
		bool bTargetSpace;
		bool bMarkerRelative;
		bool bSingleBone;
		bool bAllowPostEffects;
		bool mAnimateParams;
		f32 mMotionblurMagnitude;
		Render::DepthOfField::Focus mDofParameters;
		qSafePointer<AnimationNode> mAnimationNode;

		/* Functions */

		AnimationNode* Play(const qSymbolUC& name, f32 start_time) { return SDK_CALL_FUNC(AnimationNode*, 0x3C7EB0, void*, const qSymbolUC&, f32)(this, name, start_time); }
		void SetDofParameters(f32 focal_distance, f32 focal_range, f32 near_radius, f32 near_range, f32 far_radius, f32 far_range) {
			SDK_CALL_FUNC(void, 0x3CC020, void*, f32, f32, f32, f32, f32, f32)(this, focal_distance, focal_range, near_radius, near_range, far_radius, far_range);
		}
	};
	SDK_ASSERT_SIZEOF(AnimatedCameraComponent, 0x5D0);
}
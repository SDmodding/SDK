#pragma once

namespace UFG
{
	class DebugCameraComponent : public BaseCameraComponent, public qNode<DebugCameraComponent>
	{
	public:
		enum { _TypeUID = 0x1E000003 };

		Controller* mController;
		BaseCameraComponent* mPreviousCameraComponent;
		bool mDebugCameraOn;
		bool mUserInputEnabled;
		f32 mFov;
		f32 mDutch;
		f32 mLatitude;
		f32 mLongitude;
		f32 mDesaturation;
		f32 mMotionBlurMagnitude;
		Render::DepthOfField::Focus mDofParameters;

		/* Static Functions */

		SDK_SINLINE DebugCameraComponent* Instance() { return SDK_VAR_GET(DebugCameraComponent*, 0x23CF1A8); }
	};
	SDK_ASSERT_SIZEOF(DebugCameraComponent, 0x350);
}
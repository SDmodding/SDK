#pragma once

namespace UFG
{
	class TurfCameraComponent : public BaseCameraComponent, public qNode<TurfCameraComponent>
	{
	public:
		enum { _TypeUID = 0x1E000101 };

		enum POV
		{
			POV_Turf,
			POV_RacketSelected,
			POV_RacketFocused
		};

		enum eCameraPitch
		{
			PITCH_NEUTRAL,
			PITCH_UP,
			PITCH_DOWN
		};

		enum eCameraRotation
		{
			ROT_0,
			ROT_90,
			ROT_180,
			ROT_270
		};

		qSymbol mCameraMarkerName;
		POV mPOV;
		eCameraRotation mRotation;
		eCameraPitch mPitch;
		f32 mRacketZoomParam;
		f32 mTurfRotateParam;
		__declspec(align(16)) qMatrix44 mTurfTransform;
		qMatrix44 mRacketTransform;
		qMatrix44 mOldTurfTransform;
		qMatrix44 mTurfCameraStart;
		qVector3 mTurfMidpoint;

		/* Functions */

		qMatrix44 InterpolateTransform(const qMatrix44& fromTrans, const qMatrix44& toTrans, f32 progress) {
			return SDK_CALL_FUNC(qMatrix44, 0x3C5DD0, void*, const qMatrix44&, const qMatrix44&, f32)(this, fromTrans, toTrans, progress);
		}
	};
	SDK_ASSERT_SIZEOF(TurfCameraComponent, 0x430);
}
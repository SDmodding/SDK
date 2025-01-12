#pragma once

namespace UFG
{
	class Camera
	{
	public:
		f32 mFOVOffset;
		f32 mMotionBlur;
		bool mMotionBlurIsTimeLimited;
		u64 mMotionBlurTimeLimit;
		f32 mDesaturation;
		Render::DepthOfField::Focus mDepthOfFieldFocus;
		__declspec(align(16)) qMatrix44 mView;
		qMatrix44 mTransformation;
		qMatrix44 mProjection;
		bool bUseOverrideMatrices;
		__declspec(align(16)) qMatrix44 mOverrideView;
		qMatrix44 mOverrideTrans;
		qMatrix44 mOverrideProj;
		qMatrix44 mPreviousView;
		qMatrix44 mPreviousTransformation;
		qVector3 mVelocity;

		/* Functions */

		f32 GetFarPlane() { return SDK_CALL_FUNC(f32, 0x318C0, void*)(this); }
		f32 GetNearPlane() { return SDK_CALL_FUNC(f32, 0x4FBC0, void*)(this); }
		void ApplyDutch(f32 radians) { SDK_CALL_FUNC(void, 0xB99F0, void*, f32)(this, radians); }
		qVector3 GetScreenCoord(const qVector3& world_pos, const qVector2& viewport_scale, bool* is_on_screen = 0) { return SDK_CALL_FUNC(qVector3, 0xB9B70, void*, const qVector3&, const qVector2&, bool*)(this, world_pos, viewport_scale, is_on_screen); }
		const qMatrix44& GetViewProjection() { return SDK_CALL_FUNC(const qMatrix44&, 0xB9C50, void*)(this); }
		const qMatrix44& GetViewWorld() { return SDK_CALL_FUNC(const qMatrix44&, 0xB9C70, void*)(this); }
		const qMatrix44& GetWorldView() { return SDK_CALL_FUNC(const qMatrix44&, 0xB9C90, void*)(this); }
		qVector3 ScreenToWorldRay(const qVector2& screen_pos, const qVector2& viewport_scale) { return SDK_CALL_FUNC(qVector3, 0xBA0B0, void*, const qVector2&, const qVector2&)(this, screen_pos, viewport_scale); }
		void SetFov(f32 fov) { SDK_CALL_FUNC(void, 0xBA5E0, void*, f32)(this, fov); }
		void SetLookAtMatrix(const qVector3& eye, const qVector3& look, const qVector3& up) { SDK_CALL_FUNC(void, 0xBA680, void*, const qVector3&, const qVector3&, const qVector3&)(this, eye, look, up); }
		void SetViewProjection(f32 fov, f32 aspect, f32 nearPlane, f32 farPlane, f32 xOffset, f32 yOffset, bool applyFovOffset) { SDK_CALL_FUNC(void, 0xBA6E0, void*, f32, f32, f32, f32, f32, f32, bool)(this, fov, aspect, nearPlane, farPlane, xOffset, yOffset, applyFovOffset); }
	};
	SDK_ASSERT_SIZEOF(Camera, 0x260);
}
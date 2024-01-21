#pragma once

namespace UFG
{
	class CCamera
	{
	public:
		float mFOVOffset;
		float mMotionBlur;
		bool mMotionBlurIsTimeLimited;

		UFG_PAD(0x7);

		unsigned __int64 mMotionBlurTimeLimit;
		float mDesaturation;

		UFG_PAD(0x24);
		//Render::DepthOfField::Focus mDepthOfFieldFocus;

		qMatrix44 mView;
		qMatrix44 mTransformation;
		qMatrix44 mProjection;
		bool bUseOverrideMatrices;

		UFG_PAD(0xF);

		qMatrix44 mOverrideView;
		qMatrix44 mOverrideTrans;
		qMatrix44 mOverrideProj;
		qMatrix44 mPreviousView;
		qMatrix44 mPreviousTransformation;
		qVector3 mVelocity;

		UFG_PAD(0x4);

		UFG_INLINE void GetScreenCoord(qVector3* p_Result, const qVector3& p_WorldPos, const qVector2& p_ViewportScale, bool* p_IsOnScreen)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, const qVector3&, const qVector2&, bool*)>(UFG_RVA(0xB9B70))(this, p_Result, p_WorldPos, p_ViewportScale, p_IsOnScreen);
		}

		UFG_INLINE void ScreenToWorldRay(qVector3* p_Result, const qVector2& p_ScreenPos, const qVector2& p_ViewportScale)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, const qVector2&, const qVector2&)>(UFG_RVA(0xBA0B0))(this, p_Result, p_ScreenPos, p_ViewportScale);
		}
	};
	UFG_ASSERT_CLASS(CCamera, 0x260);
}
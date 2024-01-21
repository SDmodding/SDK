#pragma once

namespace UFG
{
	class CScriptCameraComponent : public CGameCameraComponent
	{
	public:
		UFG_PAD(0x50);

		CBaseCameraComponent* mPreviousCameraComponent;
		CTransformNodeComponent* mTargetTransform;
		CTransformNodeComponent* mCameraTransform;
		CTransformNodeComponent* mNextCameraTransform;

		UFG_PAD(0x1E8);

		bool mbScriptCameraOn;
		bool mbFollowTarget;
		bool mbFollowTargetEyeOffset;
		bool mbAttached;
		bool mbPanning;
		bool mbProfiling;
		bool mbHighlightOn;
		qSafePointer<CSimObject> mHighlightedCharacter;
		bool bAllowWideAspectDisplay;

		UFG_INLINE void SetDesiredEyeLook(const qVector3& p_Eye, const qVector3& p_Look, float p_Duration = 0.f, bool p_Snap = true)
		{
			reinterpret_cast<void(__fastcall*)(void*, const qVector3&, const qVector3&, float, bool)>(UFG_RVA(0x3CB090))(this, p_Eye, p_Look, p_Duration, p_Snap);
		}

		UFG_INLINE void ReleaseCamera(bool p_TransitionOut)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x3C84B0))(this, p_TransitionOut);
		}

		UFG_INLINE void SwitchToScriptCam(bool p_TransitionIn, float p_Fov = 0.f)
		{
			reinterpret_cast<void(__fastcall*)(void*, CTransformNodeComponent*, bool, float)>(UFG_RVA(0x3CE500))(this, mTargetTransform, p_TransitionIn, p_Fov);
		}
	};
	UFG_ASSERT_CLASS(CScriptCameraComponent, 0x760);
}
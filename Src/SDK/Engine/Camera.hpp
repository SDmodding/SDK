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

		void GetScreenCoord(qVector3* result, qVector3* world_pos, qVector2* viewport_scale, bool* is_on_screen)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, qVector3*, qVector2*, bool*)>(UFG_RVA(0xB9B70))(this, result, world_pos, viewport_scale, is_on_screen);
		}
	};

	class CScriptCameraComponent;
	class CBaseCameraComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		CCamera mCamera;
		bool mActive;
		bool mCurrent;
		bool mResetEyeLook;
		bool mControllersEnabled;
		qVector3 mEyeCurr;
		qVector3 mLookCurr;
		qVector3 mUpCurr;
		qVector3 mEyeVelocity;
		qVector3 mLookVelocity;

		void Reset()
		{
			switch (m_TypeUID)
			{
			case FollowCameraComponent_TypeUID:
				reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x3C8890))(this); break;
			case ChaseCameraComponent_TypeUID:
				reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x3C8730))(this); break;
			}
		}

		void GotoAngleSnap(float radians, bool worldSpace)
		{
			switch (m_TypeUID)
			{
				case FollowCameraComponent_TypeUID: 
					reinterpret_cast<void(__fastcall*)(void*, float, bool)>(UFG_RVA(0x3C4B80))(this, radians, worldSpace); break;
				case ChaseCameraComponent_TypeUID: 
					reinterpret_cast<void(__fastcall*)(void*, float, bool)>(UFG_RVA(0x3C4990))(this, radians, worldSpace); break;
			}
		}

		CScriptCameraComponent* GetScriptCamera()
		{
			if (!m_pSimObject) return nullptr;

			return reinterpret_cast<CScriptCameraComponent*>(m_pSimObject->GetComponentOfType(ScriptCameraComponent_TypeUID));
		}
	};

	class CGameCameraComponent : public CBaseCameraComponent
	{
	public:
		UFG_PAD(0x1F0);
	};

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

		void SetDesiredEyeLook(UFG::qVector3* eye, UFG::qVector3* look, float duration = 0.f, bool snap = true)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::qVector3*, UFG::qVector3*, float, bool)>(UFG_RVA(0x3CB090))(this, eye, look, duration, snap);
		}

		void SetEyeWorld(UFG::qVector3* position, UFG::qVector3* velocity = nullptr)
		{
			if (!velocity)
			{
				UFG::qVector3 m_Vel;
				velocity = &m_Vel;
			}

			reinterpret_cast<void(__fastcall*)(void*, UFG::qVector3*, UFG::qVector3*)>(UFG_RVA(0x3CC8D0))(this, position, velocity);
		}

		void SetLookWorld(UFG::qVector3* position, UFG::qVector3* velocity = nullptr)
		{
			if (!velocity)
			{
				UFG::qVector3 m_Vel;
				velocity = &m_Vel;
			}

			reinterpret_cast<void(__fastcall*)(void*, UFG::qVector3*, UFG::qVector3*)>(UFG_RVA(0x3CCF00))(this, position, velocity);
		}

		void ReleaseCamera(bool transitionOut)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x3C84B0))(this, transitionOut);
		}

		void SwitchToScriptCam(bool transitionIn, float fov = 0.f)
		{
			reinterpret_cast<void(__fastcall*)(void*, CTransformNodeComponent*, bool, float)>(UFG_RVA(0x3CE500))(this, mTargetTransform, transitionIn, fov);
		}
	};
}
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

		void ScreenToWorldRay(qVector3* p_Result, qVector2* p_ScreenPos, qVector2* p_ViewportScale)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, qVector2*, qVector2*)>(UFG_RVA(0xBA0B0))(this, p_Result, p_ScreenPos, p_ViewportScale);
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

		~CBaseCameraComponent() { UFG_VCall<0, void>(this); }
		const char* GetTypeName() { return UFG_VCall<1, const char*>(this); }
		uint32_t GetTypeSize() { return UFG_VCall<2, uint32_t>(this); }
		void* GetDesc() { return UFG_VCall<3, void*>(this); }
		const char* GetDebugTypeName() { return UFG_VCall<4, const char*>(this); }
		void Suspend() { UFG_VCall<8, void>(this); }
		void Restore() { UFG_VCall<9, void>(this); }
		void Reset() { UFG_VCall<14, void>(this); }
		void Update(float p_TimeDelta) { UFG_VCall<15, void>(this, p_TimeDelta); };
		void EnableControllers(bool p_Enable) { UFG_VCall<18, void>(this, p_Enable); }
		float GetFOV() { return UFG_VCall<19, float>(this); }
		void SetActive(bool p_Enable) { UFG_VCall<20, void>(this, p_Enable); }
		bool IsActive() { return UFG_VCall<21, bool>(this); }
		void SetCurrent(bool p_Enable) { UFG_VCall<22, void>(this, p_Enable); }
		float GetFOVRadians() { return UFG_VCall<23, float>(this); }
		void SetFOVRadians(float p_FOV, float p_FOVVelocity) { UFG_VCall<24, void>(this, p_FOV, p_FOVVelocity); }
		void GetEyeWorld(qVector3* p_Position, qVector3* p_Velocity) { UFG_VCall<25, void>(this, p_Position, p_Velocity); }
		void GetLookWorld(qVector3* p_Position, qVector3* p_Velocity) { UFG_VCall<26, void>(this, p_Position, p_Velocity); }
		void SetEyeWorld(qVector3* p_Position, qVector3* p_Velocity) { UFG_VCall<27, void>(this, p_Position, p_Velocity); }
		void SetLookWorld(qVector3* p_Position, qVector3* p_Velocity) { UFG_VCall<28, void>(this, p_Position, p_Velocity); }
		void TransitionFrom(CBaseCameraComponent* p_Camera, bool p_WithVelocity) { UFG_VCall<29, void>(this, p_Camera, p_WithVelocity); }

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

	class CFollowCameraComponent : public CGameCameraComponent
	{
	public:
		UFG_PAD(0xD4);

		float mDofFarFocalDist;

		RebindingComponentHandle<CCharacterSubjectComponent> mTarget;
		RebindingComponentHandle<void> mEnemyTarget;
		uint32_t mType;
		uint32_t mContext;
		uint32_t mPreviousType;
		uint32_t mPreviousContext;

		UFG_PAD(0x1438);

		qMatrix44 mTargetWorld;

		void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x3C8890))(this);
		}

		void GotoAngleSnap(float p_Radians, bool p_WorldSpace)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, bool)>(UFG_RVA(0x3C4B80))(this, p_Radians, p_WorldSpace);
		}

		void SetTarget(CSimObject* m_Target)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x3CD570))(this, m_Target);
		}
	};

	class CChaseCameraComponent : public CGameCameraComponent
	{
	public:
		void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x3C8730))(this);
		}

		void GotoAngleSnap(float p_Radians, bool p_WorldSpace)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, bool)>(UFG_RVA(0x3C4990))(this, p_Radians, p_WorldSpace);
		}

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
		bool mbFollowTarget;
		bool mbFollowTargetEyeOffset;
		bool mbAttached;
		bool mbPanning;
		bool mbProfiling;
		bool mbHighlightOn;
		qSafePointer<CSimObject> mHighlightedCharacter;
		bool bAllowWideAspectDisplay;

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
	UFG_ASSERT_CLASS(CScriptCameraComponent, 0x760);
}
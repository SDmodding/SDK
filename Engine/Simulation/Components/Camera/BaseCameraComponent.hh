#pragma once

namespace UFG
{
	//============================================================================

	class CScriptCameraComponent;

	//============================================================================

	class CBaseCameraComponent : public SimComponent, public qNode<CBaseCameraComponent>
	{
	public:
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

		UFG_INLINE ~CBaseCameraComponent()
		{ 
			UFG_VCall<0, void>(this); 
		}

		UFG_INLINE const char* GetTypeName()
		{ 
			return UFG_VCall<1, const char*>(this); 
		}

		UFG_INLINE uint32_t GetTypeSize()
		{ 
			return UFG_VCall<2, uint32_t>(this); 
		}

		UFG_INLINE void* GetDesc()
		{ 
			return UFG_VCall<3, void*>(this); 
		}

		UFG_INLINE const char* GetDebugTypeName()
		{ 
			return UFG_VCall<4, const char*>(this); 
		}

		UFG_INLINE void Suspend()
		{ 
			UFG_VCall<8, void>(this); 
		}

		UFG_INLINE void Restore()
		{ 
			UFG_VCall<9, void>(this); 
		}

		UFG_INLINE void Reset()
		{ 
			UFG_VCall<14, void>(this); 
		}

		UFG_INLINE void Update(float p_TimeDelta)
		{ 
			UFG_VCall<15, void>(this, p_TimeDelta); 
		};

		UFG_INLINE void EnableControllers(bool p_Enable)
		{ 
			UFG_VCall<18, void>(this, p_Enable); 
		}

		UFG_INLINE float GetFOV()
		{ 
			return UFG_VCall<19, float>(this); 
		}

		UFG_INLINE void SetActive(bool p_Enable)
		{ 
			UFG_VCall<20, void>(this, p_Enable); }


		UFG_INLINE bool IsActive()
		{ 
			return UFG_VCall<21, bool>(this); 
		}

		UFG_INLINE void SetCurrent(bool p_Enable)
		{ 
			UFG_VCall<22, void>(this, p_Enable); 
		}

		UFG_INLINE float GetFOVRadians()
		{ 
			return UFG_VCall<23, float>(this); 
		}

		UFG_INLINE void SetFOVRadians(float p_FOV, float p_FOVVelocity)
		{ 
			UFG_VCall<24, void>(this, p_FOV, p_FOVVelocity);
		}

		UFG_INLINE void GetEyeWorld(qVector3* p_Position, qVector3* p_Velocity)
		{ 
			UFG_VCall<25, void>(this, p_Position, p_Velocity); 
		}

		UFG_INLINE void GetLookWorld(qVector3* p_Position, qVector3* p_Velocity)
		{ 
			UFG_VCall<26, void>(this, p_Position, p_Velocity); 
		}

		UFG_INLINE void SetEyeWorld(const qVector3& p_Position, const qVector3& p_Velocity)
		{ 
			UFG_VCall<27, void>(this, p_Position, p_Velocity); 
		}

		UFG_INLINE void SetLookWorld(const qVector3& p_Position, const qVector3& p_Velocity)
		{ 
			UFG_VCall<28, void>(this, p_Position, p_Velocity); 
		}

		UFG_INLINE void TransitionFrom(CBaseCameraComponent* p_Camera, bool p_WithVelocity)
		{ 
			UFG_VCall<29, void>(this, p_Camera, p_WithVelocity); 
		}

		UFG_INLINE CScriptCameraComponent* GetScriptCamera()
		{
			if (!m_pSimObject) {
				return nullptr;
			}

			return m_pSimObject->GetComponentOfType<CScriptCameraComponent>(ScriptCameraComponent_TypeUID);
		}
	};
	UFG_ASSERT_CLASS(CBaseCameraComponent, 0x2F0);
}
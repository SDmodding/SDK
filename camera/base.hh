#pragma once

namespace UFG
{
	class BaseCameraComponent : public SimComponent, public qNode<BaseCameraComponent, BaseCameraComponent>
	{
	public:
		enum { _TypeUID = 0x1E000001 };

		Camera mCamera;
		bool mActive;
		bool mCurrent;
		bool mResetEyeLook;
		bool mControllersEnabled;
		qVector3 mEyeCurr;
		qVector3 mLookCurr;
		qVector3 mUpCurr;
		qVector3 mEyeVelocity;
		qVector3 mLookVelocity;

		/* Virtual Functions */

		virtual void Reset() = 0;
		virtual void Update(float delta_seconds) = 0;
		virtual void SetTarget(SimObject* target) = 0;
		virtual SimObject* GetTarget() = 0;
		virtual void EnableControllers(bool enable) = 0;
		virtual float GetFov() = 0;
		virtual void SetActive(bool active) = 0;
		virtual bool IsActive() = 0;
		virtual void SetCurrent(bool current) = 0;
		virtual void GetFovRadians(float* fov, float* velocity) = 0;
		virtual void SetFovRadians(float fov, float velocity) = 0;
		virtual void GetEyeWorld(qVector3& position, qVector3& velocity) = 0;
		virtual void GetLookWorld(qVector3& position, qVector3& velocity) = 0;
		virtual void SetEyeWorld(const qVector3& position, const qVector3& velocity) = 0;
		virtual void SetLookWorld(const qVector3& position, const qVector3& velocity) = 0;
		virtual void TransitionFrom(BaseCameraComponent* camera, bool withVelocity) = 0;

		/* Functions */

		void SetEyeLookUp(f32 dt, const qVector3& eye, const qVector3& look, const qVector3& up) {
			SDK_CALL_FUNC(void, 0xBA2E0, void*, f32, const qVector3&, const qVector3&, const qVector3&)(this, dt, eye, look, up); 
		}
	};
	SDK_ASSERT_SIZEOF(BaseCameraComponent, 0x2F0);
}
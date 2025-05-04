#pragma once

namespace UFG
{
	class NavSteerData
	{
	public:
		qVector3 m_vDesiredDirection;
		qVector3 m_vClampedDirection;
		qVector3 m_vLocalDirection;
		f32 m_fLocalSpeed;
	};

	class NavModuleLocal
	{
	public:
		NavComponent* m_navComponent;
		NavSteerData m_steerData;
		__declspec(align(16)) NavWaypoint m_adjustedWaypoint;
		eCollisionAvoidanceType m_avoidanceType;
		f32 m_fAdjustedSpeed;
		TestDeferrer m_deferrer;

		/* Virtual Functions */

		virtual ~NavModuleLocal() = 0;
		virtual void Update(f32 dt) = 0;
		virtual void UpdateSteering(f32 dt) = 0;
		virtual void Reset() = 0;
		virtual void Shutdown() = 0;
		virtual void OnPathChanged() = 0;
		virtual f32 GetTurningRadius(f32 fSpeed) = 0;
		virtual f32 GetMaxSpeedForRadius(f32 fSpeed) = 0;
		virtual void SetCollisionAvoidanceType(eCollisionAvoidanceType type) = 0;
		virtual eCollisionAvoidanceType GetCollisionAvoidanceType() = 0;
		virtual bool IsStuck() = 0;

		/* Functions */

		bool HasInput() { return SDK_CALL_FUNC(bool, 0x264E80, void*)(this); }
		bool IsAvoidanceEnabled() { return SDK_CALL_FUNC(bool, 0x265260, void*)(this); }
		void UpdateAdjustedWaypointAndSpeed(f32 dt) { SDK_CALL_FUNC(void, 0x266A20, void*, f32)(this, dt); }
	};
}
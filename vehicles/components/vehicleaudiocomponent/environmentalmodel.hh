#pragma once

namespace UFG
{
	class EnvironmentalModel
	{
	public:
		VehicleAudioComponent* m_pVehAudComponent;
		AudioEventController m_ecSkidInit;
		AudioEventController m_ecForceStopSkid;
		qVector3 m_lastPosOnStairs;
		f32 m_hangTime;
		bool m_onStairs;
		RateLimitedFloat m_skidAngle;
		RateLimitedFloat m_skidStrength;
		RateLimitedFloat m_burnoutAmount;
		u32 m_skidEvent;

		/* Functions */

		void HandleJump() { SDK_CALL_FUNC(void, 0x67C8A0, void*)(this); }
		void HandleSkids(f32 deltaTime) { SDK_CALL_FUNC(void, 0x67CB80, void*, f32)(this, deltaTime); }
		void HandleStairs() { SDK_CALL_FUNC(void, 0x67CF80, void*)(this); }
		void StartSkid() { SDK_CALL_FUNC(void, 0x68C430, void*)(this); }
		void Update(f32 delta_sec) { SDK_CALL_FUNC(void, 0x6910E0, void*, f32)(this, delta_sec); }
		bool WheelsOnStairs() { return SDK_CALL_FUNC(bool, 0x69B9D0, void*)(this); }
	};
}
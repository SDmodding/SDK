#pragma once

namespace UFG
{
	class DamageModel
	{
	public:
		VehicleAudioComponent* m_pVehAudComponent;
		PhysicsMoverInterface* m_mover;
		TransformNodeComponent* m_transformNode;
		AudioEventController m_ecEngineSteam;
		AudioEventController m_ecEngineClank;
		AudioEventController m_ecDrivingOnRim;
		qVector3 m_lastTireFlapPos;
		f32 m_lastEngineDamage;
		bool m_tireBlown[4];
		bool m_engineBlown;

		/* Functions */

		void HandleDamagedEngine() { SDK_CALL_FUNC(void, 0x67BC00, void*)(this); }
		void HandleDamagedTires() { SDK_CALL_FUNC(void, 0x67BE60, void*)(this); }
	};
}
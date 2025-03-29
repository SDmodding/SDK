#pragma once

namespace UFG
{
	class DriverReactions
	{
	public:
		enum eVocalDriverReactionType
		{
			eVocalDriverReactionType_Default = 0x0,
			eVocalDriverReactionType_TrafficJam = 0x40C1BD74,	// ?
			eVocalDriverReactionType_BadDriver = 0xE98D96FF,	// ?
			eVocalDriverReactionType_Max = 0xE98D9700			// ?
		};

		VehicleAudioComponent* m_pVehAudComponent;
		f32 m_reactionCooldownTimer;
		u32 m_numReactions;

		/* Functions */

		void OnCollision() { SDK_CALL_FUNC(void, 0x683F00, void*)(this); }
		void PlayCarAlarm() { SDK_CALL_FUNC(void, 0x686CB0, void*)(this); }
		void YellReactionBase(eVocalDriverReactionType reaction) { SDK_CALL_FUNC(void, 0x69BF90, void*, eVocalDriverReactionType)(this, reaction); }
	};
}
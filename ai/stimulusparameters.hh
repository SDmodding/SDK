#pragma once

namespace UFG
{
	enum eStimulusEmissionType
	{
		eSTIMULUS_EMISSION_ONE_OFF,
		eSTIMULUS_EMISSION_CONTINUOUS,
		NUM_STIMULUS_EMISSION_TYPES,
		eSTIMULUS_EMISSION_NONE = -1,
	};

	class StimulusParameters
	{
	public:
		qVector3 m_StimulusProducerOffset;
		eStimulusEmissionType m_StimulusEmissionType;
		f32 m_MaxStimulusDuration;
		f32 m_EmitUntilSpeedLessThan;
	};
}
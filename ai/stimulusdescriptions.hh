#pragma once

namespace UFG
{
	enum eStimulusType;

	enum eStimulusHandlerType
	{
		eSTIMULUS_HANDLER_NORMAL,
		eSTIMULUS_HANDLER_DANGEROUS_EVENT,
		eSTIMULUS_HANDLER_CALC_TIME_TO_IMPACT,
		NUM_STIMULUS_HANDLER_TYPES,
		eSTIMULUS_HANDLER_NONE = -1,
	};

	class StimulusDescription
	{
	public:
		eStimulusType m_Type;
		const char* m_Name;
		u32 m_NameHash;
		const char* m_Desc;
		f32 m_MinPerceptionRadiusMetres;
		f32 m_PerceptionRadiusSeconds;
		f32 m_PerceptionAngleCosine;
		f32 m_EmitterHorizontalAngleCosine;
		f32 m_EmitterVerticalAngleCosine;
		f32 m_MinTimeBetweenUpdates;
		f32 m_DangerRadius;
		f32 m_MaxLateralDistanceForCalcTimeToImpact;
		bool m_UseAimDirection;
		eStimulusHandlerType m_StimulusHandlerType;
	};
}
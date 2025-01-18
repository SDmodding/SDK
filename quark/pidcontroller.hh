#pragma once

namespace UFG
{
	class qPidParameterBlock
	{
	public:
		f32 m_P_Coefficient;
		f32 m_I_Coefficient;
		f32 m_D_Coefficient;
		f32 m_ProportionalTimeSpan;
		f32 m_DerivativeTimeSpan;
		f32 m_IntegralTimeSpan;
	};

	class qPidControllerCore
	{
	public:
		qPidParameterBlock* m_Parameters;
		qAverageWindow<f32> m_P_Term;
		qAverageWindow<f32> m_I_Term;
		qAverageWindow<f32> m_D_Term;
	};

	class qPidController : public qPidControllerCore
	{
	public:
		qPidParameterBlock m_ParameterBlock;
	};
}
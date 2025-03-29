#pragma once

namespace UFG
{
	class VehicleAudioSubTypeParameters
	{
	public:
		EngineCurve* m_engineCurve;
		EngineCurve* m_parentEngineCurve;
		RateLimitedFloat m_rateLimitedSpeed;
		qPropertySet* mpPropertySet;

		/* Functions */

		void InitFromPropertySet(qPropertySet* ps) { SDK_CALL_FUNC(void, 0x67DFD0, void*, qPropertySet*)(this, ps); }
	};

	class VehicleAudioParameters : public qNodeRB<VehicleAudioParameters>
	{
	public:
		VehicleAudioSubTypeParameters m_playerParameters;
		VehicleAudioSubTypeParameters m_aiParameters;
		VehicleAudioSubTypeParameters m_trafficParameters;
		qPropertySet* m_pPropertySet;
		qSymbol m_ParametersTableName;
		u32 m_uRefCount;

		/* Static Functions */

		// Creates a new instance if one doesn’t already exist!
		SDK_SINLINE VehicleAudioParameters* GrabParametersInstance(const qSymbol& parametersTableName) {
			return SDK_CALL_FUNC(VehicleAudioParameters*, 0x67BAA0, const qSymbol&)(parametersTableName);
		}

		SDK_SINLINE void SetRLFFromPropertySet(RateLimitedFloat* rlf, qPropertySet* pSet) { SDK_CALL_FUNC(void, 0x68AF70, RateLimitedFloat*, qPropertySet*)(rlf, pSet); }

		/* Functions */

	};
}
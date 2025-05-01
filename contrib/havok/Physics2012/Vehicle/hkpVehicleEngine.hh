#pragma once

class hkpVehicleEngine : public hkReferencedObject
{
public:
	struct EngineOutput
	{
		f32 m_torque;
		f32 m_rpm;
	};

	//virtual void calcEngineInfo(const f32 deltaTime, const hkpVehicleInstance* vehicle, const hkpVehicleDriverInput::FilteredDriverInputOutput& FilteredDriverInputOutput, const hkpVehicleTransmission::TransmissionOutput& TransmissionOutput, EngineOutput& engineOutput) = 0;
};

class hkpVehicleDefaultEngine : public hkpVehicleEngine
{
public:
	f32 m_minRPM;
	f32 m_optRPM;
	f32 m_maxRPM;
	f32 m_maxTorque;
	f32 m_torqueFactorAtMinRPM;
	f32 m_torqueFactorAtMaxRPM;
	f32 m_resistanceFactorAtMinRPM;
	f32 m_resistanceFactorAtOptRPM;
	f32 m_resistanceFactorAtMaxRPM;
	f32 m_clutchSlipRPM;
};
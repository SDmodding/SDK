#pragma once

class hkpVehicleEngine : public hkReferencedObject
{
public:
};

class hkpVehicleDefaultEngine : public hkpVehicleEngine
{
public:
	/// The min RPM of the engine.
	float m_minRPM;

	/// The optimum RPM, where the gross torque of the engine is maximal.
	float m_optRPM;

	/// The max RPM the engine can reach.
	float m_maxRPM;

	/// The maximum gross torque the engine can supply at the optimum RPM.
	float m_maxTorque;

	/// Defines the gross torque at the min rpm as a factor to the torque at optimal RPM.
	float m_torqueFactorAtMinRPM;

	/// Defines the gross torque at the max rpm as a factor to the torque at optimal RPM.
	float m_torqueFactorAtMaxRPM;

	/// Defines the engine resistance torque at the min rpm as a factor to the torque at optimal RPM.
	float m_resistanceFactorAtMinRPM;

	/// Defines the engine resistance torque at the opt rpm as a factor to the torque at optimal RPM.
	float m_resistanceFactorAtOptRPM;

	/// Defines the engine resistance torque at the max rpm as a factor to the torque at optimal RPM.
	float m_resistanceFactorAtMaxRPM;

	/// An extra RPM for the motor in case the clutch is slipping at very low speeds.
	float m_clutchSlipRPM;
};
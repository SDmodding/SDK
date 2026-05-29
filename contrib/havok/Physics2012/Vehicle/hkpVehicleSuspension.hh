#pragma once

class hkpVehicleSuspension : public hkReferencedObject
{
public:
	///  Per wheel parameters
	struct SuspensionWheelParameters
	{
		/// A point INSIDE the chassis to which the wheel suspension is attached.
		hkVector4 m_hardpointChassisSpace;

		/// The suspension direction (in Chassis Space).
		hkVector4 m_directionChassisSpace;

		/// The suspension length at rest i.e., the maximum distance from the hardpoint to
		/// the wheel center.
		f32 m_length;
	};

	/// Suspension parameters for each wheel.
	hkArray<SuspensionWheelParameters> m_wheelParams;
};

class hkpVehicleDefaultSuspension : public hkpVehicleSuspension
{
public:
	/// A struct containing all the wheel spring suspension parameters.
	struct WheelSpringSuspensionParameters
	{
		/// The strength [N/m] of the suspension at each wheel.
		f32 m_strength;

		/// The damping force [N/(m/sec)] of the suspension at each wheel.
		f32 m_dampingCompression;

		/// The damping force [N/(m/sec)] of the suspension at each wheel.
		f32 m_dampingRelaxation;
	};

	/// Suspension wheel parameters for each wheel.
	hkArray<WheelSpringSuspensionParameters> m_wheelSpringParams;
};
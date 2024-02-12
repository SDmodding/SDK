#pragma once

class hkpVehicleSuspension : public hkReferencedObject
{
public:
	struct SuspensionWheelParameters
	{
		/// A point INSIDE the chassis to which the wheel suspension is attached.
		hkVector4f m_hardpointChassisSpace;

		/// The suspension direction (in Chassis Space).
		hkVector4f m_directionChassisSpace;

		/// The suspension length at rest i.e., the maximum distance from the hardpoint to the wheel center.
		float m_length;
	};
	hkArray<SuspensionWheelParameters> m_wheelParams;
};
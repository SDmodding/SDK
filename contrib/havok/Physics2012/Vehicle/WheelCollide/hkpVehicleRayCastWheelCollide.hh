#pragma once

class hkpVehicleRayCastWheelCollide : public hkpVehicleWheelCollide
{
public:
	u32 m_wheelCollisionFilterInfo;
	hkpAabbPhantom* m_phantom;
	qProxy<hkpRejectChassisListener> m_rejectRayChassisListener;
};
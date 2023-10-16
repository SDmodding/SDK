#pragma once

class hkpVehicleWheelCollide : public hkReferencedObject
{
public:
	bool m_alreadyUsed;

	enum WheelCollideType : uint8_t
	{
		INVALID_WHEEL_COLLIDE = 0x0,
		RAY_CAST_WHEEL_COLLIDE = 0x1,
		LINEAR_CAST_WHEEL_COLLIDE = 0x2,
		USER_WHEEL_COLLIDE1 = 0x3,
		USER_WHEEL_COLLIDE2 = 0x4,
		USER_WHEEL_COLLIDE3 = 0x5,
		USER_WHEEL_COLLIDE4 = 0x6,
		USER_WHEEL_COLLIDE5 = 0x7,
	};
	WheelCollideType m_type;
};
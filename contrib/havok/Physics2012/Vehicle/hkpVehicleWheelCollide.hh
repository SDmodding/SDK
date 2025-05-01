#pragma once

class hkpVehicleWheelCollide : public hkReferencedObject
{
public:
	enum WheelCollideType
	{
		INVALID_WHEEL_COLLIDE,
		RAY_CAST_WHEEL_COLLIDE,
		LINEAR_CAST_WHEEL_COLLIDE,
		USER_WHEEL_COLLIDE1,
		USER_WHEEL_COLLIDE2,
		USER_WHEEL_COLLIDE3,
		USER_WHEEL_COLLIDE4,
		USER_WHEEL_COLLIDE5
	};

	hkBool m_alreadyUsed;
	hkEnum<WheelCollideType, u8> m_type;
};
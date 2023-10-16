#pragma once

class hkpVehicleBrake : public hkReferencedObject
{
public:
};

class hkpVehicleDefaultBrake : public hkpVehicleBrake
{
public:
	struct WheelBrakingProperties
	{
		/// The maximum torque the wheel can apply when braking. Increasing m_wheelsMass and
		/// m_wheelsMaxBrakingTorque for each wheel allows the vehicle to brake harder.
		float m_maxBreakingTorque;

		/// The minimum amount of braking from the driver that could cause the wheel to block (range [0..1])
		float m_minPedalInputToBlock;

		/// True if the particular wheel is connected to handbrake (locks when handbrake is on).
		bool m_isConnectedToHandbrake;
	};
	hkArray<WheelBrakingProperties> m_wheelBrakingProperties;

	/// The time (in secs) after which, if the user applies enough brake input, the wheel will block.
	float m_wheelsMinTimeToBlock;
};
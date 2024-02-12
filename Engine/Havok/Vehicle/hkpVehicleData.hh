#pragma once

class hkpVehicleData : public hkReferencedObject
{
public:
	/// The gravity direction used by the vehicle simulation.
	hkVector4f m_gravity;

	/// The number of wheels in the vehicle.
	char m_numWheels;

	/// The local coordinate system of the chassis. The first column is the 'up' direction of
	/// the vehicle, the second column is the 'forward' direction and the third column is perpendicular
	/// to both. Positive rotations about the third column correspond to the wheel motion when going
	/// forward. This direction affects gear shifting, braking and accelerating.
	hkRotationf m_chassisOrientation;

	/// Scales the torques applied by the simulation at the roll axis by the given factor.
	float m_torqueRollFactor;

	/// Scales the torques applied by the simulation at the pitch axis by the given factor.
	float m_torquePitchFactor;

	/// Scales the torques applied by the simulation at the yaw axis by the given factor.
	float m_torqueYawFactor;

	/// An extra torque which is applied to the car when steering is pointing left or right.
	float m_extraTorqueFactor;

	/// To avoid sliding at slow speeds or when the handbrake is turned on, we
	/// introduced a positional friction model (since Havok 2.2.1) into the vehicle
	/// friction solver. This extra friction is particular useful for slow driving
	/// cars. To avoid letting this friction influence fast cars, you can set
	/// maxVelocityForPositionalFriction to the maximum velocity, up to which you want
	/// this extra algorithm to be activated. Defines up to which speed the positional
	/// friction model will be used.
	float m_maxVelocityForPositionalFriction;

	/// The rotation inertia in yaw direction for a car of the mass 1.0f kilo.
	float m_chassisUnitInertiaYaw;

	/// The rotation inertia in roll direction for a car of the mass 1.0f kilo.
	float m_chassisUnitInertiaRoll;

	/// The rotation inertia in pitch direction for a car of the mass 1.0f kilo.
	float m_chassisUnitInertiaPitch;

	/// Specifies how the effect of dynamic load distribution is averaged with static
	/// load distribution. A value of 0.0f doesn't do any averaging (dynamic load
	/// distribution is fully taken into account). A value of 1.0f doesn't take
	/// dynamic load distribution, and the car behaves always as if it was in static
	/// load distribution. Values between 0.0f and 1.0f give a certain amount of both.
	float m_frictionEqualizer;

	/// Change this value to clip the normal in suspension force calculations. In
	/// particular, when mounting a curb, the raycast vehicle calculations can produce
	/// large impulses as the rays hit the face of the step, causing the vehicle to
	/// spin around its up-axis. Setting this value to 0.2f produces considerably more
	/// stability.
	float m_normalClippingAngleCos;

	/// Limits the mass ratio between the chassis and any dynamic body the vehicle is driving over.
	/// This prevents small objects from shooting away from an accelerating vehicle.
	float m_maxFrictionSolverMassRatio; // +default(30.0)

	struct WheelComponentParams
	{
		float m_radius;
		float m_mass;
		float m_width;
		float m_friction;
		float m_viscosityFriction;
		float m_maxFriction;
		float m_slipAngle;
		float m_forceFeedbackMultiplier;
		float m_maxContactBodyAcceleration;
		char m_axle;
	};
	hkArray<WheelComponentParams> m_wheelParams;
	hkArray<int8_t> m_numWheelsPerAxle;

	/// The inertia used for friction calculation.
	hkVector4f m_chassisFrictionInertiaInvDiag;

	/// The vehicleData can be shared between multiple vehicles, so it should be initialized only once.
	bool m_alreadyInitialised;
};
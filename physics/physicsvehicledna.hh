#pragma once

namespace UFG
{
	class BaseVehiclePhysicsDef : public qReflectObjectType<BaseVehiclePhysicsDef>
	{
	public:
		struct SearchNode : qNodeRB<BaseVehiclePhysicsDef::SearchNode>
		{
			u64 dnaGuid;
		};

		qReflectString chassis_physicsProperties;
		u32 numWheels;
		f32 mass;
		f32 collision_friction;
		f32 collision_restitution;
		f32 highSpeedGovernor;
		f32 reverseSpeedGovernor;
		f32 superStop_Drag;
		f32 other_airSteerYawRate;
		f32 other_verticalVelocityDampingUp;
		f32 other_verticalVelocityDampingDown;
		f32 rollStability;
		f32 pitchStability;
		f32 dollarValue;
		f32 steering_SensitivityLo;
		f32 steering_SensitivityHi;
		f32 steering_SensitivityMinSpeed;
		f32 steering_SensitivityMaxSpeed;
		f32 steering_SteeringModelExponent;
		i8 pad[8];
	};

	class BoatPhysicsDef : public qReflectObjectType<BoatPhysicsDef, BaseVehiclePhysicsDef>
	{
	public:
		qVector3 pontoon0;
		qVector3 pontoon1;
		qVector3 pontoon2;
		qVector3 pontoon3;
		f32 rudderForceMultiplier;
		f32 rudderOffsetX;
		f32 rudderOffsetZ;
		f32 keelTorque;
		f32 maxRudderAngle;
		f32 maxEngineThrust;
		f32 engineThrustAngle;
		f32 viscousDrag;
		f32 viscousDrag2;
		f32 quadraticDragLateralVelocityLimit;
		f32 torqueDamping;
		f32 torqueDampingBowScale;
		f32 leanFactor;
		f32 COMShift;
		f32 bowThrusterCutoffSpeed;
		f32 bowThrusterPower;
		f32 bowThrusterOffsetX;
		f32 bowThrusterOffsetZ;
		f32 pontoon0Buoyancy;
		f32 pontoon1Buoyancy;
		f32 pontoon2Buoyancy;
		f32 pontoon3Buoyancy;
		f32 pontoon0DragZ;
		f32 pontoon1DragZ;
		f32 pontoon2DragZ;
		f32 pontoon3DragZ;
	};

	class WheeledVehiclePhysicsDef : public qReflectObjectType<WheeledVehiclePhysicsDef, BaseVehiclePhysicsDef>
	{
	public:
		qReflectArray<float> torqueTable;
		qReflectArray<float> drivetrain_gearRatioTable;
		qReflectArray<float> drivetrain_upshiftTable;
		qReflectArray<float> drivetrain_downshiftTable;
		qVector3 suspension_hardpointOffsetFront;
		qVector3 suspension_hardpointOffsetRear;
		f32 engine_clutchSlipRPM;
		f32 drivetrain_downshiftRPM;
		f32 drivetrain_upshiftRPM;
		f32 drivetrain_clutchDelayTime;
		f32 drivetrain_gearRatio1;
		f32 drivetrain_gearRatio2;
		f32 drivetrain_gearRatio3;
		f32 drivetrain_gearRatio4;
		f32 drivetrain_gearRatio5;
		f32 drivetrain_reverseGearRatio;
		f32 drivetrain_finalDriveRatio;
		f32 engine_minRPM;
		f32 engine_optRPM;
		f32 engine_maxRPM;
		f32 engine_maxTorque;
		f32 engine_torqueFactorAtMinRPM;
		f32 engine_torqueFactorAtMaxRPM;
		f32 engine_resistanceMin;
		f32 engine_resistanceMax;
		f32 engine_resistanceMinSpeed;
		f32 engine_resistanceMaxSpeed;
		f32 suspension_frontSpringLength;
		f32 suspension_rearSpringLength;
		f32 suspension_frontSpringRate;
		f32 suspension_rearSpringRate;
		f32 suspension_frontShockDampingCompression;
		f32 suspension_rearShockDampingCompression;
		f32 suspension_frontShockDampingExtension;
		f32 suspension_rearShockDampingExtension;
		f32 suspension_frontUpTravelLimit;
		f32 suspension_rearUpTravelLimit;
		f32 suspension_frontDownTravelLimit;
		f32 suspension_rearDownTravelLimit;
		f32 suspension_angle_front;
		f32 suspension_angle_rear;
		f32 brakes_maxTorqueFront;
		f32 brakes_maxTorqueRear;
		f32 drivetrain_frontWheelTorqueRatio;
		f32 drivetrain_rearWheelTorqueRatio;
		f32 wheels_radius_front;
		f32 wheels_radius_rear;
		f32 wheels_frictionFront;
		f32 wheels_frictionRear;
		f32 steering_maxAngle;
		f32 aerodynamics_frontalArea;
		f32 aerodynamics_dragCoefficient;
		f32 aerodynamics_liftCoefficient;
		f32 other_extraGravity;
		f32 other_frictionEqualizer;
		f32 other_torqueRollFactor;
		f32 other_torquePitchFactor;
		f32 other_torqueYawFactor;
		f32 other_extraTorqueFactor;
		f32 other_normalClippingAngle;
		f32 other_chassisUnitInertiaYaw;
		f32 other_chassisUnitInertiaRoll;
		f32 other_chassisUnitInertiaPitch;
		f32 brakes_minTimeToBlock;
		f32 brakes_timeToMaxPedal;
		f32 brakes_frontMinPedalInputToBlock;
		f32 brakes_rearMinPedalInputToBlock;
		f32 wheels_mass;
		f32 wheels_viscosityFriction;
		f32 wheels_slipAngle;
		f32 wheels_forceFeedbackMultiplier;
		f32 aerodynamics_airDensity;
		f32 damping_normalSpinDamping;
		f32 damping_collisionSpinDamping;
		f32 damping_collisionThreshold;
		f32 other_cruiseControlPID_p;
		f32 other_cruiseControlPID_i;
		f32 other_cruiseControlPID_d;
		f32 steering_CenteringRate;
		f32 steering_DeadZone;
		f32 steering_FrontWheelMultiplier;
		f32 steering_RearWheelMultiplier;
		f32 burnout_MinSpeed;
		f32 burnout_MaxSpeed;
		f32 burnout_SpinTorqueAtLowSpeed;
		f32 burnout_SpinTorqueAtHighSpeed;
		f32 burnout_SpinFrontTireFrictionAtLowSpeed;
		f32 burnout_SpinFrontTireFrictionAtHighSpeed;
		f32 burnout_SpinRearTireFrictionAtLowSpeed;
		f32 burnout_SpinRearTireFrictionAtHighSpeed;
		f32 burnout_TorqueFactor_LowSpeed;
		f32 burnout_FwdThrustFactor_LowSpeed;
		f32 burnout_SideThrustFactor_LowSpeed;
		f32 burnout_TorqueFactor_HighSpeed;
		f32 burnout_FwdThrustFactor_HighSpeed;
		f32 burnout_SideThrustFactor_HighSpeed;
		f32 jturn_SpinTorque;
		f32 jturn_SpinFrontTireFriction;
		f32 jturn_SpinRearTireFriction;
		f32 blownTire_WobbleMagnitude;
		f32 blownTire_WobbleFrequency;
		f32 blownTire_Drag;
		f32 blownTire_FrictionMultiplier;
		f32 lodHeightFixupFront;
		f32 lodHeightFixupRear;
		f32 suspension_frontSpringRestingLength;
		f32 suspension_rearSpringRestingLength;
		f32 other_maxVelocityForPositionalFriction;
		bool burnout_UseNewMethod;
		i8 pad[7];
	};

	class BikePhysicsDef : public qReflectObjectType<BikePhysicsDef, WheeledVehiclePhysicsDef>
	{
	public:
		f32 aerodynamics_tuckDragBoost;
		f32 lean_DesiredLo;
		f32 lean_DesiredHi;
		f32 lean_MinSpeed;
		f32 lean_MaxSpeed;
		f32 lean_PID_p;
		f32 lean_PID_i;
		f32 lean_PID_d;
		f32 wheelie_SteeringRate;
		f32 wheelie_TorqueBoost;
		f32 wheelie_TorqueBoostTime;
		f32 wheelie_PID_p;
		f32 wheelie_PID_i;
		f32 wheelie_PID_d;
		f32 wheelie_Angle;
		f32 wheelie_BrakingAngle;
		f32 wheelie_BrakingYaw;
	};

	class CarPhysicsDef : public qReflectObjectType<CarPhysicsDef, WheeledVehiclePhysicsDef>
	{
	public:
		bool disableDoorL02;
		bool disableDoorR02;
		bool disableDoorL03;
		bool disableDoorR03;
		bool disableTrunk;
	};
}
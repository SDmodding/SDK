#pragma once

class hkpVehicleBrake : public hkReferencedObject
{
public:
	struct WheelBreakingOutput
	{
		hkInplaceArray<f32, 32> m_brakingTorque;
		hkInplaceArray<hkBool, 32> m_isFixed;
		f32 m_wheelsTimeSinceMaxPedalInput;
	};

	//virtual void calcBreakingInfo(const f32 deltaTime, const hkpVehicleInstance* vehicle, const hkpVehicleDriverInput::FilteredDriverInputOutput& FilteredDriverInputOutput, WheelBreakingOutput& breakingInfo) = 0;
};

class hkpVehicleDefaultBrake : public hkpVehicleBrake
{
public:
	struct WheelBrakingProperties
	{
		f32 m_maxBreakingTorque;
		f32 m_minPedalInputToBlock;
		hkBool m_isConnectedToHandbrake;
	};

	hkArray<hkpVehicleDefaultBrake::WheelBrakingProperties> m_wheelBrakingProperties;
	f32 m_wheelsMinTimeToBlock;
};
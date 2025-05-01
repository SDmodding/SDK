#pragma once

class hkpVehicleSteering : public hkReferencedObject
{
public:
	struct SteeringAnglesOutput
	{
		f32 m_mainSteeringAngle;
		f32 m_mainSteeringAngleAssumingNoReduction;
		hkInplaceArray<f32, 32> m_wheelsSteeringAngle;
	};

	//virtual void calcSteering(const f32 deltaTime, const hkpVehicleInstance* vehicle, const hkpVehicleDriverInput::FilteredDriverInputOutput& filteredInfoOutput, SteeringAnglesOutput& steeringOutput) = 0;
};
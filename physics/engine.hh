#pragma once

namespace UFG
{
	class Engine : public hkpVehicleDefaultEngine
	{
	public:
		qArray<f32> mTorqueTable;
		f32 mDamage;
		f32 mTorqueBoost;
		f32 mGovernorSpeedKPH;
		f32 mEngineResistanceMaxSpeed;
		f32 mEngineResistanceMinSpeed;
		f32 mEngineResistanceMin;
		f32 mEngineResistanceMax;

		/* Functions */

		void InitializeFromPropertySet(WheeledVehiclePhysicsDef* vehicle_data_ptr) { SDK_CALL_FUNC(void, 0x469FB0, void*, WheeledVehiclePhysicsDef*)(this, vehicle_data_ptr); }
	};
}
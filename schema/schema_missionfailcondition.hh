#pragma once

class component_MissionFailCondition
{
public:
	bool ArrestFailTrigger;
	bool DeathFailTrigger;
	bool DamageFailTrigger;
	f32 DamageHealthThreshold;
	bool DistanceFailTrigger;
	f32 DistanceFailThreshold;
	bool PanicWeaponFailTrigger;
	bool PanicVehicleFailTrigger;
	bool VehicleFlipFailTrigger;
	bool BoatStuckFailTrigger;
	UFG::qOffset64<char*> ArrestFailCaption;
	UFG::qOffset64<char*> DeathFailCaption;
	UFG::qOffset64<char*> DamageFailCaption;
	UFG::qOffset64<char*> DistanceFailCaption;
	UFG::qOffset64<char*> PanicWeaponFailCaption;
	UFG::qOffset64<char*> PanicVehicleFailCaption;
	UFG::qOffset64<char*> VehicleFlipFailCaption;
	UFG::qOffset64<char*> BoatStuckFailCaption;
};
#pragma once

class component_PhysicsMover
{
public:
	UFG::qSymbol physicsPropertySetAI;
	UFG::qSymbol physicsPropertySetHuman;
	UFG::qOffset64<char*> modelName;
	UFG::qSymbol TrunkType;
	f32 damageMultiplierWorldCollisions;
	f32 damageMultiplierVehicleCollisions;
	f32 damageMultiplierBullets;
	f32 damageMultiplierTires;
	UFG::qVector3 boundingBoxMin;
	UFG::qVector3 boundingBoxMax;
	f32 tireShotImpulse;
	f32 tireBlownImpulse;
	f32 lowLodThrottleAcceleration;
	f32 lowLodBrakesAcceleration;
	f32 lowLodCoastAcceleration;
	f32 lowLodMaxSpeed;
	f32 lowLodMaxLateralAcceleration;
	f32 lowLodMinTurningRadius;
	f32 autoDeterioratingDamageThreshold;
	f32 autoDeterioratingDamageRate;
	f32 vehicleDistanceToHighLod;
	f32 vehicleDistanceToMedLod;
	f32 vehicleCollisionMinImpulseRequiredToTakeDamage;
	f32 vehicleCollisionExtraDamageMultiplier;
	f32 vehicleCollisionDamageDealtAtMinImpulse;
	f32 vehicleCollisionDamageDealtAtMaxImpulse;
	f32 vehicleCollisionMinImpulseRequiredToDealDamage;
	f32 vehicleCollisionMaxImpulseForDealingDamage;
	f32 vehicleCollisionDamageDealtAtMinRamImpulse;
	f32 vehicleCollisionDamageDealtAtMaxRamImpulse;
	f32 vehicleCollisionMinRamImpulseRequiredToDealDamage;
	f32 vehicleCollisionMaxRamImpulseForDealingDamage;
	bool vehicleCollisionForceDamageDealer;
	bool lockedAtLowLOD;
};

class component_CarPhysicsMover : public component_PhysicsMover{};
class component_BoatPhysicsMover : public component_PhysicsMover{};

class component_BikePhysicsMover : public component_PhysicsMover
{
public:
	int canWheelie;
};
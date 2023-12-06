#pragma once

namespace UFG
{
	namespace PropertySet
	{
		struct component_PhysicsMover
		{
			qSymbol physicsPropertySetAI;
			qSymbol physicsPropertySetHuman;
			qOffset64<char*> modelName;
			qSymbol TrunkType;
			float damageMultiplierWorldCollisions;
			float damageMultiplierVehicleCollisions;
			float damageMultiplierBullets;
			float damageMultiplierTires;
			qVector3 boundingBoxMin;
			qVector3 boundingBoxMax;
			float tireShotImpulse;
			float tireBlownImpulse;
			float lowLodThrottleAcceleration;
			float lowLodBrakesAcceleration;
			float lowLodCoastAcceleration;
			float lowLodMaxSpeed;
			float lowLodMaxLateralAcceleration;
			float lowLodMinTurningRadius;
			float autoDeterioratingDamageThreshold;
			float autoDeterioratingDamageRate;
			float vehicleDistanceToHighLod;
			float vehicleDistanceToMedLod;
			float vehicleCollisionMinImpulseRequiredToTakeDamage;
			float vehicleCollisionExtraDamageMultiplier;
			float vehicleCollisionDamageDealtAtMinImpulse;
			float vehicleCollisionDamageDealtAtMaxImpulse;
			float vehicleCollisionMinImpulseRequiredToDealDamage;
			float vehicleCollisionMaxImpulseForDealingDamage;
			float vehicleCollisionDamageDealtAtMinRamImpulse;
			float vehicleCollisionDamageDealtAtMaxRamImpulse;
			float vehicleCollisionMinRamImpulseRequiredToDealDamage;
			float vehicleCollisionMaxRamImpulseForDealingDamage;
			bool vehicleCollisionForceDamageDealer;
			bool lockedAtLowLOD;
		};
	}
}
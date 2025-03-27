#pragma once

namespace UFG
{
	enum eVehicleOrientationEnum
	{
		eVEHICLE_ORIENTATION_WHEELS,
		eVEHICLE_ORIENTATION_LEFT_SIDE,
		eVEHICLE_ORIENTATION_RIGHT_SIDE,
		eVEHICLE_ORIENTATION_FRONT_END,
		eVEHICLE_ORIENTATION_REAR_END,
		eVEHICLE_ORIENTATION_ROOF,
		NUM_VEHICLE_ORIENTATIONS
	};

}

namespace UFG::VehicleUtility
{
	SDK_SINLINE void AttachAIActionTreeComponent(SimObjectVehicle* vehicle) { SDK_CALL_FUNC(void, 0x670880, SimObjectVehicle*)(vehicle); }
	SDK_SINLINE void ClearDriver(SimObjectVehicle* vehicle) { SDK_CALL_FUNC(void, 0x674480, SimObjectVehicle*)(vehicle); }
	SDK_SINLINE void ExitVehicleNoAnim(SimObject* character) { SDK_CALL_FUNC(void, 0x6782B0, SimObject*)(character); }

	SDK_SINLINE void ExitVehicleNow(SimObject* pOccupantSimObject, bool bForceClearDriver, bool bDispatchNonCameraEvents, bool bDispatchCameraEvents) {
		SDK_CALL_FUNC(void, 0x678FB0, SimObject*, bool, bool, bool)(pOccupantSimObject, bForceClearDriver, bDispatchNonCameraEvents, bDispatchCameraEvents);
	}

	SDK_SINLINE TransformNodeComponent* GetChaseSpawnTransform(SimObject* chasee, f32 distance_behind) {
		return SDK_CALL_FUNC(TransformNodeComponent*, 0x67A130, SimObject*, f32)(chasee, distance_behind);
	}

	SDK_SINLINE eVehicleOrientationEnum GetVehicleOrientation(SimObjectVehicle* pVehicleSimObject, bool bIgnoreWheelState, f32* pfReturn) {
		return SDK_CALL_FUNC(eVehicleOrientationEnum, 0x67B560, SimObjectVehicle*, bool, f32*)(pVehicleSimObject, bIgnoreWheelState, pfReturn);
	}

	SDK_SINLINE bool IsClassTypeRoadTypeMatch(qPropertySet* set, u32 roadType) { return SDK_CALL_FUNC(bool, 0x67EA00, qPropertySet*, u32)(set, roadType); }
	SDK_SINLINE bool IsDriverTypeInList(SimObject* pSimObject, const qPropertyList* list) { return SDK_CALL_FUNC(bool, 0x67EBA0, SimObject*, const qPropertyList*)(pSimObject, list); }

	SDK_SINLINE bool IsDriverTypeInList(const qPropertySet* pPropertySet, const qPropertyList* list) {
		return SDK_CALL_FUNC(bool, 0x67EBD0, const qPropertySet*, const qPropertyList*)(pPropertySet, list);
	}

	SDK_SINLINE bool IsPlayerPassengerOfVehicle(SimObject* vehicle_simobj) { return SDK_CALL_FUNC(char, 0x67F410, SimObject*)(vehicle_simobj); }
	SDK_SINLINE void OverrideForwardSpeedKPH(SimObjectVehicle* pVehicle, f32 forwardSpeedKPH) { SDK_CALL_FUNC(void, 0x685AD0, SimObjectVehicle*, f32)(pVehicle, forwardSpeedKPH); }
	SDK_SINLINE void OverrideLinearVelocityMagnitudeKPH(SimObjectVehicle* pVehicle, f32 speedKPH) { SDK_CALL_FUNC(void, 0x685BD0, SimObjectVehicle*, f32)(pVehicle, speedKPH); }
	SDK_SINLINE void PlaceCharacterInTrunk(SimObject* character, SimObjectVehicle* vehicle) { SDK_CALL_FUNC(void, 0x686060, SimObject*, SimObjectVehicle*)(character, vehicle); }

	SDK_SINLINE void PlaceCharacterInVehicle(SimObjectCharacter* character, SimObjectVehicle* vehicle, eTargetTypeEnum eRole, bool addAI, bool destroyEquipped, bool ignoreRoleGetInFirstEmptyPassengerSeat) {
		SDK_CALL_FUNC(void, 0x6864B0, SimObjectCharacter*, SimObjectVehicle*, eTargetTypeEnum, bool, bool, bool)(character, vehicle, eRole, addAI, destroyEquipped, ignoreRoleGetInFirstEmptyPassengerSeat);
	}

	SDK_SINLINE VehicleDriverInterface* SetAIDriver(SimObject* character, SimObjectVehicle* vehicle, bool isAmbient) {
		return SDK_CALL_FUNC(VehicleDriverInterface*, 0x68A270, SimObject*, SimObjectVehicle*, bool)(character, vehicle, isAmbient);
	}

	SDK_SINLINE VehicleDriverInterface* SetAIDriver(SimObjectVehicle* vehicle, bool isAmbient) {
		return SDK_CALL_FUNC(VehicleDriverInterface*, 0x68A460, SimObjectVehicle*, bool)(vehicle, isAmbient);
	}

	SDK_SINLINE VehicleDriverInterface* SetPlayerDriver(SimObjectVehicle* vehicle) { return SDK_CALL_FUNC(VehicleDriverInterface*, 0x68ACC0, SimObjectVehicle*)(vehicle); }
	SDK_SINLINE void SetRadiostation(SimObjectVehicle* vehicle) { SDK_CALL_FUNC(void, 0x68B200, SimObjectVehicle*)(vehicle); }
	SDK_SINLINE VehicleDriverInterface* SetRemoteDriver(SimObjectVehicle* vehicle) { return SDK_CALL_FUNC(VehicleDriverInterface*, 0x68B290, SimObjectVehicle*)(vehicle); }
	SDK_SINLINE void UpdateTargetsForEachVehicleRole(SimObjectVehicle* vehicle) { SDK_CALL_FUNC(void, 0x69A110, SimObjectVehicle*)(vehicle); }
}
#pragma once

namespace UFG::SimObjectUtility
{
	SDK_SINLINE void Teleport(SimObject* pSimObject, const qMatrix44& xform) { 
		reinterpret_cast<void(SDK_CALL*)(SimObject*, const qMatrix44&)>(SDK_RVA(0x556870))(pSimObject, xform); 
	}

	SDK_SINLINE void AttachHudSymbol(SimObject* pObject, const char* symbolName, bool useCustomFilterDistance, f32 customFilterDistance, const char* customWorldMapCaption) {
		reinterpret_cast<void(SDK_CALL*)(SimObject*, const char*, bool, f32, const char*)>(SDK_RVA(0x5223E0))(pObject, symbolName, useCustomFilterDistance, customFilterDistance, customWorldMapCaption);
	}

	SDK_SINLINE void ConditionSimObjectForAmbientWorld(SimObject* pObject) {
		reinterpret_cast<void(SDK_CALL*)(SimObject*)>(SDK_RVA(0x5233D0))(pObject);
	}

	SDK_SINLINE void CreateAndAttachProp(qPropertySet* propertySet, SimObject* attachTo, bool deletePhysicsFails) {
		reinterpret_cast<void(SDK_CALL*)(qPropertySet*, SimObject*, bool)>(SDK_RVA(0x523EE0))(propertySet, attachTo, deletePhysicsFails);
	}

	SDK_SINLINE void DetachHudSymbol(SimObject* pObject) {
		reinterpret_cast<void(SDK_CALL*)(SimObject*)>(SDK_RVA(0x525C70))(pObject);
	}

	SDK_SINLINE void DowngradeModelResolution(SimObject* pObject) {
		reinterpret_cast<void(SDK_CALL*)(SimObject*)>(SDK_RVA(0x526650))(pObject);
	}

	SDK_SINLINE qPropertySet* FindDriverProfile(qPropertySet* vehiclePropertySet) {
		return reinterpret_cast<qPropertySet*(SDK_CALL*)(qPropertySet*)>(SDK_RVA(0x528680))(vehiclePropertySet);
	}

	SDK_SINLINE qSymbol GenerateUniqueActorName(const qSymbol& basename) {
		return reinterpret_cast<qSymbol(SDK_CALL*)(const qSymbol&)>(SDK_RVA(0x52A360))(basename);
	}

	SDK_SINLINE u32 GetClassTypes(qPropertySet* pPropertySet, qSymbol* classTypes, u32 maxClassTypes) {
		return reinterpret_cast<u32(SDK_CALL*)(qPropertySet*, qSymbol*, u32)>(SDK_RVA(0x52B140))(pPropertySet, classTypes, maxClassTypes);
	}

	SDK_SINLINE bool GetObjectCapsuleApproximation(SimObject* pSimObject, qMatrix44** pXform, qVector3* vSegA, qVector3* vSegB, f32* fRadius) {
		return reinterpret_cast<bool(SDK_CALL*)(SimObject*, qMatrix44**, qVector3*, qVector3*, f32*)>(SDK_RVA(0x52EB50))(pSimObject, pXform, vSegA, vSegB, fRadius);
	}

	SDK_SINLINE bool HandleSimObjectLeavingWorld(SimObject* pVehicle) {
		return reinterpret_cast<bool(SDK_CALL*)(SimObject*)>(SDK_RVA(0x534640))(pVehicle);
	}

	SDK_SINLINE bool IsBoat(SimObject* pVehicle) {
		return reinterpret_cast<bool(SDK_CALL*)(SimObject*)>(SDK_RVA(0x5397C0))(pVehicle);
	}

	SDK_SINLINE bool IsBoatInWater(SimObject* pVehicle) {
		return reinterpret_cast<bool(SDK_CALL*)(SimObject*)>(SDK_RVA(0x5398B0))(pVehicle);
	}

	SDK_SINLINE bool IsCharacterInVehicle(SimObject* pSimObject) {
		return reinterpret_cast<bool(SDK_CALL*)(SimObject*)>(SDK_RVA(0x539A60))(pSimObject);
	}

	SDK_SINLINE bool IsClassType(SimObject* pSimObject, const qSymbol targetClassType) {
		return reinterpret_cast<bool(SDK_CALL*)(SimObject*, const qSymbol&)>(SDK_RVA(0x539A90))(pSimObject, targetClassType);
	}

	SDK_SINLINE bool IsClassType(qPropertySet* pPropertySet, const qSymbol targetClassType) {
		return reinterpret_cast<bool(SDK_CALL*)(qPropertySet*, const qSymbol&)>(SDK_RVA(0x539C00))(pPropertySet, targetClassType);
	}

	SDK_SINLINE bool IsClassTypeInArray(SimObject* pSimObject, const qArray<qSymbol>& array) {
		return reinterpret_cast<bool(SDK_CALL*)(SimObject*, const qArray<qSymbol>&)>(SDK_RVA(0x539CB0))(pSimObject, array);
	}

	SDK_SINLINE bool IsInWater(SimObject* pSimObject) {
		return reinterpret_cast<bool(SDK_CALL*)(SimObject*)>(SDK_RVA(0x53AC30))(pSimObject);
	}

	SDK_SINLINE bool IsPlayerVehicle(SimObject* pSimObject) {
		return reinterpret_cast<bool(SDK_CALL*)(SimObject*)>(SDK_RVA(0x53B780))(pSimObject);
	}

	SDK_SINLINE bool IsPositionOnScreen(const qVector3& position, f32 radius, bool want_fully_on_screen) {
		return reinterpret_cast<bool(SDK_CALL*)(const qVector3&, f32, bool)>(SDK_RVA(0x53B940))(position, radius, want_fully_on_screen);
	}

	SDK_SINLINE bool PlaceOnGround(qVector3* out, const qVector3& position, f32 heigh_above_ground, f32 cast_distance) {
		return reinterpret_cast<bool(SDK_CALL*)(qVector3*, const qVector3&, f32, f32)>(SDK_RVA(0x542470))(out, position, heigh_above_ground, cast_distance);
	}

	SDK_SINLINE void PostRigChangeReset(SimObject* pObject) {
		reinterpret_cast<void(SDK_CALL*)(SimObject*)>(SDK_RVA(0x542830))(pObject);
	}

	SDK_SINLINE bool ReinitializeSimObject(SimObject* pSimObjectToReset, bool bKeepItems, bool bSoft) {
		return reinterpret_cast<bool(SDK_CALL*)(SimObject*, bool, bool)>(SDK_RVA(0x547560))(pSimObjectToReset, bKeepItems, bSoft);
	}

	SDK_SINLINE void ResetSimObject(SimObject* pSimObjectResetting, SimObject* pSimObjectToReset, bool bKeepItems) {
		reinterpret_cast<void(SDK_CALL*)(SimObject*, SimObject*, bool)>(SDK_RVA(0x54A260))(pSimObjectResetting, pSimObjectToReset, bKeepItems);
	}

	SDK_SINLINE void ResetState(SimObject* pSimObjectToReset, bool bKeepItems, bool bDeleteItems) {
		reinterpret_cast<void(SDK_CALL*)(SimObject*, bool, bool)>(SDK_RVA(0x54A8D0))(pSimObjectToReset, bKeepItems, bDeleteItems);
	}

	SDK_SINLINE void UpgradeModelResolution(SimObject* pObject) {
		reinterpret_cast<void(SDK_CALL*)(SimObject*)>(SDK_RVA(0x563620))(pObject);
	}
}
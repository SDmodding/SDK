#pragma once

class hkpEntity : public hkpWorldObject
{
public:
	UFG_PAD(0x88);
	/*hkpMaterial m_material;
	void* m_limitContactImpulseUtilAndFlag;
	float m_damageMultiplier;
	hkpBreakableBody* m_breakableBody;
	unsigned int m_solverData;
	unsigned __int16 m_storageIndex;
	unsigned __int16 m_contactPointCallbackDelay;
	hkSmallArray<hkConstraintInternal> m_constraintsMaster;
	hkArray<hkpConstraintInstance*, hkContainerHeapAllocator> m_constraintsSlave;
	hkArray<unsigned char, hkContainerHeapAllocator> m_constraintRuntime;
	hkpSimulationIsland* m_simulationIsland;
	char m_autoRemoveLevel;
	char m_numShapeKeysInContactPointProperties;
	char m_responseModifierFlags;
	unsigned int m_uid;
	hkpEntity::SpuCollisionCallback m_spuCollisionCallback;*/

	hkpMaxSizeMotion m_motion;

	void Activate()
	{
		reinterpret_cast<void(_fastcall*)(void*)>(UFG_RVA(0xD60FE0))(this);
	}

	bool IsActivate()
	{
		return reinterpret_cast<bool(_fastcall*)(void*)>(UFG_RVA(0xD61300))(this);
	}
};
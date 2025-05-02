#pragma once

class hkpEntity : public hkpWorldObject
{
public:
	struct ExtendedListeners
	{
		hkSmallArray<class hkpEntityActivationListener*> m_activationListeners;
		hkSmallArray<class hkpEntityListener*> m_entityListeners;
	};

	struct SpuCollisionCallback
	{
		struct hkSpuCollisionCallbackUtil* m_util;
		u16 m_capacity;
		u8 m_eventFilter;
		u8 m_userFilter;
	};

	hkpMaterial m_material;
	void* m_limitContactImpulseUtilAndFlag;
	f32 m_damageMultiplier;
	class hkpBreakableBody* m_breakableBody;
	u32 m_solverData;
	u16 m_storageIndex;
	u16 m_contactPointCallbackDelay;
	hkSmallArray<hkConstraintInternal> m_constraintsMaster;
	hkArray<hkpConstraintInstance*> m_constraintsSlave;
	hkArray<u8> m_constraintRuntime;
	hkpSimulationIsland* m_simulationIsland;
	s8 m_autoRemoveLevel;
	u8 m_numShapeKeysInContactPointProperties;
	u8 m_responseModifierFlags;
	u32 m_uid;
	SpuCollisionCallback m_spuCollisionCallback;
	__declspec(align(16)) qProxy<hkpMaxSizeMotion> m_motion;
	hkSmallArray<hkpContactListener*> m_contactListeners;
	hkSmallArray<hkpAction*> m_actions;
	hkRefPtr<hkLocalFrame> m_localFrame;
	ExtendedListeners* m_extendedListeners;
	u32 m_npData;

	/* Functions */

	hkBool isActive() { return SDK_CALL_FUNC(hkBool, 0xD61300, void*)(this); }

	void activate() { SDK_CALL_FUNC(void, 0xD60FE0, void*)(this); }

	void deactivate() { SDK_CALL_FUNC(void, 0xD610F0, void*)(this); }
};
SDK_ASSERT_SIZEOF(hkpEntity, 0x2D0);
#pragma once

namespace UFG
{
	class TargetingSystemBaseComponent : public SimComponent, public UpdateInterface, public qNode<TargetingSystemBaseComponent>
	{
	public:
		TargetingSimObject* m_pTargets;
		TargetingMap* m_pTargetingMap;
		qList<TargetingSimObject> m_TargetedBy;

		/* Functions */

		void updateMySpawnPointTarget() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x576430))(this); }

		void shutdown() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x56D660))(this); }

		void initialize() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x56A000))(this); }

		void Reset() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x549CB0))(this); }

		void SetTargetLock(eTargetTypeEnum eTargetType, const bool bLock, const bool bDisableCollision) {
			reinterpret_cast<void(SDK_CALL*)(void*, eTargetTypeEnum, const bool, const bool)>(SDK_RVA(0x54EE40))(this, eTargetType, bLock, bDisableCollision); 
		}

		void SetTarget(eTargetTypeEnum eTargetType, SimObject* pSimObject) { 
			reinterpret_cast<void(SDK_CALL*)(void*, eTargetTypeEnum, SimObject*)>(SDK_RVA(0x54ED20))(this, eTargetType, pSimObject);
		}

		bool IsTargetedByTypeAndLocked(eTargetTypeEnum eTargetType) { return reinterpret_cast<bool(SDK_CALL*)(void*, eTargetTypeEnum)>(SDK_RVA(0x53C280))(this, eTargetType); }

		bool IsTargetedByType(eTargetTypeEnum eTargetType) { return reinterpret_cast<bool(SDK_CALL*)(void*, eTargetTypeEnum)>(SDK_RVA(0x53C250))(this, eTargetType); }

		UEL::Value GetGrappleTarget_UEL() { return reinterpret_cast<UEL::Value(SDK_CALL*)(void*)>(SDK_RVA(0x52DB90))(this); }

		void FindMatrix(TransformNodeComponent* pTNC, SimObject* pSimObject, qMatrix44* matSimObject) { 
			reinterpret_cast<void(SDK_CALL*)(TransformNodeComponent*, SimObject*, qMatrix44*)>(SDK_RVA(0x528910))(pTNC, pSimObject, matSimObject); 
		}

		void FindMatrix(SimObject* pSimObject, qMatrix44* matSimObject) { reinterpret_cast<void(SDK_CALL*)(SimObject*, qMatrix44*)>(SDK_RVA(0x5288E0))(pSimObject, matSimObject); }

		void ClearTarget(eTargetTypeEnum eTargetType) { reinterpret_cast<void(SDK_CALL*)(void*, eTargetTypeEnum)>(SDK_RVA(0x15DFB0))(this, eTargetType); }

		void AssignTarget(eTargetTypeEnum eAssignTargetTo, eTargetTypeEnum eAssignTargetFrom) { 
			reinterpret_cast<void(SDK_CALL*)(void*, eTargetTypeEnum, eTargetTypeEnum)>(SDK_RVA(0x2E7D90))(this, eAssignTargetTo, eAssignTargetFrom); 
		}

		void AssignTarget(eTargetTypeEnum eAssignTargetTo, SimObject* pSimObject) { 
			reinterpret_cast<void(SDK_CALL*)(void*, eTargetTypeEnum, SimObject*)>(SDK_RVA(0x2E7E20))(this, eAssignTargetTo, pSimObject);
		}
	};
	SDK_ASSERT_SIZEOF(TargetingSystemBaseComponent, 0x78);
}
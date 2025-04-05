#pragma once

namespace UFG
{
	class TargetingSystemBaseComponent : public SimComponent, public UpdateInterface, public qNode<TargetingSystemBaseComponent>
	{
	public:
		enum { _TypeUID = 0xA0000001 };

		TargetingSimObject* m_pTargets;
		TargetingMap* m_pTargetingMap;
		qList<TargetingSimObject> m_TargetedBy;

		/* Helper Functions */

		SDK_INLINE SimObject* GetTarget(eTargetTypeEnum eTargetType)
		{
			if (auto i = m_pTargetingMap->m_Map[eTargetType]) {
				return m_pTargets[i].m_pTarget.m_pPointer;
			}

			return 0;
		};

		/* Functions */

		void AssignTarget(eTargetTypeEnum eAssignTargetTo, SimObject* pSimObject) { SDK_CALL_FUNC(void, 0x2E7E20, void*, eTargetTypeEnum, SimObject*)(this, eAssignTargetTo, pSimObject); }
		void AssignTarget(u32 eAssignTargetTo, u32 eAssignTargetFrom) { SDK_CALL_FUNC(void, 0x2E7D90, void*, u32, u32)(this, eAssignTargetTo, eAssignTargetFrom); }
		void ClearTarget(eTargetTypeEnum eTargetType) { SDK_CALL_FUNC(void, 0x15DFB0, void*, eTargetTypeEnum)(this, eTargetType); }
		void FindMatrix(SimObject* pSimObject, qMatrix44& matSimObject) { SDK_CALL_FUNC(void, 0x5288E0, SimObject*, qMatrix44&)(pSimObject, matSimObject); }
		void FindMatrix(TransformNodeComponent* pTNC, SimObject* pSimObject, qMatrix44& matSimObject) { 
			SDK_CALL_FUNC(void, 0x528910, TransformNodeComponent*, SimObject*, qMatrix44&)(pTNC, pSimObject, matSimObject); 
		}
		UEL::Value GetGrappleTarget_UEL() { return SDK_CALL_FUNC(UEL::Value, 0x52DB90, void*)(this); }
		bool IsTargetedByType(eTargetTypeEnum eTargetType) { return SDK_CALL_FUNC(bool, 0x53C250, void*, eTargetTypeEnum)(this, eTargetType); }
		bool IsTargetedByTypeAndLocked(eTargetTypeEnum eTargetType) { return SDK_CALL_FUNC(bool, 0x53C280, void*, eTargetTypeEnum)(this, eTargetType); }
		void SetTarget(u32 eTargetType, SimObject* pSimObject) { SDK_CALL_FUNC(void, 0x54ED20, void*, u32, SimObject*)(this, eTargetType, pSimObject); }
		void SetTargetLock(eTargetTypeEnum eTargetType, bool bLock, bool bDisableCollision) { 
			SDK_CALL_FUNC(void, 0x54EE40, void*, eTargetTypeEnum, bool, bool)(this, eTargetType, bLock, bDisableCollision);
		}
	};
	SDK_ASSERT_SIZEOF(TargetingSystemBaseComponent, 0x78);
}
#pragma once

namespace UFG
{
	class InventoryItemComponent : public SimComponent, public qNode<InventoryItemComponent>
	{
	public:
		enum { _TypeUID = 0xAE000001 };

		qSafePointer<InventoryComponent> m_pOwnerInventoryComponent;
		eInventoryItemEnum m_eInventoryItem;
		qSymbol m_symInventoryItem;
		int m_iQuantity;

		/* Impl Functions */

		SDK_INLINE SimObject* GetOwnerSimObject() { return (m_pOwnerInventoryComponent ? m_pOwnerInventoryComponent->m_pSimObject : nullptr); }
		SDK_INLINE void SetQuantity(int value) { if (!m_pOwnerInventoryComponent) m_iQuantity = value; }

		/* Functions */

		UEL::Value GetOwnerSimObject_UEL() 
		{
			UEL::Value res;
			SDK_CALL_FUNC(void, 0x52F320, void*, UEL::Value*)(this, &res);
			return res;
		}
	};
}
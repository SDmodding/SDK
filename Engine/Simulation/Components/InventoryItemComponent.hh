#pragma once

namespace UFG
{
	class InventoryItemComponent : public SimComponent
	{
	public:
		qNode<InventoryItemComponent> mNode;
		qSafePointer<class CInventoryComponent> m_pOwnerInventoryComponent;
		eInventoryItemEnum m_eInventoryItem;
		qSymbol m_symInventoryItem;
		int m_iQuantity;
	}; typedef InventoryItemComponent CInventoryItemComponent;
}
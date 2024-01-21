#pragma once

namespace UFG
{
	class CInventoryItemComponent : public CSimComponent
	{
	public:
		qNode<CInventoryItemComponent> mNode;
		qSafePointer<class CInventoryComponent> m_pOwnerInventoryComponent;
		eInventoryItemEnum m_eInventoryItem;
		qSymbol m_symInventoryItem;
		int m_iQuantity;
	};
}
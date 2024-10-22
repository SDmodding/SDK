#pragma once

namespace UFG
{
	class GetInFormationNode;
	class GetInPedFormationNode;
	class HasAttackRequestNode;

	enum eActionTreeType: int
	{
		eACTION_TREE_TYPE_NONE,
		eACTION_TREE_TYPE_ACTION,
		eACTION_TREE_TYPE_AI,
		eACTION_TREE_TYPE_FACIAL,
		NUM_ACTION_TREE_TYPES
	};

	class ActionTreeComponentBase
	{
	public:
		struct ActionTreeMemoryData : qNodeRB64<ActionTreeMemoryData>, qNode<ActionTreeMemoryData>, qNode<void*>
		{
			ActionTreeComponentBase* m_pMyComponent;
			qArray<f32> m_pFloatArray;
			qArray<int> m_pIntArray;
			qArray<u64> m_pUInt64Array;
			qArray<bool> m_pBoolArray;
			qArray<qSymbol> m_pQSymbolArray;
			qArray<qSymbolUC> m_pQSymbolUCArray;
			qArray<qSafePointer<SimObject>> m_pSimObjectPointerArray;
			qArray<qSafePointer<SimComponent>> m_pSimComponentPointerArray;
			qArray<qSafePointer<GetInFormationNode>> m_pGetInFormationNodePointerArray;
			qArray<qSafePointer<GetInPedFormationNode>> m_pGetInPedFormationNodePointerArray;
			qArray<qSafePointer<HasAttackRequestNode>> m_pHasAttackRequestNodePointerArray;
			u32 mSize;
		};
		SDK_ASSERT_SIZEOF(ActionTreeMemoryData, 0x100);

		qTreeRB64<ActionTreeMemoryData> mActionTreeMemoryDataStructs;
		eActionTreeType m_eType;

		virtual ~ActionTreeComponentBase() = 0;
	};
	SDK_ASSERT_SIZEOF(ActionTreeComponentBase, 0x58);
}
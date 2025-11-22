#pragma once

namespace UFG
{
	class qTree64Base
	{
	public:
		struct BaseNode
		{
			u64 mUID;
			BaseNode* mParent;
			BaseNode* mChildren[2];
			BaseNode* mNeighbours[2];
		};

		BaseNode mHead;
		i64 mCount;

		void Add(BaseNode* node) { SDK_CALL_FUNC(void, 0x165C90, void*, BaseNode*)(this, node); }

		bool Contains(u64 key) { return SDK_CALL_FUNC(bool, 0x16AA20, void*, u64)(this, key); }

		BaseNode* Get(u64 key) { return SDK_CALL_FUNC(BaseNode*, 0x16F0F0, void*, u64)(this, key); }

		BaseNode* GetHead() { return SDK_CALL_FUNC(BaseNode*, 0x170B10, void*)(this); }

		BaseNode* GetNext(BaseNode* cur_node) { return SDK_CALL_FUNC(BaseNode*, 0x1714A0, void*, BaseNode*)(this, cur_node); }

		void Remove(BaseNode* node) { SDK_CALL_FUNC(void, 0x17A580, void*, BaseNode*)(this, node); }
	};

	template <typename T>
	class qTreeNode64
	{
	public:
		qTree64Base::BaseNode mBaseNode;
	};

	template <typename T, typename U = T>
	class qTree64
	{
	public:
		qTree64Base mTree;

		SDK_INLINE void Add(qTreeNode64<T>* node) { mTree.Add(node->mBaseNode); }

		SDK_INLINE bool Contains(u64 key) { return mTree.Contains(key); }

		SDK_INLINE T* Get(u64 key) { return static_cast<T*>(reinterpret_cast<qTreeNode64<T>*>(mTree.Get(key))); }

		SDK_INLINE T* GetHead() { return static_cast<T*>(reinterpret_cast<qTreeNode64<T>*>(mTree.GetHead())); }

		SDK_INLINE T* GetNext(qTreeNode64<T>* cur_node) { return static_cast<T*>(reinterpret_cast<qTreeNode64<T>*>(mTree.GetNext(&cur_node->mBaseNode))); }

		SDK_INLINE void Remove(qTreeNode64<T>* node) { mTree.Remove(node->mBaseNode); }
		
	};
}
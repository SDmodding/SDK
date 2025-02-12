#pragma once

namespace UFG
{
	class qBaseNodeRB
	{
	public:
		qBaseNodeRB* mParent;
		qBaseNodeRB* mChild[2];
		u32 mUID;

		qBaseNodeRB() : mParent(0), mChild{ 0, 0 }, mUID(0) {}
	};

	template <typename T>
	class qNodeRB
	{
	public:
		qBaseNodeRB mNode;

		SDK_INLINE T* type() { return (this ? static_cast<T*>(this) : reinterpret_cast<T*>(nullptr)); }
	};

	class qBaseTreeRB
	{
	public:
		qBaseNodeRB mRoot;
		qBaseNodeRB mNULL;
		int mCount;

		qBaseTreeRB() { SDK_CALL_FUNC(void, 0x160CC0, void*)(this); }
		~qBaseTreeRB() { SDK_CALL_FUNC(void, 0x167DC0, void*)(this); }

		/* Functions */

		SDK_INLINE bool IsEmpty() { return mCount == 0; }

		void Add(qBaseNodeRB* x) { SDK_CALL_FUNC(void, 0x1652A0, void*, qBaseNodeRB*)(this, x); }

		bool Contains(qBaseNodeRB* node) { return SDK_CALL_FUNC(bool, 0x16A9E0, void*, qBaseNodeRB*)(this, node); }

		qBaseNodeRB* Get(u32 uid) { return SDK_CALL_FUNC(qBaseNodeRB*, 0x16EFB0, void*, u32)(this, uid); }

		qBaseNodeRB* GetHead() { return SDK_CALL_FUNC(qBaseNodeRB*, 0x2C3100, void*)(this); }

		qBaseNodeRB* GetNext(qBaseNodeRB* x) { return SDK_CALL_FUNC(qBaseNodeRB*, 0x171440, void*, qBaseNodeRB*)(this, x); }

		qBaseNodeRB* GetTail() { return SDK_CALL_FUNC(qBaseNodeRB*, 0x1725F0, void*)(this); }
	};

	template <typename T>
	class qTreeRB
	{
	public:
		qBaseTreeRB mTree;

		/* Functions */

		SDK_INLINE bool IsEmpty() { return mTree.IsEmpty(); }

		SDK_INLINE void Add(qNodeRB<T>* x) { mTree.Add(&x->mNode); }

		SDK_INLINE bool Contains(qNodeRB<T>* node) { return mTree.Contains(&node->mNode); }

		SDK_INLINE T* Get(u32 uid) { return reinterpret_cast<qNodeRB<T>*>(mTree.Get(uid))->type(); }

		SDK_INLINE T* GetHead() { return reinterpret_cast<qNodeRB<T>*>(mTree.GetHead())->type(); }

		SDK_INLINE T* GetNext(qNodeRB<T>* x) { return reinterpret_cast<qNodeRB<T>*>(mTree.GetNext(&x->mNode))->type(); }

		SDK_INLINE T* GetTail() { return reinterpret_cast<qNodeRB<T>*>(mTree.GetTail())->type(); }

		/* Iterator */

		class Iterator
		{
		public:
			Iterator(qBaseTreeRB* tree, qBaseNodeRB* node) : mTree(tree), mNode(node) {}

			bool operator!=(const Iterator& other) const { return mNode != other.mNode; }

			T* operator*() const { return reinterpret_cast<qNodeRB<T>*>(mNode)->type(); }

			Iterator& operator++() { mNode = mTree->GetNext(mNode); return *this; }

		private:
			qBaseTreeRB* mTree;
			qBaseNodeRB* mNode;
		};

		SDK_INLINE Iterator begin() { return { &mTree, mTree.GetHead() }; }
		SDK_INLINE Iterator end() { return { nullptr, nullptr }; }
	};

	template <typename T>
	class qMapNode32 : public qNodeRB<qMapNode32<T>>
	{
	public:
		T mValue;
	};

	template <typename T>
	class qMap
	{
	public:
		qTreeRB<qMapNode32<T>> mTree;
	};

}
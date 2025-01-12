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

		qBaseTreeRB* Get(u32 uid) { return SDK_CALL_FUNC(qBaseTreeRB*, 0x16EFB0, void*, u32)(this, uid); }

		qBaseTreeRB* GetNext(qBaseNodeRB* x) { return SDK_CALL_FUNC(qBaseTreeRB*, 0x171440, void*, qBaseNodeRB*)(this, x); }

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

		SDK_INLINE T* Get(u32 uid) { return reinterpret_cast<T*>(mTree.Get(uid)); }

		SDK_INLINE T* GetNext(qNodeRB<T>* x) { return reinterpret_cast<T*>(mTree.GetNext(&x->mNode)); }

		SDK_INLINE T* GetTail() { return reinterpret_cast<T*>(mTree.GetTail()); }
	};
}
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

		qBaseTreeRB() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x160CC0))(this); }
		~qBaseTreeRB() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x167DC0))(this); }

		/* Functions */

		SDK_INLINE bool IsEmpty() { return mCount == 0; }

		void Add(qBaseNodeRB* x) { reinterpret_cast<void(SDK_CALL*)(void*, qBaseNodeRB*)>(SDK_RVA(0x1652A0))(this, x); }

		bool Contains(qBaseNodeRB* node) { return reinterpret_cast<bool(SDK_CALL*)(void*, qBaseNodeRB*)>(SDK_RVA(0x16A9E0))(this, node); }

		qBaseNodeRB* Get(u32 uid) { return reinterpret_cast<qBaseNodeRB*(SDK_CALL*)(void*, u32)>(SDK_RVA(0x16EFB0))(this, uid); }

		qBaseNodeRB* GetNext(qBaseNodeRB* x) { return reinterpret_cast<qBaseNodeRB*(SDK_CALL*)(void*, qBaseNodeRB*)>(SDK_RVA(0x171440))(this, x); }

		qBaseNodeRB* GetTail() { return reinterpret_cast<qBaseNodeRB*(SDK_CALL*)(void*)>(SDK_RVA(0x1725F0))(this); }
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
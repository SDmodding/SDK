#pragma once

namespace UFG
{
	template <typename T, typename U = T>
	class qNode
	{
	public:
		qNode<T, U>* mPrev;
		qNode<T, U>* mNext;

		qNode() : mPrev(this), mNext(this) {}
		~qNode()
		{
			auto prev = mPrev;
			auto next = mNext;
			prev->mNext = next;
			next->mPrev = prev;
			mNext = mPrev = this;
		}

		SDK_INLINE void LinkBeforeNode(qNode<T, U>* node)
		{
			node->mPrev = mPrev;
			node->mNext = this;
			mPrev->mNext = node;
			mPrev = node;
		}

		SDK_INLINE void RemoveFromList()
		{
			auto prev = mPrev;
			auto next = mNext;
			prev->mNext = next;
			next->mPrev = prev;
			mNext = mPrev = this;
		}

		SDK_INLINE T* type() { return static_cast<T*>(this); }
	};

	template <typename T>
	class qPointerNode : qNode<T>
	{
	public:
		T* mNode;
	};

	template <typename T, typename U = T, bool FREE = 1>
	class qList
	{
	public:
		qNode<T, U> mNode;

		SDK_INLINE void Insert(qNode<T, U>* node) { mNode.LinkBeforeNode(node); }

		SDK_INLINE void Remove(qNode<T, U>* node) { node->RemoveFromList(); }

		SDK_INLINE bool IsEmpty() { return mNode.mNext == &mNode; }
		SDK_INLINE qNode<T, U>* back() { return mNode.mPrev; }

		/* Iterator */

		class Iterator
		{
		public:
			Iterator(qNode<T, U>* node) : mNode(node) {}

			bool operator!=(const Iterator& other) const { return mNode != other.mNode; }

			T* operator*() const { return mNode->type(); }

			Iterator& operator++() { mNode = mNode->mNext; return *this; }

		private:
			qNode<T, U>* mNode;
		};

		SDK_INLINE Iterator begin() { return { mNode.mNext }; }
		SDK_INLINE Iterator end() { return { &mNode }; }
	};

	template <typename T>
	class GridIntrusiveNode : public qNode<T>
	{
	public:
	};

	template <typename T>
	class qValueNode : public qNode<qValueNode<T>>
	{
	public:
		T mValue;
	};

	template <typename T, typename U = T>
	class qSNode
	{
	public:
		qSNode<T, U>* mNext;
	};

	template <typename T, typename U = T>
	class qSList
	{
	public:
		qSNode<T, U>* mHead;
	};
}
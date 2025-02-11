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
			mPrev->mNext = mNext;
			mNext->mPrev = mPrev;
			mPrev = mNext = this;
		}

		SDK_INLINE T* type() { return static_cast<T*>(this); }
	};

	template <typename T, typename U = T>
	class qList
	{
	public:
		qNode<T, U> mNode;

		SDK_INLINE bool IsEmpty() { return mNode.mNext == &mNode; }
		SDK_INLINE qNode<T, U>* back() { return mNode.mPrev; }
		SDK_INLINE qNode<T, U>* begin() { return mNode.mNext; }
		SDK_INLINE qNode<T, U>* end() { return &mNode; }
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
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

		SDK_INLINE T* prev() { return static_cast<T*>(mPrev); }
		SDK_INLINE T* next() { return static_cast<T*>(mNext); }
		SDK_INLINE T* type() { return static_cast<T*>(this); }
	};

	template <typename T, typename U = T>
	class qList
	{
	public:
		qNode<T, U> mNode;

		SDK_INLINE bool IsEmpty() { return mNode.mNext == &mNode; }
		SDK_INLINE T* back() { return mNode.prev(); }
		SDK_INLINE T* begin() { return mNode.next(); }
		SDK_INLINE T* end() { return static_cast<T*>(&mNode); }
	};
}
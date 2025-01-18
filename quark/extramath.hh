#pragma once

namespace UFG
{
	template <typename T>
	class RingBuffer
	{
	public:
		int mLast;
		int mCount;
		int mCapacity;
		T* mData;
	};

	template <typename T>
	class HistoryItem
	{
		T mValue;
		u32 nTimeStamp;
	};

	template <typename T>
	class HistoryBuffer
	{
	public:
		float fDuration;
		u32 nTimeStamp;
		RingBuffer<HistoryItem<T>> mRingBuffer;
	};

	template <typename T>
	class LinearGraph
	{
	public:
		int nData;
		const f32* fDomain;
		T* tRange;
	};
}
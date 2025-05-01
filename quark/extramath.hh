#pragma once

namespace UFG
{
	template <typename T>
	class HomerCubicBase
	{
	public:
		T mDuration;
		T mParameter;
		T A;
		T B;
		T C;
		T D;
		T p0;
		T p1;
		T v0;
		T v1;
	};

	template <typename T>
	class HomerCubic : public HomerCubicBase<T>{};

	template <>
	class HomerCubic<f32> : public HomerCubicBase<f32>
	{
	public:
		void MakeCoeffs() { SDK_CALL_FUNC(void, 0x3C6BB0, void*)(this); }
		void Update(f32 f_elapsed_seconds) { SDK_CALL_FUNC(void, 0x3CF7F0, void*, f32)(this, f_elapsed_seconds); }
	};

	template <>
	class HomerCubic<qVector3> : public HomerCubicBase<qVector3>
	{
	public:
		void MakeCoeffs() { SDK_CALL_FUNC(void, 0xB9CC0, void*)(this); }
		void SetDesiredPosition(const qVector3& position) { SDK_CALL_FUNC(void, 0x3CBF90, void*, const qVector3&)(this, position); }
		void SetDuration(const qVector3& duration) { SDK_CALL_FUNC(void, 0x3CC070, void*, const qVector3&)(this, duration); }
	};

	class HomerCubicAngular
	{
	public:
		HomerCubic<f32> mHomerCubic;
		f32 mModuloRecip;
		f32 mModulo;
	};

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
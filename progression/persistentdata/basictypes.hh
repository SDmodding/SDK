#pragma once

namespace UFG::PersistentData
{
	enum ListType
	{
		LT_NONE,
		LT_BOOL,
		LT_INT,
		LT_INT64,
		LT_FLOAT
	};

	class Binary
	{
	public:
		void* mpBuffer;
		u32 mSize;
	};

	class Bool
	{
	public:
		bool mValue;
	};

	class Float
	{
	public:
		f32 mValue;
	};

	class FloatRanged
	{
	public:
		f32 mValue;
		f32 mRange;
	};

	class ID
	{
	public:
		qSymbol mValue;
	};

	class Int
	{
	public:
		int mValue;
	};

	class IntRanged
	{
	public:
		int mValue;
		int mRange;
	};

	class KeyBinary
	{
	public:
		qSymbol mKey;
		Binary mBinary;
	};

	class KeyValue
	{
	public:
		qSymbol mKey;

		union
		{
			f32 mFloatValue;
			int mIntValue;
			bool mBoolValue;
		};
	};

	class KeyValue64
	{
	public:
		qSymbol mKey;
		u64 mIntValue;
	};

	class List
	{
	public:
		ListType mType;

		union
		{
			qArray<int>* mIntList;
			qArray<i64>* mInt64List;
			qArray<bool>* mBoolList;
			qArray<f32>* mFloatList;
			void* mListInternal;
		};
	};

	class MapBinary
	{
	public:
		struct Iterator
		{
			u32 mIndex;
			MapBinary* mList;
		};

		qArray<KeyBinary> mValues;
		int mPersistentDataType;
	};

	class MapBool
	{
	public:
		enum KeepType : s32
		{
			KEEP_BOTH,
			KEEP_TRUE,
			KEEP_FALSE
		};

		struct Iterator
		{
			u32 mIndex;
			MapBool* mList;
		};

		KeepType mKeepType;
		qArray<KeyValue> mValues;
		qArray<qSymbol> mNames;
		int mPersistentDataType;
	};

	class MapFloat
	{
	public:
		struct Iterator
		{
			u32 mIndex;
			MapFloat* mList;
		};

		qArray<KeyValue> mValues;
		int mPersistentDataType;
	};

	class MapInt
	{
	public:
		struct Iterator
		{
			u32 mIndex;
			MapInt* mList;
		};

		qArray<KeyValue> mValues;
		int mPersistentDataType;
	};

	class MapUInt64
	{
	public:
		struct Iterator
		{
			unsigned int mIndex;
			MapUInt64* mList;
		};

		qArray<KeyValue64> mValues;
		int mPersistentDataType;
	};

	class String
	{
	public:
		qString mValue;
	};

	class Time
	{
	public:
		SimpleTimer mTimer;
	};

	class UInt64
	{
	public:
		u64 mValue;
	};
}
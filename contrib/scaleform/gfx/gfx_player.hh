#pragma once

namespace Scaleform::GFx
{
	class MovieImpl;
	class Value;

	class MovieDef : public Resource, public StateBag
	{
	public:
	};

	class Movie : public RefCountBase<Movie, StatMV_Other_Mem>, public StateBag
	{
	public:
		Ptr<ASMovieRootBase> pASMovieRoot;

		void CreateString(Value* pvalue, const char* pstring) { SDK_CALL_FUNC(void, 0x8C3AB0, void*, Value*, const char*)(this, pvalue, pstring); }
		bool Invoke(const char* pmethodName, Value* presult, const Value* pargs, u32 numArgs) { 
			return SDK_CALL_FUNC(bool, 0x8E6DE0, void*, const char*, Value*, const Value*, u32)(this, pmethodName, presult, pargs, numArgs);
		}
	};

	//----------------------------
	//	Value
	//----------------------------

	class Value : ListNode<Value>
	{
	public:
		enum ValueType 
		{
			VT_Undefined = 0x00,
			VT_Null = 0x01,
			VT_Boolean = 0x02,
			VT_Int = 0x03,
			VT_UInt = 0x04,
			VT_Number = 0x05,
			VT_String = 0x06,
			VT_StringW = 0x07,
			VT_Object = 0x08,
			VT_Array = 0x09,
			VT_DisplayObject = 0x0a,
			VT_Closure = 0x0b,

			VTC_ConvertBit = 0x80,
			VT_ConvertBoolean = VTC_ConvertBit | VT_Boolean,
			VT_ConvertInt = VTC_ConvertBit | VT_Int,
			VT_ConvertUInt = VTC_ConvertBit | VT_UInt,
			VT_ConvertNumber = VTC_ConvertBit | VT_Number,
			VT_ConvertString = VTC_ConvertBit | VT_String,
			VT_ConvertStringW = VTC_ConvertBit | VT_StringW
		};

		union ValueUnion
		{
			int IValue;
			u32 UIValue;
			long double NValue;
			bool BValue;
			const char* pString;
			const char** pStringManaged;
			const wchar_t* pStringW;
			void* pData;
		};

		class ObjectInterface : public NewOverrideBase<StatMV_Other_Mem>
		{
		public:
			MovieImpl* pMovieRoot;
			List<Value> ExternalObjRefs;

			virtual ~ObjectInterface() = 0;
		};

		ObjectInterface* pObjectInterface = 0;
		ValueType Type = VT_Undefined;
		ValueUnion mValue;
		u64 DataAux;

		const Value& operator=(const Value& src) { return SDK_CALL_FUNC(const Value&, 0x5CEE00, void*, const Value&)(this, src); }

		/* Impl Functions */

		SDK_INLINE void SetString(const char* str) 
		{ 
			Type = VT_String;
			mValue.pString = str;
		}

		SDK_INLINE void SetBool(bool v)
		{
			Type = VT_Boolean;
			mValue.BValue = v;
		}

		SDK_INLINE void SetInt(int v)
		{
			Type = VT_Int;
			mValue.IValue = v;
		}

		SDK_INLINE void SetNull()
		{
			Type = VT_Null;
			mValue.pData = 0;
		}

		SDK_INLINE void SetNumber(double v)
		{
			Type = VT_Number;
			mValue.NValue = v;
		}

		SDK_INLINE void SetNumber(long v)
		{
			Type = VT_Number;
			mValue.NValue = v;
		}

		SDK_INLINE void SetUInt32(u32 v)
		{
			Type = VT_UInt;
			mValue.UIValue = v;
		}

		SDK_INLINE void SetUndefined()
		{
			Type = VT_Undefined;
			mValue.pData = 0;
		}
	};
}
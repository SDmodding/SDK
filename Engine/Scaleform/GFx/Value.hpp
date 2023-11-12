#pragma once

namespace Scaleform
{
	namespace GFx
	{
		class Value : public ListNode<Value>
		{
		public:
			enum ValueType
			{
				VT_Undefined = 0x0,
				VT_Null = 0x1,
				VT_Boolean = 0x2,
				VT_Int = 0x3,
				VT_UInt = 0x4,
				VT_Number = 0x5,
				VT_String = 0x6,
				VT_StringW = 0x7,
				VT_Object = 0x8,
				VT_Array = 0x9,
				VT_DisplayObject = 0xA,
				VT_Closure = 0xB,
				VT_ConvertBoolean = 0x82,
				VT_ConvertInt = 0x83,
				VT_ConvertUInt = 0x84,
				VT_ConvertNumber = 0x85,
				VT_ConvertString = 0x86,
				VT_ConvertStringW = 0x87,
			};

			union ValueUnion
			{
				int IValue;
				unsigned int UIValue;
				long double NValue;
				bool BValue;
				const char* pString;
				const char** pStringManaged;
				const wchar_t* pStringW;
				void* pData;
			};

			class ObjectInterface
			{
			public:
				void* vfptr;
				class MovieImpl* pMovieRoot;
				List<Value> ExternalObjRefs;
			};
			ObjectInterface* pObjectInterface = nullptr;
			ValueType Type = VT_Undefined;
			ValueUnion mValue = { 0 };
			uint64_t DataAux = 0;

			__inline void SetNull()
			{
				Type = VT_Null;
				mValue.pData = nullptr;
			}

			__inline void SetBoolean(bool p_Value)
			{
				Type = VT_Boolean;
				mValue.BValue = p_Value;
			}

			__inline void SetInt(int p_Value)
			{
				Type = VT_Int;
				mValue.IValue = p_Value;
			}

			__inline void SetUInt(uint32_t p_Value)
			{
				Type = VT_UInt;
				mValue.UIValue = p_Value;
			}

			__inline void SetNumber(float p_Value)
			{
				Type = VT_Number;
				mValue.NValue = static_cast<long double>(p_Value);
			}

			__inline void SetNumber(double p_Value)
			{
				Type = VT_Number;
				mValue.NValue = static_cast<long double>(p_Value);
			}

			void SetString(ASString* p_Str)
			{
				reinterpret_cast<void(__fastcall*)(void*, ASString*)>(UFG_RVA(0x71C3D0))(this, p_Str);
			}
		};
	}
}
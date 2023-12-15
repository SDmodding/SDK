#pragma once

namespace UFG
{
	enum ePropertyType : uint8_t
	{
		ePropertyType_Int8 = 0,
		ePropertyType_Int16,
		ePropertyType_Int32,
		ePropertyType_Int64,
		ePropertyType_Int128,
		ePropertyType_UInt8,
		ePropertyType_UInt16,
		ePropertyType_UInt32,
		ePropertyType_UInt64,
		ePropertyType_Bool,
		ePropertyType_Float,
		ePropertyType_Double,
		ePropertyType_String,
		ePropertyType_RangedFloat,
		ePropertyType_RangedUInt32,
		ePropertyType_RangedInt32,
		ePropertyType_WeightedList,
		ePropertyType_qVector2,
		ePropertyType_qVector3,
		ePropertyType_qVector4,
		ePropertyType_qMatrix44,
		ePropertyType_qResHandle,
		ePropertyType_qSymbol,
		ePropertyType_qSymbolUC,
		ePropertyType_qWiseSymbol,
		ePropertyType_List,
		ePropertyType_PropertySet,
		ePropertyType_TransRot,
		ePropertyType_qTransQuat,
		ePropertyType_Invalid,
		ePropertyType_COUNT
	};

	struct Property_t
	{
		uint32_t m_Bits;
		uint32_t m_NameUID;

		ePropertyType GetTypeUID()
		{
			return reinterpret_cast<ePropertyType*>(&m_Bits)[3];
		}

		int64_t GetDataOffset()
		{
			return static_cast<int64_t>(m_Bits & 0xFFFFFF);
		}
	};

	struct PropertySetHandle_t : ResourceHandle_t
	{

	};

	struct PropertySet_t
	{
		uint32_t m_Flags;

		UFG_PAD(0x4);

		int64_t m_Owner;

		UFG_PAD(0x10);

		int64_t m_Parents;
		int64_t m_Values;
		int64_t m_DefaultBits;
		int64_t m_Properties;

		uint32_t m_Name;
		uint16_t m_NumParents;
		uint32_t m_ParentMask;
		uint32_t m_SchemaName;
		uint32_t m_PropertyMask;
		uint16_t m_NumDataBytes;
		uint16_t m_NumProperties;

		PropertySetHandle_t* GetParents()
		{
			if (!m_Parents)
				return nullptr;

			return reinterpret_cast<PropertySetHandle_t*>(reinterpret_cast<uintptr_t>(&m_Parents) + m_Parents);
		}

		uint8_t* GetValuesPtr()
		{
			if (!m_Values)
				return nullptr;

			return reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(&m_Values) + m_Values);
		}

		Property_t* GetProperties()
		{
			if (!m_Properties)
				return nullptr;

			return reinterpret_cast<Property_t*>(reinterpret_cast<uintptr_t>(&m_Properties) + m_Properties);
		}

		int64_t* GetValuePtr(Property_t* p_Property)
		{
			uint8_t* m_ValuesPtr = GetValuesPtr();
			if (!m_ValuesPtr)
				return nullptr;

			return reinterpret_cast<int64_t*>(&m_ValuesPtr[p_Property->GetDataOffset()]);
		}

		template <typename T>
		T* GetValue(Property_t* p_Property)
		{
			int64_t* m_ValuePtr = GetValuePtr(p_Property);
			if (!m_ValuePtr)
				return nullptr;

			return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(m_ValuePtr) + *m_ValuePtr);
		}

		Property_t* GetPropertyByName(uint32_t p_NameUID)
		{
			Property_t* m_Properties = GetProperties();
			if (m_Properties)
			{
				for (uint16_t i = 0; m_NumProperties > i; ++i)
				{
					Property_t* m_Property = &m_Properties[i];
					if (m_Property->m_NameUID == p_NameUID)
						return m_Property;
				}
			}

			return nullptr;
		}
	};

	struct PropertySetResource_t : ResourceData_t // TypeUID: 0x5B9BF81E
	{
		uint32_t m_Flags;
		uint32_t m_SourceCRC;
		int64_t m_NameString;
		PropertySet_t m_Data;
	};

	struct PropertyList_t
	{
		UFG_PAD(0x10);

		int64_t m_Values;
		uint32_t m_TypeUID;
		uint32_t m_ElementSize;
		int64_t m_Weights;
		uint32_t m_NumElements;
		uint32_t m_TotalWeight;

		uint8_t* GetValuesPtr()
		{
			if (!m_Values)
				return nullptr;

			return reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(&m_Values) + m_Values);
		}

		template <typename T>
		T* GetValue(uint32_t p_Index)
		{
			if (p_Index >= m_NumElements)
				return nullptr;

			uint8_t* m_Values = GetValuesPtr();
			if (!m_Values)
				return nullptr;

			return reinterpret_cast<T*>(&m_Values[p_Index * m_ElementSize]);
		}
	};
}
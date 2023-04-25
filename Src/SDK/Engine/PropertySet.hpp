#pragma once

namespace UFG
{
	struct qPropertySetResource;
	struct qPropertyList;
	struct qPropertySet;

	struct qProperty
	{
		uint32_t mTypeUIDOffsetChanged;
		uint32_t mNameUID;

		ePropertyTypeEnum GetTypeUID()
		{
			return reinterpret_cast<ePropertyTypeEnum(__fastcall*)(void*)>(UFG_RVA(0x1F84E0))(this);
		}

		uintptr_t GetDataOffset()
		{
			return reinterpret_cast<uintptr_t(__fastcall*)(void*)>(UFG_RVA(0x1F6D10))(this);
		}
	};

	struct qPropertySetHandle
	{
		UFG_PAD(0x10);

		void* mData;
		uint32_t mNameUID;
		uint32_t mTailPad;

		qPropertySet* Get()
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(void*)>(UFG_RVA(0x1F6680))(this);
		}
	};

	struct qPropertySet
	{
		uint32_t mFlags;

		UFG_PAD(0x1C);

		uintptr_t* mParents;
		uintptr_t* mValues;
		uintptr_t* mDefaultBits;
		uintptr_t* mProperties;

		qSymbol mName;
		uint16_t mRefCount;
		uint16_t mNumParents;
		uint32_t mParentMask;
		qSymbol mSchemaName;
		uint32_t mPropertyMask;
		uint16_t mNumDataBytes;
		uint16_t mNumProperties;

		const char* GetNameDebug()
		{
			return reinterpret_cast<const char*(__fastcall*)(void*)>(UFG_RVA(0x1F6F60))(this);
		}

		qProperty* GetPropertyByIndex(uint32_t m_Index)
		{
			uintptr_t m_Offset = reinterpret_cast<uintptr_t>(mProperties);
			qProperty* m_Properties = reinterpret_cast<qProperty*>(reinterpret_cast<uintptr_t>(&mProperties) + m_Offset);

			return &m_Properties[m_Index];
		}

		uintptr_t* GetValuePtrByIndex(uint32_t m_Index)
		{
			qProperty* m_Property = GetPropertyByIndex(m_Index);
			uintptr_t m_PropertyData = m_Property->GetDataOffset();
			uintptr_t m_ValueOffset = reinterpret_cast<uintptr_t>(mValues);

			if (m_ValueOffset)
			{
				uintptr_t m_ValueData = (reinterpret_cast<uintptr_t>(&mValues) + m_ValueOffset);
				return reinterpret_cast<uintptr_t*>(m_PropertyData + m_ValueData);
			}

			return reinterpret_cast<uintptr_t*>(m_PropertyData);
		}

		qPropertySet* GetParentByIndex(uint32_t m_Index)
		{
			uintptr_t m_Offset = reinterpret_cast<uintptr_t>(mParents);
			qPropertySetHandle* m_Parents = reinterpret_cast<qPropertySetHandle*>(reinterpret_cast<uintptr_t>(&mParents) + m_Offset);
			qPropertySetHandle* m_Parent = &m_Parents[m_Index];

			return m_Parent->Get();
		}

		uintptr_t GetMemImagePtr()
		{
			return reinterpret_cast<uintptr_t(__fastcall*)(void*)>(UFG_RVA(0x1F6F00))(this);
		}

		bool* GetBool(qSymbol propName, uint32_t depth = 0x1)
		{
			return reinterpret_cast<bool*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1EA610))(this, &propName, depth);
		}

		const char* GetString(qSymbol propName, uint32_t depth = 0x1)
		{
			return reinterpret_cast<const char*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x236A50))(this, &propName, depth);
		}

		int* GetInt(qSymbol propName, uint32_t depth = 0x1)
		{
			return reinterpret_cast<int*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1E98E0))(this, &propName, depth);
		}

		uint32_t* GetUint32(qSymbol propName, uint32_t depth = 0x1)
		{
			return reinterpret_cast<uint32_t*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1E99A0))(this, &propName, depth);
		}

		float* GetFloat(qSymbol propName, uint32_t depth = 0x1)
		{
			return reinterpret_cast<float*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1E9A60))(this, &propName, depth);
		}

		qSymbol* GetSymbol(qSymbol propName, uint32_t depth = 0x1)
		{
			return reinterpret_cast<qSymbol*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1E9FF0))(this, &propName, depth);
		}

		qPropertySet* GetSet(qSymbol name, uint32_t depth = 0x1)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(qPropertySet*, qSymbol*, uint32_t)>(UFG_RVA(0x1E9EF0))(this, &name, depth);
		}

		qPropertyList* GetList(qSymbol name, uint32_t depth = 0x1)
		{
			return reinterpret_cast<qPropertyList*(__fastcall*)(qPropertySet*, qSymbol*, uint32_t)>(UFG_RVA(0x1E9E60))(this, &name, depth);
		}

		void SetSymbol(qSymbol m_Name, qSymbol m_Value)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*, qSymbol*)>(UFG_RVA(0x1EB070))(this, &m_Name, &m_Value);
		}

		bool HasResource() { return (mFlags & 1); }

		qPropertySetResource* GetResource()
		{
			if (!HasResource())
				return nullptr;

			return reinterpret_cast<qPropertySetResource*>(reinterpret_cast<uintptr_t>(this) - 0x68);
		}
	};

	struct qPropertySetResource : qResourceData
	{
		uint32_t mFlags;
		uint32_t mSourceCRC;
		const char* mNameString;
		qPropertySet mData;

		qPropertySet* GetPropertySet() { return &mData; }
	};

	struct qPropertyList
	{
		UFG_PAD(0x28);

		uint32_t mNumElements;

		const char* GetString(uint32_t index)
		{
			return reinterpret_cast<const char*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x1E9AB0))(this, index);
		}

		qSymbol* GetSymbol(uint32_t index)
		{
			return reinterpret_cast<qSymbol*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x1E9F80))(this, index);
		}

		qPropertySet* GetValuePtr(uint32_t type_uid, uint32_t index)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(qPropertyList*, uint32_t, uint32_t)>(UFG_RVA(0x1F8920))(this, type_uid, index);
		}

		qPropertySet* GetProperty(uint32_t type_uid, uint32_t index)
		{
			uintptr_t* m_Item = reinterpret_cast<uintptr_t*>(GetValuePtr(type_uid, index));
			if (!m_Item || !*m_Item)
				return nullptr;

			return reinterpret_cast<qPropertySet*>(reinterpret_cast<uintptr_t>(m_Item) + *m_Item);
		}

		qPropertySet* Find(qSymbol symbol)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(qPropertyList*, qSymbol*)>(UFG_RVA(0x464730))(this, &symbol);
		}
	};

	namespace PropertySet
	{
		qPropertySet* Get(qSymbol m_Hash)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(qSymbol*)>(UFG_RVA(0x1F75F0))(&m_Hash);
		}

		qPropertyList* GetList(qPropertySet* set, qSymbol name, uint32_t depth = 0x1)
		{
			return reinterpret_cast<qPropertyList*(__fastcall*)(qPropertySet*, qSymbol*, uint32_t)>(UFG_RVA(0x1E9E60))(set, &name, depth);
		}
	}

	class CPropertySetHandle
	{
	public:
		qSymbol mName;
		qPropertySet* mpPropSet;

		void Bind()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1F20C0))(this);
		}
	};
}
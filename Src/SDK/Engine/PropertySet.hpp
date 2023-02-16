#pragma once

namespace UFG
{
	struct qPropertySetResource;
	struct qPropertyList;
	struct qPropertySet
	{
		uint32_t mFlags;

		UFG_PAD(0x3C);

		qSymbol mName;
		uint16_t mRefCount;
		uint16_t mNumParents;
		uint32_t mParentMask;
		qSymbol mSchemaName;
		uint32_t mPropertyMask;
		uint16_t mNumDataBytes;
		uint16_t mNumProperties;

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

		qPropertyList* GetList(qSymbol name, uint32_t depth = 0x1)
		{
			return reinterpret_cast<qPropertyList*(__fastcall*)(qPropertySet*, qSymbol*, uint32_t)>(UFG_RVA(0x1E9E60))(this, &name, depth);
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

			return reinterpret_cast<UFG::qPropertySet*>(reinterpret_cast<uintptr_t>(m_Item) + *m_Item);
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
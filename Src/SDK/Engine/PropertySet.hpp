#pragma once

namespace UFG
{
	struct qPropertySet;
	struct qPropertySetResource
	{
		qBaseNodeRB m_Node;
		UFG_PAD(0x14);
		char m_Name[0x24];
		unsigned int mFlags;
		unsigned int mSourceCRC;

		qPropertySet* GetProperty()
		{
			return reinterpret_cast<qPropertySet*>(reinterpret_cast<uintptr_t>(this) + 0x68);
		}
	};

	struct qPropertySet
	{
		UFG_PAD(0x40);
		qSymbol m_Hash;

		const char* GetString(qSymbol propName, uint32_t depth = 0x1)
		{
			return reinterpret_cast<const char*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x236A50))(this, &propName, depth);
		}

		qSymbol* GetSymbol(qSymbol propName, uint32_t depth = 0x1)
		{
			return reinterpret_cast<qSymbol*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1E9FF0))(this, &propName, depth);
		}

		qPropertySetResource* GetResource()
		{
			return reinterpret_cast<qPropertySetResource*>(reinterpret_cast<uintptr_t>(this) - 0x68);
		}
	};

	struct qPropertyList
	{
		UFG_PAD(0x28);

		int mNumElements;

		qPropertySet* GetValuePtr(uint32_t type_uid, uint32_t index)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(qPropertyList*, uint32_t, uint32_t)>(UFG_RVA(0x1F8920))(this, type_uid, index);
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
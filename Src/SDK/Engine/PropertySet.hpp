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

		qPropertySetResource* GetResource()
		{
			return reinterpret_cast<qPropertySetResource*>(reinterpret_cast<uintptr_t>(this) - 0x68);
		}
	};

	namespace PropertySet
	{
		qPropertySet* Get(qSymbol m_Hash)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(qSymbol*)>(UFG_RVA(0x1F75F0))(&m_Hash);
		}
	}
}
#pragma once

// Components
#include "Components/PhysicsMoverComponent.hh"

// ...
namespace UFG
{
	struct qPropertySet;
	struct qPropertySetResource;
}
#include "Collection.hh"
#include "Handle.hh"
#include "List.hh"

namespace UFG
{
	struct qProperty
	{
		uint32_t mTypeUIDOffsetChanged;
		uint32_t mNameUID;

		UFG_INLINE ePropertyTypeEnum GetTypeUID()
		{
			return reinterpret_cast<ePropertyTypeEnum(__fastcall*)(void*)>(UFG_RVA(0x1F84E0))(this);
		}

		UFG_INLINE uintptr_t GetDataOffset()
		{
			return reinterpret_cast<uintptr_t(__fastcall*)(void*)>(UFG_RVA(0x1F6D10))(this);
		}
	};

	struct qPropertySet : qPropertyCollection, qNode<qPropertySet>
	{
		qOffset64<qPropertySetHandle> mParents;
		qOffset64<uint8_t> mValues;
		qOffset64<uint32_t> mDefaultBits;
		qOffset64<qProperty> mProperties;
		qSymbol mName;
		uint16_t mRefCount;
		uint16_t mNumParents;	
		uint32_t mParentMask;
		qSymbol mSchemaName;
		uint32_t mPropertyMask;
		uint16_t mNumDataBytes;
		uint16_t mNumProperties;

		//================================================================
		// Parent

		UFG_INLINE bool AppendParentLocal(qPropertySet* p_ParentPropertySet)
		{
			return (reinterpret_cast<uint32_t(__fastcall*)(void*, qPropertySet*)>(UFG_RVA(0x1F1E70))(this, p_ParentPropertySet) != UINT32_MAX);
		}

		UFG_INLINE qPropertySet* GetParentFromIdx(uint32_t p_Index)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x1F6FB0))(this, p_Index);
		}

		UFG_INLINE void RemoveParent(qSymbol p_ParentName)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x1FB9A0))(this, &p_ParentName);
		}

		UFG_INLINE void RemoveParentsAll()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1FBD40))(this);
		}

		//================================================================
		// Property

		UFG_INLINE qProperty* GetPropertyFromIdx(uint32_t p_Index)
		{
			qProperty* m_Properties = mProperties.GetPointer();
			if (!m_Properties)
				return nullptr;

			return &m_Properties[p_Index];
		}

		UFG_INLINE void RemovePropertyByName(qSymbol p_Name)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x1FC160))(this, &p_Name);
		}

		//================================================================
		// Value

		UFG_INLINE int64_t GetValuePtr(uint32_t p_TypeUID, uint32_t p_NameUID, uint32_t p_Depth = 1)
		{
			return reinterpret_cast<int64_t(__fastcall*)(void*, uint32_t, uint32_t, uint32_t, void*)>(UFG_RVA(0x1F8990))(this, p_TypeUID, p_NameUID, p_Depth, nullptr);
		}

		UFG_INLINE uintptr_t* GetValuePtrFromIdx(uint32_t p_Index)
		{
			qProperty* m_Property = GetPropertyFromIdx(p_Index);
			if (!m_Property) {
				return nullptr;
			}

			uint8_t* m_Values = mValues.GetPointer();
			if (!m_Values) {
				return nullptr;
			}

			return reinterpret_cast<uintptr_t*>(&m_Values[m_Property->GetDataOffset()]);
		}

		template <typename T = uintptr_t>
		UFG_INLINE T GetMemImagePtr()
		{
			return reinterpret_cast<T(__fastcall*)(void*)>(UFG_RVA(0x1F6F00))(this);
		}

		//================================================================
		// Bool

		UFG_INLINE bool* GetBool(qSymbol p_PropName, uint32_t p_Depth = 1)
		{
			return reinterpret_cast<bool*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1EA610))(this, &p_PropName, p_Depth);
		}

		UFG_INLINE void SetBool(qSymbol p_PropName, bool p_Value)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1EB270))(this, &p_PropName, p_Value);
		}

		//================================================================
		// String

		UFG_INLINE const char* GetString(qSymbol p_PropName, uint32_t p_Depth = 1)
		{
			return reinterpret_cast<const char*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x236A50))(this, &p_PropName, p_Depth);
		}

		UFG_INLINE void SetString(qSymbol p_PropName, const char* p_Str)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*, const char*)>(UFG_RVA(0x1EAE90))(this, &p_PropName, p_Str);
		}

		//================================================================
		// Int

		UFG_INLINE int* GetInt(qSymbol p_PropName, uint32_t p_Depth = 1)
		{
			return reinterpret_cast<int*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1E98E0))(this, &p_PropName, p_Depth);
		}

		UFG_INLINE void SetInt(qSymbol p_PropName, int p_Value)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*, int)>(UFG_RVA(0x1EADD0))(this, &p_PropName, p_Value);
		}

		//================================================================
		// UInt32

		UFG_INLINE uint32_t* GetUInt32(qSymbol p_PropName, uint32_t p_Depth = 1)
		{
			return reinterpret_cast<uint32_t*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1E99A0))(this, &p_PropName, p_Depth);
		}

		//================================================================
		// Float

		UFG_INLINE float* GetFloat(qSymbol p_PropName, uint32_t p_Depth = 1)
		{
			return reinterpret_cast<float*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1E9A60))(this, &p_PropName, p_Depth);
		}

		//================================================================
		// Symbol

		UFG_INLINE qSymbol* GetSymbol(qSymbol p_PropName, uint32_t p_Depth = 1)
		{
			return reinterpret_cast<qSymbol*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1E9FF0))(this, &p_PropName, p_Depth);
		}

		UFG_INLINE void SetSymbol(qSymbol p_PropName, qSymbol p_Symbol)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*, qSymbol*)>(UFG_RVA(0x1EB070))(this, &p_PropName, &p_Symbol);
		}

		//================================================================
		// WiseSymbol

		UFG_INLINE qWiseSymbol* GetWiseSymbol(qSymbol p_PropName, uint32_t p_Depth = 1)
		{
			return reinterpret_cast<qWiseSymbol*(__fastcall*)(void*, qSymbol*, uint32_t)>(UFG_RVA(0x1EA3B0))(this, &p_PropName, p_Depth);
		}

		UFG_INLINE void SetWiseSymbol(qSymbol p_PropName, qWiseSymbol p_WiseSymbol)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*, qWiseSymbol*)>(UFG_RVA(0x1EB1B0))(this, &p_PropName, &p_WiseSymbol);
		}

		//================================================================
		// PropertySet

		UFG_INLINE qPropertySet* GetPropertySet(qSymbol p_PropName, uint32_t p_Depth = 1)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(qPropertySet*, qSymbol*, uint32_t)>(UFG_RVA(0x1E9EF0))(this, &p_PropName, p_Depth);
		}

		UFG_INLINE void SetPropertySet(qSymbol p_PropName, qPropertySet* p_PropertySet)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*, qPropertySet*)>(UFG_RVA(0x1EB030))(this, &p_PropName, p_PropertySet);
		}

		//================================================================
		// PropertyList

		UFG_INLINE qPropertyList* GetPropertyList(qSymbol p_PropName, uint32_t p_Depth = 1)
		{
			return reinterpret_cast<qPropertyList*(__fastcall*)(qPropertySet*, qSymbol*, uint32_t)>(UFG_RVA(0x1E9E60))(this, &p_PropName, p_Depth);
		}

		UFG_INLINE void SetPropertyList(qSymbol p_PropName, qPropertyList* p_PropertyList)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*, qPropertyList*)>(UFG_RVA(0x1EAFE0))(this, &p_PropName, p_PropertyList);
		}

		//================================================================
		// Resource

		UFG_INLINE bool IsResourceSet()
		{ 
			return (HIWORD(mFlags) & 1);
		}

		UFG_INLINE qPropertySetResource* GetResource()
		{
			if (!IsResourceSet())
				return nullptr;

			return reinterpret_cast<qPropertySetResource*>(reinterpret_cast<uintptr_t>(this) - (sizeof(qPropertySet) + 0x10));
		}
	};
	UFG_ASSERT_STRUCT(qPropertySet, 88);

	struct qPropertySetResource : qResourceData
	{
		uint32_t mFlags;
		uint32_t mSourceCRC;
		qOffset64<const char> mNameString;
		qPropertySet mData;

		UFG_INLINE qPropertySet* GetPropertySet()
		{
			return &mData;
		}
	};
	UFG_ASSERT_STRUCT(qPropertySetResource, 192);

	//==========================================================================

	namespace PropertySetCache
	{
		UFG_INLINE qPropertySetResource* GetResource(qSymbol p_NameUID)
		{
			return reinterpret_cast<qPropertySetResource*(__fastcall*)(qSymbol*)>(UFG_RVA(0x1F8090))(&p_NameUID);
		}
	}

	namespace PropertySetManager
	{
		/*	
		*	This crap is kinda un - safe since if you Create PropertySet it will set prefix & suffix with '·' for ResourceSet.
		*	Simply calling this function twice with same nameUID will create new propertyset twice even tho it already exist.
		*	~ If you will use this function first try call GetPropertySet with nameUID with prefix & suffix otherwise use this function.
		*/
		UFG_INLINE qPropertySet* CreateOrFindPropertySet(qSymbol p_NameUID)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(qSymbol*)>(UFG_RVA(0x1F4680))(&p_NameUID);
		}

		UFG_INLINE qPropertySet* GetPropertySet(qSymbol p_NameUID)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(qSymbol*)>(UFG_RVA(0x1F75F0))(&p_NameUID);
		}
	}
}
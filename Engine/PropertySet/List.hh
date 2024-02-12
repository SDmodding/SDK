#pragma once

namespace UFG
{
	struct qPropertyList : qPropertyCollection
	{
		UFG::qOffset64<uint8_t> mValues;
		uint32_t mTypeUID;
		uint32_t mElementSize;
		UFG::qOffset64<uint32_t> mWeights;
		uint32_t mNumElements;
		uint32_t mTotalWeight;

		static UFG_INLINE qPropertyList* Create(const char* p_DbgStr = UFG_CONST_CHAR(0x168E064))
		{
			return reinterpret_cast<qPropertyList*(__fastcall*)(const char*)>(UFG_RVA(0x1F4060))(p_DbgStr);
		}

		//=====================================================================

		UFG_INLINE void AddString(const char* p_String)
		{
			reinterpret_cast<void(__fastcall*)(qPropertyList*, const char*)>(UFG_RVA(0x1E8CB0))(this, p_String);
		}

		UFG_INLINE const char* GetString(uint32_t p_Index)
		{
			return reinterpret_cast<const char*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x1E9AB0))(this, p_Index);
		}

		//=====================================================================

		UFG_INLINE void AddSymbol(qSymbol p_Symbol)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x1E8D50))(this, &p_Symbol);
		}

		UFG_INLINE qSymbol* GetSymbol(uint32_t p_Index)
		{
			return reinterpret_cast<qSymbol*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x1E9F80))(this, p_Index);
		}

		//=====================================================================

		UFG_INLINE qPropertySet* GetValuePtr(uint32_t p_Index)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(qPropertyList*, uint32_t, uint32_t)>(UFG_RVA(0x1F8920))(this, mTypeUID, p_Index);
		}

		UFG_INLINE qPropertySet* GetProperty(uint32_t p_Index)
		{
			uintptr_t* m_Item = reinterpret_cast<uintptr_t*>(GetValuePtr(p_Index));
			if (!m_Item || !*m_Item) {
				return nullptr;
			}

			return reinterpret_cast<qPropertySet*>(reinterpret_cast<uintptr_t>(m_Item) + *m_Item);
		}

		UFG_INLINE qPropertySet* Find(qSymbol p_Symbol)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(qPropertyList*, qSymbol*)>(UFG_RVA(0x464730))(this, &p_Symbol);
		}

		UFG_INLINE void RemoveAll()
		{
			reinterpret_cast<void(__fastcall*)(qPropertyList*)>(UFG_RVA(0x1FB810))(this);
		}
	};
	UFG_ASSERT_STRUCT(qPropertyList, 48);
}
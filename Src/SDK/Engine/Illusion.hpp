#pragma once
#define IllusionParamOverride_VehiclePaint 0xC6D01635

namespace Illusion
{
	class CStateBlock
	{
	public:
		UFG_PAD(0x18);

		uint32_t m_UID;

		UFG_PAD(0x18);

		char m_DebugName[0x24];

		UFG_PAD(0x10);

		uint32_t mParentUID;
		uint32_t mDataByteSize;
		uint32_t mNumValues;
		uint32_t mNameUID;

		uintptr_t GetDataPointer() { return (reinterpret_cast<uintptr_t>(this) + 0x80); }
	};

	class CStateBlockItter
	{
	public:
		UFG_PAD(0x34);

		char m_DebugName[0x24];

		UFG_PAD(0x1C);

		uint32_t m_UID;
	};

	class CStateBlockInventory
	{
	public:
		CStateBlockItter* Itter(CStateBlockItter* m_Itter)
		{
			uintptr_t m_This = reinterpret_cast<uintptr_t>(this);
			CStateBlockItter* m_ItterEnd = *reinterpret_cast<CStateBlockItter**>(m_This + 0xC8);

			if (m_Itter)
			{
				uintptr_t m_ItterAddress = reinterpret_cast<uintptr_t>(m_Itter);
				m_Itter = reinterpret_cast<CStateBlockItter*>(*reinterpret_cast<uintptr_t*>(m_ItterAddress + 0x60) - 0x58);
			}
			else
				m_Itter = reinterpret_cast<CStateBlockItter*>(*reinterpret_cast<uintptr_t*>(m_This + 0x128) - 0x58);

			if (m_Itter == m_ItterEnd)
				return nullptr;

			return m_Itter;
		}

		void Add(CStateBlock* m_StateBlock)
		{
			reinterpret_cast<void(__fastcall*)(void*, CStateBlock*)>(UFG_RVA(0x8DE00))(this, m_StateBlock);
		}

		void Remove(CStateBlock* m_StateBlock)
		{
			reinterpret_cast<void(__fastcall*)(void*, CStateBlock*)>(UFG_RVA(0x94950))(this, m_StateBlock);
		}

		CStateBlock* GetStateBlock(unsigned int name_uid, int return_default_data = 1)
		{
			return reinterpret_cast<CStateBlock*(__fastcall*)(void*, unsigned int, int)>(UFG_RVA(0x92690))(this, name_uid, return_default_data);
		}
	};

	class CParamOverride
	{
	public:
		UFG_PAD(0x8);

		void* mOverrideResource;
		UFG_PAD(0x10);
		uint32_t mOverrideNameUID;

		UFG_PAD(0xC);

		void* mOriginalResource;
		UFG_PAD(0x10);
		uint32_t mOriginalNameUID;

		UFG_PAD(0x18);

		void* GetOverride()
		{
			return *reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(mOverrideResource) + 0x10);
		}

		void* GetOriginal()
		{
			return *reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(mOriginalResource) + 0x10);
		}

		void SetOverride(unsigned int param_uid, unsigned int resource_type_name_uid, unsigned int override_name_uid, int condition, unsigned int original_name_uid)
		{
			reinterpret_cast<void(__fastcall*)(void*, unsigned int, unsigned int, unsigned int, int, unsigned int)>(UFG_RVA(0x957F0))(this, param_uid, resource_type_name_uid, override_name_uid, condition, original_name_uid);
		}
	};

	class CMaterialModifierParams
	{
	public:
		void* mOverridesPtr;
		int mNumOverrides;

		UFG_PAD(0x4);

		CParamOverride mOverrides[10];
		int mMaxOverrides;

		UFG_PAD(0x4);
	};
}
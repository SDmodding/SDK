#pragma once

namespace Illusion
{
	class CMaterialParam : public CStateParam
	{
	public:
		UFG::qGenericResourceHandle mResourceHandle;

		UFG_INLINE void Set(uint32_t p_StateTypeUID, uint32_t p_StateNameUID, uint32_t p_TypeUID, uint32_t p_NameUID)
		{
			mTypeUID = p_StateTypeUID;
			mNameUID = p_StateNameUID;
			mResourceHandle.mTypeUID = p_TypeUID;
			mResourceHandle.mNameUID = p_NameUID;
		}

		UFG_INLINE void Set(uint32_t p_StateUID, uint32_t p_TypeUID, uint32_t p_NameUID)
		{
			Set(p_StateUID, p_StateUID, p_TypeUID, p_NameUID);
		}
	};

	class CMaterial : public UFG::qResourceData
	{
	public:
		__declspec(align(16)) UFG::BitFlags128 mStateBlockMask;
		uint32_t mNumParams;
		UFG::qOffset64<class CMaterialUser> mMaterialUser;

		UFG_INLINE CMaterialParam* GetParamTable()
		{
			return reinterpret_cast<CMaterialParam*>(reinterpret_cast<uintptr_t>(this) + sizeof(CMaterial));
		}

		UFG_INLINE void UpdateParam(uint32_t p_Index, uint32_t p_TypeUID, uint32_t p_NameUID)
		{
			reinterpret_cast<void(_fastcall*)(void*, uint32_t, uint32_t, uint32_t)>(UFG_RVA(0x9360))(this, p_Index, p_TypeUID, p_NameUID);
		}

		UFG_INLINE void OnLoad()
		{
			reinterpret_cast<void(_fastcall*)(void*)>(UFG_RVA(0x934A0))(this);
		}

		UFG_INLINE void OnUnload()
		{
			reinterpret_cast<void(_fastcall*)(void*)>(UFG_RVA(0x941D0))(this);
		}

		UFG_INLINE void Reload()
		{
			OnUnload();
			OnLoad();
		}
	};
}
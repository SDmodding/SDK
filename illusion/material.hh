#pragma once

namespace Illusion
{
	class MaterialUser;
	class MaterialTableUser;

	class MaterialParam : public StateParam
	{
	public:
		UFG::qGenericResourceHandle mResourceHandle;
	};

	class Material : public UFG::qResourceData
	{
	public:
		__declspec(align(16)) UFG::BitFlags128 mStateBlockMask;
		u32 mNumParams;
		UFG::qOffset<MaterialUser*> mMaterialUser;

		/* Functions */

		void OnLoad() { SDK_CALL_FUNC(void, 0x934A0, void*)(this); }
		void OnUnload() { SDK_CALL_FUNC(void, 0x941D0, void*)(this); }

		/* Helper Functions */

		SDK_INLINE MaterialParam* GetParams() { return reinterpret_cast<MaterialParam*>(&this[1]); }
		SDK_INLINE MaterialParam* GetParam(u32 index) { return &GetParams()[index]; }

		// 0, "iTexture", "texDiffuse", "Illusion.Texture", "DEFAULT"
		SDK_INLINE void SetParam(u32 index, u32 state_type, u32 state_name, u32 resource_type, u32 resource_name)
		{
			auto param = GetParam(index);
			param->mTypeUID = state_type;
			param->mNameUID = state_name;
			param->mResourceHandle.mTypeUID = resource_type;
			param->mResourceHandle.mNameUID = resource_name;
		}

		SDK_INLINE void SetParam(u32 index, u32 state_name, u32 resource_type, u32 resource_name)
		{
			SetParam(index, state_name, state_name, resource_type, resource_name);
		}

		// Use with caution: this will use and increase 'mNumParams'; ensure memory is preallocated.
		SDK_INLINE void AddParam(u32 state_type, u32 state_name, u32 resource_type, u32 resource_name)
		{
			SetParam(mNumParams++, state_type, state_name, resource_type, resource_name);
		}

		// Use with caution: this will use and increase 'mNumParams'; ensure memory is preallocated.
		SDK_INLINE void AddParam(u32 state_name, u32 resource_type, u32 resource_name)
		{
			SetParam(mNumParams++, state_name, state_name, resource_type, resource_name);
		}
	};
	SDK_ASSERT_SIZEOF(Material, 0x80);

	class MaterialHandle : public UFG::qTypedResourceHandle<RTypeUID_Material, Material>{};

	class MaterialTable : public UFG::qResourceData
	{
	public:
		u32 mNumMaterials;
		UFG::qOffset<MaterialTableUser*> mMaterialTableUser;
	};

	class MaterialTableHandle : public UFG::qTypedResourceHandle<RTypeUID_MaterialTable, MaterialTable>{};
}
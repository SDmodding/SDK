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

		MaterialParam* GetParams() { return reinterpret_cast<MaterialParam*>(&this[1]); }
		MaterialParam* GetParam(u32 index) { return &GetParams()[index]; }
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
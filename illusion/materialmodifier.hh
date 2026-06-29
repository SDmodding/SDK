#pragma once

namespace Illusion
{
	class ParamOverride
	{
	public:
		enum Condition : s32
		{
			OVERRIDE_ALWAYS,
			OVERRIDE_EQUALS,
			OVERRIDE_NOT_EQUALS,
			OVERRIDE_CONSTANT_BLOCK
		};

		int mStateParamIndex;
		Condition mCondition;
		UFG::qGenericResourceHandle mOverrideResourceHandle;
		UFG::qGenericResourceHandle mOriginalResourceHandle;
		void* mConstantBlock;
		u32 mConstantBlockSize;

		/* Functions */

		void SetOverride(u32 param_uid, u32 resource_type_name_uid, u32 override_name_uid, Condition condition, u32 original_name_uid) {
			SDK_CALL_FUNC(void, 0x957F0, void*, u32, u32, u32, Condition, u32)(this, param_uid, resource_type_name_uid, override_name_uid, condition, original_name_uid);
		}

		void SetTextureOverride(u32 param_uid, u32 override_name_uid, Condition condition, u32 original_name_uid) {
			SDK_CALL_FUNC(void, 0x95A20, void*, u32, u32, Condition, u32)(this, param_uid, override_name_uid, condition, original_name_uid);
		}
	};
	SDK_ASSERT_SIZEOF(ParamOverride, 0x68);

	class MaterialModifierData
	{
	public:
		ParamOverride* mOverridesPtr;
		int mNumOverrides;
	};

	template <int N>
	class MaterialModifierParams : public MaterialModifierData
	{
	public:
		ParamOverride mOverrides[N];
		int mMaxOverrides;
	};
}
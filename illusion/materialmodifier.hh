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
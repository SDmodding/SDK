#pragma once

class IActionTreeSerializer;

namespace Expression
{
	class IMemberMap
	{
	public:
		IMemberMap* mResourceOwner;

		/* Virtual Functions */

		virtual IMemberMap* FindWithOldPath(const char* resourcePath) = 0;
		virtual ~IMemberMap() = 0;
		virtual IMemberMap* CreateClone() = 0;
		virtual void Serialize(IActionTreeSerializer*) = 0;
		virtual const char* GetClassname() = 0;
		virtual u32 GetClassNameUID() = 0;
		virtual void GetResourcePath(char* path, int pathSize) = 0;
		virtual void ResolveReferences() = 0;
		virtual void SetResourceOwner(IMemberMap*) = 0;
		virtual IMemberMap* GetResourceOwner() = 0;
	};
	SDK_ASSERT_SIZEOF(IMemberMap, 0x10);
}

class ExpressionParameterFloat
{
public:
	BinString text;
	UFG::qOffset64<UEL::Expression*> expression;
	float value;
};
SDK_ASSERT_SIZEOF(ExpressionParameterFloat, 0x18);
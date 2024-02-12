#pragma once

namespace UFG
{
	class CPropertySetHandle
	{
	public:
		qSymbol mName;
		qPropertySet* mpPropSet;

		UFG_INLINE void Bind()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1F20C0))(this);
		}
	};

	struct qPropertySetHandle : qResourceHandle
	{
		UFG_INLINE qPropertySet* Get()
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(void*)>(UFG_RVA(0x1F6680))(this);
		}
	};
}
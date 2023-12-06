#pragma once

namespace UFG
{
	class CPropertySetHandle
	{
	public:
		qSymbol mName;
		qPropertySet* mpPropSet;

		void Bind()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1F20C0))(this);
		}
	};

	struct qPropertySetHandle : qResourceHandle
	{
		__inline qPropertySet* Get()
		{
			return reinterpret_cast<qPropertySet * (__fastcall*)(void*)>(UFG_RVA(0x1F6680))(this);
		}
	};
}
#pragma once

namespace UFG
{
	namespace PSWrapper
	{
		SDK_SINLINE u32 AppendParentLocal(qPropertySet* propSet, qPropertySet* parentPropSet) { return SDK_CALL_FUNC(u32, 0x1F1E70, qPropertySet*, qPropertySet*)(propSet, parentPropSet); }

		SDK_SINLINE i32 FindElementPropertySet(qPropertyList* list, const qSymbol& name) { return SDK_CALL_FUNC(i32, 0x1F5420, qPropertyList*, const qSymbol&)(list, name); }
	}
}
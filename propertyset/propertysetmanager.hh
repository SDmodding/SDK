#pragma once

namespace UFG
{
	namespace PropertySetManager
	{
		SDK_SINLINE void AppendParentLocal(qPropertySet* propertySet, const qSymbolUC& parentName) { SDK_CALL_FUNC(void, 0x1F1ED0, qPropertySet*, const qSymbolUC&)(propertySet, parentName); }

		SDK_SINLINE void AppendParentLocal(qPropertySet* propertySet, const char* parentNameString) { SDK_CALL_FUNC(void, 0x1F1F10, qPropertySet*, const char*)(propertySet, parentNameString); }
	}
}
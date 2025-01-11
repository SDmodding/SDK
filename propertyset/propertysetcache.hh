#pragma once

namespace UFG::PropertySetCache
{
	SDK_SINLINE void Add(qPropertySetResource* pPropResource) { SDK_CALL_FUNC(void, 0x1EFA80, qPropertySetResource*)(pPropResource); }

	SDK_SINLINE bool Contains(qPropertySetResource* pPropResource) { return SDK_CALL_FUNC(bool, 0x1F25E0, qPropertySetResource*)(pPropResource); }

	SDK_SINLINE bool ContainsSet(qPropertySet* propSet) { return SDK_CALL_FUNC(bool, 0x1F2630, qPropertySet*)(propSet); }

	SDK_SINLINE qPropertySet* GetPropSet(const qSymbol& propSetName) { return SDK_CALL_FUNC(qPropertySet*, 0x1F75F0, const qSymbol&)(propSetName); }

	SDK_SINLINE qPropertySetResource* GetResource(const qSymbol& propSetName) { return SDK_CALL_FUNC(qPropertySetResource*, 0x1F8090, const qSymbol&)(propSetName); }

	SDK_SINLINE void Remove(qPropertySetResource* pPropResource) { SDK_CALL_FUNC(void, 0x1FB580, qPropertySetResource*)(pPropResource); }
}
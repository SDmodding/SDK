#pragma once

class hkpMoppUtility
{
public:
	/// Builds the MOPP for a given set of shapes with the specified fit tolerance requirements.
	/// The returned hkpMoppCode is a referenced object, so you just need to call removeReference() when you're finished with it -
	/// the system will look after deleting the object.
	/// Note: This method can take significant time to complete. MOPP code is a platform independent byte code and should
	/// be precomputed offline and loaded at runtime.
	/// If chunk building is used for SPUs then an array can be passed to collect the re-indexing information.
	SDK_SINLINE hkpMoppCode* buildCode(const hkpShapeContainer* shapeContainer, const hkpMoppCompilerInput& req, hkArray<hkpMoppCodeReindexedTerminal>* reindexInfo = 0) {
		return SDK_CALL_FUNC(hkpMoppCode*, 0xD09230, const hkpShapeContainer*, const hkpMoppCompilerInput & req, hkArray<hkpMoppCodeReindexedTerminal>*)(shapeContainer, req, reindexInfo);
	}
};
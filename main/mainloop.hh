#pragma once

namespace UFG
{
	/* Globals */

	inline qGlobalVar<qMemoryPool*, 0x23E5650> gSimulationMemoryPool;
	inline qGlobalVar<qMemoryPool*, 0x23E7AB0> gSkookumMemoryPool;
	inline qGlobalVar<qMemoryPool*, 0x23F1B00> gScaleformMemoryPoo;

	/* Functions */

	SDK_SINLINE DataStreamer::Handle* LoadTexturePackHK(const char* perm_filename, StreamingMemory::DATA_TYPE eDataType) {
		return SDK_CALL_FUNC(DataStreamer::Handle*, 0x424D70, const char*, StreamingMemory::DATA_TYPE)(perm_filename, eDataType);
	}
}
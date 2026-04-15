#pragma once

struct hkaiNavMeshGenerationResult
{
	enum GenerationResultEnum
	{
		GENERATION_HALTED,
		GENERATION_EMPTY,
		GENERATION_OUT_OF_MEMORY,
		GENERATION_KEYCODE_ERROR,
		GENERATION_TOO_BIG,
		GENERATION_SUCCESS
	};
};

class hkaiNavMeshGenerationProgressCallback
{
public:
	virtual ~hkaiNavMeshGenerationProgressCallback() = 0;
};


class hkaiNavMeshGenerationUtils
{
public:
	SDK_SINLINE hkaiNavMeshGenerationResult::GenerationResultEnum generateNavMesh(const hkaiNavMeshGenerationSettings& input, hkGeometry* triMeshIn, hkaiNavMesh* navMeshOut, hkaiNavMeshGenerationProgressCallback* _callbacks = 0) {
		return SDK_CALL_FUNC(hkaiNavMeshGenerationResult::GenerationResultEnum, 0xB6E1C0, const hkaiNavMeshGenerationSettings&, hkGeometry*, hkaiNavMesh*, hkaiNavMeshGenerationProgressCallback*)(input, triMeshIn, navMeshOut, _callbacks);
	}
};
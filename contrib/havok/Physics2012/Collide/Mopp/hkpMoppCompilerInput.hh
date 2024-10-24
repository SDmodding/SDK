#pragma once

class hkpMoppCompilerInput
{
public:
	hkVector4f m_absoluteFitToleranceOfAxisAlignedTriangles;
	f32 m_relativeFitToleranceOfInternalNodes;
	f32 m_absoluteFitToleranceOfInternalNodes;
	f32 m_absoluteFitToleranceOfTriangles;
	hkBool m_useShapeKeys;
	hkBool m_enablePrimitiveSplitting;
	hkBool m_enableChunkSubdivision;
	hkBool m_enableInterleavedBuilding;
	hkBool m_cachePrimitiveExtents;

	hkpMoppCompilerInput() { SDK_CALL_FUNC(void, 0xD34E60, void*)(this); }
};
SDK_ASSERT_SIZEOF(hkpMoppCompilerInput, 0x30);
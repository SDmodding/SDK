#pragma once

class hkpMoppCompilerInput
{
public:
	hkVector4f m_absoluteFitToleranceOfAxisAlignedTriangles;
	float m_relativeFitToleranceOfInternalNodes;
	float m_absoluteFitToleranceOfInternalNodes;
	float m_absoluteFitToleranceOfTriangles;
	bool m_useShapeKeys;
	bool m_enablePrimitiveSplitting;
	bool m_enableChunkSubdivision;
	bool m_enableInterleavedBuilding;
	bool m_cachePrimitiveExtents;

	hkpMoppCompilerInput()
	{
		reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xD34E60))(this);
	}
};

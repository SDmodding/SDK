#pragma once

namespace UFG
{
	class HavokNavPosition : public NavPositionBase
	{
	public:
		bool m_bValid;
		hkVector4f m_hkvMeshPosition;
		u32 m_packedKey;
		u32 m_aiMeshUid;
	};
}
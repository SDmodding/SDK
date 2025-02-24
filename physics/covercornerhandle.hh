#pragma once

namespace UFG
{
	class CoverCornerHandle
	{
	public:
		u16 m_uCoverCornerIndex;
		qTypedResourceHandle<RTypeUID_CoverDataResource, CoverDataResource> m_ResourceHandle;
		qSafePointer<DynamicCoverCorner> m_pDynamicCoverCorner;
	};
}
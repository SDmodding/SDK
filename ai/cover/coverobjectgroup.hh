#pragma once

namespace UFG
{
	class CoverObjectGroup : public CoverObjectBase
	{
	public:
		qArray<CoverObjectBase*> m_aChildObjects;
		f32 m_fTotalLength;
	};
}
#pragma once

namespace UFG
{
	class RegionContainmentInfo
	{
	public:
		qArray<qSymbol> m_regionsContainedIn;

		virtual ~RegionContainmentInfo() = 0;
	};
}
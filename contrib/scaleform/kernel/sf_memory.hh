#pragma once

namespace Scaleform
{
	template <int Stat>
	class NewOverrideBase
	{
	public:
		enum { StatType = Stat };
	};
}
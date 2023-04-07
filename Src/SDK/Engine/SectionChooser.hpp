#pragma once

namespace UFG
{
	namespace SectionChooser
	{
		CBSP* GetBSP()
		{
			return *reinterpret_cast<CBSP**>(UFG_RVA(0x23A8D78));
		}
	}
}
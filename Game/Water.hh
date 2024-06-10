#pragma once

namespace UFG
{
	namespace Water
	{
		UFG_INLINE qVector3* GetCameraPos()
		{
			return reinterpret_cast<UFG::qVector3*>(UFG_RVA(0x2138CC0));
		}
	}
}
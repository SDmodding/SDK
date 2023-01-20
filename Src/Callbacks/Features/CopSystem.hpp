#pragma once

namespace Feature
{
	struct CopSystem_t
	{
		bool m_DisableHeat = false;

		void Update()
		{
			if (m_DisableHeat)
				UFG::CopSystem->SetHeatLevel(UFG::HEATLEVEL_NONE, UFG::eHEATEVENT_NONE, 0.f);
		}
	};
	static CopSystem_t CopSystem_;
}
#pragma once

namespace UFG
{
	namespace ExplosionManager
	{
		UFG_INLINE void CreateExplosion(const qVector3& p_vPosition, qSymbol p_qExplosionName, CSimObject* p_Source, CSimObject* p_Attacker)
		{
			reinterpret_cast<void(__fastcall*)(const qVector3&, qSymbol*, CSimObject*, CSimObject*)>(UFG_RVA(0x45C900))(p_vPosition, &p_qExplosionName, p_Source, p_Attacker);
		}
	}
}
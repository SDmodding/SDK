#pragma once

namespace UFG
{
	namespace ExplosionManager
	{
		void CreateExplosion(qVector3* m_Position, qSymbol m_ExplosionHash, CSimObject* m_Source, CSimObject* m_Attacker)
		{
			reinterpret_cast<void(__fastcall*)(qVector3*, qSymbol*, CSimObject*, CSimObject*)>(UFG_RVA(0x45C900))(m_Position, &m_ExplosionHash, m_Source, m_Attacker);
		}
	}
}
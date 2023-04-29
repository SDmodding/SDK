#pragma once

namespace UFG
{
	class CSoundBank
	{
	public:
		UFG_PAD(0x40);
		uint32_t m_name;
		unsigned int m_count;
		unsigned int m_priority;
		float m_unloadTimer;
		float m_unloadAfterTime;
		unsigned int m_poolId;
		unsigned int m_idealPoolId;
		void* m_group;
		int m_loadState;
		void* m_category;
		__int8 m_allowInDefault : 1;
		__int8 m_retry : 1;
		__int8 m_pendingReload : 1;
	};

	namespace SoundBankManager
	{
		bool AreAllImportantBankLoadsComplete()
		{
			return reinterpret_cast<bool(__fastcall*)()>(UFG_RVA(0x142D60))();
		}

		bool BankLoadRequestFinished(uint32_t m_BankID)
		{
			return reinterpret_cast<bool(__fastcall*)(uint32_t*)>(UFG_RVA(0x143470))(&m_BankID);
		}

		bool BankLoadRequested(uint32_t m_BankID)
		{
			return reinterpret_cast<bool(__fastcall*)(uint32_t*)>(UFG_RVA(0x1434B0))(&m_BankID);
		}

		bool BankLoaded(uint32_t m_BankID)
		{
			return reinterpret_cast<bool(__fastcall*)(uint32_t*)>(UFG_RVA(0x1434F0))(&m_BankID);
		}

		bool BankLoadedOrLoading(uint32_t m_BankID)
		{
			return reinterpret_cast<bool(__fastcall*)(uint32_t*)>(UFG_RVA(0x143590))(&m_BankID);
		}

		qBaseTreeRB* FindOrCreateGroup(uint32_t m_GroupID)
		{
			return reinterpret_cast<qBaseTreeRB*(__fastcall*)(uint32_t)>(UFG_RVA(0x145860))(m_GroupID);
		}

		CSoundBank* FindOrCreateSoundBank(uint32_t m_BankID)
		{
			return reinterpret_cast<CSoundBank*(__fastcall*)(uint32_t*)>(UFG_RVA(0x1458E0))(&m_BankID);
		}

		uint32_t GetBytesRemainingToLoad()
		{
			return reinterpret_cast<uint32_t(__fastcall*)()>(UFG_RVA(0x145C30))();
		}

		bool QueueBankForLoad(uint32_t m_BankID)
		{
			return reinterpret_cast<bool(__fastcall*)(uint32_t*)>(UFG_RVA(0x14AE00))(&m_BankID);
		}

		void QueueBankForUnload(uint32_t m_BankID)
		{
			reinterpret_cast<void(__fastcall*)(uint32_t*)>(UFG_RVA(0x14AE30))(&m_BankID);
		}

		void Update(float m_TimeDelta = 0.f)
		{
			reinterpret_cast<void(__fastcall*)(float)>(UFG_RVA(0x14DE20))(m_TimeDelta);
		}
	}
}
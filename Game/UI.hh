#pragma once

namespace UFG
{
	class CUIPropertySetMenu
	{
	public:
		UFG_PAD(0x70);

		unsigned int mState;
		qString mSelectedItem;
		qString mSelectedSubItem;
		unsigned int mNumVisibleSlots;
		qString mGameSetup;
		qString mOperation;
		qString mOpDependant;
		qString mScriptFunc;
		qSymbol mProgressionFlow;

		void AddItem(const char* caption, bool enabled)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, bool)>(UFG_RVA(0x61DD50))(this, caption, enabled);
		}
	};

	class CUIWeaponAmmoData
	{
	public:
		int ReserveAmmo;
		int ClipAmmo;
		int ClipCapacity;
		int Clips;
		int OldClips;
		int OldReserveAmmo;
		bool IsCamera;
		bool UnlimitedAmmo;
		eInventoryItemEnum InventoryItem;
		const char* IconTexture;
		const char* TexturePack;
		qSafePointer<CGunComponent> mGunComponent;
	};

	namespace UI
	{
		UFG_INLINE CUIScreenTextureManager* GetScreenTextureManager()
		{
			return *reinterpret_cast<CUIScreenTextureManager**>(UFG_RVA(0x242FF98));
		}

		UFG_INLINE CUIGfxTranslator* GetTranslator()
		{
			return CUIScreenManager::Instance()->m_translator;
		}

		UFG_INLINE bool IsGamePaused()
		{
			return reinterpret_cast<bool(__fastcall*)()>(UFG_RVA(0x5EE1B0))();
		}
	}
}

#define UIHASH_SELECT 0x6256006A
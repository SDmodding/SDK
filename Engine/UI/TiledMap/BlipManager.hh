#pragma once

namespace UFG
{
	class CUIMapBlipManager
	{
	public:
		void* vfptr;
		qTreeRB mBlipList;
		qArray<CUIMapBlip> mSortedIcons;
		bool mNeedToSort;
		int mMaxNumIcons;
		bool mAmbientBlipsPopulated;
		CUIMapBlipGraphic* mPlayerArrowIcon;

		static UFG_INLINE CUIMapBlipManager* Instance()
		{ 
			return *reinterpret_cast<CUIMapBlipManager**>(UFG_RVA(0x2430CD8));
		}

		UFG_INLINE CUIMapBlip* GetBlip(uint32_t p_NameUID)
		{
			return reinterpret_cast<CUIMapBlip*>(mBlipList.Get(p_NameUID));
		}

		UFG_INLINE CUIMapBlip* CreateIcon(uint32_t p_NameUID, const char* p_Icon, const qVector2& p_Position)
		{
			return reinterpret_cast<CUIMapBlip*(__fastcall*)(void*, uint32_t, const char*, float, float)>(UFG_RVA(0xBEA40))(this, p_NameUID, p_Icon, p_Position.x, p_Position.y);
		}

		UFG_INLINE void RemoveIcon(uint32_t p_NameUID)
		{
			return reinterpret_cast<void(__fastcall*)(void*, uint32_t)>(UFG_RVA(0xC71A0))(this, p_NameUID);
		}
	};
}
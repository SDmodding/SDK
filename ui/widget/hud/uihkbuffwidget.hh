#pragma once

namespace UFG
{
	class UIHKBuffData
	{
	public:
		enum eBuffs
		{
			eBUFF_INVALID,
			eBUFF_COP_PERK,
			eBUFF_BERSERK,
			eBUFF_SHARP_SHOOTER,
			eBUFF_ENERGY_DRINK,
			eBUFF_TEA_HOUSE,
			eBUFF_MASSAGE,
			eBUFF_HEALTHREGEN,
			eBUFF_STRIKING,
			eBUFF_DEBUG_TEST
		};

		enum eState
		{
			STATE_IDLE,
			STATE_SHOULD_SHOW,
			STATE_ACTIVE,
			STATE_SHOULD_REFRESH,
			STATE_SHOULD_RESUME
		};

		eState mState;
		eBuffs mType;
		f32 mTimer;
	};

	class UIHKBuffWidget
	{
	public:
		qString mTexturePackFilename;
		qString mIconLoaded[7];
		bool mPerkActivate;
		bool mPerkIsActive;
		f32 mPerkTimer;

		/* Static Members */

		SDK_VINLINE qGlobalVar<u32, 0x2430FD4> mNumBuffs;
		SDK_VINLINE qGlobalVar<u32, 0x2430FE0> mNumTextureLoaded;

		/* Static Functions */

		SDK_SINLINE void Add(UIHKBuffData::eBuffs type, int seconds) { SDK_CALL_FUNC(void, 0x5D18D0, UIHKBuffData::eBuffs, int)(type, seconds); }
		SDK_SINLINE void Clear() { SDK_CALL_FUNC(void, 0x5D4FE0)(); }

		/* Functions */

		void AddPerk(const char* perk) { SDK_CALL_FUNC(void, 0x5D2720, const char*)(perk); }
		void LoadTexture(const char* tpName) { SDK_CALL_FUNC(void, 0x5F11C0, void*, const char*)(this, tpName); }
	};
}
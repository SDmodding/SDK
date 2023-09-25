#pragma once

namespace UFG
{
	class CDamageMarker
	{
	public:
		unsigned int mBoneIndex;
		float mValue;
		float mSignal;
		float mTransferredDamage;
		qVector3 mPosition;
		unsigned int mNameUID;
		float mDamageScalar;
	};

	class CDamageRig
	{
	public:
		unsigned int mNumDamageMarkers;
		unsigned int mNumTriggeredMarkers;
		CDamageMarker* mDamageMarkers;
		void* mTriggeredMarkers;
		float mAggregateDamage;
		float mWeightCache[256];
		unsigned int mWeightCacheCount;
		float mDamageOverride;
		bool mBurnedOut;
		char mDetachableBoneArray[256];
		float mGrimeFactor;
		bool mWheelModelBindingState[4];

		float GetAvgDamage()
		{
			if (mNumDamageMarkers == 0)
				return 0.f;

			float m_Total = 0.f;
			for (unsigned int i = 0; mNumDamageMarkers > i; ++i)
			{
				CDamageMarker* m_DamageMarker = &mDamageMarkers[i];
				m_Total += m_DamageMarker->mValue;
			}

			return (m_Total / static_cast<float>(mNumDamageMarkers));
		}

		float GetDamageAtPosition(qVector3* p_Pos)
		{
			return reinterpret_cast<float(__fastcall*)(void*, qVector3*)>(UFG_RVA(0x3A7EA0))(this, p_Pos);
		}
	};

	class CCharacterDamageRig
	{
	public:
		struct CharacterMarker_t
		{
			uint32_t mBoneIndex;
			uint8_t mValue[6];
			qVector3 mPosition;
			uint32_t mNameUID;
		};
		CharacterMarker_t mCharacterMarkers[26];
		float mPaintEffectApplied;
		qVector3 mPaintEffect;
		float mCharredEffectAmount;
		float mCharredEffectInitialAmount;
		float mCharredEffectElapsedTime;
		bool mDamaged;
		float mDamageScale;

		struct VisualDamageTarget_t
		{
			int boneID;
			float elapsedTime;
			float duration;
			uint8_t initialDamage[6];
			uint8_t targetDamage;
		};
		qArray<VisualDamageTarget_t> mVisualDamageTargets;

		void ApplyCharredEffect(float p_Value)
		{
			p_Value = fmaxf(0.f, fminf(p_Value, 1.f));
			this->mCharredEffectAmount			= p_Value;
			this->mCharredEffectInitialAmount	= p_Value;
			this->mCharredEffectElapsedTime		= 0.f;
		}

		void SetVisualDamage(uint32_t p_BoneIndex, float p_Damage, float p_Duration)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, float, float)>(UFG_RVA(0x3AF920))(this, p_BoneIndex, p_Damage, p_Duration);
		}

		void ResetVisualDamage()
		{
			ApplyCharredEffect(0.f);

			for (CharacterMarker_t& m_Marker : mCharacterMarkers)
				memset(&m_Marker.mValue, 0, sizeof(CharacterMarker_t::mValue));
		}
	};
}
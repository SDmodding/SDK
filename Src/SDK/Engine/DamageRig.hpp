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

		float GetDamageAtPosition(qVector3* pos)
		{
			return reinterpret_cast<float(__fastcall*)(void*, qVector3*)>(UFG_RVA(0x3A7EA0))(this, pos);
		}
	};
}
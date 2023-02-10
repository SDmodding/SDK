#pragma once

namespace UFG
{
	class CFXInstance
	{
	public:
		UFG_PAD(0x70);

		float mStartTime;
		float mEndTime;
		unsigned int mId;
		float mTransformNodeExtraTime;
		unsigned __int64 mAudioId;
		unsigned int mSplitScreenViewMask;
		char mLoop;
		char mBasisRelativeToParent;
		qMatrix44 mCullMatrix;
		void* mCullInfo;
		void* mCullResults;
		void* mOcclusionQuery;

		UFG_PAD(0x18);

		qMatrix44 mBasis;
		qMatrix44 mRelativeBasis;
	};

	class CFXManager
	{
	public:
		qSymbol CreateEffect(qSymbol fx_id, qVector3 vPos, qVector3 vDir, uint32_t splitScreenViewMask = -1, void* overrideObject = nullptr)
		{
			return reinterpret_cast<qSymbol(__fastcall*)(void*, qSymbol, qVector3*, qVector3*, uint32_t, void*)>(UFG_RVA(0x1CA250))(this, fx_id, &vPos, &vDir, splitScreenViewMask, overrideObject);
		}

		qSymbol CreateEffect(qSymbol fx_id, CTransformNodeComponent* parent, uint32_t splitScreenViewMask = -1, void* overrideObject = nullptr)
		{
			return reinterpret_cast<qSymbol(__fastcall*)(void*, qSymbol, CTransformNodeComponent*, uint32_t, void*)>(UFG_RVA(0x1CA510))(this, fx_id, parent, splitScreenViewMask, overrideObject);
		}

		qSymbol CreateEffect(qSymbol fx_id, UFG::qMatrix44 basis, CTransformNodeComponent* parent, float currentTime = 0.f, uint32_t splitScreenViewMask = -1, void* overrideObject = nullptr)
		{
			return reinterpret_cast<qSymbol(__fastcall*)(void*, qSymbol, qMatrix44*, CTransformNodeComponent*, float, uint32_t, void*)>(UFG_RVA(0x1C9D30))(this, fx_id, &basis, parent, currentTime, splitScreenViewMask, overrideObject);
		}

		void KillEffect(qSymbol fxId, uint32_t killOption = 0x0)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol, uint32_t)>(UFG_RVA(0x1D1520))(this, fxId, killOption);
		}

		CFXInstance* FindEffect(qSymbol fxId)
		{
			return reinterpret_cast<CFXInstance*(__fastcall*)(void*, qSymbol)>(UFG_RVA(0x1CBDE0))(this, fxId);
		}
	};
	CFXManager* FXManager = reinterpret_cast<CFXManager*>(UFG_RVA(0x2366990));
}
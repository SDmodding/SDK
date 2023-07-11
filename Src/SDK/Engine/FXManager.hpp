#pragma once

namespace UFG
{
	class CFXOverrideSettings
	{
	public:
		float ColorTint[4];
		float Params1[4];
	};

	class CFXOverride
	{
	public:
		int mReferenceCount;
		__declspec(align(16)) CFXOverrideSettings stateBlock;
		uint32_t modelToEmitFromUID;
		float mAABBMin[3];
		float mAABBMax[3];
		float velocityScale;
		float emissionScale;
		float sizeScale;
		CMemoryPool* mMemoryPool;
		void* mTriangleInfo;
		uint32_t mNumTriangleInfo;
		float mTotalMeshSurfaceArea;
	};

	class  __declspec(align(16)) CFXInstance
	{
	public:
		UFG_PAD(0x70);

		float mStartTime;
		float mEndTime;
		uint32_t mId;
		float mTransformNodeExtraTime;
		unsigned __int64 mAudioId;
		uint32_t mSplitScreenViewMask;
		char mLoop;
		char mBasisRelativeToParent;
		qMatrix44 mCullMatrix;
		void* mCullInfo;
		void* mCullResults;
		void* mOcclusionQuery;
		qSafePointer<UFG::CTransformNodeComponent> mParentNode;
		qMatrix44 mBasis;
		qMatrix44 mRelativeBasis;
		CFXOverride* mStateBlockOverride; // SharedPtr

		void SetFxOverride(CFXOverride* p_FxOverride)
		{
			reinterpret_cast<void(__fastcall*)(CFXOverride**, CFXOverride*)>(UFG_RVA(0x1D6220))(&mStateBlockOverride, p_FxOverride);
		}
	};

	class CFXManager
	{
	public:
		qBaseTreeRB mEffectsTree; // CFXInstance
		qList<CFXInstance> mEffectsList;
		qArray<unsigned long> mFilteredEffects;
		uint32_t mEffectId;
		float mCurrentTimeOfDay;
		bool mRenderRainWhileInside;
		float mLastUpdateTime;
		__int16 mFXOverrideStateParamIndex;
		CFXOverride* mStateBlockDefaultOverride;
		qSafePointer<UFG::CTransformNodeComponent> mCamTransformNode;
		bool mDisplayFXInfo;

		qSymbol CreateEffect(qSymbol p_FxID, qVector3 p_Position, qVector3 p_Direction, uint32_t p_SplitScreenViewMask = -1, void* p_OverrideObject = nullptr)
		{
			return reinterpret_cast<qSymbol(__fastcall*)(void*, qSymbol, qVector3*, qVector3*, uint32_t, void*)>(UFG_RVA(0x1CA250))(this, p_FxID, &p_Position, &p_Direction, p_SplitScreenViewMask, p_OverrideObject);
		}

		qSymbol CreateEffect(qSymbol p_FxID, CTransformNodeComponent* p_Parent, uint32_t p_SplitScreenViewMask = -1, void* p_OverrideObject = nullptr)
		{
			return reinterpret_cast<qSymbol(__fastcall*)(void*, qSymbol, CTransformNodeComponent*, uint32_t, void*)>(UFG_RVA(0x1CA510))(this, p_FxID, p_Parent, p_SplitScreenViewMask, p_OverrideObject);
		}

		qSymbol CreateEffect(qSymbol p_FxID, UFG::qMatrix44 p_Matrix, CTransformNodeComponent* p_Parent, float p_Time = 0.f, uint32_t p_SplitScreenViewMask = -1, void* overrideObject = nullptr)
		{
			return reinterpret_cast<qSymbol(__fastcall*)(void*, qSymbol, qMatrix44*, CTransformNodeComponent*, float, uint32_t, void*)>(UFG_RVA(0x1C9D30))(this, p_FxID, &p_Matrix, p_Parent, p_Time, p_SplitScreenViewMask, overrideObject);
		}

		void KillEffect(qSymbol p_FxID, uint32_t p_KillOption = 0x0)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol, uint32_t)>(UFG_RVA(0x1D1520))(this, p_FxID, p_KillOption);
		}

		CFXInstance* FindEffect(qSymbol p_FxID)
		{
			return reinterpret_cast<CFXInstance*>(mEffectsTree.Get(p_FxID));
		}
	};
	CFXManager* FXManager = reinterpret_cast<CFXManager*>(UFG_RVA(0x2366990));

	namespace FXOverride
	{
		uint32_t* GetNumInstancesInService()
		{
			return reinterpret_cast<uint32_t*>(UFG_RVA(0x2362124));
		}

		// Constructor (650 Limit)
		CFXOverride* Create(const char* p_Name = "FXOverride", CMemoryPool* p_MemoryPool = nullptr)
		{
			return reinterpret_cast<CFXOverride * (__fastcall*)(const char*, CMemoryPool*)>(UFG_RVA(0x1CA5A0))(p_Name, p_MemoryPool);
		}

		// Own Constructor
		CFXOverride* ForceCreate(const char* p_Name = "FXOverride", CMemoryPool* p_MemoryPool = nullptr)
		{
			uint32_t* m_NumInstancesInService = GetNumInstancesInService();
			if (*m_NumInstancesInService > 0) // We force it to always decrease the value so it our new override doesn't count...
				*m_NumInstancesInService--;

			return Create(p_Name, p_MemoryPool);
		}
	}
}
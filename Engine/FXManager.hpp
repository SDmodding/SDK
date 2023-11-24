#pragma once

// CFXSettingsMember TypeUIDs
#define FX_AUDIO_TYPEUID							0xD77CCEB2
#define FX_BEAM_TYPEUID								0xA0AAE10F
#define FX_CORONA_FLARE_TYPEUID						0xB76CCFB8
#define FX_DECAL_TYPEUID							0xAE323146
#define FX_DYNAMIC_LIGHT_TYPEUID					0xD6CD7114
#define FX_EFFECT_EMITTER_TYPEUID					0xFF1F2832
#define FX_FLARE_TYPEUID							0xA6535FBB
#define FX_FORCE_TYPEUID							0x433ED8DF
#define FX_GEO_TYPEUID								0xF1734D8E
#define FX_LIGHTNING_TYPEUID						0x21AE1C64
#define FX_PARTICLE_EMITTER_TYPEUID					0x3BEE21DC
#define FX_TRACK_STRIP_TYPEUID						0x69CE5438
#define FX_SCREEN_PARTICLE_EMITTER_TYPEUID			0x354C3CDC
#define FX_VOLUMETRIC_EFFECT_TYPEUID				0xE4B8F46A

namespace UFG
{
	// Components
	class CFXComponentInstance
	{
	public:
		void* vfptr;
		qNode<CFXComponentInstance> mNode;
		class CFXOverride* mContainer;
		float mStartTime;
		float mEndTime;
		uint32_t mComponentIndex;
		bool mIsActive;
		bool mIsSuspended;
		int mForceSuspendState;
		uint32_t mSettingsId;
	};

	class CDynamicLightInstance : public CFXComponentInstance
	{
	public:
		UFG_PAD(0x28);

		qMatrix44 mTransform;
		qVector3 mColor;
		float mDecayRadius;
		float mFovHalfInner;
		float mFovHalfOuter;
		float mShadowNear;
		uint32_t mTextureUID;
		float mOnTime;
		float mOffTime;
		char mType;
		char mShadowFlags;
		char mSpecular;
		char mClipPlaneCount;
		uint32_t mLayerUid;
		float mDecayPower;
		char mClipPlanes[6];
		char mDisableAnimation;
		char mBiasLightCard;
		uint32_t mLightID;
		float mAreaLightWidth;
		float mAreaLightHeight;
		float mAreaLightNearOffset;
		float mAreaLightFarOffset;
		float mAreaLightIntensityScale;
		uint32_t mTexDistAttenUID;
		float mTexDistAttenV;
		uint32_t mPad0;

		UFG_PAD(0x20);
		// Render::DynamicLightSettingsHandle mSettingsHandle;

		bool mIsFlickeringLightOn;
		float mFlickerLastChangeTime;
		float mFlickerChangeTime;
		qVector3 mFlickerOnColor;
		qVector3 mFlickerOffColor;
		float mRadius;
		float mTimeOfFirstUpdate;
	};

	// Classes
	class CFXOverride
	{
	public:
		int mReferenceCount;
		__declspec(align(16)) Illusion::CB_FXOverrideSettings stateBlock;
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

	class CFXSettingsMember
	{
	public:
		uint32_t typeId;
		uint32_t nameId;
		uint32_t guid;
		qVector3 offset;
		char offsetWorld;
		char lodMask;
		char pad0;
		char pad1;
		float start;
		float end;
		int rotateType;
		qVector3 rotateMin;
		qVector3 rotateMax;
		qVector3 rotateSpeed;
		qMatrix44 rotateOffset;
		float startTime;
		float endTime;
	};

	class CFXSettings : public qResourceData
	{
	public:
		qVector3 mAABBMin;
		qVector3 mAABBMax;
		float mLength;
		float mTransformNodeExtraTime;
		uint64_t mAudioId;
		uint32_t mSlowMoFxId;
		float mAttachToCameraZDist;
		char mLoop;
		char mComponentCount;
		char mAttachToCamera;
		char mPad[13];
		CFXSettingsMember m_Members[0xFF];
	};

	class CFXInstance
	{
	public:
		UFG_PAD(0x50);

		CFXSettings* mSettings;

		UFG_PAD(0x8);

		qNode<CFXComponentInstance> mComponents;
		float mStartTime;
		float mEndTime;
		uint32_t mId;
		float mTransformNodeExtraTime;
		uint64_t mAudioId;
		uint32_t mSplitScreenViewMask;
		char mLoop;
		char mBasisRelativeToParent;
		qMatrix44 mCullMatrix;
		void* mCullInfo;
		void* mCullResults;
		void* mOcclusionQuery;
		qSafePointer<CTransformNodeComponent> mParentNode;
		qMatrix44 mBasis;
		qMatrix44 mRelativeBasis;
		CFXOverride* mStateBlockOverride; // SharedPtr

		UFG_PAD(0x8);

		template <typename T>
		T* GetComponentByIndex(uint32_t m_Index)
		{
			for (qNode<CFXComponentInstance>* i = mComponents.mNext; i != &mComponents; i = i->mNext)
			{
				CFXComponentInstance* m_FxComponent = i->GetPointerSub<offsetof(CFXComponentInstance, mNode)>();
				if (m_FxComponent->mComponentIndex == m_Index)
					return reinterpret_cast<T*>(m_FxComponent);
			}

			return nullptr;
		}

		void Update(qVector3 p_CameraPosition, int p_CullIndex, float p_SimTime)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, int, float)>(UFG_RVA(0x1D8FA0))(this, &p_CameraPosition, p_CullIndex, p_SimTime);
		}

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

		static CFXManager* Instance()
		{
			return reinterpret_cast<CFXManager*>(UFG_RVA(0x2366990));
		}

		qSymbol CreateEffect(qSymbol p_FxID, qVector3 p_Position, qVector3 p_Direction, uint32_t p_SplitScreenViewMask = -1, void* p_OverrideObject = nullptr)
		{
			return reinterpret_cast<qSymbol(__fastcall*)(void*, qSymbol, qVector3*, qVector3*, uint32_t, void*)>(UFG_RVA(0x1CA250))(this, p_FxID, &p_Position, &p_Direction, p_SplitScreenViewMask, p_OverrideObject);
		}

		qSymbol CreateEffect(qSymbol p_FxID, CTransformNodeComponent* p_Parent, uint32_t p_SplitScreenViewMask = -1, void* p_OverrideObject = nullptr)
		{
			return reinterpret_cast<qSymbol(__fastcall*)(void*, qSymbol, CTransformNodeComponent*, uint32_t, void*)>(UFG_RVA(0x1CA510))(this, p_FxID, p_Parent, p_SplitScreenViewMask, p_OverrideObject);
		}

		qSymbol CreateEffect(qSymbol p_FxID, qMatrix44* p_Matrix, CTransformNodeComponent* p_Parent, float p_Time = 0.f, uint32_t p_SplitScreenViewMask = -1, void* overrideObject = nullptr)
		{
			return reinterpret_cast<qSymbol(__fastcall*)(void*, qSymbol, qMatrix44*, CTransformNodeComponent*, float, uint32_t, void*)>(UFG_RVA(0x1C9D30))(this, p_FxID, p_Matrix, p_Parent, p_Time, p_SplitScreenViewMask, overrideObject);
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
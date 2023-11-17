#pragma once
#define IllusionParamOverride_VehiclePaint 0xC6D01635

namespace Illusion
{
	class CStateBlock
	{
	public:
		UFG_PAD(0x18);

		uint32_t m_UID;

		UFG_PAD(0x18);

		char m_DebugName[0x24];

		UFG_PAD(0x10);

		uint32_t mParentUID;
		uint32_t mDataByteSize;
		uint32_t mNumValues;
		uint32_t mNameUID;

		uintptr_t GetDataPointer() { return (reinterpret_cast<uintptr_t>(this) + 0x80); }
	};

	class CStateBlockItter
	{
	public:
		UFG_PAD(0x34);

		char m_DebugName[0x24];

		UFG_PAD(0x1C);

		uint32_t m_UID;
	};

	class CStateBlockInventory
	{
	public:
		CStateBlockItter* Itter(CStateBlockItter* m_Itter)
		{
			uintptr_t m_This = reinterpret_cast<uintptr_t>(this);
			CStateBlockItter* m_ItterEnd = *reinterpret_cast<CStateBlockItter**>(m_This + 0xC8);

			if (m_Itter)
			{
				uintptr_t m_ItterAddress = reinterpret_cast<uintptr_t>(m_Itter);
				m_Itter = reinterpret_cast<CStateBlockItter*>(*reinterpret_cast<uintptr_t*>(m_ItterAddress + 0x60) - 0x58);
			}
			else
				m_Itter = reinterpret_cast<CStateBlockItter*>(*reinterpret_cast<uintptr_t*>(m_This + 0x128) - 0x58);

			if (m_Itter == m_ItterEnd)
				return nullptr;

			return m_Itter;
		}

		void Add(CStateBlock* m_StateBlock)
		{
			reinterpret_cast<void(__fastcall*)(void*, CStateBlock*)>(UFG_RVA(0x8DE00))(this, m_StateBlock);
		}

		void Remove(CStateBlock* m_StateBlock)
		{
			reinterpret_cast<void(__fastcall*)(void*, CStateBlock*)>(UFG_RVA(0x94950))(this, m_StateBlock);
		}

		CStateBlock* GetStateBlock(unsigned int name_uid, int return_default_data = 1)
		{
			return reinterpret_cast<CStateBlock*(__fastcall*)(void*, unsigned int, int)>(UFG_RVA(0x92690))(this, name_uid, return_default_data);
		}
	};

	class CParamOverride
	{
	public:
		int mStateParamIndex;
		int mCondition;

		struct Handle_t
		{
			UFG_PAD(0x10);

			void* mData;
			uint32_t mNameUID;
			uint32_t mTailPad;
			uint32_t mTypeUID;
		};

		Handle_t mOverrideResourceHandle;
		Handle_t mOriginalResourceHandle;
		void* mConstantBlock;
		unsigned int mConstantBlockSize;

		void* GetOverride()
		{
			return *reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(mOverrideResourceHandle.mData) + 0x10);
		}

		void* GetOriginal()
		{
			return *reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(mOriginalResourceHandle.mData) + 0x10);
		}

		void SetOverride(uint32_t p_ParamUID, uint32_t p_ResourceTypeNameUID, uint32_t p_OverrideNameUID, int p_Condition, uint32_t p_OriginalNameUID)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, uint32_t, uint32_t, int, uint32_t)>(UFG_RVA(0x957F0))(this, p_ParamUID, p_ResourceTypeNameUID, p_OverrideNameUID, p_Condition, p_OriginalNameUID);
		}

		void SetTextureOverride(uint32_t p_ParamUID, uint32_t p_OverrideNameUID, int p_Condition, uint32_t p_OriginalNameUID)
		{
			SetOverride(p_ParamUID, 0x8B43FABF, p_OverrideNameUID, p_Condition, p_OriginalNameUID);
		}
	};

	class CMaterialModifierParams
	{
	public:
		void* mOverridesPtr;
		int mNumOverrides;

		UFG_PAD(0x4);

		CParamOverride mOverrides[10];
		int mMaxOverrides;

		UFG_PAD(0x4);
	};

	class CTargetPlat
	{
	public:
		char mResolveDepthSurface;
		char mHasDepthSurface;
		char mNumSurfaces;
		char mInvertedDepth;
		unsigned __int16 mNumMips;
		D3D11_VIEWPORT mViewport;
		ID3D11RenderTargetView* mRenderTargetView[32][4];
		ID3D11DepthStencilView* mDepthStencilView;
		ID3D11DepthStencilView* mDepthStencilViewRO;
		void* mMSAATargetTexture[4];
		void* mMSAADepthTexture;
	};

	class CTarget
	{
	public:
		int mWidth;
		int mHeight;
		CTargetPlat* mTargetPlat;
		unsigned int mNumTargetTextures;
		void* mTargetTexture[4];
		char mOwnsTargetTexture[4];
		void* mDepthTexture;
		void* mDepthTextureCopy;
		char mOwnsDepthTexture;
		char mDescription[32];
	};

	class CTexture
	{
	public:

	};
}
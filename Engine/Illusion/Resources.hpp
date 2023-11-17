#pragma once

namespace Illusion
{
	class CBuffer : public UFG::qResourceData
	{
	public:
		uint8_t mBufferType;
		uint8_t mRunTimeCreated;
		uint16_t mFlags;
		uint32_t mDataByteSize;
		UFG::qOffset64<void*> mData;
		uint32_t mElementByteSize;
		uint32_t mNumElements;
		UFG::qOffset64<void*> mBufferUser;
		uint32_t mLastUsedFrameNum;
		uint32_t pad0;
		UFG::CMemoryPool* mMemoryPool;
		uint32_t pad1;
		uint32_t pad2;
	};

	class CMaterial : public UFG::qResourceData
	{
	public:
		__declspec(align(16)) UFG::BitFlags128 mStateBlockMask;
		uint32_t mNumParams;
		UFG::qOffset64<CMaterialUser> mMaterialUser;

		void UpdateParam(uint32_t p_Index, uint32_t p_TypeUID, uint32_t p_NameUID)
		{
			reinterpret_cast<void(_fastcall*)(void*, uint32_t, uint32_t, uint32_t)>(UFG_RVA(0x9360))(this, p_Index, p_TypeUID, p_NameUID);
		}

		void OnLoad()
		{
			reinterpret_cast<void(_fastcall*)(void*)>(UFG_RVA(0x934A0))(this);
		}

		void OnUnload()
		{
			reinterpret_cast<void(_fastcall*)(void*)>(UFG_RVA(0x941D0))(this);
		}

		__inline void Reload()
		{
			OnUnload();
			OnLoad();
		}
	};

	class CModel : public UFG::qResourceData
	{
	public:
		float mAABBMin[3];
		uint32_t mNumPrims;
		float mAABBMax[3];

		UFG_PAD_ALIGN(0x4);

		UFG::qResourceHandle mMaterialTableHandle;
		UFG::qResourceHandle mBonePaletteHandle;
		UFG::qOffset64<UFG::qOffset64<void*>*> mMeshOffsetTable;
		uint32_t mNumMeshes;

		UFG::qOffset64<void*> mModelUser;

		UFG_PAD_ALIGN(0x4);

		uint32_t mLastUsedFrameNum;

		UFG_PAD_ALIGN(0x4);

		UFG::CMemoryPool* mMemoryPool;
		UFG::qResourceHandle mMorphTargetsHandle;
		UFG::qResourceHandle mLocatorsHandle;

		void OnLoad()
		{
			reinterpret_cast<void(_fastcall*)(void*)>(UFG_RVA(0x937A0))(this);
		}

		void OnUnload()
		{
			reinterpret_cast<void(_fastcall*)(void*)>(UFG_RVA(0x943D0))(this);
		}

		__inline void Reload()
		{
			OnUnload();
			OnLoad();
		}
	};
	typedef CModel CModelData;
}
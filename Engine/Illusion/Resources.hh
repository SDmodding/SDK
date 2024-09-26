#pragma once

namespace Illusion
{
	class Buffer : public UFG::qResourceData
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
	typedef Buffer CBuffer;

	class Model : public UFG::qResourceData
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

		UFG_INLINE void OnLoad()
		{
			reinterpret_cast<void(_fastcall*)(void*)>(UFG_RVA(0x937A0))(this);
		}

		UFG_INLINE void OnUnload()
		{
			reinterpret_cast<void(_fastcall*)(void*)>(UFG_RVA(0x943D0))(this);
		}

		UFG_INLINE void Reload()
		{
			OnUnload();
			OnLoad();
		}
	};
	typedef Model CModel;
	typedef Model CModelData;

	class StateBlock : public UFG::qResourceData
	{
	public:
		UFG::qNode<StateBlock> mNode;
		uint32_t mParentUID;
		uint32_t mDataByteSize;
		uint32_t mNumValues;
		uint32_t mStateUID;

		UFG_INLINE uintptr_t GetDataPointer()
		{ 
			return (reinterpret_cast<uintptr_t>(this) + sizeof(StateBlock) + 0x8); 
		}
	};
	typedef StateBlock CStateBlock;

	class StateBlockVehicleLook : public StateBlock
	{
	public:
		UFG_PAD(0x8);
		UFG::qColour m_Colour0;
		UFG::qColour m_Colour1;
		float m_Values0[4];
		float m_Values1[4];
	};
	typedef StateBlockVehicleLook CStateBlockVehicleLook;
}
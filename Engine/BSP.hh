#pragma once

namespace UFG
{
	class CBSPFace
	{
	public:
		uint32_t mSpaceFwdIdx;
		uint32_t mSpaceBckIdx;
	};

	class CBSPNode
	{
	public:
		uint32_t mNodeFwdIdx;
		uint32_t mNodeBckIdx;
		uint16_t mSerial;
		uint16_t mFaceCount;
		qOffset64<uint32_t> mFaces;
		qVector3 mPosition;
		qVector3 mNormal;
	};

	class CBSPSpace
	{
	public:
		uint32_t mFaceCount;
		uint32_t mUID;
		qOffset64<uint32_t> mFaces;
		uint32_t mIndex;
		qVector3 mCenter;
		uint32_t mSectionIndex;
		char mName[32];
		unsigned int mPad[3];
	};

	class CBSP : public qResourceData
	{
	public:
		uint32_t mNodeCount;
		qOffset64<CBSPNode> mNodes;
		uint32_t mFaceCount;
		qOffset64<CBSPFace> mFaces;
		uint32_t mSpaceCount;
		qOffset64<CBSPSpace> mSpaces;
		qVector3 mAABBMin;
		qVector3 mAABBMax;

		UFG_PAD(0x8); 

		char mName[32];

		static UFG_INLINE CBSP* Instance()
		{
			return *reinterpret_cast<CBSP**>(UFG_RVA(0x23A8D78));
		}

		UFG_INLINE CBSPNode* GetNodeByIndex(uint32_t p_Index)
		{
			return mNodes.Get(p_Index, sizeof(CBSPFace));
		}

		UFG_INLINE CBSPFace* GetFaceByIndex(uint32_t p_Index)
		{
			return mFaces.Get(p_Index, sizeof(CBSPFace));
		}

		UFG_INLINE CBSPSpace* GetSpaceByIndex(uint32_t p_Index)
		{
			return mSpaces.Get(p_Index, sizeof(CBSPSpace));
		}
	};
}
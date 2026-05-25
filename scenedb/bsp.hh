#pragma once

namespace UFG
{
	class BSPFace
	{
	public:
		u32 mSpaceFwdIdx;
		u32 mSpaceBckIdx;
	};

	class BSPNode
	{
	public:
		u32 mNodeFwdIdx;
		u32 mNodeBckIdx;
		u16 mSerial;
		u16 mFaceCount;
		qOffset64<u32*> mFaces;
		qVector3 mPosition;
		qVector3 mNormal;
	};

	class BSPSpace
	{
	public:
		u32 mFaceCount;
		u32 mUID;
		qOffset64<u32*> mFaces;
		u32 mIndex;
		qVector3 mCenter;
		u32 mSectionIndex;
		char mName[32];
		u32 mPad[3];
	};

	class BSPInventory : public qResourceInventory
	{
	public:
	};

	class BSP : public qResourceData
	{
	public:
		enum SIDE
		{
			FORWARD,
			BACK,
			COPLANAR
		};

		u32 mNodeCount;
		qOffset64<BSPNode*> mNodes;
		u32 mFaceCount;
		qOffset64<BSPFace*> mFaces;
		u32 mSpaceCount;
		qOffset64<BSPSpace*> mSpaces;
		qVector3 mAABBMin;
		qVector3 mAABBMax;
		u32 mPad[2];
		char mName[32];

		/* Static Functions */

		SDK_SINLINE BSP* Instance() { return SDK_VAR_GET(BSP*, 0x23A8D78); }
		SDK_SINLINE BSPInventory* Inventory() { return SDK_VAR(BSPInventory*, 0x23A9870); }

		/* Impl Functions */

		SDK_INLINE void GetAABB2D(qVector2& vAABBMin, qVector2& vAABBMax) { vAABBMin.x = mAABBMin.x; vAABBMin.y = mAABBMin.y; vAABBMax.x = mAABBMax.x; vAABBMax.y = mAABBMax.y; }

		/* Functions */

		BSPSpace* GetSpaceFromPoint(const qVector3& position, bool force_result, bool dbg_print_serials) {
			return SDK_CALL_FUNC(BSPSpace*, 0x232C20, void*, const qVector3&, bool, bool)(this, position, force_result, dbg_print_serials);
		}
	};
}
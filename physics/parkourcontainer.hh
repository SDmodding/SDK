#pragma once

namespace UFG
{
	class ParkourData
	{
	public:
		u16 v0;
		u16 v1;
		u16 flags;
	};

	class ParkourTreeNode
	{
	public:
		s8 mExtents[6];
		u16 mLeftChild;
		u16 mRightChild;
		s8 mFlags;
		s8 mParkourDataCountLeft;
		s8 mParkourDataCountRight;
		s8 padding;

		/* Functions */

		void ComputeChildAabbs(qVector3& leftMin, qVector3& leftMax, qVector3& rightMin, qVector3& rightMax, const qVector3& parentAabbMin, const qVector3& parentAabbMax) {
			SDK_CALL_FUNC(void, 0xA39B0, void*, qVector3&, qVector3&, qVector3&, qVector3&, const qVector3&, const qVector3&)(this, leftMin, leftMax, rightMin, rightMax, parentAabbMin, parentAabbMax);
		}
	};

	class ParkourQuery : public qNode<ParkourQuery>
	{
	public:
		void(__fastcall* callback)(void*);
		void* userData;
		qVector4 mCentre;
		f32 mRadius;
		qArray<qSafePointer<ParkourHandle>> handlesOut;
	};

	class ParkourContainer : public qResourceData
	{
	public:
		qVector3 mAabbMin;
		qVector3 mAabbMax;
		qVector3* mVertexBuffer;
		ParkourData* mParkourData;
		ParkourTreeNode* mNodes;
		u32 mNumParkourData;
		u32 mNumVertices;
		u32 mNumNodes;
		u32 mFlags;
		u32 padding[2];

		/* Functions */

		void GetVerts(const ParkourComponent* component, const qMatrix44& transform, const ParkourData* pd, qVector3& v0, qVector3& v1) {
			SDK_CALL_FUNC(void, 0x4681F0, void*, const ParkourComponent*, const qMatrix44&, const ParkourData*, qVector3&, qVector3&)(this, component, transform, pd, v0, v1);
		}

		void Query(const ParkourComponent* component, const ParkourQuery* query, hkArray<ParkourData*>& output) {
			SDK_CALL_FUNC(void, 0x471C60, void*, const ParkourComponent*, const ParkourQuery*, hkArray<ParkourData*>&)(this, component, query, output);
		}

		void Query(const ParkourComponent* component, const qVector3& queryAabbMin, const qVector3& queryAabbMax, hkArray<ParkourData*>& output) {
			SDK_CALL_FUNC(void, 0x471220, void*, const ParkourComponent*, const qVector3&, const qVector3&, hkArray<ParkourData*>&)(this, component, queryAabbMin, queryAabbMax, output);
		}

		void VisitNodesRecursive(ParkourTreeNode* node, const qVector3& queryAabbMin, const qVector3& queryAabbMax, const qVector3& parentAabbMin, const qVector3& parentAabbMax, hkArray<ParkourData*>& output) {
			SDK_CALL_FUNC(void, 0xB5930, void*, ParkourTreeNode*, const qVector3&, const qVector3&, const qVector3&, const qVector3&, hkArray<ParkourData*>&)(this, node, queryAabbMin, queryAabbMax, parentAabbMin, parentAabbMax, output);
		}
	};

	class ParkourContainerBundle : public qResourceData
	{
	public:
		u32 mNumContainers;
		qOffset64<ParkourContainer*>* mContainers;
	};

}
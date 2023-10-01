#pragma once

namespace UFG
{
	class CCollisionInstanceData
	{
	public:
		struct Part
		{
			qSafePointer<CSimObject> mSimObject;
			qSymbol mSimObjectGuid;
			uint32_t mInstanceUid;
		};

		hkQuaternionf mOrientation;
		hkQuaternionf mInitialOrientation;
		hkVector4f mPosition;
		hkVector4f mInitialPosition;
		class CSimComponent* mPhysicsComponent;
		qSymbol mSimObjectName;
		uint32_t mNumParts;
		Part* mParts;
		uint32_t mFlags;
		uint32_t mInstanceGuid;
		uint32_t mCollisionModelGuid;
		uint32_t mPadding;

		CCollisionInstanceData()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x975F0))(this);
		}
	};

	class CCollisionMeshData
	{
	public:
		qNodeRB mNode;
		uint64_t mPropertiesHandleGuid;
		uint32_t mBundleGuid;
		uint32_t mGeometryType;
		uint32_t mNumVertices;
		uint32_t mNumIndices;
		uint32_t mNumParts;
		uint32_t mNumFractureConnections;
		uint32_t mShapeKeyDepth;
		qSymbol mSceneNodeName;
		qSymbol mSceneNodeNameUC;
		uint32_t mRenderModelGuid;
		uint32_t mParkourGuid;
		uint32_t mCoverGuid;
		uint32_t mFlags;
		int mCustomDataSlotIndex;
		qVector3 mCentreOfMass;
		qVector3 mInertiaTensorRow0;
		qVector3 mInertiaTensorRow1;
		qVector3 mInertiaTensorRow2;
		float mMass;
		qOffset64<void*> mParts;
		qOffset64<void*> mPartDetails;
		qOffset64<void*> mFractureConnections;
		qOffset64<unsigned short> mIndexBuffer;
		qOffset64<qVector3> mVertexBuffer;
		hkpShape* mShape;
		void* mRemoveTerminalsMoppModifierList;
		void* mFractureConnectivity;
		qSymbol mName;
		uint32_t mSize;
		qReflectHandle<class CPhysicsObjectProperties> mObjectProperties;
		unsigned int padding[2];

		void Constructor(hkpShape* p_Shape)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, hkpShape*)>(UFG_RVA(0x978C0))(this, 0, p_Shape);
		}
	};
}
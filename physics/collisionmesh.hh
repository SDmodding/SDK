#pragma once

namespace UFG
{
	class BaseProperty : public hkpMeshMaterial
	{
	public:
		f32 tireFriction;
		u64 surfacePropertyHandleId;
		u64 objectPropertyHandleId;
		qSymbol collisionModelName;
		u32 flags;
	};

	class CollisionInstanceData
	{
	public:
		struct Part
		{
			qSafePointer<SimObject> mSimObject;
			qSymbol mSimObjectGuid;
			u32 mInstanceUid;
		};

		hkQuaternionf mOrientation;
		hkQuaternionf mInitialOrientation;
		hkVector4f mPosition;
		hkVector4f mInitialPosition;
		SimComponent* mPhysicsComponent;
		qSymbol mSimObjectName;
		u32 mNumParts;
		Part* mParts;
		u32 mFlags;
		u32 mInstanceGuid;
		u32 mCollisionModelGuid;
		u32 mPadding;
	};

	class CollisionMeshData : public qNodeRB<CollisionMeshData>
	{
	public:
		struct DeferredBreakablePartsMark : qNode<DeferredBreakablePartsMark>
		{
			qSafePointer<class RigidBody> rigidBody;
			f32 timer;
		};

		struct FractureConnection
		{
			u32 i;
			u32 j;
		};

		struct Part
		{
			BaseProperty mBaseProperty;
			u32 mVertexBase;
			u32 mIndexBase;
			u32 padding[2];
		};

		struct PartDetails
		{
			hkVector4f mCentreOfMass;
			hkVector4f mInertiaTensorRow0;
			hkVector4f mInertiaTensorRow1;
			hkVector4f mInertiaTensorRow2;
			f32 mMass;
			f32 mShearImpulse;
			qSymbol mPropertySetGuid;
			u32 mCollisionModelUid;
			u32 mRenderModelGuid;
			qSymbol mSceneNodeName;
			qSymbolUC mSceneNodeNameUC;
			u32 padding[1];
		};

		u64 mPropertiesHandleGuid;
		u32 mBundleGuid;
		u32 mGeometryType;
		u32 mNumVertices;
		u32 mNumIndices;
		u32 mNumParts;
		u32 mNumFractureConnections;
		u32 mShapeKeyDepth;
		qSymbol mSceneNodeName;
		qSymbolUC mSceneNodeNameUC;
		u32 mRenderModelGuid;
		u32 mParkourGuid;
		u32 mCoverGuid;
		u32 mFlags;
		int mCustomDataSlotIndex;
		qVector3 mCentreOfMass;
		qVector3 mInertiaTensorRow0;
		qVector3 mInertiaTensorRow1;
		qVector3 mInertiaTensorRow2;
		f32 mMass;
		qOffset64<Part*> mParts;
		qOffset64<PartDetails*> mPartDetails;
		qOffset64<FractureConnection*> mFractureConnections;
		qOffset64<u16*> mIndexBuffer;
		qOffset64<qVector3*> mVertexBuffer;
		hkpShape* mShape;
		void* mRemoveTerminalsMoppModifierList;
		FractureConnectivity* mFractureConnectivity;
		qSymbol mName;
		u32 mSize;
		qReflectHandle<PhysicsObjectProperties> mObjectProperties;
		u32 padding[2];

		void ctor(const hkpShape* shape) { SDK_CALL_FUNC(void, 0x978C0, void*, void*, const hkpShape*)(this, 0, shape); }

		/* Functions */

		//void AddMoppTerminalModifier(hkpRemoveTerminalsMoppModifier* modifier) { SDK_CALL_FUNC(void, 0xA0940, void*, hkpRemoveTerminalsMoppModifier*)(this, modifier); }
		CollisionMeshData* Clone() { return SDK_CALL_FUNC(CollisionMeshData*, 0xA2260, void*)(this); }
		void GetCentreOfMass(hkVector4f& cm) { SDK_CALL_FUNC(void, 0xA9710, void*, hkVector4f&)(this, cm); }
		void GetInertiaTensor(hkMatrix3f& I, f32 massFudgeFactor) { SDK_CALL_FUNC(void, 0xAA240, void*, hkMatrix3f&, f32)(this, I, massFudgeFactor); }
		const Part* GetPart(int index) { return SDK_CALL_FUNC(const Part*, 0xAB0D0, void*, int)(this, index); }
		const PartDetails* GetPartDetails(int index) { return SDK_CALL_FUNC(const PartDetails*, 0xAB110, void*, int)(this, index); }
		void ResetFracture() { SDK_CALL_FUNC(void, 0xAFE30, void*)(this); }
		FractureConnectivity* SplitMeshUsingConnectivity(FractureConnectivity* graph, CollisionMeshData* parent, hkTransformf& transform) { 
			return SDK_CALL_FUNC(FractureConnectivity*, 0xB2D80, FractureConnectivity*, CollisionMeshData*, hkTransformf&)(graph, parent, transform); 
		}
		void UnmarkBreakableParts(hkpEntity* entity) { SDK_CALL_FUNC(void, 0xB4400, void*, hkpEntity*)(this, entity); }
	};
	SDK_ASSERT_SIZEOF(CollisionMeshData, 0x110);
}
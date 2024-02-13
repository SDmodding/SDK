#pragma once

namespace UFG
{
	enum CollisionLayers : uint32_t
	{
		DEFAULT_LAYER = 0x0,
		PLAYER_LAYER = 0x1,
		PLAYER_LAYER2 = 0x2,
		PLAYER_COMBAT_LAYER = 0x3,
		PLAYER_DEAD_LAYER = 0x4,
		PLAYER_ENTER_EXIT_VEHICLE_LAYER = 0x5,
		PLAYER_SITTING_LAYER = 0x6,
		RAGDOLL_LAYER = 0x7,
		RAGDOLL_LAYER_2 = 0x8,
		TERRAIN_LAYER = 0x9,
		DESTRUCTABLE_TERRAIN_LAYER = 0xA,
		WHEELRAYCAST_LAYER = 0xB,
		USER_RAYCAST_LAYER_1 = 0xC,
		USER_RAYCAST_LAYER_2 = 0xD,
		USER_RAYCAST_LAYER_3 = 0xE,
		USER_RAYCAST_LAYER_4 = 0xF,
		USER_RAYCAST_LAYER_5 = 0x10,
		USER_RAYCAST_LAYER_6 = 0x11,
		CAMERA_LAYER = 0x12,
		LIGHT_DEBRIS_LAYER = 0x13,
		HEAVY_DEBRIS_LAYER = 0x14,
		NO_COLLISION_LAYER = 0x15,
		VEHICLE_LAYER = 0x16,
		WORLD_AVOIDANCE_LAYER = 0x17,
		OBJECT_AVOIDANCE_LAYER = 0x18,
		BULLET_LAYER = 0x19,
		WEAPON_LAYER = 0x1A,
		BULLET_REACTION_LAYER = 0x1B,
		WATER_LAYER = 0x1C,
		SENSOR_COMPONENT_LAYER = 0x1D,
		CAMERA_BARRIER_LAYER = 0x1E,
		SEETHROUGH_SHOOTTHROUGH_LAYER = 0x1F,
		NUM_COLLISION_LAYERS = 0x20,
		MAX_LAYERS = 0x20,
		NETWORK_PROXY_LAYER = 0x1,
	};

	//===============================================================

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
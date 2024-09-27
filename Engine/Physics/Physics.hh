#pragma once

namespace UFG
{
	struct RayCastData
	{
		hkpWorldRayCastInput mInput;
		hkpWorldRayCastOutput mOutput;
		const char* mDebugName;
		qSymbol mCollisionModelName;
		qVector3 point;
		qVector3 normal;
		float t;
		hkpRigidBody* mHavokRigidBody;
		void* mHavokPhantom;
		bool hit;
		uint64_t mPhysicsObjectPropertyHandleUid;
		uint64_t mPhysicsSurfacePropertyHandleUid;

		RayCastData()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x99880))(this);
		}

		UFG_INLINE void Init(const qVector3& p_Start, const qVector3& p_End, uint32_t p_CollisionFilter)
		{
			reinterpret_cast<void(__fastcall*)(void*, const qVector3&, const qVector3&, uint32_t)>(UFG_RVA(0xAC0E0))(this, p_Start, p_End, p_CollisionFilter);
		}
	};
	UFG_ASSERT_STRUCT(RayCastData, 0xE0);

	class PhysicsSystem
	{
	public:
		struct __declspec(align(16)) RaycastBatch_t
		{
			UFG_PAD(0xAE40);
			//UFG::AsyncRayCastData mAsyncRayData[164];
			uint32_t mCount;
		};
		UFG_ASSERT_STRUCT(RaycastBatch_t, 0xAE50);

		struct __declspec(align(16)) ShapecastBatch_t
		{
			UFG_PAD(0x2700);
			//UFG::AsyncShapeCasterCollector mAsyncShapeData[48];
			uint32_t mCount;
		};
		UFG_ASSERT_STRUCT(ShapecastBatch_t, 0x2710);

		struct StaticSceneryTracking_t : qNode<StaticSceneryTracking_t>
		{
			qVector3 pos;
			uint32_t guid;
		};

		void* vfptr;
		qTreeRB mCollisionModels;

		UFG_PAD(0x38);
		//UFG::ActiveRegionManager mActiveRegionManager;

		hkArray<hkpEntity*> mEntitiesToAdd;
		hkArray<hkpEntity*> mEntitiesToRemove;
		hkArray<hkpPhantom*> mPhantomsToAdd;
		hkArray<hkpPhantom*> mPhantomsToRemove;
		hkArray<hkpAction*> mActionsToAdd;
		hkArray<class hkpConstraintInstance*> mConstraintsToAdd;
		hkpWorld* mWorld;
		class BroadPhaseHandler* mBroadPhaseBorder;
		class hkJobThreadPool* mThreadPool;
		class hkJobQueue* mJobQueue;
		class HavokJobMemoryPoolTagger* mMemoryPoolTagger;
		hkArray<class hkpWorldRayCastCommand> mRayCastCommands;
		class hkpCollisionQueryJobHeader* mRayCastJobHeader;
		class hkSemaphore* mRayCastSemaphore;
		RaycastBatch_t mRaycastBatches[2];
		RaycastBatch_t* mRaycastBatchSubmitBuffer;
		RaycastBatch_t* mRaycastBatchExecuteBuffer;
		hkArray<class hkpWorldLinearCastCommand> mShapeCastCommands;
		class hkpCollisionQueryJobHeader* mShapeCastJobHeader;
		class hkSemaphore* mShapeCastSemaphore;
		ShapecastBatch_t mShapecastBatch;
		class CustomCollisionFilter* mCollisionFilter;
		uint32_t mFrameNumber;
		bool mBuildingAiData;
		bool mForceRemoveEntitiesToBeBatched;
		bool mRaycastCallbackActive;
		qList<StaticSceneryTracking_t> mStaticSceneryToDisable;
		qList<class SceneryToDisable0> mSceneryFoundForDisable;

		UFG_PAD(0x60);
		//UFG::ThreadSafeQueue<hkpEntity> mEntitiesLeftBroadphase;

		UFG_PAD(0x60);
		//UFG::WorldBoundaries mBoundaries;

		float mWaterElevation;
		float mWaterWaveHeight;
		float mWaterWaveFrequency;
		float mWaterWavePhase;
		float mWaterWaveAngle;

		UFG_STATIC_INLINE PhysicsSystem* Instance()
		{
			return *reinterpret_cast<PhysicsSystem**>(UFG_RVA(0x216B2C8));
		}

		UFG_INLINE CRigidBodyComponent* OnCollisionInstanceAddedToWorld(CollisionInstanceData* p_Instance, CollisionMeshData* p_Mesh, uint32_t p_OnAddedFlags, uint32_t p_RigidBodyFlags, SimObject* p_SimObject)
		{
			return reinterpret_cast<CRigidBodyComponent*(__fastcall*)(void*, CollisionInstanceData*, CollisionMeshData*, uint32_t, uint32_t, SimObject*)>(UFG_RVA(0x46E150))(this, p_Instance, p_Mesh, p_OnAddedFlags, p_RigidBodyFlags, p_SimObject);
		}

		UFG_INLINE void AddRenderHelper(SimObject* p_SimObject, CRigidBodyComponent* p_RigidBody, CollisionInstanceData* p_Instance, CCollisionMeshData* p_Mesh)
		{
			reinterpret_cast<void(__fastcall*)(void*, SimObject*, CRigidBodyComponent*, CCollisionInstanceData*, CCollisionMeshData*)>(UFG_RVA(0x455670))(this, p_SimObject, p_RigidBody, p_Instance, p_Mesh);
		}

		UFG_INLINE void AddDynamicCover(SimObject* p_SimObject, qResourceHandle* p_DynamicCoverHandle)
		{
			reinterpret_cast<void(__fastcall*)(void*, SimObject*, qResourceHandle*)>(UFG_RVA(0x45BE80))(this, p_SimObject, reinterpret_cast<qResourceHandle*>(reinterpret_cast<uintptr_t>(p_DynamicCoverHandle) - 0x50));
		}

		// return: true (if hit something)
		UFG_INLINE bool CastRay(RayCastData* p_Data)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, RayCastData*)>(UFG_RVA(0xA1950))(this, p_Data);
		}

		UFG_INLINE bool CastShape(CShapeCasterCollector* p_ShapeCasterCollector, qVector3 p_Start, qVector3 p_End)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, CShapeCasterCollector*, qVector3*, qVector3*)>(UFG_RVA(0xA1DD0))(this, p_ShapeCasterCollector, &p_Start, &p_End);
		}

		UFG_INLINE void DisableCollisionsBetween(SimObject* p_SimObjectA, SimObject* p_SimObjectB)
		{
			reinterpret_cast<void(__fastcall*)(void*, SimObject*, SimObject*)>(UFG_RVA(0x461A40))(this, p_SimObjectA, p_SimObjectB);
		}

		UFG_INLINE void ReEnableCollisionsBetween(SimObject* p_SimObjectA, SimObject* p_SimObjectB)
		{
			reinterpret_cast<void(__fastcall*)(void*, SimObject*, SimObject*)>(UFG_RVA(0x4723A0))(this, p_SimObjectA, p_SimObjectB);
		}

		// return: true (If 'p_OutPosition' position has been written)
		UFG_STATIC_INLINE bool PlaceOnGround(qVector3* p_OutPosition, qVector3* p_Position, float p_HeightAboveGround, float p_CastDistance)
		{
			return reinterpret_cast<bool(__fastcall*)(qVector3*, qVector3*, float, float)>(UFG_RVA(0x37C400))(p_OutPosition, p_Position, p_HeightAboveGround, p_CastDistance);
		}

		// return: true (If 'p_OutPosition' position has been written)
		UFG_STATIC_INLINE bool PlaceOnGround(qVector3* p_OutPosition, qVector3* p_Position, float p_HeightAboveGround, float p_CastDistanceDown, float p_CastDistanceUp)
		{
			return reinterpret_cast<bool(__fastcall*)(qVector3*, qVector3*, float, float, float)>(UFG_RVA(0x37C560))(p_OutPosition, p_Position, p_HeightAboveGround, p_CastDistanceDown, p_CastDistanceUp);
		}
	}; typedef PhysicsSystem CPhysicsSystem;
	UFG_ASSERT_CLASS(PhysicsSystem, 0x18620);
}
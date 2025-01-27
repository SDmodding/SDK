#pragma once

namespace UFG
{
	class BasePhysicsSystem
	{
	public:
		struct RaycastBatch
		{
			AsyncRayCastData mAsyncRayData[164];
			u32 mCount;
		};

		struct ShapecastBatch
		{
			AsyncShapeCasterCollector mAsyncShapeData[48];
			u32 mCount;
		};

		void* vfptr;
		qTreeRB<CollisionMeshData> mCollisionModels;
		ActiveRegionManager mActiveRegionManager;
		hkArray<hkpEntity*> mEntitiesToAdd;
		hkArray<hkpEntity*> mEntitiesToRemove;
		hkArray<hkpPhantom*> mPhantomsToAdd;
		hkArray<hkpPhantom*> mPhantomsToRemove;
		hkArray<hkpAction*> mActionsToAdd;
		hkArray<hkpConstraintInstance*> mConstraintsToAdd;
		hkpWorld* mWorld;
		BroadPhaseHandler* mBroadPhaseBorder;
		hkJobThreadPool* mThreadPool;
		hkJobQueue* mJobQueue;
		HavokJobMemoryPoolTagger* mMemoryPoolTagger;
		hkArray<hkpWorldRayCastCommand> mRayCastCommands;
		hkpCollisionQueryJobHeader* mRayCastJobHeader;
		hkSemaphore* mRayCastSemaphore;
		RaycastBatch mRaycastBatches[2];
		RaycastBatch* mRaycastBatchSubmitBuffer;
		RaycastBatch* mRaycastBatchExecuteBuffer;
		hkArray<hkpWorldLinearCastCommand> mShapeCastCommands;
		hkpCollisionQueryJobHeader* mShapeCastJobHeader;
		hkSemaphore* mShapeCastSemaphore;
		ShapecastBatch mShapecastBatch;
		CustomCollisionFilter* mCollisionFilter;
		u32 mFrameNumber;
		bool mBuildingAiData;
		bool mForceRemoveEntitiesToBeBatched;
		bool mRaycastCallbackActive;

		/* Virtual Functions */

		// NOTE: This can't be used due to compiler messing the alignment...
		//virtual ~BasePhysicsSystem() = 0;
		//virtual void AddCollisionInstanceToWorld(CollisionInstanceData* instance) = 0;
		//virtual RigidBody* OnCollisionInstanceAddedToWorld(CollisionInstanceData* instance, CollisionMeshData* mesh, u32 onAddedFlags, u32 rigidBodyFlags, SimObject* simObject) = 0;
		//virtual void OnCollisionInstanceRemovedFromWorld(CollisionInstanceData* instance) = 0;
		//virtual void PreFrameUpdate(f32 timestep) = 0;
		//virtual void Update(f32 timestep) = 0;
		//virtual void InitVisualDebugger() = 0; // UNUSED
		//virtual bool CastAsyncRay(const qVector3& rayStart, const qVector3& rayEnd, u32 collisionFilter, void(*callback)(RayCastData*, SimComponent*, void*), SimComponent* simComponent, void* userData) = 0;
		//virtual bool CastAsyncShape(AsyncShapeCasterCollector* caster, SimComponent* simComponent, void* userData) = 0;
		//virtual void PhysicsVolumeHandler(PhantomCallback* pcb, SimObject* simObject, PhantomCallbackData* data) = 0;

		void AddCollisionInstanceToWorld(CollisionInstanceData* instance) { SDK_CALL_VFUNC(void, 1, this, void*, CollisionInstanceData*)(this, instance); }
		RigidBody* OnCollisionInstanceAddedToWorld(CollisionInstanceData* instance, CollisionMeshData* mesh, char onAddedFlags, u32 rigidBodyFlags, SimObject* simObject) {
			return SDK_CALL_VFUNC(RigidBody*, 2, this, void*, CollisionInstanceData*, CollisionMeshData*, char, u32, SimObject*)(this, instance, mesh, onAddedFlags, rigidBodyFlags, simObject);
		}
		void OnCollisionInstanceRemovedFromWorld(CollisionInstanceData* instance) { SDK_CALL_VFUNC(void, 3, this, void*, CollisionInstanceData*)(this, instance); }
		bool CastAsyncRay(const qVector3& rayStart, const qVector3& rayEnd, u32 collisionFilter, void(*callback)(RayCastData*, SimComponent*, void*), SimComponent* simComponent, void* userData) {
			return SDK_CALL_VFUNC(bool, 7, this, void*, const qVector3&, const qVector3&, u32, decltype(callback), SimComponent*, void*)(this, rayStart, rayEnd, collisionFilter, callback, simComponent, userData);
		}
		bool CastAsyncShape(AsyncShapeCasterCollector* caster, SimComponent* simComponent, void* userData) {
			return SDK_CALL_VFUNC(bool, 8, this, void*, AsyncShapeCasterCollector*, SimComponent*, void*)(this, caster, simComponent, userData);
		}
		void PhysicsVolumeHandler(PhantomCallback* pcb, SimObject* simObject, PhantomCallbackData* data) {
			SDK_CALL_VFUNC(void, 9, this, void*, PhantomCallback*, SimObject*, PhantomCallbackData*)(this, pcb, simObject, data);
		}

		/* Impl Functions */

		SDK_INLINE void BeginRemoveEntityBatch() { mForceRemoveEntitiesToBeBatched = true; }

		/* Functions */

		void AddAction(hkpAction* action) { SDK_CALL_FUNC(void, 0x9FDD0, void*, hkpAction*)(this, action); }
		void AddBatchedEntities() { SDK_CALL_FUNC(void, 0x9FE50, void*)(this); }
		void AddConstraint(hkpConstraintInstance* constraint) { SDK_CALL_FUNC(void, 0xA02A0, void*, hkpConstraintInstance*)(this, constraint); }
		void AddEntity(hkpPhantom* p, bool addBatched) { SDK_CALL_FUNC(void, 0xA0460, void*, hkpPhantom*, bool)(this, p, addBatched); }
		void AddEntity(hkpRigidBody* rb, bool addBatched) { SDK_CALL_FUNC(void, 0xA0560, void*, hkpRigidBody*, bool)(this, rb, addBatched); }
		void CancelAllAsyncRayCasts() { SDK_CALL_FUNC(void, 0xA1630, void*)(this); }
		bool CastRay(RayCastData& data) { return SDK_CALL_FUNC(bool, 0xA1950, void*, RayCastData&)(this, data); }
		bool CastShape(ShapeCasterCollector& sc, const qVector3& start, const qVector3& end) {
			return SDK_CALL_FUNC(bool, 0xA1DD0, void*, ShapeCasterCollector&, const qVector3&, const qVector3&)(this, sc, start, end);
		}
		bool CastShape(ShapeCasterCollector& sc, const hkVector4f& start, const hkVector4f& end) {
			return SDK_CALL_FUNC(bool, 0xA1B50, void*, ShapeCasterCollector&, const hkVector4f&, const hkVector4f&)(this, sc, start, end);
		}
		void DetermineRaycastSurfaceProperties(RayCastData& data) { SDK_CALL_FUNC(void, 0xA7050, void*, RayCastData&)(this, data); }
		void DispatchAsyncRayCastResultCallbacks() { SDK_CALL_FUNC(void, 0xA7760, void*)(this); }
		void EndRemoveEntityBatch() { SDK_CALL_FUNC(void, 0xA7E40, void*)(this); }
		CollisionMeshData* GetCollisionModel(u32 guid) { return SDK_CALL_FUNC(CollisionMeshData*, 0xC0B60, void*, u32)(this, guid); }
		void RemoveAction(hkpAction* action) { SDK_CALL_FUNC(void, 0xAF5B0, void*, hkpAction*)(this, action); }
		void RemoveCollisionInstanceFromWorld(CollisionInstanceData* instance) { SDK_CALL_FUNC(void, 0xAF610, void*, CollisionInstanceData*)(this, instance); }
		bool RemoveConstraint(hkpConstraintInstance* constraint) { return SDK_CALL_FUNC(bool, 0xAF620, void*, hkpConstraintInstance*)(this, constraint); }
		void RemoveEntity(hkpPhantom* p, bool removeBatched) { SDK_CALL_FUNC(void, 0xAF770, void*, hkpPhantom*, bool)(this, p, removeBatched); }
		void RemoveEntity(hkpRigidBody* rb, bool removeBatched) { SDK_CALL_FUNC(void, 0xAF890, void*, hkpRigidBody*, bool)(this, rb, removeBatched); }
		bool RequestAnotherRigidBody() { return SDK_CALL_FUNC(bool, 0xAFE20, void*)(this); }
		void StartAsyncRayCasts() { SDK_CALL_FUNC(void, 0xB3500, void*)(this); }
		u32 WaitForAsyncRayCastCompletion() { return SDK_CALL_FUNC(u32, 0xB5D60, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(BasePhysicsSystem, 0x18520);
}
#pragma once

class SceneryToDisable : public UFG::qNode<SceneryToDisable>
{
public:
	UFG::qVector3 pos;
	UFG::SceneryGroup* group;
	u32 index;
};

namespace UFG
{
	class PhysicsSystem : public BasePhysicsSystem
	{
	public:
		enum Mode
		{
			ARM_INTERIOR,
			ARM_SWEATSHOP_INTERIOR,
			ARM_WEDDING_INTERIOR,
			ARM_PENTHOUSE_INTERIOR,
			ARM_EXTERIOR,
			ARM_AIPACKER,
			NUM_MODES
		};

		enum ResetFlags
		{
			PartialReset,
			FullReset
		};

		struct StaticSceneryTracking : qNode<StaticSceneryTracking>
		{
			qVector3 pos;
			u32 guid;
		};

		qList<StaticSceneryTracking> mStaticSceneryToDisable;
		qList<SceneryToDisable> mSceneryFoundForDisable;
		ThreadSafeQueue<hkpEntity> mEntitiesLeftBroadphase;
		qProxy<WorldBoundaries> mBoundaries;
		f32 mWaterElevation;
		f32 mWaterWaveHeight;
		f32 mWaterWaveFrequency;
		f32 mWaterWavePhase;
		f32 mWaterWaveAngle;

		/* Static Functions */

		SDK_SINLINE PhysicsSystem* Instance() { return SDK_VAR_GET(PhysicsSystem*, 0x216B2C8); }
		SDK_SINLINE bool FindParentObjectOfSimObject(SimObject* simObjectToFind, RigidBodyComponent** parentOut, u32& indexOut) {
			return SDK_CALL_FUNC(bool, 0x464830, SimObject*, RigidBodyComponent**, u32&)(simObjectToFind, parentOut, indexOut);
		}

		/* Functions */

		void AddParkourAndCover(SimObject* simObject, RigidBodyComponent* rbc, CollisionMeshData* mesh, int followBone) {
			SDK_CALL_FUNC(void, 0x455060, void*, SimObject*, RigidBodyComponent*, CollisionMeshData*, int)(this, simObject, rbc, mesh, followBone);
		}
		void AddPhysicsComponents(SimObject* simObject, RigResource* rig) { SDK_CALL_FUNC(void, 0x455210, void*, SimObject*, RigResource*)(this, simObject, rig); }
		void AddRenderHelper(SimObject* simObject, RigidBodyComponent* rbc, CollisionInstanceData* instance, CollisionMeshData* mesh) {
			SDK_CALL_FUNC(void, 0x455670, void*, SimObject*, RigidBodyComponent*, CollisionInstanceData*, CollisionMeshData*)(this, simObject, rbc, instance, mesh);
		}
		void AddStateMachines(SimObject* simObject, RigidBodyComponent* rbc, CollisionInstanceData* instance, CollisionMeshData* mesh) {
			SDK_CALL_FUNC(void, 0x455930, void*, SimObject*, RigidBodyComponent*, CollisionInstanceData*, CollisionMeshData*)(this, simObject, rbc, instance, mesh);
		}
		void BroadPhaseBorderHandler(hkpEntity* entity) { SDK_CALL_FUNC(void, 0x459240, hkpEntity*)(entity); }
		void CalculateWorldBoundaries() { SDK_CALL_FUNC(void, 0x45A130, void*)(this); }
		f32 ComputeBuoyancy(f32 cubePosZ, f32 cubeSideLength, f32 waterHeight) { return SDK_CALL_FUNC(f32, 0x45B010, void*, f32, f32, f32)(this, cubePosZ, cubeSideLength, waterHeight); }
		void Create(SimObject* simObject, CollisionData* collisionData, SkeletonData* skeletonData) {
			SDK_CALL_FUNC(void, 0x45B3B0, void*, SimObject*, CollisionData*, SkeletonData*)(this, simObject, collisionData, skeletonData);
		}
		void Create(SimObject* simObject, CoverData* data) { SDK_CALL_FUNC(void, 0x45BE80, void*, SimObject*, CoverData*)(this, simObject, data); }
		void Create(SimObject* simObject, FreeRunData* data) { SDK_CALL_FUNC(void, 0x45BF80, void*, SimObject*, FreeRunData*)(this, simObject, data); }
		void DeleteEntitiesLeftBroadphase() { SDK_CALL_FUNC(void, 0x460C10, void*)(this); }
		void DeleteStreamedCollisionInstances() { SDK_CALL_FUNC(void, 0x4615B0, void*)(this); }
		void DisableCollisionsBetween(SimObject* simObjectA, SimObject* simObjectB) { SDK_CALL_FUNC(void, 0x461A40, void*, SimObject*, SimObject*)(this, simObjectA, simObjectB); }
		void DisableStaticSceneryInstance(u32 sceneryGuid, const qVector3& pos) { SDK_CALL_FUNC(void, 0x461EB0, void*, u32, const qVector3&)(this, sceneryGuid, pos); }
		void FlushWorldBoundaries() { SDK_CALL_FUNC(void, 0x465500, void*)(this); }
		void MakeStaticSceneryInvisible() { SDK_CALL_FUNC(void, 0x46C3E0, void*)(this); }
		void ManageActiveRegions() { SDK_CALL_FUNC(void, 0x46C700, void*)(this); }
		void ReEnableCollisionsBetween(SimObject* simObjectA, SimObject* simObjectB) { SDK_CALL_FUNC(void, 0x4723A0, void*, SimObject*, SimObject*)(this, simObjectA, simObjectB); }
		void RecreateStreamedCollisionInstances() { SDK_CALL_FUNC(void, 0x472770, void*)(this); }
		void RemovePhysicsComponents(SimObject* simObject) { SDK_CALL_FUNC(void, 0x4731F0, void*, SimObject*)(this, simObject); }
		void ResetFracturables() { SDK_CALL_FUNC(void, 0x473810, void*)(this); }
		void ResetParkourComponents() { SDK_CALL_FUNC(void, 0x4738E0, void*)(this); }
		void ResetScene(ResetFlags flags) { SDK_CALL_FUNC(void, 0x473A30, void*, ResetFlags)(this, flags); }
		void RestorePhysicsComponents(SimObject* simObject) { SDK_CALL_FUNC(void, 0x474120, void*, SimObject*)(this, simObject); }
		void SuspendPhysicsComponents(SimObject* simObject) { SDK_CALL_FUNC(void, 0x476590, void*, SimObject*)(this, simObject); }
	};
	SDK_ASSERT_SIZEOF(PhysicsSystem, 0x18620);
}
#pragma once

namespace UFG
{
	class RigidBody : public SimComponent, public BasePhysicsObject
	{
	public:
		enum AabbTypes
		{
			LOCAL_AABB,
			WORLD_AABB
		};

		enum Flags
		{
			ACTIVE_REGION_MGT = (1 << 0),
			INFLATED = (1 << 1),
			SPAWNED_FROM_STREAMED_GEO = (1 << 2),
			RESOURCE_UNLOADED = (1 << 3),
			JUST_SPAWNED = (1 << 4),
			JUST_FRACTURED = (1 << 5),
			MODE_FIXED = (1 << 6),
			MODE_SIMULATED = (1 << 7),
			MODE_ANIMATED_HARDKEYFRAME = (1 << 8),
			MODE_ANIMATED_SOFTKEYFRAME = (1 << 9),
			MODEL_ASSET_BODY = (1 << 10)
		};

		enum FractureStrength
		{
			FRACTURE_STRENGTH_NORMAL,
			FRACTURE_STRENGTH_ALTERNATE
		};

		PhysicsResourceHandle mCollisionMeshBundle;
		CollisionInstanceData* mInstanceData;
		CollisionMeshData* mCollisionMeshData;
		hkpRigidBody* mBody;
		WaterFloatingTrackerBaseComponent* mWaterFloatingTrackerComponent;
		RebindingComponentHandle<TransformNodeComponent> mRootTransformComponent;
		WindAction* mWindAction;
		BitArray256* mFractureState;
		qArray<qSafePointer<Constraint>> mConstraints;
		u32 mFlags;
		u32 mCollisionLayerOverride;
		int mCollisionSystem;

		/* Impl Function */

		SDK_INLINE u32 GetMotionType() { return mFlags & 0x3C0; }
		SDK_INLINE u32 GetCollisionLayerOverride() { return mCollisionLayerOverride != -1 ? mCollisionLayerOverride & (MAX_LAYERS - 1) : -1; }

		/* Functions */

		void AddConstraint(Constraint* constraint) { SDK_CALL_FUNC(void, 0xA0300, void*, Constraint*)(this, constraint); }
		void ApplyAngularImpulse(const qVector3& vel) { SDK_CALL_FUNC(void, 0xA0BC0, void*, const qVector3&)(this, vel); }
		void ApplyForce(f32 timeDelta, const qVector3& force, const qVector3& point) { SDK_CALL_FUNC(void, 0xA0EA0, void*, f32, const qVector3&, const qVector3&)(this, timeDelta, force, point); }
		void ApplyLinearImpulse(const qVector3& impulse) { SDK_CALL_FUNC(void, 0xA1080, void*, const qVector3&)(this, impulse); }
		void ApplyLinearImpulse(const qVector3& impulse, const qVector3& point) { SDK_CALL_FUNC(void, 0xA1000, void*, const qVector3&, const qVector3&)(this, impulse, point); }
		bool Deflate() { return SDK_CALL_FUNC(bool, 0xA68C0, void*)(this); }
		void DeleteAllConstraints() { SDK_CALL_FUNC(void, 0xA6B70, void*)(this); }
		void DisableAllConstraints() { SDK_CALL_FUNC(void, 0xA7220, void*)(this); }
		bool DisableFracturePartByGuid(u32 nodeId) { return SDK_CALL_FUNC(bool, 0xA74B0, void*, u32)(this, nodeId); }
		bool DisableFracturePartByIndex(int index) { return SDK_CALL_FUNC(bool, 0xA75D0, void*, int)(this, index); }
		void DisableFractureParts() { SDK_CALL_FUNC(void, 0xA7670, void*)(this); }
		void EnableAllConstraints() { SDK_CALL_FUNC(void, 0xA77E0, void*)(this); }
		bool EnableFracturePartByGuid(u32 nodeId, FractureStrength strength) { return SDK_CALL_FUNC(bool, 0xA7920, void*, u32, FractureStrength)(this, nodeId, strength); }
		bool EnableFracturePartByIndex(u32 index, FractureStrength strength) { return SDK_CALL_FUNC(bool, 0xA7AE0, void*, u32, FractureStrength)(this, index, strength); }
		void EnableFractureParts(FractureStrength strength) { SDK_CALL_FUNC(void, 0xA7C50, void*, FractureStrength)(this, strength); }
		bool GetAabb(qVector3& aabbMin, qVector3& aabbMax, AabbTypes aabbType) { return SDK_CALL_FUNC(bool, 0xA93B0, void*, qVector3&, qVector3&, AabbTypes)(this, aabbMin, aabbMax, aabbType); }
		
		qVector3 GetAngularVelocity()
		{ 
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0xA9550, void*, qVector3*)(this, &res);
		}

		qVector3 GetCentreOfMass()
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0xA9730, void*, qVector3*)(this, &res);
		}

		u32 GetCollisionLayer() { return SDK_CALL_FUNC(u32, 0xA9810, void*)(this); }
		Constraint* GetConstraintByIndex(u32 index) { return SDK_CALL_FUNC(Constraint*, 0xA9900, void*, u32)(this, index); }
		Constraint* GetConstraintByName(const qSymbol& name) { return SDK_CALL_FUNC(Constraint*, 0xA9920, void*, const qSymbol&)(this, name); }
		f32 GetMass() { return SDK_CALL_FUNC(f32, 0xAA990, void*)(this); }
		u32 GetNumFracturableParts() { return SDK_CALL_FUNC(u32, 0xAAC10, void*)(this); }
		f32 GetPercentFractured() { return SDK_CALL_FUNC(f32, 0xAB1C0, void*)(this); }
		void GetTransform(qMatrix44& mat) { SDK_CALL_FUNC(void, 0xAB650, void*, qMatrix44&)(this, mat); }

		qVector3 GetVelocity()
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0xAB970, void*, qVector3*)(this, &res);
		}

		bool HasFracturedParts() { return SDK_CALL_FUNC(bool, 0xABA60, void*)(this); }
		void Inflate(bool addToWorld) { SDK_CALL_FUNC(void, 0xABAC0, void*, bool)(this, addToWorld); }
		bool IsPartFractured(u32 index) { return SDK_CALL_FUNC(bool, 0xACCD0, void*, u32)(this, index); }
		bool IsSleeping() { return SDK_CALL_FUNC(bool, 0xACD30, void*)(this); }
		void RemoveConstraint(Constraint* constraint) { SDK_CALL_FUNC(void, 0xAF6C0, void*, Constraint*)(this, constraint); }
		void RemoveFromWorld() { SDK_CALL_FUNC(void, 0xAF9E0, void*)(this); }
		void SetAngularVelocity(const qVector3& vel) { SDK_CALL_FUNC(void, 0xB05D0, void*, const qVector3&)(this, vel); }
		void SetCollisionLayer(u32 layerNum, int systemNum, int subSystemNum, int subSystemNumDisable) { 
			SDK_CALL_FUNC(void, 0xB0670, void*, u32, int, int, int)(this, layerNum, systemNum, subSystemNum, subSystemNumDisable);
		}

		void SetLinearDamping(f32 d) { SDK_CALL_FUNC(void, 0xB13D0, void*, f32)(this, d); }
		void SetMotionType(u32 mode) { SDK_CALL_FUNC(void, 0xB1500, void*, u32)(this, mode); }
		void SetTransform(const qMatrix44& mat) { SDK_CALL_FUNC(void, 0xB2630, void*, const qMatrix44&)(this, mat); }
		void SetVelocity(const qVector3& vel) { SDK_CALL_FUNC(void, 0xB2850, void*, const qVector3&)(this, vel); }
	};
}
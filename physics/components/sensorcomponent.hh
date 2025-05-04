#pragma once

namespace UFG
{
	class WallRunningRequest : public qNode<WallRunningRequest>
	{
	public:
		f32 relativeAngle;
		f32 firstRayHeight;
		f32 raySpacing;
		f32 rayLength;
		u32 queuedForDeletion;
		ParkourHandle* parkourHandle;
	};

	class SensorComponent : public SimComponent, public qNode<SensorComponent>
	{
	public:
		enum { _TypeUID = 0x84000001 };

		SensorPhantom* mSensor;
		qList<WallRunningRequest> mWallRunningRequests;
		qList<WallRunningRequest> mLatchedWallRunningRequests;
		ParkourQuery* mParkourQuery;
		ShapeCasterCollector* mSphereCaster;
		ActiveRegion* mActiveRegion;
		f32 mSensorPhantomSizeX;
		f32 mSensorPhantomSizeY;
		f32 mSensorPhantomSizeZ;

		/* Static Functions */

		SDK_SINLINE SensorComponent* PropertiesOnActivateNew(SceneObjectProperties* sceneObject, bool required = 1) {
			return SDK_CALL_FUNC(SensorComponent*, 0x4710F0, SceneObjectProperties*, bool)(sceneObject, required);
		}

		/* Impl Functions */

		SDK_INLINE void EndWallRunningTest(WallRunningRequest* request) { request->queuedForDeletion = 1; }

		/* Functions */

		WallRunningRequest* BeginWallRunningTest() { return SDK_CALL_FUNC(WallRunningRequest*, 0x4591A0, void*)(this); }

		bool CastSphere(const qMatrix44& transform, f32 radius, u32 collisionFilter, const qVector3& start, const qVector3& end, SimObject* trueIfHits) {
			return SDK_CALL_FUNC(bool, 0x45A260, void*, const qMatrix44&, f32, u32, const qVector3&, const qVector3&, SimObject*)(this, transform, radius, collisionFilter, start, end, trueIfHits);
		}

		void CollectParkourHandles(f32 queryRadius) { SDK_CALL_FUNC(void, 0x45A710, void*, f32)(this, queryRadius); }
		void CollectWallRunningInfo() { SDK_CALL_FUNC(void, 0x45A760, void*)(this); }
		void GetExtents(qVector3& vmin, qVector3& vmax) { SDK_CALL_FUNC(void, 0x466720, void*, qVector3&, qVector3&)(this, vmin, vmax); }
		void GetParkourHandles(qFixedArray<qSafePointer<ParkourHandle>, 768>& out) { SDK_CALL_FUNC(void, 0x466C80, void*, qFixedArray<qSafePointer<ParkourHandle>, 768>&)(this, out); }
		void PropertiesLoad(component_Sensor* dataPtr) { SDK_CALL_FUNC(void, 0x470AC0, void*, component_Sensor*)(this, dataPtr); }
		void Update(f32 delta_sec) { SDK_CALL_FUNC(void, 0x47D2F0, void*, f32)(this, delta_sec); }
	};
	SDK_ASSERT_SIZEOF(SensorComponent, 0xA0);
}
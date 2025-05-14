#pragma once

namespace UFG
{
	class ProjectileInfo
	{
	public:
		qSafePointer<SimComponent, SimObjectWeaponPropertiesComponent> m_pSOWPC;
		SubTargetingLocation* m_pSubTargetingLocation;
		bool m_bIsFullyAccurate;
		bool m_bIsHardLocked;
	};
	SDK_ASSERT_SIZEOF(ProjectileInfo, 0x28);

	class Bullet : public qNode<Bullet>
	{
	public:
		qSafePointer<SimObject> weaponOwnerSimObject;
		qSafePointer<SimObject> mustHitSimObject;
		ProjectileInfo projectileInfo;
		OneShotHandle oneShot;
		TransformNodeComponent* transformNodeComponent;
		Render::BeamSettingsHandle* tracerSettingsHandle;
		Render::BeamSettingsHandle* tracerTrailSettingsHandle;
		qVector3 pos_t0;
		qVector3 pos_t1;
		qVector3 pos_launch;
		qVector3 vel;
		qColour tracerColour;
		qColour tracerTrailColour;
		f32 mProjectileGravity;
		f32 mArmingDistance;
		f32 mDistanceTraveled;
		f32 mLifeSpan;
		f32 age;
		f32 mObscuredLength;
		u32 grenadeEffectID;
		eTargetTypeEnum mustHitTarget;
		bool mSharpshooter : 1;
		bool isNetworkProxy : 1;
		bool showTracer : 1;
		bool deleteMe : 1;
		bool hasBeenAbsorbed : 1;
		bool firstHit : 1;

		/* Functions */

		void Explode() { SDK_CALL_FUNC(void, 0x463E40, void*)(this); }
		void PlayBulletBy() { SDK_CALL_FUNC(void, 0x46FAF0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(Bullet, 0x100);

	class BulletManager
	{
	public:
		qList<TargetSphere> mTargetSpheres;
		qList<Bullet> mBulletList;
		qArray<qSymbol> mSimObjectsToIgnore;

		virtual ~BulletManager() = 0;

		/* Static Functions */

		SDK_SINLINE BulletManager* Instance() { return SDK_VAR_GET(BulletManager*, 0x24033D0); }
		SDK_SINLINE Render::BeamSettingsHandle* GetBeamSettingsHandle(const qSymbolUC& beamSettingsSymbol) {
			return SDK_CALL_FUNC(Render::BeamSettingsHandle*, 0x4661D0, void*, const qSymbolUC&)(0, beamSettingsSymbol);
		}

		/* Functions */

		void AddTargetSphere(TargetSphere* sphere) { SDK_CALL_FUNC(void, 0x455D40, void*, TargetSphere*)(this, sphere); }
		void RemoveTargetSphere(TargetSphere* sphere) { SDK_CALL_FUNC(void, 0x473240, void*, TargetSphere*)(this, sphere); }

		void ApplyBulletImpactImpulse(Bullet* bullet, const RayCastData& ray, HavokUserData* hd) {
			SDK_CALL_FUNC(void, 0x456350, void*, Bullet*, const RayCastData&, HavokUserData*)(this, bullet, ray, hd);
		}

		bool ApplyDamage(Bullet* bullet, const RayCastData& bulletRay, HavokUserData* hd) {
			return SDK_CALL_FUNC(bool, 0x456B40, void*, Bullet*, const RayCastData&, HavokUserData*)(this, bullet, bulletRay, hd);
		}

		void DisableBulletImpacts(SimObject* simObject) { SDK_CALL_FUNC(void, 0x461980, void*, SimObject*)(this, simObject); }
		void EnableBulletImpacts(SimObject* simObject) { SDK_CALL_FUNC(void, 0x463DA0, void*, SimObject*)(this, simObject); }

		void FireBullet(SimObject* pWeaponOwnerSimObject, const qVector3& muzzleDir, const qVector3& pos, const qVector3& vel, f32 projectileGravity, f32 armingDistance, bool posIsObscured, const qVector3& unobscuredPos, const ProjectileInfo& pi, bool showTracer, bool isNetworkProxy, eTargetTypeEnum eMustHitTarget) {
			SDK_CALL_FUNC(void, 0x4649A0, void*, SimObject*, const qVector3&, const qVector3&, const qVector3&, f32, f32, bool, const qVector3&, const ProjectileInfo&, bool, bool, eTargetTypeEnum)(this, pWeaponOwnerSimObject, muzzleDir, pos, vel, projectileGravity, armingDistance, posIsObscured, unobscuredPos, pi, showTracer, isNetworkProxy, eMustHitTarget);
		}

		void SendBulletImpactEvent(SimObject* simObject, SimObject* initiatorSimObject) { SDK_CALL_FUNC(void, 0x4742F0, void*, SimObject*, SimObject*)(this, simObject, initiatorSimObject); }

		void SendBulletImpactEvent(Bullet* bullet, const RayCastData& bulletRay, HavokUserData* hd) {
			SDK_CALL_FUNC(void, 0x474400, void*, Bullet*, const RayCastData&, HavokUserData*)(this, bullet, bulletRay, hd);
		}

		TargetSphere* TestAgainstTargetSpheres(Bullet* bullet, f32& t) { return SDK_CALL_FUNC(TargetSphere*, 0x476CD0, void*, Bullet*, f32&)(this, bullet, t); }
	};
	SDK_ASSERT_SIZEOF(BulletManager, 0x38);
}
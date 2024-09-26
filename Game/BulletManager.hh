#pragma once

namespace UFG
{
	class CBullet
	{
	public:
		qNode<CBullet> mNode;
		qSafePointer<SimWeapon> weaponOwnerSimObject;
		qSafePointer<SimObject> mustHitSimObject;

		UFG_PAD(0x30);
		/*UFG::ProjectileInfo projectileInfo;
		UFG::OneShotHandle oneShot;*/

		CTransformNodeComponent* transformNodeComponent;
		void* tracerSettingsHandle;
		void* tracerTrailSettingsHandle;
		qVector3 pos_t0;
		qVector3 pos_t1;
		qVector3 pos_launch;
		qVector3 vel;
		qColour tracerColour;
		qColour tracerTrailColour;
		float mProjectileGravity;
		float mArmingDistance;
		float mDistanceTraveled;
		float mLifeSpan;
		float age;
		float mObscuredLength;
		qSymbol grenadeEffectID;
		eTargetTypeEnum mustHitTarget;
		bool mSharpshooter : 1;
		bool isNetworkProxy : 1;
		bool showTracer : 1;
		bool deleteMe : 1;
		bool hasBeenAbsorbed : 1;
		bool firstHit : 1;
	};

	//================================================================================================================================

	class CBulletManager
	{
	public:
		void* vfptr;
		qList<void*> mTargetSpheres;
		qList<CBullet> mBulletList;
		qArray<qSymbol> mSimObjectsToIgnore;

		static UFG_INLINE CBulletManager* Instance()
		{
			return *reinterpret_cast<CBulletManager**>(UFG_RVA(0x24033D0));
		}

		UFG_INLINE qResourceHandle* GetBeamSettingsHandle(uint32_t p_NameUID)
		{
			return reinterpret_cast<qResourceHandle*(__fastcall*)(void*, uint32_t*)>(UFG_RVA(0x4661D0))(this, &p_NameUID);
		}
	};
	UFG_ASSERT_CLASS(CBulletManager, 0x38);
}
#pragma once

namespace UFG
{
	class VehiclePhantom
	{
	public:
		u32 mMarkerUID;
		qVector3 mHalfExtents;
	};

	enum eVehicleWindowTypeEnum
	{
		eVEHICLE_WINDOW_TYPE_FRONT,
		eVEHICLE_WINDOW_TYPE_REAR,
		eVEHICLE_WINDOW_TYPE_FRONT_LEFT,
		eVEHICLE_WINDOW_TYPE_FRONT_RIGHT,
		eVEHICLE_WINDOW_TYPE_REAR_LEFT,
		eVEHICLE_WINDOW_TYPE_REAR_RIGHT,
		NUM_VEHICLE_WINDOW_TYPES
	};

}

namespace UFG
{
	enum VehicleEffectId
	{
		FX_NIGHTTIME,
		FX_DAYTIME,
		FX_PLAYERHEADLIGHTS,
		FX_TRAFFICHEADLIGHTS,
		FX_PLAYERHEADLIGHTFLARES,
		FX_TRAFFICHEADLIGHTFLARES,
		FX_BRAKELIGHTS,
		FX_COPHEADLIGHTS,
		FX_EXHAUST_CLEAN,
		FX_EXHAUST_DIRTY,
		FX_AIEXHAUST_CLEAN,
		FX_AIEXHAUST_DIRTY,
		FX_AILOWLODEXHAUST,
		FX_REVERSE,
		FX_LEFTTURN,
		FX_RIGHTTURN,
		FX_INTERIORLIGHTS,
		FX_TAXILIGHTS,
		FX_DISABLED,
		FX_ENGINEDAMAGE,
		FX_ENGINEBLOWN,
		FX_DESTROYEDVEHICLE,
		FX_SMOLDERING,
		FX_DRAGGING,
		FX_ROOFSLIDING,
		FX_DESTRUCTFRONT,
		FX_DESTRUCTMID,
		FX_DESTRUCTREAR,
		FX_DAMAGE,
		FX_WINDOWSHATTER,
		FX_WINDOWBREAKSM,
		FX_WINDOWBREAKMD,
		FX_WINDOWBREAKLG,
		FX_SPRAY,
		FX_AISPRAY,
		FX_ENTERWATER,
		FX_EXITWATER,
		FX_WHEELEDVEHICLEJUMP,
		FX_WHEELEDVEHICLEIMPACT,
		EFFECT_TABLE_SIZE
	};

	class VehicleEffect : qNodeRB<VehicleEffect>
	{
	public:
		qSymbol mName;
		qSymbol mTransform;
		u32 mMarker;
		qSymbolUC mMarkerHash;
		u32 mBoundEffect[4];
		u32 mRequestedSpeed;
		u32 mSpeed;
		u32 mForwardBone;
		u32 mRearBone;
		u32 mDamageAffectorBone;
		qSymbolUC mDamageAffectorHash;
		u32 mDamageBone;
		qSymbolUC mDamageBoneHash;
		u32 mEffectRef;
		FX::SharedPointer<Render::FXOverride> mEffectOverride;
		u32 mDamageMarkerIndex;
	};

	class VehicleEffectState : public qNodeRB<VehicleEffectState>
	{
	public:
		qSymbol mStateSymbol;
		qTreeRB<VehicleEffect> mEffects;
		VehiclePhantom* mPhantom;
	};

	class EffectStatus
	{
	public:
		enum State
		{
			UNINITIALIZED,
			PENDING_MARKER_RESOLVE,
			NOT_FOUND,
			ACTIVE,
			INACTIVE
		};

		State mState;
		VehicleEffectState* mInternalState;
		bool mQueuedToPlay : 1;
	};

	class HullSprayEffects
	{
	public:
		f32 mBuoyancyRatio;
		u32 mDropletEffectRef;
		qVector3 mWaterLinePosition;
		VehicleEffect* mEffectState;
		TransformNodeComponent* mTransform;
	};
}
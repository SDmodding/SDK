#pragma once

namespace UFG
{
	enum eIconTexturePageIndex
	{
		TPCharacterPlayer,
		TPCharacterPerson,
		TPCharacterStar,
		TPObjectiveCircle,
		TPObjectiveCircleStart,
		TPCollectibleCamera,
		TPCollectibleShrine,
		TPCollectibleLockbox,
		TPAmbientFerry,
		TPAmbientBus,
		TPAmbientPorkBun,
		TPAmbientClothingStore,
		TPAmbientSafehouse,
		TPAmbientGarage,
		TPAmbientVehicleStore,
		TPAmbientGamblingDen,
		TPAmbientMassage,
		TPAmbientDoj1,
		TPAmbientApocathery,
		TPAmbientConvenienceStore,
		TPAmbientFightClub,
		TPAmbientCockFighting,
		TPObjectiveRaceFlag,
		TPUpArrow,
		TPCollectibleJump,
		TPCollectibleStatue,
		TPAmbientSafehouseStore,
		TPObjectiveTriadWars,
		TPAmbientRoadBlock,
		TPAmbientKaraoke,
		TPCharacterSocial,
		TPNotAvailable,
		TPPortal,
		TPTimeTrial,
		TPTrench,
		TPTPoliceCase,
		TPTEvent,
		TPTJob,
		TPDownArrow = 99,
		TPSinglePagesStart,
		TPFeatheredCircle = TPSinglePagesStart,
		TPBigRing,
		TPCopRadius,
		TPPulse
	};
}

namespace UFG
{
	class UIHKObjectiveDistanceWidget
	{
	public:
		enum eArrowDirection
		{
			ARROW_LEFT,
			ARROW_RIGHT,
			ARROW_UP,
			ARROW_DOWN,
			ARROW_HIDDEN
		};

		bool mVisibleSynced;
		bool mVisible;
		bool mChanged;
		bool mEnabled;
		bool mIsOnScreen;
		bool mPosSet;
		qVector3 mWorldPos;
		qVector3 mScreenPos;
		float mDistance;
		qString mCaption;
		eArrowDirection mArrowDirection;
		f32 mTargetSimObject_AcquireCounter;
		f32 mOldDistance;
		f32 mOldAlpha;
		qColour mColor;
		u32 mCoronaType;
		bool mColorChanged;
		qSymbol mAssociatedIcon;
		eIconTexturePageIndex mAssociatedIconIndex;
		Objective* mObjective;
		qSafePointer<SimObject> mTargetSimObj;
		qSymbol mSimObjectID;

		/* Static Functions */

		SDK_SINLINE UIHKObjectiveDistanceWidget* Instance() { return SDK_VAR_GET(UIHKObjectiveDistanceWidget*, 0x2430BC8); }

		/* Impl Functions */

		SDK_INLINE void SetEnabled(bool enabled) { mChanged |= (mEnabled != enabled); mEnabled = enabled; }

		/* Functions */

		void Clear() { SDK_CALL_FUNC(void, 0x5D51E0, void*)(this); }
		void Flash_SetColor(Scaleform::GFx::Movie* movie, const qColour& color) { SDK_CALL_FUNC(void, 0x5DFB10, void*, Scaleform::GFx::Movie*, const qColour&)(this, movie, color); }
		void SetArrowDirection(Scaleform::GFx::Movie* movie, eArrowDirection dir) { SDK_CALL_FUNC(void, 0x605220, void*, Scaleform::GFx::Movie*, eArrowDirection)(this, movie, dir); }
		void SetObjective(UIHKPlayerObjective* objective) { SDK_CALL_FUNC(void, 0x606630, void*, UIHKPlayerObjective*)(this, objective); }
		void Update(UIScreen* screen, f32 elapsed) { SDK_CALL_FUNC(void, 0x615440, void*, UIScreen*, f32)(this, screen, elapsed); }
	};
	SDK_ASSERT_SIZEOF(UIHKObjectiveDistanceWidget, 0xA8);
}
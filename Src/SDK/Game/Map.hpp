#pragma once

namespace UFG
{
	class CMapGPS
	{
	public:
		float mGPS_UpdatePeriod;
		bool mOnlyShowInVehicles;
		bool mChanged;
		bool mDestChanged;
		bool mActive;
		bool mVisible;
		bool mInVehicle;
		bool mNoDestination;
		bool mUsePlayerSourcePos;
		bool mInteriorActive;
		bool mIsManualMapDest;
		float mUpdateTimer;
		unsigned int mMaxNumSplinePoints;
		qVector3 mSourcePos;
		qVector3 mSourceDir;
		qVector3 mDestinationPos;
		qVector3 mDestinationDir;

		UFG_PAD(0x438);

		qArray<qVector3> mSplinePoints;
		unsigned int mNumSplinePoints;
		void* mTrueDirectionIntersectionLane;
		bool mTrueDirectionHighwayRamp;
		unsigned int mTrueDirectionEdgeCount;
	};

	class CUIHKMinimapBlipType
	{
	public:
		qSymbol TypeNameSymbol;
		qSymbol Icon;
		qString Caption;
		bool IsWorldMapOnly;
		bool IsObjective;
		bool IsDistanceFiltered;
		bool IsDistanceFilteredOnWorldMap;
		bool IsWorldMapZoomFiltered;

		UFG_PAD(0x4);

		float FilterDistance;
		float WorldMapZoomFilter;
		qColour RadiusColor;
		qColour InnerRadiusColor;
		unsigned int DrawDepth;
		bool IsHiddenIndoors;
		bool HasAltitude;
		bool IsProximityUnlockable;
		bool HideOnBorder;
		qSymbol ProgressionFlow;
		bool IsVisible;

		UFG_PAD(0x4);
	};

	class CUIMapBlipGraphicPoly
	{
	public:
		unsigned int TextureID;

		UFG_PAD(0x4);

		UFG::qMatrix44* Matrix;
		float UVs[4];
		float Scale;
		float X;
		float Y;
		float OffsetX;
		float OffsetY;
		float Size;
		UFG::qColour Color;
		bool Visible;
	};

	class CUIMapBlipGraphic
	{
	public:
		void* vfptr;
		bool mAnimateBlink;
		float mBlinkScale;
		unsigned int mBlinkTimesLooped;
		unsigned int mBlinkTimesMax;

		CUIMapBlipGraphicPoly* mPolys[5];
		CUIMapBlipGraphicPoly mIconPoly;
	};

	class CUIMapBlipTypeManager
	{
	public:
		qArray<CUIHKMinimapBlipType> mData;
		unsigned int mNumTypes;

	};

	class CUIMapBlip
	{
	public:
		qBaseNodeRB mNode;

		bool mBoundIcon;
		bool mHasAltitude;
		bool mHasObjectiveHighlight;
		bool mUseCustomFilterDistance;
		float mCustomFilterDistance;
		float mAltitudeIconRangeSq;
		bool mIsAmbient;
		bool mChanged;
		bool mIconTypeChanged;
		bool mVisible;
		CUIHKMinimapBlipType* mType;
		void* mObjective;
		qVector3 pos;
		float rot;
		float mAltitudeDiff;
		int mAltitudeState;
		bool mAltitudeStateChanged;
		bool mInAltitudeRange;
		bool mHasRadius;
		bool mHasInteriorRadius;
		bool mTouchesEdge;
		float radiusScale;
		bool mShouldBlink;
		bool mShouldPulse;
		bool mShouldHighlight;
		bool mShouldStopBlink;
		bool mShouldStopHighlight;
		bool mIsSelectedObjective;
		bool mProximityUnlockDone;
		const char* mWorldMapCaption;
		CUIMapBlipGraphic* mNativeIcon;

		void SetVisible(bool visible) { reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0xCB8B0))(this, visible); }

		void SetPosition(qVector3* worldPos) { reinterpret_cast<void(__fastcall*)(void*, qVector3*)>(UFG_RVA(0xCB3B0))(this, worldPos); }

		void SetColor(qColour col)
		{
			if (mNativeIcon)
				mNativeIcon->mIconPoly.Color = col;
		}

		void SetHigherAltitude() { reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xCA880))(this); }

		void SetNormalAltitude() { reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xCAE30))(this); }

		void SetLowerAltitude() { reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xCACA0))(this); }

		void SetWorldMapCaption(const char* caption) { reinterpret_cast<void(__fastcall*)(void*, const char*)>(UFG_RVA(0xCB8F0))(this, caption); }
	};

	class CUIMapBlipManager
	{
	public:
		UFG_PAD(0x8);

		qTreeRB mIconData;
		qArray<CUIMapBlip> mSortedIcons;
		bool mNeedToSort;
		int mMaxNumIcons;
		bool mAmbientBlipsPopulated;
		void* mPlayerArrowIcon;

		CUIMapBlip* GetBlip(unsigned int uid)
		{
			return reinterpret_cast<CUIMapBlip*>(mIconData.mTree.Get(uid));
		}

		CUIMapBlip* CreateIcon(unsigned int uid, const char* iconType, float xPos, float yPos)
		{
			return reinterpret_cast<CUIMapBlip*(__fastcall*)(void*, unsigned int, const char*, float, float)>(UFG_RVA(0xBEA40))(this, uid, iconType, xPos, yPos);
		}

		void RemoveIcon(unsigned int uid)
		{
			return reinterpret_cast<void(__fastcall*)(void*, unsigned int)>(UFG_RVA(0xC71A0))(this, uid);
		}
	};

	namespace Map
	{
		CMapGPS* GetGPS() { return *reinterpret_cast<CMapGPS**>(UFG_RVA(0x24310A0)); }

		CUIMapBlipTypeManager* GetBlipTypeManager() { return reinterpret_cast<CUIMapBlipTypeManager*(__fastcall*)()>(UFG_RVA(0xCEFE0))(); }

		CUIMapBlipManager* GetBlipManager() { return *reinterpret_cast<CUIMapBlipManager**>(UFG_RVA(0x2430CD8)); }

		float GetApproxAltitude(qVector3& pos) { return reinterpret_cast<float(__fastcall*)(qVector3&)>(UFG_RVA(0xC0CE0))(pos); }
	}
}
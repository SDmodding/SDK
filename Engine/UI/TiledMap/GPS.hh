#pragma once

namespace UFG
{
	class CUITiledMapGPS
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

		static UFG_INLINE CUITiledMapGPS* Instance()
		{ 
			return *reinterpret_cast<CUITiledMapGPS**>(UFG_RVA(0x24310A0)); 
		}
	};
}
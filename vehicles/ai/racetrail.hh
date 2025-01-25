#pragma once

namespace UFG
{
	class RaceTrail;

	class RacePoint
	{
	public:
		qVector3 vPosition;
		f32 fSpeed;
		qVector3 vDirection;
		f32 fLength;
		qVector3 vDistanceRay;
		f32 fCurvature;
		f32 fRaceDistance;
		f32 fTimeBonus;

		/* Functions */

		qVector3 GetNextPosition() { return SDK_CALL_FUNC(qVector3, 0x64E960, void*)(this); }
		f32 GetSegmentDistance(const qVector3& position) { return SDK_CALL_FUNC(f32, 0x64F370, void*, const qVector3&)(this, position); }
		qVector3 GetSegmentPosition(const qVector3& position) { return SDK_CALL_FUNC(qVector3, 0x64F490, void*, const qVector3&)(this, position); }
	};

	class RacePosition
	{
	public:
		qSafePointer<RaceTrail> pRaceTrail;
		RacePoint* pRacePoint;
		qVector3 vUpdatePosition;
		f32 fUpdateDistanceSq;
		f32 fRaceDistance;
		f32 fRaceProximity;
		f32 fBonusDistance;
		f32 fRaceTime;
		f32 fCountDownTime;

		/* Functions */

		int GetRaceIndex() { return SDK_CALL_FUNC(int, 0x64EFA0, void*)(this); }
		void InitPosition(const qVector3& position) { SDK_CALL_FUNC(void, 0x651970, void*, const qVector3&)(this, position); }
	};

	class RaceTrail : public qSafePointerNode<RaceTrail>
	{
	public:
		int nLaps;
		int nPoint;
		bool bIsLoop;
		f32 fLength;
		int mRaceIndex;
		int nRacePoints;
		RacePoint* pRacePoints;

		RaceTrail(int num_points, int raceIndex) { SDK_CALL_FUNC(void, 0x642DE0, void*, int, int)(this, num_points, raceIndex); }
		~RaceTrail() { SDK_CALL_FUNC(void, 0x643DB0, void*)(this); }

		/* Functions */

		void AddRacePoint(const qVector3& position, f32 speed, f32 bonus) { SDK_CALL_FUNC(void, 0x6448D0, void*, const qVector3&, f32, f32)(this, position, speed, bonus); }
		void Finalize() { SDK_CALL_FUNC(void, 0x64CD70, void*)(this); }
		RacePoint* GetRacePoint(const qVector3& position, f32* distSq) { return SDK_CALL_FUNC(RacePoint*, 0x64EFC0, void*, const qVector3&, f32*)(this, position, distSq); }
	};
}
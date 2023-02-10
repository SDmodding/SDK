#pragma once

namespace UFG
{
	class CRacePoint
	{
	public:
		qVector3 vPosition;
		float fSpeed;
		qVector3 vDirection;
		float fLength;
		qVector3 vDistanceRay;
		float fCurvature;
		float fRaceDistance;
		float fTimeBonus;
	};

	class CRaceTrail
	{
	public:
		UFG_PAD(0x18);

		int nLaps;
		int nPoint;
		bool bIsLoop;
		float fLength;
		int mRaceIndex;
		int nRacePoints;
		CRacePoint* pRacePoints;

		~CRaceTrail()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x643DB0))(this);
		}

		CRaceTrail() { }
		CRaceTrail(int num_points, int raceIndex = 0)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, int)>(UFG_RVA(0x642DE0))(this, num_points, raceIndex);
		}

		void AddPoint(qVector3* position, float speed, float bonus)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, float, float)>(UFG_RVA(0x6448D0))(this, position, speed, bonus);
		}

		void Finalize()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x64CD70))(this);
		}
	};

	class CRacePosition
	{
	public:
		UFG_PAD(0x10);

		CRaceTrail* pRaceTrail;
		CRacePoint* pRacePoint;
		qVector3 vUpdatePosition;
		float fUpdateDistanceSq;
		float fRaceDistance;
		float fRaceProximity;
		float fBonusDistance;
		float fRaceTime;
		float fCountDownTime;
	};
}
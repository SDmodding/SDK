#pragma once

namespace UFG
{
	class CollisionEvent : public Event
	{
	public:
		enum ContactType
		{
			COLLIDING,
			SLIDING,
			ROLLING
		};

		ContactType mType;
		qVector3 position;
		qVector3 normal;
		f32 speed;
		f32 estimatedImpulseMagnitude;
		qSafePointer<SimObject> mSimObject[2];
		qVector3 preCollisionPosition[2];
		qVector3 velocity[2];
		u64 objectPropertyHandleUID[2];
		u64 surfacePropertyHandleUID[2];
		HavokUserData* havokUserData[2];
	};
}
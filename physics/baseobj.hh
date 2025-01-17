#pragma once

namespace UFG
{
	class HavokUserData
	{
	public:
		bool isBoat;
		qSafePointer<class SimComponent> simComponent;
	};

	class BasePhysicsObject
	{
	public:
		HavokUserData mUserData;

		virtual ~BasePhysicsObject() = 0;
	};

	class PhysicsResourceHandle : public qResourceHandle
	{
	public:
		BasePhysicsObject* mOwner;
		bool mUnloading;
	};
}
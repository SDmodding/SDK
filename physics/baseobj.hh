#pragma once

namespace UFG
{
	class HavokUserData
	{
	public:
		bool isBoat;
		qSafePointer<class SimComponent> simComponent;
	};

	class PhysicsResourceHandle;

	class BasePhysicsObject
	{
	public:
		HavokUserData mUserData;

		virtual ~BasePhysicsObject() = 0;
		virtual void ResourceLoaded(PhysicsResourceHandle* res) = 0;
		virtual void ResourceUnloaded(PhysicsResourceHandle* res) = 0;
	};

	class PhysicsResourceHandle : public qResourceHandle
	{
	public:
		BasePhysicsObject* mOwner;
		bool mUnloading;
	};
}
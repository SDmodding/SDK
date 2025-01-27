#pragma once

namespace UFG
{
	class PhantomCallbackShape : public hkpPhantomCallbackShape
	{
	public:
		PhysicsVolumeProperties* mVolumeProperties;
	};

	class PhantomCallbackData
	{
	public:
		enum CallbackEvent
		{
			ENTER_EVENT,
			LEAVE_EVENT
		};

		CallbackEvent mEvent;
		PhantomCallbackShape* mPhantomCallbackShape;
		hkpRigidBody* mCollidingRigidBody;
	};

	class PhantomCallback
	{
	public:
		ThreadSafeQueue<PhantomCallbackData> mPhantomCallbackQueue;

		virtual ~PhantomCallback() = 0;
	};
}
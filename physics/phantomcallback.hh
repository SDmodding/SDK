#pragma once

namespace UFG
{
	class PhantomCallbackShape : public hkpPhantomCallbackShape
	{
	public:
		PhysicsVolumeProperties* mVolumeProperties;
	};
}
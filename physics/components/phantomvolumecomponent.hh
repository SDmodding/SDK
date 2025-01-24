#pragma once

namespace UFG
{
	class PhantomVolumeComponent : public SimComponent, public qNode<PhantomVolumeComponent>
	{
	public:
		enum { _TypeUID = 0x7E000001 };

		qSafeArray<PhysicsVolumeProperties*, 5> mVolumeProperties;
		qSafeArray<PhantomCallbackShape*, 5> mPhantomCallbackShapes;
		i8 mActiveProperties;
		i8 mActiveVolumes;

		/* Functions */

		void OnEnterVolume(PhantomCallbackShape* phantom) { SDK_CALL_FUNC(void, 0x46E8D0, void*, PhantomCallbackShape*)(this, phantom); }
		void OnLeaveVolume(PhantomCallbackShape* phantom) { SDK_CALL_FUNC(void, 0x46ECD0, void*, PhantomCallbackShape*)(this, phantom); }
	};
	SDK_ASSERT_SIZEOF(PhantomVolumeComponent, 0xA8);
}
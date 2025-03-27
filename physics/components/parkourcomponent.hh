#pragma once

namespace UFG
{
	class ParkourComponent : public SimComponent, public qNode<ParkourComponent>
	{
	public:
		enum { _TypeUID = 0x7C000001 };

		qTypedResourceHandle<RTypeUID_ParkourContainer, ParkourContainer> mParkourContainer;
		qMatrix44 mCachedInverseTransform;
		BitArray* mDisabledBits;
		u32 mFlags;
		u32 mTransformChangeId;
		int mFollowBoneIndex;

		/* Functions */

		void BuildCachedInverseTransform() { SDK_CALL_FUNC(void, 0x459CB0, void*)(this); }
		void Disable(const ParkourData* data) { SDK_CALL_FUNC(void, 0x2FDBF0, void*, const ParkourData*)(this, data); }
		void GetTransform(qMatrix44& xform) { SDK_CALL_FUNC(void, 0x467F10, void*, qMatrix44&)(this, xform); }
	};
	SDK_ASSERT_SIZEOF(ParkourComponent, 0xC8);
}
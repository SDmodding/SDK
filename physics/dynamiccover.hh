#pragma once

namespace UFG
{
	class DynamicCoverData
	{
	public:
		enum BitFieldEnum
		{
			BF_LatchFlag,
			BF_InUse
		};

		enum CoverSideEnum
		{
			CS_Left,
			CS_Right
		};

		qVector3 m_vCornerPosition;
		qVector3 m_vWallNormal;
		u32 m_eCoverSide;
		f32 m_fWallHeight;
		u32 m_uBitField;
	};

	class DynamicCoverGroup : public qResourceData
	{
	public:
		u32 mCoverNodes;
		u32 mFlags;
		u32 mParentObjectPropertyGuid;
		DynamicCoverData* mData;
	};

	class DynamicCoverComponent : public SimComponent, public qNode<DynamicCoverComponent>
	{
	public:
		enum { _TypeUID = 0x76000001 };

		qTypedResourceHandle<RTypeUID_DynamicCoverGroup, DynamicCoverGroup> mDynamicCoverGroup;
		DynamicCoverCorner* m_aDynamicCoverCorners;
		u32 m_uNumCorners;
		u32 m_TransformNodeChangeID;
		bool mEnabled;

		/* Impl Functions */

		SDK_INLINE void DisableCoverCorners() { mEnabled = 0; }

		/* Functions */

		const qVector3& GetVelocity() { return SDK_CALL_FUNC(const qVector3&, 0x468190, void*)(this); }
		bool IsEnabled() { return SDK_CALL_FUNC(bool, 0x46AEC0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(DynamicCoverComponent, 0x88);
}
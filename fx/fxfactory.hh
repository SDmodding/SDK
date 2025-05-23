#pragma once

namespace Render
{
	enum eFXMemberRotateType
	{
		FXMEMBER_ROTATE_NONE,
		FXMEMBER_ROTATE_CONSTAN1,
		FXMEMBER_ROTATE_SINE
	};

	class FXSettingsMember
	{
	public:
		u32 typeId;
		u32 nameId;
		u32 guid;
		UFG::qVector3 offset;
		bool offsetWorld;
		s8 lodMask;
		s8 pad0;
		s8 pad1;
		f32 start;
		f32 end;
		eFXMemberRotateType rotateType;
		UFG::qVector3 rotateMin;
		UFG::qVector3 rotateMax;
		UFG::qVector3 rotateSpeed;
		UFG::qMatrix44 rotateOffset;
		f32 startTime;
		f32 endTime;
	};

	class FXSettings : public UFG::qResourceData
	{
	public:
		UFG::qVector3 mAABBMin;
		UFG::qVector3 mAABBMax;
		f32 mLength;
		f32 mTransformNodeExtraTime;
		u64 mAudioId;
		u32 mSlowMoFxId;
		f32 mAttachToCameraZDist;
		i8 mLoop;
		i8 mComponentCount;
		i8 mAttachToCamera;
		i8 mPad[13];

		SDK_INLINE FXSettingsMember* GetComponents() { return reinterpret_cast<FXSettingsMember*>(&this[1]); }
	};
	SDK_ASSERT_SIZEOF(FXSettings, 0x98);

	class FXSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_FXSettings, FXSettings> {};
}
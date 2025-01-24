#pragma once

namespace UFG
{
	class PhysicsVolumeProperties : public qReflectObjectType<PhysicsVolumeProperties>
	{
	public:
		qReflectString mName;
		qSymbolUC mFootStepEffect;
		qSymbolUC mFootStepDecal_Left;
		qSymbolUC mFootStepDecal_Right;
		f32 mFootStepDecalCountdown;
		f32 mDamagePerSecond;
		f32 mFireIgnitionTime;
		int mHitRecordType;
		bool mReserved;
	};
	SDK_ASSERT_SIZEOF(PhysicsVolumeProperties, 0x80);
}
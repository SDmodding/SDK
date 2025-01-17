#pragma once

class hkaPose
{
public:
	hkaSkeleton* m_skeleton;
	hkArray<hkQsTransformf> m_localPose;
	hkArray<hkQsTransformf> m_modelPose;
	hkArray<u32> m_boneFlags;
	hkBool m_modelInSync;
	hkBool m_localInSync;
	hkArray<f32> m_floatSlotValues;
};
SDK_ASSERT_SIZEOF(hkaPose, 0x50);
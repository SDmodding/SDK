#pragma once

class hkaPose
{
public:
	hkaSkeleton* m_skeleton;
	hkArray<hkQsTransformf, hkContainerHeapAllocator> m_localPose;
	hkArray<hkQsTransformf, hkContainerHeapAllocator> m_modelPose;
	hkArray<u32, hkContainerHeapAllocator> m_boneFlags;
	hkBool m_modelInSync;
	hkBool m_localInSync;
	hkArray<f32, hkContainerHeapAllocator> m_floatSlotValues;
};
SDK_ASSERT_SIZEOF(hkaPose, 0x50);
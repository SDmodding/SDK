#pragma once

class hkaSkeleton : public hkReferencedObject
{
public:
	struct LocalFrameOnBone
	{
		hkRefPtr<hkLocalFrame> m_localFrame;
		i16 m_boneIndex;
	};

	struct Partition
	{
		hkStringPtr m_name;
		i16 m_startBoneIndex;
		i16 m_numBones;
	};

	hkStringPtr m_name;
	hkArray<i16, hkContainerHeapAllocator> m_parentIndices;
	hkArray<hkaBone, hkContainerHeapAllocator> m_bones;
	hkArray<hkQsTransformf, hkContainerHeapAllocator> m_referencePose;
	hkArray<f32, hkContainerHeapAllocator> m_referenceFloats;
	hkArray<hkStringPtr, hkContainerHeapAllocator> m_floatSlots;
	hkArray<LocalFrameOnBone, hkContainerHeapAllocator> m_localFrames;
	hkArray<Partition, hkContainerHeapAllocator> m_partitions;
};
SDK_ASSERT_SIZEOF(hkaSkeleton, 0x88);
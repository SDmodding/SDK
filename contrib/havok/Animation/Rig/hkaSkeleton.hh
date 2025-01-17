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
	hkArray<i16> m_parentIndices;
	hkArray<hkaBone> m_bones;
	hkArray<hkQsTransformf> m_referencePose;
	hkArray<f32> m_referenceFloats;
	hkArray<hkStringPtr> m_floatSlots;
	hkArray<LocalFrameOnBone> m_localFrames;
	hkArray<Partition> m_partitions;
};
SDK_ASSERT_SIZEOF(hkaSkeleton, 0x88);
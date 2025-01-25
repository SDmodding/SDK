#pragma once

struct hkAabbUint32
{
	u32 m_min[3];
	u8 m_expansionMin[3];
	u8 m_expansionShift;
	u32 m_max[3];
	u8 m_expansionMax[3];
	u8 m_shapeKeyByte;
};

class hkLocalFrame : public hkReferencedObject
{
public:
};

class hkLocalFrameCollector : public hkReferencedObject
{
public:
};

class hkLocalFrameGroup : public hkReferencedObject
{
public:
	hkStringPtr m_name;
};

class hkSimpleLocalFrame : public hkLocalFrame
{
public:
	hkTransformf m_transform;
	hkArray<hkLocalFrame*> m_children;
	hkLocalFrame* m_parentFrame;
	hkLocalFrameGroup* m_group;
	hkStringPtr m_name;
};
#pragma once

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
	hkArray<hkLocalFrame*, hkContainerHeapAllocator> m_children;
	hkLocalFrame* m_parentFrame;
	hkLocalFrameGroup* m_group;
	hkStringPtr m_name;
};
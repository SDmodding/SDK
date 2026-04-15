#pragma once

class hkAabb
{
public:
	hkVector4f m_min;
	hkVector4f m_max;
};

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

class hkGeometry : public hkReferencedObject
{
public:
	struct Triangle
	{
		int m_a;
		int m_b;
		int m_c;
		int m_material = -1;
	};

	hkArray<hkVector4f> m_vertices;
	hkArray<Triangle> m_triangles;

	void ctor()
	{
		memset(this, 0, sizeof(*this));
		*reinterpret_cast<void**>(this) = SDK_VAR(void*, 0x16883A8);
	}
};

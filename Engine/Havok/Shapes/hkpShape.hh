#pragma once

class hkpShape : public hkReferencedObject
{
public:
	uint8_t m_type;
	uint8_t m_dispatchType;
	char m_bitsPerKey;
	uint8_t m_shapeInfoCodecType;
	uint64_t m_userData;
};

class hkpShapeContainer
{
public:
	void* vfptr;
};

class hkpSingleShapeContainer : public hkpShapeContainer
{
public:
	hkpShape* m_childShape;
};

class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
public:
	bool m_disableWelding;
	uint8_t m_collectionType;
};
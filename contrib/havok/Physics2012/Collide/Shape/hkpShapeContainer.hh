#pragma once

class hkpShape;
class hkpShapeBuffer;

class hkpShapeContainer
{
public:
	virtual ~hkpShapeContainer() = 0;
	virtual int getNumChildShapes() = 0;
	virtual hkpShapeKey getFirstKey() = 0;
	virtual hkpShapeKey getNextKey(hkpShapeKey oldKey) = 0;
	virtual u32 getCollisionFilterInfo(hkpShapeKey key) = 0;
	virtual const hkpShape* getChildShape(hkpShapeKey key, hkpShapeBuffer& buffer) = 0;
	virtual bool isWeldingEnabled() = 0;
};

class hkpSingleShapeContainer : public hkpShapeContainer
{
public:
	hkpShape* m_childShape;
};

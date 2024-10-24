#pragma once

struct hkcdShapeType
{
	enum ShapeTypeEnum : s32
	{
		SPHERE,
		FIRST_SHAPE_TYPE,
		CYLINDER,
		TRIANGLE,
		BOX,
		CAPSULE,
		CONVEX_VERTICES,
		TRI_SAMPLED_HEIGHT_FIELD_COLLECTION,
		TRI_SAMPLED_HEIGHT_FIELD_BV_TREE,
		LIST,
		MOPP,
		CONVEX_TRANSLATE,
		CONVEX_TRANSFORM,
		SAMPLED_HEIGHT_FIELD,
		EXTENDED_MESH,
		TRANSFORM,
		COMPRESSED_MESH,
		STATIC_COMPOUND,
		BV_COMPRESSED_MESH,
		COLLECTION,
		USER0,
		USER1,
		USER2,
		BV_TREE,
		MAX_SPU_SHAPE_TYPE,
		CONVEX,
		CONVEX_PIECE,
		MULTI_SPHERE,
		CONVEX_LIST,
		TRIANGLE_COLLECTION,
		HEIGHT_FIELD,
		SPHERE_REP,
		BV,
		PLANE,
		PHANTOM_CALLBACK,
		MULTI_RAY,
		INVALID,
		MAX_PPU_SHAPE_TYPE,
		ALL_SHAPE_TYPES
	};
};

struct hkcdShapeDispatchType
{
	enum ShapeDispatchTypeEnum
	{
		CONVEX_IMPLICIT,
		CONVEX,
		HEIGHT_FIELD,
		COMPOSITE,
		USER,
		NUM_DISPATCH_TYPES
	};
};

struct hkcdShapeInfoCodecType
{
	enum ShapeInfoCodecTypeEnum
	{
		NULL_CODEC = 0,
		UFM358 = 1,
		MAX_NUM_CODECS = 16
	};
};

class hkcdShape : public hkReferencedObject
{
public:
	hkEnum<hkcdShapeType::ShapeTypeEnum, u8> m_type;
	hkEnum<hkcdShapeDispatchType::ShapeDispatchTypeEnum, u8> m_dispatchType;
	s8 m_bitsPerKey;
	hkEnum<hkcdShapeInfoCodecType::ShapeInfoCodecTypeEnum, u8> m_shapeInfoCodecType;
};
SDK_ASSERT_SIZEOF(hkcdShape, 0x18);
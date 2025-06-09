#pragma once

namespace Illusion
{
	enum VertexStreamElementUsage : int
	{
		VERTEX_ELEMENT_FORCE_DWORD = -1,
		VERTEX_ELEMENT_POSITION = 0,
		VERTEX_ELEMENT_NORMAL,
		VERTEX_ELEMENT_TANGENT,
		VERTEX_ELEMENT_COLOR0,
		VERTEX_ELEMENT_COLOR1,
		VERTEX_ELEMENT_TEXCOORD0,
		VERTEX_ELEMENT_TEXCOORD1,
		VERTEX_ELEMENT_TEXCOORD2,
		VERTEX_ELEMENT_TEXCOORD3,
		VERTEX_ELEMENT_TEXCOORD4,
		VERTEX_ELEMENT_TEXCOORD5,
		VERTEX_ELEMENT_TEXCOORD6,
		VERTEX_ELEMENT_TEXCOORD7,
		VERTEX_ELEMENT_BLENDINDEX,
		VERTEX_ELEMENT_BLENDWEIGHT,
		VERTEX_ELEMENT_BINORMAL,
		NUM_VERTEX_ELEMENTS
	};

	enum VertexSteamElementType : int
	{
		VERTEX_TYPE_FORCE_DWORD = -1,
		VERTEX_TYPE_FLOAT3 = 0,
		VERTEX_TYPE_FLOAT4,
		VERTEX_TYPE_HALF2,
		VERTEX_TYPE_UBYTE4,
		VERTEX_TYPE_COLOR4,
		VERTEX_TYPE_UBYTE4N,
		VERTEX_TYPE_11_11_10N,
		VERTEX_TYPE_HALF4,
		VERTEX_TYPE_HALF3,
		VERTEX_TYPE_SINT16_2,
		VERTEX_TYPE_SHORT4,
		VERTEX_TYPE_SHORT4N,
		VERTEX_TYPE_SHORT4_FIXED4_12,
		VERTEX_TYPE_SHORT4_FIXED8_8,
		VERTEX_TYPE_UINT1,
		VERTEX_TYPE_UBYTE4_DELTA,
		VERTEX_TYPE_BYTE4N,
		NUM_VERTEX_TYPES
	};

	class VertexStreamElement
	{
	public:
		VertexStreamElementUsage mUsage;
		VertexSteamElementType mType;
		s16 mStream;
		int mOffset;
		int mSize;
		UFG::qVector4 mDefault;
	};

	class VertexStreamDescriptor : public UFG::qNode<VertexStreamDescriptor>
	{
	public:
		const char* mName;
		u32 mNameUID;
		VertexStreamElement mElements[NUM_VERTEX_ELEMENTS];
		int mStreamNumElements[4];
		int mStreamSizes[4];
		u32 mStreamRuntimeFlags;
		int mIndexStreamMultiplier;
		bool mIndexStreamAsVertexStream;
		int mTotalElements;
		int mTotalSize;

		virtual void ApplyUserRemapping(UFG::qVector4*) = 0;
	};
}
#pragma once

namespace Illusion
{
	class IPrimitivePlat {};

	class Primitive : IPrimitivePlat
	{
	public:
		enum Type : s32
		{
			POINTLIST,
			LINESTRIP,
			LINELIST,
			TRIANGLELIST,
			TRIANGLESTRIP,
			TRIANGLEFAN,
			QUADLIST,
			_1_CONTROL_POINT_PATCHLIST,
			_2_CONTROL_POINT_PATCHLIST,
			_3_CONTROL_POINT_PATCHLIST,
			_4_CONTROL_POINT_PATCHLIST,
			_5_CONTROL_POINT_PATCHLIST,
			_6_CONTROL_POINT_PATCHLIST,
			_7_CONTROL_POINT_PATCHLIST,
			_8_CONTROL_POINT_PATCHLIST,
			_9_CONTROL_POINT_PATCHLIST,
			_10_CONTROL_POINT_PATCHLIST,
			_11_CONTROL_POINT_PATCHLIST,
			_12_CONTROL_POINT_PATCHLIST,
			_13_CONTROL_POINT_PATCHLIST,
			_14_CONTROL_POINT_PATCHLIST,
			_15_CONTROL_POINT_PATCHLIST,
			_16_CONTROL_POINT_PATCHLIST,
			_17_CONTROL_POINT_PATCHLIST,
			_18_CONTROL_POINT_PATCHLIST,
			_19_CONTROL_POINT_PATCHLIST,
			_20_CONTROL_POINT_PATCHLIST,
			_21_CONTROL_POINT_PATCHLIST,
			_22_CONTROL_POINT_PATCHLIST,
			_23_CONTROL_POINT_PATCHLIST,
			_24_CONTROL_POINT_PATCHLIST,
			_25_CONTROL_POINT_PATCHLIST,
			_26_CONTROL_POINT_PATCHLIST,
			_27_CONTROL_POINT_PATCHLIST,
			_28_CONTROL_POINT_PATCHLIST,
			_29_CONTROL_POINT_PATCHLIST,
			_30_CONTROL_POINT_PATCHLIST,
			_31_CONTROL_POINT_PATCHLIST,
			_32_CONTROL_POINT_PATCHLIST,
			NUM_PRIM_TYPES
		};

		const void* mVertexStream;
		VertexDecl* mVertexDecl;
		const void* mIndexStream;
		u16 mNumPrims;
		u16 mNumVerts;
		u16 mPrimType;
		u16 mIndexSize;
		u16 mNumIndices;
		const char* mDescription;

		/* Static Functions */

		SDK_SINLINE Primitive* Create(const char* description = 0) { return SDK_CALL_FUNC(Primitive*, 0xA18A20, const char*)(description); }

		/* Functions */

		bool SetBuffers(Type prim_type, const void* vertices, int num_vertices, VertexDecl* decl, const void* indices, int num_indices, bool dupe_vertex_buffer) { 
			return SDK_CALL_FUNC(bool, 0x956E0, void*, Type, const void*, int, VertexDecl*, const void*, int, bool)(this, prim_type, vertices, num_vertices, decl, indices, num_indices, dupe_vertex_buffer); 
		}
	};

}
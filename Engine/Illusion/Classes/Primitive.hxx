#pragma once

namespace Illusion
{
	class CPrimitivePlat
	{
	public:
		ID3D11Buffer* mVertexBuffer;
		int mVertexBufferOffset;
		ID3D11Buffer* mIndexBuffer;
		int mIndexBufferOffset;
		int mIndexCount;
	};

	class CPrimitive : public CPrimitivePlat
	{
	public:
		enum eType
		{
			POINTLIST = 0x0,
			LINESTRIP = 0x1,
			LINELIST = 0x2,
			TRIANGLELIST = 0x3,
			TRIANGLESTRIP = 0x4,
			TRIANGLEFAN = 0x5,
			QUADLIST = 0x6,
			_1_CONTROL_POINT_PATCHLIST = 0x7,
			_2_CONTROL_POINT_PATCHLIST = 0x8,
			_3_CONTROL_POINT_PATCHLIST = 0x9,
			_4_CONTROL_POINT_PATCHLIST = 0xA,
			_5_CONTROL_POINT_PATCHLIST = 0xB,
			_6_CONTROL_POINT_PATCHLIST = 0xC,
			_7_CONTROL_POINT_PATCHLIST = 0xD,
			_8_CONTROL_POINT_PATCHLIST = 0xE,
			_9_CONTROL_POINT_PATCHLIST = 0xF,
			_10_CONTROL_POINT_PATCHLIST = 0x10,
			_11_CONTROL_POINT_PATCHLIST = 0x11,
			_12_CONTROL_POINT_PATCHLIST = 0x12,
			_13_CONTROL_POINT_PATCHLIST = 0x13,
			_14_CONTROL_POINT_PATCHLIST = 0x14,
			_15_CONTROL_POINT_PATCHLIST = 0x15,
			_16_CONTROL_POINT_PATCHLIST = 0x16,
			_17_CONTROL_POINT_PATCHLIST = 0x17,
			_18_CONTROL_POINT_PATCHLIST = 0x18,
			_19_CONTROL_POINT_PATCHLIST = 0x19,
			_20_CONTROL_POINT_PATCHLIST = 0x1A,
			_21_CONTROL_POINT_PATCHLIST = 0x1B,
			_22_CONTROL_POINT_PATCHLIST = 0x1C,
			_23_CONTROL_POINT_PATCHLIST = 0x1D,
			_24_CONTROL_POINT_PATCHLIST = 0x1E,
			_25_CONTROL_POINT_PATCHLIST = 0x1F,
			_26_CONTROL_POINT_PATCHLIST = 0x20,
			_27_CONTROL_POINT_PATCHLIST = 0x21,
			_28_CONTROL_POINT_PATCHLIST = 0x22,
			_29_CONTROL_POINT_PATCHLIST = 0x23,
			_30_CONTROL_POINT_PATCHLIST = 0x24,
			_31_CONTROL_POINT_PATCHLIST = 0x25,
			_32_CONTROL_POINT_PATCHLIST = 0x26,
			NUM_PRIM_TYPES = 0x27,
		};

		void* mVertexStream;
		CVertexDecl* mVertexDecl;
		void* mIndexStream;
		uint16_t mNumPrims;
		uint16_t mNumVerts;
		uint16_t mPrimType;
		uint16_t mIndexSize;
		uint16_t mNumIndices;
		const char* mDescription;

		__inline void SetBuffers(eType p_Type, void* p_VertexStream, int p_NumVerts, CVertexDecl* p_VertexDecl, void* p_IndexStream = nullptr, int p_NumIndices = 0, bool p_DupeVertexBuffer = true)
		{
			reinterpret_cast<void(__fastcall*)(void*, eType, void*, int, CVertexDecl*, void*, int, bool)>(UFG_RVA(0x956E0))(this, p_Type, p_VertexStream, p_NumVerts, p_VertexDecl, p_IndexStream, p_NumIndices, p_DupeVertexBuffer);
		}
	};

	namespace Primitive
	{
		__inline CPrimitive* Create(const char* p_Description = nullptr)
		{
			return reinterpret_cast<CPrimitive*(__fastcall*)(const char*)>(UFG_RVA(0xA18A20))(p_Description);
		}

		__inline CPrimitive* Create(const char* p_Description, CPrimitive::eType p_Type, void* p_VertexStream, int p_NumVerts, CVertexDecl* p_VertexDecl, void* p_IndexStream = nullptr, int p_NumIndices = 0, bool p_DupeVertexBuffer = true)
		{
			CPrimitive* Primitive = Create(p_Description);
			Primitive->SetBuffers(p_Type, p_VertexStream, p_NumVerts, p_VertexDecl, p_IndexStream, p_NumIndices, p_DupeVertexBuffer);
			return Primitive;
		}
	}
}
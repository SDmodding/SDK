#pragma once

namespace Render
{
	class OcclusionMap
	{
	public:
		enum Result
		{
			RESULT_NOT_VISIBLE,
			RESULT_VISIBLE
		};

		void* mOBuffer0;
		void* mOBuffer1;
		UFG::qMatrix44* mWorldViewProjection;
		int mNumPixelsTested;

		/* Functions */

		void Init(void* obuffer) { SDK_CALL_FUNC(void, 0x25360, void*, void*)(this, obuffer); }
		void BeginFrame(const UFG::qMatrix44* world_view_projection) { SDK_CALL_FUNC(void, 0x24C20, void*, const UFG::qMatrix44*)(this, world_view_projection); }
		void CreateFromZBuffer(void* zbuffer) { SDK_CALL_FUNC(void, 0x24D50, void*, void*)(this, zbuffer); }
		Result TestRect(u32 minx, u32 miny, u32 maxx, u32 maxy, u32 minw) { return SDK_CALL_FUNC(Result, 0x25400, void*, u32, u32, u32, u32, u32)(this, minx, miny, maxx, maxy, minw); }
	};

	class RasterizeZ
	{
	public:
		enum InitFlags
		{
			FLAG_DONT_CLEAR,
			FLAG_CLEAR
		};

		enum BufferSize
		{
			BUFFER_1x1_SIZE = 0x10000,
			BUFFER_TAG_SIZE = 0x80,
			BUFFER_SIZE = 0x10080
		};

		void* mZBuffer;
		u32* mZBufferTag;
		UFG::qMatrix44* mWorldViewProjection;
		int mNumPolys_Total;
		int mNumPolys_Drawn;
		int mNumPolys_BackFace;
		int mNumBlocks32;
		int mNumBlocks8;
		int mNumBlocks4;
		int mNumBlocks4_ZRejected;

		/* Functions */

		void Init(void* zbuffer, u32 flags) { SDK_CALL_FUNC(void, 0x25370, void*, void*, u32)(this, zbuffer, flags); }
		void Clear() { SDK_CALL_FUNC(void, 0x24C30, void*)(this); }
		void Composite(void* zbuffer) { SDK_CALL_FUNC(void, 0x24C80, void*, void*)(this, zbuffer); }

		void Draw2DH(const UFG::qVector4& v0, const UFG::qVector4& v1, const UFG::qVector4& v2) {
			SDK_CALL_FUNC(void, 0x6A2D40, void*, const UFG::qVector4&, const UFG::qVector4&, const UFG::qVector4&)(this, v0, v1, v2);
		}

		void DrawAABB(const UFG::qVector3& vmin, const UFG::qVector3& vmax, const UFG::qMatrix44& local_world) {
			SDK_CALL_FUNC(void, 0x6A45C0, void*, const UFG::qVector3&, const UFG::qVector3&, const UFG::qMatrix44&)(this, vmin, vmax, local_world);
		}
	};
}
#pragma once

namespace Render
{
	class SkinClipInfo
	{
	public:
		struct ClipOutputVertex
		{
			i8 s0_data[24];
			i8 s1_data[8];
			i8 morph_data[8];
			UFG::qHalfFloat uv[2];
		};

		struct ClipResult
		{
			ClipOutputVertex mVerts[32];
			bool mResultReady;
			u32 mResultVertNum;
		};

		ClipResult* mResults[8];
		UFG::qMatrix44 mDecalWorld;
		UFG::qMatrix44 mModelLocalWorld;
		UFG::qVector4 mModelAABBMin;
		UFG::qVector4 mModelAABBMax;
		f32 mDecalCutoff;
		f32 mDecalDepth;
		f32 mRadius;
		bool mQueryReady;
		bool mQueryInProcess;
		u32 mMaxResults;
	};
}
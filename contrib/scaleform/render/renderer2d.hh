#pragma once

namespace Scaleform::Render
{
	// TODO: Implement commented code.
	class Renderer2DImpl : public ContextImpl::RenderNotify, public HALNotify, Scaleform::NewOverrideBase<StatRender_Mem>
	{
	public:
		Ptr<HAL> pHal;
		//MeshGenerator MeshGen;
		//StrokeGenerator StrokeGen;
		ToleranceParams Tolerances;
		//PrimitiveFillManager FillManager;
		//MatrixPoolImpl::MatrixPool MPool;
		//Ptr<MeshKeyManager> pMeshKeyManager;
		Ptr<GlyphCache> pGlyphCache;
		GlyphCacheParams mGlyphCacheParam;
		//List<ComplexMesh::UpdateNode> mComplexMeshUpdateList;
		Viewport VP;
		//List<TreeCacheNode> RenderRoots;
	};

	class Renderer2D : public RefCountBase<Renderer2D, StatRender_Mem>
	{
	public:
		Renderer2DImpl* pImpl;
	};
}
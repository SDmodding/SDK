#pragma once

class hkaiStaticTreeNavMeshQueryMediator : public hkaiNavMeshQueryMediator
{
public:
	hkRefPtr<hkcdStaticAabbTree> m_tree;
	hkRefPtr<hkaiNavMesh> m_navMesh;

	SDK_INLINE void ctor() { SDK_CALL_FUNC(void, 0xBD59F0, void*)(this); }

	SDK_INLINE void setNavMesh(hkaiNavMesh* mesh) { SDK_CALL_FUNC(void, 0xBD5AA0, void*, hkaiNavMesh*)(this, mesh); }
	SDK_INLINE void setNavMeshAndTree(hkaiNavMesh* navMesh, hkcdStaticAabbTree* staticTree) { SDK_CALL_FUNC(void, 0xBD5BE0, void*, hkaiNavMesh*, hkcdStaticAabbTree*)(this, navMesh, staticTree); }
};
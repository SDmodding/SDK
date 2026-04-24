#pragma once

namespace UFG
{
	class PhysicsRenderHelper : public SimComponent, public qNode<PhysicsRenderHelper, PhysicsRenderHelper>
	{
	public:
		enum { _TypeUID = 0x80000001 };

		u16 mNumSceneryInstances;
		DynamicSceneryInstance** mSceneryInstances;
		u32 mFlags;

		/* Functions */

		void DisableDynamicScenery(u32 dynmaicSceneryInstanceGuid) { SDK_CALL_FUNC(void, 0x461D40, void*, u32)(this, dynmaicSceneryInstanceGuid); }
		void DisableSelfIllumination() { SDK_CALL_FUNC(void, 0x461DF0, void*)(this); }
		bool HasFadedOut() { return SDK_CALL_FUNC(bool, 0x468A00, void*)(this); }
		void SetToFadeOut() { SDK_CALL_FUNC(void, 0x475670, void*)(this); }
		void SwapRenderModel(u32 renderModelUID) { SDK_CALL_FUNC(void, 0x4766E0, void*, u32)(this, renderModelUID); }
		void UpdateTransforms(const CollisionMeshData* mesh, const hkTransformf& transform) { SDK_CALL_FUNC(void, 0x4802C0, void*, const CollisionMeshData*, const hkTransformf&)(this, mesh, transform); }
	};
	SDK_ASSERT_SIZEOF(PhysicsRenderHelper, 0x68);
}
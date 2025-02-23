#pragma once

namespace UFG
{
	class FacialActionTreeComponent : public SimComponent, public ActionTreeComponentBase, public qNode<FacialActionTreeComponent>, public qNode<FacialActionTreeComponent, class FacialActionTreeComponent_UpdateList>
	{
	public:
		enum { _TypeUID = 0xB8000001 };

		const char* mActionTreeFileName;
		ActionContext* mActionContext;
		ActionController mActionController;
		bool mDisable : 1;
		bool mLowLODMode : 1;
		bool mDebugDisplay : 1;
		bool mDebugRemote : 1;
		bool mDebugDisplayActionRequests : 1;

		/* Static Members */

		SDK_VINLINE qGlobalVar<bool, 0x240DF39> sDisableFacialAnimation;
		SDK_VINLINE qGlobalVar<bool, 0x240DF3A> sDisableFacialAnimationUpdate;

		/* Functions */

		void Disable() { SDK_CALL_FUNC(void, 0x526000, void*)(this); }
		void Enable() { SDK_CALL_FUNC(void, 0x526780, void*)(this); }
		void InitActionTree() { SDK_CALL_FUNC(void, 0x5362E0, void*)(this); }
		void SyncUpdateList() { SDK_CALL_FUNC(void, 0x553180, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(FacialActionTreeComponent, 0x1E8);
}
#pragma once

namespace UFG
{
	class DoorComponent : public SimComponent, public qNode<DoorComponent>
	{
	public:
		enum { _TypeUID = 0x88000001 };

		ActionNode* mDoorOpeningLeftNode;
		ActionNode* mDoorOpeningRightNode;
		ActionNode* mDoorClosingNode;
		ActionNode* mDoorLockedNode;
		ActionNode* mDoorUnlockedNode;
		bool mOpen;
		bool mIsAutoClosed;
		bool mAutoCloseInit;
		qVector3 mAutoCloseCenter;
		f32 mAutoCloseTimer;

		/* Static Members */

		SDK_VINLINE qGlobalVar<qList<DoorComponent>*, 0x2083528> s_DoorComponentList;

		/* Impl Functions */

		SDK_INLINE bool IsOpen() { return mOpen; }

		/* Functions */

		void PropertiesLoad(SceneObjectProperties* pSceneObj) { SDK_CALL_FUNC(void, 0x489C90, void*, SceneObjectProperties*)(this, pSceneObj); }
		void SetOpen(bool open) { SDK_CALL_FUNC(void, 0x489FA0, void*, bool)(this, open); }
		void Update(f32 delta_sec) { SDK_CALL_FUNC(void, 0x48A020, void*, f32)(this, delta_sec); }
		void UpdateLockedState() { SDK_CALL_FUNC(void, 0x48A3E0, void*)(this); }
		void UpdateOpenedState() { SDK_CALL_FUNC(void, 0x48A5C0, void*)(this); }

	};
	SDK_ASSERT_SIZEOF(DoorComponent, 0x90);
}
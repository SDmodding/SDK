#pragma once

namespace UFG
{
	class CharacterControllerInterface : public SimComponent, public qNode<CharacterControllerInterface>
	{
	public:
		enum { _TypeUID = 0x44000001 };

		RebindingComponentHandle<ActionTreeComponent> m_pActionTreeComponent;

		/* Virtual Functions */

		virtual void BeginFrame() = 0;

		/* Functions */

		bool PlayActionNode(const char* node_name) { return SDK_CALL_FUNC(bool, 0x5425C0, void*, const char*)(this, node_name); }
		void SetIntentionOnActionTreeComponent(Intention& intention) { SDK_CALL_FUNC(void, 0x54D910, void*, Intention&)(this, intention); }
	};
}
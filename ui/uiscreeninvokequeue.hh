#pragma once

namespace UFG
{
	class UIScreenInvoke : public qNode<UIScreenInvoke>
	{
	public:
		qString command;

		/* Virtual Functions */

		virtual ~UIScreenInvoke() = 0;
		virtual void Invoke(Scaleform::GFx::Movie* movie) = 0;
	};

	class UIScreenInvokeQueue
	{
	public:
		int mNumCommandsPerFrame;
		qList<UIScreenInvoke> mCommandQueue;

		/* Virtual Functions */

		virtual ~UIScreenInvokeQueue() = 0;

		/* Functions */

		void Add(UIScreenInvoke* cmd) { SDK_CALL_FUNC(void, 0xA24760, void*, UIScreenInvoke*)(this, cmd); }
		void Update(UIScreen* screen) { SDK_CALL_FUNC(void, 0xA28880, void*, UIScreen*)(this, screen); }
	};
}
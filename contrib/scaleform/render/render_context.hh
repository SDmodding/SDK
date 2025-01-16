#pragma once

namespace Scaleform::Render::ContextImpl
{
	class RenderNotify
	{
	public:
		class Context;

		struct ContextNode : public ListNode<ContextNode>
		{
			Context* pContext;
		};

		struct ServiceCommand : public ThreadCommand
		{
			RenderNotify* pNotify;
		};

		List<ContextNode> ActiveContextSet;
		ThreadCommandQueue* pRTCommandQueue;
		ServiceCommand ServiceCommandInstance;

		virtual ~RenderNotify() = 0;
	};
}
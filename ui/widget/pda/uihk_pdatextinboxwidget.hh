#pragma once

namespace UFG
{
	class UIHK_PDATextInboxWidget
	{
	public:
		enum eState
		{
			STATE_IDLE,
			STATE_SHOULD_ACTIVATE,
			STATE_ACTIVE,
			STATE_SHOULD_DEACTIVATE
		};

		eState mState;
	};
}
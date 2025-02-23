#pragma once

namespace UFG
{
	class DialogArgList
	{
	public:
		u32 m_args[6];
		u32 m_nArgs;
		u32 m_uDialogEventId;

		virtual ~DialogArgList() = 0;
	};
}
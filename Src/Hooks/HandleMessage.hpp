#pragma once

#include "../Callbacks/OnDialogBox.hpp"

namespace Hook
{
	namespace HandleMessage
	{
		typedef void(__fastcall* m_tScreenDialogBox)(UFG::CScreenDialogBox*, unsigned int, UFG::CUIMessage*);
		m_tScreenDialogBox m_oScreenDialogBox;

		void __fastcall ScreenDialogBox(UFG::CScreenDialogBox* rcx, unsigned int msgId, UFG::CUIMessage* msg)
		{
			if (rcx->mState == 2 && msgId == UIHASH_SELECT)
			{
				unsigned int m_OptionHash = 0;

				switch (atol(msg->m_messageResult)) // so retarded
				{
					case 1: m_OptionHash = rcx->mData.mOption1Msg; break;
					case 2: m_OptionHash = rcx->mData.mOption2Msg; break;
					case 3: m_OptionHash = rcx->mData.mOption3Msg; break;
				}

				m_OptionHash = (m_OptionHash - UFG_DIALOGBOX_OPTION_HASH);
				if (m_OptionHash >= 0 && 3 >= m_OptionHash)
					Callback::OnDialogBox(static_cast<int>(m_OptionHash + 1));
				else
					Callback::OnDialogBox(0);
			}

			m_oScreenDialogBox(rcx, msgId, msg);
		}
	}
}
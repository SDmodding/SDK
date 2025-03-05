#pragma once

namespace UFG
{
	class UIHKSecondaryObjective
	{
	public:
		enum eWidgetState
		{
			STATE_IDLE,
			STATE_ACTIVE,
			STATE_POPUP,
			STATE_OUTRO
		};

		qString Caption;
		SecondaryObjective::eStatus Status;
		bool CaptionChanged;
		bool StatusChanged;
		u32 Progress;
		u32 MaxProgress;
		f32 HideTimer;
		eWidgetState WidgetState;

		/* Functions */

		void Populate(SecondaryObjective* objective) { SDK_CALL_FUNC(void, 0x5F4A00, void*, SecondaryObjective*)(this, objective); }
	};

	class UIHKSecondaryObjectivesWidget
	{
	public:
		bool mChanged;
		UIHKSecondaryObjective mCopObjective;
		UIHKSecondaryObjective mTriadObjective;

		/* Functions */

		void Flash_HideObjective(UIScreen* pScreen, bool isCop) { SDK_CALL_FUNC(void, 0x5DBDA0, void*, UIScreen*, bool)(this, pScreen, isCop); }
	};
}
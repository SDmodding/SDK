#pragma once

namespace Illusion
{
	enum RenderThreadCommand
	{
		RTCMD_FORCE_OS_FLIP = 0x0,
		RTCMD_SET_VSYNC_MODE = 0x1,
		RTCMD_SUBMIT = 0x2,
		RTCMD_END_OF_FRAME = 0x3,
		RTCMD_CALLBACK = 0x4,
		RTCMD_CALLBACK_2 = 0x5,
		RTCMD_WAIT_FOR_END_LABEL = 0x6,
		RTCMD_WAIT_FOR_GPU = 0x7,
		RTCMD_ADD_GPU_CALLBACK = 0x8,
		RTCMD_EXECUTE_DEFERRED_COMMANDS = 0x9,
		RTCMD_USER_EVENT = 0xA,
		NUM_RENDER_THREAD_COMMANDS = 0xB,
	};

	class CRenderThreadManager
	{
	public:
		struct Command_t
		{
			Command_t* mPrev;
			Command_t* mNext;
			RenderThreadCommand mCommand;
			void* mParam;
			void* mData0;
			void* mData1;
		};

		UFG::qMutex mCommandsMutex;
		UFG::qList<Command_t> mCommands;
		uint32_t mNumCommandsAdded;
		uint32_t mNumCommandsCompleted;
		uint32_t mEventWaitTimeoutMicroSeconds;
		bool mSubFlipEnabled;

		static CRenderThreadManager* Instance()
		{
			return reinterpret_cast<CRenderThreadManager*>(UFG_RVA(0x2452740));
		}

		const char* GetCommandName()
		{
			return reinterpret_cast<const char*>(UFG_RVA(0x1A183C8));
		}
	};
}
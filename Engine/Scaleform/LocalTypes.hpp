#pragma once

namespace Scaleform
{
	// Classes/Structs
	struct HashSetBase
	{
		uint64_t EntryCount;
		uint64_t SizeMask;
	};

	struct String
	{
		struct DataDesc
		{
			uint64_t Size;
			volatile int RefCount;
			char Data[1];
		};
		DataDesc* pData;
	};

	namespace GFx
	{
		class State
		{
		public:
			enum StateType 
			{
				State_None,
				State_Translator,
				State_Log,
				State_ActionControl,
				State_UserEventHandler,
				State_FSCommandHandler,
				State_ExternalInterface,
				State_MultitouchInterface,
				State_VirtualKeyboardInterface,
				State_FileOpener,
				State_URLBuilder,
				State_ImageCreator,
				State_ImageFileHandlerRegistry,
				State_ParseControl,
				State_ProgressHandler,
				State_ImportVisitor,
				State_FontPackParams,
				State_FontLib,
				State_DefaultFontLibName,
				State_FontProvider,
				State_FontMap,
				State_TaskManager,
				State_Clipboard,
				State_TextKeyMap,
				State_IMEManager,
				State_XMLSupport,
				State_ZlibSupport,
				State_FontCompactorParams,
				State_ImagePackerParams,
				State_Audio,
				State_Video,
				State_TestStream,
				State_SharedObject,
				State_SharedObject3,
				State_UrlNavigator,
				State_LocSupport,
				State_AS2Support,
				State_AS3Support
			};

			void* vfptr;
			volatile int RefCount;
			StateType SType;

			UFG_PAD_ALIGN(0x4);
		};

		class StateBag
		{
		public:
			void* vfptr;
		};

		class LogBase
		{
		public:
			void* vfptr;
		};

		class LogState : public State, public LogBase
		{
		public:
			void* pLog;
			//Scaleform::Ptr<Scaleform::Log> pLog;
		};
	}

	// Typedefs
	typedef String StringLH;
	typedef _RTL_CRITICAL_SECTION Lock;
}
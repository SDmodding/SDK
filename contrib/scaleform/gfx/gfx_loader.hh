#pragma once

namespace Scaleform::GFx
{
	struct MovieInfo
	{
		enum SWFFlagConstants
		{
			SWF_Compressed = 0x1,
			SWF_Stripped = 0x10
		};

		u32 Version;
		u32 Flags;
		int Width;
		int Height;
		f32 FPS;
		u32 FrameCount;
		u32 TagCount;
		u16 ExporterVersion;
		u32 ExporterFlags;
	};

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
	};

	class StateBag //: public FileTypeConstants
	{
	public:
		virtual StateBag* GetStateBagImpl() = 0;
		virtual ~StateBag() = 0;
		virtual void SetState(State::StateType state, State* pstate) = 0;
		virtual State* GetStateAddRef(State::StateType state) = 0;
		virtual void GetStatesAddRef(State** ppstatelist, State::StateType* pstates, u32 count) = 0;
	};

	class StateBagImpl : public RefCountBase<StateBagImpl, Stat_Default_Mem>, public StateBag, public LogBase<StateBagImpl>
	{
	public:
		struct StatePtr
		{
			Ptr<State> pState;
		};

		Ptr<StateBagImpl> pDelegate;
		HashSet<StatePtr> States;
		Lock StateLock;
	};


	class LoaderImpl : public RefCountBase<LoaderImpl, Stat_Default_Mem>, public StateBag, public LogBase<LoaderImpl>
	{
	public:
		class HttpFileCache;

		Ptr<StateBagImpl> pStateBag;
		Ptr<ResourceWeakLib> pWeakResourceLib;
		List<class LoadProcessNode> LoadProcesses;
		Lock LoadProcessesLock;
		bool DebugHeap;
		StringHashLH<Ptr<HttpFileCache>> HttpFilesOpened;
	};

	class Loader : public StateBag
	{
	public:
		LoaderImpl* pImpl;
		ResourceLib* pStrongResourceLib;
		u32 DefLoadFlags;
	};
}
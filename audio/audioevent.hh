#pragma once

namespace UFG
{
	enum eAudioEventCallbackType
	{
		eAudioEventCallbackType_Play,
		eAudioEventCallbackType_DetachEntity,
		eAudioEventCallbackType_End,
		eAudioEventCallbackType_Marker
	};

	class AudioEventController
	{
	public:
		AudioEvent* m_pEvent;
	};

	class AudioDialogEventController : public AudioEventController
	{
	public:
	};

	class AudioEventCallbackObject
	{
	public:
		AudioEventCallbackObject* m_next;

		virtual ~AudioEventCallbackObject() = 0;
		virtual void Do(AudioEvent*, eAudioEventCallbackType) = 0;
	};

	class AudioEventInitParams
	{
	public:
		void(__fastcall* m_EventPlayEndCallback)(AudioEntity*, eAudioEventCallbackType, AudioEvent*, void*);
		u8 gap8[16];
		void* m_EventCallbackUserData;
	};

	class ExternalSourceInfoNode
	{
	public:
		u32 m_externalSourceCookie;
		u32 m_codecID;
		u32 m_fileId;
	};

	class AudioEventExternalSourceInfo
	{
	public:
		u32 m_numExternals;
		qArray<ExternalSourceInfoNode> m_externals;

		virtual ~AudioEventExternalSourceInfo() = 0;
	};
}
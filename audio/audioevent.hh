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
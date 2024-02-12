#pragma once

enum AkCallbackType
{
	AK_EndOfEvent					= 0x0001,	///< Callback triggered when reaching the end of an event.
	AK_EndOfDynamicSequenceItem		= 0x0002,	///< Callback triggered when reaching the end of a dynamic sequence item.
	AK_Marker						= 0x0004,	///< Callback triggered when encountering a marker during playback.
	AK_Duration						= 0x0008,	///< Callback triggered when the duration of the sound is known by the sound engine.

	AK_SpeakerVolumeMatrix			= 0x0010,   ///< Callback triggered at each frame, letting the client modify the speaker volume matrix

	AK_MusicPlayStarted				= 0x0080,	///< Callback triggered when a "Play" or "Seek" command has been executed ("Seek" commands are issued from AK::SoundEngine::SeekOnEvent()). Applies to objects of the Interactive-Music Hierarchy only.
	
	AK_MusicSyncBeat				= 0x0100,	///< Enable notifications on Music Beat.
	AK_MusicSyncBar					= 0x0200,	///< Enable notifications on Music Bar.
	AK_MusicSyncEntry				= 0x0400,	///< Enable notifications on Music Entry Point.
	AK_MusicSyncExit				= 0x0800,	///< Enable notifications on Music Exit Point.

	AK_MusicSyncGrid				= 0x1000,	///< Enable notifications on Music Grid.
	AK_MusicSyncUserCue				= 0x2000,	///< Enable notifications on Music User Cue.

	AK_MusicSyncPoint				= 0x4000,	///< Enable notifications on Music synchronisation point.

	AK_MusicSyncAll					= 0xff00,	///< Use this flag if you want to receive all notifications concerning AK_MusicSync registration.

	AK_CallbackBits					= 0xffff,	///< Bitmask for all callback types.

	// Not a callback type, but needs to be part of same bitfield for AK::SoundEngine::PostEvent().
	AK_EnableGetSourcePlayPosition = 0x10000,	///< Enable play position information for use by AK::SoundEngine::GetSourcePlayPosition().
	AK_EnableGetMusicPlayPosition  = 0x20000,	///< Enable play position information of music objects, queried via AK::MusicEngine::GetPlayingSegmentInfo().
};

/// Callback information structure used as base for all notifications handled by AkCallbackFunc.
/// \sa 
/// - AK::SoundEngine::PostEvent()
/// - \ref soundengine_events
struct AkCallbackInfo
{
	void* pCookie;					///< User data, passed to PostEvent()
	AkGameObjectID gameObjID;		///< Game object ID
};

/// Function called on completion of an event, or when a marker is reached.
/// \param in_eType Type of callback.
/// \param in_pCallbackInfo Structure containing callback information.
/// \remarks An event is considered completed once all of its actions have been executed and all the playbacks in this events are terminated.
/// \remarks This callback is executed from the audio processing thread. The processing time in the callback function should be minimal. Having too much processing time could result in slowing down the audio processing.
/// \remarks Before waiting on an AK_EndOfEvent, make sure that the event is going to end. 
/// Some events can be continuously playing or infinitely looping, and the callback will not occur unless a specific stop event is sent to terminate the event.
/// \sa 
/// - AK::SoundEngine::PostEvent()
/// - AK::SoundEngine::DynamicSequence::Open()
/// - \ref soundengine_events
/// - \ref soundengine_markers
/// - \ref soundengine_music_callbacks
typedef void(*AkCallbackFunc)(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo);

/// Callback prototype used with asynchronous bank load/unload requests.
/// This function is called when the bank request has been processed 
/// and indicates if it was successfully executed or if an error occurred.
/// \param Identifier of the bank that was explicitly loaded/unloaded. 
/// In the case of PrepareEvent() or PrepareGameSyncs(), this value contains 
/// the AkUniqueID of the event/game sync that was prepared/unprepared, if the array contained only
/// one element. Otherwise, in_bankID equals AK_INVALID_UNIQUE_ID.
/// \param in_eLoadResult Result of the requested action.
///	- AK_Success: Load or unload successful.
/// - AK_IDNotFound: At least one of the event/game sync identifiers passed to PrepareEvent() or PrepareGameSyncs() does not exist.
/// - AK_InsufficientMemory: Insufficient memory to store bank data.
/// - AK_BankReadError: I/O error.
/// - AK_WrongBankVersion: Invalid bank version: make sure the version of Wwise that 
/// you used to generate the SoundBanks matches that of the SDK you are currently using.
/// - AK_InvalidFile: File specified could not be opened.
/// - AK_InvalidParameter: Invalid parameter.
/// - AK_Fail: Load or unload failed for any other reason.
/// \param in_memPoolId ID of the memory pool in which the bank was explicitly loaded/unloaded. 
/// AK_DEFAULT_POOL_ID is returned whenever this callback is issued from an implicit bank load (PrepareEvent(), PrepareGameSyncs()), 
/// the bank memory was managed internally, an error occured, or in the case of.
/// \param in_pCookie Optional cookie that was passed to the bank request.
/// \remarks This callback is executed from the bank thread. The processing time in the callback function should be minimal. Having too much processing time could slow down the bank loading process.
/// \sa 
/// - AK::SoundEngine::LoadBank()
/// - AK::SoundEngine::UnloadBank()
/// - AK::SoundEngine::PrepareEvent()
/// - AK::SoundEngine::PrepareGameSyncs()
/// - \ref soundengine_banks
typedef void(*AkBankCallbackFunc)(AkBankID in_bankID, AKRESULT in_eLoadResult, AkMemPoolId in_memPoolId, void* in_pCookie);
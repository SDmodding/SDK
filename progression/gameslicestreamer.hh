#pragma once

namespace UFG
{
	class GameSliceStreamer
	{
	public:
		struct DeferScriptDeletionRequest
		{
			qSafePointer<SSGameSlice> mScript;
		};

		struct StreamData
		{
			SSClass* mpRoot;
			void* mpBuffer;
			s8 mUsageCount;
		};

		class StreamRequest : public qNode<StreamRequest>
		{
		public:
			GameSlice* mpGameSlice;
			SSClass* mpRoot;
		};

		qList<StreamRequest> mStreamRequests;
		qFixedArray<StreamData, 128> mStreamData;
		qCircularArray<DeferScriptDeletionRequest> mDeferScriptDeletionRequests;

		/* Static Functions */

		SDK_SINLINE GameSliceStreamer* Instance() { return SDK_VAR(GameSliceStreamer*, 0x240AA30); }

		/* Functions */

		void CancelStream(GameSlice* pGameSlice) { SDK_CALL_FUNC(void, 0x496A50, void*, GameSlice*)(this, pGameSlice); }
		void Clear() { SDK_CALL_FUNC(void, 0x497700, void*)(this); }
		void DeferScriptDelete(SSGameSlice* pScript) { SDK_CALL_FUNC(void, 0x49A360, void*, SSGameSlice*)(this, pScript); }
		void RequestStream(GameSlice* pGameSlice) { SDK_CALL_FUNC(void, 0x4B66D0, void*, GameSlice*)(this, pGameSlice); }
		void RequestStream(GameSlice* pGameSlice, SSClass* pRoot) { SDK_CALL_FUNC(void, 0x4B6530, void*, GameSlice*, SSClass*)(this, pGameSlice, pRoot); }
		void Update() { SDK_CALL_FUNC(void, 0x4C3FA0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(GameSliceStreamer, 0xC48);
}
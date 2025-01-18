#pragma once

namespace UFG
{
	class PartDefinition;

	namespace PartPriority
	{
		enum Type
		{
			UnReferenced,
			Reserved,
			Critical,
			High,
			Low,
			Count
		};
	}

	class PartLoader
	{
	public:
		bool mPartsDirty;
		u32 mPartCount;
		u32 mPartRequestCount;
		PartDefinition* mParts[32];
		qSymbolUC mTextureSets[32];
		PartRequest* mPartRequests[32];
		qStaticBitField<32> mRequestsLoadedFlags;
		qStaticBitField<32> mRequestsDispatchEventFlags;
		PartPriority::Type mPriority;
		void(__fastcall* mOnLoadEventCallback)(void*, PartRequest*, bool);
		void(__fastcall* mOnForceRemovedCallback)(void*, PartRequest*);
		void* mUserContext;

		/* Impl Functions */

		SDK_INLINE PartDefinition* GetPart(u32 index) { return mParts[index]; }
		SDK_INLINE qSymbolUC* GetPartTextureSet(u32 index) { return &mTextureSets[index]; }

		/* Functions */

		void AddPart(PartDefinition* part, const qSymbolUC& textureSet) { SDK_CALL_FUNC(void, 0x1562A0, void*, PartDefinition*, const qSymbolUC&)(this, part, textureSet); }
		char IsLoaded() { return SDK_CALL_FUNC(char, 0x159520, void*)(this); }
		void QueueLoad() { SDK_CALL_FUNC(void, 0x159E60, void*)(this); }
		void Reset() { SDK_CALL_FUNC(void, 0x15A850, void*)(this); }
		void SetCallbacks(PartRequest*, decltype(mOnLoadEventCallback) loadCallback, decltype(mOnForceRemovedCallback) removedCallback, void* context) { 
			SDK_CALL_FUNC(void, 0x15AD40, void*, void*, void*, void*)(this, loadCallback, removedCallback, context); 
		}
		void Unload() { SDK_CALL_FUNC(void, 0x15B0D0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(PartLoader, 0x2C0);
}
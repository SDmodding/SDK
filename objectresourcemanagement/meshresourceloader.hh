#pragma once

namespace UFG
{
	class MeshResourceLoader
	{
	public:
		bool mHighDefinition;
		bool mResourcesDirty;
		u32 mResourceCount;
		ResourceRequest* mResourceRequests[18];
		qStaticBitField<18> mRequestsLoadedFlags;
		qStaticBitField<18> mRequestsDispatchEventFlags;
		qSymbol mActivePriority;
		qPropertySet* mPropertySet;
		TrueCrowdSet::Instance mTrueCrowdInstance;
		void(__fastcall* mOnLoadEventCallback)(void*, ResourceRequest*, bool);
		void(__fastcall* mOnForceRemovedCallback)(void*, ResourceRequest*);
		void* mUserContext;

		/* Functions */

		TrueCrowdTextureSet* GetTexture(u32 partIndex) { return SDK_CALL_FUNC(TrueCrowdTextureSet*, 0x43DEE0, void*, u32)(this, partIndex); }
		void Init(qPropertySet* propertySet, const qSymbol& priority, bool highDef) { SDK_CALL_FUNC(void, 0x43DFD0, void*, qPropertySet*, const qSymbol&, bool)(this, propertySet, priority, highDef); }
		bool IsLoaded() { return SDK_CALL_FUNC(bool, 0x43F240, void*)(this); }
		void PopulateTrueCrowdInstanceFromPropertySet(bool forceSelection) { SDK_CALL_FUNC(void, 0x43FBB0, void*, bool)(this, forceSelection); }
		void QueueLoad() { SDK_CALL_FUNC(void, 0x440EE0, void*)(this); }
		void Unload() { SDK_CALL_FUNC(void, 0x4444D0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(MeshResourceLoader, 0x1E8);
}
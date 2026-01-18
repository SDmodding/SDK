#pragma once

namespace UFG
{
	class qPropertySet;
	class qPropertyList;
	class qPropertySetResource;

	class qProperty
	{
	public:
		u32 mTypeUIDOffsetChanged;
		u32 mNameUID;
	};

	class qPropertyCollection
	{
	public:
		enum Flags
		{
			FLAG_MEMIMAGE = (1 << 0),
			FLAG_IS_SET = (1 << 1),
			FLAG_IS_LIST = (1 << 2),
			FLAG_DELETED = (1 << 3),
			FLAG_OWNER_IS_SET = (1 << 4),
			FLAG_OWNER_IS_LIST = (1 << 5)
		};

		u32 mFlags;
		u32 mPad0;
		qOffset64<qPropertyCollection*> mOwner;

		/* Impl Functions */

		SDK_INLINE bool GetFlags(int flags) const { return mFlags & flags; }
		SDK_INLINE void SetFlags(int flags) { mFlags |= flags; }

		SDK_INLINE const qPropertySet* GetOwningSet() const { return GetFlags(FLAG_OWNER_IS_SET) ? reinterpret_cast<qPropertySet*>(mOwner.Get()) : 0; }
		SDK_INLINE const qPropertyList* GetOwningList() const { return GetFlags(FLAG_OWNER_IS_LIST) ? reinterpret_cast<qPropertyList*>(mOwner.Get()) : 0; }

		SDK_INLINE bool IsMemImaged() const { return mFlags & FLAG_MEMIMAGE; }
		SDK_INLINE bool IsPropertySet() const { return (mFlags >> 1) & FLAG_IS_SET; }
		SDK_INLINE bool IsPropertyList() const { return (mFlags >> 2) & FLAG_IS_LIST; }

		SDK_INLINE void SetOwner(qPropertySet* owningSet)
		{
			mOwner.Set(owningSet);
			mFlags &= ~FLAG_OWNER_IS_LIST;
			mFlags |= FLAG_OWNER_IS_SET;
		}

		SDK_INLINE void SetOwner(qPropertyList* owningList)
		{
			mOwner.Set(owningList);
			mFlags &= ~FLAG_OWNER_IS_SET;
			mFlags |= FLAG_OWNER_IS_LIST;
		}
	};

	class qPropertySetHandle : public qTypedResourceHandle<0x54606C31, qPropertySetResource>
	{
	public:
	};

	class qPropertySet : public qPropertyCollection, public qNode<qPropertySet>
	{
	public:
		enum Type
		{
			Unknown,
			Archetype,
			SceneObject,
			LayerProperties,
			Asset
		};

		enum Flags
		{
			FLAG_RESOURCE_SET = (1 << 0) << 16,
			FLAG_HAS_SCHEMA = (1 << 1) << 16,
			FLAG_IS_SCHEMA = (1 << 2) << 16,
			FLAG_INHERIT_SCHEMA = (1 << 3) << 16,
			FLAG_COMPONENT_SCHEMA = (1 << 4) << 16,
			FLAG_CS_SKIP_PARENT_CHECK = (1 << 5) << 16,
			FLAG_REQUIRES_RECURSIVE_SETUP = (1 << 6) << 16,
			FLAG_TYPE_START = (1 << 12) << 16,
		};

		qOffset64<qPropertySetHandle*> mParents;
		qOffset64<u8*> mValues;
		qOffset64<u32*> mDefaultBits;
		qOffset64<qProperty*> mProperties;
		qSymbol mName;
		u16 mRefCount;
		u16 mNumParents;
		u32 mParentMask;
		qSymbol mSchemaName;
		u32 mPropertyMask;
		u16 mNumDataBytes;
		u16 mNumProperties;

		/* Static Functions */

		SDK_SINLINE qPropertySet* CreateResourceSet(const qSymbol& name, const char* dbg_tag) { return SDK_CALL_FUNC(qPropertySet*, 0x1F46E0, const qSymbol&, const char*)(name, dbg_tag); }

		/* Impl Functions */

		SDK_INLINE void AddRef() { ++mRefCount; }
		SDK_INLINE const qSymbol& GetName() { return mName; }
		SDK_INLINE bool IsResourceSet() { return mFlags & FLAG_RESOURCE_SET; }
		SDK_INLINE const qSymbol& GetSchemaName() { return mSchemaName; }
		SDK_INLINE Type GetType() { return static_cast<Type>(mFlags >> 0x1C); }
		SDK_INLINE u32 NumParents() { return mNumParents; }
		SDK_INLINE u32 NumProperties() { return mNumProperties; }
		SDK_INLINE void* GetMemImagePtr() { return mValues.Get(); }

		SDK_INLINE qPropertySetResource* GetResource()
		{
			if (!IsResourceSet()) {
				return nullptr;
			}

			return reinterpret_cast<qPropertySetResource*>(reinterpret_cast<uptr>(this) - (sizeof(qPropertySet) + sizeof(qChunk)));
		}

		SDK_INLINE void SetName(const qSymbol& name) { mName = name; }

		/* Parent Functions */

		u32 AddParent(qPropertySet* parent) { return SDK_CALL_FUNC(u32, 0x1F1B30, void*, qPropertySet*)(this, parent); }
		u32 AddParent(const qSymbol& parent_name) { return SDK_CALL_FUNC(u32, 0x1F1A70, void*, const qSymbol&)(this, parent_name); }
		qPropertySet* GetParentFromIdx(u32 parent_index) { return SDK_CALL_FUNC(qPropertySet*, 0x1F6FB0, void*, u32)(this, parent_index); }

		qPropertySet* GetParentFromName(const qSymbol& propertySetName, qPropertyDepth depth = DEPTH_RECURSE) {
			return SDK_CALL_FUNC(qPropertySet*, 0x1F7030, void*, const qSymbol&, qPropertyDepth)(this, propertySetName, depth);
		}

		s32 GetParentIdx(const qSymbol& parent_name) { return SDK_CALL_FUNC(s32, 0x1F71B0, void*, const qSymbol&)(this, parent_name); }
		qPropertySetHandle* InternalAddParent() { return SDK_CALL_FUNC(qPropertySetHandle*, 0x1F9760, void*)(this); }
		void RemoveParent(const qSymbol& parent_name) { SDK_CALL_FUNC(void, 0x1FB9A0, void*, const qSymbol&)(this, parent_name); }
		void RemoveParentsAll() { SDK_CALL_FUNC(void, 0x1FBD40, void*)(this); }
		void RemovePropertiesAllLocal() { SDK_CALL_FUNC(void, 0x1FBE40, void*)(this); }

		/* Property Functions */

		s32 GetPropertyIdxLocal(u32 type_uid, u32 name_uid) { return SDK_CALL_FUNC(s32, 0x1F7630, void*, u32, u32)(this, type_uid, name_uid); }
		s32 GetPropertyIndexFromName(const qSymbol& name) { return SDK_CALL_FUNC(s32, 0x1F7870, void*, const qSymbol&)(this, name); }
		const qSymbol& GetPropertyNameFromIndex(u32 index) { return SDK_CALL_FUNC(const qSymbol&, 0x1F7AC0, void*, u32)(this, index); }
		ePropertyType GetPropertyTypeFromIndex(u32 index) { return SDK_CALL_FUNC(ePropertyType, 0x1F7BF0, void*, u32)(this, index); }

		ePropertyType GetPropertyTypeFromName(const qSymbol& propName, qPropertyDepth depth = DEPTH_RECURSE) {
			return SDK_CALL_FUNC(ePropertyType, 0x1F7C70, void*, const qSymbol&, qPropertyDepth)(this, propName, depth);
		}

		void RemovePropertyByName(const qSymbol& name) { SDK_CALL_FUNC(void, 0x1FC160, void*, const qSymbol&)(this, name); }
		void RemovePropertyIdx(u32 property_index) { SDK_CALL_FUNC(void, 0x1FC220, void*, u32)(this, property_index); }
		qPropertySet* PropertyExists(const qSymbol& name, qPropertyDepth depth = DEPTH_RECURSE) { return SDK_CALL_FUNC(qPropertySet*, 0x1FA740, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }
		bool PropertyIsDefaultByName(const qSymbol& propertyName) { return SDK_CALL_FUNC(bool, 0x1FA880, void*, const qSymbol&)(this, propertyName); }
		bool PropertyIsDefaultIdx(u32 property_index) { return SDK_CALL_FUNC(bool, 0x1FA8C0, void*, u32)(this, property_index); }

		/* Functions */

		qPropertySet* Clone() { return SDK_CALL_FUNC(qPropertySet*, 0x1F2520, void*)(this); }
		void CopyFrom(qPropertySet* source_set, bool copyParents) { SDK_CALL_FUNC(void, 0x1F29A0, void*, qPropertySet*, bool)(this, source_set, copyParents); }
		void Destroy() { SDK_CALL_FUNC(void, 0x1F50F0, void*)(this); }

		void* GetValuePtr(u32 type_uid, u32 name_uid, qPropertyDepth depth = DEPTH_RECURSE, qPropertySet** owningSet = 0) {
			return SDK_CALL_FUNC(void*, 0x1F8990, void*, u32, u32, qPropertyDepth, qPropertySet**)(this, type_uid, name_uid, depth, owningSet);
		}

		void ReleaseRef() { SDK_CALL_FUNC(void, 0x1FB2B0, void*)(this); }
		void* SetInternal(u32 type_uid, u32 name_uid, const void* v) { return SDK_CALL_FUNC(void*, 0x1FD610, void*, u32, u32, const void*)(this, type_uid, name_uid, v); }

		/* Get Functions */

		template<typename T>
		T* Get(const qSymbol& name, qPropertyDepth depth = DEPTH_RECURSE);

		template<>
		qMatrix44* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qMatrix44*, 0x1E9D90, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		qPropertyList* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qPropertyList*, 0x1E9E60, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		qPropertySet* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qPropertySet*, 0x1E9EF0, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		qRangedValue<f32>* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qRangedValue<f32>*, 0x1E9C80, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		qRangedValue<s32>* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qRangedValue<s32>*, 0x1E9C30, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		qSymbol* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qSymbol*, 0x1E9FF0, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		qSymbolUC* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qSymbolUC*, 0x1EA0B0, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		qTransQuat* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qTransQuat*, 0x1E9CD0, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		qVector2* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qVector2*, 0x1EA170, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		qVector3* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qVector3*, 0x1EA230, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		qVector4* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qVector4*, 0x1EA2F0, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		qWiseSymbol* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(qWiseSymbol*, 0x1EA3B0, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		i64* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(i64*, 0x1EA470, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		bool* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(bool*, 0x1EA610, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		const char* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(const char*, 0x1E9B30, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		f32* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(f32*, 0x1E9A60, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		i32* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(i32*, 0x1E98E0, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		i16* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(i16*, 0x1E9760, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		i8* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(i8*, 0x1E95F0, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		u8* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(u8*, 0x1E96A0, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		u32* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(u32*, 0x1E99A0, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		u64* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(u64*, 0x1EA530, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		template<>
		u16* Get(const qSymbol& name, qPropertyDepth depth) { return SDK_CALL_FUNC(u16*, 0x1E9820, void*, const qSymbol&, qPropertyDepth)(this, name, depth); }

		bool GetVariant(const qSymbol& name, qPropertySetVariant& value, qPropertyDepth depth = DEPTH_RECURSE) { 
			return SDK_CALL_FUNC(bool, 0x1F9170, void*, const qSymbol&, qPropertySetVariant&, qPropertyDepth)(this, name, value, depth); 
		}

		/* Set Functions */

		void Set(const qSymbol& name, const qMatrix44& v) { SDK_CALL_FUNC(void, 0x1EAF90, void*, const qSymbol&, const qMatrix44&)(this, name, v); }
		void Set(const qSymbol& name, const qPropertyList* v) { SDK_CALL_FUNC(void, 0x1EAFE0, void*, const qSymbol&, const qPropertyList*)(this, name, v); }
		void Set(const qSymbol& name, const qPropertySet* v) { SDK_CALL_FUNC(void, 0x1EB030, void*, const qSymbol&, const qPropertySet*)(this, name, v); }
		void Set(const qSymbol& name, const qRangedValue<i32>& v) { SDK_CALL_FUNC(void, 0x1EAF10, void*, const qSymbol&, const qRangedValue<i32>&)(this, name, v); }
		void Set(const qSymbol& name, const qSymbol& v) { SDK_CALL_FUNC(void, 0x1EB070, void*, const qSymbol&, const qSymbol&)(this, name, v); }
		void Set(const qSymbol& name, const qSymbolUC& v) { SDK_CALL_FUNC(void, 0x1EB0B0, void*, const qSymbol&, const qSymbolUC&)(this, name, v); }
		void Set(const qSymbol& name, const qTransQuat& v) { SDK_CALL_FUNC(void, 0x1EAF50, void*, const qSymbol&, const qTransQuat&)(this, name, v); }
		void Set(const qSymbol& name, const qVector2& v) { SDK_CALL_FUNC(void, 0x1EB0F0, void*, const qSymbol&, const qVector2&)(this, name, v); }
		void Set(const qSymbol& name, const qVector3& v) { SDK_CALL_FUNC(void, 0x1EB130, void*, const qSymbol&, const qVector3&)(this, name, v); }
		void Set(const qSymbol& name, const qVector4& v) { SDK_CALL_FUNC(void, 0x1EB170, void*, const qSymbol&, const qVector4&)(this, name, v); }
		void Set(const qSymbol& name, const qWiseSymbol& v) { SDK_CALL_FUNC(void, 0x1EB1B0, void*, const qSymbol&, const qWiseSymbol&)(this, name, v); }
		void Set(const qSymbol& name, const i64 v) { SDK_CALL_FUNC(void, 0x1EB1F0, void*, const qSymbol&, const i64)(this, name, v); }
		void Set(const qSymbol& name, const bool& v) { SDK_CALL_FUNC(void, 0x1EB270, void*, const qSymbol&, const bool&)(this, name, v); }
		void Set(const qSymbol& name, const char* v) { SDK_CALL_FUNC(void, 0x1EAE90, void*, const qSymbol&, const char*)(this, name, v); }
		void Set(const qSymbol& name, const float v) { SDK_CALL_FUNC(void, 0x1EAE50, void*, const qSymbol&, const float)(this, name, v); }
		void Set(const qSymbol& name, const i32 v) { SDK_CALL_FUNC(void, 0x1EADD0, void*, const qSymbol&, const i32)(this, name, v); }
		void Set(const qSymbol& name, const i16 v) { SDK_CALL_FUNC(void, 0x1EAD50, void*, const qSymbol&, const i16)(this, name, v); }
		void Set(const qSymbol& name, const i8 v) { SDK_CALL_FUNC(void, 0x11EACD0, void*, const qSymbol&, const i8)(this, name, v); }
		void Set(const qSymbol& name, const u8 v) { SDK_CALL_FUNC(void, 0x1EAD10, void*, const qSymbol&, const u8)(this, name, v); }
		void Set(const qSymbol& name, const u32 v) { SDK_CALL_FUNC(void, 0x1EAE10, void*, const qSymbol&, const u32)(this, name, v); }
		void Set(const qSymbol& name, const u64 v) { SDK_CALL_FUNC(void, 0x1EB230, void*, const qSymbol&, const u64)(this, name, v); }
		void Set(const qSymbol& name, const u16 v) { SDK_CALL_FUNC(void, 0x1EAD90, void*, const qSymbol&, const u16)(this, name, v); }

		bool SetVariant(const qSymbol& name, const qPropertySetVariant& value) { return SDK_CALL_FUNC(bool, 0x1FE910, void*, const qSymbol&, const qPropertySetVariant&)(this, name, value); }
	};
	SDK_ASSERT_SIZEOF(qPropertySet, 0x58);

	class qPropertySetResource : public qResourceData
	{
	public:
		u32 mFlags;
		u32 mSourceCRC;
		qOffset64<char const*> mNameString;
		qPropertySet mData;
	};
}
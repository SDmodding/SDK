#pragma once

namespace UFG
{
	class qPropertyList : public qPropertyCollection
	{
	public:
		enum Flags
		{
			FLAG_DELETED = (1 << 16)
		};

		qOffset64<u8*> mValues;
		u32 mTypeUID;
		u32 mElementSize;
		qOffset64<u32*> mWeights;
		u32 mNumElements;
		u32 mTotalWeight;

		/* Static Functions */

		SDK_SINLINE qPropertyList* Create(const char* dbg_tag = SDK_VAR(const char*, 0x16BE9F0)) { return SDK_CALL_FUNC(qPropertyList*, 0x1F4060, const char*)(dbg_tag); }

		/* Functions */

		u32 GetRandomIndex() { return SDK_CALL_FUNC(u32, 0x1F8010, void*)(this); }
		void* GetValuePtr(u32 type_uid, u32 index) { return SDK_CALL_FUNC(void*, 0x1F8920, void*, u32, u32)(this, type_uid, index); }
		bool GetVariant(u32 index, qPropertySetVariant& value) { return SDK_CALL_FUNC(bool, 0x1F8E90, void*, u32, qPropertySetVariant&)(this, index, value); }

		/* Add Functions */

		template <typename T>
		void Add(const T v);

		template<>
		void Add(const qMatrix44& v) { SDK_CALL_FUNC(void, 0x1E8CF0, void*, const qMatrix44&)(this, v); }

		template<>
		void Add(qPropertyList* v) { SDK_CALL_FUNC(void, 0x1E8D10, void*, qPropertyList*)(this, v); }

		template<>
		void Add(qPropertySet* v) { SDK_CALL_FUNC(void, 0x1E8D30, void*, qPropertySet*)(this, v); }

		template<>
		void Add(const qSymbol& v) { SDK_CALL_FUNC(void, 0x1E8D50, void*, const qSymbol&)(this, v); }

		template<>
		void Add(const qSymbolUC& v) { SDK_CALL_FUNC(void, 0x1E8D70, void*, const qSymbolUC&)(this, v); }

		template<>
		void Add(const qTransQuat& v) { SDK_CALL_FUNC(void, 0x1E8CD0, void*, const qTransQuat&)(this, v); }

		template<>
		void Add(const qVector2& v) { SDK_CALL_FUNC(void, 0x1E8D90, void*, const qVector2&)(this, v); }

		template<>
		void Add(const qVector3& v) { SDK_CALL_FUNC(void, 0x1E8DB0, void*, const qVector3&)(this, v); }

		template<>
		void Add(const qVector4& v) { SDK_CALL_FUNC(void, 0x1E8DD0, void*, const qVector4&)(this, v); }

		template<>
		void Add(const qWiseSymbol& v) { SDK_CALL_FUNC(void, 0x1E8DF0, void*, const qWiseSymbol&)(this, v); }

		template<>
		void Add(i64 v) { SDK_CALL_FUNC(void, 0x1E8E10, void*, i64)(this, v); }

		template<>
		void Add(bool v) { SDK_CALL_FUNC(void, 0x1E8E70, void*, bool)(this, v); }

		template<>
		void Add(const char* v) { SDK_CALL_FUNC(void, 0x1E8CB0, void*, const char*)(this, v); }

		template<>
		void Add(f32 v) { SDK_CALL_FUNC(void, 0x1E8C80, void*, f32)(this, v); }

		template<>
		void Add(int v) { SDK_CALL_FUNC(void, 0x1E8C40, void*, int)(this, v); }

		template<>
		void Add(i16 v) { SDK_CALL_FUNC(void, 0x1E8BE0, void*, i16)(this, v); }

		template<>
		void Add(i8 v) { SDK_CALL_FUNC(void, 0x1E8BA0, void*, i8)(this, v); }

		template<>
		void Add(u8 v) { SDK_CALL_FUNC(void, 0x1E8BC0, void*, u8)(this, v); }

		template<>
		void Add(u32 v) { SDK_CALL_FUNC(void, 0x1E8C60, void*, u32)(this, v); }

		template<>
		void Add(u64 v) { SDK_CALL_FUNC(void, 0x1E8E40, void*, u64)(this, v); }

		template<>
		void Add(u16 v) { SDK_CALL_FUNC(void, 0x1E8C10, void*, u16)(this, v); }

		/* Get Functions */

		template <typename T>
		T* Get(u32 index);

		template<>
		qMatrix44* Get(u32 index) { return SDK_CALL_FUNC(qMatrix44*, 0x1E9D20, void*, u32)(this, index); }

		template<>
		qPropertyList* Get(u32 index) { return SDK_CALL_FUNC(qPropertyList*, 0x1E9DE0, void*, u32)(this, index); }

		template<>
		qPropertySet* Get(u32 index) { return SDK_CALL_FUNC(qPropertySet*, 0x642D0, void*, u32)(this, index); }

		template<>
		qSymbol* Get(u32 index) { return SDK_CALL_FUNC(qSymbol*, 0x1E9F80, void*, u32)(this, index); }

		template<>
		qSymbolUC* Get(u32 index) { return SDK_CALL_FUNC(qSymbolUC*, 0x1EA040, void*, u32)(this, index); }

		template<>
		qVector2* Get(u32 index) { return SDK_CALL_FUNC(qVector2*, 0x1EA100, void*, u32)(this, index); }

		template<>
		qVector3* Get(u32 index) { return SDK_CALL_FUNC(qVector3*, 0x1EA1C0, void*, u32)(this, index); }

		template<>
		qVector4* Get(u32 index) { return SDK_CALL_FUNC(qVector4*, 0x1EA280, void*, u32)(this, index); }

		template<>
		qWiseSymbol* Get(u32 index) { return SDK_CALL_FUNC(qWiseSymbol*, 0x1EA340, void*, u32)(this, index); }

		template<>
		i64* Get(u32 index) { return SDK_CALL_FUNC(i64*, 0x1EA400, void*, u32)(this, index); }

		template<>
		__m128* Get(u32 index) { return SDK_CALL_FUNC(__m128*, 0x1E9BC0, void*, u32)(this, index); }

		template<>
		bool* Get(u32 index) { return SDK_CALL_FUNC(bool*, 0x1EA580, void*, u32)(this, index); }

		template<>
		const char* Get(u32 index) { return SDK_CALL_FUNC(const char*, 0x1E9AB0, void*, u32)(this, index); }

		template<>
		f32* Get(u32 index) { return SDK_CALL_FUNC(f32*, 0x1E99F0, void*, u32)(this, index); }

		template<>
		int* Get(u32 index) { return SDK_CALL_FUNC(int*, 0x1E9870, void*, u32)(this, index); }

		template<>
		short* Get(u32 index) { return SDK_CALL_FUNC(short*, 0x1E96F0, void*, u32)(this, index); }

		template<>
		s8* Get(u32 index) { return SDK_CALL_FUNC(s8*, 0x1E9580, void*, u32)(this, index); }

		template<>
		u8* Get(u32 index) { return SDK_CALL_FUNC(u8*, 0x1E9630, void*, u32)(this, index); }

		template<>
		u32* Get(u32 index) { return SDK_CALL_FUNC(u32*, 0x1E9930, void*, u32)(this, index); }

		template<>
		u64* Get(u32 index) { return SDK_CALL_FUNC(u64*, 0x1EA4C0, void*, u32)(this, index); }

		template<>
		u16* Get(u32 index) { return SDK_CALL_FUNC(u16*, 0x1E97B0, void*, u32)(this, index); }
	};
	SDK_ASSERT_SIZEOF(qPropertyList, 0x30);
}
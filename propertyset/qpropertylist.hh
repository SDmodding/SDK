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
	};
	SDK_ASSERT_SIZEOF(qPropertyList, 0x30);
}
#pragma once

namespace UFG
{
	enum ePropertyType : s32
	{
		UID_int8,
		UID_int16,
		UID_int32,
		UID_int64,
		UID_int128,
		UID_uint8,
		UID_uint16,
		UID_uint32,
		UID_uint64,
		UID_bool,
		UID_float,
		UID_double,
		UID_string,
		UID_rangedFloat,
		UID_rangedUint32,
		UID_rangedInt32,
		UID_weightedList,
		UID_qVector2,
		UID_qVector3,
		UID_qVector4,
		UID_qMatrix44,
		UID_qResHandle,
		UID_qSymbol,
		UID_qSymbolUC,
		UID_qWiseSymbol,
		UID_list,
		UID_propertyset,
		UID_TransRot,
		UID_qTransQuat,
		UID_Invalid,
		PROPERTY_SET_DATA_TYPE_COUNT
	};

	enum qPropertyDepth : s32
	{
		DEPTH_LOCAL,
		DEPTH_RECURSE
	};

	class qPropertySetVariant
	{
	public:
		ePropertyType meType;
		union
		{
			i8 mValueI8;
			i16 mValueI16;
			i32 mValueI32;
			i64 mValueI64;
			__m128 mValueI128;
			u8 mValueU8;
			u16 mValueU16;
			u32 mValueU32;
			u64 mValueU64;
			bool mValueBool;
			f32 mValueFloat;
			double mValueDouble;
		};
		qVector2 mValueVector2;
		qVector3 mValueVector3;
		qVector4 mValueVector4;
		qMatrix44 mValueMatrix44;
		qString mValueString;
		qSymbol mValueSymbol;
		qSymbolUC mValueSymbolUC;
		qWiseSymbol mValueWiseSymbol;

		~qPropertySetVariant() { SDK_CALL_FUNC(void, 0x203E30, void*)(this); }
		void operator=(const qPropertySetVariant& other) { SDK_CALL_FUNC(void, 0x1EED30, void*, const qPropertySetVariant&)(this, other); }
		bool operator==(const qPropertySetVariant& other) { return SDK_CALL_FUNC(bool, 0x1EF180, void*, const qPropertySetVariant&)(this, other); }

		/* Functions */

		void Clear() { SDK_CALL_FUNC(void, 0x1F23F0, void*)(this); }
		void Set(const void* dataPtr, ePropertyType eType) { SDK_CALL_FUNC(void, 0x1FCA70, void*, const void*, ePropertyType)(this, dataPtr, eType); }
		void SetFromString(const qString& value, ePropertyType eType) { SDK_CALL_FUNC(void, 0x1FD0A0, void*, const qString&, ePropertyType)(this, value, eType); }
		void ToString(qString& value) { SDK_CALL_FUNC(void, 0x1FF080, void*, qString&)(this, value); }
	};

}
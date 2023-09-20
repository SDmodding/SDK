#pragma once

namespace UEL
{
	class CValue
	{
	public:
		union Data_t
		{
			int64_t integer;
			unsigned int qSymbol_mUID;
			const char* string;
			float real;
			char boolean;
			int enumeration;
			void* structPtr;
			void* getter;
			void* lookup;
			float qVector_x;
		};
		Data_t mData;
		float qVector_y;
		float qVector_z;
		float qVector_w;

		struct Type_t
		{
			uint16_t mBaseType;
			UFG::qSymbol mDetailedType;
		};
		Type_t type;
	};
}
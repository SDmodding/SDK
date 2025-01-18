#pragma once

class SSObjectId : public SSExpressionBase
{
public:
	enum eFlag
	{
		Flag_optional_find = 1 << 0,
		Flag_optional_literal = 1 << 1,
		Flag_use_cached = 1 << 2,
		Flag__custom_bit = Flag_optional_find | Flag_optional_literal,
		Flag__none = 0,
		Flag__default = Flag__none
	};

	ASymbol i_name;
	SSClass* i_class_p;
	AIdPtr<SSInstance> i_obj_p;
	u32 i_flags;
};
#pragma once

class AStringRef
{
public:
	char* i_cstr_p;
	u32 i_length;
	u32 i_size;
	u16 i_ref_count;
	bool i_deallocate;
	bool i_read_only;
};
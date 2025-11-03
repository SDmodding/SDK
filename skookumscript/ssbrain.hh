#pragma once

class SSBrain
{
public:
	/* Static Functions */

	SDK_SINLINE SSClass* create_class(const ASymbol& class_name, SSClass* superclass_p = 0, u32 flags = -1, bool append_super_members = 0) {
		return SDK_CALL_FUNC(SSClass*, 0x112D80, const ASymbol&, SSClass*, u32, bool)(class_name, superclass_p, flags, append_super_members);
	}

	SDK_SINLINE SSClass* get_class(const ASymbol& class_name) { return SDK_CALL_FUNC(SSClass*, 0x1174F0, const ASymbol&)(class_name); }
	SDK_SINLINE SSClass* get_class(const char* class_name_p) { return SDK_CALL_FUNC(SSClass*, 0x117560, const char*)(class_name_p); }
};
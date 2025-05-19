#pragma once

class SSBrain
{
public:
	/* Static Functions */

	SDK_SINLINE SSClass* get_class(const ASymbol& class_name) { return SDK_CALL_FUNC(SSClass*, 0x1174F0, const ASymbol&)(class_name); }
	SDK_SINLINE SSClass* get_class(const char* class_name_p) { return SDK_CALL_FUNC(SSClass*, 0x117560, const char*)(class_name_p); }
};
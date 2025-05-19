#pragma once

class SSSymbol
{
public:
	/* Static Functions */

	SDK_SINLINE SSInstance* as_instance(const ASymbol& sym) { return SDK_CALL_FUNC(SSInstance*, 0x10F260, const ASymbol&)(sym); }
};
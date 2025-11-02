#pragma once

class SSCode : public SSExpressionBase
{
public:
	AVCompactSortedLogical<ASymbol> i_temp_vars;
	APCompactArrayFree<SSExpressionBase> i_statements;

	SSCode(const void** binary_pp) { SDK_CALL_FUNC(void, 0x104A70, void*, const void**)(this, binary_pp); }

	/* Virtual Functions */

	virtual ~SSCode() = 0;

	/* Functions */

	void assign_binary(const void** binary_pp) { SDK_CALL_FUNC(void, 0x1110A0, void*, const void**)(this, binary_pp); }
};
#pragma once

class SSParameters : public ARefCountMix<SSParameters>
{
public:
	APCompactArrayLogical<SSParameterBase, ASymbol> i_params;
	APCompactArrayLogical<SSTypedName, ASymbol> i_return_params;
	ARefPtr<SSClassDescBase> i_result_type_p;
};
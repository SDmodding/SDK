#pragma once

class SSContextClassBase : public SSClassUnaryBase, public ARefCountMix<SSContextClassBase>
{
public:
	SSClass* i_class_p;
};
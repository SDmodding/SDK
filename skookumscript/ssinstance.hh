#pragma once

class SSInstance : public SSObjectBase, public ARefCountMix<SSInstance>
{
public:
	SSClass* i_class_p;
	u64 i_user_data;
	u64 i_user_data2;
};

class SSInstanceUnreffed : public SSInstance
{
public:
};

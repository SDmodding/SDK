#pragma once

class SSTypedName : public ANamed
{
public:
	ARefPtr<class SSClassDescBase> i_type_p;
};

class SSTypedData : public SSTypedName
{
public:
	class SSInstance* i_data_p;
};

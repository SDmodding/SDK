#pragma once

class SSData : public ANamed
{
public:
	SSInstance* i_data_p;
};

class SSObjectBase
{
public:
	u32 i_ptr_id;

	virtual ~SSObjectBase() = 0;
	virtual u32 get_obj_type() = 0;
	virtual bool is_actor() = 0;
	virtual SSInstance* as_instance() = 0;
	virtual SSInstance* get_data_by_name(const ASymbol& name) = 0;
	virtual void set_data_by_name(const ASymbol& name, SSInstance* obj_p) = 0;
	virtual class SSInvokedContextBase* get_scope_context() = 0;
	virtual SSInstance* get_topmost_scope() = 0;
};
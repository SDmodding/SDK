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
	/*
	
  SSInstance *(__fastcall *as_instance)(SSObjectBase *this);
  SSInstance *(__fastcall *get_data_by_name)(SSObjectBase *this, ASymbol *);
  void (__fastcall *set_data_by_name)(SSObjectBase *this, ASymbol *, SSInstance *);
  SSInvokedContextBase *(__fastcall *get_scope_context)(SSObjectBase *this);
  SSInstance *(__fastcall *get_topmost_scope)(SSObjectBase *this);
	*/
};
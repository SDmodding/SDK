#pragma once

class SSClass;
class SSClassUnaryBase;

class SSClassDescBase
{
public:
	virtual ~SSClassDescBase() = 0;
	virtual void reference() = 0;
	virtual void dereference() = 0;
	virtual void dereference_delay() = 0;
	virtual SSClassDescBase* as_finalized_generic(SSClassDescBase* scope_type) = 0;
	virtual SSClassUnaryBase* as_unary_class() = 0;
	virtual SSClassUnaryBase* as_unary_class2() = 0;
	virtual SSClassUnaryBase* find_common_type(SSClassDescBase* cls) = 0;
	virtual bool is_actor_class() = 0;
	virtual bool is_actor_instance() = 0;
	virtual bool is_generic() = 0;
	virtual bool is_metaclass() = 0;
	virtual bool is_class_type(SSClassDescBase* cls) = 0;
	/*
		eSSClassType (__fastcall *get_class_type)(SSClassDescBase *this);
		SSClassDescBase *(__fastcall *get_item_type)(SSClassDescBase *this);
		SSClass *(__fastcall *get_key_class)(SSClassDescBase *this);
		ASymbol *(__fastcall *get_key_class_name)(SSClassDescBase *this);
		SSMetaClass *(__fastcall *get_metaclass)(SSClassDescBase *this);
		SSClassDescBase *(__fastcall *get_data_type)(SSClassDescBase *this, ASymbol *, eSSScope *);
		SSMethodBase *(__fastcall *get_method)(SSClassDescBase *this, ASymbol *);
		SSMethodBase *(__fastcall *get_method_inherited)(SSClassDescBase *this, ASymbol *);
		bool (__fastcall *is_method_inherited_valid)(SSClassDescBase *this, ASymbol *);
		bool (__fastcall *is_method_registered)(SSClassDescBase *this, ASymbol *);
		SSCoroutineBase *(__fastcall *get_coroutine_inherited)(SSClassDescBase *this, ASymbol *);
	*/
};

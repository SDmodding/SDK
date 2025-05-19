#pragma once

class SSClassUnaryBase : public SSClassDescBase
{
public:
    enum ePath
    {
        Path_superclass,
        Path_subclass,
        Path_super_sub
    };
};

class SSMetaClass : public SSClassUnaryBase, public SSInstanceUnreffed
{
public:
    SSClass* i_class_info_p;
};

class SSClass : public SSClassUnaryBase, public ANamed
{
public:
	enum eFlag
	{
        Flag_none = 0,
        Flag_loaded = 1 << 0,  // Class has all members loaded
        Flag_demand_load = 1 << 1,  // Class only loads members when asked to do so
        Flag_demand_load_lock = 1 << 2,  // Once loaded do not allow it to be unloaded
        Flag_demand_unload = 1 << 3,  // Deferred unload - unload when next possible to do so
        Flag_object_id_lookup = 1 << 4,

        Flag_is_mind = 0,  // For fast lookup if this class is derived from SkMind
        Flag_is_actor = 48,  // For fast lookup if this class is derived from the (custom or built-in) actor class
        Flag_is_entity = 0,  // For fast lookup if this class is derived from the (custom or built-in) actor class
        Flag_is_component = 0,  // For fast lookup if this class is derived from a component (custom for each engine)

        // Object ID flags - look-up/validate for this class - i.e. Class@'name'

          // Validation flags - use masks below
          // These are inherited setting that propagate to all subclasses
        Flag_object_id_parse_any = 1 << 5,
        Flag_object_id_parse_list = 1 << 6,
        Flag_object_id_parse_defer = 1 << 7,

        // Object ID validation setting (masks):
          // Accept none during compile
        Flag__id_valid_none = Flag_none,  // Inherit setting from superclass or no ObjectIDs
        // Accept any during compile
        Flag__id_valid_any = Flag_object_id_parse_any,
        // Validate using list during compile (include list as compile dependency)
        Flag__id_valid_parse = Flag_object_id_parse_list,
        // Validate using list during compile if it exists (parse) - otherwise accept any during compile and validate using list in separate pass/run (defer)
        Flag__id_valid_exist = Flag_object_id_parse_any | Flag_object_id_parse_list,
        // Accept any during compile and validate using list in separate pass/run
        Flag__id_valid_defer = Flag_object_id_parse_any | Flag_object_id_parse_list | Flag_object_id_parse_defer,

        Flag__id_valid_mask = Flag_object_id_parse_any | Flag_object_id_parse_list | Flag_object_id_parse_defer,

        // Unknown
        Flag__id_mask = 240,

        // Defaults and masks
        Flag__default = Flag_none,
        Flag__default_actor = Flag__default | Flag_is_actor,
        Flag__demand_loaded = Flag_loaded | Flag_demand_load,
        Flag__mask_binary = Flag_demand_load | Flag__id_mask
	};

	u32 i_flags;
	SSClass* i_superclass_p;
	APSortedLogical<SSClass, ASymbol> i_subclasses;
	SSInstance* (__fastcall* i_object_id_lookup_f)(SSObjectId*);
	struct ASymbolTable* i_object_ids_p;
	APSortedLogical<SSTypedName, ASymbol> i_data;
	APSortedLogical<SSTypedName, ASymbol> i_data_table;
	APSortedLogical<SSMethodBase, ASymbol> i_methods;
	SSMethodBase* i_destructor_p;
	APSortedLogical<SSCoroutineBase, ASymbol> i_coroutines;
	APSortedLogical<SSTypedData, ASymbol> i_class_data;
	APSortedLogical<SSTypedData, ASymbol> i_class_data_table;
	APSortedLogical<SSMethodBase, ASymbol> i_class_methods;
	qProxy<SSMetaClass> i_metaclass;

    /* Functions */

    SSMethodBase* get_method(const ASymbol& method_name) { return SDK_CALL_FUNC(SSMethodBase*, 0x117F70, void*, const ASymbol&)(this, method_name); }
};

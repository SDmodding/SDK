#pragma once
#include "SkookumPwner_File.hpp"

#define SKOOKUMPWNER_ASYMBOL_CREATE						UFG_RVA(0x2247B0)

#define SKOOKUMPWNER_SSCLASS_REGISTERMETHODFUNC			UFG_RVA(0x13B840)	// Func: ASymbol - arg2

#define SKOOKUMPWNER_SSBRAIN_CREATECLASS				UFG_RVA(0x112D80)
#define SKOOKUMPWNER_SSBRAIN_GETCLASS_CHAR				UFG_RVA(0x117560)	// Func: const char* - arg1
#define SKOOKUMPWNER_SSBRAIN_CLASSES					UFG_RVA(0x2175678)	// Global variable

namespace SkookumPwner
{
	// Classes
	class SSClass
	{
	public:
		void* vfptr;
		uint32_t m_Name;
		uint32_t m_Flags;
		uintptr_t* m_SuperClass;
	};

	namespace Resolver
	{
		struct ClassMethod_t
		{
			std::string m_Name;
		};

		struct Class_t
		{
			std::string m_Name;

			std::unordered_map<void*, ClassMethod_t> m_Methods;

			ClassMethod_t* NewMethod(void* m_SSMethod, std::string m_Name)
			{
				ClassMethod_t* m_Ret = &m_Methods[m_SSMethod];
				m_Ret->m_Name = m_Name;

				return m_Ret;
			}
		};

		std::unordered_map<SSClass*, Class_t> m_ClassList;

		Class_t* GetClass(SSClass* m_SSClass)
		{
			return &m_ClassList[m_SSClass];
		}

		Class_t* NewClass(SSClass* m_SSClass, std::string m_Name)
		{
			Class_t* m_Ret = &m_ClassList[m_SSClass];
			m_Ret->m_Name = m_Name;

			return m_Ret;
		}
	}

	// Hooks, Functions...
	namespace ASymbol_
	{
		std::unordered_map<uint32_t, std::string> m_Map;

		typedef uint32_t*(__fastcall* m_tCreate)(uint32_t*, const char*, unsigned int, unsigned int);
		m_tCreate m_oCreate;

		uint32_t* __fastcall Create(uint32_t* result, const char* cstr_p, unsigned int length, unsigned int term)
		{
			std::string m_MapString = cstr_p;

			uint32_t* m_Ret = m_oCreate(result, cstr_p, length, term);

			m_Map[*m_Ret] = m_MapString;

			return m_Ret;
		}

		std::unordered_map<uint32_t, std::string> m_CompiledMap;
		void InitializeCompiledMap()
		{
			const char* m_Initializers[] = { "Actor", "Boolean", "Char", "Class", "Closure", "DataC", "Data", "Debug", "Filter", "Integer", "InvokedBase", "InvokedContextBase", "InvokedCoroutine", "InvokedMethod", "List", "LogicalActor", "None", "Object", "PhysicalActor", "Random", "Real", "SimpleType", "String", "Symbol", "TriggerInVehicle", "TriggerOnBike", "TriggerOnFoot", "World", "_Class", "_Focus", "_Named", "_Player", "_This", "_anon", "_closure", "_pulse", "_wait", "_wait_until", "add", "add_assign", "and", "append", "append_absent_eqv", "append_items", "append_list", "as_copy", "as_new", "assign", "branch", "case", "closure", "coin_toss", "crop", "decrement", "divert", "divide", "divide_assign", "down_slope", "down_slope_int", "else", "empty", "equals", "equals_eqv", "exit", "false", "find_named", "get_at", "get_count", "get_count_after", "get_first", "get_generated", "get_last", "get_name", "get_range", "get_seed", "get_strategy_name", "greater", "greater_or_equal", "if", "increment", "insert", "insert_items", "insert_list", "is", "is_class", "is_class_actor", "is_empty", "is_filled", "is_subclass", "is_superclass", "less", "less_or_equal", "loop", "multiply", "multiply_assign", "name", "nand", "nil", "nor", "normal", "normal_int", "nose", "nose_int", "not", "not_equal", "not_equal_eqv", "nxor", "or", "origin_actor_update", "origin_class_ctors", "origin_default_ctor", "origin_embedded1", "origin_embedded2", "origin_embedded3", "origin_embedded4", "origin_embedded5", "origin_parser_interpreted", "pop_at", "pop_first", "pop_last", "pop_range", "pop_range_last", "race", "remove_at", "remove_eqv", "remove_first", "remove_last", "remove_range", "remove_range_last", "reuse", "reverse", "rotate_down", "rotate_up", "set_at", "set_items", "set_seed", "set_strategy", "subtract", "subtract_assign", "swap", "sync", "this", "this_class", "this_code", "thorn", "thorn_int", "triangle", "triangle_int", "triangle_symm", "true", "uniform", "uniform_int", "uniform_symm", "up_slope", "up_slope_int", "xor" };
			for (const char* m_Initializer : m_Initializers)
			{
				uint32_t m_Hash;
				m_oCreate(&m_Hash, m_Initializer, 0xFFFFFFFF, 0x1);
				m_CompiledMap[m_Hash] = m_Initializer;
			}
		}

		std::string FindCompiled(uint32_t m_Hash)
		{
			if (m_CompiledMap.empty())
				InitializeCompiledMap();

			if (m_CompiledMap.find(m_Hash) == m_CompiledMap.end())
				return "";

			return m_CompiledMap[m_Hash];
		}

		std::string Find(uint32_t m_Hash)
		{
			if (m_Map.find(m_Hash) == m_Map.end())
				return FindCompiled(m_Hash);

			return m_Map[m_Hash];
		}
	}

	namespace SSClass_
	{
		typedef void(__fastcall* m_tregister_method_func)(SSClass*, uint32_t*, void*, uint32_t);
		m_tregister_method_func m_oregister_method_func;

		void __fastcall register_method_func(SSClass* rcx, uint32_t* method_name, void* method, uint32_t flags)
		{
			std::string m_MethodName = ASymbol_::Find(*method_name);
			if (!m_MethodName.empty())
			{
				Resolver::Class_t* m_Class = Resolver::GetClass(rcx);
				m_Class->NewMethod(method, m_MethodName);
			}

			m_oregister_method_func(rcx, method_name, method, flags);
		}
	}

	namespace SSBrain_
	{
		void ResolveClass(SSClass* m_SSClass)
		{
			if (!m_SSClass)
				return;

			std::string m_ClassName = ASymbol_::Find(m_SSClass->m_Name);
			if (m_ClassName.empty())
				return;

			Resolver::NewClass(m_SSClass, m_ClassName);
		}

		typedef SSClass* (__fastcall* m_tCreateClass)(uint32_t*, SSClass*, unsigned int, bool);
		m_tCreateClass m_oCreateClass;

		SSClass* __fastcall CreateClass(uint32_t* class_name, SSClass* superclass_p, unsigned int flags, bool append_super_members)
		{
			SSClass* m_Ret = m_oCreateClass(class_name, superclass_p, flags, append_super_members);
			ResolveClass(m_Ret);

			return m_Ret;
		}

		typedef SSClass*(__fastcall* m_tGetClass)(const char* class_name_p);
		m_tGetClass m_oGetClass;

		SSClass* __fastcall GetClass(const char* class_name_p)
		{
			SSClass* m_Ret = m_oGetClass(class_name_p);
			ResolveClass(m_Ret);

			return m_Ret;
		}

		std::vector<SSClass*> GetClassList()
		{
			int m_Count			= *reinterpret_cast<int*>(SKOOKUMPWNER_SSBRAIN_CLASSES);
			SSClass** m_Array	= *reinterpret_cast<SSClass***>(SKOOKUMPWNER_SSBRAIN_CLASSES + 0x8);

			std::vector<SSClass*> m_Ret;
			for (int i = 0; m_Count > i; ++i)
				m_Ret.emplace_back(m_Array[i]);
			
			return m_Ret;
		}
	}

	DWORD __stdcall MainThread(void* m_Reserved)
	{
		while (1)
		{
			bool m_DumpClasses = false;
			if (m_DumpClasses)
			{
				FILE* m_File = nullptr;
				fopen_s(&m_File, "dbg\\script_classes.h", "w");
				if (m_File)
				{
					char m_FileOutput[256];

					for (auto& m_ClassMap : Resolver::m_ClassList)
					{
						auto& m_Class = m_ClassMap.second;
						if (m_Class.m_Methods.empty())
							continue;

						for (auto& m_ClassMethod : m_Class.m_Methods)
							fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "%s.%s()\n", m_Class.m_Name.c_str(), m_ClassMethod.second.m_Name.c_str()), m_File);

						fwrite("\n", 1, 1, m_File);
					}

					fclose(m_File);
				}

				Resolver::m_ClassList = Resolver::m_ClassList;
				bool debug = true;
			}

			Sleep(1);
		}

		return 0;
	}

	struct HookInfo_t
	{
		uintptr_t m_Function = 0;
		void* m_Hook = nullptr;
		void** m_Original = nullptr;

		HookInfo_t(uintptr_t func, void* hook, void** original)
		{
			m_Function = func;
			m_Hook = hook;
			m_Original = original;
		}
	};

	std::vector<HookInfo_t> m_HookInfoList = 
	{ 
		{ SKOOKUMPWNER_ASYMBOL_CREATE, ASymbol_::Create, (void**)&ASymbol_::m_oCreate },
		{ SKOOKUMPWNER_SSCLASS_REGISTERMETHODFUNC, SSClass_::register_method_func, (void**)&SSClass_::m_oregister_method_func },
		{ SKOOKUMPWNER_SSBRAIN_CREATECLASS, SSBrain_::CreateClass, (void**)&SSBrain_::m_oCreateClass },
		{ SKOOKUMPWNER_SSBRAIN_GETCLASS_CHAR, SSBrain_::GetClass, (void**)&SSBrain_::m_oGetClass }
	};
}
#pragma once

class AMemoryInfo
{
public:
	const char* i_type_cstr_p;
	u32 i_type_id;
	u32 i_size_static;
	u32 i_size_debug;
	u32 i_alloc_count;
	u32 i_size_dynamic_total;
	u32 i_size_dynamic_total_actual;
};

class AMemoryInfoList : public APSorted<AMemoryInfo>
{
public:
};

class AMemoryStats
{
public:
	enum eTrack
	{
		Track_type,
		Track_needed
	};

	eTrack i_track;
	u32 i_size_needed;
	u32 i_size_needed_debug;
	AMemoryInfoList* i_info_list_p;
};
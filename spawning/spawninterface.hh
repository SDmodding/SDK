#pragma once

namespace UFG
{
	class SpawnInfoInterface 
	{
	public:
		enum SpawnPriority : int
		{
			High = 1,
			Medium,
			Low,
			Critical,
			NumSpawnPriorities
		};
	};
}
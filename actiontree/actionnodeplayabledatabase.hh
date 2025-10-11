#pragma once

class ActionNodePlayableDataBase
{
public:
	class ActionNodePlayableRecord : public UFG::qNodeRB64<ActionNodePlayableRecord>
	{
	public:
		ActionNodePlayable* mPlayable;
	};

	UFG::qTreeRB64<ActionNodePlayableRecord> mPlayables;

	/* Static Members */

	SDK_VINLINE qGlobalVar<ActionNodePlayableDataBase*, 0x23B1310> msActionNodePlayableDataBase;
};
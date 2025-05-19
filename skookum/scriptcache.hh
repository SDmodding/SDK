#pragma once

namespace UFG::ScriptCache
{
	class Script : public qNodeRB<Script>
	{
	public:
		int mRefCount;
		SSCode* mpScriptCode;
		SSClass* mpClassScope;
	};
}
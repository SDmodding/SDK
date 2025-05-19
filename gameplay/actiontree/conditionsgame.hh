#pragma once

class SkookumCondition : public Condition
{
public:
	BinString mClassScopeText;
	BinString mSkookumScriptRaw;
	UFG::ScriptCache::Script* mpScript;
};
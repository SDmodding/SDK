#pragma once

class HasClothingBuffCondition : public Condition
{
public:
	qEnum<UFG::eClothingBuffEnum, u8> mBuffType;
};

class SkookumCondition : public Condition
{
public:
	BinString mClassScopeText;
	BinString mSkookumScriptRaw;
	UFG::ScriptCache::Script* mpScript;
};
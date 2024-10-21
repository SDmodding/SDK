#pragma once

class ActionID
{
public:
	u32 mUID;
};

class ActionPath
{
public:
	BinArray<ActionID> mPath;
};

#pragma once

class Condition : public Expression::IMemberMap
{
public:
	u32 mPad0;
	u16 mPad1;
	char mPad2;
	char mBreakPoint;
};
SDK_ASSERT_SIZEOF(Condition, 0x18);

class ConditionGroup : public Condition
{
public:
	u64 mSignalMask;
	BinPtrArray<Condition> mConditions;
};
SDK_ASSERT_SIZEOF(ConditionGroup, 0x30);

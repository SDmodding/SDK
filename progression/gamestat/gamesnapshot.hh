#pragma once

namespace UFG
{
	class GameSnapshot
	{
	public:
		PersistentData::Time mTimes[30];
		PersistentData::ID mIDs[44];
		PersistentData::Bool mBools[58];
		PersistentData::Int mInts[163];
		PersistentData::UInt64 mUInt64s[1];
		PersistentData::Float mFloats[139];
		PersistentData::IntRanged mIntsRanged[7];
		PersistentData::FloatRanged mFloatsRanged[1];
		PersistentData::String mStrings[25];
		PersistentData::Binary mBinaries[3];
		PersistentData::MapBool* mpMapBools[93];
		PersistentData::MapInt* mpMapInts[47];
		PersistentData::MapUInt64* mpMapUInt64s[1];
		PersistentData::MapFloat* mpMapFloats[18];
		PersistentData::MapBinary* mpMapBinaries[2];
		PersistentData::List* mpList[1];
	};
	SDK_ASSERT_SIZEOF(GameSnapshot, 0x10F8);
}
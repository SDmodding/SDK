#pragma once

class RigInfo : public Expression::IMemberMap, public UFG::qNode<RigInfo>
{
public:
	u32 mUID;
	BinString mName;
	BinPtrArray<PoseDriver> mPoseDrivers;

	/* Functions */

	void AddToCreature(Creature* creature) { SDK_CALL_FUNC(void, 0x3A1B80, void*, Creature*)(this, creature); }
};
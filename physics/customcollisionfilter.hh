#pragma once

namespace UFG
{
	class FilterNode : public qNode<FilterNode>
	{
	public:
		hkpEntity* entityA;
		hkpEntity* entityB;
	};

	class Stack
	{
	public:
		int mHead;
		int mCapacity;
		u32* mBuffer;
	};

	class CustomCollisionFilter : public hkpGroupFilter, public hkpEntityListener
	{
	public:
		qList<FilterNode> mNonCollidable;
		Stack* mAssignedSystemGroups;
	};
}
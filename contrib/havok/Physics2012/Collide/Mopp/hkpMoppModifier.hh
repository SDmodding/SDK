#pragma once

class hkpMoppModifier
{
public:
	virtual ~hkpMoppModifier() = 0;
	virtual hkBool shouldTerminalBeRemoved(u32 id, const u32* properties) = 0;
	virtual void addTerminalRemoveInfo(int relativeMoppAddress) = 0;
};

class hkpRemoveTerminalsMoppModifier : public hkReferencedObject, public hkpMoppModifier
{
public:
	hkArray<u32> m_removeInfo;
	hkArray<u32>* m_tempShapesToRemove;
};
#pragma once

class hkpWorldDeletionListener
{
public:
	virtual ~hkpWorldDeletionListener() = 0;
	virtual void worldDeletedCallback(hkpWorld* world) = 0;
	virtual void worldRemoveAllCallback(hkpWorld* world) = 0;
};
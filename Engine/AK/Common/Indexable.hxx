#pragma once

class CAkIndexable
{
public:
	void* vfptr;
	CAkIndexable* pNextItem;
	uint32_t key;
	int m_lRef;
};

class CAkAction : public CAkIndexable
{
public:
	CAkAction* m_pNext;
	void* m_props;
	void* m_ranges;
	uint32_t m_ulElementID;
	uint16_t m_eActionType;
	int8_t m_eFadeCurve : 5;
	int8_t m_bWasLoadedFromBank : 1;
	int8_t m_bIsBusElement : 1;
};

class CAkEvent : public CAkIndexable
{
public:
	CAkAction* m_pFirstAction;
	uint32_t m_iPreparationCount;
};
#pragma once

class hkSimplePropertyValue
{
public:
	u64 m_data;
};

class hkSimpleProperty
{
public:
	u32 m_key;
	u32 m_alignmentPadding;
	hkSimplePropertyValue m_value;
};

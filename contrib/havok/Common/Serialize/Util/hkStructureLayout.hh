#pragma once

class hkStructureLayout
{
public:
	struct LayoutRules
	{
		u8 m_bytesInPointer;
		u8 m_littleEndian;
		u8 m_reusePaddingOptimization;
		u8 m_emptyBaseClassOptimization;
	};

	LayoutRules m_rules;

	hkStructureLayout() { SDK_CALL_FUNC(void, 0xE39520, void*)(this); }
};

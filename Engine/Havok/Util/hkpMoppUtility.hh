#pragma once

namespace hkpMoppUtility
{
	hkpMoppCode* BuildCode(hkpShapeContainer* p_ShapeContainer, hkpMoppCompilerInput* p_MoppInput, void* p_ReIndexInfo = nullptr)
	{
		return reinterpret_cast<hkpMoppCode*(__fastcall*)(hkpShapeContainer*, hkpMoppCompilerInput*, void*)>(UFG_RVA(0xD09230))(p_ShapeContainer, p_MoppInput, p_ReIndexInfo);
	}
}
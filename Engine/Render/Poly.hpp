#pragma once

namespace Render
{
	class CPoly
	{
	public:
		CVDynamic* mVertices;

		void Init(float x, float y, float w, float h, float z)
		{
			mVertices = nullptr;
			reinterpret_cast<void(__fastcall*)(void*, float, float, float, float, float)>(UFG_RVA(0x15C30))(this, x, y, w, h, z);
		}

		void SetColors(UFG::qColour* p_Colour0, UFG::qColour* p_Colour1, UFG::qColour* p_Colour2, UFG::qColour* p_Colour3)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::qColour*, UFG::qColour*, UFG::qColour*, UFG::qColour*)>(UFG_RVA(0x162A0))(this, p_Colour0, p_Colour1, p_Colour2, p_Colour3);
		}
	};
}
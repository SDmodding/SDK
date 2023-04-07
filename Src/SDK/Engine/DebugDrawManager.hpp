#pragma once

namespace UFG
{
	/*
	* Note:
	*	- DisableDraw must be "false" in order to render data
	*	- Callstack before game draws our data:
	*		~ CompositeFinalAndDrawUI();
	*		~ DebugDrawManager->FlushContexts();
	*		~ DebugDrawContext->Flush();
	*/
	class CDebugDrawContext
	{
	public:
		static bool* DisableDraw() { return reinterpret_cast<bool*>(UFG_RVA(0x2021C37)); }

		static __inline void ToggleDisableDraw()
		{
			bool* m_DisableDraw = DisableDraw();
			*m_DisableDraw = !(*m_DisableDraw);
		}

		static __inline qMatrix44* GetMatrix() { return reinterpret_cast<qMatrix44*>(UFG_RVA(0x203BD40)); }

		void DrawLine(qVector3 m_Start, qVector3 m_End, qColour m_Color, qMatrix44* m_Matrix = GetMatrix(), void* m_Callback = nullptr, bool m_IsScreenCoords = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, qVector3*, qColour*, qMatrix44*, void*, bool)>(UFG_RVA(0x18640))(this, &m_Start, &m_End, &m_Color, m_Matrix, m_Callback, m_IsScreenCoords);
		}

		void DrawTextA(qVector3 m_Pos, qColour m_Color, const char* m_String)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, qColour*, const char*)>(UFG_RVA(0x18E60))(this, &m_Pos, &m_Color, m_String);
		}
	};

	class CDebugDrawManager
	{
	public:
		// Everything above 3 index is available
		void CreateContext(uint32_t m_Index, int m_MemSize, uint32_t m_FeatureFlags = 0)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, int, uint32_t)>(UFG_RVA(0x17A80))(this, m_Index, m_MemSize, m_FeatureFlags);
		}

		/*
		* 0 - Persistent Main
		* 1 - Persistent Overlay
		* 2 - Main
		* 3 - Overlay
		*/
		CDebugDrawContext* GetContext(uint32_t m_Index)
		{
			return reinterpret_cast<CDebugDrawContext*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x19FD0))(this, m_Index);
		}

		uint32_t GetHighestContextIndex()
		{
			uint32_t m_Index = 0;
			while (GetContext(m_Index))
				++m_Index;

			return m_Index;
		}
	};

	namespace DebugDrawManager
	{
		CDebugDrawManager* Get()
		{
			return *reinterpret_cast<CDebugDrawManager**>(UFG_RVA(0x212B9B8));
		}
	}
}
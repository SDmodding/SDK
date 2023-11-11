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
		static __inline qMatrix44* GetMatrix() { return reinterpret_cast<qMatrix44*>(UFG_RVA(0x203BD40)); }

		void DrawLine(qVector3 m_Start, qVector3 m_End, qColour m_Color, qMatrix44* m_Matrix = GetMatrix(), void* m_Callback = nullptr, bool m_IsScreenCoords = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, qVector3*, qColour*, qMatrix44*, void*, bool)>(UFG_RVA(0x18640))(this, &m_Start, &m_End, &m_Color, m_Matrix, m_Callback, m_IsScreenCoords);
		}

		void DrawAABB(qVector3 m_Min, qVector3 m_Max, qColour m_Color, qMatrix44* m_Matrix = GetMatrix(), void* m_Callback = nullptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, qVector3*, qColour*, qMatrix44*, void*)>(UFG_RVA(0x17C10))(this, &m_Min, &m_Max, &m_Color, m_Matrix, m_Callback);
		}

		void DrawAABB(qVector3 m_Origin, qVector3 m_Min, qVector3 m_Max, qColour m_Color, qMatrix44* m_Matrix = GetMatrix(), void* m_Callback = nullptr)
		{
			UFG::qVector3 m_Points[8] =
			{
				{ m_Origin.x + m_Min.x, m_Origin.y + m_Min.y, m_Origin.z + m_Min.z },
				{ m_Origin.x + m_Min.x, m_Origin.y + m_Max.y, m_Origin.z + m_Min.z},
				{ m_Origin.x + m_Max.x, m_Origin.y + m_Max.y, m_Origin.z + m_Min.z },
				{ m_Origin.x + m_Max.x, m_Origin.y + m_Min.y, m_Origin.z + m_Min.z },
				{ m_Origin.x + m_Min.x, m_Origin.y + m_Min.y, m_Origin.z + m_Max.z },
				{ m_Origin.x + m_Min.x, m_Origin.y + m_Max.y, m_Origin.z + m_Max.z },
				{ m_Origin.x + m_Max.x, m_Origin.y + m_Max.y, m_Origin.z + m_Max.z },
				{ m_Origin.x + m_Max.x, m_Origin.y + m_Min.y, m_Origin.z + m_Max.z }
			};

			DrawLine(m_Points[0], m_Points[1], m_Color, m_Matrix, m_Callback);
			DrawLine(m_Points[1], m_Points[2], m_Color, m_Matrix, m_Callback);
			DrawLine(m_Points[2], m_Points[3], m_Color, m_Matrix, m_Callback);
			DrawLine(m_Points[3], m_Points[0], m_Color, m_Matrix, m_Callback);

			DrawLine(m_Points[4], m_Points[5], m_Color, m_Matrix, m_Callback);
			DrawLine(m_Points[5], m_Points[6], m_Color, m_Matrix, m_Callback);
			DrawLine(m_Points[6], m_Points[7], m_Color, m_Matrix, m_Callback);
			DrawLine(m_Points[7], m_Points[4], m_Color, m_Matrix, m_Callback);


			DrawLine(m_Points[0], m_Points[4], m_Color, m_Matrix, m_Callback);
			DrawLine(m_Points[1], m_Points[5], m_Color, m_Matrix, m_Callback);
			DrawLine(m_Points[2], m_Points[6], m_Color, m_Matrix, m_Callback);
			DrawLine(m_Points[3], m_Points[7], m_Color, m_Matrix, m_Callback);
		}

		void DrawCircle(qVector3 m_Center, float m_Radius, qColour m_Color, qMatrix44* m_Matrix = GetMatrix(), void* m_Callback = nullptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, float, qColour*, qMatrix44*, void*)>(UFG_RVA(0x182F0))(this, &m_Center, m_Radius, &m_Color, m_Matrix, m_Callback);
		}

		// World Position
		void DrawTextA(qVector3 m_Pos, qColour m_Color, const char* m_String)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, qColour*, const char*)>(UFG_RVA(0x18E60))(this, &m_Pos, &m_Color, m_String);
		}

		// Screen Position
		void DrawTextA(int m_X, int m_Y, qColour m_Color, const char* m_String)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, int, qColour*, const char*)>(UFG_RVA(0x18EB0))(this, m_X, m_Y, &m_Color, m_String);
		}

		void DrawSphere(qVector3 m_Center, float m_Radius, qColour m_Color, qMatrix44* m_Matrix = GetMatrix(), void* m_Callback = nullptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, float, qColour*, qMatrix44*, void*)>(UFG_RVA(0x18D00))(this, &m_Center, m_Radius, &m_Color, m_Matrix, m_Callback);
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

		bool* DisableDraw()
		{
			return reinterpret_cast<bool*>(UFG_RVA(0x2021C37));
		}
	}
}
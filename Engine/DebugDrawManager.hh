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
		static UFG_INLINE qMatrix44* GetMatrix() 
		{ 
			return reinterpret_cast<qMatrix44*>(UFG_RVA(0x203BD40)); 
		}

		UFG_INLINE void DrawLine(const qVector3& p_Start, const qVector3& p_End, const qColour& p_Color, qMatrix44* p_Matrix = GetMatrix(), void* p_Callback = nullptr, bool p_IsScreenCoords = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, const qVector3&, const qVector3&, const qColour&, qMatrix44*, void*, bool)>(UFG_RVA(0x18640))(this, p_Start, p_End, p_Color, p_Matrix, p_Callback, p_IsScreenCoords);
		}

		UFG_INLINE void DrawAABB(const qVector3 m_Min, const qVector3 m_Max, const qColour m_Color, qMatrix44* m_Matrix = GetMatrix(), void* m_Callback = nullptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, const qVector3&, const qVector3&, const qColour&, qMatrix44*, void*)>(UFG_RVA(0x17C10))(this, m_Min, m_Max, m_Color, m_Matrix, m_Callback);
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

		UFG_INLINE void DrawCircle(qVector3 m_Center, float m_Radius, qColour m_Color, qMatrix44* m_Matrix = GetMatrix(), void* m_Callback = nullptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, float, qColour*, qMatrix44*, void*)>(UFG_RVA(0x182F0))(this, &m_Center, m_Radius, &m_Color, m_Matrix, m_Callback);
		}

		template<typename FORMAT = const char*, typename... Args>
		UFG_INLINE void DrawTextA(const qVector3& p_WorldPosition, const qColour& p_Colour, FORMAT p_Format, Args... p_Args)
		{
			reinterpret_cast<void(*)(void*, const qVector3&, const qColour&, FORMAT, Args...)>(UFG_RVA(0x18E60))(this, p_WorldPosition, p_Colour, p_Format, p_Args...);
		}

		template<typename FORMAT = const char*, typename... Args>
		UFG_INLINE void DrawTextA(int p_X, int p_Y, const qColour& p_Colour, FORMAT p_Format, Args... p_Args)
		{
			reinterpret_cast<void(*)(void*, int, int, const qColour&, FORMAT, Args...)>(UFG_RVA(0x18EB0))(this, p_X, p_Y, p_Colour, p_Format, p_Args...);
		}

		UFG_INLINE void DrawSphere(qVector3 m_Center, float m_Radius, qColour m_Color, qMatrix44* m_Matrix = GetMatrix(), void* m_Callback = nullptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, float, qColour*, qMatrix44*, void*)>(UFG_RVA(0x18D00))(this, &m_Center, m_Radius, &m_Color, m_Matrix, m_Callback);
		}
	};

	class CDebugDrawManager
	{
	public:
		static UFG_INLINE CDebugDrawManager* Instance() 
		{
			return *reinterpret_cast<CDebugDrawManager**>(UFG_RVA(0x212B9B8));
		}

		// Everything above 3 index is available
		UFG_INLINE void CreateContext(uint32_t m_Index, int m_MemSize, uint32_t m_FeatureFlags = 0)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, int, uint32_t)>(UFG_RVA(0x17A80))(this, m_Index, m_MemSize, m_FeatureFlags);
		}

		/*
		* 0 - Persistent Main
		* 1 - Persistent Overlay
		* 2 - Main
		* 3 - Overlay
		*/
		UFG_INLINE CDebugDrawContext* GetContext(uint32_t m_Index)
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
		UFG_INLINE bool* DisableDraw()
		{
			return reinterpret_cast<bool*>(UFG_RVA(0x2021C37));
		}

		UFG_INLINE void SetDisableDraw(bool p_Value) 
		{
			*DisableDraw() = p_Value;
		}
	}
}
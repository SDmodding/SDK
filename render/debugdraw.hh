#pragma once

namespace UFG
{
	enum eAlphaState
	{
		AlphaState__same			= 0,
		AlphaState_none				= 0x2782CCE6, // Illusion.AlphaState.None
		AlphaState_punch_thru		= 0x2B068C0A, // Illusion.AlphaState.PunchThru
		AlphaState_additive			= 0x69DAE2D1, // Illusion.AlphaState.Additive
		AlphaState_mask				= 0x7C49699C, // Illusion.AlphaState.Mask
		AlphaState_modulated		= 0xA3833FDE, // Illusion.AlphaState.Modulated
		AlphaState_premultiplied	= 0xFAB11CA1  // Illusion.AlphaState.Premultipled
	};

	class DrawInfo
	{
	public:
		UFG::qColour mColour1;
		UFG::qColour mColour2;
		f32 mScale;
		UFG::eAlphaState mAlphaBlend;
		bool mDepthBuffer;
		bool mFaceCull;
		bool mDepthBias;
		void(__fastcall* mPreDrawCallback)(Illusion::Material*, Render::View*, Illusion::StateValues*, Illusion::Primitive*, Illusion::StateArgs*);
	};

	class XRayDrawInfo : public DrawInfo {};
}

namespace Render
{
	SDK_VINLINE qGlobalVar<bool, 0x2021C37> gDisableDebugDraw;

	namespace eDebugOutput
	{
		enum Enum
		{
			Off,
			Performance,
			CullingResults
		};
	}

	enum DebugPrimType
	{
		DebugPrim_Point,
		DebugPrim_LineStrip,
		DebugPrim_LineSegment,
		DebugPrim_Triangle,
		DebugPrim_TriangleStrip,
		DebugPrim_TriangleFan
	};

	class DebugAABB : public UFG::qNode<DebugAABB>
	{
	public:
		UFG::qMatrix44* m_LocalWorld;
		UFG::qColour m_Colour;
		UFG::qVector3 m_Min;
		UFG::qVector3 m_Max;
		void(__fastcall* m_PreDrawCallback)(Illusion::Material*, View*, Illusion::StateValues*, Illusion::Primitive*, Illusion::StateArgs*);
	};

	class DebugArc : public UFG::qNode<DebugArc>
	{
	public:
		UFG::qMatrix44* m_LocalWorld;
		f32 m_Radius;
		f32 m_MinAngle;
		f32 m_MaxAngle;
		UFG::qColour m_Colour;
		void(__fastcall* m_PreDrawCallback)(Illusion::Material*, View*, Illusion::StateValues*, Illusion::Primitive*, Illusion::StateArgs*);
	};

	class DebugAxis : public UFG::qNode<DebugAxis>
	{
	public:
		UFG::qMatrix44 mLocalWorld;
		float mScale;
		bool mDepthBuffer;
		void(__fastcall* m_PreDrawCallback)(Illusion::Material*, View*, Illusion::StateValues*, Illusion::Primitive*, Illusion::StateArgs*);
	};

	class DebugCircle : public UFG::qNode<DebugCircle>
	{
	public:
		UFG::qMatrix44* m_LocalWorld;
		f32 m_Radius;
		UFG::qVector3 m_Centre;
		UFG::qVector3 m_Normal;
		UFG::qColour m_Colour;
		void(__fastcall* m_PreDrawCallback)(Illusion::Material*, View*, Illusion::StateValues*, Illusion::Primitive*, Illusion::StateArgs*);
	};

	class DebugCylinder : public UFG::qNode<DebugCylinder>
	{
	public:
		UFG::qMatrix44* m_LocalWorld;
		UFG::qVector3 m_Min;
		UFG::qVector3 m_Max;
		f32 m_Radius;
		UFG::qColour m_Colour;
		void(__fastcall* m_PreDrawCallback)(Illusion::Material*, View*, Illusion::StateValues*, Illusion::Primitive*, Illusion::StateArgs*);
	};

	class DebugDecalRadius
	{
	public:
		UFG::qBox boxQuery;
		f32 radius;
		f32 time;
	};

	class DebugIcon : public UFG::qNode<DebugIcon>
	{
	public:
		u32 mTextureUID;
		f32 mX;
		f32 mY;
		f32 mW;
		f32 mH;
		UFG::qColour mColour;
	};

	class DebugLayer
	{
	public:
		eDebugOutput::Enum mOutput;
		eDebugOutput::Enum mOutputAllMaterials;
		bool mIsolateMaterial;
	};

	class DebugLineStrip : public UFG::qNode<DebugLineStrip>
	{
	public:
		UFG::qVector3* m_Points;
		UFG::qMatrix44* m_LocalWorld;
		int m_NumPoints;
		UFG::DrawInfo m_DrawInfo;
	};

	class DebugRect : public UFG::qNode<DebugRect>
	{
	public:
		f32 mX;
		f32 mY;
		f32 mW;
		f32 mH;
		UFG::qColour mColour;
	};

	class DebugSphere : public UFG::qNode<DebugSphere>
	{
	public:
		UFG::qMatrix44* m_LocalWorld;
		f32 m_Radius;
		UFG::qVector3 m_Centre;
		UFG::qColour m_Colour;
		void(__fastcall* m_PreDrawCallback)(Illusion::Material*, View*, Illusion::StateValues*, Illusion::Primitive*, Illusion::StateArgs*);
	};

	class DebugText : public UFG::qNode<DebugText>
	{
	public:
		const char* mText;
		FontHandle* mFont;
		UFG::qColour mColour;
		int mIsWorldSpace;
		u32 mAlignment;
		UFG::qVector3 mPos;
	};

	class DebugTriStrip : public UFG::qNode<DebugTriStrip>
	{
	public:
		int mNumPoints;
		UFG::DrawInfo mDrawInfo;
		UFG::qMatrix44* mLocalWorld;
		UFG::qVector3* mPoints;
		f32 mSortMetric;
		bool mInFront;
	};

	class DebugData
	{
	public:
		FontHandle mDebugFontHandle;
		UFG::qList<DebugText> mDebugTextLines;
		UFG::qList<DebugRect> mDebugRects;
		UFG::qList<DebugIcon> mDebugIcons;
		UFG::qList<DebugLineStrip> mDebugLineStrips;
		UFG::qList<DebugTriStrip> mDebugTriStrips;
		UFG::qList<DebugAABB> mDebugAABB;
		UFG::qList<DebugSphere> mDebugSphere;
		UFG::qList<DebugCylinder> mDebugCylinder;
		UFG::qList<DebugCircle> mDebugCircle;
		UFG::qList<DebugArc> mDebugArc;
		UFG::qList<DebugAxis> mDebugAxis;
		u32 mHaveExceededPool;
		s8* mDebugPool;
		__declspec(align(64)) UFG::qLinearAllocator mDebugMemory;
		u32 mDebugPoolSize;
	};

	class DebugDrawContext : public UFG::qNode<DebugDrawContext>
	{
	public:
		enum eAlign
		{
			AlignHoriz_left		= (1 << 0),
			AlignHoriz_center	= (1 << 1),
			AlignHoriz_right	= (1 << 2),
			AlignVert_top		= (1 << 3),
			AlignVert_center	= (1 << 4),
			AlignVert_bottom	= (1 << 5),
			Align__default		= AlignHoriz_left | AlignVert_top,
		};

		u32 mUID;
		u32 mFeatureFlags;
		View* mView;
		int mTargetWidth;
		int mTargetHeight;
		DebugData* mDebugData;
		u32 mFrame;

		/* Functions */

		void Clear() { SDK_CALL_FUNC(void, 0x177F0, void*)(this); }

		void DrawAABB(const UFG::qVector3& aabb_min, const UFG::qVector3& aabb_max, const UFG::qColour& colour, const UFG::qMatrix44* local_world = &UFG::qMatrix44::msIdentity, void* pre_draw_callback = 0) {
			SDK_CALL_FUNC(void, 0x17C10, void*, const UFG::qVector3&, const UFG::qVector3&, const UFG::qColour&, const UFG::qMatrix44*, void*)(this, aabb_min, aabb_max, colour, local_world, pre_draw_callback);
		}

		void DrawArc(f32 radius, f32 minAngle, f32 maxAngle, const UFG::qColour& colour, const UFG::qMatrix44* local_world = &UFG::qMatrix44::msIdentity, void* pre_draw_callback = 0) {
			SDK_CALL_FUNC(void, 0x17D40, void*, f32, f32, f32, const UFG::qColour&, const UFG::qMatrix44*, void*)(this, radius, minAngle, maxAngle, colour, local_world, pre_draw_callback);
		}

		void DrawCircle(const UFG::qVector3& centre, f32 radius, const UFG::qColour& colour, const UFG::qMatrix44* local_world = &UFG::qMatrix44::msIdentity, void* pre_draw_callback = 0) {
			SDK_CALL_FUNC(void, 0x182F0, void*, const UFG::qVector3&, f32, const UFG::qColour&, const UFG::qMatrix44*, void*)(this, centre, radius, colour, local_world, pre_draw_callback);
		}

		void DrawCircle(const UFG::qVector3& centre, const UFG::qVector3& normal, f32 radius, const UFG::qColour& colour, const UFG::qMatrix44* local_world = &UFG::qMatrix44::msIdentity, void* pre_draw_callback = 0) {
			SDK_CALL_FUNC(void, 0x181E0, void*, const UFG::qVector3&, const UFG::qVector3&, f32, const UFG::qColour&, const UFG::qMatrix44*, void*)(this, centre, normal, radius, colour, local_world, pre_draw_callback);
		}

		void DrawCoord(const UFG::qMatrix44& xform, f32 scale, const char* text = 0) { SDK_CALL_FUNC(void, 0x18350, void*, const UFG::qMatrix44&, f32, const char*)(this, xform, scale, text); }

		void DrawCylinder(const UFG::qVector3& min, const UFG::qVector3& max, f32 radius, const UFG::qColour& colour, const UFG::qMatrix44* local_world = &UFG::qMatrix44::msIdentity, void* pre_draw_callback = 0) {
			SDK_CALL_FUNC(void, 0x18500, void*, const UFG::qVector3&, const UFG::qVector3&, f32, const UFG::qColour&, const UFG::qMatrix44*, void*)(this, min, max, radius, colour, local_world, pre_draw_callback);
		}

		void DrawLine(const UFG::qVector3& p0, const UFG::qVector3& p1, const UFG::qColour& colour, const UFG::qMatrix44* local_world = &UFG::qMatrix44::msIdentity, void* pre_draw_callback = 0, bool is_screen_coords = false) {
			SDK_CALL_FUNC(void, 0x18640, void*, const UFG::qVector3&, const UFG::qVector3&, const UFG::qColour&, const UFG::qMatrix44*, void*, bool)(this, p0, p1, colour, local_world, pre_draw_callback, is_screen_coords);
		}

		void DrawLineStrip(const UFG::qVector3& line_points, int num_points, const UFG::DrawInfo& info, const UFG::qMatrix44* local_world = &UFG::qMatrix44::msIdentity) {
			SDK_CALL_FUNC(void, 0x18760, void*, const UFG::qVector3&, int, const UFG::DrawInfo&, const UFG::qMatrix44*)(this, line_points, num_points, info, local_world);
		}

		void DrawLineStrip(const UFG::qVector3& line_points, int num_points, const UFG::qColour& colour, const UFG::qMatrix44* local_world = &UFG::qMatrix44::msIdentity, void* pre_draw_callback = 0) {
			SDK_CALL_FUNC(void, 0x188A0, void*, const UFG::qVector3&, int, const UFG::qColour&, const UFG::qMatrix44*, void*)(this, line_points, num_points, colour, local_world, pre_draw_callback);
		}

		void DrawPillar(const UFG::qVector3& position, f32 radius, f32 height, const UFG::qColour& colour, const UFG::qMatrix44* localWorld = &UFG::qMatrix44::msIdentity, void* preDrawCallback = 0) {
			SDK_CALL_FUNC(void, 0x18A50, void*, const UFG::qVector3&, f32, f32, const UFG::qColour&, const UFG::qMatrix44*, void*)(this, position, radius, height, colour, localWorld, preDrawCallback);
		}

		void DrawPoint(const UFG::qVector3& point, const UFG::qColour& colour, const UFG::qMatrix44* local_world = &UFG::qMatrix44::msIdentity, void* pre_draw_callback = 0) {
			SDK_CALL_FUNC(void, 0x18B70, void*, const UFG::qVector3&, const UFG::qColour&, const UFG::qMatrix44*, void*)(this, point, colour, local_world, pre_draw_callback);
		}

		void DrawRect(f32 x, f32 y, f32 w, f32 h, const UFG::qColour& colour) { SDK_CALL_FUNC(void, 0x18C10, void*, f32, f32, f32, f32, const UFG::qColour&)(this, x, y, w, h, colour); }

		void DrawSphere(const UFG::qVector3& centre, f32 radius, const UFG::qColour& colour, const UFG::qMatrix44* local_world = &UFG::qMatrix44::msIdentity, void* pre_draw_callback = 0) {
			SDK_CALL_FUNC(void, 0x18D00, void*, const UFG::qVector3&, f32, const UFG::qColour&, const UFG::qMatrix44*, void*)(this, centre, radius, colour, local_world, pre_draw_callback);
		}

		template <typename... Args>
		void DrawText(const UFG::qVector3& world_position, const UFG::qColour& colour, const char* format, Args... args) {
			SDK_CALL_FUNC(void, 0x18E60, void*, const UFG::qVector3&, const UFG::qColour&, const char*, Args...)(this, world_position, colour, format, args...);
		}

		template <typename... Args>
		void DrawTextA(int x, int y, const UFG::qColour& colour, const char* format, Args... args) {
			SDK_CALL_FUNC(void, 0x18EB0, void*, int, int, const UFG::qColour&, const char*, Args...)(this, x, y, colour, format, args...);
		}

		template <typename... Args>
		void DrawTextAligned(const UFG::qVector3& world_position, u32 align_flags, FontHandle& fontName, const UFG::qColour& colour, const char* format, Args... args) {
			SDK_CALL_FUNC(void, 0x18F00, void*, const UFG::qVector3&, u32, FontHandle&, const UFG::qColour&, const char*, Args...)(this, world_position, align_flags, fontName, colour, format, args...);
		}

		template <typename... Args>
		void DrawTextAligned(int x, int y, u32 align_flags, FontHandle& fontName, const UFG::qColour& colour, const char* format, Args... args) {
			SDK_CALL_FUNC(void, 0x18F40, void*, int, int, u32, FontHandle&, const UFG::qColour&, const char*, Args...)(this, x, y, align_flags, fontName, colour, format, args...);
		}

		void DrawTextArgs(const UFG::qVector3& world_position, u32 alignment, FontHandle& fontName, const UFG::qColour& colour, char* format, char* args) {
			SDK_CALL_FUNC(void, 0x18F90, void*, const UFG::qVector3&, u32, FontHandle&, const UFG::qColour&, char*, char*)(this, world_position, alignment, fontName, colour, format, args);
		}

		void DrawTextArgs(int x, int y, u32 alignment, FontHandle& fontName, const UFG::qColour& colour, char* format, char* args) {
			SDK_CALL_FUNC(void, 0x19110, void*, int, int, u32, FontHandle&, const UFG::qColour&, char*, char*)(this, x, y, alignment, fontName, colour, format, args);
		}

		void DrawTriStrip(const UFG::qVector3& tri_points, int num_points, const UFG::DrawInfo& info, const UFG::qMatrix44* local_world = &UFG::qMatrix44::msIdentity, bool is_screen_coords = false) {
			SDK_CALL_FUNC(void, 0x19290, void*, const UFG::qVector3&, int, const UFG::DrawInfo&, const UFG::qMatrix44*, bool)(this, tri_points, num_points, info, local_world, is_screen_coords);
		}

		void Flush() { SDK_CALL_FUNC(void, 0x193A0, void*)(this); }
	};

	//-----------------------
	//	Manager
	//-----------------------

	class DebugDrawManager
	{
	public:
		enum DefaultUID
		{
			UID_PersistentMain,
			UID_PersistentOverlay,
			UID_Main,
			UID_Overlay,
			UID_User_Context_Start
		};

		struct InitInfo
		{
			int mPersistentMainSize;
			int mPersistentOverlaySize;
			int mMainSize;
			int mOverlaySize;
		};

		UFG::qList<DebugDrawContext> mContexts;

		/* Static Functions */

		SDK_SINLINE DebugDrawManager* Instance() { return SDK_VAR_GET(DebugDrawManager*, 0x212B9B8); }

		/* Functions */

		void ClearContexts(u32 feature_mask, u32 feature_ref) { SDK_CALL_FUNC(void, 0x17910, void*, u32, u32)(this, feature_mask, feature_ref); }
		DebugDrawContext* CreateContext(u32 uid, u32 mem_size, u32 context_feature_flags) {
			return SDK_CALL_FUNC(DebugDrawContext*, 0x17A80, void*, u32, u32, u32)(this, uid, mem_size, context_feature_flags);
		}
		void FlushContexts(View* view, u32 feature_mask, u32 feature_ref) { SDK_CALL_FUNC(void, 0x19F60, void*, View*, u32, u32)(this, view, feature_mask, feature_ref); }
		DebugDrawContext* GetContext(u32 uid) { return SDK_CALL_FUNC(DebugDrawContext*, 0x19FD0, void*, u32)(this, uid); }
		void SetContextsTargetSize(int width, int height, u32 feature_mask, u32 feature_ref) { SDK_CALL_FUNC(void, 0x1A0B0, void*, int, int, u32, u32)(this, width, height, feature_mask, feature_ref); }
	};
}
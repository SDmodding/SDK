#pragma once

namespace Render
{
	class vDynamic
	{
	public:
		UFG::qVector3 mPosition;
		u16 mTexCoord0[2];
		u16 mTexCoord1[2];
		UFG::qVector3 mNormal;
		UFG::qVector3 mTangent;
		u32 mColour;

		void operator=(const vDynamic&  __that) { return SDK_CALL_FUNC(void, 0xA540, void*, const vDynamic&)(this, __that); }
	};
	SDK_ASSERT_SIZEOF(vDynamic, 0x30);

	//----------------------------------------------------------------------------------
	//	Poly
	//----------------------------------------------------------------------------------

	class Poly
	{
	public:
		Render::vDynamic* mVertices;

		void Init(f32 x, f32 y, f32 w, f32 h, f32 z) { SDK_CALL_FUNC(void, 0x15C30, void*, f32, f32, f32, f32, f32)(this, x, y, w, h, z); }

		void SetUVs(f32 u, f32 v, f32 u_width, f32 v_width) { SDK_CALL_FUNC(void, 0x16960, void*, f32, f32, f32, f32)(this, u, v, u_width, v_width); }

		void SetScreenPos(f32 x, f32 y, f32 w, f32 h, f32 z) { SDK_CALL_FUNC(void, 0x16520, void*, f32, f32, f32, f32, f32)(this, x, y, w, h, z); }

		void SetScreenPos(const UFG::qVector2& p0, const UFG::qVector2& p1, const UFG::qVector2& p2, const UFG::qVector2& p3, f32 z) { 
			SDK_CALL_FUNC(void, 0x16440, void*, const UFG::qVector2&, const UFG::qVector2&, const UFG::qVector2&, const UFG::qVector2&, f32)(this, p0, p1, p2, p3, z);
		}

		void SetColour(const UFG::qColour& colour) { SDK_CALL_FUNC(void, 0x161F0, void*, const UFG::qColour&)(this, colour); }

		void SetColours(const UFG::qColour& colour0, const UFG::qColour& colour1, const UFG::qColour& colour2, const UFG::qColour& colour3) { 
			SDK_CALL_FUNC(void, 0x162A0, void*, const UFG::qColour&, const UFG::qColour&, const UFG::qColour&, const UFG::qColour&)(this, colour0, colour1, colour2, colour3); 
		}
	};

	class PolyStrip : public UFG::qNode<PolyStrip>
	{
	public:
		void* mUserData;
		vDynamic mPrevVertL;
		vDynamic mPrevVertR;
		vDynamic mVerts[48];
		int mNumVerts;
		u32 mShaderUID;
		u32 mTextureUID;
		u32 mSettingsUID;
		f32 mTimeOfCreation;
		f32 mLifeTime;
	};
	SDK_ASSERT_SIZEOF(PolyStrip, 0x990);

	//----------------------------------------------------------------------------------
	//	View
	//----------------------------------------------------------------------------------

	class __declspec(align(8)) ViewSettings
	{
	public:
		UFG::qMatrix44 mWorldView;
		UFG::qMatrix44 mProjection;
		int mCullIndex;
		f32 mCullPixelDensityThreshold;
		f32 mCullPixelDistanceBias;
	};
	SDK_ASSERT_SIZEOF(ViewSettings, 0x90);

	class View
	{
	public:
		ViewSettings* mSettings;
		Illusion::SubmitContext* mSubmitContext;
		UFG::qVector4 mFrustumPlanes[6];
		ViewMetrics mViewMetrics;
		u32 mLastBeginFrameCounter;
		__declspec(align(16)) UFG::qMatrix44 mWorldViewProjection;
		UFG::qMatrix44 mViewWorld;
		f32 mExtractedNearPlane;
		f32 mExtractedFarPlane;

		/* Static Functions */

		SDK_SINLINE Illusion::Material* CreateSimpleMaterial(u32 texture_name_uid, u32 raster_state_uid, u32 alpha_state_uid, bool depth_bias) { 
			return SDK_CALL_FUNC(Illusion::Material*, 0xD590, u32, u32, u32, bool)(texture_name_uid, raster_state_uid, alpha_state_uid, depth_bias);
		}

		/* Functions */

		void Clear(const UFG::qColour& colour, u32 flags, f32 depth, u32 stencil) { 
			SDK_CALL_FUNC(void, 0xD4D0, void*, const UFG::qColour&, u32, f32, u32)(this, colour, flags, depth, stencil);
		}

		u32 Draw(const Illusion::ModelHandle& model_handle, const UFG::qMatrix44& local_world, bool do_clip, Illusion::Material* force_mat) { 
			return SDK_CALL_FUNC(u32, 0xE420, void*, const Illusion::ModelHandle&, const UFG::qMatrix44&, bool, Illusion::Material*)(this, model_handle, local_world, do_clip, force_mat);
		}

		void Draw(Illusion::Primitive* prim, Illusion::Material* material, const UFG::qMatrix44& local_world) { 
			SDK_CALL_FUNC(void, 0xEB70, void*, Illusion::Primitive*, Illusion::Material*, const UFG::qMatrix44&)(this, prim, material, local_world);
		}

		void Draw(Poly* poly, Illusion::Material* material, const UFG::qMatrix44& local_world) { 
			SDK_CALL_FUNC(void, 0xE880, void*, Poly*, Illusion::Material*, const UFG::qMatrix44&)(this, poly, material, local_world); 
		}

		void Draw(Poly* poly, u32 texture_name_uid, const UFG::qMatrix44& local_world, u32 raster_state_uid, u32 alpha_state_uid) { 
			SDK_CALL_FUNC(void, 0xE830, void*, Poly*, u32, const UFG::qMatrix44&, u32, u32)(this, poly, texture_name_uid, local_world, raster_state_uid, alpha_state_uid); 
		}
	};
	SDK_ASSERT_SIZEOF(View, 0x190);
}
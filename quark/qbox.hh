#pragma once

namespace UFG
{
	class qBox
	{
	public:
		enum eCorner
		{
			Corner_xyz,
			Corner_Xyz,
			Corner_xYz,
			Corner_XYz,
			Corner_xyZ,
			Corner_XyZ,
			Corner_xYZ,
			Corner_XYZ,
			Corner__max_x = Corner_Xyz,
			Corner__max_y = Corner_xYz,
			Corner__max_z = Corner_xyZ
		};

		enum eFace
		{
			Face_none = 0,
			Face_max_x = 1,
			Face_front = 1,
			Face_min_x = 2,
			Face_back = 2,
			Face_max_y = 4,
			Face_left = 4,
			Face_min_y = 8,
			Face_right = 8,
			Face_max_z = 16,
			Face_top = 16,
			Face_min_z = 32,
			Face_bottom = 32
		};

		qVector3 mMin;
		qVector3 mMax;

		/* Functions */

		eFace CycleFaces(eFace face, bool forward) { return SDK_CALL_FUNC(eFace, 0x16B740, eFace, bool)(face, forward); }
		f32 DistanceSqrPoint(const qVector3& pos) { return SDK_CALL_FUNC(f32, 0x16CDF0, void*, const qVector3&)(this, pos); }
		qBox& Enclose(const qVector3& pos) { return SDK_CALL_FUNC(qBox&, 0x209CF0, void*, const qVector3&)(this, pos); }
		qVector3 GetFaceCenter(eFace face) { return SDK_CALL_FUNC(qVector3, 0x170410, void*, eFace)(this, face); }
		const qVector3& GetFaceNormal(eFace face) { return SDK_CALL_FUNC(const qVector3&, 0x1704C0, void*, eFace)(this, face); }
		qVector3 GetRandomPosition() { return SDK_CALL_FUNC(qVector3, 0x23DF00, void*)(this); }
		bool IsHitFaceBottomRay(const qVector3& rayPos, const qVector3& rayDir, qVector3* pHitPos) {
			return SDK_CALL_FUNC(bool, 0x1755E0, void*, const qVector3&, const qVector3&, qVector3*)(this, rayPos, rayDir, pHitPos);
		}
		bool IsHitRay(const qVector3& rayPos, const qVector3& rayDir, eFace* pFace, qVector3* pHitPos) {
			return SDK_CALL_FUNC(bool, 0x1756E0, void*, const qVector3&, const qVector3&, eFace*, qVector3*)(this, rayPos, rayDir, pFace, pHitPos);
		}
		bool IsHitSeg(const qVector3& start, const qVector3& end, eFace* pFace, qVector3* pHitPos) {
			return SDK_CALL_FUNC(bool, 0x175B50, void*, const qVector3&, const qVector3&, eFace*, qVector3*)(this, start, end, pFace, pHitPos);
		}
		qBox& SetRadius(f32 radius) { return SDK_CALL_FUNC(qBox&, 0x17D130, void*, f32)(this, radius); }
		void TranslateFace(eFace face, const qVector3& delta, bool preventInversion) { SDK_CALL_FUNC(void, 0x17E9E0, void*, eFace, const qVector3&, bool)(this, face, delta, preventInversion); }
	};
}
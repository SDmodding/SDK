#pragma once

namespace UFG
{
	class qBezierSplineMemImaged
	{
	public:
		u32 mNumKnots;

		// Is the total length of the spline, calculated as the sum of distances between consecutive knots.
		f32 mLength;

		qOffset64<qBezierKnot*> mKnotTable;
		qOffset64<qBezierLookup*> mLookupTable;

		void ClosestPoint3D_CurveFast(const qVector3& pos, u32 curveIndex, f32* curveT, qVector3& closestPoint) { 
			SDK_CALL_FUNC(void, 0x1685D0, void*, const qVector3&, u32, f32*, qVector3&)(this, pos, curveIndex, curveT, closestPoint);
		}

		qVector3 ClosestPoint3D_Fast(const qVector3& pos, f32* splineT) { return SDK_CALL_FUNC(qVector3, 0x168980, void*, const qVector3&, f32*)(this, pos, splineT); }
		f32 CurveIndexAndCurveTtoSplineT(int curveIndex, f32 curveT) { return SDK_CALL_FUNC(f32, 0x16B690, void*, int, f32)(this, curveIndex, curveT); }
		void FindCurveByLookup(f32 splineT, f32& curveT, u32& curveIndex) { SDK_CALL_FUNC(void, 0x16DCC0, void*, f32, f32&, u32&)(this, splineT, curveT, curveIndex); }
		qVector3 GetPosition(f32 splineT) { return SDK_CALL_FUNC(qVector3, 0x1719F0, void*, f32)(this, splineT); }
		void GetPositionAndTangent(f32 splineT, qVector3* position, qVector3* tangent) { SDK_CALL_FUNC(void, 0x171C70, void*, f32, qVector3*, qVector3*)(this, splineT, position, tangent); }
		qVector3 GetTangent(f32 splineT) { return SDK_CALL_FUNC(qVector3, 0x172930, void*, f32)(this, splineT); }
	};

	class qBezierPathMemImaged
	{
	public:
		u32 mNumSplines;

		// Is the total length of the splines
		f32 mLength;

		qOffset64<qOffset64<qBezierSplineMemImaged*>*> mSplineOffsetTable;

		qVector3 ClosestPoint3D(const qVector3& pos, f32* t = 0) { return SDK_CALL_FUNC(qVector3, 0x168450, void*, const qVector3&, f32*)(this, pos, t); }
		f32 GetPathTFromSplineT(u32 splineIndex, f32 splineT) { return SDK_CALL_FUNC(f32, 0x171620, void*, u32, f32)(this, splineIndex, splineT); }
		u32 GetSplineParameters(f32 pathT, f32* splineT) { return SDK_CALL_FUNC(u32, 0x1723A0, void*, f32, f32*)(this, pathT, splineT); }
	};

	class qBezierPathCollectionMemImaged
	{
	public:
		u32 mNumPaths;
		qOffset64<qOffset64<qBezierPathMemImaged*>*> mPathOffsetTable;

		const qBezierPathMemImaged* GetPath(u32 index) { return SDK_CALL_FUNC(const qBezierPathMemImaged*, 0x172370, void*, u32)(this, index); }
	};
}
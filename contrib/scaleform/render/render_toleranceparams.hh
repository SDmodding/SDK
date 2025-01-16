#pragma once

namespace Scaleform::Render
{
	class ToleranceParams
	{
	public:
		f32 Epsilon;
		f32 CurveTolerance;
		f32 CollinearityTolerance;
		f32 IntersectionEpsilon;
		f32 FillLowerScale;
		f32 FillUpperScale;
		f32 FillAliasedLowerScale;
		f32 FillAliasedUpperScale;
		f32 StrokeLowerScale;
		f32 StrokeUpperScale;
		f32 HintedStrokeLowerScale;
		f32 HintedStrokeUpperScale;
		f32 Scale9LowerScale;
		f32 Scale9UpperScale;
		f32 EdgeAAScale;
		f32 MorphTolerance;
		f32 MinDet3D;
		f32 MinScale3D;
		u32 CurveRecursionLimit;
	};
}
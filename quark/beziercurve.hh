#pragma once

namespace UFG
{
	class qBezierKnot
	{
	public:
		qVector3 vIn;
		qVector3 vKnot;
		qVector3 vOut;
	};

	class qBezierLookup
	{
	public:
		f32 mSplineDistance;
	};

	class qBezierSpline : public qNode<qBezierSpline>
	{
	public:
		qArray<qBezierKnot> mKnots;
		bool bClosed;
	};

	class qBezierPath
	{
	public:
		qList<qBezierSpline> mSplines;
	};
}
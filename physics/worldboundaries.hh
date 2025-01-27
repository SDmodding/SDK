#pragma once

namespace UFG
{
	class WorldBoundaries
	{
	public:
		struct WorldBoundaryNode : qNodeRB<WorldBoundaryNode>
		{
			int mPointIndex;
		};

		qArray<qVector3> mWorldBoundaries;
		qTreeRB<WorldBoundaryNode> mMappings;

		virtual ~WorldBoundaries() = 0;

		/* Functions */

		bool GetSegmentIntersection(const qVector3& a0, const qVector3& a1, const qVector3& b0, const qVector3& b1) {
			return SDK_CALL_FUNC(bool, 0x467090, void*, const qVector3&, const qVector3&, const qVector3&, const qVector3&)(this, a0, a1, b0, b1);
		}
		qVector3 GetSegmentNormal(const qVector3& a, const qVector3& b) { return SDK_CALL_FUNC(qVector3, 0x467320, void*, const qVector3&, const qVector3&)(this, a, b); }
		void Initialize() { SDK_CALL_FUNC(void, 0x4698A0, void*)(this); }
		bool IsOutsideBoundaries(const qVector3& pos, f32 radius, const qVector3& dir, f32& distance) {
			return SDK_CALL_FUNC(bool, 0x46B120, void*, const qVector3&, f32, const qVector3&, f32&)(this, pos, radius, dir, distance);
		}
		bool IsOutsideBoundaries2(const qVector3& pos, f32 radius, const qVector3& dir) {
			return SDK_CALL_FUNC(bool, 0x46AFB0, void*, const qVector3&, f32, const qVector3&)(this, pos, radius, dir);
		}
		void Shutdown() { SDK_CALL_FUNC(void, 0x475F60, void*)(this); }
	};
}
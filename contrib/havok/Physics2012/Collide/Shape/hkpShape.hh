#pragma once

class hkpShape : public hkpShapeBase
{
public:
	struct CalcSizeForSpuInput
	{
		bool m_midphaseAgent3Registered;
		bool m_isFixedOrKeyframed;
		bool m_hasDynamicMotionSaved;
	};

	u64 m_userData;

	virtual const class hkpShapeContainer* getContainer() = 0;

	/// Support for creating bounding volume hierarchies of shapes.
	/// This function returns the maximal extent of a shape along a given direction. The result will be scaled 
	/// by the direction's length.
	/// It is not the same as hkpConvexShape::getSupportingVertex, because the extent does not have to be exact, 
	/// it just has to at least contain the shape. It is for the purposes of creating bounding volumes around 
	/// the shape ( mid-phase ) rather than exact collision detection (narrow-phase).
	/// The default implementation of this function uses the AABB of the shape. For custom shapes, you can get 
	/// a better fit.
	virtual f32 getMaximumProjection(const hkVector4& direction) = 0;

	/// Returns the size of the shape class. The default implementation returns -1 which will force the shape onto the PPU.
	virtual int calcSizeForSpu(const CalcSizeForSpuInput& input, int spuBufferSizeLeft) = 0;
};

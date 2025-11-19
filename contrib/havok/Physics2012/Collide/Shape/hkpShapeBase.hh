#pragma once

typedef u16 hkpVertexId;
typedef u32 hkpShapeKey;

class hkpShapeBase : public hkcdShape
{
public:
	virtual bool isConvex() = 0;

	/// Gets the AABB for the shape given a local to world transform and an extra tolerance.
	virtual void getAabb(const hkTransformf& localToWorld, f32 tolerance, hkAabb& aabbOut) = 0;

	/// Finds the closest intersection between the shape and a ray defined in the shape's local space, starting 
	/// at fromLocal, ending at toLocal. The initial hit fraction in \a output will be used to clip the ray.
	/// The results will be placed in \a output, appending the shape key hierarchy to the current one. 
	/// If there is no hit, \a output remains unchanged.
	/// Implementation notes: For all convex shapes except hkSphere and hkCapsule the radius of the shape will 
	/// be ignored.			
	virtual hkBool castRay(const struct hkpShapeRayCastInput& input, struct hkpShapeRayCastOutput& output) = 0;

	/// Finds the closest intersection between the shape and a ray defined in the shape's local space, starting at fromLocal, ending at toLocal.
	/// This is a callback driven raycast. For each hit found, the hkpRayHitCollector receives a callback with the hit info.
	/// Implementation notes: For all convex shapes except hkSphere and hkCapsule the radius of the shape will be ignored.
	virtual void castRayWithCollector(const struct hkpShapeRayCastInput& input, const class hkpCdBody& cdBody, class hkpRayHitCollector& collector) = 0;

	/// Casts a bundle of rays against the shape.
	virtual hkVector4fComparison castRayBundle(const class hkpShapeRayBundleCastInput& input, class hkpShapeRayBundleCastOutput& output, hkVector4fComparison mask) = 0;

	/// Returns the vertex furthest along a given input direction.
	/// Each vertex must be identifiable by a 16bit vertex id, which must be stored in the result using hkVector4::setInt24W().
	virtual void getSupportingVertex(hkVector4Parameter direction, class hkcdVertex& supportingVertexOut) = 0;

	/// Converts an array of input vertex ids as returned by getSupportingVertex into an array of vertices.
	/// The .w component of the vertices out has to be set to the vertex id using hkVector4::setInt24W().
	virtual void convertVertexIdsToVertices(const hkpVertexId* ids, int numIds, class hkcdVertex* vertexArrayOut) = 0;

	/// This function returns the center point of the convex object.
	virtual void getCentre(hkVector4& centreOut) = 0;

	/// Returns the number of spheres that will be put into the sphereBuffer in the getCollisionSpheres() call.
	virtual int getNumCollisionSpheres() = 0;

	/// Gets a set of spheres representing a simplified shape. For instance, a box could return its eight corners.
	virtual const class hkSphere* getCollisionSpheres(hkSphere* sphereBuffer) = 0;

	/// Called internally to "weld" contact points. This is only called for convex objects that are in a shape collection.
	virtual int weldContactPoint(hkpVertexId* featurePoints, u8& numFeaturePoints, hkVector4& contactPointWs, const hkTransformf* thisObjTransform, const class hkpConvexShape* collidingConvexShape, const hkTransformf* collidingTransform, hkVector4& separatingNormalInOut) = 0;
};

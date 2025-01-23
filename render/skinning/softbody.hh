#pragma once

namespace Render
{
	class PackedPosition
	{
	public:
		i16 x, y, z;
	};

	class VerletCloth : public UFG::qNode<VerletCloth>
	{
	public:
		f32 mPendingTimeStep;
		PackedPosition* mPrevSoftVertPosUnconstrained;
		PackedPosition* mPrevSoftVertPosConstrained;
		u32 mPrevSoftVertPositionsSize;
		u32 mNeedsReset;
		UFG::qMatrix44 mPrevWorld;
	};

	class sSoftbodyParams
	{
	public:
		f32 timestep;
		f32 friction;
		f32 drag;
		f32 noisetime;
		u32 spring_size;
		void* spring_data;
		u32 remapper_size;
		void* remapper_data;
		UFG::qMatrix44 delta_world_transform;
		UFG::qMatrix44 inverse_world_transform;
		UFG::qVector4 winddir;
		UFG::qVector4 accel;
		UFG::qVector4 ground_plane;
		UFG::qVector4 collision_plane_data[4];
		UFG::qVector4 collision_sphere_data[4];
		u32 collision_plane_count;
		u32 collision_sphere_count;
		f32 windspeed;
		u32 soft_indices_count;
		u32 hard_indices_count;
		void* verlet_indices_data;
		void* render_indices_data;
		void* prev_soft_positions_unconstrained_data;
		void* prev_soft_positions_constrained_data;
		bool need_reset;
	};

	class SoftbodyCollisionShape : public UFG::qNode<SoftbodyCollisionShape>
	{
	public:
		virtual void UpdateTransform(const UFG::qMatrix44& initial2local, const UFG::qMatrix44& local2initial) = 0;
		virtual void FillTaskParameters(sSoftbodyParams* output) = 0;
	};

	class Softbody : public UFG::qNode<Softbody>
	{
	public:
		struct CollisionShapeCollection
		{
			UFG::qList<SoftbodyCollisionShape> mShapes;
		};

		CollisionShapeCollection mModelSpaceShapes;
		CollisionShapeCollection mSoftbodySpaceShapes;
		CollisionShapeCollection mWorldSpaceShapes;
		UFG::qMap<VerletCloth*> mModelGuidToClothMap;
		UFG::CompositeDrawableComponent* mCompDrawComp;
		UFG::qVector3 mSystemVelocity;
		bool mSystemVelocityOnceOnly;
		UFG::qMatrix44 mWorld;
		UFG::qMatrix44 mInvWorld;
		UFG::qVector3 mAccel;
		f32 mDrag;
		f32 mFriction;
	};
}
#pragma once

class PoseRecipe
{
public:
	enum Flags
	{
		Flags_ApplyAllAnimTranslations = 1,
	};

	enum PoseDescType
	{
		PoseDescType_RestPose,
		PoseDescType_IdentityPose,
		PoseDescType_Anim,
		PoseDescType_Blend,
		PoseDescType_BlendWeightSet,
		PoseDescType_BlendAdd,
		PoseDescType_BlendAddWeightSet,
		PoseDescType_BlendSub,
		PoseDescType_BlendSubWeightSet,
		PoseDescType_BlendAccum
	};

	struct AnimData
	{
		i8 mAnimType;
		i8 mBlendHint;
		i8 mNumDataChunks;
		i8 mNumTransformTracks;
		i8 mRootRetargetIndex;
		u32 mFrameIndex;
		f32 mFrameDelta;
		u16* mTrackToBoneIndices;
		hkaAnimation::DataChunk* mDataChunks;
	};

	struct AnimDesc
	{
		u32 mIndex;
	};

	struct BlendDesc
	{
		enum BlendType
		{
			NORMAL,
			ADD,
			SUB
		};

		union
		{
			f32 mWeight;
			f32* mPerBoneWeights;
		};
	};

	struct IdentityPoseDesc{};
	struct RestPoseDesc{};

	struct PoseStackEntry
	{
		PoseDescType mType;
		union
		{
			RestPoseDesc mRestPose;
			IdentityPoseDesc mIdentityPose;
			AnimDesc mAnim;
			BlendDesc mBlend;
		};
	};

	struct SkeletonDesc
	{
		u32 mBoneCount;
		hkaBone* mBones;
		hkQsTransformf* mReferencePose;
		const u16* mParentIndices;
	};

	SkeletonDesc mSkelDesc;
	int mBoneUpdateCount;
	u32 mStackCount;
	u32 mAnimDataCount;
	u32 mAnimMemoryHighWaterMark;
	u32 mFlags;
	PoseStackEntry* mPoseStack;
	AnimData* mAnimData;
};

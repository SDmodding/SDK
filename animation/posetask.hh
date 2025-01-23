#pragma once

class PoseTaskInputParams
{
public:
	PoseRecipe mRecipe;
	char* mScratchBuffer;
	u32 mBufferCount;
	u32 mBufferStride;
	u32 mBufferSize;
	UFG::qVector3 mOutputModelSpaceAABBMin;
	UFG::qVector3 mOutputModelSpaceAABBMax;
	hkQsTransformf* mOutputTransforms;
};
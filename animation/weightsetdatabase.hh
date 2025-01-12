#pragma once

class WeightsetEntry : public Expression::IMemberMap
{
public:
	BinString mName;
	f32 mWeight;
};

class Weightset : public Expression::IMemberMap
{
public:
	UFG::qSymbolUC mName;
	BinPtrArray<WeightsetEntry> mWeightsetEntires;
	u32 mRawWeightSetLength;
	u32 mRawWeightSetPaddedLength;
	UFG::qOffset64<f32*> mRawWeightSet;
};

class WeightSetGroup : public Expression::IMemberMap, public UFG::qNode<WeightSetGroup>
{
public:
	BinString mName;
	BinPtrArray<Weightset> mWeightsets;
};
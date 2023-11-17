#pragma once

namespace UFG
{
	class CModelType : public qNode<CModelType>
	{
	public:
		struct SimpleMorphTargets_t
		{
			qResourceHandle mModelHandles[2];
			float mMorphWeights[2];
			uint32_t mNumModelBindings;
		};

		struct SkinnedDecalLayer_t
		{
			uint32_t* mDecalVertSeries;
			class Render_SkinClipInfo* mClipQuery;
			class Render_SkinClipInfo_ClipOutputVertex* mDecalVerts;
			uint32_t mDecalSeriesCount;
			uint32_t mDecalVertCount;
			qResourceHandle mDecalMaterialHandle;
			uint32_t mDecalTaskUID;
			uint32_t mMaxResults;
		};

		struct ModelBindingSkin_t : qNode<ModelBindingSkin_t>
		{
			uint32_t mNumMappedBones;
			char* mSkeletonToModelBoneMap;
			uint32_t mModelUID;
			uint32_t mModelIndex;
			Illusion::CModelProxy mModelProxy;
			SimpleMorphTargets_t* mMorphTargets;
			SkinnedDecalLayer_t* mDecalLayer;
			class Render_Softbody* mSoftbody;
		};

		struct ModelBindingRigid_t : qNode<ModelBindingRigid_t>
		{
			uint32_t mModelUID;
			Illusion::CModelProxy mModelProxy;
			uint32_t mMorphModelUID;
			qResourceHandle mMorphModelHandle;
			uint32_t mNumMappedBones;
			uint32_t mModelIndex;
			uint16_t mBoneID;
			uint16_t mVisible;
		};

		CRigHandle mRigHandle;
		qList<ModelBindingSkin_t> mModelBindingSkinTable;
		qList<ModelBindingRigid_t> mModelBindingRigidTable;
		qList<class VisibilityCommand> mQueuedVisibilityCommands;
		qVector3 mAABBMin;
		qVector3 mAABBMax;
		uint32_t mLastInventoryQueryTransactionNum;

		void AddModelBinding(Illusion::CModelProxy* p_ModelProxy, uint32_t p_ModelIndex = 0, uint32_t p_LOD = 0)
		{
			reinterpret_cast<void(__fastcall*)(void*, Illusion::CModelProxy*, void*, uint32_t, uint32_t)>(UFG_RVA(0x1BF470))(this, p_ModelProxy, nullptr, p_ModelIndex, p_LOD);
		}

		void RemoveModelBinding(Illusion::CModelProxy* p_ModelProxy)
		{
			reinterpret_cast<void(__fastcall*)(void*, Illusion::CModelProxy*)>(UFG_RVA(0x1BFE10))(this, p_ModelProxy);
		}

		void RemoveSkinModelBinding(uint32_t p_Index)
		{
			for (auto i = mModelBindingSkinTable.mNode.mNext; i != &mModelBindingSkinTable.mNode; i = i->mNext)
			{
				if (p_Index)
				{
					--p_Index;
					continue;
				}

				RemoveModelBinding(&i->GetPointer()->mModelProxy);
				break;
			}
		}


		void RemoveRigidModelBinding(uint32_t p_Index)
		{
			for (auto i = mModelBindingRigidTable.mNode.mNext; i != &mModelBindingRigidTable.mNode; i = i->mNext)
			{
				if (p_Index)
				{
					--p_Index;
					continue;
				}

				RemoveModelBinding(&i->GetPointer()->mModelProxy);
				break;
			}
		}

		void RemoveAllSkinModelBindings()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1BFDB0))(this);
		}

		void RemoveAllRigidModelBindings()
		{
			reinterpret_cast<void(__fastcall*)(qList<ModelBindingRigid_t>*)>(UFG_RVA(0x1BEF90))(&mModelBindingRigidTable);
		}

		__inline void RemoveAllModelBindings()
		{
			RemoveAllSkinModelBindings();
			RemoveAllRigidModelBindings();
		}
	};

	UFG_PAD(sizeof(qNode<CModelType>));
}
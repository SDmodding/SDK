#pragma once

namespace Scaleform
{
	// Structs
	namespace GFx
	{
		struct MovieInfo
		{
			uint32_t Version;
			uint32_t Flags;
			int Width;
			int Height;
			float FPS;
			uint32_t FrameCount;
			uint32_t TagCount;
			uint16_t ExporterVersion;
			uint32_t ExporterFlags;
		};
	}

	// Classes
	namespace GFx
	{
		class ASMovieRootBase : public RefCountBase<ASMovieRootBase, 327>
		{
		public:
			class MovieImpl* pMovieImpl;
			void* pASSupport;
			char AVMVersion;
		};

		class Movie : public RefCountBase<Movie, 327>, public StateBag
		{
		public:
			ASMovieRootBase* pASMovieRoot;

			void CreateString(Value* p_Value, const char* p_String)
			{
				reinterpret_cast<void(__fastcall*)(void*, Value*, const char*)>(UFG_RVA(0x8C3AB0))(this, p_Value, p_String);
			}
		};

		class MovieDef : public Resource, public StateBag
		{
		public:
		};

		class MovieImpl : public Movie
		{
		public:
			//Scaleform::GFx::LoadQueueEntry* pLoadQueueHead;
		};

		namespace AS2
		{
			class MovieRoot : public ASMovieRootBase
			{
			public:
				UFG_PAD(0x110);
				/*Scaleform::Ptr<Scaleform::Render::TreeContainer> TopNode;
				Scaleform::Ptr<Scaleform::GFx::ASSupport> pASSupport;
				Scaleform::Ptr<Scaleform::GFx::AS2::MemoryContextImpl> MemContext;
				unsigned int NumAdvancesSinceCollection;
				unsigned int LastCollectionFrame;
				Scaleform::GFx::AS2::MouseListener* pASMouseListener;
				Scaleform::Ptr<Scaleform::GFx::AS2::GlobalContext> pGlobalContext;
				Scaleform::GFx::AS2::Value ExternalIntfRetVal;
				Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo>* pInvokeAliases;
				Scaleform::GFx::AS2::MovieRoot::ActionQueueType ActionQueue;*/

				StringManager BuiltinsMgr;

				UFG_PAD(0x18);
				//Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::Sprite>, 327, Scaleform::ArrayDefaultPolicy> SpritesWithHitArea;

				void CreateObject(Value* p_Value, const char* p_ClassName, Value* p_Args, uint32_t p_NumArgs)
				{
					reinterpret_cast<void(__fastcall*)(void*, Value*, const char*, Value*, uint32_t)>(UFG_RVA(0x6E0A00))(this, p_Value, p_ClassName, p_Args, p_NumArgs);
				}
			};
		}
	}
}
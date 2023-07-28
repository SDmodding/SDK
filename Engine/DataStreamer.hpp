#pragma once

namespace UFG
{
	namespace DataStreamer
	{
		struct Handle_t
		{
			Handle_t* mPrev;
			Handle_t* mNext;
			void* mCallback;
			void* mCallbackParam;
			void* mImpl;
			uint16_t mFlags;
			uint16_t mPriority;
			uint16_t mTargetState;

			void Initialize()
			{
				mPrev = reinterpret_cast<Handle_t*>(&mPrev);
				mNext = reinterpret_cast<Handle_t*>(&mPrev);
				mCallback = nullptr;
				mCallbackParam = nullptr;
				mImpl = nullptr;
				mFlags = static_cast<uint16_t>(0x20000003);
				mTargetState = STATE_EMPTY;
			}

			~Handle_t()
			{

			}

			Handle_t()
			{
				Initialize();
			}

			void Free()
			{
				gMainMemoryPool->Free(this);
			}
		};

		namespace Handle
		{
			Handle_t* New(const char* p_Name)
			{
				Handle_t* m_Handle = reinterpret_cast<Handle_t*>(Malloc(sizeof(Handle_t), p_Name, 0));
				if (m_Handle)
					m_Handle->Initialize();

				return m_Handle;
			}
		}

		bool QueueStream(Handle_t* p_Handle, const char* p_FileName, uint32_t p_DataType, PRIORITY p_Priority, uint32_t p_Flags, void* p_Callback, void* p_CallbackParam)
		{
			return reinterpret_cast<bool(__fastcall*)(Handle_t*, const char*, uint32_t, PRIORITY, uint32_t, void*, void*)>(UFG_RVA(0x22C580))(p_Handle, p_FileName, p_DataType, p_Priority, p_Flags, p_Callback, p_CallbackParam);
		}
	}
}
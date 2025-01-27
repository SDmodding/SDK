#pragma once

enum hkJobType
{
	HK_JOB_TYPE_DYNAMICS,
	HK_JOB_TYPE_COLLIDE,
	HK_JOB_TYPE_COLLISION_QUERY,
	HK_JOB_TYPE_RAYCAST_QUERY,
	HK_JOB_TYPE_ANIMATION_SAMPLE_AND_COMBINE,
	HK_JOB_TYPE_ANIMATION_SAMPLE_AND_BLEND,
	HK_JOB_TYPE_ANIMATION_MAPPING,
	HK_JOB_TYPE_BEHAVIOR,
	HK_JOB_TYPE_CLOTH,
	HK_JOB_TYPE_AI_PATHFINDING,
	HK_JOB_TYPE_AI_VOLUME_PATHFINDING,
	HK_JOB_TYPE_AI_DYNAMIC,
	HK_JOB_TYPE_AI_LOCAL_STEERING,
	HK_JOB_TYPE_AI_GENERATION,
	HK_JOB_TYPE_DESTRUCTION,
	HK_JOB_TYPE_UNIT_TEST,
	HK_JOB_TYPE_CHARACTER_PROXY,
	HK_JOB_TYPE_VEHICLE,
	HK_JOB_TYPE_COLLIDE_STATIC_COMPOUND,
	HK_JOB_TYPE_HAVOK_MAX,
	HK_JOB_TYPE_USER_0 = HK_JOB_TYPE_HAVOK_MAX,
	HK_JOB_TYPE_MAX,
};

class hkExternalJobProfiler
{
public:
	virtual ~hkExternalJobProfiler() = 0;
	virtual void onStartJob(hkJobType t, u32 m_jobSubType) = 0;
	virtual void onEndJob(hkJobType t) = 0;
};

class hkJobQueue
{
public:
	enum JobPopFuncResult
	{
		POP_QUEUE_ENTRY,
		DO_NOT_POP_QUEUE_ENTRY
	};

	enum JobCreationStatus
	{
		JOB_CREATED,
		NO_JOB_CREATED
	};

	enum JobPriority
	{
		JOB_HIGH_PRIORITY,
		JOB_LOW_PRIORITY
	};

	enum JobStatus
	{
		JOB_INVALID = -1,
		GOT_NEXT_JOB,
		NO_JOBS_AVAILABLE,
		ALL_JOBS_FINISHED,
		JOBS_AVAILABLE_BUT_NOT_FOR_CURRENT_ELF,
		SPU_QUIT_ELF
	};

	enum WaitPolicy
	{
		WAIT_UNTIL_ALL_WORK_COMPLETE,
		WAIT_INDEFINITELY
	};

	struct CustomJobType
	{
		hkJobType m_jobType;
		char m_jobSubType;
		char m_queueId;
	};

	struct JobQueueEntry //: hkJob
	{
		char m_data[240];
	};

	struct DynamicData
	{
		i16 m_numActiveJobs[20];
		int m_masterThreadFinishingFlags;
		WaitPolicy m_waitPolicy;
		hkBool m_outOfMemory;
		u16 m_numThreadsWaiting[5];
		//hkQueue<JobQueueEntry> m_jobQueue[25];
	};

	struct JobQueueEntryInput
	{
		/*hkPadSpu<unsigned int> m_jobPriority;
		hkJobQueue::JobQueueEntry m_job;*/
	};

	typedef JobPopFuncResult(__fastcall* JobPopFunc)(hkJobQueue& queue, DynamicData* data, JobQueueEntry& jobIn, JobQueueEntry& jobOut);
	typedef JobCreationStatus(__fastcall* FinishJobFunc)(hkJobQueue& queue, DynamicData* data, const JobQueueEntry& jobIn, JobQueueEntryInput& newJobCreatedOut);

	hkCriticalSection m_criticalSection;
	DynamicData* m_data;
	JobPopFunc m_popJobFunc;
	FinishJobFunc m_finishJobFunc;
	const int m_numJobTypes;
	int m_cpuCacheQueuesBegin;
	int m_cpuCustomQueuesBegin;
	int m_cpuTypesQueuesBegin;
	int m_numJobQueues;
	CustomJobType m_customJobs[2];
	int m_numCustomJobs;
	int m_cpuSemaphoreBegin;
	int m_directMapSemaphoreEnd;
	int m_masterThreadQueue;
	/*hkJobQueueHwSetup m_hwSetup;
	hkBool m_queryRulesAreUpdated;
	hkSemaphore* m_queueSemaphores[5];
	int m_numQueueSemaphores;
	char m_nextQueueToGet[5][27];
	char m_cpuThreadIndexToSemaphoreIndex[12];
	hkJobHandlerFuncs m_jobFuncs[20];
	struct hkSpuJobThreadPool* m_threadPool;
	hkArray<CustomJobTypeSetup> m_customJobSetup;
	hkExternalJobProfiler* m_externalJobProfiler;*/
};
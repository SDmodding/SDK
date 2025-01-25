#pragma once

namespace UFG
{
	enum DaemonType
	{
		DaemonType_Navigation,
		DaemonType_Count
	};

	enum DaemonOutputStatus
	{
		Status_Undefined,
		Status_Submitted,
		Status_Processing,
		Status_Completed,
		Status_Failed
	};

	enum QueryExecutionMode
	{
		Mode_Immediate,
		Mode_Deferred,
		Mode_Continuous,
	};


	class DaemonQueryOutput
	{
	public:
		DaemonType m_id;
		u32 m_internalType;
		DaemonOutputStatus m_status;

		virtual ~DaemonQueryOutput() = 0;
	};

	class DaemonQueryInput
	{
	public:
		DaemonType m_daemonType;
		u32 m_internalType;
		QueryExecutionMode m_mode;
		DaemonQueryOutput* m_pOutput;

		virtual ~DaemonQueryInput() = 0;
	};
}
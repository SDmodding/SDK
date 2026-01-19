#pragma once

namespace UFG
{
	class OSuiteManagerObserver : public qNode<OSuiteManagerObserver>
	{
	public:
		virtual ~OSuiteManagerObserver() = 0;
		virtual void OSuiteManagerConnected(/*OSuite::ZWebServiceClient**/) = 0;
		virtual void OSuiteManagerDisconnected() = 0;
	};
}
#pragma once

namespace UFG
{
	class OnlineId : public qNode<OnlineId>
	{
	public:
		CSteamID m_SteamId;
	};

	class OnlineManagerObserver : public qNode<OnlineManagerObserver>
	{
	public:
		virtual ~OnlineManagerObserver() = 0;
		virtual void NetworkSignedIn() = 0;
		virtual void NetworkSignedOut() = 0;
	};

	class OnlineManager
	{
	public:
		bool m_bInitialized;
		bool m_bSignedIn;
		qList<OnlineManagerObserver> m_lObservers;
		qString mRetreivedDisplayImage;

		virtual void RetreivePlayerDisplayImage(OnlineId onlineId) = 0;
		virtual ~OnlineManager() = 0;
	};
}
#pragma once

namespace UFG
{
	class UIScreenFactoryBase
	{
	public:
		virtual UIScreen* create() = 0;
		virtual ~UIScreenFactoryBase() = 0;
	};

	class UIScreenFactoryNode : public qNodeRB<UIScreenFactoryNode>
	{
	public:
		UIScreenFactoryBase* m_factory;
	};

	class UIScreenFactory
	{
	public:
		qTreeRB<UIScreenFactoryNode> m_factoryList;
		char m_rootDir[128];

		/* Virtual Functions */

		virtual ~UIScreenFactory() = 0;

		/* Functions */

		void addScreenMapping(const char* name, UIScreenFactoryBase* factory) { SDK_CALL_FUNC(void, 0xA292F0, void*, const char*, UIScreenFactoryBase*)(this, name, factory); }
		UIScreen* createScreen(const char* name) { return SDK_CALL_FUNC(UIScreen*, 0xA2A6E0, void*, const char*)(this, name); }
	};
}
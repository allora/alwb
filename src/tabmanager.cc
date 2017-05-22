#include "tabmanager.h"

TabManager::TabManager()
{
    set_title("ALWB");
    set_border_width(1);

    AddTab(true);

    add(m_box);
    m_box.show();
}

TabManager::~TabManager() {}

void TabManager::AddTab(bool changeToNewTab)
{
    auto tabInfo = std::make_shared<TabInfo>();
    tabInfo->isValid = true;
    const char* url = "https://www.google.com";
    tabInfo->tab.LoadURL(url);

    m_tabs.push_back(tabInfo);

    if (changeToNewTab)
        ChangeTab(m_tabs.size() - 1);

    m_box.pack_start(m_tabs[m_activeTabIndex]->tab);
}

void TabManager::DelTab(std::size_t index)
{
    m_tabs.erase(m_tabs.begin()+index);
}

void TabManager::ChangeTab(std::size_t index)
{
    if (index == m_activeTabIndex)
        return;

    m_tabs[m_activeTabIndex]->tab.Disable();
    m_tabs[index]->tab.Enable();

    m_activeTabIndex = index;
}

void TabManager::onOpenLink(const char* url)
{
    m_tabs[m_activeTabIndex]->tab.LoadURL(url);
}

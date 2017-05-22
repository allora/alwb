#ifndef TAB_MANAGER_H
#define TAB_MANAGER_H

#include "tab.h"
#include <vector>
#include <memory>
#include <gtkmm-3.0/gtkmm/box.h>
#include <gtkmm-3.0/gtkmm/window.h>

class TabManager : public Gtk::Window
{
    public:
        TabManager();
        virtual ~TabManager();


    private:
        void AddTab(bool changeToNewTab);
        void DelTab(std::size_t index);
        void ChangeTab(std::size_t index);

        void onOpenLink(const char* url);

    Gtk::Box m_box;
    
    std::size_t m_activeTabIndex = 0;
    std::vector<std::shared_ptr<TabInfo>> m_tabs;
};

#endif // TAB_MANAGER_H

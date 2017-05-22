#ifndef TAB_H
#define TAB_H

#include <gtkmm-3.0/gtkmm/box.h>
#include <webkit2/webkit2.h>
#include <memory>

class Tab : public Gtk::Box
{
    public:
        Tab();
        virtual ~Tab();

        void LoadURL(const char* url);
        void Enable();
        void Disable();
        bool GetIsEnabled();

    bool m_isEnabled;

    WebKitWebContext* m_ctx;
    WebKitSettings* m_config;
    WebKitWebView* m_view;
};

typedef struct
{
    Tab tab;
    bool isValid;
} TabInfo;

#endif // TAB_H

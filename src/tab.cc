#include "tab.h"

Tab::Tab()
{
    m_ctx = webkit_web_context_get_default();
    m_config = webkit_settings_new();

    webkit_settings_set_enable_webgl(m_config, true);

    m_view = WEBKIT_WEB_VIEW(webkit_web_view_new_with_settings(m_config));
    pack_start((*Glib::wrap(GTK_WIDGET(m_view))));
}

Tab::~Tab()
{
}

void Tab::LoadURL(const char* url)
{
    hide();
    webkit_web_view_load_uri(m_view, url);
    show_all();
}

void Tab::Enable()
{
    show_all();
    m_isEnabled = true;
}

void Tab::Disable()
{
    hide();
    m_isEnabled = false;
}

bool Tab::GetIsEnabled()
{
    return m_isEnabled;
}

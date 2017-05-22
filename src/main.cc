#include "tabmanager.h"
#include <gtkmm-3.0/gtkmm/application.h>
//#include <gtkmm-3.0/gtkmm/window.h>
#include <webkit2/webkit2.h>

int main (int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.alwb.example");

    TabManager window;
    window.set_default_size(800, 400);

    return app->run(window);
}

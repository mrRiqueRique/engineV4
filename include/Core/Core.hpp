#include <IO/Window.hpp>

class Core{
    public:
        Core();
        ~Core();
        int onStart();
        int onLoop();
        bool shouldEnd = false;
    private:
        Window* window;
        // cursor
        // keyboard
        // UI elements
};
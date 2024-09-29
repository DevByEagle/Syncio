#include "Syncio/uicore.h"
#include "Syncio/syncio.h"

using Syncio::UICore::WHITE;

int main() {
    Syncio::UICore::UIWindow window("Syncio", 800, 600);
    window.render(WHITE);
    window.mainloop();
    return 0;
}
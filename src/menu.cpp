
#include "menu.hpp"

using namespace geode::prelude;

void MemoryScannerMenu::open() {
    auto alert = FLAlertLayer::create(
        "MEMORY SCANNER",
        "Memory Scanner\n\n"
        "FPS Monitor\n"
        "Player Scanner\n"
        "Object Scanner\n"
        "Log Viewer\n\n"
        "Version 1.0.0",
        "CLOSE"
    );

    if (alert) {
        alert->show();
    }
}

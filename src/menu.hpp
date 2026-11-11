
#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class MemoryScannerMenu : public geode::Popup<> {
protected:
    bool setup() override;

    void showMemory();
    void showLogcat();
    void showPlayer();
    void showObjects();
    void showPerformance();
    void showSettings();

public:
    static MemoryScannerMenu* create();
};

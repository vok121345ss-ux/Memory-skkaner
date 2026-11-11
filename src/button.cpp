
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

#include "menu.hpp"

using namespace geode::prelude;

class $modify(MemoryPlayLayer, PlayLayer) {

    bool init(
        GJGameLevel* level,
        bool useReplay,
        bool dontCreateObjects
    ) {
        if (!PlayLayer::init(
            level,
            useReplay,
            dontCreateObjects
        )) {
            return false;
        }

        auto label = CCLabelBMFont::create(
            "M",
            "bigFont.fnt"
        );

        auto button = CCMenuItemLabel::create(
            label,
            this,
            menu_selector(MemoryPlayLayer::openScanner)
        );

        auto menu = CCMenu::create();

        menu->addChild(button);
        menu->setPosition({0, 0});

        button->setPosition({35.f, 120.f});

        this->addChild(menu, 1000);

        return true;
    }

    void openScanner(CCObject*) {
        MemoryScannerMenu::open();
    }
};

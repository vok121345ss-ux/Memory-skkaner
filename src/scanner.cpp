
#include "scanner.hpp"

#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

namespace memory_scanner {

    static GameStats currentStats;

    GameStats Scanner::getStats() {
        return currentStats;
    }

    void Scanner::updatePlayer(PlayLayer* layer) {
        if (!layer || !layer->m_player1) {
            currentStats.playerAvailable = false;
            return;
        }

        auto position = layer->m_player1->getPosition();

        currentStats.playerX = position.x;
        currentStats.playerY = position.y;
        currentStats.playerAvailable = true;
    }

}

class $modify(MemoryScannerPlayLayer, PlayLayer) {
    void update(float dt) {
        PlayLayer::update(dt);

        memory_scanner::Scanner::updatePlayer(this);
    }
};


#pragma once

#include <Geode/Geode.hpp>

namespace memory_scanner {

    struct GameStats {
        float fps = 0.0f;
        int objectCount = 0;
        float playerX = 0.0f;
        float playerY = 0.0f;
        bool playerAvailable = false;
    };

    class Scanner {
    public:
        static GameStats getStats();
    };

}

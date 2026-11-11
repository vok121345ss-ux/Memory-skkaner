
#include "logcat.hpp"
#include <mutex>
#include <algorithm>

namespace memory_scanner {

    static std::vector<LogEntry> logs;
    static std::mutex logsMutex;
    static bool running = false;

    void Logcat::start() {
        std::lock_guard<std::mutex> lock(logsMutex);

        running = true;

        logs.push_back({
            "START",
            "INFO",
            "Memory Scanner log viewer started"
        });

        geode::log::info("Memory Scanner: Log viewer started");
    }

    void Logcat::stop() {
        std::lock_guard<std::mutex> lock(logsMutex);
        running = false;
    }

    std::vector<LogEntry> Logcat::getLogs() {
        std::lock_guard<std::mutex> lock(logsMutex);
        return logs;
    }

    void Logcat::clear() {
        std::lock_guard<std::mutex> lock(logsMutex);
        logs.clear();
    }

    bool Logcat::isRunning() {
        std::lock_guard<std::mutex> lock(logsMutex);
        return running;
    }

}

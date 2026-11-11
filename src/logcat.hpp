#pragma once

#include <Geode/Geode.hpp>
#include <string>
#include <vector>

namespace memory_scanner {

    struct LogEntry {
        std::string time;
        std::string level;
        std::string message;
    };

    class Logcat {
    public:
        static void start();
        static void stop();
        static std::vector<LogEntry> getLogs();
        static void clear();
        static bool isRunning();
    };

}

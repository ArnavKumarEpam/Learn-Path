#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>

// Logger class 
class Logger {
private:
    std::ofstream logFile;

    std::string getCurrentTimestamp() {
        // to get the current time
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        std::tm* localTime = std::localtime(&currentTime);

        std::ostringstream oss;
        oss << std::put_time(localTime, "[%Y-%m-%d %H:%M:%S]");
        return oss.str();
    }

public:
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::app);

        if (!logFile) { // validation check
            std::cerr << "Error opening log file.\n";
        }
    }

    ~Logger() { // Destructor
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void log(const std::string& message) {
        if (logFile) {
            logFile << getCurrentTimestamp() 
                    << " " 
                    << message 
                    << std::endl;
        }
    }
};

int main() {
    Logger logger("application.log");

    logger.log("Application started.");
    logger.log("User logged in.");
    logger.log("Processing request...");
    logger.log("Application finished.");

    std::cout << "Logs written successfully.\n";

    return 0;
}
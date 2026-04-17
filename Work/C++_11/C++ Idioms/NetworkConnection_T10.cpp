#include "NetworkConnection_T10.h"
#include <iostream>

// Simulated platform-specific/network details are hidden here
struct NetworkConnection::Impl {
    std::string endpoint;
    bool connected;

    Impl(const std::string& ep) : endpoint(ep), connected(false) {
        // Simulate opening a socket or connection
        connected = true;
        std::cout << "[Impl] Connected to " << endpoint << std::endl;
    }
    ~Impl() {
        // Simulate closing the socket/connection
        if (connected) {
            std::cout << "[Impl] Connection to " << endpoint << " closed" << std::endl;
        }
    }
    void sendData(const std::string& data) {
        if (!connected) {
            std::cerr << "[Impl] Not connected!\n";
            return;
        }
        std::cout << "[Impl] Sending data to " << endpoint << ": " << data << std::endl;
    }
};

NetworkConnection::NetworkConnection(const std::string& ep)
    : impl(std::make_unique<Impl>(ep)) {}

NetworkConnection::~NetworkConnection() = default;

bool NetworkConnection::isConnected() const {
    return impl->connected;
}

void NetworkConnection::sendData(const std::string& data) {
    impl->sendData(data);
}

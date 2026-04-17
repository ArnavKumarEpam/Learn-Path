#pragma once
#include <memory>
#include <string>

class NetworkConnection {
public:
    NetworkConnection(const std::string& endpoint);
    ~NetworkConnection();

    bool isConnected() const;
    void sendData(const std::string& data);

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

#include "NetworkConnection_T10.h"
#include <iostream> 

int main() {
    {
        NetworkConnection conn1("127.0.0.1:8080");
        conn1.sendData("Hello, server!");

        NetworkConnection conn2("192.168.1.5:7000");
        conn2.sendData("Quick check");

        // Connections are closed automatically at scope exit
    }
    std::cout << "All connections closed (destructor)." << std::endl;
    return 0;
}

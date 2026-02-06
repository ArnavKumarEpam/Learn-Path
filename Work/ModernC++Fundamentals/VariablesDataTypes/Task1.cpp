#include <iostream>   // instructs preprocessor to include iostream for input/output
#include <iomanip>    // includes boolalpha and formatting tools
using namespace std;  // using all the features of standard library

int main() {
    const char sensorType = 'T';   // const to prevent changing the sensor type
    int sensorId;                  // sensor id is stored in int
    float temperature;             // temperature stored as float
    double humidity;               // humidity stored as double
    bool systemActive;             // system active status
    long battery;                  // battery percentage
    long long packets;             // number of packets received
    unsigned int uptime;            // system uptime
    short int reading;              // sensor reading
    int signalTemp;                 // temporary signal value
    unsigned char signalStrength;   // signal strength (0–255)

    cout << "Enter the sensor Id: " << endl;
    cin >> sensorId;

    cout << "Enter the temperature: " << endl;
    cin >> temperature;

    cout << "Enter the humidity: " << endl;
    cin >> humidity;

    cout << "Is the sensor active or not (1/0 or true/false): " << endl;
    cin >> boolalpha >> systemActive;

    cout << "Enter the battery of the system: " << endl;
    cin >> battery;
    if (battery < 0)
        battery = 0;
    else if (battery > 100)
        battery = 100;

    cout << "Enter the packets received by the system: " << endl;
    cin >> packets;
    if (packets < 0)
        packets = 0;

    cout << "Enter the uptime of the system: " << endl;
    cin >> uptime;

    cout << "Enter the readings of the system: " << endl;
    cin >> reading;

    cout << "Enter the signal strength (0 - 255): " << endl;
    cin >> signalTemp;
    if (signalTemp > 255)
        signalTemp = 255;
    else if (signalTemp < 0)
        signalTemp = 0;

    signalStrength = static_cast<unsigned char>(signalTemp);

    cout << "\nIoT Sensor Report!" << endl;
    cout << "Sensor type: " << sensorType << endl;
    cout << "Sensor id: " << sensorId << endl;
    cout << "Sensor temperature: " << temperature << endl;
    cout << "Sensor humidity: " << humidity << endl;
    cout << "Sensor active status: " << boolalpha << systemActive << endl;
    cout << "Sensor battery: " << battery << "%" << endl;
    cout << "Sensor received packets: " << packets << endl;
    cout << "Sensor uptime: " << uptime << endl;
    cout << "Sensor showing reading: " << reading << endl;
    cout << "Sensor signal strength: " << static_cast<int>(signalStrength) << endl;

    return 0;
}

#include<iostream>
#include <iomanip>
#include<limits>
using namespace std;

int main(){
    cout << "Welcome to eCommerce Shipping Calculator!" << endl;

    double weight;
    cout << "Enter the weight of the package (in kg) [0 - 100kg]: ";
    cin >> weight;

    // Check for invalid numeric input
    if(cin.fail()) {
        cout << "Error: Please enter a valid numeric value for weight." << endl;
        return 0;
    }

    // Check valid weight range
    if(weight <= 0 || weight > 100) {
        cout << "Error: Order weight must be between 0 and 100 kg." << endl;
        return 0;
    }

    // Clear input buffer before reading region
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string regionInput;
    cout << "Enter the shipping region (A/B/C): ";
    getline(cin, regionInput);

    // Ensure single character and valid region
    if(regionInput.length() != 1 || (regionInput[0] != 'A' && regionInput[0] != 'B' && regionInput[0] != 'C')) {
        cout << "Error: Invalid shipping region. Please enter A, B, or C." << endl;
        return 0;
    }

    char region = regionInput[0];
    
    double totalShippingCost = 0.0;
    // Calculating totalShippingCost for region A
    if(region == 'A'){

        if(weight >= 0 && weight <= 2){ // weight <= 2kg
            totalShippingCost += 100.0;
        }

        else if(weight > 2 && weight <= 10){ // 2kg < weight <= 10kg
            totalShippingCost += 200.0;
        }

        else if(weight > 10) { // weight > 10kg
            totalShippingCost += 200.0;
            double extraWeight = weight - 10;
            totalShippingCost += extraWeight * 50.0;
        }
    }
    // Calculating totalShippingCost for region B
    else if(region == 'B'){

        if(weight >= 0 && weight <= 5){ // weight <= 5kg
            totalShippingCost += 300.0;
        }

        else if(weight > 5) { // weight > 5kg
            totalShippingCost += 300.0;
            double extraWeight = weight - 5;
            totalShippingCost += extraWeight * 50.0;
        }
    }
    // Calculating totalShippingCost for region C
    else if(region == 'C'){

        if(weight >= 0 && weight <= 5){ // weight <= 5kg
            totalShippingCost += 500.0;
        }

        else if(weight > 5) { // weight > 5kg
            totalShippingCost += 500.0;
            double extraWeight = weight - 5;
            totalShippingCost += extraWeight * 100.0;
        }
    }

    // Display the shipping totalShippingCost
    cout << "The Total Shipping Cost: Rs. " << fixed << setprecision(2) << totalShippingCost << endl;
    return 0;
}
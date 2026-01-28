#include<iostream>
#include<iomanip>
#include<limits>
#include<climits>
using namespace std;

// ============ FUNCTION: Input Array Elements ============
// Parameters: arr[] (array), size (number of elements)
// Reads integer values from user with validation
void inputArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        while(true){
            cout << "Enter the number " << (i + 1) << ": ";
            
            // Check if input is valid number
            if(!(cin >> arr[i])){
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
                cout << "Invalid input! Please enter a numeric value." << endl;
                continue; // Retry current index
            }
            
            break; // Valid input received
        }
    }
}

// ============ FUNCTION: Calculate Sum of Array Elements ============
// Parameters: arr[] (array), size (number of elements)
// Returns: Sum of all elements
// Used for modular design - can be reused independently
int sumArray(int arr[], int size){
    long long sum = 0; // Use long long to prevent overflow
    
    for(int i = 0; i < size; i++){
        sum += arr[i]; // Add each element to sum
    }
    
    // Check for overflow
    if(sum > INT_MAX){
        cout << "Warning: Sum exceeds INT_MAX. Result may be inaccurate." << endl;
    }
    
    return (int)sum; // Return the total sum
}

// ============ FUNCTION: Calculate Average of Array Elements ============
// Parameters: arr[] (array), size (number of elements)
// Returns: Average as float
// CRITICAL FIX: Cast to float BEFORE division to avoid integer division loss
float calculateAverage(int arr[], int size){
    // Validate input
    if(size == 0){
        return 0.0f;
    }
    
    // Get sum using sumArray function (modular approach)
    int sum = sumArray(arr, size);
    
    // FIXED: Cast sum to float BEFORE division
    // This ensures float division, not integer division
    // Wrong: (float)(sum / size) - divides as integers first, then converts
    // Correct: (float)sum / size - converts to float first, then divides
    return (float)sum / size;
}

// ============ FUNCTION: Find Minimum Element ============
// Parameters: arr[] (array), size (number of elements)
// Returns: Minimum value in array
int findMinimum(int arr[], int size){
    int minVal = arr[0];
    
    for(int i = 1; i < size; i++){
        if(arr[i] < minVal){
            minVal = arr[i];
        }
    }
    
    return minVal;
}

// ============ FUNCTION: Find Maximum Element ============
// Parameters: arr[] (array), size (number of elements)
// Returns: Maximum value in array
int findMaximum(int arr[], int size){
    int maxVal = arr[0];
    
    for(int i = 1; i < size; i++){
        if(arr[i] > maxVal){
            maxVal = arr[i];
        }
    }
    
    return maxVal;
}

// ============ FUNCTION: Display Results ============
// Parameters: arr[] (array), size (number of elements), average (calculated average)
void displayResults(int arr[], int size, float average){
    cout << "\n" << string(60, '=') << endl;
    cout << setw(35) << "ARRAY ANALYSIS RESULTS" << endl;
    cout << string(60, '=') << endl;
    
    cout << "\nArray Elements: ";
    for(int i = 0; i < size; i++){
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << endl;
    
    cout << "\nStatistics:" << endl;
    cout << string(40, '-') << endl;
    cout << "Number of Elements: " << size << endl;
    cout << "Sum of Elements: " << sumArray(arr, size) << endl;
    cout << "Minimum Value: " << findMinimum(arr, size) << endl;
    cout << "Maximum Value: " << findMaximum(arr, size) << endl;
    
    cout << "\nAverage Calculation:" << endl;
    cout << string(40, '-') << endl;
    cout << setprecision(2) << fixed;
    cout << "Average (to 2 decimal places): " << average << endl;
    
    cout << string(60, '=') << "\n" << endl;
}

// ============ FUNCTION: Get Validated Array Size ============
// Returns: Validated positive array size
int getValidArraySize(){
    int size;
    
    while(true){
        cout << "Enter the size of the array: ";
        
        // Check if input is valid
        if(!(cin >> size)){
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
            cout << "Invalid input! Please enter a positive numeric value." << endl;
            continue;
        }
        
        // Validate size is positive
        if(size < 0){
            cout << "Invalid input! Array size must be positive." << endl;
            continue;
        }
        
        // Check for empty array
        if(size == 0){
            cout << "Array size cannot be 0. Please enter a positive value." << endl;
            continue;
        }
        
        // Check for excessively large size that could cause memory issues
        if(size > 100000){
            cout << "Warning: Array size is very large. Proceeding may cause memory issues." << endl;
        }
        
        return size; // Return valid size
    }
}

int main(){
    cout << "=====================================================" << endl;
    cout << setw(40) << "ARRAY AVERAGE CALCULATOR" << endl;
    cout << "=====================================================" << endl;
    cout << "\nThis program calculates statistics for an array of integers.\n" << endl;
    
    // Get validated array size
    int n = getValidArraySize();
    
    // Create array
    int arr[n];
    
    // Input array elements
    cout << "\n--- Enter Array Elements ---" << endl;
    inputArray(arr, n);
    
    // Calculate average
    float average = calculateAverage(arr, n);
    
    // Display comprehensive results
    displayResults(arr, n, average);
    
    return 0;

}
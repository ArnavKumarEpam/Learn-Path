#include<iostream>
#include<cmath>
#include<iomanip>
#include<limits>
using namespace std;

// Function to calculate factorial of a non-negative integer n
// Returns: n! as long long to handle large factorial values
// Example: factorial(5) = 120
// Note: Factorials grow very quickly; be cautious with large values of n
long long factorial(int n){
    // Handle edge case: 0! = 1 and 1! = 1
    if(n == 0 || n == 1){
        return 1;
    }
    
    // Warning: factorials exceed long long capacity at n > 20
    // For n > 20, overflow will occur
    if(n > 20){
        cout << "Warning: Factorial of " << n << " exceeds long long capacity!" << endl;
    }
    
    long long result = 1;
    // Multiply all integers from 2 to n
    for(int i = 2; i <= n; i++){
        result *= i;
    }
    
    return result;
}

// Function to compute the nth term of the Taylor series
// Parameters: x (value for exp), n (term number, starting from 0), prevFact (previous factorial for optimization)
// Formula: (x^n) / n!
// Returns: nth term as float
float term(float x, int n, long long& prevFact){
    // Calculate x^n using repeated multiplication
    float power = 1.0f;
    for(int i = 0; i < n; i++){
        power *= x;
    }
    
    // Optimize: calculate factorial iteratively using previous value
    // Instead of recalculating from 1 each time, multiply by n
    if(n > 0){
        prevFact *= n; // Multiply previous factorial by n to get n!
    }
    long long fact = prevFact;
    
    // Return (x^n) / n!
    // Add small check to avoid division by zero (though factorial won't be 0)
    if(fact == 0) fact = 1;
    
    return power / fact;
}

// Function to compute exp(x) using Taylor series expansion
// Parameters: x (value for exp), terms (number of terms to sum)
// exp(x) = 1 + x + (x^2)/2! + (x^3)/3! + ... (for 'terms' number of terms)
// Returns: approximate value of exp(x)
float expTaylor(float x, int terms){
    // Validate input: must have at least 1 term
    if(terms <= 0){
        cout << "Error: Number of terms must be positive!" << endl;
        return 0.0f;
    }
    
    // Check for excessively large inputs that might cause overflow or precision issues
    if(abs(x) > 100){
        cout << "Warning: Large value of x (" << x << ") may cause numerical instability!" << endl;
    }
    if(terms > 100){
        cout << "Warning: Large number of terms (" << terms << ") may cause overflow!" << endl;
    }
    
    float sum = 0.0f;
    long long prevFact = 1; // Start with 0! = 1
    
    // Sum up the first 'terms' terms of the Taylor series
    // Term n starts from 0 (which gives us the constant 1)
    // Optimization: pass factorial by reference to avoid recalculation
    for(int n = 0; n < terms; n++){
        sum += term(x, n, prevFact);
    }
    
    return sum;
}

// Function to get validated input for x value
// Returns: validated float value for x
float getXValue(){
    float x;
    while(true){
        cout << "Enter the value of x: ";
        
        // Check if input is valid
        if(!(cin >> x)){
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
            cout << "Invalid input! Please enter a valid number." << endl;
            continue;
        }
        
        return x; // Accept any real number
    }
}

// Function to get validated input for number of terms
// Returns: validated positive integer for number of terms
// Note: Maximum recommended value is 50 to avoid overflow in factorial calculations
int getNumTerms(){
    int terms;
    while(true){
        cout << "Enter the number of terms in the series (recommended max: 50): ";
        
        // Check if input is valid
        if(!(cin >> terms)){
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
            cout << "Invalid input! Please enter a valid number." << endl;
            continue;
        }
        
        // Validate that terms is positive
        if(terms <= 0){
            cout << "Invalid input! Number of terms must be greater than 0." << endl;
            continue;
        }
        
        // Warn user if terms exceed safe limit
        if(terms > 50){
            cout << "Note: Using " << terms << " terms may cause factorial overflow or numerical instability." << endl;
            cout << "Proceeding anyway..." << endl;
        }
        
        return terms;
    }
}

// Function to display results with detailed formatting
// Parameters: x (input value), approxValue (computed exp(x)), terms (number of terms used)
void displayResult(float x, float approxValue, int terms){
    cout << "\n" << string(70, '=') << endl;
    cout << setw(40) << "EXPONENTIAL SERIES RESULT" << endl;
    cout << string(70, '=') << endl;
    
    cout << "\nInput Parameters:" << endl;
    cout << string(50, '-') << endl;
    cout << "x value: " << x << endl;
    cout << "Number of terms: " << terms << endl;
    
    cout << "\nResults:" << endl;
    cout << string(50, '-') << endl;
    cout << setprecision(8) << fixed;
    cout << "Approximate exp(x) using Taylor series: " << approxValue << endl;
    
    // Display comparison with built-in exp() function
    float exactValue = exp(x);
    float error = abs(exactValue - approxValue);
    float percentError = (error / exactValue) * 100;
    
    cout << "Exact exp(x) (using built-in exp()):  " << exactValue << endl;
    cout << "Absolute Error: " << error << endl;
    cout << "Percentage Error: " << percentError << "%" << endl;
    
    // Display convergence information
    cout << "\nConvergence Analysis:" << endl;
    cout << string(50, '-') << endl;
    if(percentError < 0.001){
        cout << "Excellent: Error < 0.001%" << endl;
    }
    else if(percentError < 0.1){
        cout << "Good: Error < 0.1%" << endl;
    }
    else if(percentError < 1.0){
        cout << "Fair: Error < 1%" << endl;
    }
    else{
        cout << "Poor: Error >= 1% (consider using more terms)" << endl;
    }
    
    cout << string(70, '=') << "\n" << endl;
}

int main(){
    cout << "=====================================================" << endl;
    cout << setw(40) << "EXP(x) CALCULATOR" << endl;
    cout << setw(50) << "Using Taylor Series Expansion" << endl;
    cout << "=====================================================" << endl;
    cout << "\nFormula: exp(x) = 1 + x + (x^2)/2! + (x^3)/3! + ..." << endl;
    cout << "=========================================================\n" << endl;
    
    // Step 1: Get validated input for x value
    float x = getXValue();
    
    // Step 2: Get validated input for number of terms
    int numTerms = getNumTerms();
    
    // Step 3: Calculate exp(x) using Taylor series
    float approximation = expTaylor(x, numTerms);
    
    // Step 4: Display results with detailed analysis
    displayResult(x, approximation, numTerms);
    
    return 0;

}

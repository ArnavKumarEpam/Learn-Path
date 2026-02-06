#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

/*
 Computes exp(x) using Taylor Series:
 exp(x) = 1 + x + x^2/2! + x^3/3! + ...

 Optimized using recurrence relation:
 term_n = term_(n-1) * (x / n)

 Time Complexity: O(n)
 Space Complexity: O(1)
*/

// Computes exp(x) using Taylor Series
double expTaylor(double x, int terms) {
    double sum = 1.0;     // First term = 1
    double term = 1.0;    // Current term

    for (int n = 1; n < terms; n++) {
        term *= x / n;    // Efficient recurrence
        sum += term;
    }

    return sum;
}

// Input validation for x
double getXValue() {
    double x;
    while (true) {
        cout << "Enter the value of x: ";
        if (cin >> x) return x;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a numeric value.\n";
    }
}

// Input validation for number of terms
int getNumTerms() {
    int terms;
    while (true) {
        cout << "Enter number of terms (recommended <= 50): ";
        if (cin >> terms && terms > 0) return terms;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a positive integer.\n";
    }
}

// Displays formatted output and analysis
void displayResult(double x, double approx, int terms) {
    double exact = exp(x);
    double absError = fabs(exact - approx);
    double percentError = (absError / exact) * 100;

   
    cout << "EXPONENTIAL FUNCTION RESULT\n";
   

    cout << fixed << setprecision(10);
    cout << "x value              : " << x << '\n';
    cout << "Number of terms      : " << terms << '\n';
    cout << "Taylor Approximation : " << approx << '\n';
    cout << "Built-in exp(x)      : " << exact << '\n';
    cout << "Absolute Error       : " << absError << '\n';
    cout << "Percentage Error     : " << percentError << "%\n";

    cout << "\nConvergence Quality: ";
    if (percentError < 0.001) cout << "Excellent\n";
    else if (percentError < 0.1) cout << "Good\n";
    else if (percentError < 1.0) cout << "Fair\n";
    else cout << "Poor (increase terms)\n";

    
}

int main() {
    
    cout << "EXP(x) CALCULATOR USING TAYLOR SERIES\n";

    double x = getXValue();
    int terms = getNumTerms();

    double approximation = expTaylor(x, terms);
    displayResult(x, approximation, terms);

    return 0;
}

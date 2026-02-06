#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

/*
  Function: factorial
  Purpose : Computes factorial of a non-negative integer n (n!)
*/
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;

    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;

    return result;
}

/*
  Function: term
  Purpose : Computes the nth term of sine Taylor series
            term = (-1)^(n+1) * x^(2n-1) / (2n-1)!
*/
float term(float x, int n) {
    int power = 2 * n - 1;
    float numerator = 1.0f;

    // Compute x^(2n-1)
    for (int i = 0; i < power; i++)
        numerator *= x;

    long long denom = factorial(power);

    // Alternating sign
    if (n % 2 == 0)
        numerator = -numerator;

    return numerator / denom;
}

/*
  Function: sinTaylor
  Purpose : Approximates sin(x) using Taylor series
*/
float sinTaylor(float x, int terms) {
    float result = 0.0f;

    for (int n = 1; n <= terms; n++) {
        result += term(x, n);
    }

    return result;
}

int main() {
    float X;
    int terms;

    cout << "========================================\n";
    cout << "  SIN(X) CALCULATION USING TAYLOR SERIES\n";
    cout << "========================================\n";

    // Input angle
    cout << "Enter angle in degrees: ";
    while (!(cin >> X)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a numeric value: ";
    }

    // Input terms
    cout << "Enter number of terms (positive integer): ";
    while (!(cin >> terms) || terms <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a positive integer: ";
    }

    // Degree to radian conversion
    float x = X * M_PI / 180.0f;

    // Taylor series approximation
    float approxValue = sinTaylor(x, terms);

    // Built-in value
    float exactValue = sin(x);
    float absError = fabs(exactValue - approxValue);

    cout << fixed << setprecision(8);
    cout << "\n----------------------------------------\n";
    cout << "Angle (degrees) : " << X << '\n';
    cout << "Angle (radians) : " << x << '\n';
    cout << "Terms used      : " << terms << '\n';
    cout << "sin(x) Taylor   : " << approxValue << '\n';
    cout << "sin(x) built-in : " << exactValue << '\n';
    cout << "Absolute Error  : " << absError << '\n';
    cout << "----------------------------------------\n";

    return 0;
}

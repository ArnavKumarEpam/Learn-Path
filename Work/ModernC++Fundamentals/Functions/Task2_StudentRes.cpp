#include<iostream>
#include<limits>
#include<iomanip>
using namespace std;

// Function to calculate average marks of all subjects
// Parameters: marks[] - array of subject marks, numSubjects - total number of subjects
// Returns: average as float value
float calculateAverage(int marks[], int numSubjects){
    // Edge case handling: ensure numSubjects is valid before division
    if(numSubjects <= 0){ 
        return 0.0f; // Return 0 if no subjects (division by zero prevention)
    }
    
    int total = 0;
    // Sum all the marks from the array
    for(int i = 0; i < numSubjects; i++){
        total += marks[i];
    }
    
    // Calculate and return average with proper type casting
    return static_cast<float>(total) / numSubjects;
}

// Function to determine grade based on average marks using specified grading scale
// A: 90 and above
// B: 80–89
// C: 70–79
// D: 60–69
// F: Below 60
char determineGrade(float average){
    // Convert average to an integer for cleaner switch-case logic
    int gradeThreshold = static_cast<int>(average / 10);
    
    switch(gradeThreshold){
        case 10:
        case 9: // 90-100
            return 'A'; // Excellent performance
        case 8: // 80-89
            return 'B'; // Good performance
        case 7: // 70-79
            return 'C'; // Average performance
        case 6: // 60-69
            return 'D'; // Below average performance
        default: // Below 60
            return 'F'; // Fail
    }
}

// Function to display formatted results with all student information
// Parameters: marks[] - array of marks, numSubjects - total subjects, grade - assigned grade, average - calculated average
// Displays results in a well-formatted table
void displayResult(int marks[], int numSubjects, char grade, float average){
    cout << "\n" << string(50, '=') << endl;
    cout << setw(30) << "RESULTS" << endl;
    cout << string(50, '=') << endl;
    
    cout << "\nMarks Obtained:" << endl;
    cout << string(30, '-') << endl;
    
    // Display marks for each subject
    for(int i = 0; i < numSubjects; i++){
        cout << "Subject " << setw(2) << (i + 1) << ": " << setw(3) << marks[i] << " out of 100" << endl;
    }
    
    cout << string(30, '-') << endl;
    
    // Display average and grade with proper formatting
    cout << setprecision(2) << fixed;
    cout << "Average Marks: " << setw(6) << average << " %" << endl;
    cout << "Grade: " << grade << endl;
    cout << string(50, '=') << "\n" << endl;
}

// Function to get number of subjects with proper input validation and retry logic
// Returns: validated positive integer for number of subjects
int getNumSubjects(){
    int numSubjects;
    while(true){
        cout << "Enter number of subjects: ";
        
        // Check if input is valid - handle non-numeric input
        if(!(cin >> numSubjects)){
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            cout << "Invalid input! Please enter a valid number." << endl;
            continue;
        }
        
        // Validate that number of subjects is positive (greater than 0)
        if(numSubjects <= 0){
            cout << "Invalid number of subjects! Please enter a positive number." << endl;
            continue;
        }
        
        return numSubjects; // Return validated input
    }
}

// Function to get marks for each subject with proper validation and retry logic
// Parameters: marks[] - array to store marks, numSubjects - number of subjects to input
// Ensures all marks are valid (0-100 range) before proceeding
void getMarks(int marks[], int numSubjects){
    for(int i = 0; i < numSubjects; i++){
        while(true){
            cout << "Enter marks for subject " << (i + 1) << " (0-100): ";
            
            // Check if input is valid - handle non-numeric input
            if(!(cin >> marks[i])){
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                cout << "Invalid input! Please enter a valid number." << endl;
                continue;
            }
            
            // Validate marks are within valid range (0-100)
            if(marks[i] < 0 || marks[i] > 100){
                cout << "Invalid marks! Please enter marks between 0 and 100." << endl;
                continue;
            }
            
            break; // Valid input received, proceed to next subject
        }
    }
}

int main(){
    cout << "======================================" << endl;
    cout << setw(25) << "School Grade Calculator" << endl;
    cout << "======================================\n" << endl;
    
    // Step 1: Get validated number of subjects from user
    int numSubjects = getNumSubjects();
    
    // Step 2: Create array to store marks for each subject
    int marks[numSubjects];
    
    // Step 3: Get validated marks for each subject
    getMarks(marks, numSubjects);
    
    // Step 4: Calculate average marks using the marks array
    float average = calculateAverage(marks, numSubjects);
    
    // Step 5: Determine grade based on calculated average
    char grade = determineGrade(average);
    
    // Step 6: Display formatted results to the user
    displayResult(marks, numSubjects, grade, average);
    
    return 0;

}
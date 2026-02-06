#include <iostream>
#include <iomanip>
using namespace std;

// Utility Functions....

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void printMatrix(int rows, int cols, int** matrix) {
    
    for (int i = 0; i < rows; i++) {
        cout << "|";
        for (int j = 0; j < cols; j++)
            cout << setw(6) << matrix[i][j];
        cout << " |\n";
    }
   
}

// Input Functions....

void inputDimensions(int& rows, int& cols) {
    while (true) {
        cout << "Enter number of rows: ";
        cin >> rows;
        if (!cin.fail() && rows > 0) break;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Try again.\n";
    }

    while (true) {
        cout << "Enter number of columns: ";
        cin >> cols;
        if (!cin.fail() && cols > 0) break;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Try again.\n";
    }
}

void inputMatrix(int rows, int cols, int** matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            while (true) {
                cout << "Element [" << i + 1 << "," << j + 1 << "]: ";
                cin >> matrix[i][j];
                if (!cin.fail()) break;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Enter an integer.\n";
            }
        }
    }
}

// Matrix Operations....

bool addMatrices(int r1, int c1, int** A, int r2, int c2, int** B, int** R) {
    if (r1 != r2 || c1 != c2) return false;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            R[i][j] = A[i][j] + B[i][j];
    return true;
}

bool subtractMatrices(int r1, int c1, int** A, int r2, int c2, int** B, int** R) {
    if (r1 != r2 || c1 != c2) return false;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            R[i][j] = A[i][j] - B[i][j];
    return true;
}

bool multiplyMatrices(int r1, int c1, int** A, int r2, int c2, int** B, int** R) {
    if (c1 != r2) return false;

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < c1; k++)
                R[i][j] += A[i][k] * B[k][j];
        }
    }
    return true;
}

void transposeMatrix(int rows, int cols, int** A, int** R) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            R[j][i] = A[i][j];
}



int main() {
    int r1, c1, r2, c2;

    cout << "\nMatrix 1\n";
    inputDimensions(r1, c1); // input for dimensions for matrix1
    int** matrix1 = allocateMatrix(r1, c1);
    inputMatrix(r1, c1, matrix1); // input elements in the matrix1

    cout << "\nMatrix 2\n";
    inputDimensions(r2, c2); // input for dimensions of matrix2
    int** matrix2 = allocateMatrix(r2, c2); // input elements in the matrix2
    inputMatrix(r2, c2, matrix2);

    cout << "\nMATRIX OPERATIONS \n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Transpose (Matrix 1)\n";
    cout << "Choose option (1-4): ";

    int choice;
    cin >> choice;

    if (cin.fail()) {
        cout << "Invalid choice.\n";
        return 0;
    }

    if (choice == 1 || choice == 2) {
        int** result = allocateMatrix(r1, c1);
        bool success = (choice == 1)
            ? addMatrices(r1, c1, matrix1, r2, c2, matrix2, result)
            : subtractMatrices(r1, c1, matrix1, r2, c2, matrix2, result);

        if (!success)
            cout << "Operation not possible due to incompatible dimensions.\n";
        else
            printMatrix(r1, c1, result);

        freeMatrix(result, r1);
    }
    else if (choice == 3) {
        int** result = allocateMatrix(r1, c2);
        if (!multiplyMatrices(r1, c1, matrix1, r2, c2, matrix2, result))
            cout << "Multiplication not possible.\n";
        else
            printMatrix(r1, c2, result);

        freeMatrix(result, r1);
    }
    else if (choice == 4) {
        int** result = allocateMatrix(c1, r1);
        transposeMatrix(r1, c1, matrix1, result);
        printMatrix(c1, r1, result);
        freeMatrix(result, c1);
    }
    else {
        cout << "Invalid option selected.\n";
    }

    freeMatrix(matrix1, r1);
    freeMatrix(matrix2, r2);

    return 0;
}

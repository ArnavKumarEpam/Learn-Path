// #include<iostream>
// #include <iomanip>
// using namespace std;

// void inputDimensions(int &row, int &col){ // function to input the dimension of the matrix
    
    
//     while (true) {
//         cout<<"Enter the number of rows of the matrix:";
//         cin >> row;
//         if (!cin.fail() && row > 0) break;
//         cout << "Invalid input. Try again: ";
//         cin.clear();
//         cin.ignore(1000, '\n');
//     }
//     while (true) {
//         cout<<"Enter the number of columns of the matrix:";
//         cin >> col;
//         if (!cin.fail() && col > 0) break;
//         cout << "Invalid input. Try again: ";
//         cin.clear();
//         cin.ignore(1000, '\n');
//     }
    
    

// }
// void inputMatrix(int row, int col, int **matrix){ // function to input matrix elements
//     for(int i = 0 ; i < row ; i++){
//         for(int j = 0 ; j < col ; j++){
//             cout<<"Enter the element of matrix at position: "<<i + 1<<", "<<j + 1<<": ";
//             cin>>matrix[i][j];
//             if(cin.fail()){
//                 cout<<"Invalid input! Please enter numeric values only."<<endl;
//                 cin.clear();
//                 cin.ignore(1000, '\n');
//                 j--; // retry current index
//             }
//         }
//     }
// }

// // function to add two matrices
// bool addMatrices(int row1, int col1, int **matrix1, int row2, int col2, int **matrix2, int **resultMatrix){
//     cout<<"Adding the matrices"<<endl;
//     if(row1 != row2 || col1 != col2){
//         cout<<"Error: Matrices dimensions do not match for addition!"<<endl;
//         return false;
//     }
//     for(int i = 0 ; i < row1 ; i++){
//         for(int j = 0 ; j < col1 ; j++){
//             resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
//         }
//     }
//     return true;
// }

// // function to subtract two matrices
// bool subtractMatrices(int row1, int col1, int **matrix1, int row2, int col2, int **matrix2, int **resultMatrix){
//     cout<<"Subtracting the matrices"<<endl;
//     if(row1 != row2 || col1 != col2){
//         cout<<"Error: Matrices dimensions do not match for subtraction!"<<endl;
//         return false;
//     }
//     for(int i = 0 ; i < row1 ; i++){
//         for(int j = 0 ; j < col1 ; j++){
//             resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
//         }
//     }
//     return true;
// }

// // function to multiply two matrices
// bool multiplyMatrices(int row1, int col1, int **matrix1, int row2, int col2, int **matrix2, int **resultMatrix){
    
//     if(col1 != row2){
//         cout<<"Error: Matrices dimensions do not match for multiplication!"<<endl;
//         return false;
//     }
    
//     cout<<"Multiplying the matrices"<<endl;
    
//     for(int i = 0; i < row1; i++){
//     for(int j = 0; j < col2; j++){
//         resultMatrix[i][j] = 0;
//         for(int k = 0; k < col1; k++){
//             resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
//         }
//     }
// }
//     return true;
// }

// // function to calculate transpose of a matrix
// void transposeMatrix(int row, int col, int **matrix, int **resultMatrix){
    
//     cout<<"Transposing the matrix"<<endl;
//     for(int i = 0 ; i < row ; i++){
//         for(int j = 0 ; j < col ; j++){
//             resultMatrix[j][i] = matrix[i][j];
//         }
//     }
// }

// // function to print the matrix in tabular format
// void printMatrix(int row, int col, int **matrix){
//     cout<<"---------The Matrix is:----------"<<endl;
//     for(int i = 0 ; i < row ; i++){
//         cout<<"|";
//         for(int j = 0 ; j < col ; j++){
//             cout<<setw(5)<<matrix[i][j];
//         }
//         cout<<"|" << endl;
//     }
//     cout<<"---------------------------------"<<endl;
// }

// void freeMatrix(int **matrix, int rows){
//     for(int i = 0; i < rows; i++)
//         delete[] matrix[i];
//     delete[] matrix;
// }




// int main(){
//     int row1, col1;
//     inputDimensions(row1, col1); // getting input of size of the array

//     int **matrix1 = new int*[row1];
//     for(int i = 0; i < row1; i++) matrix1[i] = new int[col1];

//     inputMatrix(row1, col1, matrix1); // getting input of matrix1 elements

//     int row2, col2;
//     inputDimensions(row2, col2); // getting input of size of the array

//     int **matrix2 = new int*[row2];
//     for(int i = 0; i < row2; i++) matrix2[i] = new int[col2];
    
//     inputMatrix(row2, col2, matrix2); // getting input of matrix2 elements

//     int **resultMatrix = new int*[row1]; // resultant matrix declaration

//     for(int i = 0; i < row1; i++){
//         resultMatrix[i] = new int[col1];
//     }

//     do{
//     cout << "\n========== MATRIX OPERATIONS ==========\n";
//     cout << "1. Addition\n";
//     cout << "2. Subtraction\n";
//     cout << "3. Multiplication\n";
//     cout << "4. Transpose (First Matrix)\n";
//     cout << "Choose an option (1-4): ";
//     int choice;
//     cin >> choice;
//     if(cin.fail()){
//         cin.clear();
//         cin.ignore(1000, '\n');
//         cout<<"Invalid input! Enter a number between 1 and 4."<<endl;
//         continue;
//     }

//     switch(choice){
//         case 1:
//             // adding two matrices
//             if(!addMatrices(row1, col1, matrix1, row2, col2, matrix2, resultMatrix)){
//                 cout<<"Addition failed due to incompatible dimensions. "<<endl;
//                 freeMatrix(matrix1, row1);
//                 freeMatrix(matrix2, row2);
//                 freeMatrix(resultMatrix, row1);

//                 return 0;
//             }
//             cout<<"Resultant Matrix after Addition:"<<endl;
//             printMatrix(row1, col1, resultMatrix);
//             freeMatrix(matrix1, row1);
//             freeMatrix(matrix2, row2);
//             freeMatrix(resultMatrix, row1);

//             return 0;
//         case 2:
//             // subtracting two matrices
//             if(!subtractMatrices(row1, col1, matrix1, row2, col2, matrix2, resultMatrix)){
//                 cout<<"Subtraction failed due to incompatible dimensions. "<<endl;
//                 freeMatrix(matrix1, row1);
//                 freeMatrix(matrix2, row2);
//                 freeMatrix(resultMatrix, row1);

//                 return 0;
//             }
//             cout<<"Resultant Matrix after Subtraction:"<<endl;
//             printMatrix(row1, col1, resultMatrix);
//             freeMatrix(matrix1, row1);
//             freeMatrix(matrix2, row2);
//             freeMatrix(resultMatrix, row1);

//             return 0;
//         case 3:
//             // multiplying two matrices
//             freeMatrix(resultMatrix, row1);
//             resultMatrix = new int *[row1];
//             for(int i = 0 ; i < row1 ; i++){
//                 resultMatrix[i] = new int[col2];
//             }
//             if(!multiplyMatrices(row1, col1, matrix1, row2, col2, matrix2, resultMatrix)){
//                 cout<<"Multiplication not possible due to incompatible dimensions! "<<endl;
//                 freeMatrix(matrix1, row1);
//                 freeMatrix(matrix2, row2);
//                 freeMatrix(resultMatrix, row1);
//                 return 0;
//             }
//             cout<<"Resultant Matrix after Multiplication:"<<endl;
            
            
//             printMatrix(row1, col2, resultMatrix);
            
//             freeMatrix(matrix1, row1);
//             freeMatrix(matrix2, row2);
//             if(resultMatrix != nullptr){
//                 freeMatrix(resultMatrix, row1);
//             }

//             return 0;
//         case 4:
//             // transpose of a matrix
//             freeMatrix(resultMatrix, row1);
//             resultMatrix = new int*[col1]; // transposed matrix will have dimensions col1 x row1
//             for(int i = 0; i < col1; i++){
//                 resultMatrix[i] = new int[row1];
//             }   
//             transposeMatrix(row1, col1, matrix1, resultMatrix);
//             cout<<"Transpose of first Matrix:"<<endl;
//             printMatrix(col1, row1, resultMatrix);
            
//             freeMatrix(matrix1, row1);
//             freeMatrix(matrix2, row2);
//             freeMatrix(resultMatrix, col1);

//             return 0;
//         default:
//             cout<<"Invalid choice! Please select operation between the range of 1 - 4 "<<endl;
//             return 0;
            
//     }
// }while(true);
//     return 0;
// }


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
    cout << "\n----------- MATRIX -----------\n";
    for (int i = 0; i < rows; i++) {
        cout << "|";
        for (int j = 0; j < cols; j++)
            cout << setw(6) << matrix[i][j];
        cout << " |\n";
    }
    cout << "------------------------------\n";
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

    cout << "\n--- Matrix 1 ---\n";
    inputDimensions(r1, c1); // input for dimensions for matrix1
    int** matrix1 = allocateMatrix(r1, c1);
    inputMatrix(r1, c1, matrix1); // input elements in the matrix1

    cout << "\n--- Matrix 2 ---\n";
    inputDimensions(r2, c2); // input for dimensions of matrix2
    int** matrix2 = allocateMatrix(r2, c2); // input elements in the matrix2
    inputMatrix(r2, c2, matrix2);

    cout << "\n========== MATRIX OPERATIONS ==========\n";
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

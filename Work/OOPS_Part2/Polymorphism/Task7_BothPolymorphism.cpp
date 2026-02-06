#include<iostream>
#include<vector>
const int MAX = 100;

class Matrix{
    public:
        int row, col;
        double arr[MAX][MAX];
        Matrix(int row, int col) : row(row), col(col){

            for(int i = 0 ; i < row ; i++){
                for(int j = 0 ; j < col ; j++){
                    arr[i][j] = 0;
                }
            }
        }

        void setValue(int row, int col, int value){
            std::cout<<"Function Overloading + (Compile Time Polymorphism)"<<std::endl;
            arr[row][col] = value;
        }
        void setValue(double row, double col, double value){
            std::cout<<"Function Overloading + (Compile Time Polymorphism)"<<std::endl;
            arr[(int)row][(int)col] = value;
        }
        Matrix operator+ (const Matrix &matrixA){ 
            std::cout<<"Operator Overloading + (Compile Time Polymorphism)"<<std::endl;
            Matrix result(row, col);
            for(int i = 0 ; i < row; i++){
                for(int j = 0 ; j < col ; j++){
                    result.arr[i][j] = this->arr[i][j] + matrixA.arr[i][j];
                }
            }
            return result;
        }
        virtual void display()const{
            std::cout<<"Displaying the Matrix! "<<std::endl;
            for(int i = 0 ; i < row; i++){
                for(int j = 0 ; j < col ; j++){
                    std::cout<<arr[i][j]<<" ";
                }
                std::cout<<std::endl;
            }
        }
};

class SquareMatrix : public Matrix{
    public:
        SquareMatrix(int row, int col): Matrix(row, col){}
        void display() const override{
            std::cout<<"Runtime Polymorphism! "<<std::endl;
            Matrix::display();
        }
};

class IdentityMatrix : public Matrix{
    public:
        IdentityMatrix(int row, int col) : Matrix(row, col){
            for(int i = 0 ; i < row ; i++){
                for(int j = 0 ; j < col ; j++){
                    arr[i][j] = 1;
                }
            }
        }
        void display() const override{
            std::cout<<"Runtime Polymorphism! "<<std::endl;
            Matrix::display();
        }
};

int main(){
    int row = 2, col = 2;
    SquareMatrix matrix(row, col);
    matrix.setValue(1, 1, 5);
    matrix.setValue(0.00, 0.00, 4.00);

    SquareMatrix matrix2(row, col);
    matrix2.setValue(1, 1, 5);
    matrix2.setValue(0.00, 0.00, 4.00);
    
    Matrix Result = matrix + matrix2;
    Result.display();

    IdentityMatrix identityMatrix(2, 2);

    std::vector<Matrix *> ptrList;
    ptrList.push_back(&matrix);
    ptrList.push_back(&Result);
    ptrList.push_back(&identityMatrix);

    for(int i = 0 ; i < ptrList.size() ; i++){
        ptrList[i]->display();
    }
}
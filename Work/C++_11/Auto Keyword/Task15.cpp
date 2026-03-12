#include<iostream>
#include<vector>
#include<initializer_list>

class Matrix{
    private:
        std::vector<std::vector<int>> mat;
    public:
        Matrix(std::initializer_list<std::initializer_list<int>> list) {
            for(auto &row : list){
                mat.push_back(row);
            }
        }

        void printAndDouble(){
            std::cout<<"Printing Before Updation\n";
            for(auto &row : mat){
                for(auto &col : row){
                    std::cout<<col<<" ";
                    col *= 2;
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl;
        }

        
        void print(){
            std::cout<<"Printing After Doubling: \n";
            for(auto &row : mat){
                for(auto &col : row){
                    std::cout<<col<<" ";
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl;
        }
};

int main(){
    Matrix matrix{{1, 2},
        {3, 4},
        {5, 6}
        };
    matrix.printAndDouble();
    matrix.print();
}
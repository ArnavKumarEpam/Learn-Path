#include<iostream>
#include<tuple>
template<typename ...Args>
 class Mytuple{
    std::tuple<Args...> data;

    public:
        Mytuple(Args ...args) : data(args...){}
        void print(){
            printHelper<0>();
        }
    private:
        
        template<std::size_t index>
        void printHelper() const{
            if constexpr(index < sizeof...(Args)){
                std::cout<<std::get<Index>(data)<<std::endl;
                printHelper<index + 1> ();
            }

        }
        
};

int main(){
    Mytuple<int, double, std::string> data(1, 2.5, "hello");
    data.print();
  
}
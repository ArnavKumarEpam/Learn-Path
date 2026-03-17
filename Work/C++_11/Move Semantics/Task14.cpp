#include<iostream>
#include<cstring>

class Base{
    protected:
        int * baseData;
    public:
        Base() : baseData(new int(99)){
            std::cout<<"Base Constructor: " << baseData <<" ( "<<*baseData<<" ) \n";
        }
        Base(const Base &other) : baseData(new int(*other.baseData)){    
            std::cout << "Base copy ctor: " << baseData << " (" << *baseData << ")\n";
        }
        Base & operator=(const Base &other){
            if(this != &other){
                baseData = new int(*other.baseData);
                std::cout << "Base copy assign: (" << *baseData << ")\n";
            }
            return *this;

        }
        Base(Base &&other) noexcept {
            baseData = other.baseData;
            other.baseData = nullptr;
            std::cout << "Base move ctor: " << baseData << '\n';
        }
        Base & operator =(Base &&other) noexcept{
            if(this != &other){
                baseData = other.baseData;
                other.baseData = nullptr;
                std::cout << "Base move assign: (" << *baseData << ")\n";
            }
            return *this;
        }
        virtual ~Base(){
            std::cout<<"Base Destructor! \n";
            delete[] baseData;
        }
        virtual void print(const char* lbl) const {
        std::cout << lbl << " Base data: " << baseData << " (" << (baseData ? *baseData : 0) << ")\n";
    }
};

class Derived : public Base{
    char * derivedData;
    public:
        Derived() : Base(), derivedData(new char[8]){
            strcpy(derivedData, "Derived");
            std::cout<<"Derived Class Constructor! "<<static_cast<void*>(derivedData)<<std::endl;
            std::cout<<"Derived class const ending\n";
        }
        Derived(const Derived &other) : Base(other), derivedData(new char[std::strlen(other.derivedData) + 1]){
            strcpy(derivedData, other.derivedData);
            std::cout<<"Derived Class Copy Constructor! "<<static_cast<void*>(derivedData)<<std::endl;
            
        }
        Derived &operator=(const Derived &other){
            if(this != &other){
                delete[] derivedData;
                derivedData = new char[std::strlen(other.derivedData) + 1];
                strcpy(derivedData, other.derivedData);
                std::cout<<"Derived Class Copy Assignment Operator! "<<static_cast<void*>(derivedData)<<std::endl;

            }
            return *this;
        }
        Derived(Derived &&other) noexcept {
            derivedData = new char[std::strlen(other.derivedData) + 1];
            strcpy(derivedData, other.derivedData);
            other.derivedData = nullptr;
            std::cout<<"Derived Class Move Constructor! "<<static_cast<void*>(derivedData)<<std::endl;
        } 
        Derived &operator=(Derived &&other) noexcept{
            if(this != &other){
                delete []derivedData;
                derivedData = new char[std::strlen(other.derivedData) + 1];
                strcpy(derivedData, other.derivedData);
                other.derivedData = nullptr;
                std::cout<<"Derived Class Move Assignment Operator! "<<static_cast<void*>(derivedData)<<std::endl;
            }
            return *this;
        }
        ~Derived() override{
            std::cout << "Derived dtor: " << static_cast<void*>(derivedData) << "\n";
            delete[] derivedData;
        }
        void print(const char* lbl) const override {
        Base::print(lbl);
        std::cout << lbl << " Derived data: " << static_cast<const void*>(derivedData)
                  << " (" << (derivedData ? derivedData : "null") << ")\n";
    }
};

int main(){
    std::cout << "--- Base test ---\n";
    Base b1;
    Base b2 = b1;       // Copy
    b2 = std::move(b1); // Move assign

    std::cout << "--- Derived test ---\n";
    Derived d1;
    Derived d2 = d1;    // Copy ctor
    d2 = std::move(d1); // Move assign

    std::cout << "--- Slicing demo ---\n";
    Base sliced = d2;   // Slicing (loses Derived-specific data)
    sliced.print("sliced: ");
    d2.print("d2: ");

    std::cout << "--- Polymorphic deletion ---\n";
    Base* poly = new Derived();
    delete poly;        // Should call both destructors safely
    return 0;
}
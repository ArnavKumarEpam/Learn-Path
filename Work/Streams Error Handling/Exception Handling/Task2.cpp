// #include<exception>
// #include<iostream>
// #include<vector>
// int main(){
//     // std::vector<int> v = {1, 2, 3, 4, 5};
//     // try{
//     //     std::cout<<v.at(4)<<std::endl;
//     // }
//     // catch(std::out_of_range e){
//     //     std::cout<<"MEssage: "<<e.what()<<std::endl;
//     // }
//     // std::cout<<"AAgya ladle\n";
//     try{
//         // throw 1;
//         // throw 1.1;
//         // throw 1.2f;
//         // throw 'a';
//         // throw "THis is the character array";
//         throw (std::string)"this is the string";
//     }
//     catch(const int &e){
//         std::cout<<"Integer Exception: "<<e<<std::endl;    
//     }
//     catch(const double &e){
//         std::cout<<"Double Exception: "<<e<<std::endl;    
//     }
//     catch(const float &e){
//         std::cout<<"Float Exception: "<<e<<std::endl;    
//     }
//     catch(const char &e){
//         std::cout<<"Character Exception: " <<e<<std::endl;
//     }
//     catch (const char *&e){
//         std::cout<<"Character Array Exception: "<<e<<std::endl;
//     }
//     catch(const std::string &e){
//         std::cout<<"String Exception: "<<e<<std::endl;
//     }
// }

#include<iostream>
#include<exception>


static int counter = 0;

class SystemError : public std::exception{
    std::string message;
    public: 
        SystemError(std::string msg) : message(msg){}
        const char* what() const noexcept override{
            return message.c_str();
        }
};
class NetworkError : public std::exception{
    std::string message;
    public: 
        NetworkError(std::string msg) : message(msg){}
        const char* what() const noexcept override{
            return message.c_str();
        }
};
void complexOperation(){
    counter++;
    if(counter == 1){
        throw SystemError("System Error! \n");
    }
    else if(counter == 2){
        throw NetworkError("Network Error! \n");
    }
    else if(counter == 3){
        throw -1;
    }
    else if(counter == 4){
        throw (char*)("Very unexpected error! \n");
    }
    else{
        std::cout<<"Operation completed successfully.\n";
    }
}
int main(){
    for(int i = 0 ; i < 6; i++){
        try{complexOperation();
   }
    catch(const SystemError &e){
        std::cout<<e.what();
        std::cout<<"End of Processing\n";
    }
    catch(const NetworkError &e){
        std::cout<<e.what();
        std::cout<<"End of Processing\n";
    }
    catch(int e){
        std::cout<<e<<std::endl;
        std::cout<<"End of Processing\n";
    }
    catch(const char* message){
        std::cout<<message;
        std::cout<<"End of Processing\n";
    }
        
    }

}
#include<iostream>
#include<mutex>
#include<thread>

class Logger{
    private:
        Logger(){}
        Logger(const Logger &) = delete;
        Logger& operator = (const Logger &) = delete;
    public:
        static Logger &getInstance(){
            static Logger instance;
            return instance;
        }

        void print(){
            std::cout<<"Thread ID: "<<std::this_thread::get_id()<<", Singleton Address: "<<this<<std::endl;
        }

};

int main(){
    std::thread t1(&Logger::print, &Logger::getInstance());
    std::thread t2(&Logger::print, &Logger::getInstance());
    std::thread t3(&Logger::print, &Logger::getInstance());
    t1.join();
    t2.join();
    t3.join();

}
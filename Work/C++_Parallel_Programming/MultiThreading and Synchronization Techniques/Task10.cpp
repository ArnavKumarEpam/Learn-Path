#include<iostream>
#include<mutex>
#include<thread>

class Logger{
    private:
        Logger(){}
        Logger(const Logger &) = delete;
        Logger & operator=(const Logger &) = delete;
        static Logger * instance;
        static std::once_flag flag;

    public:
        static Logger &getInstance(){
            std::call_once(flag, [](){ instance = new Logger();});
            return *instance;
        }
        void log(){
            std::cout<<"Instance Address: "<<this<<", Thread ID: "<<std::this_thread::get_id()<<std::endl;
        }
};

Logger * Logger::instance = nullptr;
std::once_flag Logger::flag;

int main(){
    std::thread t1(&Logger::log, &Logger::getInstance());
    std::thread t2(&Logger::log, &Logger::getInstance());
    std::thread t3(&Logger::log, &Logger::getInstance());

    t1.join();
    t2.join();
    t3.join();
}

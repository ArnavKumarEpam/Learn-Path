#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<list>



struct Task{
    std::string name;
    int priority;
    int deadline;

    void print() const {
        std::cout<<"Task Name: "<<name<<", Priority: "<<priority<<", Deadline: "<<deadline<<std::endl;
    }
};

struct Compare{
    bool operator()(const Task &a, const Task &b){
    if(a.priority == b.priority){ // if priorities are the same sort by deadline which is earlier deadline should come first
        return a.deadline < b.deadline;
    }
    return a.priority < b.priority; // else sort it by priority 
}
};



int main(){
    std::list<Task> tasks = { {"Sending the Mail", 2, 5}, 
    {"Fix Critical bug", 1, 1}, 
    {"Team meeting", 2, 1}, 
    {"Code review", 2, 3}, 
    {"Update docs", 3, 4} };

    std::cout<<"Printing before sorting: "<<std::endl;
    for(const auto &task : tasks){
        task.print();
    }

    tasks.sort(Compare());
     std::cout<<"Printing after sorting: "<<std::endl;
    for(const auto &task : tasks){
        task.print();
    }

}

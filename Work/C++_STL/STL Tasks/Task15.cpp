#include<iostream>
#include<string>
#include<queue>
#include<algorithm>

struct Patient{
    std::string name;
    int severity;
    int arrivalTime;
    Patient(std::string n, int s, int a) : name(n), severity(s), arrivalTime(a){}


};

struct ComparePatients{
    bool operator()(const Patient &p1, const Patient &p2){
        if(p1.severity == p2.severity){
            return p1.arrivalTime > p2.arrivalTime; // if severity is same then sort by arrival time which is earlier should come first
        }
        return p1.severity > p2.severity; // lower severity should come first
    }
};

int main(){
    std::priority_queue<Patient, std::vector<Patient>, ComparePatients> erQueue;
    erQueue.push(Patient("Alice Smith", 3, 10));
    erQueue.push(Patient("Bob", 1, 5));
    erQueue.push(Patient("Charlie", 3, 8));
    erQueue.push(Patient("David", 2, 12));
    erQueue.push(Patient("Eve", 1, 7));
    erQueue.push(Patient("Frank", 5, 2));

    while(!erQueue.empty()){
        Patient patient = erQueue.top();
        std::cout<<"Processing patient [" << patient.name<< "], Severity ["<<patient.severity<<"], Arrived at ["<<patient.arrivalTime<<"]"<<std::endl;
        erQueue.pop();
    }

}
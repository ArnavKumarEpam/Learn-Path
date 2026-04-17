#include<iostream>
#include<set>
#include<string>
#include<vector>

bool scheduleEvent(std::set<int>& scheduledEvents, int startTime){
    auto ifAdded = scheduledEvents.emplace(startTime);
    if(ifAdded.second){
        std::cout<<"Event at "<<startTime<<" minutes scheduled successfully."<<std::endl;
        return true;
    }
    else{
        std::cout<<"EConflict: Time slot "<<startTime<<" minutes is already taken."<<std::endl;
        return false;
    } 
}


void displayScheduledEvents(const std::set<int>& events){
    if(events.empty()) std::cout<<"No events scheduled! "<<std::endl;
    else{
        for(int time : events){
            std::cout << " - " << time << " minutes" << std::endl; 
        } 
        std::cout << "--------------------------------\n" << std::endl;
    }
}

int main(){
    std::set<int> myCalendar;
    std::cout << "Attempting to schedule events for the first time:\n";
    scheduleEvent(myCalendar, 900);
    scheduleEvent(myCalendar, 1030);
    scheduleEvent(myCalendar, 1300);
    scheduleEvent(myCalendar, 1400);
    displayScheduledEvents(myCalendar);


    std::cout << "\nAttempting to schedule a conflicting event:\n";
    scheduleEvent(myCalendar, 1030); // This should fail as it's already scheduled
    displayScheduledEvents(myCalendar);


    // Another unique event
    scheduleEvent(myCalendar, 1200);
    displayScheduledEvents(myCalendar);


    std::cout << "\nAttempting to schedule a batch of events (some new, some duplicates):\n";
    std::vector<int> newEventTimes = {800, 1400, 1600, 900, 1800};
    for(int time : newEventTimes){
        scheduleEvent(myCalendar, time);
    }
    displayScheduledEvents(myCalendar);

}
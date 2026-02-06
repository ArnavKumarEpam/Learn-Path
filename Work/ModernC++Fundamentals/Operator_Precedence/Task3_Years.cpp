#include<iostream>
using namespace std;

string daysToYear(int days){ // function to convert days to years, weeks, days
    int year = days / 365; // calculate number of years
    int remainingDays = days % 365; // calculate remaining days after extracting years
    int week = remainingDays / 7; // calculate number of weeks
    int day = remainingDays % 7; // calculate remaining days after extracting weeks
    return to_string(year) + " years, " + to_string(week) + " weeks, and " + to_string(day) + " days";
}

int main(){
    cout<<"Welcome"<<endl;
    cout<<"Enter the number of days: ";
    int days;
    cin>>days;
    if(cin.fail() || days < 0){ // input validation
        cout<<"Invalid input! Please enter a positive numeric value for days."<<endl;
        cin.clear(); // clear error flag
        return 0;
    }
    string result = daysToYear(days); // calling conversion function
    cout<<days<<" Days when converted to Years, Weeks, Days: "<<result<<endl;

}
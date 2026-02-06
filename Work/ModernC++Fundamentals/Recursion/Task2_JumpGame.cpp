#include<iostream>

#define MAX 100

int cache[MAX];

int stairCaseCounter(int totalSteps){
    if(totalSteps == 0 || totalSteps == 1) return 1;
    if(totalSteps == 2) return 2;
    if(cache[totalSteps] != -1){ // if already calculated then return it no need to calculate again
        return cache[totalSteps];
    }
    // totalSteps - 1 for jumping 1 stair and totalSteps - 2 for jumping 2 stairs
    cache[totalSteps] = stairCaseCounter(totalSteps - 1) + stairCaseCounter(totalSteps - 2);
    return cache[totalSteps];
}

int main(){
    int totalSteps;
    for(int i = 0 ; i < MAX ; i++){
        cache[i] = -1; // setting cache as -1
    }

    std::cout<<"Enter Total Steps: "<<std::endl;
    std::cin>>totalSteps; // input of totalSteps 

    if(totalSteps < 0 || totalSteps >= MAX) { // checking if totalSteps are valid or not
        std::cout<<"Total Number of Steps have to be in range 0 - 100 ! "<<std::endl;
        return 1;
    }

    int totalWays = stairCaseCounter(totalSteps); // calling stairCaseCounter function to calculate the ways to climb up stairs
    std::cout<<"Total Ways to climb up stairs having steps "<<totalSteps<<" are: "<<totalWays<<std::endl;

    return 0;


    
}
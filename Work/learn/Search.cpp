#include<iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int left = 0, right = size - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return - 1; // key not found
}

int linearSearch(int arr[], int size, int key){
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1; // key not found
}

void printResult(int index, int key){
    if(index != -1){
        cout<<"Key "<< key <<" found at index "<< index <<endl;
    }
    else{
        cout<<"Key  "<< key <<" not found in the array."<<endl;
    }
}

void inputSize(int &size){
    cout<<"Enter the size of the array: ";
    cin>>size;
    if(cin.fail() || size <= 0){ // validate positive size
        cout<<"Invalid input! Please enter a positive numeric value for size."<<endl;
        return;
    }
}

void inputArray(int arr[], int size){
    cout<<"Enter the elements of the array:"<<endl;
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
        if(cin.fail()){ // validate numeric input
            cout<<"Invalid input! Please enter numeric values only."<<endl;
            cin.clear();
            i--; // retry current index
        }
    }
    
}

bool ifSorted(int arr[], int size){
    for(int i = 1 ; i < size ; i++){
        if(arr[i] < arr[i - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    int arr[100];
    int size;
    inputSize(size);
    inputArray(arr, size);
    cout<<"Enter the element to search: ";
    int key;
    cin>>key;
    if(cin.fail()){
        cout<<"Invalid input! Please enter a numeric value for the element to search."<<endl;
        return 0;
    }

    cout<<"Which searching technique do you want to use?"<<endl;
    cout<<"1. Linear Search"<<endl;
    cout<<"2. Binary Search"<<endl;
    cout<<"Enter your choice (1 or 2): ";
    int choice;
    cin>>choice;
    switch(choice){
        case 1: {
            // Linear Search
            int index = linearSearch(arr, size, key);
            printResult(index, key);
            break;
        }
        case 2: {
            // For binary search, array must be sorted
            cout<<"Checking if array is sorted..."<<endl;
            if(!ifSorted(arr, size)){
                cout<<"Array is not sorted! Sorting the array first..."<<endl;
                sort(arr, arr + size);
            }
            
            int index = binarySearch(arr, size, key);
            printResult(index, key);
            break;
        }
        default:
            cout<<"Invalid choice! Please select 1 or 2."<<endl;
    }


}
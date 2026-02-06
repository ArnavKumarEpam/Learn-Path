#include<iostream>
using namespace std;

void inputSize(int &size){ // function to input size of the array
    cout<<"Enter the size of the array: ";
    cin>>size;
    if(cin.fail() || size <= 0){ // validate positive size
        cout<<"Invalid input! Please enter a positive numeric value for size."<<endl;
        return;
    }
}

void inputArray(int arr[], int size){ // function to input array elements
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

void reverseArray(int arr[], int reversedArray[], int size){ // function to reverse the array
    if(size == 1){ // if size is 1, no need to reverse
        reversedArray[0] = arr[0];
        return;
    }
    for(int i = 0 ; i < size ; i++){
        // reversedArray[0] = arr[last element], reversedArray[1] = arr[second last element] ...
        reversedArray[i] = arr[size - i - 1]; 
    }
}

void printArray(int arr[], int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int size;
    inputSize(size); // getting input of size of the array
    int arr[size]; // declaring the array of given size
    inputArray(arr, size); // getting input of array elements
    int reversedArray[size]; // declaring array to hold the reverse numbers

    reverseArray(arr, reversedArray, size); // function to reverse the array
    cout<<"Original Array: ";
    printArray(arr, size); // printing original array
    cout<<"\nReversed Array: ";
    printArray(reversedArray, size); // printing reversed array

}
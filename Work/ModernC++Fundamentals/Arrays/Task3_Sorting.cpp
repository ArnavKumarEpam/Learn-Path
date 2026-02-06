#include<iostream>
#include <algorithm>
using namespace std;

int getSize(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    if(cin.fail() || size <= 0){ // validate positive size
        cout<<"Invalid input! Please enter a positive numeric value for size."<<endl;
        return -1;
    }
    return size;
}
void inputArray(int arr[], int size){
    cout<<"Enter the elements of the array:"<<endl;
    for(int i = 0 ; i < size ; i++){
        cout<<"Enter element "<<i + 1<<": ";
        cin>>arr[i];
        if(cin.fail()){ // validate numeric input
            cout<<"Invalid input! Please enter numeric values only."<<endl;
            cin.clear();
            i--; // retry current index
        }
    }
    
}

void bubbleSort(int arr[], int size){
    // for(int i = 0 ; i < size - 1 ; i++){
    //     for(int j = 0 ; j < size - i - 1; j++){
    //         if(arr[j] > arr[j + 1]){
    //             swap(arr[j], arr[j + 1]);
    //         }
    //     }
    // }
    for(int i = 0 ; i < size ; i++){
        for(int j = i + 1; j < size ; j++){
            if(arr[j] < arr[i]) swap(arr[j], arr[i]);
        }
    }
}

void selectionSort(int arr[], int size){
    for(int i = 0 ; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1 ; j < size ; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void qsortWrapper(int arr[], int size){
    sort(arr, arr + size);
}

void printArray(int arr[], int size){
    
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int size = getSize();
    int arr[size];
    inputArray(arr, size);
    cout<<"Array before sorting: "<<endl;
    printArray(arr, size);
    cout<<"Enter the sorting algorithm to use:"<<endl;
    cout<<"For Bubble Sort enter [1]"<<endl;
    cout<<"For Selection Sort enter [2]"<<endl;
    cout<<"For Quick Sort enter [3]"<<endl;
    int choice;
    cin>>choice;
    if(cin.fail()){
        cout<<"Invalid input! Please enter a numeric value for choice."<<endl;
        return 0;
    }   
    switch(choice){
        case 1:
            bubbleSort(arr, size);
            break;
        case 2:
            selectionSort(arr, size);
            break;
        case 3:
            qsortWrapper(arr, size);
            break;
        default:
            cout<<"Invalid choice! Please enter 1, 2 or 3."<<endl;
            return 0;
    }
    cout<<"Array after sorting: "<<endl;
    printArray(arr, size);
    return 0;

}
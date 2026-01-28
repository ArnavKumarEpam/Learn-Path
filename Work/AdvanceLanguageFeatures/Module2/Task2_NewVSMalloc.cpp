#include<iostream>
using namespace std;

/*
    new is type safe as in this object is properly created
    whereas malloc isnt type safe as it provides only memory not object
    malloc needs type casting as by default malloc return void*,
    therefore we need to type cast it to int or double or whatever type we are using
*/
int main(){
    int *newArray = new int[5]; // new calls constructor, return bad_alloc in case of memory not allocated
    // malloc requires manual type casting, returns null if memory not allocated
    int *mallocArray = (int*)malloc(sizeof(int) * 5); // malloc doesnt call the constructor it just provides raw memory
    if(mallocArray == NULL) {
      cout<<"Memory not allocated to mallocArray!"<<endl;
      return 1;
    }
    for(int i = 0 ; i < 5 ; i++){
        newArray[i] = i + 1;
        mallocArray[i] = i + 1;
    }
    cout<<"Elements of the Array having memory alloted through (new): "<<endl;
    for(int i = 0 ; i < 5 ; i++){
        cout<<*(newArray + i)<<" ";
    }
    cout<<"Elements of the Array having memory alloted through (malloc): "<<endl;
    for(int i = 0 ; i < 5 ; i++){
        cout<<*(mallocArray + i)<<" ";
    }


    delete[] newArray; // calls destructor 
    free(mallocArray); // free doesnt call the destructor
}
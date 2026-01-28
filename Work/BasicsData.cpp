#include<bits/stdc++.h>
using namespace std;

#define pi 3.14
enum Week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};


int main(){
    // int num = 10;
    // cout<<"Size of int: "<<sizeof(num)<<" bytes"<<endl;
    // unsigned int unum = 20;
    // cout<<"Size of unsigned int: "<<sizeof(unum)<<" bytes"<<endl;
    // signed long int snum = -15;
    // cout<<"Size of signed int: "<<sizeof(snum)<<" bytes"<<endl;
    // signed long long int slnum = -123456789;
    // cout<<"Size of signed long long int: "<<sizeof(slnum)<<" bytes"<<endl;
    // wchar_t ch16 = char32_t('A');
    // cout<<"Size of char16_t: "<<sizeof(ch16)<<" bytes"<<endl;

    int *ptr = new int();
    cout<<ptr<<endl;
    *ptr = 50;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    delete ptr;

    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cin.ignore(); // to ignore the newline character left in the buffer
    string *arr = new string[num];
    for(int i = 0 ; i < num ; i++){
        cout<<"Enter string "<<i + 1<<": ";
        getline(cin, arr[i]);
    }
    for(int i = 0 ; i < num ; i++){
        cout<<"You entered string "<<i + 1<<": "<<arr[i]<<endl;
    }
    delete arr;
    
    // int a = 10;
    // int b (10);
    // int c {10};
    // cout<<a<<" "<<b<<" "<<c<<endl;
    // cout<<"Value of pi: "<<pi<<endl;
    // Week today = Sunday;
    // cout<<"Day number of today: "<<today + 1<<endl;
    // return 0;
}
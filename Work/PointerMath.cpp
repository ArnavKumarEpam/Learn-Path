#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int *p1 = &arr[0];
    int *p2 = &arr[1];
    cout << "Value at p1: " << *p1 << "having address" << p1 << endl;
    cout << "Value at p2: " << *p2 << "having address" << p2 << endl;
    p1 += 1;
    cout<<p1<< " " << *p1<<endl;
    cout<<p2<<" " << *p2<<endl;
    return 0;
}
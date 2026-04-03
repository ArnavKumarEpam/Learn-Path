// #include<iostream>
// using namespace std;

// int main(){
//     string s= "121212";
//     int one = 0, two = 0;
//     for(char c : s){
//         if(c == '1') one++;
//         else two++;
//     }
//     int i = 0, j = s.size() - 1;
//     while(i < s.size() && j >= 0){
//         if(s[i] == '1'&& one % 2 != 0){
//             one = 0;
//             i++;
//         }
//         else if(s[j] == '2' && two % 2 != 0){
//             j -= 1;
//             two = 0;
//         }else break;

        
//     }
//     string ans = s.substr(i, j);
//     cout<<ans;
// }

#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v = {10, 122};
    cout<<v.size()<<" "<< v.capacity()<<endl;
    v.push_back(10);
    cout<<v.size()<<" "<< v.capacity()<<endl;
    // auto it = v.cbegin();
   
    // cout<<*(it + 1);
    // cout<<*v.data()<<endl;
    cout<<"Max size of the vector possible: "<<v.max_size()<<endl;
    v.resize(10);
    cout<<v.size()<<" "<< v.capacity()<<endl;
    int arr[10];
    int b[10];
    
    
   
    
    // for(int i = 0 ; i < 5 ; i++){
    //     vec.push_back(i);
    //     cout<<"Stored at address: "<<static_cast<void*>(vec.data())<<endl;
    //     cout<<vec.size() << " "<<vec.capacity() << endl;
    // }
}
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int main(){
    // string name;
    // getline(cin, name);
    // cout<<name<<endl;
    fstream file;
    file.open("sample.txt", ios::out);
    file<<"Hello, World!"<<endl;
    file.close();
    fstream readFile;
    readFile.open("sample.txt", ios::in);
    string content;
    getline(readFile, content);
    cout<<content<<endl;

}
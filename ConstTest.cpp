//
// Created by 范鑫磊 on 17/3/9.
//
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main(){
    string s;
    getline(cin,s);
    istringstream buffer(s);
    int n;
    buffer >> n;
    int r = 0;
    if(n == 0){
        r = 0;
    }else if(n == 1){
        r = 1;
    }else{
        int c0=0,c1=1;
        for(int i=2;i<=n;i++){
            int temp = c0;
            c0 = c1;
            c1 = temp + c1;
        }
        r=c1;
    }
    cout << r << endl;

    return 0;
}
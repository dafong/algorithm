//
// Created by 范鑫磊 on 17/4/7.
//

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int LIS_RECURSE(vector<int> array){
    int lis = 0;
    return lis;
}

int LIS_Loop(vector<int> &array){
    vector<int> s(array.size());
    for(int i=0;i<s.size();i++){
        s[i]=0;
    }
    int lis = 0;
    for(int i=0;i<array.size();i++){
        int max = 1;
        for(int j=0;j<i;j++){
            if(array[j]< array[i]){
                int temp = s[j]+1;
                if( temp > max) {
                    max = temp;
                }
            }
        }
        s[i]=max;
        if(max > lis)
            lis = max;
    }
    return lis;
}

int main (){
    vector<int> array;
    string s;
    getline(cin,s);
    istringstream buffer(s);
    int i = 0;
    while(buffer >> i){
        array.push_back(i);
    }
    int lis = LIS_Loop(array);
    cout << "lis is "<< lis << endl;
    return 0;
}
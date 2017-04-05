//
// Created by 范鑫磊 on 17/3/28.
//

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

void EXCHANGE(vector<int> &a ,int i,int j){
    int t = a[i];
    a[i]  = a[j];
    a[j]  = t;
}

int PARTITION(vector<int> &a,int p,int r){
    int m  = a[r];
    int q  = p - 1;
    for(int i = p;i<=r-1;i++){
        if(a[i]<=m){
            q = q + 1;
            EXCHANGE(a,q,i);
        }
    }
    EXCHANGE(a,q+1,r);
    return q+1;
}

int RANDOMIZED_PARTITION(vector<int> &a,int p ,int r){

}

void QUICK_SORT(vector<int> &arr,int p,int r){
    if(p < r){
        int q = PARTITION(arr,p,r);
        QUICK_SORT(arr,p,q-1);
        QUICK_SORT(arr,q+1,r);
    }
}

int main(){
    string s;
    getline(cin,s);
    istringstream buffer(s);
    int n = 0;
    vector<int> array;
    while(buffer >> n){
        array.push_back(n);
    }
    QUICK_SORT(array,0,array.size()-1);
    for(auto i : array){
        cout << i << endl;
    }

    return 0;
}
//
// Created by 范鑫磊 on 17/3/31.
//
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;


void MERGE(vector<int> &array,int p,int q,int r){
    vector<int> p1;
    vector<int> p2;

    int i = p;
    while(i<=q){
        p1.push_back(array[i]);
        i++;
    }
    i=q+1;
    while(i<=r){
        p2.push_back(array[i]);
        i++;
    }
    int i1=0;
    int i2=0;
    i=p;
    while(i<=r){
        if(i1<p1.size()){
            if(i2<p2.size()){
                if(p1[i1] < p2[i2]){
                    array[i]=p1[i1];
                    i1++;
                }else{
                    array[i]=p2[i2];
                    i2++;
                }
            }else{
                array[i]=p1[i1];
                i1++;
            }
        }else{
            array[i]=p2[i2];
            i2++;
        }
        i++;
    }
}

void MERGE_SORT(vector<int> &array,int p,int r){
    if (p>=r) return;
    int q = (p+r)/2 ;
    MERGE_SORT(array,p,q);
    MERGE_SORT(array,q+1,r);
    MERGE(array,p,q,r);
}



int main(){
    string s;
    getline(cin,s);
    istringstream buffer(s);
    int i=0;
    vector<int> array;
    while( buffer >> i){
        array.push_back(i);
    }
    MERGE_SORT(array,0,array.size()-1);
    for(int i = 0;i<array.size();i++){
        cout << array[i] << endl;
    }
    return 0;
}
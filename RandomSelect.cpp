//
// Created by 范鑫磊 on 17/4/5.
//

#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

void EXCHANGE(vector<int> &array,int i,int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int PARTITION(vector<int> &array,int p,int r){
    int q = p-1;
    int i = p;
    int main = p+ rand() % (r-p+1);
    int min = array[main];
    EXCHANGE(array,main,r);
    while(i<r){
        if(array[i] <= min){
            q=q+1;
            EXCHANGE(array,q,i);
        }
        i++;
    }
    EXCHANGE(array,q+1,r);
    return q+1;
}

int RANDOM_SELECT(vector<int> &array,int p,int r,int i){
    int q = PARTITION(array,p,r);
    int k = q-p+1;
    if (i == k){
        return array[q];
    }
    if(i < k){
       return RANDOM_SELECT(array,p,q-1,i);
    }else{
       return RANDOM_SELECT(array,q+1,r,i-k);
    }
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
    int order = 2;
    int result = RANDOM_SELECT(array,0,array.size()-1,order);
    cout << "the " << order << " min is " << result << endl;
    return 0;
}

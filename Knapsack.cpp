//
// Created by yina on 17/4/10.
//

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

static int capacity = 10;
//0-1 knapsack
int Knapsack(vector<int> &weights,vector<int> &prices){
    vector<vector<int>> s(weights.size()+1,vector<int>(capacity+1));
    for(int i=0;i<=capacity;i++){
        s[0][i]=0;
    }

    for(int i=1;i<=weights.size();i++){
        s[i][0]=0;
        for(int j=1;j<=capacity;j++){
            int max = s[i-1][j];
            if(j>=weights[i-1]){
                if(max < (s[i-1][j-weights[i-1]]+prices[i-1]) ){
                    max = s[i-1][j-weights[i-1]]+prices[i-1];
                }
            }
            s[i][j]=max;
        }
    }
    return s[weights.size()][capacity];
}
//1 3 2 6 5 10 5 11 7 13
int main(){

    string s;
    getline(cin,s);
    istringstream buffer(s);
    int n = 0;
    vector<int> weights;
    vector<int> prices;
    int i = 0;
    while(buffer >> n){
        i++;
        if(i%2 == 1){
            weights.push_back(n);
        }else{
            prices.push_back(n);
        }

    }
    if(i%2!=0){
        cout << "input is invalid" << endl;
        return 1;
    }

    int max = Knapsack(weights,prices);
    cout << "the max is " << max << endl;

    return 0;
}
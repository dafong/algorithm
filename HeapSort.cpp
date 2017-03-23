//
// Created by 范鑫磊 on 17/3/23.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define PARENT(x) x/2
#define LEFT(x) x*2
#define RIGHT(x) x*2+1


void max_heap(vector<int> &heap,int i,int heapsize){
    int largest = i;
    if (LEFT(i) <= heapsize && heap[i] < heap[LEFT(i)])
        largest = LEFT(i);
    if (RIGHT(i) <= heapsize && heap[largest] < heap[RIGHT(i)])
        largest = RIGHT(i);
    if(largest!=i){
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        max_heap(heap,largest,heapsize);
    }
}

void build_heap(vector<int> &heap){
    int end = heap.size()/2;
    for(int i = end; i >=0 ;i--){
        max_heap(heap,i,heap.size());
    }
}


void heap_sort(vector<int> &array){
    build_heap(array);
    int size = array.size()-1;
    while(size > 0){
        int temp = array[0];
        array[0] = array[size];
        array[size] = temp;
        size = size - 1;
        max_heap(array,0,size);
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
    heap_sort(array);
    for(int i = 0;i<array.size();i++){
        cout << array[i] << endl;
    }
    return 0;
}
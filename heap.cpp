#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100000], heapsize = 0;
void swap(int *a, int *b){
    long long temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//Sink down operation
void min_heapify(long long arr[], long long size, long long index){
    long long smallest = index;
    long long left = 2*index + 1;
    long long right = 2*index + 2;
    if(left < size && arr[left] < arr[smallest])
        smallest = left;
    if(right < size && arr[right] < arr[smallest])
        smallest = right;
    if(smallest != index){
        swap(arr[index], arr[smallest]);
        min_heapify(arr, size, smallest);
    }
}
//Sink up operation
void heapify_up(long long index){
    long long parent = index/2;
    if(parent == 0){
        if(arr[parent] > arr[index]){
            swap(arr[index], arr[parent]);
            return;
        }
    }
    else{
        if(arr[parent] > arr[index]){
            swap(arr[parent], arr[index]);
            heapify_up(parent);
        }
        else
            return;
        
    }
    
}
void build_heap(long long arr[], long long size){
    for(long long i = size/2 - 1; i >= 0; i--){
        min_heapify(arr, size, i);
    }
}
//Extract minimum element
long long extract_min(long long arr[], long long size){
    long long temp = arr[0];
    swap(arr[0], arr[size-1]);
    min_heapify(arr, size-1 , arr[0]);
    return temp;
}
//Delete minimum element from Heap
void delete_element(long long element){
    long long i;
    for(i = 0; i < heapsize; i++){
        if(arr[i] == element)
            {
                
            break;
        }
    }
    swap(arr[i], arr[heapsize-1]);
   
    heapsize -= 1;
    min_heapify(arr, heapsize, i);
}
//Insert an element into Heap
void insert_val(long long value){
    
    arr[heapsize] = value;
    heapsize += 1;
    if(heapsize > 1)
        heapify_up(heapsize-1);
}
// print current heap
void print_current_heap(long long arr[] , long long heapsize){
    for(int i = 0 ; i < heapsize ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long q;
    cin>>q;
    long long op, value;
    
    while(q--){
        cin>>op;
        if(op == 1){
            
            cin>>value;
            insert_val(value);
        }
        else if(op == 2){
            cin>>value;
            delete_element(value);
        }
        else
            cout<<arr[0]<<endl;
    }
    return 0;
}

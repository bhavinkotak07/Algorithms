/*
Author: Bhavin Kotak
Find size of largest and smallest connected components in a graph using Disjoint set data structure
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <limits.h>
using namespace std;
//Find parent of an element in Set
int find(int parent[], int i)
{
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}
 
// A utility function to do union of two subsets 
void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}
//Check if two elements are in same set
bool sameComponents(int parent[], int a, int b){
    if(find(parent, a) == find(parent, b) )
        return true;
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    int arr[100000];
    
    //bool visited[15000];
    for(int i = 0; i < 100000; i++)
        arr[i] = i;
    //Stores all edges of a graph
    map<int,int> edges;
    //Stores all the nodes of graph
    set<int> nodes;
    int a, b;
    while(n--){
        //visited[n] = false;
        cin>>a>>b;
        nodes.insert(a);
        nodes.insert(b);
        edges[a] = b;
        if(find(arr, a) != find(arr, b))
            Union(arr, a, b);
        
    }
    
    map<int, int> components;
    //Compute all the connected components of graph and calculate its size
    for(auto it=nodes.begin(); it != nodes.end(); it++){
        components[find(arr, *it)] += 1;
        //cout<<find(arr, *it)<<endl;
    }
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for(auto it=components.begin(); it != components.end(); it++){
        if(it->second > largest)
            largest = it->second;
        if(it->second < smallest)
            smallest = it->second;
    }
    cout<<smallest<< " "<< largest;
        
    
    return 0;
}

/*
Author : Bhavin Kotak
*/
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
class Edge{
	int source;
	int destination;
	int weight;
	public:
	Edge(){
	
	}
	Edge(int source, int destination, int weight){
		this->source = source;
		this->destination = destination;
		this->weight = weight;
	}
	bool operator < (const Edge& edge) const
    {
        return (weight < edge.weight);
    }
    int getSource(){
    	return source;
    }
    int getDestination(){
    	return destination;
    }
    int getWeight(){
    	return weight;
    }
	
};
class Graph{
	int node;
	int edge;
	vector <int> parent;
	vector <Edge> edges;
	public:
	Graph(){
		
	}
	Graph(int node, int edge){
		//edges = new vector<Edge>();
		this->node = node;
		this->edge = edge;
		for(int i = 0; i < node; i++)
			parent.push_back(i);
	}
    int getNodes(){
		return node;
	}
	int getEdges(){
		return edge;
	}
	void addEdge(int source, int destination){
		addEdge(source, destination, 0);
	}
	void addEdge(int source, int destination, int weight){
		
		edges.push_back(Edge(source, destination, weight));
	}
	int root(int x)
	{
    	while(parent[x] != x)
	    {
	        parent[x] = parent[parent[x]];
	        x = parent[x];
	    }
    	return x;
	}
	void union1(int x, int y){
		int p = root(x);
		int q = root(y);
		parent[p] = parent[q];
		
	}
	int Krushkal(){
		int minCost = 0;
		std::sort(edges.begin(), edges.end());
		
		for(int i = 0; i < edge; i++){
			
			int x = edges[i].getSource();
			int y = edges[i].getDestination();
			if(root(x) != root(y) ){
				union1(x, y);
				minCost += edges[i].getWeight();
				//cout<<edges[i].getWeight();
			}
		}
		return minCost;
		
	}
	
};
int main(){
	Graph graph;
	int nodes;
	int edges;
	int minCost;
	cin>> nodes >> edges;
	graph = Graph(nodes, edges);
	int x, y, w;
	
	for(int i = 0; i < edges; i++){
		cin>> x >> y >> w;
		graph.addEdge(x, y, w);
	}
	cout<<graph.Krushkal();
}

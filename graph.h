#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <iostream>

class Graph{
public:
//Edge representing a destination followed by weight/cost
struct Edge{
	char dest;
	int weight;
};
	//default constructor 
	Graph(){ } 
	//addVertex adds a vertex to our adjancecy list if
	//does not already exist.
	void addVertex(char v); 
	//addEdge adds an edge from a src vertex to a 
	//destination vertex with a given weight
	//an Edge is created in this function add is 
	//added to the src's list of edges
	void addEdge(char src, char dest, int weight);
	//printGraph prints out the adjancey list
	void printGraph();
	//getAdjEdges returns the list of edges for a given
	//src vertex. list is of Graph::Edge type
	std::vector<Edge> getAdjEdges(char src);
    	//Getter function to retrieve the graphs adjacency list
	//it is a map of characters to list of edges
	std::unordered_map<char,std::vector<Edge>> getAdj(){return adj;}
private:
	//this->adj represents the map of verticies to 
	//it's list of edges.
	std::unordered_map<char,std::vector<Edge>> adj;
};

#endif

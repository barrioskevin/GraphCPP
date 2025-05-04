#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <climits>

class Graph{
public:

//Edge representing a destination followed by weight/cost
struct Edge{
	char dest;
	int weight;
};

	//default constructor 
	Graph(){ numVert = 0; numEdges = 0;} 

	//addVertex adds a vertex to our adjancecy list if
	//does not already exist.
	void addVertex(char v); 

	//addEdge adds an edge from a src vertex to a 
	//destination vertex with a given weight
	//an Edge is created in this function add is 
	//added to the src's list of edges
    //if no weight is provided a default value will be used.
	void addEdge(char src, char dest, int weight);
    void addEdge(char src, char dest);

	//printGraph prints out the adjancey list
	void printGraph();

	//getAdjEdges returns the list of edges for a given
	//src vertex. list is of Graph::Edge type
	std::vector<Edge> getAdjEdges(char src);

	//getAdjEdgesdInts returns the list of edges for a given
	//src vertex where we use integers to represent the vertex
	std::vector<std::vector<int>> getAdjEdgesInts(int src);

	//function to convert a graphs idx to a graphs char name
	char numVtoCharV(int v);

	//function to convert a graphs name to a graphs idx
	int charVtoNumV(char v);

	//function to update weight of an edge present in graph
 	void changeEdgeWeight(char src, char dest, int w);	

    //Getter function to retrieve the graphs adjacency list
	//it is a map of characters to list of edges
	std::unordered_map<char,std::vector<Edge>> getAdj(){return adj;}

	//Getter function to retrieve the graphs adjacency list
	//it is a list of integers [i] where i is 
	//a vector holding vectors of outgoing edges [j]
	//and j is a vector holding destination(0index) and weight(1index)
	std::vector<std::vector<std::vector<int>>> getAdjInt() {return adjInts;}

	//Getter function to retrieve the graphs adjacency matrix
	//it is a VxV matrix accessed [i][j] where the value of 
	//matrix[i][j] will be a boolean indicating an edge from
	//i to j exists
	std::vector<std::vector<bool>> getAdjMatrix() {return adjMatrix;}

	//Getter function to retrieve the graphs weights where 
	//weights is a VxV matrix accessed [i][j] where the value of
	//matrix[i][j] will be the weight of edge i to j if it exists
	//infinity else case.
	std::vector<std::vector<int>> getWeights() {return weights;}

	int getNumVert() {return numVert;}
	int getNumEdges() {return numEdges;}

private:
	//this->adj represents the map of verticies to 
	//it's list of edges.
	std::unordered_map<char,std::vector<Edge>> adj;
	std::vector<std::vector<std::vector<int>>> adjInts;
	std::vector<std::vector<bool>> adjMatrix;
	std::vector<std::vector<int>> weights;
	std::unordered_map<char,int> vToIdx;
	std::vector<char> idxToName;
	int numVert;
	int numEdges;
};

#endif

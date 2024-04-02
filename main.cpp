#include<iostream>
#include "graph.h"
int main(int argc, char* argv[])
{
	//Sample Graph
	Graph g = Graph();
	g.addVertex('S');
	g.addVertex('C');
	g.addVertex('B');
	g.addVertex('A');
	g.addVertex('D');
	g.addVertex('E');
	g.addVertex('F');
	g.addEdge('S','C',8);
	g.addEdge('S','B',2);
	g.addEdge('S','A',3);
	g.addEdge('C','A',5);
	g.addEdge('A','D',2);
	g.addEdge('B','D',7);
	g.addEdge('B','E',8);
	g.addEdge('D','E',2);
	g.addEdge('E','F',2);
	g.addEdge('D','F',2);
	g.printGraph();


	//Extracting AdjList (CHAR FORM)
	std::unordered_map<char,std::vector<Graph::Edge>> adj = g.getAdj();
	for(const auto& v : adj)
	{
		for(const Graph::Edge& e : v.second)
		{
			std::cout << v.first << ":" << e.dest << ","
				<< e.weight << std::endl;
		}
	}

	//Extracing AdjList (INT FORM)
	//AdjList[i][j][0] <- destination of i's jth edge
	//AdjList[i][j][1] <- cost of jth edge
	std::vector<std::vector<std::vector<int>>> adjInt = g.getAdjInt();
	for(int i = 0; i < adjInt.size(); i++)
		for(int j = 0; j < adjInt[i].size(); j++)
		{
			int destination = adjInt[i][j][0];
			int weight = adjInt[i][j][1];
			std::cout << "adjInt[" << i << "][" << j
				<< "][0] = " << destination << " , "
				<< "adjInt[" << i << "][" << j
				<< "][1] = " << weight << std::endl;
		}

	//Extracting AdjMatrix (booleans)
	//if edge from vertex i to vertex j exists a true value exist
	//else it is labeled false
	std::vector<std::vector<bool>> matrix = g.getAdjMatrix();
	for(int i = 0; i < matrix.size(); i++)
		for(int j = 0; j < matrix[i].size(); j++)
			std::cout << "adj[" << g.numVtoCharV(i) << "]["
				<< g.numVtoCharV(j) << "] = " 
				<< matrix[i][j] << std::endl;

	//Extracting Weights (ints holding weight from i to j)
	//weights are infinity if does not exist
	std::vector<std::vector<int>> W = g.getWeights();
	for(int i = 0; i < W.size(); i++)
		for(int j = 0; j < W[i].size(); j++)
			std::cout << "W[" << g.numVtoCharV(i) << "]["
				<< g.numVtoCharV(j) << "] = " 
				<< W[i][j] << std::endl;


	return 0;
}

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
	//Adjancey List is printed
	g.printGraph();
	return 0;
}

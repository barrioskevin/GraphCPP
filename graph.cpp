#include "graph.h"

void Graph::addVertex(char v)
{
	//Adds vertex to graph with an empty
	//list of edges if its not already
	//present in the graph
	if(adj.find(v) == adj.end())
	{
		adj[v] = std::vector<Graph::Edge>();
	}
	else
	{
		std::cout << "Vertex " << v << " already exists!\n";
	}
}
void Graph::addEdge(char src, char dest, int weight)
{
	if(adj.find(src) == adj.end() || adj.find(dest) == adj.end())
		std::cout << "Missing src vertex or dest vertex!\n";
	else
	{
		Graph::Edge e;
		e.dest = dest;
		e.weight = weight;
		adj[src].push_back(e);
	}
}
void Graph::printGraph()
{
	for (const auto& k : adj)
	{
		bool f = 0;
		for(const Graph::Edge& e : k.second)
		{
			f = 1;
			std::cout << k.first << "->" << e.dest << " (cost: "
			    << e.weight << "), ";
		}
		if(!f)
			std::cout << k.first << "-> NO OUTGOING EDGES\n";
	       	else 
			std::cout << std::endl;
       	}
}

std::vector<Graph::Edge> Graph::getAdjEdges(char src)
{
	std::vector<Graph::Edge> adjEdges;
	if(adj.find(src) != adj.end())
		for(const Graph::Edge& e : adj[src])
		    adjEdges.push_back(e);
	return adjEdges;
}

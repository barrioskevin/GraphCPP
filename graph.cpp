#include "graph.h"

void Graph::addVertex(char v)
{
	//Adds vertex to graph with an empty
	//list of edges if its not already
	//present in the graph
	if(adj.find(v) == adj.end())
	{
		adj[v] = std::vector<Graph::Edge>();
		numVert++;
		adjInts.push_back(std::vector<std::vector<int>>());
		vToIdx[v] = numVert-1;
		idxToName.push_back(v);
		for(int i = 0; i < adjMatrix.size(); i++)
		{
			for(int j = adjMatrix[i].size(); j < numVert; j++)
			{
				adjMatrix[i].push_back(0);
				weights[i].push_back(INT_MAX);
			}
		}
		adjMatrix.push_back(std::vector<bool>(numVert));
		weights.push_back(std::vector<int>(numVert,INT_MAX));
	}
	else
	{
		std::cout << "Vertex " << v << " already exists!\n";
	}
}
void Graph::addEdge(char src, char dest, int weight)
{
	int idx = this->vToIdx[src];
	int destIdx = this->vToIdx[dest];
	if(adj.find(src) == adj.end() || adj.find(dest) == adj.end())
		std::cout << "Missing src vertex or dest vertex!\n";
	else if(adjMatrix[idx][destIdx] == 1)
		std::cout << "EDGE ALREADY EXISTS!\n";
	else if(adjMatrix[destIdx][idx] == 1 && weight != weights[destIdx][idx])
		std::cout << "ILLEGAL EDGE TO ADD!\n";
	else
	{
		Graph::Edge e;
		e.dest = dest;
		e.weight = weight;
		adj[src].push_back(e);
		numEdges++;
		std::vector<int> edge = {destIdx,weight};
		adjInts[idx].push_back(edge);
		adjMatrix[idx][destIdx] = 1;
		weights[idx][destIdx] = weight;
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
std::vector<std::vector<int>> Graph::getAdjEdgesInts(int src)
{
	std::vector<std::vector<int>> adjEdges;
	if(src < numVert)
	{
		for(int i = 0; i < adjInts[src].size(); i++)
		{
			std::vector<int> e = {adjInts[src][i][0],adjInts[src][i][1]};
			adjEdges.push_back(e);
		}
	}	
	return adjEdges;
}
char Graph::numVtoCharV(int v)
{
	if(v >= numVert)
	{
		std::cout << "NO SUCH VERTEX, RETURNING '!'";
		return '!';
	}
	return idxToName[v];
}
int Graph::charVtoNumV(char v)
{
	if(adj.find(v) == adj.end())
	{
		std::cout << "NO SUCH VERTEX, RETURNING -1";
		return -1;
	}	
	return vToIdx[v];
}
//Graph::Edge e;
//e.dest = dest;
//e.weight = weight;
//adj[src].push_back(e);
//numEdges++;
//std::vector<int> edge = {destIdx,weight};
//adjInts[idx].push_back(edge);
//adjMatrix[idx][destIdx] = 1;
//weights[idx][destIdx] = weight;
//
void Graph::changeEdgeWeight(char src, char dest, int w)
{
	int s_id = charVtoNumV(src);
	int d_id = charVtoNumV(dest);
	if(s_id == -1 || d_id == -1) return;
	if(weights[s_id][d_id] == INT_MAX) return;
	std::vector<int> edge = {d_id,w};
	Graph::Edge e;
	e.dest = dest;
	e.weight = w;
	for(int i = 0; i < adj[src].size(); i++)
	{
		if(adj[src][i].dest == dest)
			adj[src][i].weight = w;
	}
	int j;
	for(int i = 0; i < adjInts[s_id].size(); i++)
		if(adjInts[s_id][i][0] == d_id)
			j = i;
	adjInts[s_id][j] = edge;
	weights[s_id][d_id] = w;

}

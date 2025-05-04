# Graph CPP
An attempt to represent graphs in cpp. The graph is using an adjacency list managed by an unordered map in order to support vertices with char type names. However the verticies and edges can be extracted from your graph in various formats. The adjancey list hashmap. The adjancey list integer version. The adjancey matrix. The weights matrix.

## Installation

Clone the repo.
```sh
$ git clone https://github.com/barrioskevin/GraphCPP.git
$ cd GraphCPP/
```

Build using your cpp compiler.
```sh
$ g++ main.cpp graph.cpp -o output
$ ./output
```

The `main.cpp` file provided contains examples of how `Graph` is used. This file intends to demonstrate extracting a graph's data in differnt formats and prints the results. After seeing the example, you can link your own programs with `graph.cpp` to utilize the graph object. See Usage for more info.

## Usage

First create your graph
```
Graph graph = Graph();
```

After a graph is created you can start adding edges. If you dont have weights in your graph a default value of 1 can be used by ommiting the weight parameter.
```
graph.addEdge('S','C',8); <- adds edge from node 'S' to node 'C' with cost of 8.
graph.addEdge('S','C'); <- defaults to weight of 1 for unweighted graph.
```
**If you want a undirected graph, add edges both ways**
```
graph.addEdge(src, dest, cost);
graph.addEdge(dest, src, cost);
```

For sparse nodes you can add individual verticies to your graph
```
graph.addVertex('X');
```

The graphs data can be extracted in multiple formats.

### AdjList (map/edges)

The simplest way to read data from the graph is to use the `getAdj()` method. This method will return
an unordered map, mapping each vertex (in character form) to a list of Edge structs. An edge contains two values a destination `dest` and weight `weight`.
```
std::unordered_map<char,std::vector<Graph::Edge>> adj = graph.getAdj();
for(const auto& v : adj)
    for(const Graph::Edge& e : v.second)
    {
        "v.first <- src node"
        "e.dest <- a neighbor of src node"
        "e.weight <- the cost from src to neighbor"
    }
```

### AdjList (vector/integers). 

This version of the adjacency list uses the vertex id. when edges are
added using a character it get assigend a corresponding integer and that
value is whats being used to represent nodes here.
```
std::vector<std::vector<std::vector<int>>> adj = g.getAdjInt();
adj[i][j]    <- jth edge of vertex i
adj[i][j][0] <- vertex i's jth edge's destination vertex
adj[i][j][1] <- vertex i's jth edge's cost
```

### Adjacent verticies of a vertex can also be extracted
In case you do not need to use the graph's entire adjacency list you can also call directly for a specific nodes entry in the adj list.
calling `getAdjEdges` and providing a vertex will give back it's list of neighbors.
```
// Graph::Edge consists of a edge type where edge.dest = char id of destination, edge.weight = cost of edge
vector<Graph::Edge> adjEdges = g.getAdjEdges('S');   <- Character version of adj edges

// vector<int> edge (aka inner vector) holds two values. edge[0] = int id of destination, edge[1] = cost of edge
vector<vector<int>> adjEdges = g.getAdjEdgesInts(0); <- Integer version of adj edges
```

### AdjMatrix
The adjacency matrix uses the vertex id to index nodes. It is a 2 dimensional
matrix of size V * V. There is and edge from node i to node j if adjMatrix[i][j] is true.
This matrix does not give info about edge weights.
```
std::vector<std::vector<bool>> adjMatrix = g.getAdjMatrix();
adjMatrix[i][j] <- true or false value indicating edge from i to j
```

### Weights Matrix
Similar to the adjacency matrix the weight matrix is a 2d matrix of side V * V. This matrix will give an integer value for each weights[i][j]
representing the edge's cost from node i to node j. If no edge exists the weight will be infinity.
```
std::vector<std::vector<int>> W = g.getWeights();
W[i][j] <- cost from vertex i to j if it exist, INT_MAX else case
```

### Using characters vs integers.
GraphCPP was designed to use characters in order to have a more academic representation of graphs. Most of the graph algorithms or graph representations use integers in order to identify nodes. To solve this each graph provides methods to easily obtain an integer id (or character from an id) for any of the graph's nodes.  
```
g.addVertex('S');

//use of char to num
int vertex_id = g.charVtoNumV('S');  <- vertex_id is integer id of vertex 'S'

//use of num to char
char vertex_name = g.numVtoCharV(vertex_id); <- vertex_name = 'S'
```
*The goal is to be able to add in your graphs and you can implement your favorite graph algorithms!*

## PREVIEW 
  *  Visual of sample graph.
  *  ![Sample Graph inserted in main.cpp](sample/samplegraphvisual.png)
  *  Output of printGraph().
  *  ![output of main.cpp](sample/outputex.png)



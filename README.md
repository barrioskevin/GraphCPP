# Graph CPP
An attempt to represent graphs in cpp. The graph is using an adjacency list managed by an unordered map in order to support vertices with char type names. However the verticies and edges can be extracted from your graph in various formats. The adjancey list hashmap. The adjancey list integer version. The adjancey matrix. The weights matrix.
## Usage
* In main.cpp a sample graph is added and it is printed.
* All forms of the graphs representation is also printed.
* Following printGraph the adjancy list is printed, followed by the integer version of the adjancey list, followed by the adjancey matrix, followed by the weights matrix
* First create your graph
  ```
  Graph g = Graph();
  ```
* Next add verticies to your graph
  ```
  g.addVertex('S');
  g.addVertex('C');
  ```
* Finally add edges to your graph
* If you dont have weights in your graph you may insert the value 1 for each weight
  ```
  g.addEdge('S','C',8);
  g.addEdge('S','C',1); <- weight should be 1 for unweighted graph 
  ```
* If you want a undirected graph, add edges both ways
  ```
  g.addEdge(src, dest, cost);
  g.addEdge(dest, src, cost);
  ```
* The graphs data can be extracted in multiple formats
* Getting AdjList 
  ```
  std::vector<std::vector<std::vector<int>>> adj = g.getAdjInt();
  adj[i][j]    <- jth edge of vertex i
  adj[i][j][0] <- vertex i's jth edge's destination vertex
  adj[i][j][1] <- vertex i's jth edge's cost
  ```
* Getting AdjMatrix
  ```
  std::vector<std::vector<bool>> adjMatrix = g.getAdjMatrix();
  adjMatrix[i][j] <- true or false value indicating edge from i to j
  ```
* Getting Weights Matrix
  ```
  std::vector<std::vector<int>> W = g.getWeights();
  W[i][j] <- cost from vertex i to j if it exist, INT_MAX else case
  ```
* You can always convert from integer index to name of vertex and back
  ```
  g.addVertex('S');
  int vertex_id = g.charVtoNumV('S');          <- vertex_id is integer id of vertex 'S'
  char vertex_name = g.numVtoCharV(vertex_id); <- vertex_name = 'S'
  ```
* Adjacent verticies of a vertex can also be extracted
  ```
  g.addVertex('S');
  // Graph::Edge consists of a edge type where edge.dest = char id of destination, edge.weight = cost of edge
  vector<Graph::Edge> adjEdges = g.getAdjEdges('S');   <- Character version of adj edges
  // vector<int> edge (aka inner vector) holds two values. edge[0] = int id of destination, edge[1] = cost of edge
  vector<vector<int>> adjEdges = g.getAdjEdgesInts(0); <- Integer version of adj edges
  ```
* The goal is to be able to add in your graphs and you can implement your favorite graph algorithms!

## Installation
build using your cpp complier
```sh
$ g++ main.cpp graph.cpp -o output
$ ./output
```
## PREVIEW 
  *  Visual of sample graph.
  *  ![Sample Graph inserted in main.cpp](sample/samplegraphvisual.png)
  *  Output of printGraph().
  *  ![output of main.cpp](sample/outputex.png)



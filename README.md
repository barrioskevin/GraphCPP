# Graph CPP
An attempt to represent graphs in cpp. Currently the graph is using an adjacency list managed by an unordered map in order to support vertices with char type names.
## Usage
* In main.cpp a sample graph is added and it is printed.
* First create your graph
* Next add verticies to your graph
* Finally add edges to your graph
* If you dont have weights in your graph you may insert the value 1 for each weight
* If you want a undirected graph, add edges both ways
  ```
  addEdge(src, dest, cost);
  addEdge(dest, src, cost);
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
  *  ![Sample Graph inserted in main.cpp](samplegraphvisual.png)
  *  Output of printGraph().
  *  ![output of main.cpp](outputex.png)



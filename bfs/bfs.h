#ifndef BFS_H
#define BFS_H

#include <stdio.h>
#include <iostream>
#include <string>

struct Node {
  bool visited;
  int value;
};

struct Graph {
  Node *vertices;
  int **matrix;
};

/*
* Creates an adjacency matrix populated with random values
*/
Graph get_random_graph(int vertices);

/*
* Returns true if the value is found in the given adjacency matrix
*/
bool bfs_search(Graph graph, int value, int start, int num_vertices);

#endif

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include "bfs.h"

using namespace std;

/*
* Creates an adjacency matrix populated with random values
* between 1 and 10
*/
Graph get_random_graph(int n) {
  cout << "Creating random graph:" << endl;
  Graph new_graph;
  // Allocate memory for matrix
  int **matrix = new int*[n];
  for (int x = 0; x < n; x++) {
    matrix[x] = new int[n];
  }
  bool add_edge = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      add_edge = rand() % 2; // Decide to add edge or not
      if (add_edge && i!=j) {
        matrix[i][j] = true;
      }
      matrix[i][j] = false;
      cout << matrix[i][j];
    }
    cout << endl;
  }
  new_graph.matrix = matrix;
  Node *graph_vertices = new Node*[n];
  cout << "Creating vertex values: ";
  for (int y = 0; y < n; y++) {
    graph_vertices[y].value = rand() % 9 + 1; // Random values between 1 and 9
    graph_vertices[y].visited = false;
    cout << graph_vertices[y] << " ";
  }
  cout << endl;
  new_graph.vertices = graph_vertices;
  return new_graph;
}

/*
* Returns true if the value is found in the given adjacency matric
* Terminates immediately when the value is found
*/
bool bfs_search(Graph graph, int value, int start, int num_vertices) {
  list<int> queue;
  graph.vertices[start].visited = true;
  queue.push_back(start);
  cout << "Starting BFS search" << endl;
  while (!queue.empty()) {
    s = queue.front();
    cout << "Looking at vertex #" << s << " with value " << graph.vertices[s].value << endl;
    if (graph.vertices[s].value == value) {
      return true;
    }
    queue.pop_front();
    for (int i = 0; i < num_vertices; i++) {
      if (graph.matrix[s][i]) { // If an edge exists
        graph.vertices[i].visited = true;
        queue.push_back(i);
      }
    }
  }
  return false;
}

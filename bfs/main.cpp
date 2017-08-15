#include "bfs.h"

using namespace std;

int main()
{
  int num_vertices;
  int value;
  int start;
  cout << "Pick a value between 1 and 9 to search for: ";
  cin >> value;
  cout << "In a graph with how many vertices? ";
  cin >> num_vertices;
  // Generate random tree
  Graph search_graph = get_random_graph(num_vertices);
  cout << "Start at which vertex? ";
  cin >> start;
  // Search for input
  if (bfs_search(search_graph, value, start, num_vertices)) {
    cout << "Found it" << endl;
  } else {
    cout << "This value is not found within the data structure" << endl;
  }
  return 0;
}

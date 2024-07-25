#include <bits/stdc++.h>
using namespace std;

enum
{
  UNVISITED = -1,
  VISITED = -2
}; // basic flags

// these variables have to be global to be easily accessible by our recursion (other ways exist)

// The 'index' 'u' of the DAG is to be the 1st node and the pair.v is the 2nd node
// the no. of pairs == no. of edges outword from that index `u`
vector<vector<pair<int, int>>> DAG;
// DAG: 'size=V=no. of vertices'

vector<int> checkVisited; // this tracks which elements are visited and which are not visited
vector<int> toposortedVector;
int V; // no. of vertices

void toposort(int u)
{
  checkVisited[u] = VISITED;
  for (auto &el : DAG[u])                    // el=(v, edgeWt) ==>  v->el.first,  edgeWt->el.second
    if (checkVisited[el.first] == UNVISITED) // 'v' is being marked unvisited
      toposort(el.first);                    // 'v' is being called for toposort
  toposortedVector.push_back(u);
}

void createDAG()
{
  DAG.assign(V, vector<pair<int, int>>());

  // index 'u' of the DAG is to be the 1st node and the `v' of pair.(v) is the 2nd node
  for (int u = 0; u < V; ++u)
  {
    int k; // no. of pairs for Vertex `u`
    cin >> k;
    while (k--)
    {
      int v, w; // for the pair of (vertex, edge_wt)
      cin >> v >> w;
      DAG[u].emplace_back(v, w); // `u` is the 1st node and the `pair.v` is the 2nd node
      // the edge between `u` & `v` has [ edge_wt=w ]
    }
  }
}

int main()
{
  /*
  // Example of a Directed Acyclic Graph in Figure 4.3 (for toposort)
8
  2    1 0 2 0
  2    2 0 3 0
  2    3 0 5 0
  1    4 0
  0
  0
  0
  1    6 0

  // [7 6 0 1 2 5 3 4]
  */

  cin >> V;

  createDAG();

  // make sure that the given graph is DAG
  // printf("Topological Sort (the input graph must be DAG)\n");

  checkVisited.assign(V, UNVISITED); // global variable
  // toposortedVector.clear();     // global variable

  /* Applying Toposort on DAG */
  // index 'u' of the DAG is to be the 1st node and the `v' of pair.(v) is the 2nd node
  for (int u = 0; u < V; ++u)
    if (checkVisited[u] == UNVISITED)
      toposort(u);

  // currently 'toposortedVector' is in STACK form, so converting it into a stringht vector form by reversing the STACK form
  // Don't reverse if want to use the 'toposortedVector' to further "SOLVE the DAG",
  // else if want to "just print toposort, use this"
  reverse(toposortedVector.begin(), toposortedVector.end());

  for (auto &u : toposortedVector) // simply read the content
    printf(" %d", u);              // of ts backwards
  printf("\n");

  return 0;
}
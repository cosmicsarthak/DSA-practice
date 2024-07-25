#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

enum
{
    UNVISITED = -1,
    VISITED = -2
}; // basic flags

// these variables have to be global to be easily accessible by our recursion (other ways exist)
vector<vii> DAG;
vi checkVisited;
vi toposortedVector;

void toposort(int u)
{
    checkVisited[u] = VISITED;
    for (auto &[v, w] : DAG[u])
        if (checkVisited[v] == UNVISITED)
            toposort(v);
    toposortedVector.push_back(u); // this is the only change
}

int main()
{
    /*
    // Example of a Directed Acyclic Graph in Figure 4.3 (for toposort)
    8
    2 1 0 2 0
    2 2 0 3 0
    2 3 0 5 0
    1 4 0
    0
    0
    0
    1 6 0

    // [7 6 0 1 2 5 3 4]
    */

    // freopen("toposort_in.txt", "r", stdin);

    int V;
    scanf("%d", &V);
    DAG.assign(V, vector<pair<int, int>>());
    for (int u = 0; u < V; ++u)
    {
        int k;
        scanf("%d", &k);
        while (k--)
        {
            int v, w;
            scanf("%d %d", &v, &w);
            DAG[u].emplace_back(v, w);
        }
    }

    // make sure that the given graph is DAG
    // printf("Topological Sort (the input graph must be DAG)\n");
    checkVisited.assign(V, UNVISITED); // global variable
    toposortedVector.clear();          // global variable
    for (int u = 0; u < V; ++u)        // same as finding CCs
        if (checkVisited[u] == UNVISITED)
            toposort(u);

    reverse(toposortedVector.begin(), toposortedVector.end()); // reverse ts or
    for (auto &u : toposortedVector)                           // simply read the content
        printf(" %d", u);                                      // of ts backwards
    printf("\n");

    return 0;
}
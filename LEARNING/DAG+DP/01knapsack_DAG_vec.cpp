#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

// 0/1 knapsack Input:
int maxN = 12;
int maxW = 20;
int N;
int W;
vector<int> val;
vector<int> wt;
vector<vector<bool>> checkDAG(maxN, vector<bool>(maxW, false));
vector<vector<bool>> checkVisited(maxN, vector<bool>(maxW, false));

// DAG = [ [ ((vertex,remWt), edge_wt), ((vertex,remWt), edgeWt), ...] ]
vector<vector<pair<pair<int, int>, int>>> DAG;
vector<pair<int, int>> toposortedVec;

vector<int> longDist;

void longestPath()
{
    longDist.resize(N * W, -1e9);
    for (auto &el : toposortedVec)
    {
    }
}

void toposort(int u, int w)
{
    checkVisited[u][w] = true;

    for (auto &el : DAG[u])
    {
        // cout << el.first.first << "," << el.first.second << endl;
        if (checkVisited[el.first.first][el.first.second] == false) // 'v' is being marked unvisited
        {
            toposort(el.first.first, el.first.second);
        }
    }
    toposortedVec.emplace_back(u, w);
}

void createDAG()
{
    // giving values to DAG
    vector<int> oldWtTmp;
    oldWtTmp.emplace_back(W);
    for (int u = 0; u < N; u++) // 'u' is the Knapsack 'id'
    {
        vector<int> newWtTmp;
        pair<int, int> pr;
        vector<pair<pair<int, int>, int>> tmpPairVec;
        for (auto el : oldWtTmp)
        {
            // if (!checkDAG[u + 1][el])
            // {
            pr = {u + 1, el};
            tmpPairVec.emplace_back(pr, 0);
            newWtTmp.emplace_back(el);
            checkDAG[u + 1][el] = true;
            // }

            if ((el - wt[u]) >= 0) // el is one value of oldWtTmp
            {
                // if (!checkDAG[u + 1][el - wt[u]])
                // {
                pr = {u + 1, el - wt[u]};
                tmpPairVec.emplace_back(pr, val[u]);
                newWtTmp.emplace_back(el - wt[u]);
                checkDAG[u + 1][el - wt[u]] = true;
                // }
            }
        }
        DAG.emplace_back(tmpPairVec);
        oldWtTmp = newWtTmp;
    }

    // PRINT
    for (int i = 0; i < DAG.size(); i++)
    {
        cerr << "🔢" << DAG[i].size() << endl;
        for (int j = 0; j < DAG[i].size(); j++)
        {
            // if (checkDAG[i][j])
            // {
            auto e = DAG[i][j];
            cerr << i << ","
                 << j
                 << "__.."
                 << "(" << e.first.first << " " << e.first.second << ")," << e.second << endl;
            // }
        }
        cerr << endl;
    }
    // cerr << ">>" << DAG.size() << ".." << endl
    //      << endl;
    // for (auto &el : DAG)
    // {
    //     cerr << el.size() << endl;
    //     // for (auto &e : el)
    //     //     cout << "(" << e.first.first << " " << e.first.second << ")," << e.second << " ";
    //     // cout << endl;
    // }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // n = 5, val = {4, 2, 10, 1, 2}, wt = {12, 1, 4, 1, 2}, W = 15
    cin >> N >> W;
    val.resize(N, 0);
    wt.resize(N, 0);
    for (auto &el : val)
        cin >> el;
    for (auto &el : wt)
        cin >> el;

    createDAG();

    // toposort
    for (int u = 0; u < N; u++)
    {
        for (int w = W; w >= 0; w--)
        {
            if (checkDAG[u][w])
            {
                if (checkVisited[u][w] == false)
                    toposort(u, w);
            }
        }
    }

    reverse(toposortedVec.begin(), toposortedVec.end());
    for (auto el : toposortedVec)
        cout << "(" << el.first << "," << el.second << ")  ";
    cout << endl;

    longestPath();

    return 0;
}
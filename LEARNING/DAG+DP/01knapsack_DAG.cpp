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

// vector<vector<pair<int, pair<int, int>>>> DAG(N); // DAG = [ rem_wt, [(vertex,edge_wt), (,), ..] ]

// DAG = [ [ ((vertex,remWt), edge_wt), ((vertex,remWt), edgeWt), ...] ]
vector<vector<pair<pair<int, int>, int>>> DAG(N);

void convertToDAG()
{
    // giving values to DAG
    vector<int> oldWtTmp;
    oldWtTmp.emplace_back(W);
    for (int u = 0; u < N; u++) // 'u' is the Knapsack 'id'
    {
        vector<int> newWtTmp;
        pair<int, int> pr;
        for (auto el : oldWtTmp)
        {
            vector<pair<pair<int, int>, int>> tmpPrVec;
            if (!checkDAG[u + 1][el])
            {
                pr = {u + 1, el};
                tmpPrVec.emplace_back(pr, 0);
                newWtTmp.emplace_back(el);
                checkDAG[u + 1][el] = true;
            }

            if ((el - wt[u]) >= 0) // el is one value of oldWtTmp
            {
                if (!checkDAG[u + 1][el - wt[u]])
                {
                    pr = {u + 1, el - wt[u]};
                    tmpPrVec.emplace_back(pr, val[u]);
                    newWtTmp.emplace_back(el - wt[u]);
                    checkDAG[u + 1][el - wt[u]] = false;
                }
            }
            DAG.emplace_back(tmpPrVec);
        }
        oldWtTmp = newWtTmp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // n = 5, val = {4, 2, 10, 1, 2}, wt = {12, 1, 4, 1, 2}, W = 15
    cin >> N >> W;
    val.assign(N, 0);
    wt.assign(N, 0);
    for (auto &el : val)
        cin >> el;
    for (auto &el : wt)
        cin >> el;
    cerr << val.size();
    cerr << wt.size();

    convertToDAG();

    for (auto &el : DAG)
    {
        for (auto &e : el)
            cout << "(" << e.first.first << " " << e.first.second << ")," << e.second << " ";
        cout << endl;
    }

    return 0;
}
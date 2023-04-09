#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

// 0/1 knapsack Input:
int maxN = 12;
int N;
int W;
vector<int> val(N);
vector<int> wt(N);

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
        for (auto &el : oldWtTmp)
        {
            vector<pair<pair<int, int>, int>> tmppr;
            tmppr.emplace_back((u + 1, el), 0);
            newWtTmp.emplace_back(el);
            if ((el - wt[u]) >= 0) // el is one value of oldWtTmp
            {
                tmppr.emplace_back((u + 1, el - wt[u]), val[u]);
                newWtTmp.emplace_back(el - wt[u]);
            }
            DAG.emplace_back(tmppr);
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
    for (auto &el : val)
        cin >> el;
    for (auto &el : wt)
        cin >> el;

    convertToDAG();

    return 0;
}
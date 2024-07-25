#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll n;
ll totalVal;
vector<ll> coins;
vector<vector<ll>> DAG;
// ll visited[100000];
vector<bool> visited(1e6 + 2, false);
vector<ll> toposortedVec;
vector<ll> pathVec;

void shortestPath()
{
    pathVec.assign(totalVal + 1, 1e9);
    pathVec.at(totalVal) = 0;

    for (auto &el : toposortedVec)
    {
        for (auto &e : DAG.at(el))
        {
            ll currVal = pathVec.at(el);
            ll edgeVal = 1;
            pathVec.at(e) = min(pathVec.at(e), currVal + edgeVal);
        }
    }
}

void toposort(ll i)
{
    visited[i] = true;
    for (auto &el : DAG.at(i))
        if (!visited[el])
            toposort(el);

    toposortedVec.emplace_back(i);
}

void createDAG()
{
    for (ll i = 0; i <= totalVal; i++)
        for (auto &el : coins)
            if ((i - el) >= 0)
                DAG.at(i).emplace_back(i - el);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> totalVal;
    coins.assign(n, 0);
    for (auto &el : coins)
        cin >> el;

    // memset(visited, 0, sizeof visited); // TOP-DOWN: init memo
    DAG.assign(totalVal + 1, vector<ll>());

    createDAG();

    for (ll i = totalVal; i >= 0; i--)
        if (!visited[i])
            toposort(i);
    reverse(toposortedVec.begin(), toposortedVec.end());

    shortestPath();

    for (auto &el : pathVec)
        cerr << el << " ";
    cerr << endl;

    if (pathVec.at(0) != 1e9)
        cout << pathVec.at(0);
    else
        cout << -1;

    return 0;
}
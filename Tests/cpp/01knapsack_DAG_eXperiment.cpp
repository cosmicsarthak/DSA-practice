#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

// 0/1 knapsack Input:
int maxN = 1e3 + 5;
int maxW = 1e5 + 5;
int N;
int W;
vector<int> val;
vector<int> wt;
vector<vector<bool>> DAG_Open_to_add(maxN, vector<bool>(maxW, false));
vector<vector<bool>> checkVisited(maxN, vector<bool>(maxW, false));

vector<vector<vector<pair<pair<int, int>, int>>>> DAG;
vector<pair<int, int>> toposortedVec;

vector<vector<int>> longDist; // to store the the dist of all [vertices/nodes from ToposortedVec] to [their particular corresponding nodes int the DAG]

int totalcount = 0;

void longestPath()
{
    // src node is [0][W] -> also thats my 1st node in the 'reversed toposortedVec'
    longDist.assign(N + 1, vector<int>(W + 1, -1e9));
    longDist.at(0).at(W) = 0;
    for (auto &el : toposortedVec)
    {
        // auto x = DAG.at(el.first).at(el.second);
        int curLongDist = longDist.at(el.first).at(el.second);
        for (auto &pairVectex : DAG.at(el.first).at(el.second))
        {
            int curNode = pairVectex.first.first;
            int curWt = pairVectex.first.second;
            int nodeDist = pairVectex.second;

            longDist.at(curNode).at(curWt) = max(longDist.at(curNode).at(curWt), nodeDist + curLongDist);
        }
    }

    // ✅ answer
    vector<int> tmpForMaxLength;
    for (auto el : longDist)
        tmpForMaxLength.emplace_back(*max_element(el.begin(), el.end()));
    int ans = *max_element(tmpForMaxLength.begin(), tmpForMaxLength.end());
    cout << ans << endl;
}

void toposort(int u, int w)
{
    checkVisited.at(u).at(w) = true;
    for (auto &el : DAG.at(u).at(w))
    {
        int tmp_u = el.first.first;
        int tmp_w = el.first.second;

        if (!checkVisited[tmp_u][tmp_w]) // ✅☑️✔️NECESSARY  to prevent unnecessary calls
        {
            toposort(tmp_u, tmp_w); // u->u+1,__remWt...
        }
    }
    toposortedVec.emplace_back(u, w);
}

void createDAG() // O( N*W*2 )
{
    DAG.assign(N + 1, vector<vector<pair<pair<int, int>, int>>>(W + 1)); // I will be calling for [0][15] or [5][15]
    pair<int, int> pr;
    DAG_Open_to_add.at(0).at(W) = true;

    for (int u = 0; u < N; u++) // 'u' is the 'id' of knapsack
    {
        for (int remW = W; remW >= 0; remW--)
        {
            ++totalcount;
            if (DAG_Open_to_add[u][remW])
            {
                pr = {u + 1, remW};
                DAG.at(u).at(remW).emplace_back(pr, 0);
                DAG_Open_to_add.at(u + 1).at(remW) = true;

                if (remW - wt[u] >= 0)
                {
                    pr = {u + 1, remW - wt[u]};
                    DAG.at(u).at(remW).emplace_back(pr, val[u]);
                    DAG_Open_to_add.at(u + 1).at(remW - wt[u]) = true;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> W;
    val.resize(N, 0);
    wt.resize(N, 0);
    for (auto &el : val)
        cin >> el;
    for (auto &el : wt)
        cin >> el;

    createDAG();

    // toposort
    for (int u = 0; u < N; u++) // u+1 will be called inside toposort
    {
        for (int w = W; w >= 0; w--)
        {
            if (DAG_Open_to_add.at(u).at(w))
                if (!checkVisited.at(u).at(w))
                    toposort(u, w);
        }
    }

    // cerr << "ToposortedVector is: " << endl;
    reverse(toposortedVec.begin(), toposortedVec.end());
    for (auto el : toposortedVec)
        cerr << "(" << el.first << "," << el.second << ")  ";
    cerr << endl;

    longestPath();

    cout << endl
         << "⌚:" << totalcount << endl;

    return 0;
}
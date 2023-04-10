#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

class Solution
{
public:
    // 0/1 knapsack Input:
    int maxN = 1000;
    int maxW = 1000;
    int N;
    int W;
    vector<int> val;
    vector<int> wt;
    vector<vector<bool>> DAGavailable = vector<vector<bool>>(maxN, vector<bool>(maxW, false));
    vector<vector<bool>> checkVisited = vector<vector<bool>>(maxN, vector<bool>(maxW, false));

    vector<vector<vector<pair<pair<int, int>, int>>>> DAG;
    vector<pair<int, int>> toposortedVec;

    vector<vector<int>> longDist; // to store the the dist of all [vertices/nodes from ToposortedVec] to [their particular corresponding nodes int the DAG]

    int topsum = 0;

    int longestPath()
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
        // cout << ans << endl;
        return ans;
    }

    void toposort(int u, int w)
    {
        checkVisited.at(u).at(w) = true;
        for (auto &el : DAG.at(u).at(w))
        {
            ++topsum;
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
        vector<int> oldWt;
        oldWt.emplace_back(W);
        for (int u = 0; u < N; u++) // 'u' is the 'id' of knapsack
        {
            vector<int> newWt;
            for (auto &el : oldWt)
            {
                pr = {u + 1, el};
                newWt.emplace_back(el);
                DAG.at(u).at(el).emplace_back(pr, 0); // e.g::  DAG[1][15] = [ (2,15),0   (2,14),2  ]

                if (el - wt[u] >= 0)
                {
                    pr = {u + 1, el - wt[u]};
                    newWt.emplace_back(el - wt[u]);
                    DAG.at(u).at(el).emplace_back(pr, val[u]);
                }

                DAGavailable[u][el] = true;
            }
            oldWt = newWt;
        }
        DAGavailable.at(0).at(15) = true;
    }

    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int WInp, int wtAr[], int valAr[], int nInp)
    {

        N = nInp;
        W = WInp;

        for (int i = 0; i < nInp; i++)
            wt.emplace_back(wtAr[i]);
        for (int i = 0; i < nInp; i++)
            val.emplace_back(valAr[i]);

        createDAG();

        // toposort
        for (int u = 0; u < N; u++) // u+1 will be called inside toposort
        {
            for (int w = W; w >= 0; w--)
            {
                if (DAGavailable.at(u).at(w))
                    if (!checkVisited.at(u).at(w))
                        toposort(u, w);
            }
        }
        cerr << "topsum_call: " << topsum << endl;

        // cerr << "ToposortedVector is: " << endl;
        reverse(toposortedVec.begin(), toposortedVec.end());
        // for (auto el : toposortedVec)
        //     cerr << "(" << el.first << "," << el.second << ")  ";
        // cerr << endl;

        return longestPath();

        return 0;
    }
};

int main()
{
    int n, w;
    cin >> n >> w;
    int val[n];
    int wt[n];

    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    Solution ob;
    cout << ob.knapSack(w, wt, val, n) << endl;
}
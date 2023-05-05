#include <bits/stdc++.h>
using namespace std;
int N;
int W;
vector<int> val;
vector<int> wt;
int mx = -1;
int best;

int dfs(int idx, int w)
{
    if (idx == N)
    {
        return 0;
    }

    if ((w - wt.at(idx)) >= 0)
    {
        best = max(dfs(idx + 1, w - wt.at(idx)) + val[idx], dfs(idx + 1, w));
        return best;
    }
    else
    {
        best = dfs(idx + 1, w);
        return best;
    }
}

int main()
{
    cin >> N >> W;
    val.resize(N);
    wt.resize(N);

    for (auto &el : val)
        cin >> el;
    for (auto &el : wt)
        cin >> el;

    cout << dfs(0, W);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> memo;
vector<int> v;

int dp(int i)
{
    if (i == 0)
        return 0;
    if (memo.at(i) != -1)
        return memo.at(i);
    int best = INT_MAX;

    best = min(best, dp(i - 1) + abs(v[i - 1] - v[i]));
    if ((i - 2) >= 0)
        best = min(best, dp(i - 2) + abs(v[i - 2] - v[i]));

    memo[i] = best;
    return memo[i];
}

int main()
{
    int n;
    cin >> n;
    v.assign(n, 0);
    for (auto &el : v)
        cin >> el;

    memo.assign(n, -1);
    memo[0] = 0;

    cout << dp(n - 1);
}
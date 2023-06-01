#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &el : v)
        cin >> el;

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + abs(v[i - 1] - v[i]));
        if ((i - 2) >= 0)
            dp[i] = min(dp[i], dp[i - 2] + abs(v[i - 2] - v[i]));
    }

    cout << dp[n - 1];
}
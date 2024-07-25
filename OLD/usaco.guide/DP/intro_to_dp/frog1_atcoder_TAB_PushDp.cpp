// BEST METHOD ✅

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

    // base case
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        if ((i + 1) < n)
            dp.at(i + 1) = min(dp.at(i + 1), dp[i] + abs(v.at(i + 1) - v[i]));
        if ((i + 2) < n)
            dp.at(i + 2) = min(dp.at(i + 2), dp[i] + abs(v.at(i + 2) - v[i]));
    }

    cout << dp[n - 1];
}
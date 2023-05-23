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

    cout << dp[n - 1];
}
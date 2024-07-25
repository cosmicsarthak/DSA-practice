#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<int> limit(100);
    vector<int> bes(100);

    int len, spd, pos = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> len >> spd;
        for (int j = pos; j < pos + len; j++)
        {
            limit.at(j) = spd;
        }
        pos += len;
    }
    pos = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> len >> spd;
        for (int j = pos; j < pos + len; j++)
        {
            bes.at(j) = spd;
        }
        pos += len;
    }

    int mx = 0;
    for (int i = 0; i < 100; i++)
    {
        mx = max(mx, (bes[i] - limit[i]));
    }

    cout << mx;

    return 0;
}
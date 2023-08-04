#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
#endif

    int n;
    cin >> n;
    int tmp;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> tmp;
            v[i].emplace_back(tmp);
        }
    }

    vector<int> choice = {1, 2, 3};
    int mx = 0;
    for (auto c : choice)
    {
        int sum = 0;
        int now = c;
        for (auto el : v)
        {
            if (el.at(0) == now)
            {
                now = el.at(1);
            }
            else if (el.at(1) == now)
            {
                now = el.at(0);
            }

            if (el.at(2) == now)
                ++sum;
        }
        mx = max(sum, mx);
    }
    cout << mx;

    return 0;
}
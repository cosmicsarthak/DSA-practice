#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("gymnastics.in", "r", stdin);
    // freopen("gymnastics.out", "w", stdout);

    int k, n;
    cin >> k >> n;

    vector<vector<int>> v(k, vector<int>(n));

    for (auto &el : v)
    {
        for (auto &el2 : el)
        {
            cin >> el2;
        }
    }

    vector<vector<int>> sol(n, vector<int>(n, -1));
    for (auto &el : v)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i < j) && sol.at(el.at(i) - 1).at(j) != 0)
                {
                    sol.at(el.at(i) - 1).at(j) = 1;
                    // cerr << "__. " << el.at(i) - 1 << " j:" << (j) << endl;
                }
                else
                {
                    sol.at(el.at(i) - 1).at(j) = 0;
                }
            }
            for (auto &eli : sol)
            {
                for (auto &eli2 : eli)
                {
                    cerr << eli2 << " ";
                }
                cerr << endl;
            }
            cerr << endl;
        }
    }

    int ans = 0;
    for (auto &el : sol)
    {
        for (auto el2 : el)
        {
            // cerr << el2 << " ";
            if (el2 == 1)
            {
                ++ans;
            }
        }
        // cerr << endl;
    }

    cout << ans;

    return 0;
}
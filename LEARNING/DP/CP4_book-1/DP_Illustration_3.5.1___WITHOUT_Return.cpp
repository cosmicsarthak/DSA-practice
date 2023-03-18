#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int res = -1e6;

void foo(vector<vector<int>> &v, int budget, int row, int orig)
{
    if (row == v.size())
    {
        if ((orig - budget) <= orig)
        {
            res = max(orig - budget, res);
        }
        return;
    }

    for (int col = 0; col < v.at(row).size(); col++)
    {
        budget -= v.at(row).at(col);
        foo(v, budget, row + 1, orig);
        budget += v.at(row).at(col);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int budget, n;
        cin >> budget >> n;
        vector<vector<int>> v(n);

        for (auto &el : v)
        {
            int n1;
            cin >> n1;
            int tmp;
            // cerr << n1 << " ";
            for (int j = 0; j < n1; j++)
            {
                cin >> tmp;
                el.emplace_back(tmp);
            }
        }

        int row = 0, orig = budget;
        foo(v, budget, row, orig);
        if (res > 0)
            cout << res << endl;
        else
            cout << "no solution" << endl;
        res = -1e6;
        cerr << endl;
    }

    return 0;
}
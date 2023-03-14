#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int res = -1e6;

void foo(vector<vector<int>> &v, int bud, int row, int orig, int mn)
{
    if (row == v.size())
    {
        if ((orig - bud) <= orig)
        {
            res = max(orig - bud, res);
        }
        return;
    }

    for (int col = 0; col < v.at(row).size(); col++)
    {
        bud -= v.at(row).at(col);
        foo(v, bud, row + 1, orig, mn);
        bud += v.at(row).at(col);
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
        int bud, n;
        cin >> bud >> n;
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

        int row = 0, orig = bud, mn = 1e6;
        foo(v, bud, row, orig, mn);
        if (res > 0)
            cout << res << endl;
        else
            cout << "no solution" << endl;
        res = -1e6;
        cerr << endl;
    }

    return 0;
}
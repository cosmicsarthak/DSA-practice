#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int res = 0;

void foo(vector<vector<int>> &v, int bud, int row, int ans, int org)
{
    cerr << bud << "   ";
    if (bud <= org)
    {
        ans = max(ans, bud);
        res = ans;
    }

    for (int col = 0; col < v.at(row).size(); col++)
    {
        row =
            bud -= v.at(row).at(col);
        foo(v, bud, row + 1, ans, org);
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
        int org = bud;
        vector<vector<int>> v(n);

        // cerr << bud << endl
        //      << n << endl;

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
                // cerr << tmp << " ";
            }
            // cerr << endl;
        }
        // cerr << endl;

        int row = 0, ans = 1e6;
        foo(v, bud, row, ans, org);
        cout << res << endl;
        res = 0;
    }

    return 0;
}
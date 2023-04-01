#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int MAX_price = 210;
int MAX_gar = 30;
int MAX_K = 30;
int M, C;
vector<vector<int>> v(MAX_gar);
vector<vector<int>> memo(MAX_gar); // table

int dp(int row, int bud)
{
    if (bud < 0)
        return -1e9;
    if (row == C)
        return M - bud; // bud is remaining budget
    if (memo[row][bud] != -1)
        return memo[row][bud];
    int ans = -1;
    for (int k = 1; k <= v.at(row).at(0); k++)
    {
        ans = max(ans, dp(row + 1, bud - v.at(row).at(k)));
    }
    memo[row][bud] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        fill(v.begin(), v.end(), vector<int>(MAX_K, -1));
        fill(memo.begin(), memo.end(), vector<int>(MAX_price, -1));
        cin >> M >> C;
        for (int row = 0; row < C; row++)
        {
            cin >> v.at(row).at(0);
            for (int i = 1; i <= v.at(row).at(0); i++)
            {
                cin >> v.at(row).at(i);
            }
        }

        int bud = M, row = 0;
        int ans = dp(row, bud);
        if (ans >= 0)
            cout << ans << endl;
        else
            cout << "no sol" << endl;

        for (auto &el : memo)
        {
            for (auto e : el)
                cerr << e << " ";
            cerr << endl;
        }
    }

    return 0;
}
/*
3

9 3
3 6 4 8
2 5 10
4 1 5 3 5

12 3
3 6 4 8
2 5 10
4 1 5 3 5

20 3
3 6 4 8
2 5 10
4 1 5 3 5
 */
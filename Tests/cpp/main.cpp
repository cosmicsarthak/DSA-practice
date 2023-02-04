#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n;

bool is_valid(int rw, int cl, vector<vector<int>> &board, vector<int> &row, vector<int> &col, vector<int> &pr_dg, vector<int> &sec_dg)
{
    if (row.at(rw) == 1)
        return false;
    if (col.at(cl) == 1)
        return false;
    if (pr_dg.at(n + rw - cl) == 1)
        return false;
    if (sec_dg.at(rw + cl) == 1)
        return false;
    return true;
}

void foo(vector<vector<int>> &board, vector<int> &row, vector<int> &col, vector<int> &pr_dg, vector<int> &sec_dg, int rw)
{
    if (rw == n)
    {
        for (auto &el : board)
        {
            for (auto &el2 : el)
                cout << el2 << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int cl = 0; cl < n; cl++)
    {
        if (is_valid(rw, cl, board, row, col, pr_dg, sec_dg))
        {
            board.at(rw).at(cl) = 1;
            row.at(rw) = 1;
            col.at(cl) = 1;
            pr_dg.at(n + rw - cl) = 1;
            sec_dg.at(rw + cl) = 1;
            foo(board, row, col, pr_dg, sec_dg, rw + 1);
            board.at(rw).at(cl) = 0;
            row.at(rw) = 0;
            col.at(cl) = 0;
            pr_dg.at(n + rw - cl) = 0;
            sec_dg.at(rw + cl) = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> row(n, 0);
    vector<int> col(n, 0);
    vector<int> pr_dg(2 * n, 0);
    vector<int> sec_dg(2 * n, 0);

    foo(board, row, col, pr_dg, sec_dg, 0);

    return 0;
}

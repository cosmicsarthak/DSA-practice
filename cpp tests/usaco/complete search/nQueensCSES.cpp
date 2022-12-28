#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int ans = 0;

bool is_safe(int row, int col, vector<int> &primary_diagonal, vector<int> &secondary_diagonal, vector<int> &rw, vector<int> &cl, int n)
{
    if (rw.at(row) == 1 || cl.at(col) == 1 || primary_diagonal.at(n + col - row) == 1 || secondary_diagonal.at(row + col) == 1)
    {
        return false;
    }
    return true;
}

void foo(vector<string> &board, int row, int n, vector<int> &primary_diagonal, vector<int> &secondary_diagonal, vector<int> &rw, vector<int> &cl)
{
    if (row == n)
    {
        ++ans;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (is_safe(row, col, primary_diagonal, secondary_diagonal, rw, cl, n))
        {
            if (board.at(row).at(col) != '*')
            {
                primary_diagonal.at(n + col - row) = 1;
                secondary_diagonal.at(row + col) = 1;
                rw.at(row) = 1;
                cl.at(col) = 1;
                board.at(row).at(col) = '*';
                foo(board, row + 1, n, primary_diagonal, secondary_diagonal, rw, cl);
                board.at(row).at(col) = '.';
                primary_diagonal.at(n + col - row) = 0;
                secondary_diagonal.at(row + col) = 0;
                rw.at(row) = 0;
                cl.at(col) = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 8;
    vector<string> board(n);
    for (auto &el : board)
    {
        string tmp;
        getline(cin, tmp);
        el = tmp;
    }

    vector<int> primary_diagonal(2 * n, 0);
    vector<int> secondary_diagonal(2 * n, 0);
    vector<int> rw(n, 0);
    vector<int> cl(n, 0);
    int row = 0;
    foo(board, row, n, primary_diagonal, secondary_diagonal, rw, cl);

    cout << ans;

    return 0;
}
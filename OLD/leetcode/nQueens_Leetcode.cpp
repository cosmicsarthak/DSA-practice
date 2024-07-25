#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<vector<string>> ans;

bool is_safe(vector<int> &primary_diagonal, vector<int> &secondary_diagonal, vector<int> &rw, vector<int> &cl, int row, int col, int n)
{
    if ((rw.at(row) == 1) || (cl.at(col) == 1) || (primary_diagonal.at(n + col - row) == 1) || (secondary_diagonal.at(row + col) == 1))
    {
        return false;
    }
    return true;
}

void foo(vector<string> &board, int row, int n, vector<int> &primary_diagonal, vector<int> &secondary_diagonal, vector<int> &rw, vector<int> &cl)
{
    if (row == n)
    {
        ans.emplace_back(board);

        for (auto &el : board)
        {
            for (auto &el2 : el)
                cerr << el2 << " ";
            cerr << endl;
        }
        cerr << endl;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (is_safe(primary_diagonal, secondary_diagonal, rw, cl, row, col, n)) // i.e. not being attacked
        // if (rw[row] == 0 && secondary_diagonal[row + col] == 0 && primary_diagonal[n - 1 + col - row] == 0) // i.e. not being attacked
        {
            primary_diagonal.at(n + col - row) = 1;
            secondary_diagonal.at(row + col) = 1;
            rw.at(row) = 1;
            cl.at(col) = 1;
            board.at(row).at(col) = 'Q';
            foo(board, row + 1, n, primary_diagonal, secondary_diagonal, rw, cl);
            board.at(row).at(col) = '.';
            primary_diagonal.at(n + col - row) = 0;
            secondary_diagonal.at(row + col) = 0;
            rw.at(row) = 0;
            cl.at(col) = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n);
    string str(n, '.');
    for (int i = 0; i < n; i++)
    {
        board.at(i) = str;
    }

    vector<int> primary_diagonal(2 * n, 0);
    vector<int> secondary_diagonal(2 * n, 0);
    vector<int> rw(n, 0);
    vector<int> cl(n, 0);
    int row = 0;
    foo(board, row, n, primary_diagonal, secondary_diagonal, rw, cl);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> xx = solveNQueens(n);
    for (auto el : xx)
    {
        for (auto el2 : el)
        {
            cout << el2 << ",";
        }
        cout << endl;
    }
}
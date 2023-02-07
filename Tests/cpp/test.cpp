#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int N, ans = 0;
    vector<int> col_ar = {-1, 0, 1, 0}; // up, right, down, left
    vector<int> row_ar = {0, 1, 0, -1};
    vector<char> directions = {'U', 'R', 'D', 'L'};
    vector<string> result;
    string str = "";

    bool checks(vector<vector<int>> &board, int row, int col, int pathNum)
    {
        // given blockages
        if (board.at(row).at(col) == 0)
            return false;

        // // splitted into two parts
        // if ((board.at(row).at(col + 1) == 0) && (board.at(row).at(col - 1) == 0) && (board.at(row + 1).at(col) == 1) && (board.at(row - 1).at(col) == 1))
        //     return false; // columns are free but rows are not
        // if ((board.at(row + 1).at(col) == 0) && (board.at(row - 1).at(col) == 0) && (board.at(row).at(col + 1) == 1) && (board.at(row).at(col - 1) == 1))
        //     return false; // rows are free but columns are not

        // // reached others ends
        // if (pathNum == N * N && (row != N - 1 || col != N - 1))
        //     return false;

        // // reached end but not all paths taken
        // if ((row == N - 1 && col == N - 1) && pathNum != N * N)
        //     return false;

        // if ((row == N - 1 && col == N - 1) && pathNum == N * N)
        //     ++ans;

        // reached end .. for Rat in a maze
        if ((row == N - 1) && (col == N - 1))
            result.emplace_back(str);
        ++ans;

        return true;
    }

    void foo(vector<vector<int>> &board, int row, int col, int pathNum)
    {
        // next path
        for (int i = 0; i < N; i++)
        { // for up->left
            int nextRow = row + row_ar[i];
            int nextCol = col + col_ar[i];
            if (checks(board, nextRow, nextCol, pathNum))
            {
                board.at(row).at(col) = 0;
                str.push_back(directions.at(i));
                ++pathNum;
                foo(board, nextRow, nextCol, pathNum);
                --pathNum;
                str.pop_back();
                // after foo I am back again with "old" 'row and col'
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<vector<int>> board(n + 2, vector<int>(n + 2, 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board.at(i + 1).at(j + 1) = m.at(i).at(j);
            }
        }

        for (auto &el : board)
        {
            for (auto &e : el)
                cerr << e << " ";
            cerr << endl;
        }

        N = n;
        int pathNum = 0;
        int col = 0;
        int row = 0;
        foo(board, row, col, pathNum);

        cerr << endl
             << endl
             << N << ans << endl;
        return result;
    }
};

// Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int col_directions[] = {-1, 0, 1, 0}; // up right down left // to be used for getting all possible directionsin a for loop
int row_directions[] = {0, 1, 0, -1}; // up right down left
int ans = 0;

void foo(vector<vector<int>> &grid, int curRow, int curCol, string str, int strIndex, int n)
{
    // base case
    if (strIndex == (n * n - 1)) // as input-path is of size 48 , so the index is [0...47]
    {
        cerr << "..." << endl;
        ++ans;
        return;
    }

    // split grid into two
    if ((grid.at(curRow + 1).at(curCol) == 1 && grid.at(curRow - 1).at(curCol) == 1) && (grid.at(curRow).at(curCol + 1) != 1 && grid.at(curRow).at(curCol - 1)) != 1)
    { // left-right boundary,  top-bottom both open
        return;
    }
    else if ((grid.at(curRow).at(curCol + 1) == 1 && grid.at(curRow).at(curCol - 1) == 1) && (grid.at(curRow + 1).at(curCol) != 1 && grid.at(curRow - 1).at(curCol)) != 1)
    { // top-bottom boundary, left-right both open
        return;
    }

    // reached end without going through all the paths
    if (curRow == n && curCol == 1 && (strIndex != n * n - 1)) // as the grid is [9x9] and actually wanted at [1..7]
    {
        return;
    }

    // TODO can't get to the end position from here

    grid.at(curRow).at(curCol) = 1; // this path is Done, Now going to 'next-path'

    /* if  'next-path' is already given*/
    if (str.at(strIndex) == 'U')
    {
        curCol -= 1;
        foo(grid, curRow, curCol, str, strIndex + 1, n);
    }
    else if (str.at(strIndex) == 'R')
    {
        curRow += 1;
        foo(grid, curRow, curCol, str, strIndex + 1, n);
    }
    else if (str.at(strIndex) == 'D')
    {
        curCol += 1;
        foo(grid, curRow, curCol, str, strIndex + 1, n);
    }
    else if (str.at(strIndex) == 'L')
    {
        curRow -= 1;
        foo(grid, curRow, curCol, str, strIndex + 1, n);
    }
    else if (str.at(strIndex) == '?') /* for '?' */
    {
        for (int i = 0; i < 4; i++)
        {
            curRow += row_directions[i];
            curCol += col_directions[i];
            cerr << "" << curRow << "," << curCol << "   ";
            foo(grid, curRow, curCol, str, strIndex + 1, n);
            // for 0 .. row_direction[0]==-1 & col_direction[0]==0 - UP
            // for 1 .. col_direction[1]==1 & row_direction[1]==0 - RIGHT
            // for 2 .. row_direction[2]==1 & col_direction[2]==0 - DOWN
            // for 3 .. col_direction[3]==-1 & row_direction[3]==0 - RIGHT
        }
    }

    grid.at(curRow).at(curCol) = 0; // backtracking
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int n = 7;

    vector<vector<int>> grid(n + 2, vector<int>(n + 2, 0));
    for (int i = 0; i < grid.size(); i++)
    {
        grid.at(0).at(i) = 1;
        grid.at(grid.size() - 1).at(i) = 1;
        grid.at(i).at(0) = 1;
        grid.at(i).at(grid.size() - 1) = 1;
    }

    // for (auto el : grid)
    // {
    //     for (auto el2 : el)
    //     {
    //         cerr << el2 << " ";
    //     }
    //     cerr << endl;
    // }

    int curRow = 1;
    int curCol = 1;
    int strIndex = 0;

    foo(grid, curRow, curCol, str, strIndex, n);
    cout << ans;

    return 0;
}
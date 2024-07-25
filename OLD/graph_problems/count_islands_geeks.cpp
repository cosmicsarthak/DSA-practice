//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int rw, cl, ans = 0;
    deque<pair<char, char>> q;
    vector<pair<int, int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

    void bfs(pair<char, char> p, vector<vector<char>> grid, vector<vector<int>> &vis)
    {
        while (!q.empty())
        {
            p = q.front();
            q.pop_front();
            for (auto el : dir)
            {
                int x = p.first + el.first;
                int y = p.second + el.second;
                if ((x >= rw) || (y >= cl) || (x < 0) || (y < 0))
                    continue;
                if ((grid.at(x).at(y) == '1') && (!vis.at(x).at(y)))
                {
                    vis.at(x).at(y) = 1;
                    pair<int, int> tmp = {x, y};
                    q.emplace_back(tmp);
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        rw = grid.size();
        cl = grid[0].size();
        vector<vector<int>> vis(rw, vector<int>(cl, 0));
        for (int i = 0; i < rw; i++)
        {
            for (int j = 0; j < cl; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    vis[i][j] = 1;
                    ++ans;
                    pair<int, int> tmp = {i, j};
                    q.emplace_back(tmp);
                    bfs(tmp, grid, vis);
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << "::::" << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &v)
{
    vector<int> sol;
    int rFirst = 0, rLast = v.size() - 1, cFirst = 0, cLast = v[0].size() - 1;
    int r = rFirst, c = cFirst;
    int count = v.size() * v[0].size();
    while (count)
    {
        // right
        if (r == rFirst)
        {
            while (c <= cLast)
            {
                cerr << "right ____" << v[r][c] << endl;
                sol.emplace_back(v[r][c]);
                ++c;
                cerr << "**c__" << c << endl;
                --count;
                cerr << count << endl;
                if (count <= 0)
                {
                    return sol;
                }
            }
            ++rFirst, c = cLast;
            cerr << "cLast__." << cLast << endl;
            cerr << "cFirst__." << cFirst << endl;
        }
        r = rFirst;

        // down
        if (c == cLast)
        {
            while (r <= rLast)
            {
                cerr << "down ____" << v[r][c] << endl;
                sol.emplace_back(v[r][c]);
                ++r;
                --count;
                cerr << count << endl;
                if (count <= 0)
                {
                    return sol;
                }
            }
            --cLast, r = rLast;
        }
        c = cLast;
        cerr << "cLast__." << cLast << endl;
        cerr << "cFirst__." << cFirst << endl;

        // left
        if (r == rLast)
        {
            while (c >= cFirst)
            {
                cerr << "left ____" << v[r][c] << endl;
                sol.emplace_back(v[r][c]);
                --c;
                --count;
                cerr << count << endl;
                if (count <= 0)
                {
                    return sol;
                }
            }
            --rLast, c = cFirst;
        }
        r = rLast;

        // up
        if (c == cFirst)
        {
            while (r >= rFirst)
            {
                cerr << "up ____" << v[r][c] << endl;
                sol.emplace_back(v[r][c]);
                --r;
                --count;
                cerr << count << endl;
                if (count <= 0)
                {
                    return sol;
                }
            }
            ++cFirst, r = rFirst;
        }
        c = cFirst;
        cerr << "cLast__." << cLast << endl;
        cerr << "cFirst__." << cFirst << endl;
    }

    return sol;
}

int main()
{

    vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    vector<int> v2(spiralOrder(v));

    for (auto el : v2)
    {
        cout << el << " ";
    }
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int>(c));
    for (auto &el : v)
    {
        for (auto &el2 : el)
        {
            cin >> el2;
        }
    }

    int mx = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (j - 1 > 0)
            {
                int &tmp = v.at(i).at(j - 1);
                if (tmp == -1)
                {
                    swap(v.at(i).at(j), tmp);
                }
                else if (tmp > 0)
                {
                    v.at(i).at(j) += tmp;
                    mx = max(mx, v.at(i).at(j));
                    tmp = -1;
                }
            }
            else if (i - 1 > 0)
            {
                int &tmp = v.at(i - 1).at(j);
                if (tmp == -1)
                {
                    swap(v.at(i).at(j), tmp);
                }
                else if (tmp > 0)
                {
                    v.at(i).at(j) += tmp;
                    mx = max(mx, v.at(i).at(j));
                    tmp = -1;
                }
            }
            if (j + 1 < c - 1)
            {
                int &tmp = v.at(i).at(j + 1);
                if (tmp == -1)
                {
                    swap(v.at(i).at(j), tmp);
                }
                else if (tmp > 0)
                {
                    v.at(i).at(j) += tmp;
                    mx = max(mx, v.at(i).at(j));
                    tmp = -1;
                }
            }
            if (i + 1 < r - 1)
            {
                int &tmp = v.at(i + 1).at(j);
                if (tmp == -1)
                {
                    swap(v.at(i).at(j), tmp);
                }
                else if (tmp > 0)
                {
                    v.at(i).at(j) += tmp;
                    mx = max(mx, v.at(i).at(j));
                    tmp = -1;
                }
            }
        }
    }

    cout << mx << endl;

    for (auto el : v)
    {
        for (auto el2 : el)
            cerr << el2 << " ";
        cerr << endl;
    }

    return 0;
}
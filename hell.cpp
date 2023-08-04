#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v1;
    vector<int> v2;
    int n = 17262, m = 23569;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v1.emplace_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        v2.emplace_back(tmp);
    }

    vector<int> sol;
    int p1 = 0;
    int p2 = 0;

    while (p1 < n && p2 < m)
    {
        if (v1.at(p1) <= v2.at(p2))
        {
            if ((sol.size() == 0) || sol.back() != v1[p1])
            {
                sol.emplace_back(v1[p1]);
            }
            p1++;
        }
        else
        {
            if ((sol.size() == 0) || sol.back() != v2[p2])
            {
                sol.emplace_back(v2[p2]);
            }
            p2++;
        }
    }

    while (p1 < n)
    {
        if ((sol.size() == 0) || sol.back() != v1[p1])
        {
            sol.emplace_back(v1[p1]);
        }
        p1++;
    }
    while (p2 < m)
    {
        if ((sol.size() == 0) || sol.back() != v2[p2])
        {
            sol.emplace_back(v2[p2]);
        }
        p2++;
    }

    cout << sol.size();
}

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> v(26);

    string w1, w2;
    unordered_map<char, int> ump1;
    unordered_map<char, int> ump2;
    unordered_map<char, int> merge;
    for (int i = 0; i < n; i++)
    {
        ump1.clear();
        ump2.clear();
        cin >> w1 >> w2;
        for (auto el : w1)
        {
            el = el + 2;
            ++ump1[el];
        }
        for (const auto el : w2)
        {
            ++ump2[el];
        }

        merge.clear();
        for (const auto el : ump1)
        {
            merge[el.first] = el.second;
        }
        for (const auto el : ump2)
        {
            if (el.second > merge[el.first])
            {
                merge[el.first] = el.second;
            }
        }

        for (const auto el : merge)
        {
            v.at(el.first - 'a') += el.second;
        }
    }

    for (const auto el : v)
        cout << el << endl;

    return 0;
}
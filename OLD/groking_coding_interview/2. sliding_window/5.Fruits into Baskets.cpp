#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    istringstream ss(s);
    vector<char> v;
    char tmp;
    unordered_map<char, int> mp;

    while (ss >> tmp)
        v.emplace_back(tmp);

    vector<char> subV;
    int mx = -1, n = v.size();
    vector<char> ans;
    int win_end = 0, win_start = 0;

    for (win_end = 0; win_end < n; win_end++) // O(n)
    {
        subV.emplace_back(v.at(win_end));
        ++mp[v.at(win_end)];

        for (auto el : subV)
            cerr << el << " ";
        cerr << endl;

        while (mp.size() > 2) // basket = 2  // O(log n)
        {
            char el = subV.at(0);
            --mp[subV.at(0)];
            if (mp[el] == 0)
            {
                mp.erase(el);
            }
            subV.erase(subV.begin());
        }

        for (auto el : subV)
            cerr << el << "..";
        cerr << endl;

        int len = subV.size(); // `.size()` is unsigned so can't be compared to -ve integers
        if (len > mx)
        {
            mx = subV.size();
            ans = subV;
        }
    }

    for (auto el : ans)
        cout << el << " ";
    cout << endl;
    cout << mx << endl;

    return 0;
}
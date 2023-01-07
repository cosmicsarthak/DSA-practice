#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
#endif

    int n;
    cin >> n;
    string line;
    getline(cin, line); // "\n"
    map<string, vector<string>> mp;

    vector<string> v = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        istringstream ss(s);
        string tmp;
        deque<string> indistring;
        while (ss >> tmp)
        {
            indistring.emplace_back(tmp);
        }
        string x1 = indistring.front();
        string x2 = indistring.back();
        mp[x1].emplace_back(x2); // mp gets the pairs
        mp[x2].emplace_back(x1); // mp gets the pairs
    }

    do
    {
        bool flag = true;
        // return for not exist
        for (int i = 0; i < v.size(); i++)
        {
            if (mp.count(v.at(i)))
            {
                for (auto el : mp[v.at(i)])
                {
                    if (i > 0 && i < v.size() - 1)
                    {
                        if ((v.at(i - 1) != el) && (v.at(i + 1) != el))
                        {
                            flag = false;
                            break;
                        }
                    }
                    else if (i == 0)
                    {
                        if ((v.at(i + 1) != el))
                        {
                            flag = false;
                            break;
                        }
                    }
                    else if (i == v.size() - 1)
                    {
                        if ((v.at(i - 1) != el))
                        {
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }
        // exists
        if (flag)
        {
            // for (auto el : v)
            //     cerr << el << " ";
            // cerr << endl;
            break;
        }

    } while (next_permutation(v.begin(), v.end()));

    for (auto el : v)
    {
        cout << el << endl;
    }

    return 0;
}
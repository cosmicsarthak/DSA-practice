#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

map<char, int> mp;
string s;
vector<string> v;

void foo(string &perm)
{
    if (perm.size() == s.size())
    {
        v.emplace_back(perm);
        return;
    }
    for (auto &el : mp)
    {
        if (el.second <= 0)
        {
            continue;
        }
        --el.second;
        perm.push_back(el.first);
        foo(perm);
        perm.pop_back();
        ++el.second;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    for (auto el : s)
    {
        ++mp[el];
    }
    string perm;
    foo(perm);

    cout << v.size() << endl;
    for (auto el : v)
    {
        cout << el << endl;
    }

    return 0;
}
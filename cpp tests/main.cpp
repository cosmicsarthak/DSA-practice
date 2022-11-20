#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int roo(vector<int> &v, int i, bool b)
{
    if (i >= v.size())
    {
        if (b)
            return 0;
        else
            return -1e5;
    }
    if (b)
        return max(v.at(i) + roo(v, i + 1, true), 0);
    else
        return max(v.at(i) + roo(v, i + 1, true), roo(v, i + 1, false));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &el : v)
        cin >> el;
    cout << roo(v, 0, false);

    return 0;
}
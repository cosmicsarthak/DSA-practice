#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<vector<int>> ans;
vector<int> sub;

void roo(vector<int> &v, vector<int> &sub, int i)
{
    if (i == v.size())
    {
        ans.emplace_back(sub);
        return;
    }
    roo(v, sub, i + 1);
    sub.emplace_back(v.at(i));
    roo(v, sub, i + 1);
    sub.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &el : v)
    {
        cin >> el;
    }

    roo(v, sub, 0);

    for (auto el : ans)
    {
        for (auto el2 : el)
        {
            cout << el2 << " ";
        }
        cout << endl;
    }

    return 0;
}
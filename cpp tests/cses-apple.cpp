#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<ll> gl;

ll roo(vector<ll> v, ll i, ll s1, ll s2)
{
    if (i == v.size())
    {
        return abs(s2 - s1);
    }
    return min((roo(v, i + 1, s1 + v.at(i), s2)), roo(v, i + 1, s1, s2 + v.at(i)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &el : v)
        cin >> el;
    cout << roo(v, 0, 0, 0);

    return 0;
}

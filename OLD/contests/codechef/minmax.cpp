#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool fo(ll n, vector<int> &v, int mid)
{
    vector<int> ds = v;
    if (v[0] > mid)
        return false;
    for (ll i = 0; i < n; i++)
    {
        if (v[i - 1] < mid)
        {
            v[i] = v[i] - (mid - v[i - 1]);
            v[i - 1] = mid;
        }
        if (v[i] > mid)
        {
            return false;
        }
    }
    if (*max_element(v.begin(), v.end()) > mid)
    {
        return false;
    }
    return true;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<int> v(2 * n);
        for (auto &el : v)
            cin >> el;

        ll i = 0;
        ll j = *max_element(v.begin(), v.end());
        ll ans = 1e9;
        while (i <= j)
        {
            ll mid = (i + j) / 2;
            if (fo(n, v, mid))
            {
                j = mid - 1;
                ans = min(ans, mid);
            }
            else
            {
                i = mid + 1;
            }
            cout << ans;
        }

        return 0;
    }
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("balancing.in", "r", stdin);
    // freopen("balancing.out", "w", stdout);

    ll n;
    cin >> n;
    vector<ll> v(n);

    for (auto &el : v)
    {
        cin >> el;
    }

    ll mndif = 1000000001;
    ll total = accumulate(v.begin(), v.end(), 0);
    for (ll i = 0; i < n; i++)
    {
        ll tmpsum = v.at(i);
        ll other, diff;
        if (v.size() > 1)
        {
            other = total - tmpsum;
            diff = abs(tmpsum - other);
            // cerr << v.at(i) << "(" << tmpsum << ")"
            //      << ".[" << other << "]==" << diff << "\t";
            mndif = min(mndif, diff);
        }
        for (ll j = 0; j < n; j++)
        {
            if (j != i)
            {
                tmpsum += v.at(j);
                other = total - tmpsum;
                diff = abs(tmpsum - other);
                // cerr << v.at(j) << "(" << tmpsum << ")"
                //      << ".[" << other << "]==" << diff << "\t";
            }
            mndif = min(mndif, diff);
        }
        // cerr << endl
        //      << endl;
    }

    cout << mndif;

    return 0;
}
// using subset here and then just finding the [(sum-subset_sum) - subset_sum)]

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll mn = 1e9;
ll sum, n;

void foo(vector<ll> &v, vector<ll> &subset, ll subset_sum, ll pos)
{
    if (pos == n)
    {
        ll other_subset_sum = sum - subset_sum;
        ll diff = abs(other_subset_sum - subset_sum);

        // cerr << sum << " - " << subset_sum << "," << other_subset_sum << " .." << abs(other_subset_sum - subset_sum) << endl;

        // to be divided into 2 groups, So, subset_sum can't be ==sum or ==0
        if (subset_sum != 0 && subset_sum != sum)
        {
            mn = min(mn, diff);
        }
        return;
    }

    foo(v, subset, subset_sum, pos + 1);
    subset.emplace_back(v.at(pos));
    subset_sum += v.at(pos);
    foo(v, subset, subset_sum, pos + 1);
    subset_sum -= v.at(pos);
    subset.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<ll> v(n);
    for (auto &el : v)
        cin >> el;

    for (auto &el : v)
        sum += el;

    if (n == 1)
    {
        cout << v.at(0);
        return 0;
    }

    vector<ll> subset;
    ll pos = 0, subset_sum = 0;
    foo(v, subset, subset_sum, pos);

    cout << mn;

    return 0;
}
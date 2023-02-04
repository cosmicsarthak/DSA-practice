#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll n, total = 0;
ll mind = 10e6;

void foo(vector<ll> &v, vector<ll> &sub, ll pos)

{
    if (pos == n)
    {
        ll sub_sum = 0;
        for (auto &el : sub)
            sub_sum += el;
        if (sub_sum != 0 && sub_sum != total)
        {
            ll other_sum = abs(total - sub_sum);
            cerr << sub_sum << " " << other_sum;

            ll diff = abs(sub_sum - other_sum);
            mind = min(diff, mind);
        }
        return;
    }

    foo(v, sub, pos + 1);
    sub.emplace_back(v.at(pos));
    foo(v, sub, pos + 1);
    sub.pop_back();
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
        total += el;

    vector<ll> sub;
    foo(v, sub, 0);

    cout << mind << endl;
    cerr << "total_" << total << endl;

    return 0;
}
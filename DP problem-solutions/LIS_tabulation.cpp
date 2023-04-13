#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &el : v)
        cin >> el;

    vector<ll> tab(n, 1); // as per INDEX of vector 'v'

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < i; j++)
        {
            if (v.at(j) < v.at(i))
                if (tab.at(i) < (tab.at(j) + 1))
                    tab.at(i) = tab.at(j) + 1;
        }
    }

    // for (auto &el : tab)
    //     cerr << el << " ";
    // cerr << endl;

    cout << *max_element(tab.begin(), tab.end());

    return 0;
}
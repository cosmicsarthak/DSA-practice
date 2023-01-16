#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n);
        for (auto &el : v)
            cin >> el;

        vector<ll> diff1;
        vector<ll> diff2;
        for (int i = 0; i < 2 * n; i++)
        {
            cerr << "i(" << i << ")"
                 << ".." << v[i] << "." << n << endl;
            if (v[i] > n and i < n)
                diff1.emplace_back(i + 1);
            if (v[i] <= n and i >= n)
                diff2.emplace_back(i + 1);
        }
        sort(diff1.begin(), diff1.end()); // 123
        sort(diff2.begin(), diff2.end()); // 456
        ll ans = 0;
        n = diff1.size(); // 3
        for (int i = 0; i < n; i++)
        {
            ans += abs(diff1[i] - diff2[i]);
        }
        cout << ans << endl;
    }
    return 0;
}

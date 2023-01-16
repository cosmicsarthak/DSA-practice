#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n);
        for (auto &el : v)
            cin >> el;

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < 2 * n; j++)
            {
                cerr << j << '(' << v[j - 1] << "," << v[j] << ")"
                     << "  ";
                for (auto &el : v)
                    cerr << el << ".";
                if (v[j - 1] > v[j])
                {
                    swap(v[j - 1], v[j]);
                    ++ans;
                    cerr << "... ";
                    for (auto &el : v)
                        cerr << el << ".";
                }
                cerr << endl;
            }
        }
        // for (auto &el : v)
        //     cerr << el << " ";
        cerr << endl;
        cout << ans << endl;
    }
    return 0;
}

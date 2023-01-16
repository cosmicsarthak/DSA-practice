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

        vector<int> tmp = v;
        sort(tmp.begin(), tmp.end());
        unordered_set<int> st(tmp.begin() + n, tmp.end());

        ll ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < i + n; j++)
            {
                cerr << j << '(' << v[j] << "," << v[j + 1] << ")"
                     << "  ";
                for (auto &el : v)
                    cerr << el << ".";
                if ((st.count(v[j])) && (v[j] > v[j + 1]))
                {
                    swap(v[j], v[j + 1]);
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
        // cerr << endl;
        cout << ans << endl;
    }
    return 0;
}

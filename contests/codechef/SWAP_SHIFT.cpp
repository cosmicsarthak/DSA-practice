#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &el : v)
            cin >> el;

        sort(v.begin(), v.end());

        for (auto &el : v)
            cout << el << " ";
        cout << endl;
    }

    return 0;
}

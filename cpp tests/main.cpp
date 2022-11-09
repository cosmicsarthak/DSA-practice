#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v(4);

    for (int &el : v)
    {
        cin >> el;
    }

    for (auto el : v)
    {
        cout << el << " ";
    }

    return 0;
}
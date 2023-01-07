#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> mp;
    ++mp[78];
    ++mp[78];
    ++mp[755];

    cout << mp.size() << endl;

    --mp[755];
    cout << mp.size() << endl;

    return 0;
}
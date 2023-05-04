#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
    int n, total;
    cin >> n >> total;
    vector<int> coins(n);
    for (auto &el : coins)
        cin >> el;
    for (auto &el : coins)
        cerr << el << ".";

    vector<int> tab(total + 1);

    // Tablulation
    tab[0] = 0; // somewhat similar to `memo[]`
    for (int x = 1; x <= total; x++)
    {
        tab[x] = 1e8;
        for (auto c : coins)
        {
            if (x - c >= 0)
            {
                tab[x] = min(tab[x], tab[x - c] + 1);
            }
        }
    }
    if (tab.at(total) == 1e8)
        cout << -1;
    else
        cout << tab.at(total);
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int tab[];
int coins[100];

int main()
{

    // Tablulation
    tab[0] = 0; // somewhat similar to `memo[]`
    for (int x = 1; x <= n; x++)
    {
        tab[x] = -1e8;
        for (auto c : coins)
        {
            if (x - c >= 0)
            {
                tab[x] = min(tab[x], tab[x - c] + 1);
            }
        }
    }
}
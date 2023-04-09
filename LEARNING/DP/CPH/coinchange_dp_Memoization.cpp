#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int memo[];
bool ready[];
int coins[100];

int dp(int x)
{
    if (x < 0)
        return 1e8;
    if (x == 0)
        return 0;
    if (ready[x])
        return memo[x];
    int best = 1e8;
    for (auto c : coins)
    {
        best = min(best, dp(x - c) + 1);
    }
    memo[x] = best;
    ready[x] = true;
    return best;
}

int main()
{
}
#include <bits/stdc++.h>
using namespace std;

const int MAX_gm = 30; // up to 20 garments at most and 20 models/garment
const int MAX_M = 210; // maximum budget is 200
int M, C;

int price[MAX_gm][MAX_gm]; // g < 20 and k <= 20
// vector<vector<int>> price(MAX_gm, vector<int>(MAX_gm));

int memo[MAX_gm][MAX_M]; // g < 20 and b <= 200
// vector<vector<int>> memo(MAX_gm, vector<int>(MAX_M));

int dp(int g, int b)
{
    if (b < 0)
        return -1e9; // fail, return -ve number
    if (g == C)
        return M - b; // we are done
    // if the line below is commented, top-down DP will become backtracking!!
    if (memo[g][b] != -1)
        return memo[g][b];                 // TOP-DOWN: memoization
    int ans = -1;                          // start with a -ve number
    for (int k = 1; k <= price[g][0]; ++k) // try each model k
        ans = max(ans, dp(g + 1, b - price[g][k]));
    // memo[g][b] = ans;
    // return ans;
    return memo[g][b] = ans; // TOP-DOWN: memoize ans
}

int main()
{ // easy to code
    int TC;
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d %d", &M, &C);
        for (int g = 0; g < C; ++g)
        {
            scanf("%d", &price[g][0]); // store k in price[g][0]
            for (int k = 1; k <= price[g][0]; ++k)
                scanf("%d", &price[g][k]);
        }
        memset(memo, -1, sizeof memo); // TOP-DOWN: init memo
        if (dp(0, M) < 0)
            printf("no solution\n"); // start the top-down DP
        else
            printf("%d\n", dp(0, M));

        for (auto &el : memo)
        {
            for (auto e : el)
                cerr << e << " ";
            cerr << endl;
        }
    }
    return 0;
}
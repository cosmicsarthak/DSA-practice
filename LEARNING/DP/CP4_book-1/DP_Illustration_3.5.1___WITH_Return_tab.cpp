// UVa 11450 - Wedding Shopping - Bottom Up (faster than Top Down)
#include <bits/stdc++.h>
using namespace std;

const int MAX_gm = 30;         // <= 20 garments&models
const int MAX_M = 210;         // maximum budget is 200
int price[MAX_gm][MAX_gm];     // g < 20 and k <= 20
bool reachable[MAX_gm][MAX_M]; // g < 20 and b <= 200

int main()
{
    int TC;
    scanf("%d", &TC);
    while (TC--)
    {
        int M, C;
        scanf("%d %d", &M, &C);
        for (int row = 0; row < C; ++row)
        {
            scanf("%d", &price[row][0]); // store k in price[g][0]
            for (int k = 1; k <= price[row][0]; ++k)
                scanf("%d", &price[row][k]);
        }

        memset(reachable, false, sizeof reachable); // clear everything

        // initial values (base cases), using first garment g = 0
        for (int k = 1; k <= price[0][0]; ++k)
            if (M - price[0][k] >= 0)
                reachable[0][M - price[0][k]] = true;
        int b;
        for (int row = 1; row < C; ++row) // for each garment
            for (b = 0; b < M; ++b)
                if (reachable[row - 1][b])
                    for (int k = 1; k <= price[row][0]; ++k)
                        if (b - price[row][k] >= 0)
                            reachable[row][b - price[row][k]] = true; // also reachable now
        for (b = 0; b <= M && !reachable[C - 1][b]; ++b)
            ;
        if (b == M + 1)
            printf("no solution\n"); // last row has no on bit
        else
            printf("%d\n", M - b);
    }
    return 0;
}
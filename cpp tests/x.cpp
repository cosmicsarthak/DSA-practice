#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int countPrimes(int n)
{
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        bool flag = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0 && i != j)
            {
                cout << "b__" << i << endl;
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cerr << i << " ";
            ++count;
        }
    }

    return count;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << countPrimes(10);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
void setIO(string name = "")
{ // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0); // see Fast Input & Output
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin); // see Input & Output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool ok[8][8];

int ans = 0;

int main()
{
    setIO();
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++)
        {
            ok[i][j] = (s[j] == '.');
        }
    }
    vi vals(8);

    iota(begin(vals), end(vals), 0); // set vals to 0 1 ... 7

    do
    {
        bool works = true;
        bool blocked[16];
        for (int i = 0; i < 8; i++)
        {
            if (!ok[i][vals[i]])
            {
                works = false;
            }
        }
        // first mark all squares as not blocked
        memset(blocked, false, sizeof(blocked));
        for (int i = 0; i < 8; i++)
        {
            if (blocked[i + vals[i]])
            {
                works = false;
            }
            blocked[i + vals[i]] = true; // mark this diagonal
        }
        memset(blocked, false, sizeof(blocked));
        for (int i = 0; i < 8; i++)
        {
            if (blocked[i + 7 - vals[i]])
            {
                works = false;
            }
            blocked[i + 7 - vals[i]] = true;
        }
        if (works)
            ++ans;
    } while (next_permutation(begin(vals), end(vals)));

    cout << ans << '\n';
}
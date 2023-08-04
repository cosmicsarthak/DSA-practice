#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("breedflip.in", "r", stdin);
    // freopen("breedflip.out", "w", stdout);

    int n;
    string a;
    string b;
    cin >> n >> a >> b;
    int ans = 0;

    bool flip = false;
    for (int i = 0; i < n; i++)
    {
        if (b.at(i) != a.at(i))
        {
            if (!flip)
            {
                ++ans;
                flip = true;
            }
        }
        else
        {
            flip = false;
        }
    }

    cout << ans;

    return 0;
}

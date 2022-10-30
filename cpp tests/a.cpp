#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void sol(vector<int> &v, int k)
{
    int maxsum = 0, tmpsum = 0;
    int winst = 0, winen = 0;
    for (int winen = 0; winen < v.size(); winen++)
    {
        tmpsum += v.at(winen);
        if (winen >= k - 1)
        {
            maxsum = max(maxsum, tmpsum);
            tmpsum -= v.at(winst);
            ++winst;
        }
    }

    cout << maxsum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v = {2, 1, 5, 1, 3, 2};
    int k = 3;

    sol(v, k);

    return 0;
}
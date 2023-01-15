#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void sol(vector<int> &v)
{
    int dist1 = sqrt(pow((v[0] - 0), 2) + pow((v[1] - 0), 2));
    int dist2 = sqrt(pow((v[2] - 0), 2) + pow((v[3] - 0), 2));

    if (dist2 > dist1)
        cout << "BOB";
    else if (dist1 > dist2)
        cout << "ALEX";
    else
        cout << "EQUAL";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v(4);
        for (auto &el : v)
            cin >> el;
        sol(v);
    }

    return 0;
}

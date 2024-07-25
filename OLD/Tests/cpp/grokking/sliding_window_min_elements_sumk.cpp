#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string x;
    getline(cin, x);
    istringstream ss(x);
    vector<int> v;
    int k;
    cin >> k;

    int tmp;
    while (ss >> tmp)
    {
        v.emplace_back(tmp);
    }

    int sli_start = 0;
    int sli_sum = 0;
    int sm = 1e6;
    for (int sli_end = 0; sli_end < v.size(); sli_end++)
    {
        sli_sum += v.at(sli_end);
        while (sli_sum >= k)
        {
            sm = min(sm, sli_end - sli_start + 1);
            sli_sum -= v.at(sli_start);
            ++sli_start;
        }
    }

    cout << sm << endl;

    return 0;
}
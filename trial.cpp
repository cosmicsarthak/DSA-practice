#include <bits/stdc++.h>
using namespace std;
int N;
int W;
vector<int> val;
vector<int> wt;

int main()
{

    cin >> N >> W;

    wt.assign(N, 0);
    val.assign(N, 0);
    for (auto &el : val)
        cin >> el;
    for (auto &el : wt)
        cin >> el;
    cerr << N << " " << W << endl;
    cerr << val.size();
    cerr << wt.size();
}